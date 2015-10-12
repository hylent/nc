
extern zend_class_entry *nc_log_logger_ce;

ZEPHIR_INIT_CLASS(Nc_Log_Logger);

PHP_METHOD(Nc_Log_Logger, setLogBackend);
PHP_METHOD(Nc_Log_Logger, getLogBackend);
PHP_METHOD(Nc_Log_Logger, emergency);
PHP_METHOD(Nc_Log_Logger, alert);
PHP_METHOD(Nc_Log_Logger, critical);
PHP_METHOD(Nc_Log_Logger, error);
PHP_METHOD(Nc_Log_Logger, warning);
PHP_METHOD(Nc_Log_Logger, notice);
PHP_METHOD(Nc_Log_Logger, info);
PHP_METHOD(Nc_Log_Logger, debug);
PHP_METHOD(Nc_Log_Logger, log);
PHP_METHOD(Nc_Log_Logger, flush);
PHP_METHOD(Nc_Log_Logger, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_setlogbackend, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logBackend, Nc\\Log\\Backend\\LogBackendInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_logger_method_entry) {
	PHP_ME(Nc_Log_Logger, setLogBackend, arginfo_nc_log_logger_setlogbackend, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, getLogBackend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, emergency, arginfo_nc_log_logger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, alert, arginfo_nc_log_logger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, critical, arginfo_nc_log_logger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, error, arginfo_nc_log_logger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, warning, arginfo_nc_log_logger_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, notice, arginfo_nc_log_logger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, info, arginfo_nc_log_logger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, debug, arginfo_nc_log_logger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, log, arginfo_nc_log_logger_log, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
