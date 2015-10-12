
extern zend_class_entry *nc_image_gd_ce;

ZEPHIR_INIT_CLASS(Nc_Image_Gd);

PHP_METHOD(Nc_Image_Gd, __construct);
PHP_METHOD(Nc_Image_Gd, text);
PHP_METHOD(Nc_Image_Gd, captcha);
PHP_METHOD(Nc_Image_Gd, fromImage);
PHP_METHOD(Nc_Image_Gd, fromSize);
PHP_METHOD(Nc_Image_Gd, fromPath);
PHP_METHOD(Nc_Image_Gd, fromString);
PHP_METHOD(Nc_Image_Gd, resize);
PHP_METHOD(Nc_Image_Gd, crop);
PHP_METHOD(Nc_Image_Gd, thumbnail);
PHP_METHOD(Nc_Image_Gd, draw);
PHP_METHOD(Nc_Image_Gd, save);
PHP_METHOD(Nc_Image_Gd, destroy);
PHP_METHOD(Nc_Image_Gd, drawText);
PHP_METHOD(Nc_Image_Gd, copy);
PHP_METHOD(Nc_Image_Gd, copyResampled);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, defaults, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_captcha, 0, 0, 3)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_fromimage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_fromsize, 0, 0, 1)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_frompath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_resize, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_crop, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_thumbnail, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, cropped)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_draw, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, destIm, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, srcIm, Nc\\Image\\Item\\ImageItemAbstract, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_save, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, destPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_destroy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\ImageItemAbstract, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_drawtext, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, dest, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, src, Nc\\Image\\Item\\Text, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_copy, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, dest, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, src, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_gd_copyresampled, 0, 0, 10)
	ZEND_ARG_OBJ_INFO(0, dest, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, src, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, srcX)
	ZEND_ARG_INFO(0, srcY)
	ZEND_ARG_INFO(0, srcW)
	ZEND_ARG_INFO(0, srcH)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_gd_method_entry) {
	PHP_ME(Nc_Image_Gd, __construct, arginfo_nc_image_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Image_Gd, text, arginfo_nc_image_gd_text, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, captcha, arginfo_nc_image_gd_captcha, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, fromImage, arginfo_nc_image_gd_fromimage, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, fromSize, arginfo_nc_image_gd_fromsize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, fromPath, arginfo_nc_image_gd_frompath, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, fromString, arginfo_nc_image_gd_fromstring, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, resize, arginfo_nc_image_gd_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, crop, arginfo_nc_image_gd_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, thumbnail, arginfo_nc_image_gd_thumbnail, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, draw, arginfo_nc_image_gd_draw, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, save, arginfo_nc_image_gd_save, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, destroy, arginfo_nc_image_gd_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Image_Gd, drawText, arginfo_nc_image_gd_drawtext, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Image_Gd, copy, arginfo_nc_image_gd_copy, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Image_Gd, copyResampled, arginfo_nc_image_gd_copyresampled, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
