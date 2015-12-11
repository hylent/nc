
extern zend_class_entry *nc_db_pdopgsql_ce;

ZEPHIR_INIT_CLASS(Nc_Db_PdoPgsql);

PHP_METHOD(Nc_Db_PdoPgsql, paginationSql);
PHP_METHOD(Nc_Db_PdoPgsql, randomOrderSql);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_pdopgsql_paginationsql, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_pdopgsql_method_entry) {
	PHP_ME(Nc_Db_PdoPgsql, paginationSql, arginfo_nc_db_pdopgsql_paginationsql, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_PdoPgsql, randomOrderSql, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
