
extern zend_class_entry *nc_std_sequenceinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Std_SequenceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequenceinterface_getnextsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequenceinterface_restoresequence, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_sequenceinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Std_SequenceInterface, getNextSequence, arginfo_nc_std_sequenceinterface_getnextsequence)
	PHP_ABSTRACT_ME(Nc_Std_SequenceInterface, restoreSequence, arginfo_nc_std_sequenceinterface_restoresequence)
	PHP_FE_END
};
