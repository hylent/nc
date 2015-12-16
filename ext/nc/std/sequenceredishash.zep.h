
extern zend_class_entry *nc_std_sequenceredishash_ce;

ZEPHIR_INIT_CLASS(Nc_Std_SequenceRedisHash);

PHP_METHOD(Nc_Std_SequenceRedisHash, __construct);
PHP_METHOD(Nc_Std_SequenceRedisHash, getNextSequence);
PHP_METHOD(Nc_Std_SequenceRedisHash, restoreSequence);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequenceredishash___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, hashName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequenceredishash_getnextsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequenceredishash_restoresequence, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_sequenceredishash_method_entry) {
	PHP_ME(Nc_Std_SequenceRedisHash, __construct, arginfo_nc_std_sequenceredishash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_SequenceRedisHash, getNextSequence, arginfo_nc_std_sequenceredishash_getnextsequence, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_SequenceRedisHash, restoreSequence, arginfo_nc_std_sequenceredishash_restoresequence, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
