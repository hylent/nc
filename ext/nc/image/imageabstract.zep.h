
extern zend_class_entry *nc_image_imageabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Image_ImageAbstract);

PHP_METHOD(Nc_Image_ImageAbstract, setDefaults);
PHP_METHOD(Nc_Image_ImageAbstract, setDefault);
PHP_METHOD(Nc_Image_ImageAbstract, validTextOptions);
PHP_METHOD(Nc_Image_ImageAbstract, validCaptchaOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageabstract_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageabstract_setdefault, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageabstract_validtextoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageabstract_validcaptchaoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_imageabstract_method_entry) {
	PHP_ME(Nc_Image_ImageAbstract, setDefaults, arginfo_nc_image_imageabstract_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, setDefault, arginfo_nc_image_imageabstract_setdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, validTextOptions, arginfo_nc_image_imageabstract_validtextoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Image_ImageAbstract, validCaptchaOptions, arginfo_nc_image_imageabstract_validcaptchaoptions, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
