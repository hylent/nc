
extern zend_class_entry *nc_std_sequencemysql_ce;

ZEPHIR_INIT_CLASS(Nc_Std_SequenceMysql);

PHP_METHOD(Nc_Std_SequenceMysql, __construct);
PHP_METHOD(Nc_Std_SequenceMysql, getNextSequence);
PHP_METHOD(Nc_Std_SequenceMysql, restoreSequence);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequencemysql___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, mysql, Nc\\Db\\PdoMysql, 0)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequencemysql_getnextsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sequencemysql_restoresequence, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_sequencemysql_method_entry) {
	PHP_ME(Nc_Std_SequenceMysql, __construct, arginfo_nc_std_sequencemysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_SequenceMysql, getNextSequence, arginfo_nc_std_sequencemysql_getnextsequence, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_SequenceMysql, restoreSequence, arginfo_nc_std_sequencemysql_restoresequence, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
