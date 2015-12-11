
extern zend_class_entry *nc_db_entity_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Entity);

PHP_METHOD(Nc_Db_Entity, __construct);
PHP_METHOD(Nc_Db_Entity, getModel);
PHP_METHOD(Nc_Db_Entity, asArray);
PHP_METHOD(Nc_Db_Entity, isNew);
PHP_METHOD(Nc_Db_Entity, isDirty);
PHP_METHOD(Nc_Db_Entity, setCollection);
PHP_METHOD(Nc_Db_Entity, hasCollection);
PHP_METHOD(Nc_Db_Entity, getCollection);
PHP_METHOD(Nc_Db_Entity, primaryKeyValue);
PHP_METHOD(Nc_Db_Entity, set);
PHP_METHOD(Nc_Db_Entity, __set);
PHP_METHOD(Nc_Db_Entity, __get);
PHP_METHOD(Nc_Db_Entity, save);
PHP_METHOD(Nc_Db_Entity, drop);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_entity___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Nc\\Db\\Model, 0)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_entity_setcollection, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Nc\\Db\\Collection, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_entity_set, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, updates, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_entity___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_entity___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_entity_method_entry) {
	PHP_ME(Nc_Db_Entity, __construct, arginfo_nc_db_entity___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Db_Entity, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, asArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, isNew, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, isDirty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, setCollection, arginfo_nc_db_entity_setcollection, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, hasCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, getCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, primaryKeyValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, set, arginfo_nc_db_entity_set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, __set, arginfo_nc_db_entity___set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, __get, arginfo_nc_db_entity___get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Entity, drop, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
