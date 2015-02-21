
extern zend_class_entry *nc_log_backend_logbackendinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Log_Backend_LogBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_backend_logbackendinterface_processlogs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, logs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_backend_logbackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Log_Backend_LogBackendInterface, processLogs, arginfo_nc_log_backend_logbackendinterface_processlogs)
  PHP_FE_END
};
