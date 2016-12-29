
extern zend_class_entry *nc_sequence_mysqlmyisam_ce;

ZEPHIR_INIT_CLASS(Nc_Sequence_MysqlMyisam);

PHP_METHOD(Nc_Sequence_MysqlMyisam, __construct);
PHP_METHOD(Nc_Sequence_MysqlMyisam, getDaoMysql);
PHP_METHOD(Nc_Sequence_MysqlMyisam, initialize);
PHP_METHOD(Nc_Sequence_MysqlMyisam, next);
PHP_METHOD(Nc_Sequence_MysqlMyisam, restore);
PHP_METHOD(Nc_Sequence_MysqlMyisam, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mysqlmyisam___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, db, Nc\\Db\\DbInterface, 0)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mysqlmyisam_next, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mysqlmyisam_restore, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_sequence_mysqlmyisam_method_entry) {
	PHP_ME(Nc_Sequence_MysqlMyisam, __construct, arginfo_nc_sequence_mysqlmyisam___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Sequence_MysqlMyisam, getDaoMysql, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_MysqlMyisam, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_MysqlMyisam, next, arginfo_nc_sequence_mysqlmyisam_next, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_MysqlMyisam, restore, arginfo_nc_sequence_mysqlmyisam_restore, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_MysqlMyisam, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
