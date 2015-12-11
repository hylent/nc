
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/math.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Image_Imagick) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Imagick, nc, image_imagick, nc_image_imagebackendabstract_ce, nc_image_imagick_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Imagick, __construct) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *defaultOptions_param = NULL, _0, *_1 = NULL;
	zval *defaultOptions = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultOptions_param);

	if (!defaultOptions_param) {
		ZEPHIR_INIT_VAR(defaultOptions);
		array_init(defaultOptions);
	} else {
		zephir_get_arrval(defaultOptions, defaultOptions_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "imagick", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 12, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Missing extension: imagick", "nc/image/imagick.zep", 8);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, nc_image_imagick_ce, this_ptr, "__construct", &_2, 48, defaultOptions);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Imagick, text) {

	long padding2 = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *text_param = NULL, *options_param = NULL, *im = NULL, *imagick = NULL, *imgickDraw = NULL, *m = NULL, *_0, *_1, *_2, *_3, *_4, *_5;
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


	ZEPHIR_CALL_METHOD(&im, this_ptr, "newtext", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("text"), text TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, im, "setoptions", NULL, 0, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(imgickDraw);
	object_init_ex(imgickDraw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("font"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "setfont", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, im, SL("fontSize"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, imgickDraw, "setfontsize", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&m, imagick, "queryfontmetrics", NULL, 0, imgickDraw, text);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, im, SL("padding"), PH_NOISY_CC);
	padding2 = (zephir_get_intval(_2) * 2);
	zephir_array_fetch_string(&_3, m, SL("textWidth"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 30 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, (zephir_get_numberval(_3) + padding2));
	zephir_update_property_zval(im, SL("width"), _4 TSRMLS_CC);
	zephir_array_fetch_string(&_5, m, SL("textHeight"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 31 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, (zephir_get_numberval(_5) + padding2));
	zephir_update_property_zval(im, SL("height"), _4 TSRMLS_CC);
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Imagick, fromImage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *copyIm = NULL, *imagick = NULL, *_0, *_1 = NULL, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getimageblob", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimageblob", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&copyIm, this_ptr, "newimage", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(copyIm, SL("handler"), imagick TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, im, SL("width"), PH_NOISY_CC);
	zephir_update_property_zval(copyIm, SL("width"), _2 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, im, SL("height"), PH_NOISY_CC);
	zephir_update_property_zval(copyIm, SL("height"), _3 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, im, SL("extension"), PH_NOISY_CC);
	zephir_update_property_zval(copyIm, SL("extension"), _4 TSRMLS_CC);
	RETURN_CCTOR(copyIm);

}

PHP_METHOD(Nc_Image_Imagick, fromSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *extension = NULL;
	zval *width_param = NULL, *height_param = NULL, *extension_param = NULL, *im = NULL, *imagick = NULL, *_0, *_3, *_4 = NULL, *_5, *_6, *_1$$5 = NULL, *_2$$5;
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


	if (width < 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/imagick.zep", 57);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_CALL_METHOD(&im, this_ptr, "newimage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, width);
	zephir_update_property_zval(im, SL("width"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, height);
	zephir_update_property_zval(im, SL("height"), _0 TSRMLS_CC);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_2$$5);
		zephir_fast_strtolower(_2$$5, extension);
		zephir_update_property_zval(im, SL("extension"), _2$$5 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "rgba(255,255,255,127)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, im, SL("extension"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, width);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, height);
	ZEPHIR_CALL_METHOD(NULL, imagick, "newimage", NULL, 0, _4, _6, _3, _5);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("handler"), imagick TSRMLS_CC);
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Imagick, fromPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *extension_param = NULL, *im = NULL, *imagick = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3$$3 = NULL, *_4$$3, *_5$$4, _6$$4, *_7$$4 = NULL;
	zval *path = NULL, *extension = NULL, *_8$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &extension_param);

	zephir_get_strval(path, path_param);
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}


	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "realpath", NULL, 75, path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimage", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&im, this_ptr, "newimage", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("handler"), imagick TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, imagick, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("width"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, imagick, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("height"), _2 TSRMLS_CC);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_fast_strtolower(_4$$3, extension);
		zephir_update_property_zval(im, SL("extension"), _4$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_LONG(&_6$$4, 4);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "pathinfo", NULL, 50, path, &_6$$4);
		zephir_check_call_status();
		zephir_fast_strtolower(_5$$4, _7$$4);
		zephir_get_strval(_8$$4, _5$$4);
		zephir_update_property_zval(im, SL("extension"), _8$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Imagick, fromString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *extension_param = NULL, *im = NULL, *imagick = NULL, *_0 = NULL, *_1 = NULL, *_2$$3 = NULL, *_3$$3;
	zval *data = NULL, *extension = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &extension_param);

	zephir_get_strval(data, data_param);
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}


	ZEPHIR_INIT_VAR(imagick);
	object_init_ex(imagick, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagick, "readimageblob", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&im, this_ptr, "newimage", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("handler"), imagick TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, imagick, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("width"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, imagick, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("height"), _1 TSRMLS_CC);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_fast_strtolower(_3$$3, extension);
		zephir_update_property_zval(im, SL("extension"), _3$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Imagick, captcha) {

	double rPadding = 0, rOverlap = 0;
	zephir_fcall_cache_entry *_27 = NULL, *_32 = NULL, *_43 = NULL, *_51 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	long width, height, textLen = 0, fontSize = 0, padding = 0, r = 0, g = 0, b = 0, dr = 0, dg = 0, db = 0, i = 0, j = 0, x = 0, y = 0, x2 = 0, y2 = 0, angle = 0;
	zval *text_param = NULL, *width_param = NULL, *height_param = NULL, *options_param = NULL, *im = NULL, *imagick = NULL, *imagickDraw = NULL, *shadow = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5, *_7, *_8, _9 = zval_used_for_init, *_10 = NULL, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, *_22$$6 = NULL, _23$$6 = zval_used_for_init, _24$$6 = zval_used_for_init, _25$$6 = zval_used_for_init, *_28$$6 = NULL, *_29$$6 = NULL, *_30$$6 = NULL, *_31$$6 = NULL, _33$$8 = zval_used_for_init, _34$$8 = zval_used_for_init, _35$$7 = zval_used_for_init, _36$$7 = zval_used_for_init, _37$$7 = zval_used_for_init, _38$$7 = zval_used_for_init, _39$$7 = zval_used_for_init, _40$$7 = zval_used_for_init, _41$$7 = zval_used_for_init, *_42$$7 = NULL, _45$$7 = zval_used_for_init, _46$$7 = zval_used_for_init, _47$$7 = zval_used_for_init, *_48$$7 = NULL, *_49$$7 = NULL, *_50$$7 = NULL, _52$$7 = zval_used_for_init, _53$$7 = zval_used_for_init, _54$$7 = zval_used_for_init, *_56$$7 = NULL, _57$$9 = zval_used_for_init, _58$$9 = zval_used_for_init, _59$$9 = zval_used_for_init, _60$$9 = zval_used_for_init, _61$$9 = zval_used_for_init, _62$$9 = zval_used_for_init, *_63$$9 = NULL, _64$$9 = zval_used_for_init, _65$$9 = zval_used_for_init, _66$$9 = zval_used_for_init, _68$$9 = zval_used_for_init, _69$$9 = zval_used_for_init, _70$$9 = zval_used_for_init, _71$$9 = zval_used_for_init, _72$$9 = zval_used_for_init, _73$$9 = zval_used_for_init, _74$$9 = zval_used_for_init, _75$$9 = zval_used_for_init, *_80$$9 = NULL, *_81$$9 = NULL, *_82$$9 = NULL, *_83$$9 = NULL, *_76$$10 = NULL, *_77$$10 = NULL, *_78$$10 = NULL, *_79$$10 = NULL;
	zval *text = NULL, *font = NULL, *ch = NULL, *_6 = NULL, *_26$$6 = NULL, *_44$$7 = NULL, *_55$$7 = NULL, *_67$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &text_param, &width_param, &height_param, &options_param);

	zephir_get_strval(text, text_param);
	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	if (width < 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/imagick.zep", 124);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_CALL_METHOD(&im, this_ptr, "newcaptcha", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, width);
	zephir_update_property_zval(im, SL("width"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, height);
	zephir_update_property_zval(im, SL("height"), _0 TSRMLS_CC);
	zephir_update_property_zval(im, SL("text"), text TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, im, "setoptions", NULL, 0, options);
	zephir_check_call_status();
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
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, im, SL("extension"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, width);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, height);
	ZEPHIR_CALL_METHOD(NULL, imagick, "newimage", NULL, 0, _2, _4, _1, _3);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("handler"), imagick TSRMLS_CC);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, im, SL("font"), PH_NOISY_CC);
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(font, _6);
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property(&_7, im, SL("rPadding"), PH_NOISY_CC);
	rPadding = zephir_get_doubleval(_7);
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property(&_8, im, SL("rOverlap"), PH_NOISY_CC);
	rOverlap = zephir_get_doubleval(_8);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "utf-8", 0);
	ZEPHIR_CALL_FUNCTION(&_10, "mb_strlen", NULL, 59, text, &_9);
	zephir_check_call_status();
	textLen = zephir_get_intval(_10);
	fontSize = (long) (zephir_safe_div_double_long((1.0 * width), (((rPadding * (double) 2) + textLen)) TSRMLS_CC));
	if (fontSize > height) {
		fontSize = height;
	}
	padding = (long) (((double) fontSize * rPadding));
	ZEPHIR_INIT_VAR(imagickDraw);
	object_init_ex(imagickDraw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_9);
	ZVAL_LONG(&_9, 200);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 255);
	r = zephir_mt_rand(zephir_get_intval(&_9), zephir_get_intval(&_11) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 200);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, 255);
	g = zephir_mt_rand(zephir_get_intval(&_12), zephir_get_intval(&_13) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, 200);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, 255);
	b = zephir_mt_rand(zephir_get_intval(&_14), zephir_get_intval(&_15) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, 100);
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_LONG(&_17, 150);
	dr = (long) (zephir_safe_div_long_long((r - zephir_mt_rand(zephir_get_intval(&_16), zephir_get_intval(&_17) TSRMLS_CC)), width TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_LONG(&_18, 100);
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_LONG(&_19, 150);
	dg = (long) (zephir_safe_div_long_long((g - zephir_mt_rand(zephir_get_intval(&_18), zephir_get_intval(&_19) TSRMLS_CC)), width TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_20);
	ZVAL_LONG(&_20, 100);
	ZEPHIR_SINIT_VAR(_21);
	ZVAL_LONG(&_21, 150);
	db = (long) (zephir_safe_div_long_long((b - zephir_mt_rand(zephir_get_intval(&_20), zephir_get_intval(&_21) TSRMLS_CC)), width TSRMLS_CC));
	i = 0;
	while (1) {
		if (!(i < width)) {
			break;
		}
		ZEPHIR_INIT_NVAR(_22$$6);
		object_init_ex(_22$$6, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_23$$6);
		ZVAL_LONG(&_23$$6, r);
		ZEPHIR_SINIT_NVAR(_24$$6);
		ZVAL_LONG(&_24$$6, g);
		ZEPHIR_SINIT_NVAR(_25$$6);
		ZVAL_LONG(&_25$$6, b);
		ZEPHIR_INIT_LNVAR(_26$$6);
		ZEPHIR_CONCAT_SVSVSVS(_26$$6, "rgb(", &_23$$6, ",", &_24$$6, ",", &_25$$6, ")");
		ZEPHIR_CALL_METHOD(NULL, _22$$6, "__construct", NULL, 0, _26$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_27, 0, _22$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_28$$6);
		ZVAL_LONG(_28$$6, i);
		ZEPHIR_INIT_NVAR(_29$$6);
		ZVAL_LONG(_29$$6, 0);
		ZEPHIR_INIT_NVAR(_30$$6);
		ZVAL_LONG(_30$$6, i);
		ZEPHIR_INIT_NVAR(_31$$6);
		ZVAL_LONG(_31$$6, height);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_32, 0, _28$$6, _29$$6, _30$$6, _31$$6);
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
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "#000000", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, shadow, "__construct", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfont", NULL, 0, font);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, fontSize);
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfontsize", NULL, 0, _2);
	zephir_check_call_status();
	x = padding;
	i = 0;
	while (1) {
		if (!(i < textLen)) {
			break;
		}
		x2 = (long) (((double) (width - (padding * 2)) - (((double) ((((double) (1.0 - rOverlap)) * (double) (((textLen - i)))) + rOverlap)) * fontSize)));
		if (x2 > x) {
			ZEPHIR_SINIT_NVAR(_33$$8);
			ZVAL_LONG(&_33$$8, x);
			ZEPHIR_SINIT_NVAR(_34$$8);
			ZVAL_LONG(&_34$$8, x2);
			x = zephir_mt_rand(zephir_get_intval(&_33$$8), zephir_get_intval(&_34$$8) TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_35$$7);
		ZVAL_LONG(&_35$$7, fontSize);
		ZEPHIR_SINIT_NVAR(_36$$7);
		ZVAL_LONG(&_36$$7, height);
		y = zephir_mt_rand(zephir_get_intval(&_35$$7), zephir_get_intval(&_36$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_37$$7);
		ZVAL_LONG(&_37$$7, -15);
		ZEPHIR_SINIT_NVAR(_38$$7);
		ZVAL_LONG(&_38$$7, 15);
		angle = zephir_mt_rand(zephir_get_intval(&_37$$7), zephir_get_intval(&_38$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_39$$7);
		ZVAL_LONG(&_39$$7, i);
		ZEPHIR_SINIT_NVAR(_40$$7);
		ZVAL_LONG(&_40$$7, 1);
		ZEPHIR_SINIT_NVAR(_41$$7);
		ZVAL_STRING(&_41$$7, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_42$$7, "mb_substr", &_43, 62, text, &_39$$7, &_40$$7, &_41$$7);
		zephir_check_call_status();
		zephir_get_strval(_44$$7, _42$$7);
		ZEPHIR_CPY_WRT(ch, _44$$7);
		ZEPHIR_SINIT_NVAR(_39$$7);
		ZVAL_LONG(&_39$$7, 0);
		ZEPHIR_SINIT_NVAR(_40$$7);
		ZVAL_LONG(&_40$$7, 255);
		r = zephir_mt_rand(zephir_get_intval(&_39$$7), zephir_get_intval(&_40$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_41$$7);
		ZVAL_LONG(&_41$$7, 0);
		ZEPHIR_SINIT_NVAR(_45$$7);
		ZVAL_LONG(&_45$$7, 255);
		g = zephir_mt_rand(zephir_get_intval(&_41$$7), zephir_get_intval(&_45$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_46$$7);
		ZVAL_LONG(&_46$$7, 0);
		ZEPHIR_SINIT_NVAR(_47$$7);
		ZVAL_LONG(&_47$$7, 255);
		b = zephir_mt_rand(zephir_get_intval(&_46$$7), zephir_get_intval(&_47$$7) TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_27, 0, shadow);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_48$$7);
		ZVAL_LONG(_48$$7, (x + 1));
		ZEPHIR_INIT_NVAR(_49$$7);
		ZVAL_LONG(_49$$7, (y + 1));
		ZEPHIR_INIT_NVAR(_50$$7);
		ZVAL_LONG(_50$$7, angle);
		ZEPHIR_CALL_METHOD(NULL, imagick, "annotateimage", &_51, 0, imagickDraw, _48$$7, _49$$7, _50$$7, ch);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_48$$7);
		object_init_ex(_48$$7, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_52$$7);
		ZVAL_LONG(&_52$$7, r);
		ZEPHIR_SINIT_NVAR(_53$$7);
		ZVAL_LONG(&_53$$7, g);
		ZEPHIR_SINIT_NVAR(_54$$7);
		ZVAL_LONG(&_54$$7, b);
		ZEPHIR_INIT_LNVAR(_55$$7);
		ZEPHIR_CONCAT_SVSVSVS(_55$$7, "rgb(", &_52$$7, ",", &_53$$7, ",", &_54$$7, ")");
		ZEPHIR_CALL_METHOD(NULL, _48$$7, "__construct", NULL, 0, _55$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_27, 0, _48$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_49$$7);
		ZVAL_LONG(_49$$7, x);
		ZEPHIR_INIT_NVAR(_50$$7);
		ZVAL_LONG(_50$$7, y);
		ZEPHIR_INIT_NVAR(_56$$7);
		ZVAL_LONG(_56$$7, angle);
		ZEPHIR_CALL_METHOD(NULL, imagick, "annotateimage", &_51, 0, imagickDraw, _49$$7, _50$$7, _56$$7, ch);
		zephir_check_call_status();
		x = (x + (((double) (1.0 - rOverlap)) * fontSize));
		i++;
	}
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "clear", NULL, 0);
	zephir_check_call_status();
	i = 0;
	while (1) {
		if (!(i < textLen)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_57$$9);
		ZVAL_LONG(&_57$$9, 0);
		ZEPHIR_SINIT_NVAR(_58$$9);
		ZVAL_LONG(&_58$$9, 255);
		r = zephir_mt_rand(zephir_get_intval(&_57$$9), zephir_get_intval(&_58$$9) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_59$$9);
		ZVAL_LONG(&_59$$9, 0);
		ZEPHIR_SINIT_NVAR(_60$$9);
		ZVAL_LONG(&_60$$9, 255);
		g = zephir_mt_rand(zephir_get_intval(&_59$$9), zephir_get_intval(&_60$$9) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_61$$9);
		ZVAL_LONG(&_61$$9, 0);
		ZEPHIR_SINIT_NVAR(_62$$9);
		ZVAL_LONG(&_62$$9, 255);
		b = zephir_mt_rand(zephir_get_intval(&_61$$9), zephir_get_intval(&_62$$9) TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_63$$9);
		object_init_ex(_63$$9, zephir_get_internal_ce(SS("imagickpixel") TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_64$$9);
		ZVAL_LONG(&_64$$9, r);
		ZEPHIR_SINIT_NVAR(_65$$9);
		ZVAL_LONG(&_65$$9, g);
		ZEPHIR_SINIT_NVAR(_66$$9);
		ZVAL_LONG(&_66$$9, b);
		ZEPHIR_INIT_LNVAR(_67$$9);
		ZEPHIR_CONCAT_SVSVSVS(_67$$9, "rgb(", &_64$$9, ",", &_65$$9, ",", &_66$$9, ")");
		ZEPHIR_CALL_METHOD(NULL, _63$$9, "__construct", NULL, 0, _67$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_27, 0, _63$$9);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_68$$9);
		ZVAL_LONG(&_68$$9, 0);
		ZEPHIR_SINIT_NVAR(_69$$9);
		ZVAL_LONG(&_69$$9, width);
		x = zephir_mt_rand(zephir_get_intval(&_68$$9), zephir_get_intval(&_69$$9) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_70$$9);
		ZVAL_LONG(&_70$$9, 0);
		ZEPHIR_SINIT_NVAR(_71$$9);
		ZVAL_LONG(&_71$$9, height);
		y = zephir_mt_rand(zephir_get_intval(&_70$$9), zephir_get_intval(&_71$$9) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_72$$9);
		ZVAL_LONG(&_72$$9, 0);
		ZEPHIR_SINIT_NVAR(_73$$9);
		ZVAL_LONG(&_73$$9, width);
		x2 = zephir_mt_rand(zephir_get_intval(&_72$$9), zephir_get_intval(&_73$$9) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_74$$9);
		ZVAL_LONG(&_74$$9, 0);
		ZEPHIR_SINIT_NVAR(_75$$9);
		ZVAL_LONG(&_75$$9, height);
		y2 = zephir_mt_rand(zephir_get_intval(&_74$$9), zephir_get_intval(&_75$$9) TSRMLS_CC);
		j = 0;
		while (1) {
			if (!(j <= padding)) {
				break;
			}
			ZEPHIR_INIT_NVAR(_76$$10);
			ZVAL_LONG(_76$$10, (x + j));
			ZEPHIR_INIT_NVAR(_77$$10);
			ZVAL_LONG(_77$$10, y);
			ZEPHIR_INIT_NVAR(_78$$10);
			ZVAL_LONG(_78$$10, (x2 + j));
			ZEPHIR_INIT_NVAR(_79$$10);
			ZVAL_LONG(_79$$10, y2);
			ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_32, 0, _76$$10, _77$$10, _78$$10, _79$$10);
			zephir_check_call_status();
			j++;
		}
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "setfillcolor", &_27, 0, shadow);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_80$$9);
		ZVAL_LONG(_80$$9, (x + j));
		ZEPHIR_INIT_NVAR(_81$$9);
		ZVAL_LONG(_81$$9, y);
		ZEPHIR_INIT_NVAR(_82$$9);
		ZVAL_LONG(_82$$9, (x2 + j));
		ZEPHIR_INIT_NVAR(_83$$9);
		ZVAL_LONG(_83$$9, y2);
		ZEPHIR_CALL_METHOD(NULL, imagickDraw, "line", &_32, 0, _80$$9, _81$$9, _82$$9, _83$$9);
		zephir_check_call_status();
		i++;
	}
	ZEPHIR_CALL_METHOD(NULL, imagick, "drawimage", NULL, 0, imagickDraw);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, imagickDraw, "clear", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(im);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/imagick.zep", 233);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, 0, im);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(imagick);
	zephir_read_property(&imagick, destIm, SL("handler"), PH_NOISY_CC);
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
	zval *im, *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, *destIm = NULL, *_1, *_3, *_4, *_5, *_6, *_7, *_8, *_9;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Arguments x and y must not be negative", "nc/image/imagick.zep", 256);
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument w must be positive", "nc/image/imagick.zep", 260);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cropping out of area", "nc/image/imagick.zep", 268);
		return;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, 0, im);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, destIm, SL("handler"), PH_NOISY_CC);
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
	ZEPHIR_INIT_ZVAL_NREF(_9);
	ZVAL_LONG(_9, w);
	zephir_update_property_zval(destIm, SL("width"), _9 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_9);
	ZVAL_LONG(_9, h);
	zephir_update_property_zval(destIm, SL("height"), _9 TSRMLS_CC);
	RETURN_CCTOR(destIm);

}

PHP_METHOD(Nc_Image_Imagick, thumbnail) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool cropped;
	long width, height;
	zval *im, *width_param = NULL, *height_param = NULL, *cropped_param = NULL, *destIm = NULL, *_8, *_0$$5, *_1$$5, *_2$$5, *_3$$6, *_4$$6, *_5$$6, *_6$$6, *_7$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &im, &width_param, &height_param, &cropped_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	cropped = zephir_get_boolval(cropped_param);


	if (unlikely(width < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/imagick.zep", 285);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_CALL_METHOD(&destIm, this_ptr, "fromimage", NULL, 0, im);
	zephir_check_call_status();
	if (cropped) {
		ZEPHIR_OBS_VAR(_0$$5);
		zephir_read_property(&_0$$5, destIm, SL("handler"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_LONG(_1$$5, width);
		ZEPHIR_INIT_VAR(_2$$5);
		ZVAL_LONG(_2$$5, height);
		ZEPHIR_CALL_METHOD(NULL, _0$$5, "cropthumbnailimage", NULL, 0, _1$$5, _2$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(_3$$6);
		zephir_read_property(&_3$$6, destIm, SL("handler"), PH_NOISY_CC);
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
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, width);
	zephir_update_property_zval(destIm, SL("width"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, height);
	zephir_update_property_zval(destIm, SL("height"), _8 TSRMLS_CC);
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
	if (zephir_instance_of_ev(srcIm, nc_image_image_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property(&_0$$3, resultIm, SL("handler"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property(&_1$$3, srcIm, SL("handler"), PH_NOISY_CC);
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
	if (zephir_instance_of_ev(srcIm, nc_image_text_ce TSRMLS_CC)) {
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
		zephir_read_property(&_10$$4, resultIm, SL("handler"), PH_NOISY_CC);
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
	zephir_throw_exception_debug(_16, "nc/image/imagick.zep", 329 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Image_Imagick, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *destPath = NULL;
	zval *im, *destPath_param = NULL, *_0$$3, *_1$$4, *_2$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &im, &destPath_param);

	zephir_get_strval(destPath, destPath_param);


	if (!(!destPath) && Z_STRLEN_P(destPath)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property(&_0$$3, im, SL("handler"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "writeimage", NULL, 0, destPath);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_VAR(_1$$4);
		zephir_read_property(&_1$$4, im, SL("handler"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2$$4, _1$$4, "getimageblob", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(_2$$4, 0);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Imagick, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	if (zephir_instance_of_ev(im, nc_image_image_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property(&_0$$3, im, SL("handler"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "clear", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

