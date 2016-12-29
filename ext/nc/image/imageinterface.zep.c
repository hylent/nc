
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Image_ImageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Image, ImageInterface, nc, image_imageinterface, nc_image_imageinterface_method_entry);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("LEFT_TOP"), 7);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("TOP"), 8);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("RIGHT_TOP"), 9);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("LEFT"), 4);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("CENTER"), 5);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("RIGHT"), 6);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("LEFT_BOTTOM"), 1);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("BOTTOM"), 2);

	zephir_declare_class_constant_long(nc_image_imageinterface_ce, SL("RIGHT_BOTTOM"), 3);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, bySize);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, byString);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, byPath);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, byImage);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, copy);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, getWidth);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, getHeight);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, getExtension);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, getMimeType);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, largest);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, resize);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, thumbnail);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, cropThumbnail);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, crop);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, paste);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, annotate);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, queryTextArea);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, save);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, toString);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, __toString);

