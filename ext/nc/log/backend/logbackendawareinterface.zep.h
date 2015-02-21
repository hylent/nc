
extern zend_class_entry *nc_log_backend_logbackendawareinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Log_Backend_LogBackendAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_backend_logbackendawareinterface_setlogbackend, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logBackend, Nc\\Log\\Backend\\LogBackendInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_backend_logbackendawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Log_Backend_LogBackendAwareInterface, setLogBackend, arginfo_nc_log_backend_logbackendawareinterface_setlogbackend)
	PHP_ABSTRACT_ME(Nc_Log_Backend_LogBackendAwareInterface, getLogBackend, NULL)
  PHP_FE_END
};
