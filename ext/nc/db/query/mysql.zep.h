
extern zend_class_entry *nc_db_query_mysql_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Query_Mysql);

PHP_METHOD(Nc_Db_Query_Mysql, insert);
PHP_METHOD(Nc_Db_Query_Mysql, concat);
PHP_METHOD(Nc_Db_Query_Mysql, replace);
PHP_METHOD(Nc_Db_Query_Mysql, getSelectAsString);
PHP_METHOD(Nc_Db_Query_Mysql, selectAndCount);
PHP_METHOD(Nc_Db_Query_Mysql, buildOrderBy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_mysql_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_mysql_concat, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_mysql_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_query_mysql_method_entry) {
	PHP_ME(Nc_Db_Query_Mysql, insert, arginfo_nc_db_query_mysql_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Mysql, concat, arginfo_nc_db_query_mysql_concat, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Mysql, replace, arginfo_nc_db_query_mysql_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Mysql, getSelectAsString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Mysql, selectAndCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_Mysql, buildOrderBy, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
