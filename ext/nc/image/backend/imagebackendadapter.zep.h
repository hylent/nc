
extern zend_class_entry *nc_image_backend_imagebackendadapter_ce;

ZEPHIR_INIT_CLASS(Nc_Image_Backend_ImageBackendAdapter);

PHP_METHOD(Nc_Image_Backend_ImageBackendAdapter, setDefaults);
PHP_METHOD(Nc_Image_Backend_ImageBackendAdapter, setDefault);
PHP_METHOD(Nc_Image_Backend_ImageBackendAdapter, validTextOptions);
PHP_METHOD(Nc_Image_Backend_ImageBackendAdapter, validCaptchaOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_backend_imagebackendadapter_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_backend_imagebackendadapter_setdefault, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_backend_imagebackendadapter_validtextoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_backend_imagebackendadapter_validcaptchaoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_backend_imagebackendadapter_method_entry) {
	PHP_ME(Nc_Image_Backend_ImageBackendAdapter, setDefaults, arginfo_nc_image_backend_imagebackendadapter_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Backend_ImageBackendAdapter, setDefault, arginfo_nc_image_backend_imagebackendadapter_setdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Backend_ImageBackendAdapter, validTextOptions, arginfo_nc_image_backend_imagebackendadapter_validtextoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Image_Backend_ImageBackendAdapter, validCaptchaOptions, arginfo_nc_image_backend_imagebackendadapter_validcaptchaoptions, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
