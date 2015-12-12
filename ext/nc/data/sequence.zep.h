
extern zend_class_entry *nc_data_sequence_ce;

ZEPHIR_INIT_CLASS(Nc_Data_Sequence);

PHP_METHOD(Nc_Data_Sequence, next);
PHP_METHOD(Nc_Data_Sequence, restore);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_sequence_next, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_sequence_restore, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, sequences, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_data_sequence_method_entry) {
	PHP_ME(Nc_Data_Sequence, next, arginfo_nc_data_sequence_next, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Sequence, restore, arginfo_nc_data_sequence_restore, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
