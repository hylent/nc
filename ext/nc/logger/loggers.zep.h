
extern zend_class_entry *nc_logger_loggers_ce;

ZEPHIR_INIT_CLASS(Nc_Logger_Loggers);

PHP_METHOD(Nc_Logger_Loggers, addLogger);
PHP_METHOD(Nc_Logger_Loggers, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggers_addlogger, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logger, Nc\\Logger\\LoggerInterface, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggers_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_logger_loggers_method_entry) {
	PHP_ME(Nc_Logger_Loggers, addLogger, arginfo_nc_logger_loggers_addlogger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_Loggers, log, arginfo_nc_logger_loggers_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
