
extern zend_class_entry *nc_log_file_ce;

ZEPHIR_INIT_CLASS(Nc_Log_File);

PHP_METHOD(Nc_Log_File, __construct);
PHP_METHOD(Nc_Log_File, getBasePath);
PHP_METHOD(Nc_Log_File, getSuffixType);
PHP_METHOD(Nc_Log_File, writeLogs);
PHP_METHOD(Nc_Log_File, getPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
	ZEND_ARG_INFO(0, suffixType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_file_writelogs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, logs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_file_method_entry) {
	PHP_ME(Nc_Log_File, __construct, arginfo_nc_log_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Log_File, getBasePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_File, getSuffixType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_File, writeLogs, arginfo_nc_log_file_writelogs, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Log_File, getPath, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
