
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Image_ImageAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Image, ImageAbstract, nc, image_imageabstract, nc_image_imageabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_image_imageabstract_ce, SL("width"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_image_imageabstract_ce, SL("height"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_image_imageabstract_ce, SL("extension"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_image_imageabstract_ce, SL("mimeType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_image_imageabstract_ce TSRMLS_CC, 1, nc_image_imageinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Image_ImageAbstract, byImage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *im, im_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&im_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	ZEPHIR_CALL_METHOD(&_0, im, "tostring", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, im, "getextension", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "bystring", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_ImageAbstract, copy) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "byimage", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_ImageAbstract, getWidth) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "width");

}

PHP_METHOD(Nc_Image_ImageAbstract, getHeight) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "height");

}

PHP_METHOD(Nc_Image_ImageAbstract, getExtension) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "extension");

}

PHP_METHOD(Nc_Image_ImageAbstract, getMimeType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "mimeType");

}

PHP_METHOD(Nc_Image_ImageAbstract, __toString) {

	zval _1$$3;
	zval _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "tostring", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_get_strval(&_1$$3, &_0$$3);
		RETURN_CTOR(&_1$$3);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_STRING("");

}

PHP_METHOD(Nc_Image_ImageAbstract, newInstance) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_called_class(&_1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 15, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "newinstancewithoutconstructor", NULL, 16);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_ImageAbstract, getPaintingAreaByPosition) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, *position_param = NULL, x, y, _0, _1, _4, _5, _2$$12, _3$$12;
	long w, h, position, oriW = 0, oriH = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&x);
	ZVAL_UNDEF(&y);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$12);
	ZVAL_UNDEF(&_3$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &w_param, &h_param, &position_param);

	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);
	position = zephir_get_intval(position_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("width"), PH_NOISY_CC);
	oriW = zephir_get_intval(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("height"), PH_NOISY_CC);
	oriH = zephir_get_intval(&_1);
	do {
		if (position == 1) {
			ZEPHIR_INIT_VAR(&x);
			ZVAL_LONG(&x, 0);
			ZEPHIR_INIT_VAR(&y);
			ZVAL_LONG(&y, (oriH - h));
			break;
		}
		if (position == 2) {
			ZEPHIR_INIT_NVAR(&x);
			ZVAL_DOUBLE(&x, zephir_safe_div_long_long(((oriW - w)), 2 TSRMLS_CC));
			ZEPHIR_INIT_NVAR(&y);
			ZVAL_LONG(&y, (oriH - h));
			break;
		}
		if (position == 3) {
			ZEPHIR_INIT_NVAR(&x);
			ZVAL_LONG(&x, (oriW - w));
			ZEPHIR_INIT_NVAR(&y);
			ZVAL_LONG(&y, (oriH - h));
			break;
		}
		if (position == 4) {
			ZEPHIR_INIT_NVAR(&x);
			ZVAL_LONG(&x, 0);
			ZEPHIR_INIT_NVAR(&y);
			ZVAL_DOUBLE(&y, zephir_safe_div_long_long(((oriH - h)), 2 TSRMLS_CC));
			break;
		}
		if (position == 5) {
			ZEPHIR_INIT_NVAR(&x);
			ZVAL_DOUBLE(&x, zephir_safe_div_long_long(((oriW - w)), 2 TSRMLS_CC));
			ZEPHIR_INIT_NVAR(&y);
			ZVAL_DOUBLE(&y, zephir_safe_div_long_long(((oriH - h)), 2 TSRMLS_CC));
			break;
		}
		if (position == 6) {
			ZEPHIR_INIT_NVAR(&x);
			ZVAL_LONG(&x, (oriW - w));
			ZEPHIR_INIT_NVAR(&y);
			ZVAL_DOUBLE(&y, zephir_safe_div_long_long(((oriH - h)), 2 TSRMLS_CC));
			break;
		}
		if (position == 7) {
			ZEPHIR_INIT_NVAR(&x);
			ZVAL_LONG(&x, 0);
			ZEPHIR_INIT_NVAR(&y);
			ZVAL_LONG(&y, 0);
			break;
		}
		if (position == 8) {
			ZEPHIR_INIT_NVAR(&x);
			ZVAL_DOUBLE(&x, zephir_safe_div_long_long(((oriW - w)), 2 TSRMLS_CC));
			ZEPHIR_INIT_NVAR(&y);
			ZVAL_LONG(&y, 0);
			break;
		}
		if (position == 9) {
			ZEPHIR_INIT_NVAR(&x);
			ZVAL_LONG(&x, (oriW - w));
			ZEPHIR_INIT_NVAR(&y);
			ZVAL_LONG(&y, 0);
			break;
		}
		ZEPHIR_INIT_VAR(&_2$$12);
		object_init_ex(&_2$$12, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$12);
		ZVAL_STRING(&_3$$12, "getPaintingAreaByPosition");
		ZEPHIR_CALL_METHOD(NULL, &_2$$12, "__construct", NULL, 3, &_3$$12);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$12, "nc/image/imageabstract.zep", 100 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	object_init_ex(return_value, nc_image_area_ce);
	ZVAL_LONG(&_4, w);
	ZVAL_LONG(&_5, h);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 17, &x, &y, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

