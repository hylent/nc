
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
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Image_Backend_ImageBackendAdapter) {

	ZEPHIR_REGISTER_CLASS(Nc\\Image\\Backend, ImageBackendAdapter, nc, image_backend_imagebackendadapter, nc_image_backend_imagebackendadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_image_backend_imagebackendadapter_ce, SL("defaults"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_image_backend_imagebackendadapter_ce TSRMLS_CC, 1, nc_image_backend_imagebackendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Image_Backend_ImageBackendAdapter, setDefaults) {

	HashTable *_1;
	HashPosition _0;
	zval *options_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	zephir_is_iterable(options, &_1, &_0, 0, 0, "nc/image/backend/imagebackendadapter.zep", 14);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_update_property_array(this_ptr, SL("defaults"), k, v TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Backend_ImageBackendAdapter, setDefault) {

	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("defaults"), name, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Backend_ImageBackendAdapter, validTextOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_15 = NULL, *_18 = NULL;
	zend_bool _13;
	double d;
	long l;
	zval *s = NULL, *_10 = NULL, *_12 = NULL;
	zval *options_param = NULL, *valid, *merged = NULL, *v = NULL, *m = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_11 = NULL, *_14 = NULL, *_16, *_17 = NULL, *_19, *_20 = NULL, *_21, *_22, *_23 = NULL, *_24;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);
	ZEPHIR_INIT_VAR(valid);
	array_init(valid);
	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("defaults"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(merged);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
		zephir_fast_array_merge(merged, &(_1), &(options) TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(merged, options);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "nc.ttf", 1);
	zephir_array_update_string(&valid, SL("font"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 24);
	zephir_array_update_string(&valid, SL("fontSize"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "#000000", 1);
	zephir_array_update_string(&valid, SL("color"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 0);
	zephir_array_update_string(&valid, SL("red"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 0);
	zephir_array_update_string(&valid, SL("green"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 0);
	zephir_array_update_string(&valid, SL("blue"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_DOUBLE(_8, 0.5);
	zephir_array_update_string(&valid, SL("opacity"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 5);
	zephir_array_update_string(&valid, SL("padding"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("font"), 0 TSRMLS_CC)) {
		zephir_get_strval(_10, v);
		ZEPHIR_CPY_WRT(s, _10);
		if (s && Z_STRLEN_P(s)) {
			zephir_array_update_string(&valid, SL("font"), &s, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("fontSize"), 0 TSRMLS_CC)) {
		l = zephir_get_intval(v);
		if (l > 7) {
			ZEPHIR_INIT_VAR(_11);
			ZVAL_LONG(_11, l);
			zephir_array_update_string(&valid, SL("fontSize"), &_11, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("color"), 0 TSRMLS_CC)) {
		zephir_get_strval(_12, v);
		ZEPHIR_CPY_WRT(s, _12);
		_13 = zephir_is_true(s);
		if (_13) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", ZEPHIR_TEMP_PARAM_COPY);
			Z_SET_ISREF_P(m);
			ZEPHIR_CALL_FUNCTION(&_14, "preg_match", &_15, _11, s, m);
			zephir_check_temp_parameter(_11);
			Z_UNSET_ISREF_P(m);
			zephir_check_call_status();
			_13 = zephir_is_true(_14);
		}
		if (_13) {
			zephir_array_update_string(&valid, SL("color"), &s, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_long(&_16, m, 1, PH_NOISY | PH_READONLY, "nc/image/backend/imagebackendadapter.zep", 59 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_17, "hexdec", &_18, _16);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_LONG(_11, zephir_get_intval(_17));
			zephir_array_update_string(&valid, SL("red"), &_11, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_long(&_19, m, 2, PH_NOISY | PH_READONLY, "nc/image/backend/imagebackendadapter.zep", 60 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_20, "hexdec", &_18, _19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_21);
			ZVAL_LONG(_21, zephir_get_intval(_20));
			zephir_array_update_string(&valid, SL("green"), &_21, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_long(&_22, m, 3, PH_NOISY | PH_READONLY, "nc/image/backend/imagebackendadapter.zep", 61 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_23, "hexdec", &_18, _22);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_24);
			ZVAL_LONG(_24, zephir_get_intval(_23));
			zephir_array_update_string(&valid, SL("blue"), &_24, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("opacity"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(v);
		_13 = d >= 0;
		if (_13) {
			_13 = d <= 1;
		}
		if (_13) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_DOUBLE(_11, d);
			zephir_array_update_string(&valid, SL("opacity"), &_11, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("padding"), 0 TSRMLS_CC)) {
		l = zephir_get_intval(v);
		if (l >= 0) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_LONG(_11, l);
			zephir_array_update_string(&valid, SL("padding"), &_11, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(valid);

}

PHP_METHOD(Nc_Image_Backend_ImageBackendAdapter, validCaptchaOptions) {

	zend_bool _6;
	double d;
	zval *s = NULL, *_5 = NULL;
	zval *options_param = NULL, *valid, *merged = NULL, *v = NULL, *_0, *_1, *_2, *_3, *_4, *_7 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);
	ZEPHIR_INIT_VAR(valid);
	array_init(valid);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("defaults"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(merged);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
		zephir_fast_array_merge(merged, &(_1), &(options) TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(merged, options);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "nc.ttf", 1);
	zephir_array_update_string(&valid, SL("font"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_DOUBLE(_3, 0.2);
	zephir_array_update_string(&valid, SL("rPadding"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_DOUBLE(_4, 0.2);
	zephir_array_update_string(&valid, SL("rOverlap"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("font"), 0 TSRMLS_CC)) {
		zephir_get_strval(_5, v);
		ZEPHIR_CPY_WRT(s, _5);
		if (s && Z_STRLEN_P(s)) {
			zephir_array_update_string(&valid, SL("font"), &s, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("rPadding"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(v);
		_6 = d > 0;
		if (_6) {
			_6 = d < 1;
		}
		if (_6) {
			ZEPHIR_INIT_VAR(_7);
			ZVAL_DOUBLE(_7, d);
			zephir_array_update_string(&valid, SL("rPadding"), &_7, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("rOverlap"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(v);
		_6 = d > 0;
		if (_6) {
			_6 = d < 1;
		}
		if (_6) {
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_DOUBLE(_7, d);
			zephir_array_update_string(&valid, SL("rOverlap"), &_7, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(valid);

}

