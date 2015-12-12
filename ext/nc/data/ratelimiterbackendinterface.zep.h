
extern zend_class_entry *nc_data_ratelimiterbackendinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Data_RateLimiterBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_ratelimiterbackendinterface_passratelimiter, 0, 0, 4)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_data_ratelimiterbackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Data_RateLimiterBackendInterface, passRateLimiter, arginfo_nc_data_ratelimiterbackendinterface_passratelimiter)
	PHP_FE_END
};
