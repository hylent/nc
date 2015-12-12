
extern zend_class_entry *nc_logger_logclosure_ce;

ZEPHIR_INIT_CLASS(Nc_Logger_LogClosure);

PHP_METHOD(Nc_Logger_LogClosure, __construct);
PHP_METHOD(Nc_Logger_LogClosure, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_logclosure___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logClosure, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_logclosure_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_logger_logclosure_method_entry) {
	PHP_ME(Nc_Logger_LogClosure, __construct, arginfo_nc_logger_logclosure___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Logger_LogClosure, log, arginfo_nc_logger_logclosure_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
