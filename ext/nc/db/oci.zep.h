
extern zend_class_entry *nc_db_oci_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Oci);

PHP_METHOD(Nc_Db_Oci, __construct);
PHP_METHOD(Nc_Db_Oci, begin);
PHP_METHOD(Nc_Db_Oci, commit);
PHP_METHOD(Nc_Db_Oci, rollback);
PHP_METHOD(Nc_Db_Oci, quote);
PHP_METHOD(Nc_Db_Oci, query);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_oci___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, passwd)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_oci_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_oci_query, 0, 0, 2)
	ZEND_ARG_INFO(0, flag)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_oci_method_entry) {
	PHP_ME(Nc_Db_Oci, __construct, arginfo_nc_db_oci___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Db_Oci, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci, quote, arginfo_nc_db_oci_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Oci, query, arginfo_nc_db_oci_query, ZEND_ACC_PUBLIC)
  PHP_FE_END
};