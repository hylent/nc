
extern zend_class_entry *nc_std_sequencemongocollection_ce;

ZEPHIR_INIT_CLASS(Nc_Std_SequenceMongoCollection);

PHP_METHOD(Nc_Std_SequenceMongoCollection, __construct);
PHP_METHOD(Nc_Std_SequenceMongoCollection, getNextSequence);
PHP_METHOD(Nc_Std_SequenceMongoCollection, restoreSequence);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequencemongocollection___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, mongoCollection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequencemongocollection_getnextsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequencemongocollection_restoresequence, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_sequencemongocollection_method_entry) {
	PHP_ME(Nc_Std_SequenceMongoCollection, __construct, arginfo_nc_std_sequencemongocollection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_SequenceMongoCollection, getNextSequence, arginfo_nc_std_sequencemongocollection_getnextsequence, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_SequenceMongoCollection, restoreSequence, arginfo_nc_std_sequencemongocollection_restoresequence, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
