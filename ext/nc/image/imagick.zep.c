
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


ZEPHIR_INIT_CLASS(Nc_Image_Imagick) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Imagick, nc, image_imagick, nc_image_imageabstract_ce, nc_image_imagick_method_entry, 0);

	zend_declare_property_null(nc_image_imagick_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Imagick, __construct) {

	zval _0, _1, _2$$3, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "imagick");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 25, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "__construct");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "nc/image/imagick.zep", 10 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Imagick, bySize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval extension;
	zval *w_param = NULL, *h_param = NULL, *extension_param = NULL, handler, _2, _3, _4, _5, _6, _0$$3, _1$$3, _7$$5, _8$$5;
	long w, h;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
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
		zephir_throw_exception_debug(&_0$$3, "nc/image/imagick.zep", 19 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_INIT_VAR(&handler);
	object_init_ex(&handler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, zephir_get_internal_ce(SL("imagickpixel")));
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "rgba(255,255,255,127)");
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_5, w);
	ZVAL_LONG(&_6, h);
	ZEPHIR_CALL_METHOD(&_2, &handler, "newimage", NULL, 0, &_5, &_6, &_3, &extension);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_7$$5);
		object_init_ex(&_7$$5, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "bySize");
		ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 3, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$5, "nc/image/imagick.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &handler, &extension);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, byString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *extension_param = NULL, handler, _0, _3, _1$$3, _2$$3, _4$$4, _5$$4;
	zval data, extension;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 40 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&handler);
	object_init_ex(&handler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &handler, "readimageblob", NULL, 0, &data);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "byString");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 3, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "nc/image/imagick.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &handler, &extension);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, byPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, eit, handler, extension, _4, _0$$3, _1$$3, _2$$4, _3$$4, _5$$5, _6$$5;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&eit);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

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
		zephir_throw_exception_debug(&_0$$3, "nc/image/imagick.zep", 57 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&eit, "exif_imagetype", NULL, 74, &path);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&eit))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "byPath");
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 3, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "nc/image/imagick.zep", 63 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&handler);
	object_init_ex(&handler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &handler, "readimage", NULL, 0, &path);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_4))) {
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "byPath");
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 3, &_6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "nc/image/imagick.zep", 69 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_LONG(&eit, 2)) {
			ZEPHIR_INIT_VAR(&extension);
			ZVAL_STRING(&extension, "jpg");
			break;
		}
		if (ZEPHIR_IS_LONG(&eit, 3)) {
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_STRING(&extension, "png");
			break;
		}
		if (ZEPHIR_IS_LONG(&eit, 1)) {
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_STRING(&extension, "gif");
			break;
		}
		ZEPHIR_CALL_METHOD(&extension, &handler, "getimageformat", NULL, 0);
		zephir_check_call_status();
		break;
	} while(0);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &handler, &extension);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, copy) {

	zval dstHandler, _0, _3, _4, _1$$3, _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dstHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "copy");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 96 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&dstHandler);
	object_init_ex(&dstHandler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "addimage", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &dstHandler, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, largest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, dstHandler, _0, _5, _6, _7, _1$$3, _2$$3, _3$$4, _4$$4;
	long w, h;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dstHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 110 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (unlikely(w < 1)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "largest");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 3, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "nc/image/imagick.zep", 114 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_INIT_VAR(&dstHandler);
	object_init_ex(&dstHandler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "addimage", NULL, 0, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, w);
	ZVAL_LONG(&_7, h);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "thumbnailimage", NULL, 0, &_6, &_7);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &dstHandler, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, resize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, dstHandler, _0, _5, _6, _7, _8, _1$$3, _2$$3, _3$$4, _4$$4;
	long w, h;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dstHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 133 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_3$$4, "nc/image/imagick.zep", 137 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_INIT_VAR(&dstHandler);
	object_init_ex(&dstHandler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "addimage", NULL, 0, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, w);
	ZVAL_LONG(&_7, h);
	ZVAL_BOOL(&_8, 1);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "thumbnailimage", NULL, 0, &_6, &_7, &_8);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &dstHandler, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, thumbnail) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, dstHandler, _0, _5, _6, _7, _8, _9, _1$$3, _2$$3, _3$$4, _4$$4;
	long w, h;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dstHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 156 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_3$$4, "nc/image/imagick.zep", 160 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_INIT_VAR(&dstHandler);
	object_init_ex(&dstHandler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "addimage", NULL, 0, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, w);
	ZVAL_LONG(&_7, h);
	ZVAL_BOOL(&_8, 1);
	ZVAL_BOOL(&_9, 1);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "thumbnailimage", NULL, 0, &_6, &_7, &_8, &_9);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &dstHandler, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, cropThumbnail) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *w_param = NULL, *h_param = NULL, dstHandler, _0, _5, _6, _7, _1$$3, _2$$3, _3$$4, _4$$4;
	long w, h;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dstHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 179 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_3$$4, "nc/image/imagick.zep", 183 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (h < 1) {
		h = w;
	}
	ZEPHIR_INIT_VAR(&dstHandler);
	object_init_ex(&dstHandler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "addimage", NULL, 0, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, w);
	ZVAL_LONG(&_7, h);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "cropthumbnailimage", NULL, 0, &_6, &_7);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &dstHandler, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, crop) {

	zend_bool _3, _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, dstHandler, _0, _8, _9, _13, _14, _15, _16, _17, _1$$3, _2$$3, _4$$4, _5$$4, _6$$5, _7$$5, _11$$7, _12$$7;
	long x, y, w, h, oriW = 0, oriH = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dstHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 202 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_4$$4, "nc/image/imagick.zep", 206 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_6$$5, "nc/image/imagick.zep", 210 TSRMLS_CC);
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
		zephir_throw_exception_debug(&_11$$7, "nc/image/imagick.zep", 221 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&dstHandler);
	object_init_ex(&dstHandler, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "addimage", NULL, 0, &_13);
	zephir_check_call_status();
	ZVAL_LONG(&_14, w);
	ZVAL_LONG(&_15, h);
	ZVAL_LONG(&_16, x);
	ZVAL_LONG(&_17, y);
	ZEPHIR_CALL_METHOD(NULL, &dstHandler, "cropimage", NULL, 0, &_14, &_15, &_16, &_17);
	zephir_check_call_status();
	zephir_read_property(&_14, this_ptr, SL("extension"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newimage", NULL, 0, &dstHandler, &_14);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, paste) {

	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval *im, im_sub, *x_param = NULL, *y_param = NULL, srcIm, dstIm, paintingArea, _0, _3, _10, _11, _12, _13, _14, _15, _1$$3, _2$$3, _4$$6, _5$$6, _6$$7, _7$$7, _8$$7, _9$$7, _16$$8, _17$$8;
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);

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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 236 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_instance_of_ev(im, nc_image_imagick_ce TSRMLS_CC)) {
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
		zephir_throw_exception_debug(&_4$$6, "nc/image/imagick.zep", 246 TSRMLS_CC);
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
	zephir_read_property(&_12, &srcIm, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_13, 54);
	ZVAL_LONG(&_14, x);
	ZVAL_LONG(&_15, y);
	ZEPHIR_CALL_METHOD(&_11, &_10, "compositeimage", NULL, 0, &_12, &_13, &_14, &_15);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_11))) {
		ZEPHIR_INIT_VAR(&_16$$8);
		object_init_ex(&_16$$8, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_17$$8);
		ZVAL_STRING(&_17$$8, "paste");
		ZEPHIR_CALL_METHOD(NULL, &_16$$8, "__construct", NULL, 3, &_17$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_16$$8, "nc/image/imagick.zep", 258 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(dstIm);

}

PHP_METHOD(Nc_Image_Imagick, annotate) {

	int ZEPHIR_LAST_CALL_STATUS;
	long x, y;
	zval options, _3;
	zval *text_param = NULL, *options_param = NULL, *x_param = NULL, *y_param = NULL, dstIm, dstHandler, mo, textArea, paintingArea, imagickDraw, _0, _4, _5, _6, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _32, _33, _34, _35, _37, _38, _39, _1$$3, _2$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _12$$4, _13$$5, _14$$5, _25$$6, _26$$6, _27$$6, _28$$6, _29$$6, _30$$7, _31$$7, _36$$8, _40$$9, _41$$9;
	zval text;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&dstIm);
	ZVAL_UNDEF(&dstHandler);
	ZVAL_UNDEF(&mo);
	ZVAL_UNDEF(&textArea);
	ZVAL_UNDEF(&paintingArea);
	ZVAL_UNDEF(&imagickDraw);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
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
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 269 TSRMLS_CC);
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
	zephir_array_fetch_string(&_4, &mo, SL("font"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 284 TSRMLS_CC);
	zephir_array_fetch_string(&_5, &mo, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 284 TSRMLS_CC);
	zephir_array_fetch_string(&_6, &mo, SL("padding"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 284 TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(&imagickDraw);
	object_init_ex(&imagickDraw, zephir_get_internal_ce(SL("imagickdraw")));
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "__construct", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_15, 96);
	ZVAL_LONG(&_16, 96);
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setresolution", NULL, 0, &_15, &_16);
	zephir_check_call_status();
	zephir_array_fetch_string(&_17, &mo, SL("font"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 297 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_18, "realpath", NULL, 91, &_17);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setfont", NULL, 0, &_18);
	zephir_check_call_status();
	zephir_array_fetch_string(&_19, &mo, SL("fontSize"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 298 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setfontsize", NULL, 0, &_19);
	zephir_check_call_status();
	zephir_array_fetch_string(&_20, &mo, SL("opacity"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 299 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setfillopacity", NULL, 0, &_20);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_21);
	ZEPHIR_INIT_VAR(&_22);
	zephir_array_fetch_string(&_23, &mo, SL("shadowColor"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 301 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_24);
	ZVAL_STRING(&_24, "/^#[0-9a-fA-F]{6}$/");
	zephir_preg_match(&_22, &_24, &_23, &_21, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_22)) {
		zephir_array_fetch_string(&_25$$6, &mo, SL("shadowColor"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 302 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setfillcolor", NULL, 0, &_25$$6);
		zephir_check_call_status();
		ZVAL_LONG(&_27$$6, (x + 1));
		ZVAL_LONG(&_28$$6, (y + 1));
		ZVAL_LONG(&_29$$6, 0);
		ZEPHIR_CALL_METHOD(&_26$$6, &dstHandler, "annotateimage", NULL, 0, &imagickDraw, &_27$$6, &_28$$6, &_29$$6, &text);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(&_26$$6))) {
			ZEPHIR_INIT_VAR(&_30$$7);
			object_init_ex(&_30$$7, nc_image_exception_ce);
			ZEPHIR_INIT_VAR(&_31$$7);
			ZVAL_STRING(&_31$$7, "annotate");
			ZEPHIR_CALL_METHOD(NULL, &_30$$7, "__construct", NULL, 3, &_31$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_30$$7, "nc/image/imagick.zep", 304 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_32);
	ZEPHIR_INIT_VAR(&_33);
	zephir_array_fetch_string(&_34, &mo, SL("color"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 308 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_35);
	ZVAL_STRING(&_35, "/^#[0-9a-fA-F]{6}$/");
	zephir_preg_match(&_33, &_35, &_34, &_32, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(&_33))) {
		ZEPHIR_INIT_VAR(&_36$$8);
		ZVAL_STRING(&_36$$8, "#000000");
		zephir_array_update_string(&mo, SL("color"), &_36$$8, PH_COPY | PH_SEPARATE);
	}
	zephir_array_fetch_string(&_37, &mo, SL("color"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 312 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setfillcolor", NULL, 0, &_37);
	zephir_check_call_status();
	ZVAL_LONG(&_15, x);
	ZVAL_LONG(&_16, y);
	ZVAL_LONG(&_39, 0);
	ZEPHIR_CALL_METHOD(&_38, &dstHandler, "annotateimage", NULL, 0, &imagickDraw, &_15, &_16, &_39, &text);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_38))) {
		ZEPHIR_INIT_VAR(&_40$$9);
		object_init_ex(&_40$$9, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_41$$9);
		ZVAL_STRING(&_41$$9, "annotate");
		ZEPHIR_CALL_METHOD(NULL, &_40$$9, "__construct", NULL, 3, &_41$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_40$$9, "nc/image/imagick.zep", 314 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(dstIm);

}

PHP_METHOD(Nc_Image_Imagick, queryTextArea) {

	int ZEPHIR_LAST_CALL_STATUS;
	long fontSize, padding, x = 0, y = 0, w = 0, h = 0;
	zval *text_param = NULL, *font_param = NULL, *fontSize_param = NULL, *padding_param = NULL, testF, testW, testH, imagickDraw, imagick, page, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zval text, font;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&font);
	ZVAL_UNDEF(&testF);
	ZVAL_UNDEF(&testW);
	ZVAL_UNDEF(&testH);
	ZVAL_UNDEF(&imagickDraw);
	ZVAL_UNDEF(&imagick);
	ZVAL_UNDEF(&page);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);

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


	ZEPHIR_INIT_VAR(&testF);
	ZVAL_LONG(&testF, (fontSize * 2));
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "UTF-8");
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strlen", NULL, 92, &text, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&testW);
	ZVAL_LONG(&testW, (zephir_get_numberval(&testF) * (zephir_get_numberval(&_1) + 2)));
	ZEPHIR_INIT_VAR(&testH);
	ZVAL_LONG(&testH, (zephir_get_numberval(&testF) * 2));
	ZEPHIR_INIT_VAR(&imagickDraw);
	object_init_ex(&imagickDraw, zephir_get_internal_ce(SL("imagickdraw")));
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "__construct", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 96);
	ZVAL_LONG(&_3, 96);
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setresolution", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "realpath", NULL, 91, &font);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setfont", NULL, 0, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_2, fontSize);
	ZEPHIR_CALL_METHOD(NULL, &imagickDraw, "setfontsize", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&imagick);
	object_init_ex(&imagick, zephir_get_internal_ce(SL("imagick")));
	ZEPHIR_CALL_METHOD(NULL, &imagick, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "transparent");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "png");
	ZEPHIR_CALL_METHOD(NULL, &imagick, "newimage", NULL, 0, &testW, &testH, &_0, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &imagick, "annotateimage", NULL, 0, &imagickDraw, &testF, &testF, &_2, &text);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &imagick, "trimimage", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&page, &imagick, "getimagepage", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, &page, SL("x"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 339 TSRMLS_CC);
	x = (((padding + zephir_get_numberval(&testF)) - zephir_get_numberval(&_6)));
	zephir_array_fetch_string(&_7, &page, SL("y"), PH_NOISY | PH_READONLY, "nc/image/imagick.zep", 340 TSRMLS_CC);
	y = (((padding + zephir_get_numberval(&testF)) - zephir_get_numberval(&_7)));
	ZEPHIR_CALL_METHOD(&_8, &imagick, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	w = ((padding * 2) + zephir_get_numberval(&_8));
	ZEPHIR_CALL_METHOD(&_9, &imagick, "getimageheight", NULL, 0);
	zephir_check_call_status();
	h = ((padding * 2) + zephir_get_numberval(&_9));
	ZEPHIR_CALL_METHOD(NULL, &imagick, "clear", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, nc_image_area_ce);
	ZVAL_LONG(&_2, x);
	ZVAL_LONG(&_3, y);
	ZVAL_LONG(&_10, w);
	ZVAL_LONG(&_11, h);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 16, &_2, &_3, &_10, &_11);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Image_Imagick, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _3, _4, _1$$3, _2$$3, _5$$4, _6$$4;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

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
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 352 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "writeimage", NULL, 0, &path);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_4))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "save");
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 3, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "nc/image/imagick.zep", 356 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Imagick, toString) {

	zval _5;
	zval _0, _3, _4, _1$$3, _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "toString");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 363 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "getimageblob", NULL, 0);
	zephir_check_call_status();
	zephir_get_strval(&_5, &_4);
	RETURN_CTOR(_5);

}

PHP_METHOD(Nc_Image_Imagick, __destruct) {

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
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "clear", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_NULL();

}

PHP_METHOD(Nc_Image_Imagick, newImage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, *extension, extension_sub, im, _0, _3, _4, _5, _1$$3, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&extension_sub);
	ZVAL_UNDEF(&im);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler, &extension);



	ZEPHIR_CALL_METHOD(&_0, handler, "setimageformat", NULL, 0, extension);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_image_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "newImage");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/image/imagick.zep", 385 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&im, this_ptr, "newinstance", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(&im, SL("handler"), handler);
	ZEPHIR_CALL_METHOD(&_3, handler, "getimagewidth", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(&im, SL("width"), &_3);
	ZEPHIR_CALL_METHOD(&_4, handler, "getimageheight", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(&im, SL("height"), &_4);
	zephir_update_property_zval(&im, SL("extension"), extension);
	ZEPHIR_CALL_METHOD(&_5, handler, "getimagemimetype", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(&im, SL("mimeType"), &_5);
	RETURN_CCTOR(im);

}

