<?php
/**
 * ADOdb Lite Transaction Module for ibase
 * 
 */

eval('class ibase_transaction_EXTENDER extends '. $last_module . '_ADOConnection { }');

class ibase_transaction_ADOConnection extends ibase_transaction_EXTENDER
{
	var $autoCommit = true;
	var $transOff = 0;
	var $transCnt = 0;
	var $transaction_status = true;

	function StartTrans($errfn = 'ADODB_TransMonitor')
	{
		if ($this->transOff > 0) {
			$this->transOff += 1;
			return;
		}

		$this->transaction_status = true;

		if ($this->debug && $this->transCnt > 0)
			ADOConnection::outp("Bad Transaction: StartTrans called within BeginTrans");

		$this->BeginTrans();
		$this->transOff = 1;
	}

	function BeginTrans()
	{
		if ($this->transOff)
			return true;
		$this->transCnt += 1;
		$this->autoCommit = false;
	 	$this->_transactionID = $this->connectionId;
		return $this->_transactionID;
	}

	function CompleteTrans($autoComplete = true)
	{
		if ($this->transOff > 1) {
			$this->transOff -= 1;
			return true;
		}

		$this->transOff = 0;
		if ($this->transaction_status && $autoComplete) {
			if (!$this->CommitTrans()) {
				$this->transaction_status = false;
				if ($this->debug)
					ADOConnection::outp("Smart Commit failed");
			} else
				if ($this->debug)
					ADOConnection::outp("Smart Commit occurred");
		} else {
			$this->transaction_status = false;
			$this->RollbackTrans();
			if ($this->debug)
				ADOCOnnection::outp("Smart Rollback occurred");
		}

		return $this->transaction_status;
	}

	function CommitTrans($ok=true) 
	{
		if (!$ok)
			return $this->RollbackTrans();
		if ($this->transOff)
			return true;
		if ($this->transCnt)
			$this->transCnt -= 1;
		$ret = false;
		$this->autoCommit = true;
		if ($this->_transactionID)
		{
			$ret = ibase_commit($this->_transactionID);
		}
		$this->_transactionID = false;
		return $ret;
	}

	function RollbackTrans() 
	{
		if ($this->transOff)
			return true;
		if ($this->transCnt)
			$this->transCnt -= 1;
		$ret = false;
		$this->autoCommit = true;
		if ($this->_transactionID)
			$ret = ibase_rollback($this->_transactionID);
		$this->_transactionID = false;   
		return $ret;
	}

	function FailTrans()
	{
		if ($this->debug) 
			if ($this->transOff == 0) {
				ADOConnection::outp("FailTrans outside StartTrans/CompleteTrans");
			} else {
				ADOConnection::outp("FailTrans was called");
			}
		$this->transaction_status = false;
	}

	function HasFailedTrans()
	{
		if ($this->transOff > 0)
			return $this->transaction_status == false;

		return false;
	}

	function RowLock($table,$where)
	{
		if ($this->autoCommit)
			$this->BeginTrans();
		$this->Execute("UPDATE $table SET $col=$col WHERE $where ");
		return 1;
	}

	function CommitLock($table)
	{
		return $this->CommitTrans();
	}

	function RollbackLock($table)
	{
		return $this->RollbackTrans();
	}
}

eval('class ibase_transaction_resultset_EXTENDER extends '. $last_module . '_ResultSet { }');

class ibase_transaction_ResultSet extends ibase_transaction_resultset_EXTENDER
{
}
?>