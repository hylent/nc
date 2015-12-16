
extern zend_class_entry *nc_std_groupedredishashserialized_ce;

ZEPHIR_INIT_CLASS(Nc_Std_GroupedRedisHashSerialized);

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, serializeValue);
PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, unserializeValue);
PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, setGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, getGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, setManyGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, getManyGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, setAllGrouped);
PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, getAllGrouped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishashserialized_serializevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishashserialized_unserializevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishashserialized_setgrouped, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishashserialized_getgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishashserialized_setmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishashserialized_getmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishashserialized_setallgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedredishashserialized_getallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_groupedredishashserialized_method_entry) {
	PHP_ME(Nc_Std_GroupedRedisHashSerialized, serializeValue, arginfo_nc_std_groupedredishashserialized_serializevalue, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHashSerialized, unserializeValue, arginfo_nc_std_groupedredishashserialized_unserializevalue, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHashSerialized, setGrouped, arginfo_nc_std_groupedredishashserialized_setgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHashSerialized, getGrouped, arginfo_nc_std_groupedredishashserialized_getgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHashSerialized, setManyGrouped, arginfo_nc_std_groupedredishashserialized_setmanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHashSerialized, getManyGrouped, arginfo_nc_std_groupedredishashserialized_getmanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHashSerialized, setAllGrouped, arginfo_nc_std_groupedredishashserialized_setallgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedRedisHashSerialized, getAllGrouped, arginfo_nc_std_groupedredishashserialized_getallgrouped, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
