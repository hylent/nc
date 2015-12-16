
extern zend_class_entry *nc_std_groupedredishash_ce;

ZEPHIR_INIT_CLASS(Nc_Std_GroupedRedisHash);

PHP_METHOD(Nc_Std_GroupedRedisHash, __construct);
PHP_METHOD(Nc_Std_GroupedRedisHash, setGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHash, getGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHash, deleteGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHash, setManyGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHash, getManyGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHash, deleteManyGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHash, setAllGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHash, getAllGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHash, deleteAllGrouped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_setgrouped, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_getgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_deletegrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_setmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_getmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_deletemanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_setallgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_getallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishash_deleteallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_groupedredishash_method_entry) {
	PHP_ME(Nc_Std_GroupedRedisHash, __construct, arginfo_nc_std_groupedredishash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_GroupedRedisHash, setGrouped, arginfo_nc_std_groupedredishash_setgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHash, getGrouped, arginfo_nc_std_groupedredishash_getgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHash, deleteGrouped, arginfo_nc_std_groupedredishash_deletegrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHash, setManyGrouped, arginfo_nc_std_groupedredishash_setmanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHash, getManyGrouped, arginfo_nc_std_groupedredishash_getmanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHash, deleteManyGrouped, arginfo_nc_std_groupedredishash_deletemanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHash, setAllGrouped, arginfo_nc_std_groupedredishash_setallgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHash, getAllGrouped, arginfo_nc_std_groupedredishash_getallgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHash, deleteAllGrouped, arginfo_nc_std_groupedredishash_deleteallgrouped, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
