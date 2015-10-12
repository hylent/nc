
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Image_Item_Image) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image\\Item, Image, nc, image_item_image, nc_image_item_imageitemabstract_ce, nc_image_item_image_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Item_Image, resize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *width_param = NULL, *height_param = NULL, *_0, *_1, *_2;
	long width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, width);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, height);
	ZEPHIR_RETURN_CALL_METHOD(_0, "resize", NULL, 0, this_ptr, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Item_Image, crop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, *_0, *_1, *_2, *_3, *_4;
	long x, y, w, h;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &x_param, &y_param, &w_param, &h_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);
	w = zephir_get_intval(w_param);
	if (!h_param) {
		h = 0;
	} else {
		h = zephir_get_intval(h_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, x);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, y);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, w);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, h);
	ZEPHIR_RETURN_CALL_METHOD(_0, "crop", NULL, 0, this_ptr, _1, _2, _3, _4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Item_Image, thumbnail) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool cropped;
	zval *width_param = NULL, *height_param = NULL, *cropped_param = NULL, *_0, *_1, *_2, *_3;
	long width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &width_param, &height_param, &cropped_param);

	width = zephir_get_intval(width_param);
	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}
	if (!cropped_param) {
		cropped = 0;
	} else {
		cropped = zephir_get_boolval(cropped_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, width);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, height);
	ZEPHIR_INIT_VAR(_3);
	if (cropped) {
		ZVAL_BOOL(_3, 1);
	} else {
		ZVAL_BOOL(_3, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(_0, "thumbnail", NULL, 0, this_ptr, _1, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Item_Image, draw) {

	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval *srcItem, *x_param = NULL, *y_param = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &srcItem, &x_param, &y_param);

	if (!x_param) {
		x = 0;
	} else {
		x = zephir_get_intval(x_param);
	}
	if (!y_param) {
		y = 0;
	} else {
		y = zephir_get_intval(y_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, x);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, y);
	ZEPHIR_RETURN_CALL_METHOD(_0, "draw", NULL, 0, this_ptr, srcItem, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Item_Image, drawTo) {

	zval *_6$$12;
	int ZEPHIR_LAST_CALL_STATUS;
	long position, x = 0, y = 0, w = 0, h = 0, srcW = 0, srcH = 0;
	zval *srcItem, *position_param = NULL, *_0, *_1, *_2, *_3, *_7, *_8, *_9, *_4$$12, _5$$12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &srcItem, &position_param);

	position = zephir_get_intval(position_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, this_ptr, SL("width"), PH_NOISY_CC);
	w = zephir_get_intval(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, this_ptr, SL("height"), PH_NOISY_CC);
	h = zephir_get_intval(_1);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, srcItem, SL("width"), PH_NOISY_CC);
	srcW = zephir_get_intval(_2);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, srcItem, SL("height"), PH_NOISY_CC);
	srcH = zephir_get_intval(_3);
	do {
		if (position == 1) {
			x = 0;
			y = (h - srcH);
			break;
		}
		if (position == 2) {
			x = (long) (zephir_safe_div_long_long(((w - srcW)), 2 TSRMLS_CC));
			y = (h - srcH);
			break;
		}
		if (position == 3) {
			x = (w - srcW);
			y = (h - srcH);
			break;
		}
		if (position == 4) {
			x = 0;
			y = (long) (zephir_safe_div_long_long(((h - srcH)), 2 TSRMLS_CC));
			break;
		}
		if (position == 5) {
			x = (long) (zephir_safe_div_long_long(((w - srcW)), 2 TSRMLS_CC));
			y = (long) (zephir_safe_div_long_long(((h - srcH)), 2 TSRMLS_CC));
			break;
		}
		if (position == 6) {
			x = (w - srcW);
			y = (long) (zephir_safe_div_long_long(((h - srcH)), 2 TSRMLS_CC));
			break;
		}
		if (position == 7) {
			x = 0;
			y = 0;
			break;
		}
		if (position == 8) {
			x = (long) (zephir_safe_div_long_long(((w - srcW)), 2 TSRMLS_CC));
			y = 0;
			break;
		}
		if (position == 9) {
			x = (w - srcW);
			y = 0;
			break;
		}
		ZEPHIR_INIT_VAR(_4$$12);
		object_init_ex(_4$$12, nc_image_item_exception_ce);
		ZEPHIR_SINIT_VAR(_5$$12);
		ZVAL_LONG(&_5$$12, position);
		ZEPHIR_INIT_VAR(_6$$12);
		ZEPHIR_CONCAT_SV(_6$$12, "Invalid position: ", &_5$$12);
		ZEPHIR_CALL_METHOD(NULL, _4$$12, "__construct", NULL, 2, _6$$12);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$12, "nc/image/item/image.zep", 75 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	_7 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, x);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, y);
	ZEPHIR_RETURN_CALL_METHOD(_7, "draw", NULL, 0, this_ptr, srcItem, _8, _9);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Item_Image, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *destPath, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &destPath);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "save", NULL, 0, this_ptr, destPath);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Item_Image, __toString) {

	zval *_0$$3, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 78);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_implicit_flush", NULL, 79, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_NULL(_0$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, _0$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 80);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CPY_WRT(_1, EG(exception));
		if (zephir_instance_of_ev(_1, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 81);
			zephir_check_call_status();
		}
	}
	RETURN_MM_STRING("", 1);

}

