
extern zend_class_entry *nc_image_imageabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Image_ImageAbstract);

PHP_METHOD(Nc_Image_ImageAbstract, __construct);
PHP_METHOD(Nc_Image_ImageAbstract, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageabstract___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, backend, Nc\\Image\\ImageBackendAbstract, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_imageabstract_method_entry) {
	PHP_ME(Nc_Image_ImageAbstract, __construct, arginfo_nc_image_imageabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Image_ImageAbstract, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
