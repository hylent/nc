
extern zend_class_entry *nc_db_daooracle_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DaoOracle);

PHP_METHOD(Nc_Db_DaoOracle, upsert);
PHP_METHOD(Nc_Db_DaoOracle, updateTop);
PHP_METHOD(Nc_Db_DaoOracle, deleteTop);
PHP_METHOD(Nc_Db_DaoOracle, makeRandomOrder);
PHP_METHOD(Nc_Db_DaoOracle, makePagination);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daooracle_upsert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, inserts, 0)
	ZEND_ARG_ARRAY_INFO(0, updates, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daooracle_updatetop, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, updates, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daooracle_deletetop, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daooracle_makepagination, 0, 0, 3)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_daooracle_method_entry) {
	PHP_ME(Nc_Db_DaoOracle, upsert, arginfo_nc_db_daooracle_upsert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoOracle, updateTop, arginfo_nc_db_daooracle_updatetop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoOracle, deleteTop, arginfo_nc_db_daooracle_deletetop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoOracle, makeRandomOrder, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DaoOracle, makePagination, arginfo_nc_db_daooracle_makepagination, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
