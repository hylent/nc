
extern zend_class_entry *nc_log_writerinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Log_WriterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_writerinterface_appendlog, 0, 0, 1)
	ZEND_ARG_INFO(0, log)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_writerinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Log_WriterInterface, appendLog, arginfo_nc_log_writerinterface_appendlog)
	PHP_FE_END
};
