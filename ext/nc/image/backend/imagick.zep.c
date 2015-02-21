
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Image_Backend_Imagick) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image\\Backend, Imagick, nc, image_backend_imagick, nc_image_backend_imagebackendadapter_ce, nc_image_backend_imagick_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Backend_Imagick, __construct) {

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
	ZVAL_STRING(&_0, "imagick", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_backend_exception_ce, "Missing extension: imagick", "nc/image/backend/imagick.zep", 12);
		return;
	}
	if (zephir_fast_count_int(defaults TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaults", NULL, defaults);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Backend_Imagick, text) {

	int ZEPHIR_LAST_CALL_STATUS;
	long padding2;
	zval *options = NULL;
	zval *text_param = NULL, *options_param = NULL, *imProperties = NULL, *imagick, *imgickDraw, *m = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6;
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
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(imgickDraw);
	object_init_ex(imgickDraw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "__construct", NULL);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, imProperties, SL("font"), PH_NOISY | PH_READONLY, "nc/image/backend/imagick.zep", 29 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "setfont", NULL, _0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, imProperties, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/backend/imagick.zep", 30 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "setfontsize", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&m, imagick, "queryfontmetrics", NULL, imgickDraw, text);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, imProperties, SL("padding"), PH_NOISY, "nc/image/backend/imagick.zep", 33 TSRMLS_CC);
	padding2 = (2 * zephir_get_intval(_2));
	zephir_array_update_string(&imProperties, SL("text"), &text, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_3, m, SL("textWidth"), PH_NOISY | PH_READONLY, "nc/image/backend/imagick.zep", 36 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, (zephir_get_numberval(_3) + padding2));
	zephir_array_update_string(&imProperties, SL("width"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_5, m, SL("textHeight"), PH_NOISY | PH_READONLY, "nc/image/backend/imagick.zep", 37 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, (zephir_get_numberval(_5) + padding2));
	zephir_array_update_string(&imProperties, SL("height"), &_6, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_text_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Backend_Imagick, captcha) {

	zephir_fcall_cache_entry *_20 = NULL, *_21 = NULL, *_24 = NULL, *_30 = NULL, *_35 = NULL, *_36 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	double rPadding, rOverlap;
	zval *options = NULL;
	long width, height, codeLen, fontSize, padding, r, g, b, dr, dg, db, i, j, x, y, x2, y2, angle;
	zval *code_param = NULL, *width_param = NULL, *height_param = NULL, *options_param = NULL, *validOptions = NULL, *im = NULL, *imagick, *imagickDraw, *shadow, *_0, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, _10 = zval_used_for_init, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, _18 = zval_used_for_init, *_22 = NULL, *_23 = NULL, _25 = zval_used_for_init, *_26 = NULL, *_27 = NULL, _28 = zval_used_for_init, *_29 = NULL, *_32 = NULL, *_33 = NULL, *_34 = NULL, _37 = zval_used_for_init, _38 = zval_used_for_init, _39 = zval_used_for_init, *_40 = NULL, *_41 = NULL, *_42 = NULL, *_43 = NULL;
	zval *code = NULL, *font = NULL, *ch = NULL, *_1 = NULL, *_9 = NULL, *_19 = NULL, *_31 = NULL;

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
	zephir_array_fetch_string(&_0, validOptions, SL("font"), PH_NOISY, "nc/image/backend/imagick.zep", 51 TSRMLS_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(font, _1);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, validOptions, SL("rPadding"), PH_NOISY, "nc/image/backend/imagick.zep", 52 TSRMLS_CC);
	rPadding = zephir_get_doubleval(_2);
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_string(&_3, validOptions, SL("rOverlap"), PH_NOISY, "nc/image/backend/imagick.zep", 53 TSRMLS_CC);
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
	ZVAL_STRING(_9, "imagick", 1);
	ZEPHIR_OBS_VAR(imagick);
	zephir_read_property_zval(&imagick, im, _9, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(imagickDraw);
	object_init_ex(imagickDraw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "__construct", NULL);
	zephir_check_call_status();
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
		ZEPHIR_INIT_NVAR(_6);
		object_init_ex(_6, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, r);
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_LONG(&_10, g);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, b);
		ZEPHIR_INIT_LNVAR(_19);
		ZEPHIR_CONCAT_SVSVSVS(_19, "rgb(", &_4, ",", &_10, ",", &_18, ")");
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_20, _19);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_21, _6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, i);
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, 0);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, i);
		ZEPHIR_INIT_NVAR(_23);
		ZVAL_LONG(_23, height);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_24, _7, _8, _22, _23);
		zephir_check_call_status();
		r -= dr;
		g -= dg;
		b -= db;
		i++;
	}
	ZEPHIR_CALL_METHOD(NULL, imagick, "drawimage", NULL, imagickDraw);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "clear", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(shadow);
	object_init_ex(shadow, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "#000000", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, shadow, "__construct", &_20, _7);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfont", NULL, font);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, fontSize);
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfontsize", NULL, _7);
	zephir_check_call_status();
	x = padding;
	i = 0;
	while (1) {
		if (!(i < codeLen)) {
			break;
		}
		x2 = (long) (((double) (width - (padding * 2)) - (((double) ((((double) (1.0 - rOverlap)) * (double) (((codeLen - i)))) + rOverlap)) * fontSize)));
		if (x2 > x) {
			ZEPHIR_SINIT_NVAR(_18);
			ZVAL_LONG(&_18, x);
			ZEPHIR_SINIT_NVAR(_25);
			ZVAL_LONG(&_25, x2);
			ZEPHIR_CALL_FUNCTION(&_26, "mt_rand", &_12, &_18, &_25);
			zephir_check_call_status();
			x = zephir_get_intval(_26);
		}
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, fontSize);
		ZEPHIR_SINIT_NVAR(_25);
		ZVAL_LONG(&_25, height);
		ZEPHIR_CALL_FUNCTION(&_26, "mt_rand", &_12, &_18, &_25);
		zephir_check_call_status();
		y = zephir_get_intval(_26);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, -15);
		ZEPHIR_SINIT_NVAR(_25);
		ZVAL_LONG(&_25, 15);
		ZEPHIR_CALL_FUNCTION(&_27, "mt_rand", &_12, &_18, &_25);
		zephir_check_call_status();
		angle = zephir_get_intval(_27);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, i);
		ZEPHIR_SINIT_NVAR(_25);
		ZVAL_LONG(&_25, 1);
		ZEPHIR_SINIT_NVAR(_28);
		ZVAL_STRING(&_28, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_29, "mb_substr", &_30, code, &_18, &_25, &_28);
		zephir_check_call_status();
		zephir_get_strval(_31, _29);
		ZEPHIR_CPY_WRT(ch, _31);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_25);
		ZVAL_LONG(&_25, 255);
		ZEPHIR_CALL_FUNCTION(&_32, "mt_rand", &_12, &_18, &_25);
		zephir_check_call_status();
		r = zephir_get_intval(_32);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_25);
		ZVAL_LONG(&_25, 255);
		ZEPHIR_CALL_FUNCTION(&_33, "mt_rand", &_12, &_18, &_25);
		zephir_check_call_status();
		g = zephir_get_intval(_33);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_25);
		ZVAL_LONG(&_25, 255);
		ZEPHIR_CALL_FUNCTION(&_34, "mt_rand", &_12, &_18, &_25);
		zephir_check_call_status();
		b = zephir_get_intval(_34);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_21, shadow);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_LONG(_7, (x + 1));
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, (y + 1));
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, angle);
		ZEPHIR_CALL_METHOD(NULL, imagick, "annotateimage", &_35, imagickDraw, _7, _8, _22, ch);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7);
		object_init_ex(_7, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, r);
		ZEPHIR_SINIT_NVAR(_25);
		ZVAL_LONG(&_25, g);
		ZEPHIR_SINIT_NVAR(_28);
		ZVAL_LONG(&_28, b);
		ZEPHIR_INIT_LNVAR(_19);
		ZEPHIR_CONCAT_SVSVSVS(_19, "rgb(", &_18, ",", &_25, ",", &_28, ")");
		ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_20, _19);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_21, _7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_8);
		ZVAL_LONG(_8, x);
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, y);
		ZEPHIR_INIT_NVAR(_23);
		ZVAL_LONG(_23, angle);
		ZEPHIR_CALL_METHOD(NULL, imagick, "annotateimage", &_36, imagickDraw, _8, _22, _23, ch);
		zephir_check_call_status();
		x = (x + (((double) (1.0 - rOverlap)) * fontSize));
		i++;
	}
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "clear", NULL);
	zephir_check_call_status();
	i = 0;
	while (1) {
		if (!(i < codeLen)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_28);
		ZVAL_LONG(&_28, 255);
		ZEPHIR_CALL_FUNCTION(&_27, "mt_rand", &_12, &_18, &_28);
		zephir_check_call_status();
		r = zephir_get_intval(_27);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_28);
		ZVAL_LONG(&_28, 255);
		ZEPHIR_CALL_FUNCTION(&_29, "mt_rand", &_12, &_18, &_28);
		zephir_check_call_status();
		g = zephir_get_intval(_29);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_28);
		ZVAL_LONG(&_28, 255);
		ZEPHIR_CALL_FUNCTION(&_32, "mt_rand", &_12, &_18, &_28);
		zephir_check_call_status();
		b = zephir_get_intval(_32);
		ZEPHIR_INIT_NVAR(_8);
		object_init_ex(_8, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, r);
		ZEPHIR_SINIT_NVAR(_28);
		ZVAL_LONG(&_28, g);
		ZEPHIR_SINIT_NVAR(_37);
		ZVAL_LONG(&_37, b);
		ZEPHIR_INIT_LNVAR(_19);
		ZEPHIR_CONCAT_SVSVSVS(_19, "rgb(", &_18, ",", &_28, ",", &_37, ")");
		ZEPHIR_CALL_METHOD(NULL, _8, "__construct", &_20, _19);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_21, _8);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_38);
		ZVAL_LONG(&_38, 0);
		ZEPHIR_SINIT_NVAR(_39);
		ZVAL_LONG(&_39, width);
		ZEPHIR_CALL_FUNCTION(&_33, "mt_rand", &_12, &_38, &_39);
		zephir_check_call_status();
		x = zephir_get_intval(_33);
		ZEPHIR_SINIT_NVAR(_38);
		ZVAL_LONG(&_38, 0);
		ZEPHIR_SINIT_NVAR(_39);
		ZVAL_LONG(&_39, height);
		ZEPHIR_CALL_FUNCTION(&_34, "mt_rand", &_12, &_38, &_39);
		zephir_check_call_status();
		y = zephir_get_intval(_34);
		ZEPHIR_SINIT_NVAR(_38);
		ZVAL_LONG(&_38, 0);
		ZEPHIR_SINIT_NVAR(_39);
		ZVAL_LONG(&_39, width);
		ZEPHIR_CALL_FUNCTION(&_40, "mt_rand", &_12, &_38, &_39);
		zephir_check_call_status();
		x2 = zephir_get_intval(_40);
		ZEPHIR_SINIT_NVAR(_38);
		ZVAL_LONG(&_38, 0);
		ZEPHIR_SINIT_NVAR(_39);
		ZVAL_LONG(&_39, height);
		ZEPHIR_CALL_FUNCTION(&_41, "mt_rand", &_12, &_38, &_39);
		zephir_check_call_status();
		y2 = zephir_get_intval(_41);
		j = 0;
		while (1) {
			if (!(j <= padding)) {
				break;
			}
			ZEPHIR_INIT_NVAR(_22);
			ZVAL_LONG(_22, (x + j));
			ZEPHIR_INIT_NVAR(_23);
			ZVAL_LONG(_23, y);
			ZEPHIR_INIT_NVAR(_42);
			ZVAL_LONG(_42, (x2 + j));
			ZEPHIR_INIT_NVAR(_43);
			ZVAL_LONG(_43, y2);
			ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_24, _22, _23, _42, _43);
			zephir_check_call_status();
			j++;
		}
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_21, shadow);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_LONG(_22, (x + j));
		ZEPHIR_INIT_NVAR(_23);
		ZVAL_LONG(_23, y);
		ZEPHIR_INIT_NVAR(_42);
		ZVAL_LONG(_42, (x2 + j));
		ZEPHIR_INIT_NVAR(_43);
		ZVAL_LONG(_43, y2);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_24, _22, _23, _42, _43);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_CALL_METHOD(NULL, imagick, "drawimage", NULL, imagickDraw);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "clear", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Backend_Imagick, fromImage) {

	zval *_0 = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *imProperties, *imagick, *_1, *_2 = NULL, *_4, *_6, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);

	ZEPHIR_INIT_VAR(imProperties);
	array_init(imProperties);


	if (!(zephir_instance_of_ev(im, nc_image_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Image'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "imagick", 1);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "getimageblob", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimageblob", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "extension", 1);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_zval(&_4, im, _3, PH_NOISY_CC);
	zephir_array_update_string(&imProperties, SL("extension"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_STRING(_5, "width", 1);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_zval(&_6, im, _5, PH_NOISY_CC);
	zephir_array_update_string(&imProperties, SL("width"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "height", 1);
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property_zval(&_8, im, _7, PH_NOISY_CC);
	zephir_array_update_string(&imProperties, SL("height"), &_8, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("imagick"), &imagick, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Backend_Imagick, fromSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *extension = NULL, *ext = NULL;
	zval *width_param = NULL, *height_param = NULL, *extension_param = NULL, *imProperties, *imagick, *_0 = NULL, *_1 = NULL, *_2 = NULL;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_backend_exception_ce, "Argument width must be positive", "nc/image/backend/imagick.zep", 162);
		return;
	}
	if (height < 1) {
		height = width;
	}
	if (extension && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strtolower(_0, extension);
		zephir_get_strval(ext, _0);
	} else {
		ZEPHIR_INIT_VAR(ext);
		ZVAL_STRING(ext, "jpg", 1);
	}
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "rgba(255,255,255,127)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, width);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, height);
	ZEPHIR_CALL_METHOD(NULL, imagick, "newimage", NULL, _1, _2, _0, ext);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, width);
	zephir_array_update_string(&imProperties, SL("width"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, height);
	zephir_array_update_string(&imProperties, SL("height"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("imagick"), &imagick, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Backend_Imagick, fromPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zval *path_param = NULL, *extension_param = NULL, *imProperties, *imagick, *_0 = NULL, _1, *_2 = NULL, *_6 = NULL, *_7 = NULL;
	zval *path = NULL, *extension = NULL, *ext = NULL, *_4 = NULL;

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
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "realpath", &_5, path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimage", NULL, _2);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_6, imagick, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("width"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, imagick, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("height"), &_7, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("imagick"), &imagick, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Backend_Imagick, fromString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *extension_param = NULL, *imProperties, *imagick, *_0, *_1 = NULL, *_2 = NULL;
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
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimageblob", NULL, data);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, imagick, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("width"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, imagick, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("height"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("imagick"), &imagick, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Backend_Imagick, resize) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long width, height;
	zval *im, *width_param = NULL, *height_param = NULL, *destIm = NULL, *imagick, *_1, *_2, *_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &im, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	if (!(zephir_instance_of_ev(im, nc_image_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Image'", "", 0);
		return;
	}
	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_backend_exception_ce, "Argument width must be positive", "nc/image/backend/imagick.zep", 235);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, im);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "imagick", 1);
	ZEPHIR_OBS_VAR(imagick);
	zephir_read_property_zval(&imagick, destIm, _0, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, width);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, height);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(NULL, imagick, "thumbnailimage", NULL, _1, _2, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, imagick, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_update_property_zval(destIm, SL("width"), _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, imagick, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_update_property_zval(destIm, SL("height"), _5 TSRMLS_CC);
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Backend_Imagick, crop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1 = NULL, *_4 = NULL, *_6 = NULL;
	zend_bool _0, _3;
	long x, y, w, h;
	zval *im, *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, *destIm = NULL, *_2, *_5, *_7, *_8 = NULL, *_9 = NULL, *_10, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &im, &x_param, &y_param, &w_param, &h_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);
	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);


	if (!(zephir_instance_of_ev(im, nc_image_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Image'", "", 0);
		return;
	}
	_0 = x < 0;
	if (!(_0)) {
		_0 = y < 0;
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_backend_exception_ce, "Arguments x and y must not be negative", "nc/image/backend/imagick.zep", 258);
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_backend_exception_ce, "Argument w must be positive", "nc/image/backend/imagick.zep", 262);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_backend_exception_ce, "Cropping out of area", "nc/image/backend/imagick.zep", 270);
		return;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, im);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "imagick", 1);
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property_zval(&_7, destIm, _6, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, w);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, h);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, x);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, y);
	ZEPHIR_CALL_METHOD(NULL, _7, "cropimage", NULL, _8, _9, _10, _11);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_LONG(_8, w);
	zephir_update_property_zval(destIm, SL("width"),  _8 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_LONG(_9, h);
	zephir_update_property_zval(destIm, SL("height"),  _9 TSRMLS_CC);
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Backend_Imagick, thumbnail) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool cropped;
	long width, height;
	zval *im, *width_param = NULL, *height_param = NULL, *cropped_param = NULL, *destIm = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &im, &width_param, &height_param, &cropped_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	cropped = zephir_get_boolval(cropped_param);


	if (!(zephir_instance_of_ev(im, nc_image_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Image'", "", 0);
		return;
	}
	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_backend_exception_ce, "Argument width must be positive", "nc/image/backend/imagick.zep", 287);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, im);
	zephir_check_call_status();
	if (cropped) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "imagick", 1);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, destIm, _0, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, width);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_CALL_METHOD(NULL, _1, "cropthumbnailimage", NULL, _2, _3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "imagick", 1);
		ZEPHIR_OBS_NVAR(_1);
		zephir_read_property_zval(&_1, destIm, _0, PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, width);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, height);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_BOOL(_4, 1);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_BOOL(_5, 1);
		ZEPHIR_CALL_METHOD(NULL, _1, "thumbnailimage", NULL, _2, _3, _4, _5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, width);
	zephir_update_property_zval(destIm, SL("width"),  _2 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, height);
	zephir_update_property_zval(destIm, SL("height"),  _3 TSRMLS_CC);
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Backend_Imagick, draw) {

	zval *_0 = NULL, *_2 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_18 = NULL, *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval *destIm, *srcIm, *x_param = NULL, *y_param = NULL, *resultIm = NULL, *imagickDraw, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_8, *_10, *_12, *_14 = NULL, *_16 = NULL, *_17 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &destIm, &srcIm, &x_param, &y_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);


	if (!(zephir_instance_of_ev(destIm, nc_image_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'destIm' must be an instance of 'Nc\\Image\\Image'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(srcIm, nc_image_item_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'srcIm' must be an instance of 'Nc\\Image\\Item'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&resultIm, this_ptr, "fromimage", NULL, destIm);
	zephir_check_call_status();
	if (zephir_instance_of_ev(srcIm, nc_image_image_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "imagick", 1);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, resultIm, _0, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "imagick", 1);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property_zval(&_3, srcIm, _2, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 40);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, x);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_LONG(_6, y);
		ZEPHIR_CALL_METHOD(NULL, _1, "compositeimage", NULL, _3, _4, _5, _6);
		zephir_check_call_status();
		RETURN_CCTOR(resultIm);
	}
	if (zephir_instance_of_ev(srcIm, nc_image_text_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(imagickDraw);
		object_init_ex(imagickDraw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "__construct", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "font", 1);
		ZEPHIR_OBS_NVAR(_1);
		zephir_read_property_zval(&_1, srcIm, _0, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfont", NULL, _1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_2);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "fontSize", 1);
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_property_zval(&_3, srcIm, _2, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfontsize", NULL, _3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, "color", 1);
		ZEPHIR_OBS_VAR(_8);
		zephir_read_property_zval(&_8, srcIm, _7, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", NULL, _8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "opacity", 1);
		ZEPHIR_OBS_VAR(_10);
		zephir_read_property_zval(&_10, srcIm, _9, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillopacity", NULL, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_11);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "padding", 1);
		ZEPHIR_OBS_VAR(_12);
		zephir_read_property_zval(&_12, srcIm, _11, PH_NOISY_CC);
		x += zephir_get_numberval(_12);
		ZEPHIR_INIT_VAR(_13);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_STRING(_13, "height", 1);
		ZEPHIR_OBS_VAR(_14);
		zephir_read_property_zval(&_14, srcIm, _13, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_15);
		ZEPHIR_INIT_NVAR(_15);
		ZVAL_STRING(_15, "padding", 1);
		ZEPHIR_OBS_VAR(_16);
		zephir_read_property_zval(&_16, srcIm, _15, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_17);
		sub_function(_17, _14, _16 TSRMLS_CC);
		y += zephir_get_numberval(_17);
		ZEPHIR_INIT_VAR(_18);
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_STRING(_18, "imagick", 1);
		ZEPHIR_OBS_NVAR(_14);
		zephir_read_property_zval(&_14, resultIm, _18, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_19);
		ZEPHIR_INIT_NVAR(_19);
		ZVAL_STRING(_19, "text", 1);
		ZEPHIR_OBS_NVAR(_16);
		zephir_read_property_zval(&_16, srcIm, _19, PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, x);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, y);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_CALL_METHOD(NULL, _14, "annotateimage", NULL, imagickDraw, _4, _5, _6, _16);
		zephir_check_call_status();
		RETURN_CCTOR(resultIm);
	}
	ZEPHIR_INIT_NVAR(_4);
	object_init_ex(_4, nc_image_backend_exception_ce);
	ZEPHIR_INIT_NVAR(_5);
	zephir_get_class(_5, srcIm, 0 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_17);
	ZEPHIR_CONCAT_SV(_17, "Invalid item type: ", _5);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _17);
	zephir_check_call_status();
	zephir_throw_exception_debug(_4, "nc/image/backend/imagick.zep", 331 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Image_Backend_Imagick, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;
	zval *im, *destPath, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &im, &destPath);



	if (!(zephir_instance_of_ev(im, nc_image_image_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Image'", "", 0);
		return;
	}
	if (Z_TYPE_P(destPath) == IS_NULL) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "imagick", 1);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "getimageblob", NULL);
		zephir_check_call_status();
		zend_print_zval(_2, 0);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "imagick", 1);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "writeimage", NULL, destPath);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Backend_Imagick, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;
	zval *im, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	if (!(zephir_instance_of_ev(im, nc_image_item_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'im' must be an instance of 'Nc\\Image\\Item'", "", 0);
		return;
	}
	if (zephir_instance_of_ev(im, nc_image_image_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "imagick", 1);
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, im, _0, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "clear", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

