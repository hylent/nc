
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Application_ControllerAbstractHttp) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Application, ControllerAbstractHttp, nc, application_controllerabstracthttp, nc_application_controllerabstract_ce, nc_application_controllerabstracthttp_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Nc_Application_ControllerAbstractHttp, getRequest) {

	zval *name_param = NULL, *defaultValue = NULL, *_REQUEST, *value = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(name, name_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_fetch(&value, _REQUEST, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Application_ControllerAbstractHttp, getQuery) {

	zval *name_param = NULL, *defaultValue = NULL, *_GET, *value = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(name, name_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_fetch(&value, _GET, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Application_ControllerAbstractHttp, getPost) {

	zval *name_param = NULL, *defaultValue = NULL, *_POST, *value = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(name, name_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_fetch(&value, _POST, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Application_ControllerAbstractHttp, getCookie) {

	zval *name_param = NULL, *defaultValue = NULL, *_COOKIE, *value = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(name, name_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_fetch(&value, _COOKIE, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Application_ControllerAbstractHttp, newUploadedFile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *error, *size, *name, *tmpName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &error, &size, &name, &tmpName);



	object_init_ex(return_value, nc_application_uploadedfile_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 32, error, size, name, tmpName);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Application_ControllerAbstractHttp, hasUploadedFile) {

	zval *index_param = NULL, *_FILES;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	RETURN_MM_BOOL(zephir_array_isset(_FILES, index));

}

PHP_METHOD(Nc_Application_ControllerAbstractHttp, getUploadedFile) {

	zend_bool _0$$3, _1$$3, _2$$3, _3$$3, _4$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *_FILES, *a = NULL, *error = NULL, *size = NULL, *name = NULL, *tmpName = NULL, *_6;
	zval *index = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	while (1) {
		ZEPHIR_OBS_NVAR(a);
		_0$$3 = !(zephir_array_isset_fetch(&a, _FILES, index, 0 TSRMLS_CC));
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(a) != IS_ARRAY;
		}
		if (unlikely(_0$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(error);
		_1$$3 = !(zephir_array_isset_string_fetch(&error, a, SS("error"), 0 TSRMLS_CC));
		if (!(_1$$3)) {
			_1$$3 = Z_TYPE_P(error) != IS_LONG;
		}
		if (unlikely(_1$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(size);
		_2$$3 = !(zephir_array_isset_string_fetch(&size, a, SS("size"), 0 TSRMLS_CC));
		if (!(_2$$3)) {
			_2$$3 = Z_TYPE_P(size) != IS_LONG;
		}
		if (unlikely(_2$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(name);
		_3$$3 = !(zephir_array_isset_string_fetch(&name, a, SS("name"), 0 TSRMLS_CC));
		if (!(_3$$3)) {
			_3$$3 = Z_TYPE_P(name) != IS_STRING;
		}
		if (unlikely(_3$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(tmpName);
		_4$$3 = !(zephir_array_isset_string_fetch(&tmpName, a, SS("tmp_name"), 0 TSRMLS_CC));
		if (!(_4$$3)) {
			_4$$3 = Z_TYPE_P(tmpName) != IS_STRING;
		}
		if (unlikely(_4$$3)) {
			break;
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newuploadedfile", &_5, 0, error, size, name, tmpName);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_6);
	object_init_ex(_6, nc_application_exception_ce);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SV(_7, "Invalid uploaded file: ", index);
	ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 2, _7);
	zephir_check_call_status();
	zephir_throw_exception_debug(_6, "nc/application/controllerabstracthttp.zep", 84 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Application_ControllerAbstractHttp, getUploadedFiles) {

	HashTable *_3;
	HashPosition _2;
	zend_bool _0, _1, _6$$5, _8$$5, _10$$5;
	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *_FILES, *files = NULL, *a = NULL, *errors = NULL, *i = NULL, *error = NULL, *size = NULL, *name = NULL, *tmpName = NULL, **_4, *_5$$5, *_7$$5, *_9$$5, *_11$$5 = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_INIT_VAR(files);
	array_init(files);
	ZEPHIR_OBS_VAR(a);
	_0 = !(zephir_array_isset_fetch(&a, _FILES, index, 0 TSRMLS_CC));
	if (_0) {
		_0 = Z_TYPE_P(a) != IS_ARRAY;
	}
	if (unlikely(_0)) {
		RETURN_CCTOR(files);
	}
	ZEPHIR_OBS_VAR(errors);
	_1 = !(zephir_array_isset_string_fetch(&errors, a, SS("error"), 0 TSRMLS_CC));
	if (_1) {
		_1 = Z_TYPE_P(errors) != IS_ARRAY;
	}
	if (unlikely(_1)) {
		RETURN_CCTOR(files);
	}
	zephir_is_iterable(errors, &_3, &_2, 0, 0, "nc/application/controllerabstracthttp.zep", 113);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(i, _3, _2);
		ZEPHIR_GET_HVALUE(error, _4);
		ZEPHIR_OBS_NVAR(size);
		zephir_array_fetch_string(&_5$$5, a, SL("size"), PH_READONLY, "nc/application/controllerabstracthttp.zep", 100 TSRMLS_CC);
		_6$$5 = !(zephir_array_isset_fetch(&size, _5$$5, i, 0 TSRMLS_CC));
		if (!(_6$$5)) {
			_6$$5 = Z_TYPE_P(size) != IS_LONG;
		}
		if (unlikely(_6$$5)) {
			continue;
		}
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch_string(&_7$$5, a, SL("name"), PH_READONLY, "nc/application/controllerabstracthttp.zep", 103 TSRMLS_CC);
		_8$$5 = !(zephir_array_isset_fetch(&name, _7$$5, i, 0 TSRMLS_CC));
		if (!(_8$$5)) {
			_8$$5 = Z_TYPE_P(name) != IS_STRING;
		}
		if (unlikely(_8$$5)) {
			continue;
		}
		ZEPHIR_OBS_NVAR(tmpName);
		zephir_array_fetch_string(&_9$$5, a, SL("tmp_name"), PH_READONLY, "nc/application/controllerabstracthttp.zep", 106 TSRMLS_CC);
		_10$$5 = !(zephir_array_isset_fetch(&tmpName, _9$$5, i, 0 TSRMLS_CC));
		if (!(_10$$5)) {
			_10$$5 = Z_TYPE_P(tmpName) != IS_STRING;
		}
		if (unlikely(_10$$5)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "newuploadedfile", &_12, 0, error, size, name, tmpName);
		zephir_check_call_status();
		zephir_array_update_zval(&files, i, &_11$$5, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(files);

}

