
extern zend_class_entry *nc_db_daomysql_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DaoMysql);

PHP_METHOD(Nc_Db_DaoMysql, queryLastInsertId);
PHP_METHOD(Nc_Db_DaoMysql, replace);
PHP_METHOD(Nc_Db_DaoMysql, insert);
PHP_METHOD(Nc_Db_DaoMysql, upsert);
PHP_METHOD(Nc_Db_DaoMysql, updateTop);
PHP_METHOD(Nc_Db_DaoMysql, deleteTop);
PHP_METHOD(Nc_Db_DaoMysql, countAndFind);
PHP_METHOD(Nc_Db_DaoMysql, makeRandomOrder);
PHP_METHOD(Nc_Db_DaoMysql, makePagination);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daomysql_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daomysql_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, inserts, 0)
	ZEND_ARG_INFO(0, ignoreSequence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daomysql_upsert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, inserts, 0)
	ZEND_ARG_ARRAY_INFO(0, updates, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daomysql_updatetop, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, updates, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daomysql_deletetop, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daomysql_countandfind, 0, 0, 6)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_INFO(0, order)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
	ZEND_ARG_INFO(0, lock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_daomysql_makepagination, 0, 0, 3)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_daomysql_method_entry) {
	PHP_ME(Nc_Db_DaoMysql, queryLastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoMysql, replace, arginfo_nc_db_daomysql_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoMysql, insert, arginfo_nc_db_daomysql_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoMysql, upsert, arginfo_nc_db_daomysql_upsert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoMysql, updateTop, arginfo_nc_db_daomysql_updatetop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoMysql, deleteTop, arginfo_nc_db_daomysql_deletetop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoMysql, countAndFind, arginfo_nc_db_daomysql_countandfind, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DaoMysql, makeRandomOrder, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DaoMysql, makePagination, arginfo_nc_db_daomysql_makepagination, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
