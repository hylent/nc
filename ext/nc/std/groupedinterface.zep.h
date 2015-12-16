
extern zend_class_entry *nc_std_groupedinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Std_GroupedInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_setgrouped, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_getgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_deletegrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_setmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_getmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_deletemanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_setallgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_getallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedinterface_deleteallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_groupedinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, setGrouped, arginfo_nc_std_groupedinterface_setgrouped)
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, getGrouped, arginfo_nc_std_groupedinterface_getgrouped)
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, deleteGrouped, arginfo_nc_std_groupedinterface_deletegrouped)
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, setManyGrouped, arginfo_nc_std_groupedinterface_setmanygrouped)
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, getManyGrouped, arginfo_nc_std_groupedinterface_getmanygrouped)
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, deleteManyGrouped, arginfo_nc_std_groupedinterface_deletemanygrouped)
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, setAllGrouped, arginfo_nc_std_groupedinterface_setallgrouped)
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, getAllGrouped, arginfo_nc_std_groupedinterface_getallgrouped)
	PHP_ABSTRACT_ME(Nc_Std_GroupedInterface, deleteAllGrouped, arginfo_nc_std_groupedinterface_deleteallgrouped)
	PHP_FE_END
};
