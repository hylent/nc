
extern zend_class_entry *nc_db_dbawareinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DbAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbawareinterface_setdb, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, db, Nc\\Db\\DbInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_dbawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Db_DbAwareInterface, setDb, arginfo_nc_db_dbawareinterface_setdb)
	PHP_ABSTRACT_ME(Nc_Db_DbAwareInterface, getDb, NULL)
	PHP_FE_END
};
