
extern zend_class_entry *nc_db_collection_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Collection);

PHP_METHOD(Nc_Db_Collection, __construct);
PHP_METHOD(Nc_Db_Collection, getModel);
PHP_METHOD(Nc_Db_Collection, at);
PHP_METHOD(Nc_Db_Collection, id);
PHP_METHOD(Nc_Db_Collection, count);
PHP_METHOD(Nc_Db_Collection, rewind);
PHP_METHOD(Nc_Db_Collection, valid);
PHP_METHOD(Nc_Db_Collection, current);
PHP_METHOD(Nc_Db_Collection, key);
PHP_METHOD(Nc_Db_Collection, next);
PHP_METHOD(Nc_Db_Collection, data);
PHP_METHOD(Nc_Db_Collection, indexedData);
PHP_METHOD(Nc_Db_Collection, groupedData);
PHP_METHOD(Nc_Db_Collection, groupIndexedData);
PHP_METHOD(Nc_Db_Collection, values);
PHP_METHOD(Nc_Db_Collection, uniqueValues);
PHP_METHOD(Nc_Db_Collection, indexedValues);
PHP_METHOD(Nc_Db_Collection, groupedValues);
PHP_METHOD(Nc_Db_Collection, groupIndexedValues);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Nc\\Db\\Model, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_at, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, asArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_id, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, asArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_current, 0, 0, 0)
	ZEND_ARG_INFO(0, asArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_indexeddata, 0, 0, 1)
	ZEND_ARG_INFO(0, indexKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_groupeddata, 0, 0, 1)
	ZEND_ARG_INFO(0, groupKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_groupindexeddata, 0, 0, 2)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, indexKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_values, 0, 0, 1)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_uniquevalues, 0, 0, 1)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_indexedvalues, 0, 0, 2)
	ZEND_ARG_INFO(0, indexKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_groupedvalues, 0, 0, 2)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_collection_groupindexedvalues, 0, 0, 3)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, indexKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_collection_method_entry) {
	PHP_ME(Nc_Db_Collection, __construct, arginfo_nc_db_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Db_Collection, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, at, arginfo_nc_db_collection_at, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, id, arginfo_nc_db_collection_id, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, current, arginfo_nc_db_collection_current, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, data, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, indexedData, arginfo_nc_db_collection_indexeddata, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, groupedData, arginfo_nc_db_collection_groupeddata, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, groupIndexedData, arginfo_nc_db_collection_groupindexeddata, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, values, arginfo_nc_db_collection_values, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, uniqueValues, arginfo_nc_db_collection_uniquevalues, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, indexedValues, arginfo_nc_db_collection_indexedvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, groupedValues, arginfo_nc_db_collection_groupedvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Collection, groupIndexedValues, arginfo_nc_db_collection_groupindexedvalues, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
