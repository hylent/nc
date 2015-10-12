
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
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Image_Imagick) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Imagick, nc, image_imagick, nc_image_imageabstract_ce, nc_image_imagick_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Imagick, __construct) {

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
	ZVAL_STRING(&_0, "imagick", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 14, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Missing extension: imagick", "nc/image/imagick.zep", 8);
		return;
	}
	if (zephir_fast_count_int(defaults TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaults", NULL, 0, defaults);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Imagick, text) {

	long padding2 = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *text_param = NULL, *options_param = NULL, *imProperties = NULL, *imagick = NULL, *imgickDraw = NULL, *m = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6;
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
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(imgickDraw);
	object_init_ex(imgickDraw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, imProperties, SL("font"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 25 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "setfont", NULL, 0, _0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, imProperties, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 26 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "setfontsize", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&m, imagick, "queryfontmetrics", NULL, 0, imgickDraw, text);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, imProperties, SL("padding"), PH_NOISY, "nc/image/imagick.zep", 29 TSRMLS_CC);
	padding2 = (2 * zephir_get_intval(_2));
	zephir_array_update_string(&imProperties, SL("text"), &text, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_3, m, SL("textWidth"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 32 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, (zephir_get_numberval(_3) + padding2));
	zephir_array_update_string(&imProperties, SL("width"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_5, m, SL("textHeight"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 33 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, (zephir_get_numberval(_5) + padding2));
	zephir_array_update_string(&imProperties, SL("height"), &_6, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_text_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, captcha) {

	double rPadding = 0, rOverlap = 0;
	zephir_fcall_cache_entry *_25 = NULL, *_26 = NULL, *_31 = NULL, *_42 = NULL, *_50 = NULL, *_56 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	long width, height, codeLen = 0, fontSize = 0, padding = 0, r = 0, g = 0, b = 0, dr = 0, dg = 0, db = 0, i = 0, j = 0, x = 0, y = 0, x2 = 0, y2 = 0, angle = 0;
	zval *code_param = NULL, *width_param = NULL, *height_param = NULL, *options_param = NULL, *validOptions = NULL, *im = NULL, *imagick = NULL, *imagickDraw = NULL, *shadow = NULL, *_0, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_6 = NULL, *_7, *_8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, *_20$$4 = NULL, _21$$4 = zval_used_for_init, _22$$4 = zval_used_for_init, _23$$4 = zval_used_for_init, *_27$$4 = NULL, *_28$$4 = NULL, *_29$$4 = NULL, *_30$$4 = NULL, _32$$6 = zval_used_for_init, _33$$6 = zval_used_for_init, _34$$5 = zval_used_for_init, _35$$5 = zval_used_for_init, _36$$5 = zval_used_for_init, _37$$5 = zval_used_for_init, _38$$5 = zval_used_for_init, _39$$5 = zval_used_for_init, _40$$5 = zval_used_for_init, *_41$$5 = NULL, _44$$5 = zval_used_for_init, _45$$5 = zval_used_for_init, _46$$5 = zval_used_for_init, *_47$$5 = NULL, *_48$$5 = NULL, *_49$$5 = NULL, _51$$5 = zval_used_for_init, _52$$5 = zval_used_for_init, _53$$5 = zval_used_for_init, *_55$$5 = NULL, _57$$7 = zval_used_for_init, _58$$7 = zval_used_for_init, _59$$7 = zval_used_for_init, _60$$7 = zval_used_for_init, _61$$7 = zval_used_for_init, _62$$7 = zval_used_for_init, *_63$$7 = NULL, _64$$7 = zval_used_for_init, _65$$7 = zval_used_for_init, _66$$7 = zval_used_for_init, _68$$7 = zval_used_for_init, _69$$7 = zval_used_for_init, _70$$7 = zval_used_for_init, _71$$7 = zval_used_for_init, _72$$7 = zval_used_for_init, _73$$7 = zval_used_for_init, _74$$7 = zval_used_for_init, _75$$7 = zval_used_for_init, *_80$$7 = NULL, *_81$$7 = NULL, *_82$$7 = NULL, *_83$$7 = NULL, *_76$$8 = NULL, *_77$$8 = NULL, *_78$$8 = NULL, *_79$$8 = NULL;
	zval *code = NULL, *font = NULL, *ch = NULL, *_1 = NULL, *_24$$4 = NULL, *_43$$5 = NULL, *_54$$5 = NULL, *_67$$7 = NULL;

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
	zephir_array_fetch_string(&_0, validOptions, SL("font"), PH_NOISY, "nc/image/imagick.zep", 47 TSRMLS_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(font, _1);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, validOptions, SL("rPadding"), PH_NOISY, "nc/image/imagick.zep", 48 TSRMLS_CC);
	rPadding = zephir_get_doubleval(_2);
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_string(&_3, validOptions, SL("rOverlap"), PH_NOISY, "nc/image/imagick.zep", 49 TSRMLS_CC);
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
	ZEPHIR_OBS_VAR(imagick);
	zephir_read_property(&imagick, im, SL("imagick"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(imagickDraw);
	object_init_ex(imagickDraw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "__construct", NULL, 0);
	zephir_check_call_status();
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
		ZEPHIR_INIT_NVAR(_20$$4);
		object_init_ex(_20$$4, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_21$$4);
		ZVAL_LONG(&_21$$4, r);
		ZEPHIR_SINIT_NVAR(_22$$4);
		ZVAL_LONG(&_22$$4, g);
		ZEPHIR_SINIT_NVAR(_23$$4);
		ZVAL_LONG(&_23$$4, b);
		ZEPHIR_INIT_LNVAR(_24$$4);
		ZEPHIR_CONCAT_SVSVSVS(_24$$4, "rgb(", &_21$$4, ",", &_22$$4, ",", &_23$$4, ")");
		ZEPHIR_CALL_METHOD(NULL, _20$$4, "__construct", &_25, 0, _24$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_26, 0, _20$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_27$$4);
		ZVAL_LONG(_27$$4, i);
		ZEPHIR_INIT_NVAR(_28$$4);
		ZVAL_LONG(_28$$4, 0);
		ZEPHIR_INIT_NVAR(_29$$4);
		ZVAL_LONG(_29$$4, i);
		ZEPHIR_INIT_NVAR(_30$$4);
		ZVAL_LONG(_30$$4, height);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_31, 0, _27$$4, _28$$4, _29$$4, _30$$4);
		zephir_check_call_status();
		r -= dr;
		g -= dg;
		b -= db;
		i++;
	}
	ZEPHIR_CALL_METHOD(NULL, imagick, "drawimage", NULL, 0, imagickDraw);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(shadow);
	object_init_ex(shadow, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "#000000", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, shadow, "__construct", &_25, 0, _6);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfont", NULL, 0, font);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, fontSize);
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfontsize", NULL, 0, _6);
	zephir_check_call_status();
	x = padding;
	i = 0;
	while (1) {
		if (!(i < codeLen)) {
			break;
		}
		x2 = (long) (((double) (width - (padding * 2)) - (((double) ((((double) (1.0 - rOverlap)) * (double) (((codeLen - i)))) + rOverlap)) * fontSize)));
		if (x2 > x) {
			ZEPHIR_SINIT_NVAR(_32$$6);
			ZVAL_LONG(&_32$$6, x);
			ZEPHIR_SINIT_NVAR(_33$$6);
			ZVAL_LONG(&_33$$6, x2);
			x = zephir_mt_rand(zephir_get_intval(&_32$$6), zephir_get_intval(&_33$$6) TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_34$$5);
		ZVAL_LONG(&_34$$5, fontSize);
		ZEPHIR_SINIT_NVAR(_35$$5);
		ZVAL_LONG(&_35$$5, height);
		y = zephir_mt_rand(zephir_get_intval(&_34$$5), zephir_get_intval(&_35$$5) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_36$$5);
		ZVAL_LONG(&_36$$5, -15);
		ZEPHIR_SINIT_NVAR(_37$$5);
		ZVAL_LONG(&_37$$5, 15);
		angle = zephir_mt_rand(zephir_get_intval(&_36$$5), zephir_get_intval(&_37$$5) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_38$$5);
		ZVAL_LONG(&_38$$5, i);
		ZEPHIR_SINIT_NVAR(_39$$5);
		ZVAL_LONG(&_39$$5, 1);
		ZEPHIR_SINIT_NVAR(_40$$5);
		ZVAL_STRING(&_40$$5, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_41$$5, "mb_substr", &_42, 57, code, &_38$$5, &_39$$5, &_40$$5);
		zephir_check_call_status();
		zephir_get_strval(_43$$5, _41$$5);
		ZEPHIR_CPY_WRT(ch, _43$$5);
		ZEPHIR_SINIT_NVAR(_38$$5);
		ZVAL_LONG(&_38$$5, 0);
		ZEPHIR_SINIT_NVAR(_39$$5);
		ZVAL_LONG(&_39$$5, 255);
		r = zephir_mt_rand(zephir_get_intval(&_38$$5), zephir_get_intval(&_39$$5) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_40$$5);
		ZVAL_LONG(&_40$$5, 0);
		ZEPHIR_SINIT_NVAR(_44$$5);
		ZVAL_LONG(&_44$$5, 255);
		g = zephir_mt_rand(zephir_get_intval(&_40$$5), zephir_get_intval(&_44$$5) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_45$$5);
		ZVAL_LONG(&_45$$5, 0);
		ZEPHIR_SINIT_NVAR(_46$$5);
		ZVAL_LONG(&_46$$5, 255);
		b = zephir_mt_rand(zephir_get_intval(&_45$$5), zephir_get_intval(&_46$$5) TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_26, 0, shadow);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_47$$5);
		ZVAL_LONG(_47$$5, (x + 1));
		ZEPHIR_INIT_NVAR(_48$$5);
		ZVAL_LONG(_48$$5, (y + 1));
		ZEPHIR_INIT_NVAR(_49$$5);
		ZVAL_LONG(_49$$5, angle);
		ZEPHIR_CALL_METHOD(NULL, imagick, "annotateimage", &_50, 0, imagickDraw, _47$$5, _48$$5, _49$$5, ch);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_47$$5);
		object_init_ex(_47$$5, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_51$$5);
		ZVAL_LONG(&_51$$5, r);
		ZEPHIR_SINIT_NVAR(_52$$5);
		ZVAL_LONG(&_52$$5, g);
		ZEPHIR_SINIT_NVAR(_53$$5);
		ZVAL_LONG(&_53$$5, b);
		ZEPHIR_INIT_LNVAR(_54$$5);
		ZEPHIR_CONCAT_SVSVSVS(_54$$5, "rgb(", &_51$$5, ",", &_52$$5, ",", &_53$$5, ")");
		ZEPHIR_CALL_METHOD(NULL, _47$$5, "__construct", &_25, 0, _54$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_26, 0, _47$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_48$$5);
		ZVAL_LONG(_48$$5, x);
		ZEPHIR_INIT_NVAR(_49$$5);
		ZVAL_LONG(_49$$5, y);
		ZEPHIR_INIT_NVAR(_55$$5);
		ZVAL_LONG(_55$$5, angle);
		ZEPHIR_CALL_METHOD(NULL, imagick, "annotateimage", &_56, 0, imagickDraw, _48$$5, _49$$5, _55$$5, ch);
		zephir_check_call_status();
		x = (x + (((double) (1.0 - rOverlap)) * fontSize));
		i++;
	}
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "clear", NULL, 0);
	zephir_check_call_status();
	i = 0;
	while (1) {
		if (!(i < codeLen)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_57$$7);
		ZVAL_LONG(&_57$$7, 0);
		ZEPHIR_SINIT_NVAR(_58$$7);
		ZVAL_LONG(&_58$$7, 255);
		r = zephir_mt_rand(zephir_get_intval(&_57$$7), zephir_get_intval(&_58$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_59$$7);
		ZVAL_LONG(&_59$$7, 0);
		ZEPHIR_SINIT_NVAR(_60$$7);
		ZVAL_LONG(&_60$$7, 255);
		g = zephir_mt_rand(zephir_get_intval(&_59$$7), zephir_get_intval(&_60$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_61$$7);
		ZVAL_LONG(&_61$$7, 0);
		ZEPHIR_SINIT_NVAR(_62$$7);
		ZVAL_LONG(&_62$$7, 255);
		b = zephir_mt_rand(zephir_get_intval(&_61$$7), zephir_get_intval(&_62$$7) TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_63$$7);
		object_init_ex(_63$$7, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_64$$7);
		ZVAL_LONG(&_64$$7, r);
		ZEPHIR_SINIT_NVAR(_65$$7);
		ZVAL_LONG(&_65$$7, g);
		ZEPHIR_SINIT_NVAR(_66$$7);
		ZVAL_LONG(&_66$$7, b);
		ZEPHIR_INIT_LNVAR(_67$$7);
		ZEPHIR_CONCAT_SVSVSVS(_67$$7, "rgb(", &_64$$7, ",", &_65$$7, ",", &_66$$7, ")");
		ZEPHIR_CALL_METHOD(NULL, _63$$7, "__construct", &_25, 0, _67$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_26, 0, _63$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_68$$7);
		ZVAL_LONG(&_68$$7, 0);
		ZEPHIR_SINIT_NVAR(_69$$7);
		ZVAL_LONG(&_69$$7, width);
		x = zephir_mt_rand(zephir_get_intval(&_68$$7), zephir_get_intval(&_69$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_70$$7);
		ZVAL_LONG(&_70$$7, 0);
		ZEPHIR_SINIT_NVAR(_71$$7);
		ZVAL_LONG(&_71$$7, height);
		y = zephir_mt_rand(zephir_get_intval(&_70$$7), zephir_get_intval(&_71$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_72$$7);
		ZVAL_LONG(&_72$$7, 0);
		ZEPHIR_SINIT_NVAR(_73$$7);
		ZVAL_LONG(&_73$$7, width);
		x2 = zephir_mt_rand(zephir_get_intval(&_72$$7), zephir_get_intval(&_73$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_74$$7);
		ZVAL_LONG(&_74$$7, 0);
		ZEPHIR_SINIT_NVAR(_75$$7);
		ZVAL_LONG(&_75$$7, height);
		y2 = zephir_mt_rand(zephir_get_intval(&_74$$7), zephir_get_intval(&_75$$7) TSRMLS_CC);
		j = 0;
		while (1) {
			if (!(j <= padding)) {
				break;
			}
			ZEPHIR_INIT_NVAR(_76$$8);
			ZVAL_LONG(_76$$8, (x + j));
			ZEPHIR_INIT_NVAR(_77$$8);
			ZVAL_LONG(_77$$8, y);
			ZEPHIR_INIT_NVAR(_78$$8);
			ZVAL_LONG(_78$$8, (x2 + j));
			ZEPHIR_INIT_NVAR(_79$$8);
			ZVAL_LONG(_79$$8, y2);
			ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_31, 0, _76$$8, _77$$8, _78$$8, _79$$8);
			zephir_check_call_status();
			j++;
		}
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_26, 0, shadow);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_80$$7);
		ZVAL_LONG(_80$$7, (x + j));
		ZEPHIR_INIT_NVAR(_81$$7);
		ZVAL_LONG(_81$$7, y);
		ZEPHIR_INIT_NVAR(_82$$7);
		ZVAL_LONG(_82$$7, (x2 + j));
		ZEPHIR_INIT_NVAR(_83$$7);
		ZVAL_LONG(_83$$7, y2);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_31, 0, _80$$7, _81$$7, _82$$7, _83$$7);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_CALL_METHOD(NULL, imagick, "drawimage", NULL, 0, imagickDraw);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "clear", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Imagick, fromImage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *imProperties = NULL, *imagick = NULL, *_0, *_1 = NULL, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	ZEPHIR_INIT_VAR(imProperties);
	array_init(imProperties);
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("imagick"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getimageblob", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimageblob", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, im, SL("extension"), PH_NOISY_CC);
	zephir_array_update_string(&imProperties, SL("extension"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, im, SL("width"), PH_NOISY_CC);
	zephir_array_update_string(&imProperties, SL("width"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, im, SL("height"), PH_NOISY_CC);
	zephir_array_update_string(&imProperties, SL("height"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("imagick"), &imagick, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, fromSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *extension = NULL, *ext = NULL;
	zval *width_param = NULL, *height_param = NULL, *extension_param = NULL, *imProperties = NULL, *imagick = NULL, *_1, *_2 = NULL, *_3 = NULL, *_0$$5;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/imagick.zep", 158);
		return;
	}
	if (height < 1) {
		height = width;
	}
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_0$$5);
		zephir_fast_strtolower(_0$$5, extension);
		zephir_get_strval(ext, _0$$5);
	} else {
		ZEPHIR_INIT_VAR(ext);
		ZVAL_STRING(ext, "jpg", 1);
	}
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "rgba(255,255,255,127)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, width);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, height);
	ZEPHIR_CALL_METHOD(NULL, imagick, "newimage", NULL, 0, _2, _3, _1, ext);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, width);
	zephir_array_update_string(&imProperties, SL("width"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, height);
	zephir_array_update_string(&imProperties, SL("height"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("imagick"), &imagick, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, fromPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *extension_param = NULL, *imProperties = NULL, *imagick = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_0$$3, *_1$$4, _2$$4, *_3$$4 = NULL;
	zval *path = NULL, *extension = NULL, *ext = NULL, *_4$$4 = NULL;

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
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "realpath", NULL, 77, path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimage", NULL, 0, _5);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_6, imagick, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("width"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, imagick, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("height"), &_7, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("imagick"), &imagick, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, fromString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *extension_param = NULL, *imProperties = NULL, *imagick = NULL, *_1 = NULL, *_2 = NULL, *_0$$3;
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
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimageblob", NULL, 0, data);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("extension"), &ext, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, imagick, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("width"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, imagick, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&imProperties, SL("height"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&imProperties, SL("imagick"), &imagick, PH_COPY | PH_SEPARATE);
	object_init_ex(return_value, nc_image_item_image_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, this_ptr, imProperties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, resize) {

	int ZEPHIR_LAST_CALL_STATUS;
	long width, height;
	zval *im, *width_param = NULL, *height_param = NULL, *destIm = NULL, *imagick = NULL, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &im, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/imagick.zep", 231);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, 0, im);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(imagick);
	zephir_read_property(&imagick, destIm, SL("imagick"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, width);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, height);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, imagick, "thumbnailimage", NULL, 0, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, imagick, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(destIm, SL("width"), _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, imagick, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(destIm, SL("height"), _4 TSRMLS_CC);
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Imagick, crop) {

	zend_bool _0, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	long x, y, w, h;
	zval *im, *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, *destIm = NULL, *_1, *_3, *_4, *_5 = NULL, *_6 = NULL, *_7, *_8;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Arguments x and y must not be negative", "nc/image/imagick.zep", 254);
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument w must be positive", "nc/image/imagick.zep", 258);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cropping out of area", "nc/image/imagick.zep", 266);
		return;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, 0, im);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, destIm, SL("imagick"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, w);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, h);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, x);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, y);
	ZEPHIR_CALL_METHOD(NULL, _4, "cropimage", NULL, 0, _5, _6, _7, _8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, w);
	zephir_update_property_zval(destIm, SL("width"), _5 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_LONG(_6, h);
	zephir_update_property_zval(destIm, SL("height"), _6 TSRMLS_CC);
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Imagick, thumbnail) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool cropped;
	long width, height;
	zval *im, *width_param = NULL, *height_param = NULL, *cropped_param = NULL, *destIm = NULL, *_8, *_9, *_0$$5, *_1$$5, *_2$$5, *_3$$6, *_4$$6, *_5$$6, *_6$$6, *_7$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &im, &width_param, &height_param, &cropped_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	cropped = zephir_get_boolval(cropped_param);


	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/imagick.zep", 283);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, 0, im);
	zephir_check_call_status();
	if (cropped) {
		ZEPHIR_OBS_VAR(_0$$5);
		zephir_read_property(&_0$$5, destIm, SL("imagick"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_LONG(_1$$5, width);
		ZEPHIR_INIT_VAR(_2$$5);
		ZVAL_LONG(_2$$5, height);
		ZEPHIR_CALL_METHOD(NULL, _0$$5, "cropthumbnailimage", NULL, 0, _1$$5, _2$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(_3$$6);
		zephir_read_property(&_3$$6, destIm, SL("imagick"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4$$6);
		ZVAL_LONG(_4$$6, width);
		ZEPHIR_INIT_VAR(_5$$6);
		ZVAL_LONG(_5$$6, height);
		ZEPHIR_INIT_VAR(_6$$6);
		ZVAL_BOOL(_6$$6, 1);
		ZEPHIR_INIT_VAR(_7$$6);
		ZVAL_BOOL(_7$$6, 1);
		ZEPHIR_CALL_METHOD(NULL, _3$$6, "thumbnailimage", NULL, 0, _4$$6, _5$$6, _6$$6, _7$$6);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, width);
	zephir_update_property_zval(destIm, SL("width"), _8 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, height);
	zephir_update_property_zval(destIm, SL("height"), _9 TSRMLS_CC);
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Imagick, draw) {

	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval *destIm, *srcIm, *x_param = NULL, *y_param = NULL, *resultIm = NULL, *imagickDraw = NULL, *_16, *_17, *_18, *_0$$3, *_1$$3, *_2$$3, *_3$$3, *_4$$3, *_5$$4, *_6$$4, *_7$$4, *_8$$4, *_9$$4, *_10$$4 = NULL, *_11$$4 = NULL, *_12$$4, *_13$$4, *_14$$4, *_15$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &destIm, &srcIm, &x_param, &y_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);


	ZEPHIR_CALL_METHOD(&resultIm, this_ptr, "fromimage", NULL, 0, destIm);
	zephir_check_call_status();
	if (zephir_instance_of_ev(srcIm, nc_image_item_image_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property(&_0$$3, resultIm, SL("imagick"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property(&_1$$3, srcIm, SL("imagick"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 40);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, x);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, y);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "compositeimage", NULL, 0, _1$$3, _2$$3, _3$$3, _4$$3);
		zephir_check_call_status();
		RETURN_CCTOR(resultIm);
	}
	if (zephir_instance_of_ev(srcIm, nc_image_item_text_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(imagickDraw);
		object_init_ex(imagickDraw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "__construct", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_5$$4);
		zephir_read_property(&_5$$4, srcIm, SL("font"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfont", NULL, 0, _5$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_6$$4);
		zephir_read_property(&_6$$4, srcIm, SL("fontSize"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfontsize", NULL, 0, _6$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_7$$4);
		zephir_read_property(&_7$$4, srcIm, SL("color"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", NULL, 0, _7$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_8$$4);
		zephir_read_property(&_8$$4, srcIm, SL("opacity"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillopacity", NULL, 0, _8$$4);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(_9$$4);
		zephir_read_property(&_9$$4, srcIm, SL("padding"), PH_NOISY_CC);
		x += zephir_get_numberval(_9$$4);
		ZEPHIR_OBS_VAR(_10$$4);
		zephir_read_property(&_10$$4, srcIm, SL("height"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_11$$4);
		zephir_read_property(&_11$$4, srcIm, SL("padding"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_12$$4);
		zephir_sub_function(_12$$4, _10$$4, _11$$4);
		y += zephir_get_numberval(_12$$4);
		ZEPHIR_OBS_NVAR(_10$$4);
		zephir_read_property(&_10$$4, resultIm, SL("imagick"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(_11$$4);
		zephir_read_property(&_11$$4, srcIm, SL("text"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_13$$4);
		ZVAL_LONG(_13$$4, x);
		ZEPHIR_INIT_VAR(_14$$4);
		ZVAL_LONG(_14$$4, y);
		ZEPHIR_INIT_VAR(_15$$4);
		ZVAL_LONG(_15$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, _10$$4, "annotateimage", NULL, 0, imagickDraw, _13$$4, _14$$4, _15$$4, _11$$4);
		zephir_check_call_status();
		RETURN_CCTOR(resultIm);
	}
	ZEPHIR_INIT_VAR(_16);
	object_init_ex(_16, nc_image_exception_ce);
	ZEPHIR_INIT_VAR(_17);
	zephir_get_class(_17, srcIm, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CONCAT_SV(_18, "Invalid item type: ", _17);
	ZEPHIR_CALL_METHOD(NULL, _16, "__construct", NULL, 2, _18);
	zephir_check_call_status();
	zephir_throw_exception_debug(_16, "nc/image/imagick.zep", 327 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Image_Imagick, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *destPath, *_0$$3, *_1$$3 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &im, &destPath);



	if (Z_TYPE_P(destPath) == IS_NULL) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property(&_0$$3, im, SL("imagick"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_1$$3, _0$$3, "getimageblob", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(_1$$3, 0);
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, im, SL("imagick"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "writeimage", NULL, 0, destPath);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Imagick, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	if (zephir_instance_of_ev(im, nc_image_item_image_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property(&_0$$3, im, SL("imagick"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "clear", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

