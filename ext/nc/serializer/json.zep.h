
extern zend_class_entry *nc_serializer_json_ce;

ZEPHIR_INIT_CLASS(Nc_Serializer_Json);

PHP_METHOD(Nc_Serializer_Json, __construct);
PHP_METHOD(Nc_Serializer_Json, serialize);
PHP_METHOD(Nc_Serializer_Json, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_serializer_json___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, serializeFlag)
	ZEND_ARG_INFO(0, unserializeToArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_serializer_json_serialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_serializer_json_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_serializer_json_method_entry) {
	PHP_ME(Nc_Serializer_Json, __construct, arginfo_nc_serializer_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Serializer_Json, serialize, arginfo_nc_serializer_json_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Serializer_Json, unserialize, arginfo_nc_serializer_json_unserialize, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
