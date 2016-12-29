
extern zend_class_entry *nc_image_gd_ce;

ZEPHIR_INIT_CLASS(Nc_Image_Gd);

PHP_METHOD(Nc_Image_Gd, __construct);
PHP_METHOD(Nc_Image_Gd, bySize);
PHP_METHOD(Nc_Image_Gd, byString);
PHP_METHOD(Nc_Image_Gd, byPath);
PHP_METHOD(Nc_Image_Gd, copy);
PHP_METHOD(Nc_Image_Gd, resample);
PHP_METHOD(Nc_Image_Gd, largest);
PHP_METHOD(Nc_Image_Gd, resize);
PHP_METHOD(Nc_Image_Gd, thumbnail);
PHP_METHOD(Nc_Image_Gd, cropThumbnail);
PHP_METHOD(Nc_Image_Gd, crop);
PHP_METHOD(Nc_Image_Gd, paste);
PHP_METHOD(Nc_Image_Gd, annotate);
PHP_METHOD(Nc_Image_Gd, queryTextArea);
PHP_METHOD(Nc_Image_Gd, save);
PHP_METHOD(Nc_Image_Gd, toString);
PHP_METHOD(Nc_Image_Gd, __destruct);
PHP_METHOD(Nc_Image_Gd, newImage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_bysize, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_bystring, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_bypath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_resample, 0, 0, 4)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_OBJ_INFO(0, dstArea, Nc\\Image\\Area, 0)
	ZEND_ARG_OBJ_INFO(0, srcArea, Nc\\Image\\Area, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_largest, 0, 0, 2)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_resize, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_thumbnail, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_cropthumbnail, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_crop, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_paste, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\ImageInterface, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_annotate, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_querytextarea, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, font)
	ZEND_ARG_INFO(0, fontSize)
	ZEND_ARG_INFO(0, padding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_save, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_newimage, 0, 0, 2)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_gd_method_entry) {
	PHP_ME(Nc_Image_Gd, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Image_Gd, bySize, arginfo_nc_image_gd_bysize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, byString, arginfo_nc_image_gd_bystring, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, byPath, arginfo_nc_image_gd_bypath, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, copy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, resample, arginfo_nc_image_gd_resample, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, largest, arginfo_nc_image_gd_largest, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, resize, arginfo_nc_image_gd_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, thumbnail, arginfo_nc_image_gd_thumbnail, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, cropThumbnail, arginfo_nc_image_gd_cropthumbnail, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, crop, arginfo_nc_image_gd_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, paste, arginfo_nc_image_gd_paste, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, annotate, arginfo_nc_image_gd_annotate, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, queryTextArea, arginfo_nc_image_gd_querytextarea, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, save, arginfo_nc_image_gd_save, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_Image_Gd, newImage, arginfo_nc_image_gd_newimage, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
