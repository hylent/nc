
extern zend_class_entry *nc_data_singlevalue_ce;

ZEPHIR_INIT_CLASS(Nc_Data_SingleValue);

PHP_METHOD(Nc_Data_SingleValue, set);
PHP_METHOD(Nc_Data_SingleValue, get);
PHP_METHOD(Nc_Data_SingleValue, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_singlevalue_set, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_data_singlevalue_method_entry) {
	PHP_ME(Nc_Data_SingleValue, set, arginfo_nc_data_singlevalue_set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_SingleValue, get, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_SingleValue, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
