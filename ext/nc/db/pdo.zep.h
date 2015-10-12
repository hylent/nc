
extern zend_class_entry *nc_db_pdo_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Pdo);

PHP_METHOD(Nc_Db_Pdo, __construct);
PHP_METHOD(Nc_Db_Pdo, quote);
PHP_METHOD(Nc_Db_Pdo, query);
PHP_METHOD(Nc_Db_Pdo, tryToBegin);
PHP_METHOD(Nc_Db_Pdo, tryToCommit);
PHP_METHOD(Nc_Db_Pdo, tryToRollback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_pdo_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_pdo_query, 0, 0, 2)
	ZEND_ARG_INFO(0, flag)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_pdo_method_entry) {
	PHP_ME(Nc_Db_Pdo, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Db_Pdo, quote, arginfo_nc_db_pdo_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Pdo, query, arginfo_nc_db_pdo_query, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Pdo, tryToBegin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Pdo, tryToCommit, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Pdo, tryToRollback, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
