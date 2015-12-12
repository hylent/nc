
extern zend_class_entry *nc_logger_loggerinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Logger_LoggerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerinterface_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_logger_loggerinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Logger_LoggerInterface, log, arginfo_nc_logger_loggerinterface_log)
	PHP_FE_END
};
