
extern zend_class_entry *nc_serializer_igbinary_ce;

ZEPHIR_INIT_CLASS(Nc_Serializer_Igbinary);

PHP_METHOD(Nc_Serializer_Igbinary, __construct);
PHP_METHOD(Nc_Serializer_Igbinary, serialize);
PHP_METHOD(Nc_Serializer_Igbinary, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_serializer_igbinary_serialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_serializer_igbinary_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_serializer_igbinary_method_entry) {
	PHP_ME(Nc_Serializer_Igbinary, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Serializer_Igbinary, serialize, arginfo_nc_serializer_igbinary_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Serializer_Igbinary, unserialize, arginfo_nc_serializer_igbinary_unserialize, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
