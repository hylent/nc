
extern zend_class_entry *nc_logger_file_ce;

ZEPHIR_INIT_CLASS(Nc_Logger_File);

PHP_METHOD(Nc_Logger_File, __construct);
PHP_METHOD(Nc_Logger_File, setChunkSize);
PHP_METHOD(Nc_Logger_File, getChunkSize);
PHP_METHOD(Nc_Logger_File, log);
PHP_METHOD(Nc_Logger_File, flush);
PHP_METHOD(Nc_Logger_File, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_file_setchunksize, 0, 0, 1)
	ZEND_ARG_INFO(0, chunkSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_file_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_logger_file_method_entry) {
	PHP_ME(Nc_Logger_File, __construct, arginfo_nc_logger_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Logger_File, setChunkSize, arginfo_nc_logger_file_setchunksize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_File, getChunkSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_File, log, arginfo_nc_logger_file_log, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_File, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_File, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
