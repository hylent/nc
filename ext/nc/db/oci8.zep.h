
extern zend_class_entry *nc_db_oci8_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Oci8);

PHP_METHOD(Nc_Db_Oci8, __construct);
PHP_METHOD(Nc_Db_Oci8, getInternalHandler);
PHP_METHOD(Nc_Db_Oci8, quote);
PHP_METHOD(Nc_Db_Oci8, queryAndFetch);
PHP_METHOD(Nc_Db_Oci8, upsert);
PHP_METHOD(Nc_Db_Oci8, parsePagination);
PHP_METHOD(Nc_Db_Oci8, parseRandomOrder);
PHP_METHOD(Nc_Db_Oci8, tryToBegin);
PHP_METHOD(Nc_Db_Oci8, tryToCommit);
PHP_METHOD(Nc_Db_Oci8, tryToRollback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_oci8___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, passwd)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_oci8_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_oci8_queryandfetch, 0, 0, 2)
	ZEND_ARG_INFO(0, fetch)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_oci8_upsert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_oci8_parsepagination, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_oci8_method_entry) {
	PHP_ME(Nc_Db_Oci8, __construct, arginfo_nc_db_oci8___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Db_Oci8, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci8, quote, arginfo_nc_db_oci8_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci8, queryAndFetch, arginfo_nc_db_oci8_queryandfetch, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci8, upsert, arginfo_nc_db_oci8_upsert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci8, parsePagination, arginfo_nc_db_oci8_parsepagination, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci8, parseRandomOrder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci8, tryToBegin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Oci8, tryToCommit, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Oci8, tryToRollback, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
