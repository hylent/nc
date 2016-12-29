
extern zend_class_entry *nc_queue_mysql_ce;

ZEPHIR_INIT_CLASS(Nc_Queue_Mysql);

PHP_METHOD(Nc_Queue_Mysql, __construct);
PHP_METHOD(Nc_Queue_Mysql, getDaoMysql);
PHP_METHOD(Nc_Queue_Mysql, initialize);
PHP_METHOD(Nc_Queue_Mysql, put);
PHP_METHOD(Nc_Queue_Mysql, reserve);
PHP_METHOD(Nc_Queue_Mysql, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_mysql___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, db, Nc\\Db\\DbInterface, 0)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_mysql_put, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, delay)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_mysql_reserve, 0, 0, 1)
	ZEND_ARG_INFO(0, ttr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_mysql_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_queue_mysql_method_entry) {
	PHP_ME(Nc_Queue_Mysql, __construct, arginfo_nc_queue_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Queue_Mysql, getDaoMysql, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Queue_Mysql, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Queue_Mysql, put, arginfo_nc_queue_mysql_put, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Queue_Mysql, reserve, arginfo_nc_queue_mysql_reserve, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Queue_Mysql, delete, arginfo_nc_queue_mysql_delete, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
