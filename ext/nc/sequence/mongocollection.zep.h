
extern zend_class_entry *nc_sequence_mongocollection_ce;

ZEPHIR_INIT_CLASS(Nc_Sequence_MongoCollection);

PHP_METHOD(Nc_Sequence_MongoCollection, __construct);
PHP_METHOD(Nc_Sequence_MongoCollection, getMongoCollection);
PHP_METHOD(Nc_Sequence_MongoCollection, next);
PHP_METHOD(Nc_Sequence_MongoCollection, restore);
PHP_METHOD(Nc_Sequence_MongoCollection, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mongocollection___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, mongoCollection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mongocollection_next, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mongocollection_restore, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_sequence_mongocollection_method_entry) {
	PHP_ME(Nc_Sequence_MongoCollection, __construct, arginfo_nc_sequence_mongocollection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Sequence_MongoCollection, getMongoCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_MongoCollection, next, arginfo_nc_sequence_mongocollection_next, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_MongoCollection, restore, arginfo_nc_sequence_mongocollection_restore, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_MongoCollection, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
