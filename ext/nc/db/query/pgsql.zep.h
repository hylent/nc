
extern zend_class_entry *nc_db_query_pgsql_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Query_Pgsql);

PHP_METHOD(Nc_Db_Query_Pgsql, insert);
PHP_METHOD(Nc_Db_Query_Pgsql, getSelectAsString);
PHP_METHOD(Nc_Db_Query_Pgsql, selectAndCount);
PHP_METHOD(Nc_Db_Query_Pgsql, buildOrderBy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_pgsql_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_query_pgsql_method_entry) {
	PHP_ME(Nc_Db_Query_Pgsql, insert, arginfo_nc_db_query_pgsql_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Pgsql, getSelectAsString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Pgsql, selectAndCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Pgsql, buildOrderBy, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
