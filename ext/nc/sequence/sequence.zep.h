
extern zend_class_entry *nc_sequence_sequence_ce;

ZEPHIR_INIT_CLASS(Nc_Sequence_Sequence);

PHP_METHOD(Nc_Sequence_Sequence, __construct);
PHP_METHOD(Nc_Sequence_Sequence, getBackend);
PHP_METHOD(Nc_Sequence_Sequence, getName);
PHP_METHOD(Nc_Sequence_Sequence, next);
PHP_METHOD(Nc_Sequence_Sequence, restore);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_sequence___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, backend, Nc\\Sequence\\SequenceBackendInterface, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_sequence_restore, 0, 0, 1)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_sequence_sequence_method_entry) {
	PHP_ME(Nc_Sequence_Sequence, __construct, arginfo_nc_sequence_sequence___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Sequence_Sequence, getBackend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Sequence, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Sequence, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Sequence, restore, arginfo_nc_sequence_sequence_restore, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
