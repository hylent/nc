
extern zend_class_entry *nc_db_dbinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DbInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_savepoint, 0, 0, 0)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_rollbacktosavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_transactionatomic, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_savepointatomic, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
	ZEND_ARG_INFO(0, savepointIfNeeded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_atomic, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_query, 0, 0, 2)
	ZEND_ARG_INFO(0, flag)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_setqueryclass, 0, 0, 1)
	ZEND_ARG_INFO(0, queryClass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, tableAlias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_dbinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, inTransaction, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, begin, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, commit, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, savepoint, arginfo_nc_db_dbinterface_savepoint)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, releaseSavepoint, arginfo_nc_db_dbinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, releaseLastSavepoint, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, rollbackToSavepoint, arginfo_nc_db_dbinterface_rollbacktosavepoint)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, rollbackToLastSavepoint, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, transactionAtomic, arginfo_nc_db_dbinterface_transactionatomic)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, savepointAtomic, arginfo_nc_db_dbinterface_savepointatomic)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, atomic, arginfo_nc_db_dbinterface_atomic)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, quote, arginfo_nc_db_dbinterface_quote)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, query, arginfo_nc_db_dbinterface_query)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, setQueryClass, arginfo_nc_db_dbinterface_setqueryclass)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, getQueryClass, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, __invoke, arginfo_nc_db_dbinterface___invoke)
	PHP_FE_END
};
