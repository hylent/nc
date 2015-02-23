
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Image_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Gd, nc, image_gd, nc_image_imageabstract_ce, nc_image_gd_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Gd, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *defaults_param = NULL, _0, *_1 = NULL;
	zval *defaults = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaults_param);

	if (!defaults_param) {
	ZEPHIR_INIT_VAR(defaults);
	array_init(defaults);
	} else {
		zephir_get_arrval(defaults, defaults_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "gd", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Missing extension: gd", "nc/image/gd.zep", 8);
		return;
	}
	if (zephir_fast_count_int(defaults TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaults", NULL, defaults);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, text) {

	int ZEPHIR_LAST_CALL_STATUS;
	long padding2;
	zval *options = NULL;
	zval *text_param = NULL, *options_param = NULL, *imProperties = NULL, *box = NULL, *_0, *_1, _2 = zval_used_for_init, *_3, *_4, *_5, *_6, _7, *_8;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &options_param);

	zephir_get_strval(text, text_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_METHOD(&imProperties, this_ptr, "validtextoptions", NULL, options);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, imProperties, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 23 TSRMLS_CC);
	zephir_array_fetch_string(&_1, imProperties, SL("font"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 23 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&box, "imagettfbbox", NULL, _0, &_2, _1, text);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(box))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagettfbbox", "nc/image/gd.zep", 25);
		return;
	}
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_string(&_3, imProperties, SL("padding"), PH_NOISY, "nc/image/gd.zep", 28 TSRMLS_CC);
	padding2 = (2 * zephir_get_intval(_3));
	zephir_array_update_string(&imProperties, SL("text"), &text, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_long(&_4, box, 2, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 31 TSRMLS_CC);
	zephir_array_fetch_long(&_5, box, 6, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 31 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	sub_function(&_2, _4, _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, (zephir_get_numberval(&_2) + padding2));
	zephir_array_update_string(&imProperties, SL("width"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_long(&_4, box, 3, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 32 TSRMLS_CC);
	zephir_array_fetch_long(&_5, box, 7, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 32 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_7);
	sub_function(&_7, _4, _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, (zephir_get_numberval(&_7) + padding2));
	zephir_array_update_string(&imProperties, SL("height"), &_8, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_text_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, captcha) {

	zephir_fcall_cache_entry *_19 = NULL, *_21 = NULL, *_25 = NULL, *_30 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	double rPadding, rOverlap;
	zval *options = NULL;
	long width, height, codeLen, fontSize, padding, r, g, b, dr, dg, db, i, j, x, y, x2, y2, angle;
	zval *code_param = NULL, *width_param = NULL, *height_param = NULL, *options_param = NULL, *validOptions = NULL, *im = NULL, *handler, *color = NULL, *shadow = NULL, *_0, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6, *_7, *_8, _10 = zval_used_for_init, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, _18 = zval_used_for_init, _20 = zval_used_for_init, *_22 = NULL, *_23 = NULL, *_24 = NULL, *_27 = NULL, *_28 = NULL, *_29 = NULL, *_31 = NULL, *_32 = NULL;
	zval *code = NULL, *font = NULL, *ch = NULL, *_1 = NULL, *_9 = NULL, *_26 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &code_param, &width_param, &height_param, &options_param);

	zephir_get_strval(code, code_param);
	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_METHOD(&validOptions, this_ptr, "validcaptchaoptions", NULL, options);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_0);
	zephir_array_fetch_string(&_0, validOptions, SL("font"), PH_NOISY, "nc/image/gd.zep", 46 TSRMLS_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(font, _1);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, validOptions, SL("rPadding"), PH_NOISY, "nc/image/gd.zep", 47 TSRMLS_CC);
	rPadding = zephir_get_doubleval(_2);
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_string(&_3, validOptions, SL("rOverlap"), PH_NOISY, "nc/image/gd.zep", 48 TSRMLS_CC);
	rOverlap = zephir_get_doubleval(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "utf-8", 0);
	ZEPHIR_CALL_FUNCTION(&_5, "mb_strlen", NULL, code, &_4);
	zephir_check_call_status();
	codeLen = zephir_get_intval(_5);
	fontSize = (long) (zephir_safe_div_double_long((1.0 * width), (((rPadding * (double) 2) + codeLen)) TSRMLS_CC));
	if (fontSize > height) {
		fontSize = height;
	}
	padding = (long) (((double) fontSize * rPadding));
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, width);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, height);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "png", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&im, this_ptr, "fromsize", NULL, _6, _7, _8);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "handler", 1);
	ZEPHIR_OBS_VAR(handler);
	zephir_read_property_zval(&handler, im, _9, PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 200);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 255);
	ZEPHIR_CALL_FUNCTION(&_11, "mt_rand", &_12, &_4, &_10);
	zephir_check_call_status();
	r = zephir_get_intval(_11);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 200);
	ZEPHIR_SINIT_NVAR(_10);
	ZVAL_LONG(&_10, 255);
	ZEPHIR_CALL_FUNCTION(&_13, "mt_rand", &_12, &_4, &_10);
	zephir_check_call_status();
	g = zephir_get_intval(_13);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 200);
	ZEPHIR_SINIT_NVAR(_10);
	ZVAL_LONG(&_10, 255);
	ZEPHIR_CALL_FUNCTION(&_14, "mt_rand", &_12, &_4, &_10);
	zephir_check_call_status();
	b = zephir_get_intval(_14);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 100);
	ZEPHIR_SINIT_NVAR(_10);
	ZVAL_LONG(&_10, 150);
	ZEPHIR_CALL_FUNCTION(&_15, "mt_rand", &_12, &_4, &_10);
	zephir_check_call_status();
	dr = (long) (zephir_safe_div_long_long((r - zephir_get_numberval(_15)), width TSRMLS_CC));
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 100);
	ZEPHIR_SINIT_NVAR(_10);
	ZVAL_LONG(&_10, 150);
	ZEPHIR_CALL_FUNCTION(&_16, "mt_rand", &_12, &_4, &_10);
	zephir_check_call_status();
	dg = (long) (zephir_safe_div_long_long((g - zephir_get_numberval(_16)), width TSRMLS_CC));
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 100);
	ZEPHIR_SINIT_NVAR(_10);
	ZVAL_LONG(&_10, 150);
	ZEPHIR_CALL_FUNCTION(&_17, "mt_rand", &_12, &_4, &_10);
	zephir_check_call_status();
	db = (long) (zephir_safe_div_long_long((b - zephir_get_numberval(_17)), width TSRMLS_CC));
	i = 0;
	while (1) {
		if (!(i < width)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, r);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, g);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, b);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_19, handler, &_4, &_10, &_18);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, i);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 0);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, i);
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_21, handler, &_4, &_10, &_18, &_20, color);
		zephir_check_call_status();
		r -= dr;
		g -= dg;
		b -= db;
		i++;
	}
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_NVAR(_10);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_SINIT_NVAR(_18);
	ZVAL_LONG(&_18, 0);
	ZEPHIR_CALL_FUNCTION(&shadow, "imagecolorallocate", &_19, handler, &_4, &_10, &_18);
	zephir_check_call_status();
	x = padding;
	i = 0;
	while (1) {
		if (!(i < codeLen)) {
			break;
		}
		x2 = (long) (((double) (width - (padding * 2)) - (((double) ((((double) (1.0 - rOverlap)) * (double) (((codeLen - i)))) + rOverlap)) * fontSize)));
		if (x2 > x) {
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, x);
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_LONG(&_10, x2);
			ZEPHIR_CALL_FUNCTION(&_22, "mt_rand", &_12, &_4, &_10);
			zephir_check_call_status();
			x = zephir_get_intval(_22);
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, fontSize);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, height);
		ZEPHIR_CALL_FUNCTION(&_22, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		y = zephir_get_intval(_22);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, -15);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 15);
		ZEPHIR_CALL_FUNCTION(&_23, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		angle = zephir_get_intval(_23);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, i);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 1);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_STRING(&_18, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_24, "mb_substr", &_25, code, &_4, &_10, &_18);
		zephir_check_call_status();
		zephir_get_strval(_26, _24);
		ZEPHIR_CPY_WRT(ch, _26);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 255);
		ZEPHIR_CALL_FUNCTION(&_27, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 255);
		ZEPHIR_CALL_FUNCTION(&_28, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 255);
		ZEPHIR_CALL_FUNCTION(&_29, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_19, handler, _27, _28, _29);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, fontSize);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, angle);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, (x + 1));
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, (y + 1));
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", &_30, handler, &_4, &_10, &_18, &_20, shadow, font, ch);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, fontSize);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, angle);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, x);
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, y);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", &_30, handler, &_4, &_10, &_18, &_20, color, font, ch);
		zephir_check_call_status();
		x = (x + (((double) (1.0 - rOverlap)) * fontSize));
		i++;
	}
	i = 0;
	while (1) {
		if (!(i < codeLen)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 255);
		ZEPHIR_CALL_FUNCTION(&_23, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 255);
		ZEPHIR_CALL_FUNCTION(&_24, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, 255);
		ZEPHIR_CALL_FUNCTION(&_27, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_19, handler, _23, _24, _27);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, width);
		ZEPHIR_CALL_FUNCTION(&_28, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		x = zephir_get_intval(_28);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, height);
		ZEPHIR_CALL_FUNCTION(&_29, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		y = zephir_get_intval(_29);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, width);
		ZEPHIR_CALL_FUNCTION(&_31, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		x2 = zephir_get_intval(_31);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, height);
		ZEPHIR_CALL_FUNCTION(&_32, "mt_rand", &_12, &_4, &_10);
		zephir_check_call_status();
		y2 = zephir_get_intval(_32);
		j = 0;
		while (1) {
			if (!(j <= padding)) {
				break;
			}
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, (x + j));
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_LONG(&_10, y);
			ZEPHIR_SINIT_NVAR(_18);
			ZVAL_LONG(&_18, (x2 + j));
			ZEPHIR_SINIT_NVAR(_20);
			ZVAL_LONG(&_20, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_21, handler, &_4, &_10, &_18, &_20, color);
			zephir_check_call_status();
			j++;
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, (x + j));
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, y);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, (x2 + j));
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, y2);
		ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_21, handler, &_4, &_10, &_18, &_20, shadow);
		zephir_check_call_status();
		i++;
	}
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Gd, fromImage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL, *_4 = NULL;
	zval *im, *copyIm = NULL, *_1, *_3, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	if (!(zephir_instance_of_ev(im, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "width", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "height", 1);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_zval(&_3, im, _2, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "extension", 1);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_zval(&_5, im, _4, PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&copyIm, this_ptr, "fromsize", NULL, _1, _3, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 0);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "copy", NULL, copyIm, im, _6, _7);
	zephir_check_call_status();
	RETURN_CCTOR(copyIm);

}

PHP_METHOD(Nc_Image_Gd, fromSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *extension = NULL;
	zval *width_param = NULL, *height_param = NULL, *extension_param = NULL, *imProperties, *handler = NULL, *background = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, _2, _3, *_4 = NULL, *_5, *_6;
	long width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &width_param, &height_param, &extension_param);

	width = zephir_get_intval(width_param);
	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}
	ZEPHIR_INIT_VAR(imProperties);
	array_init(imProperties);


	if (width < 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/gd.zep", 133);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, width);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&handler, "imagecreatetruecolor", NULL, &_0, &_1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image", "nc/image/gd.zep", 142);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 255);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 255);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 255);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 127);
	ZEPHIR_CALL_FUNCTION(&background, "imagecolorallocatealpha", NULL, handler, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagecolortransparent", NULL, handler, background);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, handler, &_0, &_1, background);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	if (extension && Z_STRLEN_P(extension)) {
		ZEPHIR_CPY_WRT(_4, extension);
	} else {
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "jpg", 1);
	}
	zephir_array_update_string(&imProperties, SL("extension"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, width);
	zephir_array_update_string(&imProperties, SL("width"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, height);
	zephir_array_update_string(&imProperties, SL("height"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, fromPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *path_param = NULL, *extension_param = NULL, *imProperties, *handler = NULL, *_0 = NULL, _1, *_2 = NULL, *_6 = NULL;
	zval *path = NULL, *extension = NULL, *ext = NULL, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &extension_param);

	zephir_get_strval(path, path_param);
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}
	ZEPHIR_INIT_VAR(imProperties);
	array_init(imProperties);


	if (extension && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, extension);
		zephir_get_strval(ext, _0);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 4);
		ZEPHIR_CALL_FUNCTION(&_2, "pathinfo", &_3, path, &_1);
		zephir_check_call_status();
		zephir_fast_strtolower(_0, _2);
		zephir_get_strval(_4, _0);
		ZEPHIR_CPY_WRT(ext, _4);
	}
	do {
		if (ZEPHIR_IS_STRING(ext, "png")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefrompng", NULL, path);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(ext, "gif")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromgif", NULL, path);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(ext, "jpg") || ZEPHIR_IS_STRING(ext, "jpeg")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromjpeg", NULL, path);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SV(_5, "Unsupported extension: ", ext);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "nc/image/gd.zep", 183 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image", "nc/image/gd.zep", 187);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesx", NULL, handler);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("width"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_6, "imagesy", NULL, handler);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("height"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, fromString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *extension_param = NULL, *imProperties, *handler = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *data = NULL, *extension = NULL, *ext = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &extension_param);

	zephir_get_strval(data, data_param);
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}
	ZEPHIR_INIT_VAR(imProperties);
	array_init(imProperties);


	if (extension && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, extension);
		zephir_get_strval(ext, _0);
	} else {
		ZEPHIR_INIT_VAR(ext);
		ZVAL_STRING(ext, "jpg", 1);
	}
	ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromstring", NULL, data);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image", "nc/image/gd.zep", 214);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, handler);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("width"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, handler);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("height"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, resize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL, *_4 = NULL;
	long width, height, srcW, srcH, w, h;
	zval *im, *width_param = NULL, *height_param = NULL, *destIm = NULL, *_1, *_3, *_5, *_6 = NULL, *_7 = NULL, *_8, *_9, *_10, *_11, *_12, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &im, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	if (!(zephir_instance_of_ev(im, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/gd.zep", 234);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "width", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
	srcW = zephir_get_intval(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "height", 1);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_zval(&_3, im, _2, PH_NOISY_CC);
	srcH = zephir_get_intval(_3);
	w = srcW;
	h = srcH;
	if ((w * height) > (h * width)) {
		w = width;
		h = (long) (zephir_safe_div_double_long(((1.0 * srcH) * w), srcW TSRMLS_CC));
	} else {
		h = height;
		w = (long) (zephir_safe_div_double_long(((1.0 * srcW) * h), srcH TSRMLS_CC));
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "extension", 1);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_zval(&_5, im, _4, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, w);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, h);
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromsize", NULL, _6, _7, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, 0);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, w);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, h);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 0);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, srcW);
	ZEPHIR_INIT_VAR(_13);
	ZVAL_LONG(_13, srcH);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "copyresampled", NULL, destIm, im, _6, _7, _8, _9, _10, _11, _12, _13);
	zephir_check_call_status();
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Gd, crop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1 = NULL, *_4 = NULL, *_6 = NULL;
	zend_bool _0, _3;
	long x, y, w, h;
	zval *im, *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, *destIm = NULL, *_2, *_5, *_7, *_8 = NULL, *_9 = NULL, *_10, *_11, *_12, *_13, *_14, *_15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &im, &x_param, &y_param, &w_param, &h_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);
	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);


	if (!(zephir_instance_of_ev(im, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	_0 = x < 0;
	if (!(_0)) {
		_0 = y < 0;
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Arguments x and y must not be negative", "nc/image/gd.zep", 266);
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument w must be positive", "nc/image/gd.zep", 270);
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "width", 1);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_zval(&_2, im, _1, PH_NOISY_CC);
	_3 = ZEPHIR_LT_LONG(_2, (x + w));
	if (!(_3)) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "height", 1);
		ZEPHIR_OBS_VAR(_5);
		zephir_read_property_zval(&_5, im, _4, PH_NOISY_CC);
		_3 = ZEPHIR_LT_LONG(_5, (y + h));
	}
	if (unlikely(_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cropping out of area", "nc/image/gd.zep", 278);
		return;
	}
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "extension", 1);
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property_zval(&_7, im, _6, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, w);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, h);
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromsize", NULL, _8, _9, _7);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_LONG(_8, 0);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_LONG(_9, 0);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, w);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, h);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, x);
	ZEPHIR_INIT_VAR(_13);
	ZVAL_LONG(_13, y);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_LONG(_14, w);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_LONG(_15, h);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "copyresampled", NULL, destIm, im, _8, _9, _10, _11, _12, _13, _14, _15);
	zephir_check_call_status();
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Gd, thumbnail) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL, *_4 = NULL;
	zend_bool cropped;
	long width, height, srcW, srcH, w, h, x, y;
	zval *im, *width_param = NULL, *height_param = NULL, *cropped_param = NULL, *destIm = NULL, *_1, *_3, *_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &im, &width_param, &height_param, &cropped_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	cropped = zephir_get_boolval(cropped_param);


	if (!(zephir_instance_of_ev(im, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Width must be positive", "nc/image/gd.zep", 293);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "width", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
	srcW = zephir_get_intval(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "height", 1);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_zval(&_3, im, _2, PH_NOISY_CC);
	srcH = zephir_get_intval(_3);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "extension", 1);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_zval(&_5, im, _4, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, width);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, height);
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromsize", NULL, _6, _7, _5);
	zephir_check_call_status();
	if (cropped) {
		if ((width * srcH) > (height * srcW)) {
			w = srcW;
			h = (long) (zephir_safe_div_double_long(((1.0 * height) * w), width TSRMLS_CC));
		} else {
			h = srcH;
			w = (long) (zephir_safe_div_double_long(((1.0 * width) * h), height TSRMLS_CC));
		}
		x = (long) ((0.5 * (double) (((srcW - w)))));
		y = (long) ((0.5 * (double) (((srcH - h)))));
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_INIT_VAR(_8);
		ZVAL_LONG(_8, width);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_LONG(_9, height);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_LONG(_10, x);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, y);
		ZEPHIR_INIT_VAR(_12);
		ZVAL_LONG(_12, w);
		ZEPHIR_INIT_VAR(_13);
		ZVAL_LONG(_13, h);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "copyresampled", NULL, destIm, im, _6, _7, _8, _9, _10, _11, _12, _13);
		zephir_check_call_status();
	} else {
		if ((width * srcH) < (height * srcW)) {
			w = width;
			h = (long) (zephir_safe_div_double_long(((1.0 * srcH) * w), srcW TSRMLS_CC));
		} else {
			h = height;
			w = (long) (zephir_safe_div_double_long(((1.0 * srcW) * h), srcH TSRMLS_CC));
		}
		x = (long) ((0.5 * (double) (((width - w)))));
		y = (long) ((0.5 * (double) (((height - h)))));
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, x);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, y);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, w);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, h);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, 0);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_LONG(_11, 0);
		ZEPHIR_INIT_NVAR(_12);
		ZVAL_LONG(_12, srcW);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_LONG(_13, srcH);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "copyresampled", NULL, destIm, im, _6, _7, _8, _9, _10, _11, _12, _13);
		zephir_check_call_status();
	}
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Gd, draw) {

	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval *destIm, *srcIm, *x_param = NULL, *y_param = NULL, *resultIm = NULL, *_0 = NULL, *_1 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &destIm, &srcIm, &x_param, &y_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);


	if (!(zephir_instance_of_ev(destIm, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'destIm' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(srcIm, nc_image_item_imageitemabstract_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'srcIm' must be an instance of 'Nc\\Image\\Item\\ImageItemAbstract'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&resultIm, this_ptr, "fromimage", NULL, destIm);
	zephir_check_call_status();
	do {
		if (zephir_instance_of_ev(srcIm, nc_image_item_image_ce TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, x);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, y);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "copy", &_2, resultIm, srcIm, _0, _1);
			zephir_check_call_status();
			break;
		}
		if (zephir_instance_of_ev(srcIm, nc_image_item_text_ce TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, x);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, y);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "drawtext", &_3, resultIm, srcIm, _0, _1);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, nc_image_exception_ce);
		ZEPHIR_INIT_NVAR(_1);
		zephir_get_class(_1, srcIm, 0 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Invalid item type: ", _1);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_5, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "nc/image/gd.zep", 349 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while (0);
	RETURN_CCTOR(resultIm);

}

PHP_METHOD(Nc_Image_Gd, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL;
	zval *im, *destPath, *_1, *_3 = NULL, *_4 = NULL, _5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &im, &destPath);



	if (!(zephir_instance_of_ev(im, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "extension", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(_1, "png")) {
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "handler", 1);
			ZEPHIR_OBS_VAR(_3);
			zephir_read_property_zval(&_3, im, _2, PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_4, "imagepng", NULL, _3, destPath);
			zephir_check_call_status();
			if (zephir_is_true(_4)) {
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "gif")) {
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "handler", 1);
			ZEPHIR_OBS_NVAR(_3);
			zephir_read_property_zval(&_3, im, _2, PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_4, "imagegif", NULL, _3, destPath);
			zephir_check_call_status();
			if (zephir_is_true(_4)) {
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "jpg") || ZEPHIR_IS_STRING(_1, "jpeg")) {
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "handler", 1);
			ZEPHIR_OBS_NVAR(_3);
			zephir_read_property_zval(&_3, im, _2, PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_LONG(&_5, 100);
			ZEPHIR_CALL_FUNCTION(&_4, "imagejpeg", NULL, _3, destPath, &_5);
			zephir_check_call_status();
			if (zephir_is_true(_4)) {
				RETURN_MM_NULL();
			}
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Unsupported extension", "nc/image/gd.zep", 378);
		return;
	} while(0);

	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot save image", "nc/image/gd.zep", 381);
	return;

}

PHP_METHOD(Nc_Image_Gd, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;
	zval *im, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	if (!(zephir_instance_of_ev(im, nc_image_item_imageitemabstract_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Item\\ImageItemAbstract'", "", 0);
		return;
	}
	if (zephir_instance_of_ev(im, nc_image_item_image_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "handler", 1);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _1);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, drawText) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL, *_4 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_12 = NULL, *_15 = NULL, *_17 = NULL, *_19 = NULL;
	long x, y, alpha;
	zval *dest, *src, *x_param = NULL, *y_param = NULL, *handler, *color = NULL, *_1, *_3 = NULL, *_5 = NULL, *_6, *_11, *_13, _14 = zval_used_for_init, *_16, *_18, *_20, _21, _22, *_23 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &dest, &src, &x_param, &y_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);


	if (!(zephir_instance_of_ev(dest, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dest' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(src, nc_image_item_text_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'src' must be an instance of 'Nc\\Image\\Item\\Text'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "padding", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, src, _0, PH_NOISY_CC);
	x += zephir_get_numberval(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "height", 1);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_zval(&_3, src, _2, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "padding", 1);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_zval(&_5, src, _4, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	sub_function(_6, _3, _5 TSRMLS_CC);
	y += zephir_get_numberval(_6);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "handler", 1);
	ZEPHIR_OBS_VAR(handler);
	zephir_read_property_zval(&handler, dest, _7, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_STRING(_8, "opacity", 1);
	ZEPHIR_OBS_NVAR(_3);
	zephir_read_property_zval(&_3, src, _8, PH_NOISY_CC);
	alpha = (long) ((1.0 - zephir_get_numberval(_3)) * 127.0);
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "red", 1);
	ZEPHIR_OBS_NVAR(_5);
	zephir_read_property_zval(&_5, src, _9, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "green", 1);
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property_zval(&_11, src, _10, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "blue", 1);
	ZEPHIR_OBS_VAR(_13);
	zephir_read_property_zval(&_13, src, _12, PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, handler, _5, _11, _13, &_14);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "fontSize", 1);
	ZEPHIR_OBS_VAR(_16);
	zephir_read_property_zval(&_16, src, _15, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_17);
	ZEPHIR_INIT_NVAR(_17);
	ZVAL_STRING(_17, "font", 1);
	ZEPHIR_OBS_VAR(_18);
	zephir_read_property_zval(&_18, src, _17, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_INIT_NVAR(_19);
	ZVAL_STRING(_19, "text", 1);
	ZEPHIR_OBS_VAR(_20);
	zephir_read_property_zval(&_20, src, _19, PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_14);
	ZVAL_LONG(&_14, 0);
	ZEPHIR_SINIT_VAR(_21);
	ZVAL_LONG(&_21, x);
	ZEPHIR_SINIT_VAR(_22);
	ZVAL_LONG(&_22, y);
	ZEPHIR_CALL_FUNCTION(&_23, "imagettftext", NULL, handler, _16, &_14, &_21, &_22, color, _18, _20);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_23))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagettftext", "nc/image/gd.zep", 405);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, copy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL, *_4 = NULL, *_6 = NULL;
	long x, y;
	zval *dest, *src, *x_param = NULL, *y_param = NULL, *_1, *_3, *_5, *_7, _8, _9, _10, _11, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &dest, &src, &x_param, &y_param);

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


	if (!(zephir_instance_of_ev(dest, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dest' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(src, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'src' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "handler", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, dest, _0, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "handler", 1);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_zval(&_3, src, _2, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "width", 1);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_zval(&_5, src, _4, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "height", 1);
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property_zval(&_7, src, _6, PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, x);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, y);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 0);
	ZEPHIR_CALL_FUNCTION(&_12, "imagecopy", NULL, _1, _3, &_8, &_9, &_10, &_11, _5, _7);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_12))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagecopy", "nc/image/gd.zep", 412);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, copyResampled) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL;
	long x, y, w, h, srcX, srcY, srcW, srcH;
	zval *dest, *src, *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, *srcX_param = NULL, *srcY_param = NULL, *srcW_param = NULL, *srcH_param = NULL, *_1, *_3, _4, _5, _6, _7, _8, _9, _10, _11, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 10, 0, &dest, &src, &x_param, &y_param, &w_param, &h_param, &srcX_param, &srcY_param, &srcW_param, &srcH_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);
	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);
	srcX = zephir_get_intval(srcX_param);
	srcY = zephir_get_intval(srcY_param);
	srcW = zephir_get_intval(srcW_param);
	srcH = zephir_get_intval(srcH_param);


	if (!(zephir_instance_of_ev(dest, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dest' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(src, nc_image_item_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'src' must be an instance of 'Nc\\Image\\Item\\Image'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "handler", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, dest, _0, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "handler", 1);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_zval(&_3, src, _2, PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, x);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, y);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, srcX);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, srcY);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, w);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, h);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, srcW);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, srcH);
	ZEPHIR_CALL_FUNCTION(&_12, "imagecopyresampled", NULL, _1, _3, &_4, &_5, &_6, &_7, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_12))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagecopyresampled", "nc/image/gd.zep", 421);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

