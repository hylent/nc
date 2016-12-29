
extern zend_class_entry *nc_sequence_sequencebackendinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Sequence_SequenceBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_sequencebackendinterface_getsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_sequencebackendinterface_next, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_sequencebackendinterface_restore, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_sequence_sequencebackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Sequence_SequenceBackendInterface, getSequence, arginfo_nc_sequence_sequencebackendinterface_getsequence)
	PHP_ABSTRACT_ME(Nc_Sequence_SequenceBackendInterface, next, arginfo_nc_sequence_sequencebackendinterface_next)
	PHP_ABSTRACT_ME(Nc_Sequence_SequenceBackendInterface, restore, arginfo_nc_sequence_sequencebackendinterface_restore)
	PHP_ABSTRACT_ME(Nc_Sequence_SequenceBackendInterface, clear, NULL)
	PHP_FE_END
};
