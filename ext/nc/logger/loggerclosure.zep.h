
extern zend_class_entry *nc_logger_loggerclosure_ce;

ZEPHIR_INIT_CLASS(Nc_Logger_LoggerClosure);

PHP_METHOD(Nc_Logger_LoggerClosure, __construct);
PHP_METHOD(Nc_Logger_LoggerClosure, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerclosure___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, loggerClosure, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerclosure_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_logger_loggerclosure_method_entry) {
	PHP_ME(Nc_Logger_LoggerClosure, __construct, arginfo_nc_logger_loggerclosure___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Logger_LoggerClosure, log, arginfo_nc_logger_loggerclosure_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
