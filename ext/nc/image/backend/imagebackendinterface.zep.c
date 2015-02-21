
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Image_Backend_ImageBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Image\\Backend, ImageBackendInterface, nc, image_backend_imagebackendinterface, nc_image_backend_imagebackendinterface_method_entry);

	zend_declare_class_constant_string(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_FONT"), "nc.ttf" TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_FONT_SIZE"), 24 TSRMLS_CC);

	zend_declare_class_constant_string(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_COLOR"), "#000000" TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_RED"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_GREEN"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_BLUE"), 0 TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_OPACITY"), 0.5 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_PADDING"), 5 TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_R_PADDING"), 0.2 TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_backend_imagebackendinterface_ce, SL("DEFAULT_R_OVERLAP"), 0.2 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("LEFT_TOP"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("TOP"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("RIGHT_TOP"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("LEFT"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("CENTER"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("RIGHT"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("LEFT_BOTTOM"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("BOTTOM"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_backend_imagebackendinterface_ce, SL("RIGHT_BOTTOM"), 3 TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, text);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, captcha);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, fromImage);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, fromSize);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, fromPath);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, fromString);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, resize);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, crop);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, thumbnail);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, draw);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, save);

ZEPHIR_DOC_METHOD(Nc_Image_Backend_ImageBackendInterface, destroy);

