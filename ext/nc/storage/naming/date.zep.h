
extern zend_class_entry *nc_storage_naming_date_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_Naming_Date);

PHP_METHOD(Nc_Storage_Naming_Date, __construct);
PHP_METHOD(Nc_Storage_Naming_Date, generateName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_naming_date___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dateFormat)
	ZEND_ARG_INFO(0, randStringLength)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_naming_date_method_entry) {
	PHP_ME(Nc_Storage_Naming_Date, __construct, arginfo_nc_storage_naming_date___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Storage_Naming_Date, generateName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
