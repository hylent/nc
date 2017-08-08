
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
#include "kernel/time.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_ContextHttp) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Mvc, ContextHttp, nc, mvc_contexthttp, nc_mvc_contextabstract_ce, nc_mvc_contexthttp_method_entry, 0);

	zend_declare_property_null(nc_mvc_contexthttp_ce, SL("queries"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_contexthttp_ce, SL("posts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_contexthttp_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_contexthttp_ce, SL("files"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_contexthttp_ce, SL("defaultCookieOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_ContextHttp, generateSessionId) {

	zval __$true, _0, _1, _2, _3, _4, _5, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZEPHIR_CALL_FUNCTION(&_1, "mt_rand", NULL, 8);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "uniqid", NULL, 9, &_1, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "php_uname", NULL, 19);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_2, &_3);
	ZEPHIR_CALL_FUNCTION(&_5, "sha1", NULL, 10, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "%08x%s");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 2, &_6, &_0, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *_GET, *_POST, *_COOKIE, *_FILES;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	if (!_FILES) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (!_COOKIE) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_POST, SL("_POST"));
	if (!_POST) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_GET, SL("_GET"));
	if (!_GET) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_SERVER, SL("_SERVER"));
	if (!_SERVER) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}

	zephir_update_property_zval(this_ptr, SL("serverVars"), _SERVER);
	zephir_update_property_zval(this_ptr, SL("queries"), _GET);
	zephir_update_property_zval(this_ptr, SL("posts"), _POST);
	zephir_update_property_zval(this_ptr, SL("cookies"), _COOKIE);
	zephir_update_property_zval(this_ptr, SL("files"), _FILES);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initargvectorfromrequesturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttp, getRoutingNames) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "http");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, getRawInput) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://input");
	zephir_file_get_contents(return_value, &_0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, getParamMap) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("queries"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("posts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_replace", NULL, 20, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, getParam) {

	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_OBS_VAR(&value);
	zephir_read_property(&_0, this_ptr, SL("queries"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&value);
	}
	ZEPHIR_OBS_NVAR(&value);
	zephir_read_property(&_1, this_ptr, SL("posts"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_1, &name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, getQuery) {

	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("queries"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, getPost) {

	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("posts"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, getCookie) {

	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, newUploadedFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *error, error_sub, *size, size_sub, *name, name_sub, *tmpName, tmpName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&error_sub);
	ZVAL_UNDEF(&size_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&tmpName_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &error, &size, &name, &tmpName);



	object_init_ex(return_value, nc_mvc_uploadedfile_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, error, size, name, tmpName);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, hasUploadedFile) {

	zend_bool _2;
	zval *index_param = NULL, error, _0, _1;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_OBS_VAR(&error);
	zephir_read_property(&_0, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, &index, PH_READONLY, "nc/mvc/contexthttp.zep", 103 TSRMLS_CC);
	_2 = zephir_array_isset_string_fetch(&error, &_1, SL("error"), 0);
	if (_2) {
		_2 = zephir_is_numeric(&error);
	}
	RETURN_MM_BOOL(_2);

}

PHP_METHOD(Nc_Mvc_ContextHttp, getUploadedFile) {

	zend_bool _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, a, error, size, name, tmpName, _7, _8, _9, _0$$3;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tmpName);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	while (1) {
		ZEPHIR_OBS_NVAR(&a);
		zephir_read_property(&_0$$3, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
		_1$$3 = !(zephir_array_isset_fetch(&a, &_0$$3, &index, 0 TSRMLS_CC));
		if (!(_1$$3)) {
			_1$$3 = Z_TYPE_P(&a) != IS_ARRAY;
		}
		if (UNEXPECTED(_1$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(&error);
		_2$$3 = !(zephir_array_isset_string_fetch(&error, &a, SL("error"), 0));
		if (!(_2$$3)) {
			_2$$3 = Z_TYPE_P(&error) != IS_LONG;
		}
		if (UNEXPECTED(_2$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(&size);
		_3$$3 = !(zephir_array_isset_string_fetch(&size, &a, SL("size"), 0));
		if (!(_3$$3)) {
			_3$$3 = Z_TYPE_P(&size) != IS_LONG;
		}
		if (UNEXPECTED(_3$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(&name);
		_4$$3 = !(zephir_array_isset_string_fetch(&name, &a, SL("name"), 0));
		if (!(_4$$3)) {
			_4$$3 = Z_TYPE_P(&name) != IS_STRING;
		}
		if (UNEXPECTED(_4$$3)) {
			break;
		}
		ZEPHIR_OBS_NVAR(&tmpName);
		_5$$3 = !(zephir_array_isset_string_fetch(&tmpName, &a, SL("tmp_name"), 0));
		if (!(_5$$3)) {
			_5$$3 = Z_TYPE_P(&tmpName) != IS_STRING;
		}
		if (UNEXPECTED(_5$$3)) {
			break;
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newuploadedfile", &_6, 0, &error, &size, &name, &tmpName);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, nc_mvc_exception_ce);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "Invalid uploaded file '%s'");
	ZEPHIR_CALL_FUNCTION(&_9, "sprintf", NULL, 2, &_8, &index);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 3, &_9);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_7, "nc/mvc/contexthttp.zep", 131 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Mvc_ContextHttp, getUploadedFiles) {

	zend_string *_5;
	zend_ulong _4;
	zend_bool _1, _2, _7$$5, _9$$5, _11$$5;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, files, a, errors, i, error, size, name, tmpName, _0, *_3, _6$$5, _8$$5, _10$$5, _12$$5;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tmpName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_OBS_VAR(&a);
	zephir_read_property(&_0, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
	_1 = !(zephir_array_isset_fetch(&a, &_0, &index, 0 TSRMLS_CC));
	if (_1) {
		_1 = Z_TYPE_P(&a) != IS_ARRAY;
	}
	if (UNEXPECTED(_1)) {
		RETURN_CCTOR(&files);
	}
	ZEPHIR_OBS_VAR(&errors);
	_2 = !(zephir_array_isset_string_fetch(&errors, &a, SL("error"), 0));
	if (_2) {
		_2 = Z_TYPE_P(&errors) != IS_ARRAY;
	}
	if (UNEXPECTED(_2)) {
		RETURN_CCTOR(&files);
	}
	zephir_is_iterable(&errors, 0, "nc/mvc/contexthttp.zep", 160);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&errors), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&i);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&i, _5);
		} else {
			ZVAL_LONG(&i, _4);
		}
		ZEPHIR_INIT_NVAR(&error);
		ZVAL_COPY(&error, _3);
		ZEPHIR_OBS_NVAR(&size);
		zephir_array_fetch_string(&_6$$5, &a, SL("size"), PH_READONLY, "nc/mvc/contexthttp.zep", 147 TSRMLS_CC);
		_7$$5 = !(zephir_array_isset_fetch(&size, &_6$$5, &i, 0 TSRMLS_CC));
		if (!(_7$$5)) {
			_7$$5 = Z_TYPE_P(&size) != IS_LONG;
		}
		if (UNEXPECTED(_7$$5)) {
			continue;
		}
		ZEPHIR_OBS_NVAR(&name);
		zephir_array_fetch_string(&_8$$5, &a, SL("name"), PH_READONLY, "nc/mvc/contexthttp.zep", 150 TSRMLS_CC);
		_9$$5 = !(zephir_array_isset_fetch(&name, &_8$$5, &i, 0 TSRMLS_CC));
		if (!(_9$$5)) {
			_9$$5 = Z_TYPE_P(&name) != IS_STRING;
		}
		if (UNEXPECTED(_9$$5)) {
			continue;
		}
		ZEPHIR_OBS_NVAR(&tmpName);
		zephir_array_fetch_string(&_10$$5, &a, SL("tmp_name"), PH_READONLY, "nc/mvc/contexthttp.zep", 153 TSRMLS_CC);
		_11$$5 = !(zephir_array_isset_fetch(&tmpName, &_10$$5, &i, 0 TSRMLS_CC));
		if (!(_11$$5)) {
			_11$$5 = Z_TYPE_P(&tmpName) != IS_STRING;
		}
		if (UNEXPECTED(_11$$5)) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "newuploadedfile", &_13, 0, &error, &size, &name, &tmpName);
		zephir_check_call_status();
		zephir_array_update_zval(&files, &i, &_12$$5, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&error);
	ZEPHIR_INIT_NVAR(&i);
	RETURN_CCTOR(&files);

}

PHP_METHOD(Nc_Mvc_ContextHttp, getRequestMethod) {

	zval _3;
	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "REQUEST_METHOD");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "UNKNOWN");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservervar", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_get_strval(&_3, &_0);
	RETURN_CTOR(&_3);

}

PHP_METHOD(Nc_Mvc_ContextHttp, getRemoteAddr) {

	zval _3;
	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "REMOTE_ADDR");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "0.0.0.0");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservervar", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_get_strval(&_3, &_0);
	RETURN_CTOR(&_3);

}

PHP_METHOD(Nc_Mvc_ContextHttp, isXhr) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_X_REQUESTED_WITH");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservervar", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "XMLHttpRequest"));

}

PHP_METHOD(Nc_Mvc_ContextHttp, getHttpHost) {

	zval _2;
	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_HOST");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservervar", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_0);
	RETURN_CTOR(&_2);

}

PHP_METHOD(Nc_Mvc_ContextHttp, getHttpUserAgent) {

	zval _2;
	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_USER_AGENT");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservervar", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_0);
	RETURN_CTOR(&_2);

}

PHP_METHOD(Nc_Mvc_ContextHttp, getHttpReferer) {

	zval _2;
	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_REFERER");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservervar", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_0);
	RETURN_CTOR(&_2);

}

PHP_METHOD(Nc_Mvc_ContextHttp, setDefaultCookieOptions) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdefaultcookieoptions", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &options TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("defaultCookieOptions"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttp, getDefaultCookieOptions) {

	zval _1$$3;
	zval __$false, _0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("defaultCookieOptions"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 5, 0 TSRMLS_CC);
		add_assoc_long_ex(&_1$$3, SL("lifetime"), 0);
		add_assoc_stringl_ex(&_1$$3, SL("path"), SL("/"));
		add_assoc_stringl_ex(&_1$$3, SL("domain"), SL(""));
		zephir_array_update_string(&_1$$3, SL("secure"), &__$false, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1$$3, SL("httponly"), &__$false, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, SL("defaultCookieOptions"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "defaultCookieOptions");

}

PHP_METHOD(Nc_Mvc_ContextHttp, startSession) {

	zval _1$$3;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionIdGenerator = NULL, sessionIdGenerator_sub, __$null, id, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionIdGenerator_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sessionIdGenerator);

	if (!sessionIdGenerator) {
		sessionIdGenerator = &sessionIdGenerator_sub;
		sessionIdGenerator = &__$null;
	}


	if (Z_TYPE_P(sessionIdGenerator) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CALL_USER_FUNC(&_0$$3, sessionIdGenerator);
		zephir_check_call_status();
		zephir_get_strval(&_1$$3, &_0$$3);
		ZEPHIR_CPY_WRT(&id, &_1$$3);
		if (zephir_fast_strlen_ev(&id) > 0) {
			ZEPHIR_CALL_FUNCTION(NULL, "session_id", &_2, 22, &id);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "session_start", &_3, 23);
			zephir_check_call_status();
			RETURN_CCTOR(&id);
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_start", &_3, 23);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("session_id", &_2, 22);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttp, status) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *status_param = NULL, _0;
	long status;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &status_param);

	status = zephir_get_intval(status_param);


	ZVAL_LONG(&_0, status);
	ZEPHIR_CALL_FUNCTION(NULL, "http_response_code", NULL, 24, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttp, cookie) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *name_param = NULL, *value_param = NULL, *options_param = NULL, a, _0, _1, _2, _3, _4, _5;
	zval name, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &value_param, &options_param);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&value, value_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultcookieoptions", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&a);
	zephir_fast_array_merge(&a, &_0, &options TSRMLS_CC);
	zephir_array_fetch_string(&_1, &a, SL("lifetime"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttp.zep", 240 TSRMLS_CC);
	zephir_array_fetch_string(&_2, &a, SL("path"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttp.zep", 240 TSRMLS_CC);
	zephir_array_fetch_string(&_3, &a, SL("domain"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttp.zep", 240 TSRMLS_CC);
	zephir_array_fetch_string(&_4, &a, SL("secure"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttp.zep", 240 TSRMLS_CC);
	zephir_array_fetch_string(&_5, &a, SL("httponly"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttp.zep", 240 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 25, &name, &value, &_1, &_2, &_3, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttp, header) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL;
	zval name, value, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSV(&_0, &name, ": ", &value);
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 26, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttp, redirect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, _0;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Location");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "header", NULL, 0, &_0, &url);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttp, sendFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_CALL_FUNCTION(NULL, "readfile", NULL, 27, &path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttp, initArgVectorFromRequestUri) {

	zval _2, _5$$3;
	zval __$null, uri, pos, _0, _1, _6, _7, _8, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "REQUEST_URI");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservervar", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_0);
	ZEPHIR_CPY_WRT(&uri, &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "?");
	ZEPHIR_INIT_VAR(&pos);
	zephir_fast_strpos(&pos, &uri, &_1, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_substr(&_4$$3, &uri, 0 , zephir_get_intval(&pos), 0);
		zephir_get_strval(&_5$$3, &_4$$3);
		ZEPHIR_CPY_WRT(&uri, &_5$$3);
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "#/+#");
	ZVAL_LONG(&_7, 1);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_split", NULL, 28, &_6, &uri, &__$null, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("argVector"), &_8);
	ZEPHIR_MM_RESTORE();

}

