
extern zend_class_entry *nc_db_dbabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DbAbstract);

PHP_METHOD(Nc_Db_DbAbstract, inTransaction);
PHP_METHOD(Nc_Db_DbAbstract, begin);
PHP_METHOD(Nc_Db_DbAbstract, commit);
PHP_METHOD(Nc_Db_DbAbstract, rollback);
PHP_METHOD(Nc_Db_DbAbstract, savepoint);
PHP_METHOD(Nc_Db_DbAbstract, releaseSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, releaseLastSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, rollbackToSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, rollbackToLastSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, transactionAtomic);
PHP_METHOD(Nc_Db_DbAbstract, savepointAtomic);
PHP_METHOD(Nc_Db_DbAbstract, atomic);
PHP_METHOD(Nc_Db_DbAbstract, setQueryClass);
PHP_METHOD(Nc_Db_DbAbstract, getQueryClass);
PHP_METHOD(Nc_Db_DbAbstract, __invoke);
PHP_METHOD(Nc_Db_DbAbstract, tryToBegin);
PHP_METHOD(Nc_Db_DbAbstract, tryToCommit);
PHP_METHOD(Nc_Db_DbAbstract, tryToRollback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_savepoint, 0, 0, 0)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_rollbacktosavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_transactionatomic, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_savepointatomic, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
	ZEND_ARG_INFO(0, savepointIfNeeded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_atomic, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_setqueryclass, 0, 0, 1)
	ZEND_ARG_INFO(0, queryClass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, tableAlias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_dbabstract_method_entry) {
	PHP_ME(Nc_Db_DbAbstract, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, savepoint, arginfo_nc_db_dbabstract_savepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, releaseSavepoint, arginfo_nc_db_dbabstract_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, releaseLastSavepoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, rollbackToSavepoint, arginfo_nc_db_dbabstract_rollbacktosavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, rollbackToLastSavepoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, transactionAtomic, arginfo_nc_db_dbabstract_transactionatomic, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, savepointAtomic, arginfo_nc_db_dbabstract_savepointatomic, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, atomic, arginfo_nc_db_dbabstract_atomic, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, setQueryClass, arginfo_nc_db_dbabstract_setqueryclass, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, getQueryClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, __invoke, arginfo_nc_db_dbabstract___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, tryToBegin, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, tryToCommit, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, tryToRollback, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
