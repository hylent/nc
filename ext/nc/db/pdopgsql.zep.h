
extern zend_class_entry *nc_db_pdopgsql_ce;

ZEPHIR_INIT_CLASS(Nc_Db_PdoPgsql);

PHP_METHOD(Nc_Db_PdoPgsql, parsePagination);
PHP_METHOD(Nc_Db_PdoPgsql, parseRandomOrder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_pdopgsql_parsepagination, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_pdopgsql_method_entry) {
	PHP_ME(Nc_Db_PdoPgsql, parsePagination, arginfo_nc_db_pdopgsql_parsepagination, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_PdoPgsql, parseRandomOrder, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
