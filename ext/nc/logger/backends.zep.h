
extern zend_class_entry *nc_logger_backends_ce;

ZEPHIR_INIT_CLASS(Nc_Logger_Backends);

PHP_METHOD(Nc_Logger_Backends, addBackend);
PHP_METHOD(Nc_Logger_Backends, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_backends_addbackend, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, backend, Nc\\Logger\\LoggerBackendInterface, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_logger_backends_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_logger_backends_method_entry) {
	PHP_ME(Nc_Logger_Backends, addBackend, arginfo_nc_logger_backends_addbackend, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Logger_Backends, log, arginfo_nc_logger_backends_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
