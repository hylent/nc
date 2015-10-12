
extern zend_class_entry *nc_image_imageinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Image_ImageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_captcha, 0, 0, 3)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_fromimage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_fromsize, 0, 0, 1)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_frompath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_resize, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_crop, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_thumbnail, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, cropped)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_draw, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, destIm, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, srcIm, Nc\\Image\\Item\\ImageItemAbstract, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_save, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\Image, 0)
	ZEND_ARG_INFO(0, destPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_destroy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\Item\\ImageItemAbstract, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_imageinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, text, arginfo_nc_image_imageinterface_text)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, captcha, arginfo_nc_image_imageinterface_captcha)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, fromImage, arginfo_nc_image_imageinterface_fromimage)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, fromSize, arginfo_nc_image_imageinterface_fromsize)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, fromPath, arginfo_nc_image_imageinterface_frompath)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, fromString, arginfo_nc_image_imageinterface_fromstring)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, resize, arginfo_nc_image_imageinterface_resize)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, crop, arginfo_nc_image_imageinterface_crop)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, thumbnail, arginfo_nc_image_imageinterface_thumbnail)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, draw, arginfo_nc_image_imageinterface_draw)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, save, arginfo_nc_image_imageinterface_save)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, destroy, arginfo_nc_image_imageinterface_destroy)
	PHP_FE_END
};
