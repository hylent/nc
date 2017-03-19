
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
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Image_Gd) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Gd, nc, image_gd, nc_image_imageabstract_ce, nc_image_gd_method_entry, 0);

	zend_declare_property_null(nc_image_gd_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Gd, __construct) {

	zval _0, _1, _2$$3, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "gd");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 28, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "__construct");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "nc/image/gd.zep", 10 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Gd, bySize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval extension;
	zval *w_param = NULL, *h_param = NULL, *extension_param = NULL, __$true, handler, bgColor, _2, _3, _6, _7, _0$$3, _1$$3, _4$$5, _5$$5;
	long w, h;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&bgColor);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&extension);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &w_param, &h_param, &extension_param);

	w = zephir_get_intval(w_param);
	if (!h_param) {
		h = 0;
	} else {
		h = zephir_get_intval(h_param);
	}
	if (!extension_param) {
		ZEPHIR_INIT_VAR(&extension);
		ZVAL_STRING(&extension, "png");
	} else {
		zephir_get_strval(&extension, extension_param);
	}


	if (unlikely(w < 1)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "bySize");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "nc/image/gd.zep", 19 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZVAL_LONG(&_2, w);
	ZVAL_LONG(&_3, h);
	ZEPHIR_CALL_FUNCTION(&handler, "imagecreatetruecolor", NULL, 70, &_2, &_3);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&handler))) {
		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "bySize");
		ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 3, &_5$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$5, "nc/image/gd.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 71, &handler, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 72, &handler, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 255);
	ZVAL_LONG(&_3, 255);
	ZVAL_LONG(&_6, 255);
	ZVAL_LONG(&_7, 127);
	ZEPHIR_CALL_FUNCTION(&bgColor, "imagecolorallocatealpha", NULL, 73, &handler, &_2, &_3, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagecolortransparent", NULL, 74, &handler, &bgColor);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagefill", NULL, 75, &handler, &_2, &_3, &bgColor);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &handler, &extension);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, byString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *extension_param = NULL, __$true, handler, _0, _1$$3, _2$$3, _3$$4, _4$$4;
	zval data, extension;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&extension);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &extension_param);

	zephir_get_strval(&data, data_param);
	if (!extension_param) {
		ZEPHIR_INIT_VAR(&extension);
		ZVAL_STRING(&extension, "png");
	} else {
		zephir_get_strval(&extension, extension_param);
	}


	if (unlikely(zephir_fast_strlen_ev(&data) < 1)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "byString");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 47 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromstring", NULL, 76, &data);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&handler))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "byString");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 3, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "nc/image/gd.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 71, &handler, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 72, &handler, &__$true);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &handler, &extension);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, byPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, __$true, eit, handler, extension, _0$$3, _1$$3, _2$$4, _3$$4, _4$$8, _5$$8, _6$$9, _7$$9;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&eit);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	if (unlikely(!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "byPath");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "nc/image/gd.zep", 66 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&eit, "exif_imagetype", NULL, 77, &path);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&eit))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "byPath");
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 3, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "nc/image/gd.zep", 72 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_LONG(&eit, 2)) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromjpeg", NULL, 78, &path);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&extension);
			ZVAL_STRING(&extension, "jpg");
			break;
		}
		if (ZEPHIR_IS_LONG(&eit, 3)) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefrompng", NULL, 79, &path);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_STRING(&extension, "png");
			break;
		}
		if (ZEPHIR_IS_LONG(&eit, 1)) {
			ZEPHIR_CALL_FUNCTION(&handler, "imagecreatefromgif", NULL, 80, &path);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_STRING(&extension, "gif");
			break;
		}
		ZEPHIR_INIT_VAR(&_4$$8);
		object_init_ex(&_4$$8, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$8);
		ZVAL_STRING(&_5$$8, "byPath");
		ZEPHIR_CALL_METHOD(NULL, &_4$$8, "__construct", NULL, 3, &_5$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$8, "nc/image/gd.zep", 90 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (unlikely(!zephir_is_true(&handler))) {
		ZEPHIR_INIT_VAR(&_6$$9);
		object_init_ex(&_6$$9, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_7$$9);
		ZVAL_STRING(&_7$$9, "byPath");
		ZEPHIR_CALL_METHOD(NULL, &_6$$9, "__construct", NULL, 3, &_7$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$9, "nc/image/gd.zep", 94 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, 71, &handler, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagesavealpha", NULL, 72, &handler, &__$true);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &handler, &extension);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, copy) {

	zval dstIm, _0, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _1$$3, _2$$3, _15$$4, _16$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dstIm);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "copy");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 108 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("height"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&dstIm, this_ptr, "bysize", NULL, 0, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_read_property(&_6, &dstIm, SL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_8, this_ptr, SL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_9, this_ptr, SL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_10, 0);
	ZVAL_LONG(&_11, 0);
	ZVAL_LONG(&_12, 0);
	ZVAL_LONG(&_13, 0);
	ZEPHIR_CALL_FUNCTION(&_14, "imagecopy", NULL, 81, &_6, &_7, &_10, &_11, &_12, &_13, &_8, &_9);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_14))) {
		ZEPHIR_INIT_VAR(&_15$$4);
		object_init_ex(&_15$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_16$$4);
		ZVAL_STRING(&_16$$4, "copy");
		ZEPHIR_CALL_METHOD(NULL, &_15$$4, "__construct", NULL, 3, &_16$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$4, "nc/image/gd.zep", 123 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(dstIm);

}

PHP_METHOD(Nc_Image_Gd, resample) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, *dstArea, dstArea_sub, *srcArea, srcArea_sub, dstIm, _0, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _1$$3, _2$$3, _15$$4, _16$$4;
	long w, h;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dstArea_sub);
	ZVAL_UNDEF(&srcArea_sub);
	ZVAL_UNDEF(&dstIm);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &w_param, &h_param, &dstArea, &srcArea);

	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "resample");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 134 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, w);
	ZVAL_LONG(&_5, h);
	ZEPHIR_CALL_METHOD(&dstIm, this_ptr, "bysize", NULL, 0, &_4, &_5, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, &dstIm, SL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_6, dstArea, SL("x"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, dstArea, SL("y"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_8, srcArea, SL("x"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_9, srcArea, SL("y"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_10, dstArea, SL("w"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, dstArea, SL("h"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, srcArea, SL("w"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, srcArea, SL("h"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_14, "imagecopyresampled", NULL, 82, &_4, &_5, &_6, &_7, &_8, &_9, &_10, &_11, &_12, &_13);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_14))) {
		ZEPHIR_INIT_VAR(&_15$$4);
		object_init_ex(&_15$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_16$$4);
		ZVAL_STRING(&_16$$4, "resample");
		ZEPHIR_CALL_METHOD(NULL, &_15$$4, "__construct", NULL, 3, &_16$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$4, "nc/image/gd.zep", 151 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(dstIm);

}

PHP_METHOD(Nc_Image_Gd, largest) {

	zend_bool _5, _6;
	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, _0, _3, _4, _7, _8, _9, _10, _11, _13, _1$$3, _2$$3;
	long w, h, oriW = 0, oriH = 0, dstW = 0, dstH = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &w_param, &h_param);

	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "largest");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 162 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("width"), PH_NOISY_CC);
	oriW = zephir_get_intval(&_3);
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, this_ptr, SL("height"), PH_NOISY_CC);
	oriH = zephir_get_intval(&_4);
	dstW = oriW;
	dstH = oriH;
	_5 = w > 0;
	if (_5) {
		_5 = dstW > w;
	}
	if (_5) {
		dstH = (long) (zephir_safe_div_double_long(((1.0 * dstH) * w), dstW TSRMLS_CC));
		dstW = w;
	}
	_6 = h > 0;
	if (_6) {
		_6 = dstH > h;
	}
	if (_6) {
		dstW = (long) (zephir_safe_div_double_long(((1.0 * dstW) * h), dstH TSRMLS_CC));
		dstH = h;
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, nc_image_area_ce);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, dstW);
	ZVAL_LONG(&_11, dstH);
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", &_12, 16, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	object_init_ex(&_13, nc_image_area_ce);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, oriW);
	ZVAL_LONG(&_11, oriH);
	ZEPHIR_CALL_METHOD(NULL, &_13, "__construct", &_12, 16, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	ZVAL_LONG(&_8, dstW);
	ZVAL_LONG(&_9, dstH);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resample", NULL, 0, &_8, &_9, &_7, &_13);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, resize) {

	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, _0, _5, _6, _7, _8, _9, _10, _11, _13, _1$$3, _2$$3, _3$$4, _4$$4;
	long w, h, oriW = 0, oriH = 0, dstW = 0, dstH = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &w_param, &h_param);

	w = zephir_get_intval(w_param);
	if (!h_param) {
		h = 0;
	} else {
		h = zephir_get_intval(h_param);
	}


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "resize");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 194 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "resize");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 3, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "nc/image/gd.zep", 198 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("width"), PH_NOISY_CC);
	oriW = zephir_get_intval(&_5);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("height"), PH_NOISY_CC);
	oriH = zephir_get_intval(&_6);
	if ((oriW * h) > (oriH * w)) {
		dstW = w;
		dstH = (long) (zephir_safe_div_double_long(((1.0 * oriH) * w), oriW TSRMLS_CC));
	} else {
		dstW = (long) (zephir_safe_div_double_long(((1.0 * oriW) * h), oriH TSRMLS_CC));
		dstH = h;
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, nc_image_area_ce);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, dstW);
	ZVAL_LONG(&_11, dstH);
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", &_12, 16, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	object_init_ex(&_13, nc_image_area_ce);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, oriW);
	ZVAL_LONG(&_11, oriH);
	ZEPHIR_CALL_METHOD(NULL, &_13, "__construct", &_12, 16, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	ZVAL_LONG(&_8, dstW);
	ZVAL_LONG(&_9, dstH);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resample", NULL, 0, &_8, &_9, &_7, &_13);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, thumbnail) {

	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, _0, _5, _6, _7, _8, _9, _10, _11, _13, _1$$3, _2$$3, _3$$4, _4$$4;
	long w, h, oriW = 0, oriH = 0, dstX = 0, dstY = 0, dstW = 0, dstH = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &w_param, &h_param);

	w = zephir_get_intval(w_param);
	if (!h_param) {
		h = 0;
	} else {
		h = zephir_get_intval(h_param);
	}


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "thumbnail");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 229 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "thumbnail");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 3, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "nc/image/gd.zep", 233 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("width"), PH_NOISY_CC);
	oriW = zephir_get_intval(&_5);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("height"), PH_NOISY_CC);
	oriH = zephir_get_intval(&_6);
	if ((oriW * h) > (oriH * w)) {
		dstW = w;
		dstH = (long) (zephir_safe_div_double_long(((1.0 * oriH) * w), oriW TSRMLS_CC));
	} else {
		dstW = (long) (zephir_safe_div_double_long(((1.0 * oriW) * h), oriH TSRMLS_CC));
		dstH = h;
	}
	dstX = (long) ((0.5 * (double) (((w - dstW)))));
	dstY = (long) ((0.5 * (double) (((h - dstH)))));
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, nc_image_area_ce);
	ZVAL_LONG(&_8, dstX);
	ZVAL_LONG(&_9, dstY);
	ZVAL_LONG(&_10, dstW);
	ZVAL_LONG(&_11, dstH);
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", &_12, 16, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	object_init_ex(&_13, nc_image_area_ce);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, oriW);
	ZVAL_LONG(&_11, oriH);
	ZEPHIR_CALL_METHOD(NULL, &_13, "__construct", &_12, 16, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	ZVAL_LONG(&_8, w);
	ZVAL_LONG(&_9, h);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resample", NULL, 0, &_8, &_9, &_7, &_13);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, cropThumbnail) {

	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, _0, _5, _6, _7, _8, _9, _10, _11, _13, _1$$3, _2$$3, _3$$4, _4$$4;
	long w, h, oriW = 0, oriH = 0, srcX = 0, srcY = 0, srcW = 0, srcH = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &w_param, &h_param);

	w = zephir_get_intval(w_param);
	if (!h_param) {
		h = 0;
	} else {
		h = zephir_get_intval(h_param);
	}


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "cropThumbnail");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 267 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "cropThumbnail");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 3, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "nc/image/gd.zep", 271 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("width"), PH_NOISY_CC);
	oriW = zephir_get_intval(&_5);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("height"), PH_NOISY_CC);
	oriH = zephir_get_intval(&_6);
	if ((oriW * h) < (oriH * w)) {
		srcW = oriW;
		srcH = (long) (zephir_safe_div_double_long(((1.0 * h) * oriW), w TSRMLS_CC));
	} else {
		srcW = (long) (zephir_safe_div_double_long(((1.0 * w) * oriH), h TSRMLS_CC));
		srcH = oriH;
	}
	srcX = (long) ((0.5 * (double) (((oriW - srcW)))));
	srcY = (long) ((0.5 * (double) (((oriH - srcH)))));
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, nc_image_area_ce);
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, w);
	ZVAL_LONG(&_11, h);
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", &_12, 16, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	object_init_ex(&_13, nc_image_area_ce);
	ZVAL_LONG(&_8, srcX);
	ZVAL_LONG(&_9, srcY);
	ZVAL_LONG(&_10, srcW);
	ZVAL_LONG(&_11, srcH);
	ZEPHIR_CALL_METHOD(NULL, &_13, "__construct", &_12, 16, &_8, &_9, &_10, &_11);
	zephir_check_call_status();
	ZVAL_LONG(&_8, w);
	ZVAL_LONG(&_9, h);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resample", NULL, 0, &_8, &_9, &_7, &_13);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, crop) {

	zend_bool _3, _10;
	zephir_fcall_cache_entry *_18 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, _0, _8, _9, _13, _14, _15, _16, _17, _19, _1$$3, _2$$3, _4$$4, _5$$4, _6$$5, _7$$5, _11$$7, _12$$7;
	long x, y, w, h, oriW = 0, oriH = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);

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


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "crop");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 305 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = x < 0;
	if (!(_3)) {
		_3 = y < 0;
	}
	if (unlikely(_3)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "crop");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 3, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "nc/image/gd.zep", 309 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "crop");
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 3, &_7$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "nc/image/gd.zep", 313 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, SL("width"), PH_NOISY_CC);
	oriW = zephir_get_intval(&_8);
	ZEPHIR_OBS_VAR(&_9);
	zephir_read_property(&_9, this_ptr, SL("height"), PH_NOISY_CC);
	oriH = zephir_get_intval(&_9);
	_10 = (x + w) > oriW;
	if (!(_10)) {
		_10 = (y + h) > oriH;
	}
	if (unlikely(_10)) {
		ZEPHIR_INIT_VAR(&_11$$7);
		object_init_ex(&_11$$7, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$7);
		ZVAL_STRING(&_12$$7, "crop");
		ZEPHIR_CALL_METHOD(NULL, &_11$$7, "__construct", NULL, 3, &_12$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$7, "nc/image/gd.zep", 324 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_13);
	object_init_ex(&_13, nc_image_area_ce);
	ZVAL_LONG(&_14, 0);
	ZVAL_LONG(&_15, 0);
	ZVAL_LONG(&_16, w);
	ZVAL_LONG(&_17, h);
	ZEPHIR_CALL_METHOD(NULL, &_13, "__construct", &_18, 16, &_14, &_15, &_16, &_17);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_19);
	object_init_ex(&_19, nc_image_area_ce);
	ZVAL_LONG(&_14, x);
	ZVAL_LONG(&_15, y);
	ZVAL_LONG(&_16, w);
	ZVAL_LONG(&_17, h);
	ZEPHIR_CALL_METHOD(NULL, &_19, "__construct", &_18, 16, &_14, &_15, &_16, &_17);
	zephir_check_call_status();
	ZVAL_LONG(&_14, w);
	ZVAL_LONG(&_15, h);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resample", NULL, 0, &_14, &_15, &_13, &_19);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, paste) {

	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval *im, im_sub, *x_param = NULL, *y_param = NULL, srcIm, dstIm, paintingArea, _0, _3, _10, _11, _12, _13, _14, _15, _16, _17, _18, _1$$3, _2$$3, _4$$6, _5$$6, _6$$7, _7$$7, _8$$7, _9$$7, _19$$8, _20$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&im_sub);
	ZVAL_UNDEF(&srcIm);
	ZVAL_UNDEF(&dstIm);
	ZVAL_UNDEF(&paintingArea);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &im, &x_param, &y_param);

	x = zephir_get_intval(x_param);
	if (!y_param) {
		y = -2147483647;
	} else {
		y = zephir_get_intval(y_param);
	}


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "paste");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 340 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_instance_of_ev(im, nc_image_gd_ce TSRMLS_CC)) {
		ZEPHIR_CPY_WRT(&srcIm, im);
	} else {
		ZEPHIR_CALL_METHOD(&srcIm, this_ptr, "byimage", NULL, 0, im);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, &srcIm, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$6);
		object_init_ex(&_4$$6, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "paste");
		ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 3, &_5$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$6, "nc/image/gd.zep", 350 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&dstIm, this_ptr, "copy", NULL, 0);
	zephir_check_call_status();
	if (y == -2147483647) {
		ZEPHIR_CALL_METHOD(&_6$$7, im, "getwidth", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$7, im, "getheight", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$7, x);
		ZEPHIR_CALL_METHOD(&paintingArea, this_ptr, "getpaintingareabyposition", NULL, 0, &_6$$7, &_7$$7, &_8$$7);
		zephir_check_call_status();
		zephir_read_property(&_8$$7, &paintingArea, SL("x"), PH_NOISY_CC | PH_READONLY);
		x = zephir_get_numberval(&_8$$7);
		zephir_read_property(&_9$$7, &paintingArea, SL("y"), PH_NOISY_CC | PH_READONLY);
		y = zephir_get_numberval(&_9$$7);
	}
	zephir_read_property(&_10, &dstIm, SL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, &srcIm, SL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, &srcIm, SL("width"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, &srcIm, SL("height"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_14, x);
	ZVAL_LONG(&_15, y);
	ZVAL_LONG(&_16, 0);
	ZVAL_LONG(&_17, 0);
	ZEPHIR_CALL_FUNCTION(&_18, "imagecopy", NULL, 81, &_10, &_11, &_14, &_15, &_16, &_17, &_12, &_13);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_18))) {
		ZEPHIR_INIT_VAR(&_19$$8);
		object_init_ex(&_19$$8, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_20$$8);
		ZVAL_STRING(&_20$$8, "paste");
		ZEPHIR_CALL_METHOD(NULL, &_19$$8, "__construct", NULL, 3, &_20$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_19$$8, "nc/image/gd.zep", 371 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(dstIm);

}

PHP_METHOD(Nc_Image_Gd, annotate) {

	zephir_fcall_cache_entry *_21 = NULL, *_30 = NULL, *_34 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long x, y, alpha = 0, r = 0, g = 0, b = 0;
	zval options, _3;
	zval *text_param = NULL, *options_param = NULL, *x_param = NULL, *y_param = NULL, dstIm, dstHandler, mo, textArea, paintingArea, m, colorResource, _0, _4, _5, _6, _15, _16, _17, _18, _37, _38, _39, _46, _47, _48, _49, _50, _51, _52, _1$$3, _2$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _12$$4, _13$$5, _14$$5, _19$$6, _20$$6, _22$$6, _23$$6, _24$$6, _25$$6, _26$$6, _27$$6, _28$$6, _29$$6, _31$$6, _32$$6, _33$$6, _35$$7, _36$$7, _40$$8, _41$$8, _42$$8, _43$$8, _44$$8, _45$$8, _53$$9, _54$$9;
	zval text;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&dstIm);
	ZVAL_UNDEF(&dstHandler);
	ZVAL_UNDEF(&mo);
	ZVAL_UNDEF(&textArea);
	ZVAL_UNDEF(&paintingArea);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&colorResource);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_33$$6);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_36$$7);
	ZVAL_UNDEF(&_40$$8);
	ZVAL_UNDEF(&_41$$8);
	ZVAL_UNDEF(&_42$$8);
	ZVAL_UNDEF(&_43$$8);
	ZVAL_UNDEF(&_44$$8);
	ZVAL_UNDEF(&_45$$8);
	ZVAL_UNDEF(&_53$$9);
	ZVAL_UNDEF(&_54$$9);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &text_param, &options_param, &x_param, &y_param);

	zephir_get_strval(&text, text_param);
	zephir_get_arrval(&options, options_param);
	x = zephir_get_intval(x_param);
	if (!y_param) {
		y = -2147483647;
	} else {
		y = zephir_get_intval(y_param);
	}


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "annotate");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 382 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&dstIm, this_ptr, "copy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&dstHandler);
	zephir_read_property(&dstHandler, &dstIm, SL("handler"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 6, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_3, SL("font"), SL("simsun.ttf"));
	add_assoc_long_ex(&_3, SL("fontSize"), 28);
	add_assoc_long_ex(&_3, SL("padding"), 2);
	add_assoc_double_ex(&_3, SL("opacity"), 1.0);
	add_assoc_stringl_ex(&_3, SL("color"), SL("#000000"));
	add_assoc_stringl_ex(&_3, SL("shadowColor"), SL(""));
	ZEPHIR_INIT_VAR(&mo);
	zephir_add_function(&mo, &options, &_3);
	zephir_array_fetch_string(&_4, &mo, SL("font"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 397 TSRMLS_CC);
	zephir_array_fetch_string(&_5, &mo, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 397 TSRMLS_CC);
	zephir_array_fetch_string(&_6, &mo, SL("padding"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 397 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&textArea, this_ptr, "querytextarea", NULL, 0, &text, &_4, &_5, &_6);
	zephir_check_call_status();
	if (y == -2147483647) {
		zephir_read_property(&_7$$4, &textArea, SL("w"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_8$$4, &textArea, SL("h"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_9$$4, x);
		ZEPHIR_CALL_METHOD(&paintingArea, this_ptr, "getpaintingareabyposition", NULL, 0, &_7$$4, &_8$$4, &_9$$4);
		zephir_check_call_status();
		zephir_read_property(&_9$$4, &paintingArea, SL("x"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_10$$4, &textArea, SL("x"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$4);
		zephir_add_function(&_11$$4, &_9$$4, &_10$$4);
		x = zephir_get_numberval(&_11$$4);
		zephir_read_property(&_9$$4, &paintingArea, SL("y"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_10$$4, &textArea, SL("y"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_12$$4);
		zephir_add_function(&_12$$4, &_9$$4, &_10$$4);
		y = zephir_get_numberval(&_12$$4);
	} else {
		zephir_read_property(&_13$$5, &textArea, SL("x"), PH_NOISY_CC | PH_READONLY);
		x += zephir_get_numberval(&_13$$5);
		zephir_read_property(&_14$$5, &textArea, SL("y"), PH_NOISY_CC | PH_READONLY);
		y += zephir_get_numberval(&_14$$5);
	}
	zephir_array_fetch_string(&_15, &mo, SL("opacity"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 408 TSRMLS_CC);
	alpha = (long) ((((1.0 - zephir_get_numberval(&_15))) * 127.0));
	ZEPHIR_INIT_VAR(&m);
	ZVAL_NULL(&m);
	ZEPHIR_INIT_VAR(&_16);
	zephir_array_fetch_string(&_17, &mo, SL("shadowColor"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 411 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_STRING(&_18, "/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})$/");
	zephir_preg_match(&_16, &_18, &_17, &m, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_16)) {
		zephir_array_fetch_long(&_19$$6, &m, 1, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 412 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_20$$6, "hexdec", &_21, 83, &_19$$6);
		zephir_check_call_status();
		r = zephir_get_intval(&_20$$6);
		zephir_array_fetch_long(&_22$$6, &m, 2, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 413 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_23$$6, "hexdec", &_21, 83, &_22$$6);
		zephir_check_call_status();
		g = zephir_get_intval(&_23$$6);
		zephir_array_fetch_long(&_24$$6, &m, 3, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 414 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_25$$6, "hexdec", &_21, 83, &_24$$6);
		zephir_check_call_status();
		b = zephir_get_intval(&_25$$6);
		ZVAL_LONG(&_26$$6, r);
		ZVAL_LONG(&_27$$6, g);
		ZVAL_LONG(&_28$$6, b);
		ZVAL_LONG(&_29$$6, alpha);
		ZEPHIR_CALL_FUNCTION(&colorResource, "imagecolorallocatealpha", &_30, 73, &dstHandler, &_26$$6, &_27$$6, &_28$$6, &_29$$6);
		zephir_check_call_status();
		zephir_array_fetch_string(&_31$$6, &mo, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 420 TSRMLS_CC);
		zephir_array_fetch_string(&_32$$6, &mo, SL("font"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 425 TSRMLS_CC);
		ZVAL_LONG(&_26$$6, 0);
		ZVAL_LONG(&_27$$6, (x + 1));
		ZVAL_LONG(&_28$$6, (y + 1));
		ZEPHIR_CALL_FUNCTION(&_33$$6, "imagettftext", &_34, 84, &dstHandler, &_31$$6, &_26$$6, &_27$$6, &_28$$6, &colorResource, &_32$$6, &text);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(&_33$$6))) {
			ZEPHIR_INIT_VAR(&_35$$7);
			object_init_ex(&_35$$7, nc_image_exception_ce);
			ZEPHIR_INIT_VAR(&_36$$7);
			ZVAL_STRING(&_36$$7, "annotate");
			ZEPHIR_CALL_METHOD(NULL, &_35$$7, "__construct", NULL, 3, &_36$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_35$$7, "nc/image/gd.zep", 428 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&m);
	ZVAL_NULL(&m);
	r = 0;
	g = 0;
	b = 0;
	ZEPHIR_INIT_VAR(&_37);
	zephir_array_fetch_string(&_38, &mo, SL("color"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 436 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_39);
	ZVAL_STRING(&_39, "/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})$/");
	zephir_preg_match(&_37, &_39, &_38, &m, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_37)) {
		zephir_array_fetch_long(&_40$$8, &m, 1, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 437 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_41$$8, "hexdec", &_21, 83, &_40$$8);
		zephir_check_call_status();
		r = zephir_get_intval(&_41$$8);
		zephir_array_fetch_long(&_42$$8, &m, 2, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 438 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_43$$8, "hexdec", &_21, 83, &_42$$8);
		zephir_check_call_status();
		g = zephir_get_intval(&_43$$8);
		zephir_array_fetch_long(&_44$$8, &m, 3, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 439 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_45$$8, "hexdec", &_21, 83, &_44$$8);
		zephir_check_call_status();
		b = zephir_get_intval(&_45$$8);
	}
	ZVAL_LONG(&_46, r);
	ZVAL_LONG(&_47, g);
	ZVAL_LONG(&_48, b);
	ZVAL_LONG(&_49, alpha);
	ZEPHIR_CALL_FUNCTION(&colorResource, "imagecolorallocatealpha", &_30, 73, &dstHandler, &_46, &_47, &_48, &_49);
	zephir_check_call_status();
	zephir_array_fetch_string(&_50, &mo, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 446 TSRMLS_CC);
	zephir_array_fetch_string(&_51, &mo, SL("font"), PH_NOISY | PH_READONLY, "nc/image/gd.zep", 451 TSRMLS_CC);
	ZVAL_LONG(&_46, 0);
	ZVAL_LONG(&_47, x);
	ZVAL_LONG(&_48, y);
	ZEPHIR_CALL_FUNCTION(&_52, "imagettftext", &_34, 84, &dstHandler, &_50, &_46, &_47, &_48, &colorResource, &_51, &text);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_52))) {
		ZEPHIR_INIT_VAR(&_53$$9);
		object_init_ex(&_53$$9, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_54$$9);
		ZVAL_STRING(&_54$$9, "annotate");
		ZEPHIR_CALL_METHOD(NULL, &_53$$9, "__construct", NULL, 3, &_54$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_53$$9, "nc/image/gd.zep", 454 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(dstIm);

}

PHP_METHOD(Nc_Image_Gd, queryTextArea) {

	int ZEPHIR_LAST_CALL_STATUS;
	long fontSize, padding, x = 0, y = 0, w = 0, h = 0;
	zval *text_param = NULL, *font_param = NULL, *fontSize_param = NULL, *padding_param = NULL, box, _0, _1, _4, _5, _6, _7, _8, _9, _10, _11, _2$$3, _3$$3;
	zval text, font;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&font);
	ZVAL_UNDEF(&box);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &text_param, &font_param, &fontSize_param, &padding_param);

	zephir_get_strval(&text, text_param);
	zephir_get_strval(&font, font_param);
	fontSize = zephir_get_intval(fontSize_param);
	if (!padding_param) {
		padding = 0;
	} else {
		padding = zephir_get_intval(padding_param);
	}


	ZVAL_LONG(&_0, fontSize);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(&box, "imagettfbbox", NULL, 85, &_0, &_1, &font, &text);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&box))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "queryTextArea");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "nc/image/gd.zep", 466 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_long(&_4, &box, 6, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 469 TSRMLS_CC);
	x = (((padding - 1) - zephir_get_numberval(&_4)));
	zephir_array_fetch_long(&_5, &box, 7, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 470 TSRMLS_CC);
	y = (((padding - 1) - zephir_get_numberval(&_5)));
	zephir_array_fetch_long(&_6, &box, 2, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 471 TSRMLS_CC);
	zephir_array_fetch_long(&_7, &box, 6, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 471 TSRMLS_CC);
	w = (((padding * 2) + zephir_get_numberval(&_6)) - zephir_get_numberval(&_7));
	zephir_array_fetch_long(&_8, &box, 3, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 472 TSRMLS_CC);
	zephir_array_fetch_long(&_9, &box, 7, PH_NOISY | PH_READONLY, "nc/image/gd.zep", 472 TSRMLS_CC);
	h = (((padding * 2) + zephir_get_numberval(&_8)) - zephir_get_numberval(&_9));
	object_init_ex(return_value, nc_image_area_ce);
	ZVAL_LONG(&_0, x);
	ZVAL_LONG(&_1, y);
	ZVAL_LONG(&_10, w);
	ZVAL_LONG(&_11, h);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 16, &_0, &_1, &_10, &_11);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Gd, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _3, _13, _14, _1$$3, _2$$3, _4$$4, _5$$4, _6$$4, _7$$6, _8$$6, _9$$8, _10$$8, _11$$10, _12$$10;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "save");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 480 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_STRING(&_3, "jpg") || ZEPHIR_IS_STRING(&_3, "jpeg")) {
			zephir_read_property(&_4$$4, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_5$$4, 100);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "imagejpeg", NULL, 86, &_4$$4, &path, &_5$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$4)) {
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(&_3, "png")) {
			zephir_read_property(&_7$$6, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_8$$6, "imagepng", NULL, 87, &_7$$6, &path);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$6)) {
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(&_3, "gif")) {
			zephir_read_property(&_9$$8, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_10$$8, "imagegif", NULL, 88, &_9$$8, &path);
			zephir_check_call_status();
			if (zephir_is_true(&_10$$8)) {
				RETURN_MM_NULL();
			}
			break;
		}
		ZEPHIR_INIT_VAR(&_11$$10);
		object_init_ex(&_11$$10, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$10);
		ZVAL_STRING(&_12$$10, "save");
		ZEPHIR_CALL_METHOD(NULL, &_11$$10, "__construct", NULL, 3, &_12$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$10, "nc/image/gd.zep", 504 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_INIT_VAR(&_13);
	object_init_ex(&_13, nc_image_exception_ce);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "save");
	ZEPHIR_CALL_METHOD(NULL, &_13, "__construct", NULL, 3, &_14);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_13, "nc/image/gd.zep", 507 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Image_Gd, toString) {

	zval _9;
	zval __$null, success, result, _0, _3, _8, _1$$3, _2$$3, _4$$4, _5$$4, _6$$5, _7$$6, _10$$7, _11$$7, _12$$8, _13$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&success);
	ZVAL_NULL(&success);
	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "toString");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/gd.zep", 515 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 89);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_STRING(&_3, "jpg") || ZEPHIR_IS_STRING(&_3, "jpeg")) {
			zephir_read_property(&_4$$4, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_5$$4, 100);
			ZEPHIR_CALL_FUNCTION(&success, "imagejpeg", NULL, 86, &_4$$4, &__$null, &_5$$4);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_3, "png")) {
			zephir_read_property(&_6$$5, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&success, "imagepng", NULL, 87, &_6$$5);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_3, "gif")) {
			zephir_read_property(&_7$$6, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&success, "imagegif", NULL, 88, &_7$$6);
			zephir_check_call_status();
			break;
		}
	} while(0);

	ZEPHIR_CALL_FUNCTION(&_8, "ob_get_clean", NULL, 90);
	zephir_check_call_status();
	zephir_get_strval(&_9, &_8);
	ZEPHIR_CPY_WRT(&result, &_9);
	if (Z_TYPE_P(&success) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_10$$7);
		object_init_ex(&_10$$7, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_11$$7);
		ZVAL_STRING(&_11$$7, "toString");
		ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", NULL, 3, &_11$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$7, "nc/image/gd.zep", 538 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_INIT_VAR(&_12$$8);
		object_init_ex(&_12$$8, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_13$$8);
		ZVAL_STRING(&_13$$8, "toString");
		ZEPHIR_CALL_METHOD(NULL, &_12$$8, "__construct", NULL, 3, &_13$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$8, "nc/image/gd.zep", 542 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(Nc_Image_Gd, __destruct) {

	zval _0$$3, _1$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_0$$3)) {
			zephir_read_property(&_1$$4, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, 91, &_1$$4);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_NULL();

}

PHP_METHOD(Nc_Image_Gd, newImage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval extension;
	zval *handler, handler_sub, *extension_param = NULL, mimeType, im, _2, _3, _0$$6, _1$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&mimeType);
	ZVAL_UNDEF(&im);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&extension);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler, &extension_param);

	zephir_get_strval(&extension, extension_param);


	do {
		if (ZEPHIR_IS_STRING(&extension, "jpg") || ZEPHIR_IS_STRING(&extension, "jpeg")) {
			ZEPHIR_INIT_VAR(&mimeType);
			ZVAL_STRING(&mimeType, "image/jpeg");
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "png")) {
			ZEPHIR_INIT_NVAR(&mimeType);
			ZVAL_STRING(&mimeType, "image/png");
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "gif")) {
			ZEPHIR_INIT_NVAR(&mimeType);
			ZVAL_STRING(&mimeType, "image/gif");
			break;
		}
		ZEPHIR_INIT_VAR(&_0$$6);
		object_init_ex(&_0$$6, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$6);
		ZVAL_STRING(&_1$$6, "newImage");
		ZEPHIR_CALL_METHOD(NULL, &_0$$6, "__construct", NULL, 3, &_1$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$6, "nc/image/gd.zep", 578 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_CALL_METHOD(&im, this_ptr, "newinstance", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(&im, SL("handler"), handler);
	ZEPHIR_CALL_FUNCTION(&_2, "imagesx", NULL, 92, handler);
	zephir_check_call_status();
	zephir_update_property_zval(&im, SL("width"), &_2);
	ZEPHIR_CALL_FUNCTION(&_3, "imagesy", NULL, 93, handler);
	zephir_check_call_status();
	zephir_update_property_zval(&im, SL("height"), &_3);
	zephir_update_property_zval(&im, SL("extension"), &extension);
	zephir_update_property_zval(&im, SL("mimeType"), &mimeType);
	RETURN_CCTOR(im);

}

