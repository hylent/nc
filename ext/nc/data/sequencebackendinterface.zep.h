
extern zend_class_entry *nc_data_sequencebackendinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Data_SequenceBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_sequencebackendinterface_nextsequence, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_sequencebackendinterface_restoresequence, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, sequences, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_data_sequencebackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Data_SequenceBackendInterface, nextSequence, arginfo_nc_data_sequencebackendinterface_nextsequence)
	PHP_ABSTRACT_ME(Nc_Data_SequenceBackendInterface, restoreSequence, arginfo_nc_data_sequencebackendinterface_restoresequence)
	PHP_FE_END
};
