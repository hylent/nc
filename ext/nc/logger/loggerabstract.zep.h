
extern zend_class_entry *nc_logger_loggerabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Logger_LoggerAbstract);

PHP_METHOD(Nc_Logger_LoggerAbstract, stringifyLog);
PHP_METHOD(Nc_Logger_LoggerAbstract, emergency);
PHP_METHOD(Nc_Logger_LoggerAbstract, alert);
PHP_METHOD(Nc_Logger_LoggerAbstract, critical);
PHP_METHOD(Nc_Logger_LoggerAbstract, error);
PHP_METHOD(Nc_Logger_LoggerAbstract, warning);
PHP_METHOD(Nc_Logger_LoggerAbstract, notice);
PHP_METHOD(Nc_Logger_LoggerAbstract, info);
PHP_METHOD(Nc_Logger_LoggerAbstract, debug);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_stringifylog, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_loggerabstract_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_logger_loggerabstract_method_entry) {
	PHP_ME(Nc_Logger_LoggerAbstract, stringifyLog, arginfo_nc_logger_loggerabstract_stringifylog, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Logger_LoggerAbstract, emergency, arginfo_nc_logger_loggerabstract_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_LoggerAbstract, alert, arginfo_nc_logger_loggerabstract_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_LoggerAbstract, critical, arginfo_nc_logger_loggerabstract_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_LoggerAbstract, error, arginfo_nc_logger_loggerabstract_error, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_LoggerAbstract, warning, arginfo_nc_logger_loggerabstract_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_LoggerAbstract, notice, arginfo_nc_logger_loggerabstract_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_LoggerAbstract, info, arginfo_nc_logger_loggerabstract_info, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_LoggerAbstract, debug, arginfo_nc_logger_loggerabstract_debug, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
