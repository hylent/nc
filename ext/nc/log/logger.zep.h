
extern zend_class_entry *nc_log_logger_ce;

ZEPHIR_INIT_CLASS(Nc_Log_Logger);

PHP_METHOD(Nc_Log_Logger, generateLogId);
PHP_METHOD(Nc_Log_Logger, __construct);
PHP_METHOD(Nc_Log_Logger, getLogId);
PHP_METHOD(Nc_Log_Logger, setFallbackWriter);
PHP_METHOD(Nc_Log_Logger, getFallbackWriter);
PHP_METHOD(Nc_Log_Logger, offsetSet);
PHP_METHOD(Nc_Log_Logger, offsetGet);
PHP_METHOD(Nc_Log_Logger, offsetExists);
PHP_METHOD(Nc_Log_Logger, offsetUnset);
PHP_METHOD(Nc_Log_Logger, emergency);
PHP_METHOD(Nc_Log_Logger, alert);
PHP_METHOD(Nc_Log_Logger, critical);
PHP_METHOD(Nc_Log_Logger, error);
PHP_METHOD(Nc_Log_Logger, warning);
PHP_METHOD(Nc_Log_Logger, notice);
PHP_METHOD(Nc_Log_Logger, info);
PHP_METHOD(Nc_Log_Logger, debug);
PHP_METHOD(Nc_Log_Logger, log);
PHP_METHOD(Nc_Log_Logger, main);
PHP_METHOD(Nc_Log_Logger, __destruct);
PHP_METHOD(Nc_Log_Logger, stringifyLog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, logId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_setfallbackwriter, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, writer, Nc\\Log\\WriterInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, writer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_main, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, duplicate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logger_stringifylog, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_logger_method_entry) {
	PHP_ME(Nc_Log_Logger, generateLogId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Log_Logger, __construct, arginfo_nc_log_logger___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Log_Logger, getLogId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, setFallbackWriter, arginfo_nc_log_logger_setfallbackwriter, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, getFallbackWriter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, offsetSet, arginfo_nc_log_logger_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, offsetGet, arginfo_nc_log_logger_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, offsetExists, arginfo_nc_log_logger_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, offsetUnset, arginfo_nc_log_logger_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, emergency, arginfo_nc_log_logger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, alert, arginfo_nc_log_logger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, critical, arginfo_nc_log_logger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, error, arginfo_nc_log_logger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, warning, arginfo_nc_log_logger_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, notice, arginfo_nc_log_logger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, info, arginfo_nc_log_logger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, debug, arginfo_nc_log_logger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, log, arginfo_nc_log_logger_log, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, main, arginfo_nc_log_logger_main, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_Logger, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_Log_Logger, stringifyLog, arginfo_nc_log_logger_stringifylog, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
