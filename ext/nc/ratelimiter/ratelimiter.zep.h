
extern zend_class_entry *nc_ratelimiter_ratelimiter_ce;

ZEPHIR_INIT_CLASS(Nc_RateLimiter_RateLimiter);

PHP_METHOD(Nc_RateLimiter_RateLimiter, __construct);
PHP_METHOD(Nc_RateLimiter_RateLimiter, getBackend);
PHP_METHOD(Nc_RateLimiter_RateLimiter, getName);
PHP_METHOD(Nc_RateLimiter_RateLimiter, pass);
PHP_METHOD(Nc_RateLimiter_RateLimiter, passRateLimits);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_ratelimiter_ratelimiter___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, backend, Nc\\RateLimiter\\RateLimiterBackendInterface, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_ratelimiter_ratelimiter_pass, 0, 0, 2)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_ratelimiter_ratelimiter_passratelimits, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rateLimits, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_ratelimiter_ratelimiter_method_entry) {
	PHP_ME(Nc_RateLimiter_RateLimiter, __construct, arginfo_nc_ratelimiter_ratelimiter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_RateLimiter_RateLimiter, getBackend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_RateLimiter_RateLimiter, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_RateLimiter_RateLimiter, pass, arginfo_nc_ratelimiter_ratelimiter_pass, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_RateLimiter_RateLimiter, passRateLimits, arginfo_nc_ratelimiter_ratelimiter_passratelimits, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
