
extern zend_class_entry *nc_log_nil_ce;

ZEPHIR_INIT_CLASS(Nc_Log_Nil);

PHP_METHOD(Nc_Log_Nil, appendLog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_nil_appendlog, 0, 0, 1)
	ZEND_ARG_INFO(0, log)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_nil_method_entry) {
	PHP_ME(Nc_Log_Nil, appendLog, arginfo_nc_log_nil_appendlog, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
