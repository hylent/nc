
extern zend_class_entry *nc_ratelimiter_mysql_ce;

ZEPHIR_INIT_CLASS(Nc_RateLimiter_Mysql);

PHP_METHOD(Nc_RateLimiter_Mysql, __construct);
PHP_METHOD(Nc_RateLimiter_Mysql, getDaoMysql);
PHP_METHOD(Nc_RateLimiter_Mysql, initialize);
PHP_METHOD(Nc_RateLimiter_Mysql, getNumRetries);
PHP_METHOD(Nc_RateLimiter_Mysql, passRateLimits);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_ratelimiter_mysql___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, db, Nc\\Db\\DbInterface, 0)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, numRetries)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_ratelimiter_mysql_passratelimits, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, rateLimits, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_ratelimiter_mysql_method_entry) {
	PHP_ME(Nc_RateLimiter_Mysql, __construct, arginfo_nc_ratelimiter_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_RateLimiter_Mysql, getDaoMysql, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_RateLimiter_Mysql, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_RateLimiter_Mysql, getNumRetries, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_RateLimiter_Mysql, passRateLimits, arginfo_nc_ratelimiter_mysql_passratelimits, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
