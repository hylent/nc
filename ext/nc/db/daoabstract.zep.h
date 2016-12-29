
extern zend_class_entry *nc_db_daoabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DaoAbstract);

PHP_METHOD(Nc_Db_DaoAbstract, __construct);
PHP_METHOD(Nc_Db_DaoAbstract, getDb);
PHP_METHOD(Nc_Db_DaoAbstract, getTable);
PHP_METHOD(Nc_Db_DaoAbstract, getPrimaryKey);
PHP_METHOD(Nc_Db_DaoAbstract, getSequenceField);
PHP_METHOD(Nc_Db_DaoAbstract, lastSequence);
PHP_METHOD(Nc_Db_DaoAbstract, insert);
PHP_METHOD(Nc_Db_DaoAbstract, upsert);
PHP_METHOD(Nc_Db_DaoAbstract, update);
PHP_METHOD(Nc_Db_DaoAbstract, updateTop);
PHP_METHOD(Nc_Db_DaoAbstract, delete);
PHP_METHOD(Nc_Db_DaoAbstract, deleteTop);
PHP_METHOD(Nc_Db_DaoAbstract, find);
PHP_METHOD(Nc_Db_DaoAbstract, countAndFind);
PHP_METHOD(Nc_Db_DaoAbstract, findAll);
PHP_METHOD(Nc_Db_DaoAbstract, findPaged);
PHP_METHOD(Nc_Db_DaoAbstract, findTop);
PHP_METHOD(Nc_Db_DaoAbstract, findFirst);
PHP_METHOD(Nc_Db_DaoAbstract, findVector);
PHP_METHOD(Nc_Db_DaoAbstract, findMap);
PHP_METHOD(Nc_Db_DaoAbstract, findCell);
PHP_METHOD(Nc_Db_DaoAbstract, group);
PHP_METHOD(Nc_Db_DaoAbstract, aggregations);
PHP_METHOD(Nc_Db_DaoAbstract, aggregation);
PHP_METHOD(Nc_Db_DaoAbstract, countAll);
PHP_METHOD(Nc_Db_DaoAbstract, count);
PHP_METHOD(Nc_Db_DaoAbstract, max);
PHP_METHOD(Nc_Db_DaoAbstract, min);
PHP_METHOD(Nc_Db_DaoAbstract, sum);
PHP_METHOD(Nc_Db_DaoAbstract, avg);
PHP_METHOD(Nc_Db_DaoAbstract, makeWhere);
PHP_METHOD(Nc_Db_DaoAbstract, parseWhere);
PHP_METHOD(Nc_Db_DaoAbstract, parseWhereIn);
PHP_METHOD(Nc_Db_DaoAbstract, parseWhereBetween);
PHP_METHOD(Nc_Db_DaoAbstract, makeOrder);
PHP_METHOD(Nc_Db_DaoAbstract, makeRandomOrder);
PHP_METHOD(Nc_Db_DaoAbstract, makePagination);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, db, Nc\\Db\\DbInterface, 0)
	ZEND_ARG_INFO(0, tb)
	ZEND_ARG_ARRAY_INFO(0, pk, 0)
	ZEND_ARG_INFO(0, sf)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, inserts, 0)
	ZEND_ARG_INFO(0, ignoreSequence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_upsert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, inserts, 0)
	ZEND_ARG_ARRAY_INFO(0, updates, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_update, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, updates, 0)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_updatetop, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, updates, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_deletetop, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_find, 0, 0, 6)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
	ZEND_ARG_INFO(0, lock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_countandfind, 0, 0, 6)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
	ZEND_ARG_INFO(0, lock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_findall, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_findpaged, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_findtop, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, lock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, lock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_findvector, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_findmap, 0, 0, 2)
	ZEND_ARG_INFO(0, kField)
	ZEND_ARG_INFO(0, vField)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_findcell, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_group, 0, 0, 2)
	ZEND_ARG_INFO(0, byField)
	ZEND_ARG_ARRAY_INFO(0, aggrs, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, having)
	ZEND_ARG_INFO(0, order)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_aggregations, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, aggrs, 0)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_aggregation, 0, 0, 2)
	ZEND_ARG_INFO(0, aggrFunction)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_countall, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_count, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_max, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_min, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_sum, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_avg, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_makewhere, 0, 0, 1)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, connector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_parsewhere, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, where, 0)
	ZEND_ARG_INFO(0, sep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_parsewherein, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, not)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_parsewherebetween, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, not)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_makeorder, 0, 0, 1)
	ZEND_ARG_INFO(0, order)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daoabstract_makepagination, 0, 0, 3)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_daoabstract_method_entry) {
	PHP_ME(Nc_Db_DaoAbstract, __construct, arginfo_nc_db_daoabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Db_DaoAbstract, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, getTable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, getPrimaryKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, getSequenceField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, lastSequence, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, insert, arginfo_nc_db_daoabstract_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, upsert, arginfo_nc_db_daoabstract_upsert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, update, arginfo_nc_db_daoabstract_update, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, updateTop, arginfo_nc_db_daoabstract_updatetop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, delete, arginfo_nc_db_daoabstract_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, deleteTop, arginfo_nc_db_daoabstract_deletetop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, find, arginfo_nc_db_daoabstract_find, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, countAndFind, arginfo_nc_db_daoabstract_countandfind, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, findAll, arginfo_nc_db_daoabstract_findall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, findPaged, arginfo_nc_db_daoabstract_findpaged, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, findTop, arginfo_nc_db_daoabstract_findtop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, findFirst, arginfo_nc_db_daoabstract_findfirst, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, findVector, arginfo_nc_db_daoabstract_findvector, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, findMap, arginfo_nc_db_daoabstract_findmap, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, findCell, arginfo_nc_db_daoabstract_findcell, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, group, arginfo_nc_db_daoabstract_group, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, aggregations, arginfo_nc_db_daoabstract_aggregations, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, aggregation, arginfo_nc_db_daoabstract_aggregation, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, countAll, arginfo_nc_db_daoabstract_countall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, count, arginfo_nc_db_daoabstract_count, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, max, arginfo_nc_db_daoabstract_max, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, min, arginfo_nc_db_daoabstract_min, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, sum, arginfo_nc_db_daoabstract_sum, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, avg, arginfo_nc_db_daoabstract_avg, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoAbstract, makeWhere, arginfo_nc_db_daoabstract_makewhere, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DaoAbstract, parseWhere, arginfo_nc_db_daoabstract_parsewhere, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DaoAbstract, parseWhereIn, arginfo_nc_db_daoabstract_parsewherein, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DaoAbstract, parseWhereBetween, arginfo_nc_db_daoabstract_parsewherebetween, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DaoAbstract, makeOrder, arginfo_nc_db_daoabstract_makeorder, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DaoAbstract, makeRandomOrder, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DaoAbstract, makePagination, arginfo_nc_db_daoabstract_makepagination, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
