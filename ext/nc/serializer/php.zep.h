
extern zend_class_entry *nc_serializer_php_ce;

ZEPHIR_INIT_CLASS(Nc_Serializer_Php);

PHP_METHOD(Nc_Serializer_Php, serialize);
PHP_METHOD(Nc_Serializer_Php, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_serializer_php_serialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_serializer_php_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_serializer_php_method_entry) {
	PHP_ME(Nc_Serializer_Php, serialize, arginfo_nc_serializer_php_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Serializer_Php, unserialize, arginfo_nc_serializer_php_unserialize, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
