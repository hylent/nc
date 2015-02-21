
extern zend_class_entry *nc_db_dbadapter_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DbAdapter);

PHP_METHOD(Nc_Db_DbAdapter, inTransaction);
PHP_METHOD(Nc_Db_DbAdapter, savepoint);
PHP_METHOD(Nc_Db_DbAdapter, releaseSavepoint);
PHP_METHOD(Nc_Db_DbAdapter, releaseLastSavepoint);
PHP_METHOD(Nc_Db_DbAdapter, rollbackToSavepoint);
PHP_METHOD(Nc_Db_DbAdapter, rollbackToLastSavepoint);
PHP_METHOD(Nc_Db_DbAdapter, setQueryClass);
PHP_METHOD(Nc_Db_DbAdapter, getQueryClass);
PHP_METHOD(Nc_Db_DbAdapter, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbadapter_savepoint, 0, 0, 0)
	ZEND_ARG_INFO(0, autoTransaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbadapter_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbadapter_rollbacktosavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbadapter_setqueryclass, 0, 0, 1)
	ZEND_ARG_INFO(0, queryClass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbadapter___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, tableAlias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_dbadapter_method_entry) {
	PHP_ME(Nc_Db_DbAdapter, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAdapter, savepoint, arginfo_nc_db_dbadapter_savepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAdapter, releaseSavepoint, arginfo_nc_db_dbadapter_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAdapter, releaseLastSavepoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAdapter, rollbackToSavepoint, arginfo_nc_db_dbadapter_rollbacktosavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAdapter, rollbackToLastSavepoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAdapter, setQueryClass, arginfo_nc_db_dbadapter_setqueryclass, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAdapter, getQueryClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAdapter, __invoke, arginfo_nc_db_dbadapter___invoke, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
