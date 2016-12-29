
extern zend_class_entry *nc_image_imageabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Image_ImageAbstract);

PHP_METHOD(Nc_Image_ImageAbstract, byImage);
PHP_METHOD(Nc_Image_ImageAbstract, copy);
PHP_METHOD(Nc_Image_ImageAbstract, getWidth);
PHP_METHOD(Nc_Image_ImageAbstract, getHeight);
PHP_METHOD(Nc_Image_ImageAbstract, getExtension);
PHP_METHOD(Nc_Image_ImageAbstract, getMimeType);
PHP_METHOD(Nc_Image_ImageAbstract, __toString);
PHP_METHOD(Nc_Image_ImageAbstract, newInstance);
PHP_METHOD(Nc_Image_ImageAbstract, getPaintingAreaByPosition);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageabstract_byimage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\ImageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageabstract_getpaintingareabyposition, 0, 0, 3)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_imageabstract_method_entry) {
	PHP_ME(Nc_Image_ImageAbstract, byImage, arginfo_nc_image_imageabstract_byimage, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, copy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, getWidth, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, getHeight, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, getExtension, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, getMimeType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_ImageAbstract, newInstance, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Image_ImageAbstract, getPaintingAreaByPosition, arginfo_nc_image_imageabstract_getpaintingareabyposition, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
