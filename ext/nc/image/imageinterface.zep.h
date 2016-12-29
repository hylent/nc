
extern zend_class_entry *nc_image_imageinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Image_ImageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_bysize, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_bystring, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_bypath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_byimage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\ImageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_largest, 0, 0, 2)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_resize, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_thumbnail, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_cropthumbnail, 0, 0, 1)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_crop, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_paste, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, im, Nc\\Image\\ImageInterface, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_annotate, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_querytextarea, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, font)
	ZEND_ARG_INFO(0, fontSize)
	ZEND_ARG_INFO(0, padding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_imageinterface_save, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_imageinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, bySize, arginfo_nc_image_imageinterface_bysize)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, byString, arginfo_nc_image_imageinterface_bystring)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, byPath, arginfo_nc_image_imageinterface_bypath)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, byImage, arginfo_nc_image_imageinterface_byimage)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, copy, NULL)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, getWidth, NULL)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, getHeight, NULL)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, getExtension, NULL)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, getMimeType, NULL)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, largest, arginfo_nc_image_imageinterface_largest)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, resize, arginfo_nc_image_imageinterface_resize)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, thumbnail, arginfo_nc_image_imageinterface_thumbnail)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, cropThumbnail, arginfo_nc_image_imageinterface_cropthumbnail)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, crop, arginfo_nc_image_imageinterface_crop)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, paste, arginfo_nc_image_imageinterface_paste)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, annotate, arginfo_nc_image_imageinterface_annotate)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, queryTextArea, arginfo_nc_image_imageinterface_querytextarea)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, save, arginfo_nc_image_imageinterface_save)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, toString, NULL)
	PHP_ABSTRACT_ME(Nc_Image_ImageInterface, __toString, NULL)
	PHP_FE_END
};
