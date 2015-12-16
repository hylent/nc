
extern zend_class_entry *nc_std_groupedmongocollections_ce;

ZEPHIR_INIT_CLASS(Nc_Std_GroupedMongoCollections);

PHP_METHOD(Nc_Std_GroupedMongoCollections, __construct);
PHP_METHOD(Nc_Std_GroupedMongoCollections, setGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, getGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, deleteGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, setManyGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, getManyGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, deleteManyGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, setAllGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, getAllGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, deleteAllGrouped);
PHP_METHOD(Nc_Std_GroupedMongoCollections, collection);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, mongoDb)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_setgrouped, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_getgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_deletegrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_setmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_getmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_deletemanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_setallgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_getallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_deleteallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedmongocollections_collection, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_groupedmongocollections_method_entry) {
	PHP_ME(Nc_Std_GroupedMongoCollections, __construct, arginfo_nc_std_groupedmongocollections___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_GroupedMongoCollections, setGrouped, arginfo_nc_std_groupedmongocollections_setgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, getGrouped, arginfo_nc_std_groupedmongocollections_getgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, deleteGrouped, arginfo_nc_std_groupedmongocollections_deletegrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, setManyGrouped, arginfo_nc_std_groupedmongocollections_setmanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, getManyGrouped, arginfo_nc_std_groupedmongocollections_getmanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, deleteManyGrouped, arginfo_nc_std_groupedmongocollections_deletemanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, setAllGrouped, arginfo_nc_std_groupedmongocollections_setallgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, getAllGrouped, arginfo_nc_std_groupedmongocollections_getallgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, deleteAllGrouped, arginfo_nc_std_groupedmongocollections_deleteallgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedMongoCollections, collection, arginfo_nc_std_groupedmongocollections_collection, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
