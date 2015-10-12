
extern zend_class_entry *nc_log_loginterface_ce;

ZEPHIR_INIT_CLASS(Nc_Log_LogInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_loginterface_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_loginterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, emergency, arginfo_nc_log_loginterface_emergency)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, alert, arginfo_nc_log_loginterface_alert)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, critical, arginfo_nc_log_loginterface_critical)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, error, arginfo_nc_log_loginterface_error)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, warning, arginfo_nc_log_loginterface_warning)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, notice, arginfo_nc_log_loginterface_notice)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, info, arginfo_nc_log_loginterface_info)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, debug, arginfo_nc_log_loginterface_debug)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, log, arginfo_nc_log_loginterface_log)
	PHP_ABSTRACT_ME(Nc_Log_LogInterface, flush, NULL)
	PHP_FE_END
};
