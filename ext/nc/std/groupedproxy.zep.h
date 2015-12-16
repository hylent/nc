
extern zend_class_entry *nc_std_groupedproxy_ce;

ZEPHIR_INIT_CLASS(Nc_Std_GroupedProxy);

PHP_METHOD(Nc_Std_GroupedProxy, __construct);
PHP_METHOD(Nc_Std_GroupedProxy, setGrouped);
PHP_METHOD(Nc_Std_GroupedProxy, getGrouped);
PHP_METHOD(Nc_Std_GroupedProxy, deleteGrouped);
PHP_METHOD(Nc_Std_GroupedProxy, setManyGrouped);
PHP_METHOD(Nc_Std_GroupedProxy, getManyGrouped);
PHP_METHOD(Nc_Std_GroupedProxy, deleteManyGrouped);
PHP_METHOD(Nc_Std_GroupedProxy, setAllGrouped);
PHP_METHOD(Nc_Std_GroupedProxy, getAllGrouped);
PHP_METHOD(Nc_Std_GroupedProxy, deleteAllGrouped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, frontend, Nc\\Std\\GroupedInterface, 0)
	ZEND_ARG_OBJ_INFO(0, backend, Nc\\Std\\GroupedInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_setgrouped, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_getgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_deletegrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_setmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_getmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_deletemanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_setallgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_getallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedproxy_deleteallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_groupedproxy_method_entry) {
	PHP_ME(Nc_Std_GroupedProxy, __construct, arginfo_nc_std_groupedproxy___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_GroupedProxy, setGrouped, arginfo_nc_std_groupedproxy_setgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedProxy, getGrouped, arginfo_nc_std_groupedproxy_getgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedProxy, deleteGrouped, arginfo_nc_std_groupedproxy_deletegrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedProxy, setManyGrouped, arginfo_nc_std_groupedproxy_setmanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedProxy, getManyGrouped, arginfo_nc_std_groupedproxy_getmanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedProxy, deleteManyGrouped, arginfo_nc_std_groupedproxy_deletemanygrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedProxy, setAllGrouped, arginfo_nc_std_groupedproxy_setallgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedProxy, getAllGrouped, arginfo_nc_std_groupedproxy_getallgrouped, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_GroupedProxy, deleteAllGrouped, arginfo_nc_std_groupedproxy_deleteallgrouped, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
