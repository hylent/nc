
extern zend_class_entry *nc_std_ratelimiterinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Std_RateLimiterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_ratelimiterinterface_passratelimiter, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_ratelimiterinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Std_RateLimiterInterface, passRateLimiter, arginfo_nc_std_ratelimiterinterface_passratelimiter)
	PHP_FE_END
};
