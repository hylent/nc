
extern zend_class_entry *nc_std_ratelimiter_ce;

ZEPHIR_INIT_CLASS(Nc_Std_RateLimiter);

PHP_METHOD(Nc_Std_RateLimiter, __construct);
PHP_METHOD(Nc_Std_RateLimiter, pass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_ratelimiter___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, backend, Nc\\Std\\RateLimiterBackendInterface, 0)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_ratelimiter_pass, 0, 0, 2)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_ratelimiter_method_entry) {
	PHP_ME(Nc_Std_RateLimiter, __construct, arginfo_nc_std_ratelimiter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_RateLimiter, pass, arginfo_nc_std_ratelimiter_pass, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
