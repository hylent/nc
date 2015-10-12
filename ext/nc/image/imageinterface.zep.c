
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

	zend_declare_class_constant_string(nc_image_imageinterface_ce, SL("DEFAULT_FONT"), "" TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("DEFAULT_FONT_SIZE"), 24 TSRMLS_CC);

	zend_declare_class_constant_string(nc_image_imageinterface_ce, SL("DEFAULT_COLOR"), "#000000" TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("DEFAULT_RED"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("DEFAULT_GREEN"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("DEFAULT_BLUE"), 0 TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_imageinterface_ce, SL("DEFAULT_OPACITY"), 0.5 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("DEFAULT_PADDING"), 5 TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_imageinterface_ce, SL("DEFAULT_R_PADDING"), 0.2 TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_imageinterface_ce, SL("DEFAULT_R_OVERLAP"), 0.2 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("LEFT_TOP"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("TOP"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("RIGHT_TOP"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("LEFT"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("CENTER"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("RIGHT"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("LEFT_BOTTOM"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("BOTTOM"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imageinterface_ce, SL("RIGHT_BOTTOM"), 3 TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, text);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, captcha);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, fromImage);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, fromSize);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, fromPath);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, fromString);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, resize);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, crop);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, thumbnail);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, draw);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, save);

ZEPHIR_DOC_METHOD(Nc_Image_ImageInterface, destroy);

