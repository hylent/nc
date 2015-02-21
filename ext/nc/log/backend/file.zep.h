
extern zend_class_entry *nc_log_backend_file_ce;

ZEPHIR_INIT_CLASS(Nc_Log_Backend_File);

PHP_METHOD(Nc_Log_Backend_File, __construct);
PHP_METHOD(Nc_Log_Backend_File, processLogs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_backend_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, logLevels, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_backend_file_processlogs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, logs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_backend_file_method_entry) {
	PHP_ME(Nc_Log_Backend_File, __construct, arginfo_nc_log_backend_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Log_Backend_File, processLogs, arginfo_nc_log_backend_file_processlogs, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
