
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
#include "kernel/concat.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Nc_Image_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Gd, nc, image_gd, nc_image_imagebackendabstract_ce, nc_image_gd_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Gd, __construct) {

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
	ZVAL_STRING(&_0, "gd", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 12, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Missing extension: gd", "nc/image/gd.zep", 8);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, nc_image_gd_ce, this_ptr, "__construct", &_2, 48, defaultOptions);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, text) {

	long padding2 = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *text_param = NULL, *options_param = NULL, *im = NULL, *box = NULL, *_0, *_1, _2 = zval_used_for_init, *_3, *_4, *_5, *_6, _7;
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
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("fontSize"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, im, SL("font"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&box, "imagettfbbox", NULL, 49, _0, &_2, _1, text);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(box))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagettfbbox", "nc/image/gd.zep", 25);
		return;
	}
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, im, SL("padding"), PH_NOISY_CC);
	padding2 = (zephir_get_intval(_3) * 2);
	zephir_array_fetch_long(&_4, box, 2, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 29 TSRMLS_CC);
	zephir_array_fetch_long(&_5, box, 6, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 29 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	zephir_sub_function(&_2, _4, _5);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, (zephir_get_numberval(&_2) + padding2));
	zephir_update_property_zval(im, SL("width"), _6 TSRMLS_CC);
	zephir_array_fetch_long(&_4, box, 3, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 30 TSRMLS_CC);
	zephir_array_fetch_long(&_5, box, 7, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 30 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_7);
	zephir_sub_function(&_7, _4, _5);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, (zephir_get_numberval(&_7) + padding2));
	zephir_update_property_zval(im, SL("height"), _6 TSRMLS_CC);
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
	zval *width_param = NULL, *height_param = NULL, *extension_param = NULL, *im = NULL, *gdIm = NULL, *_0, *_1, *_2, *_3, *_4, *_5$$3 = NULL, *_6$$3;
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


	ZEPHIR_CALL_METHOD(&im, this_ptr, "newimage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, width);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, height);
	ZEPHIR_CALL_METHOD(&gdIm, this_ptr, "creategdimagefromsize", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, gdIm, SL("handler"), PH_NOISY_CC);
	zephir_update_property_zval(im, SL("handler"), _2 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, gdIm, SL("width"), PH_NOISY_CC);
	zephir_update_property_zval(im, SL("width"), _3 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, gdIm, SL("height"), PH_NOISY_CC);
	zephir_update_property_zval(im, SL("height"), _4 TSRMLS_CC);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_fast_strtolower(_6$$3, extension);
		zephir_update_property_zval(im, SL("extension"), _6$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Gd, fromPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *extension_param = NULL, *im = NULL, *handler = NULL, *_7 = NULL, *_8 = NULL, *_0$$3, *_1$$4, _2$$4, *_3$$4 = NULL, *_5$$8;
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


	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_strtolower(_0$$3, extension);
		zephir_get_strval(ext, _0$$3);
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_SINIT_VAR(_2$$4);
		ZVAL_LONG(&_2$$4, 4);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "pathinfo", NULL, 50, path, &_2$$4);
		zephir_check_call_status();
		zephir_fast_strtolower(_1$$4, _3$$4);
		zephir_get_strval(_4$$4, _1$$4);
		ZEPHIR_CPY_WRT(ext, _4$$4);
	}
	do {
		if (ZEPHIR_IS_STRING(ext, "png")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefrompng", NULL, 51, path);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(ext, "gif")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromgif", NULL, 52, path);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(ext, "jpg") || ZEPHIR_IS_STRING(ext, "jpeg")) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromjpeg", NULL, 53, path);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(_5$$8);
		object_init_ex(_5$$8, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(_6$$8);
		ZEPHIR_CONCAT_SV(_6$$8, "Unsupported extension: ", ext);
		ZEPHIR_CALL_METHOD(NULL, _5$$8, "__construct", NULL, 2, _6$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$8, "nc/image/gd.zep", 85 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image", "nc/image/gd.zep", 89);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 54, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 55, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&im, this_ptr, "newimage", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("handler"), handler TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_7, "imagesx", NULL, 56, handler);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("width"), _7 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_8, "imagesy", NULL, 57, handler);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("height"), _8 TSRMLS_CC);
	zephir_update_property_zval(im, SL("extension"), ext TSRMLS_CC);
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Gd, fromString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *extension_param = NULL, *im = NULL, *handler = NULL, *_0 = NULL, *_1 = NULL, *_2$$4 = NULL, *_3$$4;
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


	ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromstring", NULL, 58, data);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image: imagecreatefromstring", "nc/image/gd.zep", 111);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 54, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 55, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&im, this_ptr, "newimage", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("handler"), handler TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_0, "imagesx", NULL, 56, handler);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("width"), _0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "imagesy", NULL, 57, handler);
	zephir_check_call_status();
	zephir_update_property_zval(im, SL("height"), _1 TSRMLS_CC);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_3$$4);
		zephir_fast_strtolower(_3$$4, extension);
		zephir_update_property_zval(im, SL("extension"), _3$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Gd, captcha) {

	double rPadding = 0, rOverlap = 0;
	zephir_fcall_cache_entry *_26 = NULL, *_28 = NULL, *_42 = NULL, *_51 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	long width, height, textLen = 0, fontSize = 0, padding = 0, r = 0, g = 0, b = 0, dr = 0, dg = 0, db = 0, i = 0, j = 0, x = 0, y = 0, x2 = 0, y2 = 0, angle = 0;
	zval *text_param = NULL, *width_param = NULL, *height_param = NULL, *options_param = NULL, *im = NULL, *gdIm = NULL, *handler = NULL, *color = NULL, *shadow = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_7, *_8, _9 = zval_used_for_init, *_10 = NULL, *_11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _29, _30, _31, _23$$4 = zval_used_for_init, _24$$4 = zval_used_for_init, _25$$4 = zval_used_for_init, _27$$4 = zval_used_for_init, _32$$6 = zval_used_for_init, _33$$6 = zval_used_for_init, _34$$5 = zval_used_for_init, _35$$5 = zval_used_for_init, _36$$5 = zval_used_for_init, _37$$5 = zval_used_for_init, _38$$5 = zval_used_for_init, _39$$5 = zval_used_for_init, _40$$5 = zval_used_for_init, *_41$$5 = NULL, _44$$5 = zval_used_for_init, _45$$5 = zval_used_for_init, _46$$5 = zval_used_for_init, _47$$5 = zval_used_for_init, _48$$5 = zval_used_for_init, _49$$5 = zval_used_for_init, _50$$5 = zval_used_for_init, _52$$7 = zval_used_for_init, _53$$7 = zval_used_for_init, _54$$7 = zval_used_for_init, _55$$7 = zval_used_for_init, _56$$7 = zval_used_for_init, _57$$7 = zval_used_for_init, _58$$7 = zval_used_for_init, _59$$7 = zval_used_for_init, _60$$7 = zval_used_for_init, _61$$7 = zval_used_for_init, _62$$7 = zval_used_for_init, _63$$7 = zval_used_for_init, _64$$7 = zval_used_for_init, _65$$7 = zval_used_for_init, _70$$7 = zval_used_for_init, _71$$7 = zval_used_for_init, _72$$7 = zval_used_for_init, _73$$7 = zval_used_for_init, _66$$8 = zval_used_for_init, _67$$8 = zval_used_for_init, _68$$8 = zval_used_for_init, _69$$8 = zval_used_for_init;
	zval *text = NULL, *font = NULL, *ch = NULL, *_6 = NULL, *_43$$5 = NULL;

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


	ZEPHIR_CALL_METHOD(&im, this_ptr, "newcaptcha", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, width);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, height);
	ZEPHIR_CALL_METHOD(&gdIm, this_ptr, "creategdimagefromsize", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, gdIm, SL("handler"), PH_NOISY_CC);
	zephir_update_property_zval(im, SL("handler"), _2 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, gdIm, SL("width"), PH_NOISY_CC);
	zephir_update_property_zval(im, SL("width"), _3 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, gdIm, SL("height"), PH_NOISY_CC);
	zephir_update_property_zval(im, SL("height"), _4 TSRMLS_CC);
	zephir_update_property_zval(im, SL("text"), text TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, im, "setoptions", NULL, 0, options);
	zephir_check_call_status();
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
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property(&_11, im, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(handler, _11);
	ZEPHIR_SINIT_NVAR(_9);
	ZVAL_LONG(&_9, 200);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 255);
	r = zephir_mt_rand(zephir_get_intval(&_9), zephir_get_intval(&_12) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, 200);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, 255);
	g = zephir_mt_rand(zephir_get_intval(&_13), zephir_get_intval(&_14) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, 200);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, 255);
	b = zephir_mt_rand(zephir_get_intval(&_15), zephir_get_intval(&_16) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_LONG(&_17, 100);
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_LONG(&_18, 150);
	dr = (long) (zephir_safe_div_long_long((r - zephir_mt_rand(zephir_get_intval(&_17), zephir_get_intval(&_18) TSRMLS_CC)), width TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_LONG(&_19, 100);
	ZEPHIR_SINIT_VAR(_20);
	ZVAL_LONG(&_20, 150);
	dg = (long) (zephir_safe_div_long_long((g - zephir_mt_rand(zephir_get_intval(&_19), zephir_get_intval(&_20) TSRMLS_CC)), width TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_21);
	ZVAL_LONG(&_21, 100);
	ZEPHIR_SINIT_VAR(_22);
	ZVAL_LONG(&_22, 150);
	db = (long) (zephir_safe_div_long_long((b - zephir_mt_rand(zephir_get_intval(&_21), zephir_get_intval(&_22) TSRMLS_CC)), width TSRMLS_CC));
	i = 0;
	while (1) {
		if (!(i < width)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_23$$4);
		ZVAL_LONG(&_23$$4, r);
		ZEPHIR_SINIT_NVAR(_24$$4);
		ZVAL_LONG(&_24$$4, g);
		ZEPHIR_SINIT_NVAR(_25$$4);
		ZVAL_LONG(&_25$$4, b);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_26, 60, handler, &_23$$4, &_24$$4, &_25$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_23$$4);
		ZVAL_LONG(&_23$$4, i);
		ZEPHIR_SINIT_NVAR(_24$$4);
		ZVAL_LONG(&_24$$4, 0);
		ZEPHIR_SINIT_NVAR(_25$$4);
		ZVAL_LONG(&_25$$4, i);
		ZEPHIR_SINIT_NVAR(_27$$4);
		ZVAL_LONG(&_27$$4, height);
		ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_28, 61, handler, &_23$$4, &_24$$4, &_25$$4, &_27$$4, color);
		zephir_check_call_status();
		r -= dr;
		g -= dg;
		b -= db;
		i++;
	}
	ZEPHIR_SINIT_VAR(_29);
	ZVAL_LONG(&_29, 0);
	ZEPHIR_SINIT_VAR(_30);
	ZVAL_LONG(&_30, 0);
	ZEPHIR_SINIT_VAR(_31);
	ZVAL_LONG(&_31, 0);
	ZEPHIR_CALL_FUNCTION(&shadow, "imagecolorallocate", &_26, 60, handler, &_29, &_30, &_31);
	zephir_check_call_status();
	x = padding;
	i = 0;
	while (1) {
		if (!(i < textLen)) {
			break;
		}
		x2 = (long) (((double) (width - (padding * 2)) - (((double) ((((double) (1.0 - rOverlap)) * (double) (((textLen - i)))) + rOverlap)) * fontSize)));
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
		ZEPHIR_CALL_FUNCTION(&_41$$5, "mb_substr", &_42, 62, text, &_38$$5, &_39$$5, &_40$$5);
		zephir_check_call_status();
		zephir_get_strval(_43$$5, _41$$5);
		ZEPHIR_CPY_WRT(ch, _43$$5);
		ZEPHIR_SINIT_NVAR(_38$$5);
		ZVAL_LONG(&_38$$5, 0);
		ZEPHIR_SINIT_NVAR(_39$$5);
		ZVAL_LONG(&_39$$5, 255);
		ZEPHIR_SINIT_NVAR(_40$$5);
		ZVAL_LONG(&_40$$5, 0);
		ZEPHIR_SINIT_NVAR(_44$$5);
		ZVAL_LONG(&_44$$5, 255);
		ZEPHIR_SINIT_NVAR(_45$$5);
		ZVAL_LONG(&_45$$5, 0);
		ZEPHIR_SINIT_NVAR(_46$$5);
		ZVAL_LONG(&_46$$5, 255);
		ZEPHIR_SINIT_NVAR(_47$$5);
		ZVAL_LONG(&_47$$5, zephir_mt_rand(zephir_get_intval(&_38$$5), zephir_get_intval(&_39$$5) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_48$$5);
		ZVAL_LONG(&_48$$5, zephir_mt_rand(zephir_get_intval(&_40$$5), zephir_get_intval(&_44$$5) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_49$$5);
		ZVAL_LONG(&_49$$5, zephir_mt_rand(zephir_get_intval(&_45$$5), zephir_get_intval(&_46$$5) TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_26, 60, handler, &_47$$5, &_48$$5, &_49$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_47$$5);
		ZVAL_LONG(&_47$$5, fontSize);
		ZEPHIR_SINIT_NVAR(_48$$5);
		ZVAL_LONG(&_48$$5, angle);
		ZEPHIR_SINIT_NVAR(_49$$5);
		ZVAL_LONG(&_49$$5, (x + 1));
		ZEPHIR_SINIT_NVAR(_50$$5);
		ZVAL_LONG(&_50$$5, (y + 1));
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", &_51, 63, handler, &_47$$5, &_48$$5, &_49$$5, &_50$$5, shadow, font, ch);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_47$$5);
		ZVAL_LONG(&_47$$5, fontSize);
		ZEPHIR_SINIT_NVAR(_48$$5);
		ZVAL_LONG(&_48$$5, angle);
		ZEPHIR_SINIT_NVAR(_49$$5);
		ZVAL_LONG(&_49$$5, x);
		ZEPHIR_SINIT_NVAR(_50$$5);
		ZVAL_LONG(&_50$$5, y);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", &_51, 63, handler, &_47$$5, &_48$$5, &_49$$5, &_50$$5, color, font, ch);
		zephir_check_call_status();
		x = (x + (((double) (1.0 - rOverlap)) * fontSize));
		i++;
	}
	i = 0;
	while (1) {
		if (!(i < textLen)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_52$$7);
		ZVAL_LONG(&_52$$7, 0);
		ZEPHIR_SINIT_NVAR(_53$$7);
		ZVAL_LONG(&_53$$7, 255);
		ZEPHIR_SINIT_NVAR(_54$$7);
		ZVAL_LONG(&_54$$7, 0);
		ZEPHIR_SINIT_NVAR(_55$$7);
		ZVAL_LONG(&_55$$7, 255);
		ZEPHIR_SINIT_NVAR(_56$$7);
		ZVAL_LONG(&_56$$7, 0);
		ZEPHIR_SINIT_NVAR(_57$$7);
		ZVAL_LONG(&_57$$7, 255);
		ZEPHIR_SINIT_NVAR(_58$$7);
		ZVAL_LONG(&_58$$7, zephir_mt_rand(zephir_get_intval(&_52$$7), zephir_get_intval(&_53$$7) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_59$$7);
		ZVAL_LONG(&_59$$7, zephir_mt_rand(zephir_get_intval(&_54$$7), zephir_get_intval(&_55$$7) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_60$$7);
		ZVAL_LONG(&_60$$7, zephir_mt_rand(zephir_get_intval(&_56$$7), zephir_get_intval(&_57$$7) TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_26, 60, handler, &_58$$7, &_59$$7, &_60$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_58$$7);
		ZVAL_LONG(&_58$$7, 0);
		ZEPHIR_SINIT_NVAR(_59$$7);
		ZVAL_LONG(&_59$$7, width);
		x = zephir_mt_rand(zephir_get_intval(&_58$$7), zephir_get_intval(&_59$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_60$$7);
		ZVAL_LONG(&_60$$7, 0);
		ZEPHIR_SINIT_NVAR(_61$$7);
		ZVAL_LONG(&_61$$7, height);
		y = zephir_mt_rand(zephir_get_intval(&_60$$7), zephir_get_intval(&_61$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_62$$7);
		ZVAL_LONG(&_62$$7, 0);
		ZEPHIR_SINIT_NVAR(_63$$7);
		ZVAL_LONG(&_63$$7, width);
		x2 = zephir_mt_rand(zephir_get_intval(&_62$$7), zephir_get_intval(&_63$$7) TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_64$$7);
		ZVAL_LONG(&_64$$7, 0);
		ZEPHIR_SINIT_NVAR(_65$$7);
		ZVAL_LONG(&_65$$7, height);
		y2 = zephir_mt_rand(zephir_get_intval(&_64$$7), zephir_get_intval(&_65$$7) TSRMLS_CC);
		j = 0;
		while (1) {
			if (!(j <= padding)) {
				break;
			}
			ZEPHIR_SINIT_NVAR(_66$$8);
			ZVAL_LONG(&_66$$8, (x + j));
			ZEPHIR_SINIT_NVAR(_67$$8);
			ZVAL_LONG(&_67$$8, y);
			ZEPHIR_SINIT_NVAR(_68$$8);
			ZVAL_LONG(&_68$$8, (x2 + j));
			ZEPHIR_SINIT_NVAR(_69$$8);
			ZVAL_LONG(&_69$$8, y2);
			ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_28, 61, handler, &_66$$8, &_67$$8, &_68$$8, &_69$$8, color);
			zephir_check_call_status();
			j++;
		}
		ZEPHIR_SINIT_NVAR(_70$$7);
		ZVAL_LONG(&_70$$7, (x + j));
		ZEPHIR_SINIT_NVAR(_71$$7);
		ZVAL_LONG(&_71$$7, y);
		ZEPHIR_SINIT_NVAR(_72$$7);
		ZVAL_LONG(&_72$$7, (x2 + j));
		ZEPHIR_SINIT_NVAR(_73$$7);
		ZVAL_LONG(&_73$$7, y2);
		ZEPHIR_CALL_FUNCTION(NULL, "imageline", &_28, 61, handler, &_70$$7, &_71$$7, &_72$$7, &_73$$7, shadow);
		zephir_check_call_status();
		i++;
	}
	RETURN_CCTOR(im);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument width must be positive", "nc/image/gd.zep", 223);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Arguments x and y must not be negative", "nc/image/gd.zep", 255);
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Argument w must be positive", "nc/image/gd.zep", 259);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cropping out of area", "nc/image/gd.zep", 267);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Width must be positive", "nc/image/gd.zep", 282);
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
		if (zephir_instance_of_ev(srcIm, nc_image_image_ce TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_0$$4);
			ZVAL_LONG(_0$$4, x);
			ZEPHIR_INIT_NVAR(_1$$4);
			ZVAL_LONG(_1$$4, y);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "copy", &_2, 0, resultIm, srcIm, _0$$4, _1$$4);
			zephir_check_call_status();
			break;
		}
		if (zephir_instance_of_ev(srcIm, nc_image_text_ce TSRMLS_CC)) {
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
		zephir_throw_exception_debug(_6$$3, "nc/image/gd.zep", 338 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while (0);
	RETURN_CCTOR(resultIm);

}

PHP_METHOD(Nc_Image_Gd, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *destPath = NULL;
	zval *im, *destPath_param = NULL, *_0, *_1$$3, *_2$$3 = NULL, *_3$$3 = NULL, *_4$$5, *_5$$5 = NULL, *_6$$5 = NULL, *_7$$7, *_8$$7 = NULL, _9$$7, *_10$$7 = NULL, *_11$$9, *_12$$9, *_13$$9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &im, &destPath_param);

	zephir_get_strval(destPath, destPath_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, im, SL("extension"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(_0, "png")) {
			ZEPHIR_OBS_VAR(_1$$3);
			zephir_read_property(&_1$$3, im, SL("handler"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			if (!(!destPath) && Z_STRLEN_P(destPath)) {
				ZEPHIR_CPY_WRT(_2$$3, destPath);
			} else {
				ZEPHIR_INIT_NVAR(_2$$3);
				ZVAL_NULL(_2$$3);
			}
			ZEPHIR_CALL_FUNCTION(&_3$$3, "imagepng", NULL, 64, _1$$3, _2$$3);
			zephir_check_call_status();
			if (zephir_is_true(_3$$3)) {
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "gif")) {
			ZEPHIR_OBS_VAR(_4$$5);
			zephir_read_property(&_4$$5, im, SL("handler"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_5$$5);
			if (!(!destPath) && Z_STRLEN_P(destPath)) {
				ZEPHIR_CPY_WRT(_5$$5, destPath);
			} else {
				ZEPHIR_INIT_NVAR(_5$$5);
				ZVAL_NULL(_5$$5);
			}
			ZEPHIR_CALL_FUNCTION(&_6$$5, "imagegif", NULL, 65, _4$$5, _5$$5);
			zephir_check_call_status();
			if (zephir_is_true(_6$$5)) {
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_0, "jpg") || ZEPHIR_IS_STRING(_0, "jpeg")) {
			ZEPHIR_OBS_VAR(_7$$7);
			zephir_read_property(&_7$$7, im, SL("handler"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_8$$7);
			if (!(!destPath) && Z_STRLEN_P(destPath)) {
				ZEPHIR_CPY_WRT(_8$$7, destPath);
			} else {
				ZEPHIR_INIT_NVAR(_8$$7);
				ZVAL_NULL(_8$$7);
			}
			ZEPHIR_SINIT_VAR(_9$$7);
			ZVAL_LONG(&_9$$7, 100);
			ZEPHIR_CALL_FUNCTION(&_10$$7, "imagejpeg", NULL, 66, _7$$7, _8$$7, &_9$$7);
			zephir_check_call_status();
			if (zephir_is_true(_10$$7)) {
				RETURN_MM_NULL();
			}
			break;
		}
		ZEPHIR_INIT_VAR(_11$$9);
		object_init_ex(_11$$9, nc_image_exception_ce);
		ZEPHIR_OBS_VAR(_12$$9);
		zephir_read_property(&_12$$9, im, SL("extension"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_13$$9);
		ZEPHIR_CONCAT_SV(_13$$9, "Unsupported extension: ", _12$$9);
		ZEPHIR_CALL_METHOD(NULL, _11$$9, "__construct", NULL, 2, _13$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_11$$9, "nc/image/gd.zep", 367 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot save image", "nc/image/gd.zep", 370);
	return;

}

PHP_METHOD(Nc_Image_Gd, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *im, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &im);



	if (zephir_instance_of_ev(im, nc_image_image_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property(&_0$$3, im, SL("handler"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 67, _0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, createGdImageFromSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *width_param = NULL, *height_param = NULL, *im = NULL, *handler = NULL, *background = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, _2, _3, *_4;
	long width, height;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &width_param, &height_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);


	if (width < 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Width must be positive", "nc/image/gd.zep", 385);
		return;
	}
	if (height < 1) {
		height = width;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, width);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, height);
	ZEPHIR_CALL_FUNCTION(&handler, "imagecreatetruecolor", NULL, 68, &_0, &_1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "Cannot create image: imagecreatetruecolor", "nc/image/gd.zep", 394);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 54, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 55, handler, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 255);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 255);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 255);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 127);
	ZEPHIR_CALL_FUNCTION(&background, "imagecolorallocatealpha", NULL, 69, handler, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagecolortransparent", NULL, 70, handler, background);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 71, handler, &_0, &_1, background);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(im);
	object_init(im);
	zephir_update_property_zval(im, SL("handler"), handler TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, width);
	zephir_update_property_zval(im, SL("width"), _4 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, height);
	zephir_update_property_zval(im, SL("height"), _4 TSRMLS_CC);
	RETURN_CCTOR(im);

}

PHP_METHOD(Nc_Image_Gd, drawText) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	long x, y, alpha = 0, r, g, b;
	zval *dest, *src, *x_param = NULL, *y_param = NULL, *handler = NULL, *color = NULL, *m = NULL, *_0, *_1, _2, *_10, *_11 = NULL, *_12 = NULL, *_13, _14 = zval_used_for_init, _15 = zval_used_for_init, _16 = zval_used_for_init, _17, *_18, *_19, *_20 = NULL, *_3$$3, *_4$$3 = NULL, *_6$$3, *_7$$3 = NULL, *_8$$3, *_9$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &dest, &src, &x_param, &y_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);


	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
	r = 0;
	g = 0;
	b = 0;
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, src, SL("color"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", 0);
	zephir_preg_match(_0, &_2, _1, m, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		zephir_array_fetch_long(&_3$$3, m, 1, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 419 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "hexdec", &_5, 72, _3$$3);
		zephir_check_call_status();
		r = zephir_get_intval(_4$$3);
		zephir_array_fetch_long(&_6$$3, m, 2, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 420 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "hexdec", &_5, 72, _6$$3);
		zephir_check_call_status();
		g = zephir_get_intval(_7$$3);
		zephir_array_fetch_long(&_8$$3, m, 3, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 421 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_9$$3, "hexdec", &_5, 72, _8$$3);
		zephir_check_call_status();
		b = zephir_get_intval(_9$$3);
	}
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, src, SL("padding"), PH_NOISY_CC);
	x += zephir_get_numberval(_10);
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property(&_11, src, SL("height"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_12);
	zephir_read_property(&_12, src, SL("padding"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_13);
	zephir_sub_function(_13, _11, _12);
	y += zephir_get_numberval(_13);
	ZEPHIR_OBS_NVAR(_11);
	zephir_read_property(&_11, dest, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(handler, _11);
	ZEPHIR_OBS_NVAR(_11);
	zephir_read_property(&_11, src, SL("opacity"), PH_NOISY_CC);
	alpha = (long) ((1.0 - zephir_get_numberval(_11)) * 127.0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, r);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, g);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, b);
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_LONG(&_17, alpha);
	ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocatealpha", NULL, 69, handler, &_14, &_15, &_16, &_17);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(_12);
	zephir_read_property(&_12, src, SL("fontSize"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_18);
	zephir_read_property(&_18, src, SL("font"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_19);
	zephir_read_property(&_19, src, SL("text"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_14);
	ZVAL_LONG(&_14, 0);
	ZEPHIR_SINIT_NVAR(_15);
	ZVAL_LONG(&_15, x);
	ZEPHIR_SINIT_NVAR(_16);
	ZVAL_LONG(&_16, y);
	ZEPHIR_CALL_FUNCTION(&_20, "imagettftext", NULL, 63, handler, _12, &_14, &_15, &_16, color, _18, _19);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_20))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagettftext", "nc/image/gd.zep", 433);
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
	ZEPHIR_CALL_FUNCTION(&_8, "imagecopy", NULL, 73, _0, _1, &_4, &_5, &_6, &_7, _2, _3);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_8))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagecopy", "nc/image/gd.zep", 440);
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
	ZEPHIR_CALL_FUNCTION(&_10, "imagecopyresampled", NULL, 74, _0, _1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_10))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_image_exception_ce, "imagecopyresampled", "nc/image/gd.zep", 449);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

