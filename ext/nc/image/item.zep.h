
extern zend_class_entry *nc_image_item_ce;

ZEPHIR_INIT_CLASS(Nc_Image_Item);

PHP_METHOD(Nc_Image_Item, __construct);
PHP_METHOD(Nc_Image_Item, __set);
PHP_METHOD(Nc_Image_Item, __get);
PHP_METHOD(Nc_Image_Item, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_item___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, backend, Nc\\Image\\Backend\\ImageBackendInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, properties, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_item___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_item___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_item_method_entry) {
	PHP_ME(Nc_Image_Item, __construct, arginfo_nc_image_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Image_Item, __set, arginfo_nc_image_item___set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Item, __get, arginfo_nc_image_item___get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Item, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
  PHP_FE_END
};
