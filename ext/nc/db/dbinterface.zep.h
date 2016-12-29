
extern zend_class_entry *nc_db_dbinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DbInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_savepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_rollbacktosavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_expression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, input, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_queryrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_querycell, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_queryvector, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbinterface_querymap, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_dbinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, inTransaction, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, begin, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, commit, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, savepoint, arginfo_nc_db_dbinterface_savepoint)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, releaseSavepoint, arginfo_nc_db_dbinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, rollbackToSavepoint, arginfo_nc_db_dbinterface_rollbacktosavepoint)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, quote, arginfo_nc_db_dbinterface_quote)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, expression, arginfo_nc_db_dbinterface_expression)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, execute, arginfo_nc_db_dbinterface_execute)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, query, arginfo_nc_db_dbinterface_query)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, queryRow, arginfo_nc_db_dbinterface_queryrow)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, queryCell, arginfo_nc_db_dbinterface_querycell)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, queryVector, arginfo_nc_db_dbinterface_queryvector)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, queryMap, arginfo_nc_db_dbinterface_querymap)
	PHP_ABSTRACT_ME(Nc_Db_DbInterface, getSqls, NULL)
	PHP_FE_END
};
