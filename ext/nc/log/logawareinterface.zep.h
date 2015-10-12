
extern zend_class_entry *nc_log_logawareinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Log_LogAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_logawareinterface_setlog, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, log, Nc\\Log\\LogInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_logawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Log_LogAwareInterface, setLog, arginfo_nc_log_logawareinterface_setlog)
	PHP_ABSTRACT_ME(Nc_Log_LogAwareInterface, getLog, NULL)
	PHP_FE_END
};
