
extern zend_class_entry *nc_log_backend_nil_ce;

ZEPHIR_INIT_CLASS(Nc_Log_Backend_Nil);

PHP_METHOD(Nc_Log_Backend_Nil, processLogs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_backend_nil_processlogs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, logs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_backend_nil_method_entry) {
	PHP_ME(Nc_Log_Backend_Nil, processLogs, arginfo_nc_log_backend_nil_processlogs, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
