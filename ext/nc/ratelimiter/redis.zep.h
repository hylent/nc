
extern zend_class_entry *nc_ratelimiter_redis_ce;

ZEPHIR_INIT_CLASS(Nc_RateLimiter_Redis);

PHP_METHOD(Nc_RateLimiter_Redis, __construct);
PHP_METHOD(Nc_RateLimiter_Redis, getRedis);
PHP_METHOD(Nc_RateLimiter_Redis, getPrefix);
PHP_METHOD(Nc_RateLimiter_Redis, passRateLimits);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_ratelimiter_redis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_ratelimiter_redis_passratelimits, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, rateLimits, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_ratelimiter_redis_method_entry) {
	PHP_ME(Nc_RateLimiter_Redis, __construct, arginfo_nc_ratelimiter_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_RateLimiter_Redis, getRedis, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_RateLimiter_Redis, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_RateLimiter_Redis, passRateLimits, arginfo_nc_ratelimiter_redis_passratelimits, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
