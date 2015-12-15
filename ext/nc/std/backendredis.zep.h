
extern zend_class_entry *nc_std_backendredis_ce;

ZEPHIR_INIT_CLASS(Nc_Std_BackendRedis);

PHP_METHOD(Nc_Std_BackendRedis, __construct);
PHP_METHOD(Nc_Std_BackendRedis, rateLimiter);
PHP_METHOD(Nc_Std_BackendRedis, passRateLimiter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_backendredis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_backendredis_ratelimiter, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_backendredis_passratelimiter, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_backendredis_method_entry) {
	PHP_ME(Nc_Std_BackendRedis, __construct, arginfo_nc_std_backendredis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_BackendRedis, rateLimiter, arginfo_nc_std_backendredis_ratelimiter, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_BackendRedis, passRateLimiter, arginfo_nc_std_backendredis_passratelimiter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
