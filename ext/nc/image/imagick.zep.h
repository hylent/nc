
extern zend_class_entry *nc_image_imagick_ce;

ZEPHIR_INIT_CLASS(Nc_Image_Imagick);

PHP_METHOD(Nc_Image_Imagick, __construct);
PHP_METHOD(Nc_Image_Imagick, bySize);
PHP_METHOD(Nc_Image_Imagick, byString);
PHP_METHOD(Nc_Image_Imagick, byPath);
PHP_METHOD(Nc_Image_Imagick, copy);
PHP_METHOD(Nc_Image_Imagick, largest);
PHP_METHOD(Nc_Image_Imagick, resize);
PHP_METHOD(Nc_Image_Imagick, thumbnail);
PHP_METHOD(Nc_Image_Imagick, cropThumbnail);
PHP_METHOD(Nc_Image_Imagick, crop);
PHP_METHOD(Nc_Image_Imagick, paste);
PHP_METHOD(Nc_Image_Imagick, annotate);
PHP_METHOD(Nc_Image_Imagick, queryTextArea);
PHP_METHOD(Nc_Image_Imagick, save);
PHP_METHOD(Nc_Image_Imagick, toString);
PHP_METHOD(Nc_Image_Imagick, __destruct);
PHP_METHOD(Nc_Image_Imagick, newImage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_bysize, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_bystring, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_bypath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_largest, 0, 0, 2)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_resize, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_thumbnail, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_cropthumbnail, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_crop, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_paste, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\ImageInterface, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_annotate, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_querytextarea, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, font)
	ZEND_ARG_INFO(0, fontSize)
	ZEND_ARG_INFO(0, padding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_save, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imagick_newimage, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, handler, Imagick, 0)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_imagick_method_entry) {
	PHP_ME(Nc_Image_Imagick, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Image_Imagick, bySize, arginfo_nc_image_imagick_bysize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, byString, arginfo_nc_image_imagick_bystring, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, byPath, arginfo_nc_image_imagick_bypath, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, copy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, largest, arginfo_nc_image_imagick_largest, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, resize, arginfo_nc_image_imagick_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, thumbnail, arginfo_nc_image_imagick_thumbnail, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, cropThumbnail, arginfo_nc_image_imagick_cropthumbnail, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, crop, arginfo_nc_image_imagick_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, paste, arginfo_nc_image_imagick_paste, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, annotate, arginfo_nc_image_imagick_annotate, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, queryTextArea, arginfo_nc_image_imagick_querytextarea, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, save, arginfo_nc_image_imagick_save, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Imagick, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_Image_Imagick, newImage, arginfo_nc_image_imagick_newimage, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
