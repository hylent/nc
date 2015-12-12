
extern zend_class_entry *nc_data_ratelimiter_ce;

ZEPHIR_INIT_CLASS(Nc_Data_RateLimiter);

PHP_METHOD(Nc_Data_RateLimiter, pass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_ratelimiter_pass, 0, 0, 3)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_data_ratelimiter_method_entry) {
	PHP_ME(Nc_Data_RateLimiter, pass, arginfo_nc_data_ratelimiter_pass, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
