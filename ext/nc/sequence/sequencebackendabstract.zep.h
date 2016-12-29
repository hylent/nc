
extern zend_class_entry *nc_sequence_sequencebackendabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Sequence_SequenceBackendAbstract);

PHP_METHOD(Nc_Sequence_SequenceBackendAbstract, getSequence);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_sequencebackendabstract_getsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_sequence_sequencebackendabstract_method_entry) {
	PHP_ME(Nc_Sequence_SequenceBackendAbstract, getSequence, arginfo_nc_sequence_sequencebackendabstract_getsequence, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
