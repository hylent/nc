
extern zend_class_entry *nc_db_pdomysql_ce;

ZEPHIR_INIT_CLASS(Nc_Db_PdoMysql);

PHP_METHOD(Nc_Db_PdoMysql, insert);
PHP_METHOD(Nc_Db_PdoMysql, upsert);
PHP_METHOD(Nc_Db_PdoMysql, countAndSelect);
PHP_METHOD(Nc_Db_PdoMysql, parsePagination);
PHP_METHOD(Nc_Db_PdoMysql, parseRandomOrder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_pdomysql_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
	ZEND_ARG_INFO(0, upsert)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_pdomysql_upsert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_pdomysql_countandselect, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_INFO(0, fetch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_pdomysql_parsepagination, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_pdomysql_method_entry) {
	PHP_ME(Nc_Db_PdoMysql, insert, arginfo_nc_db_pdomysql_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_PdoMysql, upsert, arginfo_nc_db_pdomysql_upsert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_PdoMysql, countAndSelect, arginfo_nc_db_pdomysql_countandselect, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_PdoMysql, parsePagination, arginfo_nc_db_pdomysql_parsepagination, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_PdoMysql, parseRandomOrder, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
