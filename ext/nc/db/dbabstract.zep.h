
extern zend_class_entry *nc_db_dbabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DbAbstract);

PHP_METHOD(Nc_Db_DbAbstract, inTransaction);
PHP_METHOD(Nc_Db_DbAbstract, begin);
PHP_METHOD(Nc_Db_DbAbstract, commit);
PHP_METHOD(Nc_Db_DbAbstract, rollback);
PHP_METHOD(Nc_Db_DbAbstract, savepoint);
PHP_METHOD(Nc_Db_DbAbstract, releaseSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, rollbackToSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, expression);
PHP_METHOD(Nc_Db_DbAbstract, execute);
PHP_METHOD(Nc_Db_DbAbstract, query);
PHP_METHOD(Nc_Db_DbAbstract, queryRow);
PHP_METHOD(Nc_Db_DbAbstract, queryCell);
PHP_METHOD(Nc_Db_DbAbstract, queryVector);
PHP_METHOD(Nc_Db_DbAbstract, queryMap);
PHP_METHOD(Nc_Db_DbAbstract, getSqls);
PHP_METHOD(Nc_Db_DbAbstract, tryToBegin);
PHP_METHOD(Nc_Db_DbAbstract, tryToCommit);
PHP_METHOD(Nc_Db_DbAbstract, tryToRollback);
PHP_METHOD(Nc_Db_DbAbstract, executeQuery);
PHP_METHOD(Nc_Db_DbAbstract, addSql);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_savepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_rollbacktosavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_expression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, input, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_queryrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_querycell, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_queryvector, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_querymap, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_executequery, 0, 0, 2)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, executionOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_addsql, 0, 0, 3)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, startTime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_dbabstract_method_entry) {
	PHP_ME(Nc_Db_DbAbstract, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, savepoint, arginfo_nc_db_dbabstract_savepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, releaseSavepoint, arginfo_nc_db_dbabstract_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, rollbackToSavepoint, arginfo_nc_db_dbabstract_rollbacktosavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, expression, arginfo_nc_db_dbabstract_expression, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, execute, arginfo_nc_db_dbabstract_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, query, arginfo_nc_db_dbabstract_query, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, queryRow, arginfo_nc_db_dbabstract_queryrow, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, queryCell, arginfo_nc_db_dbabstract_querycell, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, queryVector, arginfo_nc_db_dbabstract_queryvector, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, queryMap, arginfo_nc_db_dbabstract_querymap, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, getSqls, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, tryToBegin, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, tryToCommit, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, tryToRollback, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, executeQuery, arginfo_nc_db_dbabstract_executequery, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, addSql, arginfo_nc_db_dbabstract_addsql, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
