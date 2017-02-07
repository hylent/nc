
extern zend_class_entry *nc_log_stderr_ce;

ZEPHIR_INIT_CLASS(Nc_Log_StdErr);

PHP_METHOD(Nc_Log_StdErr, __construct);
PHP_METHOD(Nc_Log_StdErr, appendLog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_stderr_appendlog, 0, 0, 1)
	ZEND_ARG_INFO(0, log)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_stderr_method_entry) {
	PHP_ME(Nc_Log_StdErr, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Log_StdErr, appendLog, arginfo_nc_log_stderr_appendlog, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
