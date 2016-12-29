
extern zend_class_entry *nc_sequence_mysql_ce;

ZEPHIR_INIT_CLASS(Nc_Sequence_Mysql);

PHP_METHOD(Nc_Sequence_Mysql, __construct);
PHP_METHOD(Nc_Sequence_Mysql, getDaoMysql);
PHP_METHOD(Nc_Sequence_Mysql, initialize);
PHP_METHOD(Nc_Sequence_Mysql, next);
PHP_METHOD(Nc_Sequence_Mysql, restore);
PHP_METHOD(Nc_Sequence_Mysql, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mysql___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, db, Nc\\Db\\DbInterface, 0)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mysql_next, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_mysql_restore, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_sequence_mysql_method_entry) {
	PHP_ME(Nc_Sequence_Mysql, __construct, arginfo_nc_sequence_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Sequence_Mysql, getDaoMysql, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Mysql, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Mysql, next, arginfo_nc_sequence_mysql_next, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Mysql, restore, arginfo_nc_sequence_mysql_restore, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Mysql, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
