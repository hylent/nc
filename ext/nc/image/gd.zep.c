
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
#include "kernel/math.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Image_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Gd, nc, image_gd, nc_image_imageabstract_ce, nc_image_gd_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Gd, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 14, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Missing extension: gd", "nc/image/gd.zep", 8);
		return;
	}
	if (zephir_fast_count_int(defaults TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaults", NULL, 0, defaults);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, text) {

	long padding2 = 0;
	int ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_CALL_METHOD(&imProperties, this_ptr, "validtextoptions", NULL, 0, options);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, imProperties, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 23 TSRMLS_CC);
	zephir_array_fetch_string(&_1, imProperties, SL("font"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 23 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&box, "imagettfbbox", NULL, 52, _0, &_2, _1, text);
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
	zephir_sub_function(&_2, _4, _5);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, (zephir_get_numberval(&_2) + padding2));
	zephir_array_update_string(&imProperties, SL("width"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_long(&_4, box, 3, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 32 TSRMLS_CC);
	zephir_array_fetch_long(&_5, box, 7, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 32 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_7);
	zephir_sub_function(&_7, _4, _5);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, (zephir_get_numberval(&_7) + padding2));
	zephir_array_update_string(&imProperties, SL("height"), &_8, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_text_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, captcha) {

	double rPadding = 0, rOverlap = 0;
	zephir_fcall_cache_entry *_23 = NULL, *_25 = NULL, *_39 = NULL, *_48 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	long width, height, codeLen = 0, fontSize = 0, padding = 0, r = 0, g = 0, b = 0, dr = 0, dg = 0, db = 0, i = 0, j = 0, x = 0, y = 0, x2 = 0, y2 = 0, angle = 0;
	zval *code_param = NULL, *width_param = NULL, *height_param = NULL, *options_param = NULL, *validOptions = NULL, *im = NULL, *handler = NULL, *color = NULL, *shadow = NULL, *_0, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6, *_7, *_8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _26, _27, _28, _20$$4 = zval_used_for_init, _21$$4 = zval_used_for_init, _22$$4 = zval_used_for_init, _24$$4 = zval_used_for_init, _29$$6 = zval_used_for_init, _30$$6 = zval_used_for_init, _31$$5 = zval_used_for_init, _32$$5 = zval_used_for_init, _33$$5 = zval_used_for_init, _34$$5 = zval_used_for_init, _35$$5 = zval_used_for_init, _36$$5 = zval_used_for_init, _37$$5 = zval_used_for_init, *_38$$5 = NULL, _41$$5 = zval_used_for_init, _42$$5 = zval_used_for_init, _43$$5 = zval_used_for_init, _44$$5 = zval_used_for_init, _45$$5 = zval_used_for_init, _46$$5 = zval_used_for_init, _47$$5 = zval_used_for_init, _49$$7 = zval_used_for_init, _50$$7 = zval_used_for_init, _51$$7 = zval_used_for_init, _52$$7 = zval_used_for_init, _53$$7 = zval_used_for_init, _54$$7 = zval_used_for_init, _55$$7 = zval_used_for_init, _56$$7 = zval_used_for_init, _57$$7 = zval_used_for_init, _58$$7 = zval_used_for_init, _59$$7 = zval_used_for_init, _60$$7 = zval_used_for_init, _61$$7 = zval_used_for_init, _62$$7 = zval_used_for_init, _67$$7 = zval_used_for_init, _68$$7 = zval_used_for_init, _69$$7 = zval_used_for_init, _70$$7 = zval_used_for_init, _63$$8 = zval_used_for_init, _64$$8 = zval_used_for_init, _65$$8 = zval_used_for_init, _66$$8 = zval_used_for_init;
	zval *code = NULL, *font = NULL, *ch = NULL, *_1 = NULL, *_40$$5 = NULL;

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


	ZEPHIR_CALL_METHOD(&validOptions, this_ptr, "validcaptchaoptions", NULL, 0, options);
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
	ZEPHIR_CALL_FUNCTION(&_5, "mb_strlen", NULL, 54, code, &_4);
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
	ZEPHIR_CALL_METHOD(&im, this_ptr, "fromsize", NULL, 0, _6, _7, _8);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(handler);
	zephir_read_property(&handler, im, SL("handler"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 200);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 255);
	r = zephir_mt_rand(zephir_get_intval(&_4), zephir_get_intval(&_9) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 200);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 255);
	g = zephir_mt_rand(zephir_get_intval(&_10), zephir_get_intval(&_11) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 200);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, 255);
	b = zephir_mt_rand(zephir_get_intval(&_12), zephir_get_intval(&_13) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, 100);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, 150);
	dr = (long) (zephir_safe_div_long_long((r - zephir_mt_rand(zephir_get_intval(&_14), zephir_get_intval(&_15) TSRMLS_CC)), width TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, 100);
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_LONG(&_17, 150);
	dg = (long) (zephir_safe_div_long_long((g - zephir_mt_rand(zephir_get_intval(&_16), zephir_get_intval(&_17) TSRMLS_CC)), width TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_LONG(&_18, 100);
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_LONG(&_19, 150);
	db = (long) (zephir_safe_div_long_long((b - zephir_mt_rand(zephir_get_intval(&_18), zephir_get_intval(&_19) TSRMLS_CC)), width TSRMLS_CC));
	i = 0;
	while (1) {
		if (!(i < width)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_20$$4);
		ZVAL_LONG(&_20$$4, r);
		ZEPHIR_SINIT_NVAR(_21$$4);
		ZVAL_LONG(&_21$$4, g);
		ZEPHIR_SINIT_NVAR(_22$$4);
		ZVAL_LONG(&_22$$4, b);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_23, 55, handler, &_20$$4, &_21$$4, &_22$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_20$$4);
		ZVAL_LONG(&_20$$4, i);
		ZEPHIR_SINIT_NVAR(_21$$4);
		ZVAL_LONG(&_21$$4, 0);
		ZEPHIR_SINIT_NVAR(_22$$4);
		ZVAL_LONG(&_22$$4, i);
		ZEPHIR_SINIT_NVAR(_24$$4);
		ZVAL_LONG(&_24$$4, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_25, 56, handler, &_20$$4, &_21$$4, &_22$$4, &_24$$4, color);
		zephir_check_call_status();
		r -= dr;
		g -= dg;
		b -= db;
		i++;
	}
	ZEPHIR_SINIT_VAR(_26);
	ZVAL_LONG(&_26, 0);
	ZEPHIR_SINIT_VAR(_27);
	ZVAL_LONG(&_27, 0);
	ZEPHIR_SINIT_VAR(_28);
	ZVAL_LONG(&_28, 0);
	ZEPHIR_CALL_FUNCTION(&shadow, "imagecolorallocate", &_23, 55, handler, &_26, &_27, &_28);
	zephir_check_call_status();
	x = padding;
	i = 0;
	while (1) {
		if (!(i < codeLen)) {
			break;
		}
		x2 = (long) (((double) (width - (padding * 2)) - (((double) ((((double) (1.0 - rOverlap)) * (double) (((codeLen - i)))) + rOverlap)) * fontSize)));
		if (x2 > x) {
			ZEPHIR_SINIT_NVAR(_29$$6);
			ZVAL_LONG(&_29$$6, x);
			ZEPHIR_SINIT_NVAR(_30$$6);
			ZVAL_LONG(&_30$$6, x2);
			x = zephir_mt_rand(zephir_get_intval(&_29$$6), zephir_get_intval(&_30$$6) TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_31$$5);
		ZVAL_LONG(&_31$$5, fontSize);
		ZEPHIR_SINIT_NVAR(_32$$5);
		ZVAL_LONG(&_32$$5, height);
		y = zephir_mt_rand(zephir_get_intval(&_31$$5), zephir_get_intval(&_32$$5) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_33$$5);
		ZVAL_LONG(&_33$$5, -15);
		ZEPHIR_SINIT_NVAR(_34$$5);
		ZVAL_LONG(&_34$$5, 15);
		angle = zephir_mt_rand(zephir_get_intval(&_33$$5), zephir_get_intval(&_34$$5) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_35$$5);
		ZVAL_LONG(&_35$$5, i);
		ZEPHIR_SINIT_NVAR(_36$$5);
		ZVAL_LONG(&_36$$5, 1);
		ZEPHIR_SINIT_NVAR(_37$$5);
		ZVAL_STRING(&_37$$5, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_38$$5, "mb_substr", &_39, 57, code, &_35$$5, &_36$$5, &_37$$5);
		zephir_check_call_status();
		zephir_get_strval(_40$$5, _38$$5);
		ZEPHIR_CPY_WRT(ch, _40$$5);
		ZEPHIR_SINIT_NVAR(_35$$5);
		ZVAL_LONG(&_35$$5, 0);
		ZEPHIR_SINIT_NVAR(_36$$5);
		ZVAL_LONG(&_36$$5, 255);
		ZEPHIR_SINIT_NVAR(_37$$5);
		ZVAL_LONG(&_37$$5, 0);
		ZEPHIR_SINIT_NVAR(_41$$5);
		ZVAL_LONG(&_41$$5, 255);
		ZEPHIR_SINIT_NVAR(_42$$5);
		ZVAL_LONG(&_42$$5, 0);
		ZEPHIR_SINIT_NVAR(_43$$5);
		ZVAL_LONG(&_43$$5, 255);
		ZEPHIR_SINIT_NVAR(_44$$5);
		ZVAL_LONG(&_44$$5, zephir_mt_rand(zephir_get_intval(&_35$$5), zephir_get_intval(&_36$$5) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_45$$5);
		ZVAL_LONG(&_45$$5, zephir_mt_rand(zephir_get_intval(&_37$$5), zephir_get_intval(&_41$$5) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_46$$5);
		ZVAL_LONG(&_46$$5, zephir_mt_rand(zephir_get_intval(&_42$$5), zephir_get_intval(&_43$$5) TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_23, 55, handler, &_44$$5, &_45$$5, &_46$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_44$$5);
		ZVAL_LONG(&_44$$5, fontSize);
		ZEPHIR_SINIT_NVAR(_45$$5);
		ZVAL_LONG(&_45$$5, angle);
		ZEPHIR_SINIT_NVAR(_46$$5);
		ZVAL_LONG(&_46$$5, (x + 1));
		ZEPHIR_SINIT_NVAR(_47$$5);
		ZVAL_LONG(&_47$$5, (y + 1));
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", &_48, 58, handler, &_44$$5, &_45$$5, &_46$$5, &_47$$5, shadow, font, ch);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_44$$5);
		ZVAL_LONG(&_44$$5, fontSize);
		ZEPHIR_SINIT_NVAR(_45$$5);
		ZVAL_LONG(&_45$$5, angle);
		ZEPHIR_SINIT_NVAR(_46$$5);
		ZVAL_LONG(&_46$$5, x);
		ZEPHIR_SINIT_NVAR(_47$$5);
		ZVAL_LONG(&_47$$5, y);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", &_48, 58, handler, &_44$$5, &_45$$5, &_46$$5, &_47$$5, color, font, ch);
		zephir_check_call_status();
		x = (x + (((double) (1.0 - rOverlap)) * fontSize));
		i++;
	}
	i = 0;
	while (1) {
		if (!(i < codeLen)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_49$$7);
		ZVAL_LONG(&_49$$7, 0);
		ZEPHIR_SINIT_NVAR(_50$$7);
		ZVAL_LONG(&_50$$7, 255);
		ZEPHIR_SINIT_NVAR(_51$$7);
		ZVAL_LONG(&_51$$7, 0);
		ZEPHIR_SINIT_NVAR(_52$$7);
		ZVAL_LONG(&_52$$7, 255);
		ZEPHIR_SINIT_NVAR(_53$$7);
		ZVAL_LONG(&_53$$7, 0);
		ZEPHIR_SINIT_NVAR(_54$$7);
		ZVAL_LONG(&_54$$7, 255);
		ZEPHIR_SINIT_NVAR(_55$$7);
		ZVAL_LONG(&_55$$7, zephir_mt_rand(zephir_get_intval(&_49$$7), zephir_get_intval(&_50$$7) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_56$$7);
		ZVAL_LONG(&_56$$7, zephir_mt_rand(zephir_get_intval(&_51$$7), zephir_get_intval(&_52$$7) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_57$$7);
		ZVAL_LONG(&_57$$7, zephir_mt_rand(zephir_get_intval(&_53$$7), zephir_get_intval(&_54$$7) TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_23, 55, handler, &_55$$7, &_56$$7, &_57$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_55$$7);
		ZVAL_LONG(&_55$$7, 0);
		ZEPHIR_SINIT_NVAR(_56$$7);
		ZVAL_LONG(&_56$$7, width);
		x = zephir_mt_rand(zephir_get_intval(&_55$$7), zephir_get_intval(&_56$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_57$$7);
		ZVAL_LONG(&_57$$7, 0);
		ZEPHIR_SINIT_NVAR(_58$$7);
		ZVAL_LONG(&_58$$7, height);
		y = zephir_mt_rand(zephir_get_intval(&_57$$7), zephir_get_intval(&_58$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_59$$7);
		ZVAL_LONG(&_59$$7, 0);
		ZEPHIR_SINIT_NVAR(_60$$7);
		ZVAL_LONG(&_60$$7, width);
		x2 = zephir_mt_rand(zephir_get_intval(&_59$$7), zephir_get_intval(&_60$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_61$$7);
		ZVAL_LONG(&_61$$7, 0);
		ZEPHIR_SINIT_NVAR(_62$$7);
		ZVAL_LONG(&_62$$7, height);
		y2 = zephir_mt_rand(zephir_get_intval(&_61$$7), zephir_get_intval(&_62$$7) TSRMLS_CC);
		j = 0;
		while (1) {
			if (!(j <= padding)) {
				break;
			}
			ZEPHIR_SINIT_NVAR(_63$$8);
			ZVAL_LONG(&_63$$8, (x + j));
			ZEPHIR_SINIT_NVAR(_64$$8);
			ZVAL_LONG(&_64$$8, y);
			ZEPHIR_SINIT_NVAR(_65$$8);
			ZVAL_LONG(&_65$$8, (x2 + j));
			ZEPHIR_SINIT_NVAR(_66$$8);
			ZVAL_LONG(&_66$$8, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_25, 56, handler, &_63$$8, &_64$$8, &_65$$8, &_66$$8, color);
			zephir_check_call_status();
			j++;
		}
		ZEPHIR_SINIT_NVAR(_67$$7);
		ZVAL_LONG(&_67$$7, (x + j));
		ZEPHIR_SINIT_NVAR(_68$$7);
		ZVAL_LONG(&_68$$7, y);
		ZEPHIR_SINIT_NVAR(_69$$7);
		ZVAL_LONG(&_69$$7, (x2 + j));
		ZEPHIR_SINIT_NVAR(_70$$7);
		ZVAL_LONG(&_70$$7, y2);
		ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_25, 56, handler, &_67$$7, &_68$$7, &_69$$7, &_70$$7, shadow);
		zephir_check_call_status();
		i++;
	}
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Gd, fromImage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *copyIm = NULL, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("width"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, im, SL("height"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, im, SL("extension"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&copyIm, this_ptr, "fromsize", NULL, 0, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "copy", NULL, 0, copyIm, im, _3, _4);
	zephir_check_call_status();
	RETURN_CCTOR(copyIm);

}

PHP_METHOD(Nc_Image_Gd, fromSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *extension = NULL;
	zval *width_param = NULL, *height_param = NULL, *extension_param = NULL, *imProperties = NULL, *handler = NULL, *background = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, _2, _3, *_4 = NULL, *_5, *_6;
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
	ZEPHIR_CALL_FUNCTION(&handler, "imagecreatetruecolor", NULL, 59, &_0, &_1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image", "nc/image/gd.zep", 142);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 60, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 61, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 255);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 255);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 255);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 127);
	ZEPHIR_CALL_FUNCTION(&background, "imagecolorallocatealpha", NULL, 62, handler, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagecolortransparent", NULL, 63, handler, background);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 64, handler, &_0, &_1, background);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	if (!(!extension) && Z_STRLEN_P(extension)) {
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, fromPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *extension_param = NULL, *imProperties = NULL, *handler = NULL, *_7 = NULL, *_8 = NULL, *_0$$3, *_1$$4, _2$$4, *_3$$4 = NULL, *_5$$8;
	zval *path = NULL, *extension = NULL, *ext = NULL, *_4$$4 = NULL, *_6$$8;

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
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_strtolower(_0$$3, extension);
		zephir_get_strval(ext, _0$$3);
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_SINIT_VAR(_2$$4);
		ZVAL_LONG(&_2$$4, 4);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "pathinfo", NULL, 51, path, &_2$$4);
		zephir_check_call_status();
		zephir_fast_strtolower(_1$$4, _3$$4);
		zephir_get_strval(_4$$4, _1$$4);
		ZEPHIR_CPY_WRT(ext, _4$$4);
	}
	do {
		if (ZEPHIR_IS_STRING(ext, "png")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefrompng", NULL, 65, path);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(ext, "gif")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromgif", NULL, 66, path);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(ext, "jpg") || ZEPHIR_IS_STRING(ext, "jpeg")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromjpeg", NULL, 67, path);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(_5$$8);
		object_init_ex(_5$$8, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(_6$$8);
		ZEPHIR_CONCAT_SV(_6$$8, "Unsupported extension: ", ext);
		ZEPHIR_CALL_METHOD(NULL, _5$$8, "__construct", NULL, 2, _6$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$8, "nc/image/gd.zep", 183 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image", "nc/image/gd.zep", 187);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 60, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 61, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_7, "imagesx", NULL, 68, handler);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("width"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_8, "imagesy", NULL, 69, handler);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("height"), &_8, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, fromString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *extension_param = NULL, *imProperties = NULL, *handler = NULL, *_1 = NULL, *_2 = NULL, *_0$$3;
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
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_strtolower(_0$$3, extension);
		zephir_get_strval(ext, _0$$3);
	} else {
		ZEPHIR_INIT_VAR(ext);
		ZVAL_STRING(ext, "jpg", 1);
	}
	ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromstring", NULL, 70, data);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image", "nc/image/gd.zep", 214);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 60, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 61, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_1, "imagesx", NULL, 68, handler);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("width"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesy", NULL, 69, handler);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("height"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, resize) {

	int ZEPHIR_LAST_CALL_STATUS;
	long width, height, srcW = 0, srcH = 0, w = 0, h = 0;
	zval *im, *width_param = NULL, *height_param = NULL, *destIm = NULL, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5, *_6, *_7, *_8, *_9, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &im, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/gd.zep", 234);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("width"), PH_NOISY_CC);
	srcW = zephir_get_intval(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, im, SL("height"), PH_NOISY_CC);
	srcH = zephir_get_intval(_1);
	w = srcW;
	h = srcH;
	if ((w * height) > (h * width)) {
		w = width;
		h = (long) (zephir_safe_div_double_long(((1.0 * srcH) * w), srcW TSRMLS_CC));
	} else {
		h = height;
		w = (long) (zephir_safe_div_double_long(((1.0 * srcW) * h), srcH TSRMLS_CC));
	}
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, im, SL("extension"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, w);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, h);
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromsize", NULL, 0, _3, _4, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, w);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, h);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, 0);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, srcW);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, srcH);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "copyresampled", NULL, 0, destIm, im, _3, _4, _5, _6, _7, _8, _9, _10);
	zephir_check_call_status();
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Gd, crop) {

	zend_bool _0, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	long x, y, w, h;
	zval *im, *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, *destIm = NULL, *_1, *_3, *_4, *_5 = NULL, *_6 = NULL, *_7, *_8, *_9, *_10, *_11, *_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &im, &x_param, &y_param, &w_param, &h_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);
	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);


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
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, im, SL("width"), PH_NOISY_CC);
	_2 = ZEPHIR_LT_LONG(_1, (x + w));
	if (!(_2)) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, im, SL("height"), PH_NOISY_CC);
		_2 = ZEPHIR_LT_LONG(_3, (y + h));
	}
	if (unlikely(_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cropping out of area", "nc/image/gd.zep", 278);
		return;
	}
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, im, SL("extension"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, w);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, h);
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromsize", NULL, 0, _5, _6, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 0);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, 0);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, w);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, h);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, x);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, y);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, w);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, h);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "copyresampled", NULL, 0, destIm, im, _5, _6, _7, _8, _9, _10, _11, _12);
	zephir_check_call_status();
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Gd, thumbnail) {

	zephir_fcall_cache_entry *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool cropped;
	long width, height, srcW = 0, srcH = 0, w = 0, h = 0, x = 0, y = 0;
	zval *im, *width_param = NULL, *height_param = NULL, *cropped_param = NULL, *destIm = NULL, *_0, *_1, *_2, *_3, *_4, *_5$$5, *_6$$5, *_7$$5, *_8$$5, *_9$$5, *_10$$5, *_11$$5, *_12$$5, *_14$$8, *_15$$8, *_16$$8, *_17$$8, *_18$$8, *_19$$8, *_20$$8, *_21$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &im, &width_param, &height_param, &cropped_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	cropped = zephir_get_boolval(cropped_param);


	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Width must be positive", "nc/image/gd.zep", 293);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("width"), PH_NOISY_CC);
	srcW = zephir_get_intval(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, im, SL("height"), PH_NOISY_CC);
	srcH = zephir_get_intval(_1);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, im, SL("extension"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, width);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, height);
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromsize", NULL, 0, _3, _4, _2);
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
		ZEPHIR_INIT_VAR(_5$$5);
		ZVAL_LONG(_5$$5, 0);
		ZEPHIR_INIT_VAR(_6$$5);
		ZVAL_LONG(_6$$5, 0);
		ZEPHIR_INIT_VAR(_7$$5);
		ZVAL_LONG(_7$$5, width);
		ZEPHIR_INIT_VAR(_8$$5);
		ZVAL_LONG(_8$$5, height);
		ZEPHIR_INIT_VAR(_9$$5);
		ZVAL_LONG(_9$$5, x);
		ZEPHIR_INIT_VAR(_10$$5);
		ZVAL_LONG(_10$$5, y);
		ZEPHIR_INIT_VAR(_11$$5);
		ZVAL_LONG(_11$$5, w);
		ZEPHIR_INIT_VAR(_12$$5);
		ZVAL_LONG(_12$$5, h);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "copyresampled", &_13, 0, destIm, im, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _12$$5);
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
		ZEPHIR_INIT_VAR(_14$$8);
		ZVAL_LONG(_14$$8, x);
		ZEPHIR_INIT_VAR(_15$$8);
		ZVAL_LONG(_15$$8, y);
		ZEPHIR_INIT_VAR(_16$$8);
		ZVAL_LONG(_16$$8, w);
		ZEPHIR_INIT_VAR(_17$$8);
		ZVAL_LONG(_17$$8, h);
		ZEPHIR_INIT_VAR(_18$$8);
		ZVAL_LONG(_18$$8, 0);
		ZEPHIR_INIT_VAR(_19$$8);
		ZVAL_LONG(_19$$8, 0);
		ZEPHIR_INIT_VAR(_20$$8);
		ZVAL_LONG(_20$$8, srcW);
		ZEPHIR_INIT_VAR(_21$$8);
		ZVAL_LONG(_21$$8, srcH);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "copyresampled", &_13, 0, destIm, im, _14$$8, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8);
		zephir_check_call_status();
	}
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Gd, draw) {

	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval *destIm, *srcIm, *x_param = NULL, *y_param = NULL, *resultIm = NULL, *_0$$4 = NULL, *_1$$4 = NULL, *_3$$5 = NULL, *_4$$5 = NULL, *_6$$3 = NULL, *_7$$3 = NULL, *_8$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &destIm, &srcIm, &x_param, &y_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);


	ZEPHIR_CALL_METHOD(&resultIm, this_ptr, "fromimage", NULL, 0, destIm);
	zephir_check_call_status();
	do {
		if (zephir_instance_of_ev(srcIm, nc_image_item_image_ce TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_0$$4);
			ZVAL_LONG(_0$$4, x);
			ZEPHIR_INIT_NVAR(_1$$4);
			ZVAL_LONG(_1$$4, y);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "copy", &_2, 0, resultIm, srcIm, _0$$4, _1$$4);
			zephir_check_call_status();
			break;
		}
		if (zephir_instance_of_ev(srcIm, nc_image_item_text_ce TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_3$$5);
			ZVAL_LONG(_3$$5, x);
			ZEPHIR_INIT_NVAR(_4$$5);
			ZVAL_LONG(_4$$5, y);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "drawtext", &_5, 0, resultIm, srcIm, _3$$5, _4$$5);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_NVAR(_6$$3);
		object_init_ex(_6$$3, nc_image_exception_ce);
		ZEPHIR_INIT_NVAR(_7$$3);
		zephir_get_class(_7$$3, srcIm, 0 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_8$$3);
		ZEPHIR_CONCAT_SV(_8$$3, "Invalid item type: ", _7$$3);
		ZEPHIR_CALL_METHOD(NULL, _6$$3, "__construct", &_9, 2, _8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$3, "nc/image/gd.zep", 349 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while (0);
	RETURN_CCTOR(resultIm);

}

PHP_METHOD(Nc_Image_Gd, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *destPath, *_0, *_1$$3, *_2$$3 = NULL, *_3$$5, *_4$$5 = NULL, *_5$$7, _6$$7, *_7$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &im, &destPath);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("extension"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(_0, "png")) {
			ZEPHIR_OBS_VAR(_1$$3);
			zephir_read_property(&_1$$3, im, SL("handler"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_2$$3, "imagepng", NULL, 71, _1$$3, destPath);
			zephir_check_call_status();
			if (zephir_is_true(_2$$3)) {
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "gif")) {
			ZEPHIR_OBS_VAR(_3$$5);
			zephir_read_property(&_3$$5, im, SL("handler"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_4$$5, "imagegif", NULL, 72, _3$$5, destPath);
			zephir_check_call_status();
			if (zephir_is_true(_4$$5)) {
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "jpg") || ZEPHIR_IS_STRING(_0, "jpeg")) {
			ZEPHIR_OBS_VAR(_5$$7);
			zephir_read_property(&_5$$7, im, SL("handler"), PH_NOISY_CC);
			ZEPHIR_SINIT_VAR(_6$$7);
			ZVAL_LONG(&_6$$7, 100);
			ZEPHIR_CALL_FUNCTION(&_7$$7, "imagejpeg", NULL, 73, _5$$7, destPath, &_6$$7);
			zephir_check_call_status();
			if (zephir_is_true(_7$$7)) {
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
	zval *im, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	if (zephir_instance_of_ev(im, nc_image_item_image_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property(&_0$$3, im, SL("handler"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 74, _0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, drawText) {

	int ZEPHIR_LAST_CALL_STATUS;
	long x, y, alpha = 0;
	zval *dest, *src, *x_param = NULL, *y_param = NULL, *handler = NULL, *color = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5, _6 = zval_used_for_init, *_7, *_8, *_9, _10, _11, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &dest, &src, &x_param, &y_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, src, SL("padding"), PH_NOISY_CC);
	x += zephir_get_numberval(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, src, SL("height"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, src, SL("padding"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_sub_function(_3, _1, _2);
	y += zephir_get_numberval(_3);
	ZEPHIR_OBS_VAR(handler);
	zephir_read_property(&handler, dest, SL("handler"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property(&_1, src, SL("opacity"), PH_NOISY_CC);
	alpha = (long) ((1.0 - zephir_get_numberval(_1)) * 127.0);
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_property(&_2, src, SL("red"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, src, SL("green"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, src, SL("blue"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 62, handler, _2, _4, _5, &_6);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property(&_7, src, SL("fontSize"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property(&_8, src, SL("font"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property(&_9, src, SL("text"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, x);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, y);
	ZEPHIR_CALL_FUNCTION(&_12, "imagettftext", NULL, 58, handler, _7, &_6, &_10, &_11, color, _8, _9);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_12))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagettftext", "nc/image/gd.zep", 405);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, copy) {

	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval *dest, *src, *x_param = NULL, *y_param = NULL, *_0, *_1, *_2, *_3, _4, _5, _6, _7, *_8 = NULL;

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


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, dest, SL("handler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, src, SL("handler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, src, SL("width"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, src, SL("height"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, x);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, y);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopy", NULL, 75, _0, _1, &_4, &_5, &_6, &_7, _2, _3);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_8))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagecopy", "nc/image/gd.zep", 412);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, copyResampled) {

	int ZEPHIR_LAST_CALL_STATUS;
	long x, y, w, h, srcX, srcY, srcW, srcH;
	zval *dest, *src, *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, *srcX_param = NULL, *srcY_param = NULL, *srcW_param = NULL, *srcH_param = NULL, *_0, *_1, _2, _3, _4, _5, _6, _7, _8, _9, *_10 = NULL;

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


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, dest, SL("handler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, src, SL("handler"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, x);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, y);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, srcX);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, srcY);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, w);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, h);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, srcW);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, srcH);
	ZEPHIR_CALL_FUNCTION(&_10, "imagecopyresampled", NULL, 76, _0, _1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_10))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagecopyresampled", "nc/image/gd.zep", 421);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

