
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Image_ImageBackendAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Image, ImageBackendAbstract, nc, image_imagebackendabstract, nc_image_imagebackendabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_image_imagebackendabstract_ce, SL("defaultOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("LEFT_TOP"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("TOP"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("RIGHT_TOP"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("LEFT"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("CENTER"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("RIGHT"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("LEFT_BOTTOM"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("BOTTOM"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("RIGHT_BOTTOM"), 3 TSRMLS_CC);

	zend_declare_class_constant_string(nc_image_imagebackendabstract_ce, SL("DEFAULT_FONT"), "simhei.ttf" TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("DEFAULT_FONTSIZE"), 24 TSRMLS_CC);

	zend_declare_class_constant_string(nc_image_imagebackendabstract_ce, SL("DEFAULT_COLOR"), "#000000" TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_imagebackendabstract_ce, SL("DEFAULT_OPACITY"), 0.5 TSRMLS_CC);

	zend_declare_class_constant_long(nc_image_imagebackendabstract_ce, SL("DEFAULT_PADDING"), 5 TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_imagebackendabstract_ce, SL("DEFAULT_R_PADDING"), 0.2 TSRMLS_CC);

	zend_declare_class_constant_double(nc_image_imagebackendabstract_ce, SL("DEFAULT_R_OVERLAP"), 0.2 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, __construct) {

	zval *defaultOptions_param = NULL;
	zval *defaultOptions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultOptions_param);

	if (!defaultOptions_param) {
		ZEPHIR_INIT_VAR(defaultOptions);
		array_init(defaultOptions);
	} else {
		zephir_get_arrval(defaultOptions, defaultOptions_param);
	}


	zephir_update_property_this(this_ptr, SL("defaultOptions"), defaultOptions TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, setDefaultOptions) {

	HashTable *_1;
	HashPosition _0;
	zval *options_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	zephir_is_iterable(options, &_1, &_0, 0, 0, "nc/image/imagebackendabstract.zep", 37);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_update_property_array(this_ptr, SL("defaultOptions"), k, v TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, getDefaultOptions) {

	

	RETURN_MEMBER(this_ptr, "defaultOptions");

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, text) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, fromImage) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, fromSize) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, fromPath) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, fromString) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, captcha) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, resize) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, crop) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, thumbnail) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, draw) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, save) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, destroy) {

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, newText) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, nc_image_text_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, newImage) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, nc_image_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_ImageBackendAbstract, newCaptcha) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, nc_image_captcha_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

