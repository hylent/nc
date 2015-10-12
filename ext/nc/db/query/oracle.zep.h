
extern zend_class_entry *nc_db_query_oracle_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Query_Oracle);

PHP_METHOD(Nc_Db_Query_Oracle, insert);
PHP_METHOD(Nc_Db_Query_Oracle, replace);
PHP_METHOD(Nc_Db_Query_Oracle, getSelectAsString);
PHP_METHOD(Nc_Db_Query_Oracle, selectAndCount);
PHP_METHOD(Nc_Db_Query_Oracle, buildOrderBy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_oracle_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_oracle_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_query_oracle_method_entry) {
	PHP_ME(Nc_Db_Query_Oracle, insert, arginfo_nc_db_query_oracle_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Oracle, replace, arginfo_nc_db_query_oracle_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Oracle, getSelectAsString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Oracle, selectAndCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Oracle, buildOrderBy, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
