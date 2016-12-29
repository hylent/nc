
extern zend_class_entry *nc_log_writerbufferedabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Log_WriterBufferedAbstract);

PHP_METHOD(Nc_Log_WriterBufferedAbstract, setBufferSize);
PHP_METHOD(Nc_Log_WriterBufferedAbstract, getBufferSize);
PHP_METHOD(Nc_Log_WriterBufferedAbstract, appendLog);
PHP_METHOD(Nc_Log_WriterBufferedAbstract, flush);
PHP_METHOD(Nc_Log_WriterBufferedAbstract, __destruct);
PHP_METHOD(Nc_Log_WriterBufferedAbstract, writeLogs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_writerbufferedabstract_setbuffersize, 0, 0, 1)
	ZEND_ARG_INFO(0, bufferSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_writerbufferedabstract_appendlog, 0, 0, 1)
	ZEND_ARG_INFO(0, log)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_writerbufferedabstract_writelogs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, logs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_writerbufferedabstract_method_entry) {
	PHP_ME(Nc_Log_WriterBufferedAbstract, setBufferSize, arginfo_nc_log_writerbufferedabstract_setbuffersize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_WriterBufferedAbstract, getBufferSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_WriterBufferedAbstract, appendLog, arginfo_nc_log_writerbufferedabstract_appendlog, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_WriterBufferedAbstract, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_WriterBufferedAbstract, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_Log_WriterBufferedAbstract, writeLogs, arginfo_nc_log_writerbufferedabstract_writelogs, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
