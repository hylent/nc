
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
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_ContextHttpSwoole) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Mvc, ContextHttpSwoole, nc, mvc_contexthttpswoole, nc_mvc_contexthttp_ce, nc_mvc_contexthttpswoole_method_entry, 0);

	zend_declare_property_null(nc_mvc_contexthttpswoole_ce, SL("swooleRequest"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_contexthttpswoole_ce, SL("swooleResponse"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, __construct) {

	zend_string *_6$$4, *_11$$6;
	zend_ulong _5$$4, _10$$6;
	zend_bool _3, _8, _18, _20, _22, _24;
	zephir_fcall_cache_entry *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *swooleRequest, swooleRequest_sub, *swooleResponse, swooleResponse_sub, _SERVER, a, k, v, _0, _1, _2, *_4$$4, _7$$5, *_9$$6, _12$$7, _13$$7, _14$$7, _15$$7, _17$$7, _19$$9, _21$$11, _23$$13, _25$$15;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&swooleRequest_sub);
	ZVAL_UNDEF(&swooleResponse_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_25$$15);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 2, 0, &swooleRequest, &swooleResponse);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "swoole");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 28, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_mvc_exception_ce, "ExtensionMissing swoole", "nc/mvc/contexthttpswoole.zep", 13);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("swooleRequest"), swooleRequest);
	zephir_update_property_zval(this_ptr, SL("swooleResponse"), swooleResponse);
	zephir_update_property_zval(this_ptr, SL("serverVars"), &_SERVER);
	zephir_read_property(&_2, swooleRequest, SL("fd"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SWOOLE_FD");
	zephir_update_property_array(this_ptr, SL("serverVars"), &_0, &_2 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&a);
	_3 = zephir_fetch_property(&a, swooleRequest, SL("server"), PH_SILENT_CC);
	if (_3) {
		_3 = Z_TYPE_P(&a) == IS_ARRAY;
	}
	if (_3) {
		zephir_is_iterable(&a, 0, "nc/mvc/contexthttpswoole.zep", 26);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&a), _5$$4, _6$$4, _4$$4)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_6$$4 != NULL) { 
				ZVAL_STR_COPY(&k, _6$$4);
			} else {
				ZVAL_LONG(&k, _5$$4);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _4$$4);
			ZEPHIR_INIT_NVAR(&_7$$5);
			zephir_fast_strtoupper(&_7$$5, &k);
			zephir_update_property_array(this_ptr, SL("serverVars"), &_7$$5, &v TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
	}
	ZEPHIR_OBS_NVAR(&a);
	_8 = zephir_fetch_property(&a, swooleRequest, SL("header"), PH_SILENT_CC);
	if (_8) {
		_8 = Z_TYPE_P(&a) == IS_ARRAY;
	}
	if (_8) {
		zephir_is_iterable(&a, 0, "nc/mvc/contexthttpswoole.zep", 31);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&a), _10$$6, _11$$6, _9$$6)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_11$$6 != NULL) { 
				ZVAL_STR_COPY(&k, _11$$6);
			} else {
				ZVAL_LONG(&k, _10$$6);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _9$$6);
			ZEPHIR_INIT_NVAR(&_12$$7);
			ZEPHIR_INIT_NVAR(&_13$$7);
			ZVAL_STRING(&_13$$7, "-");
			ZEPHIR_INIT_NVAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "_");
			ZEPHIR_CALL_FUNCTION(&_15$$7, "strtr", &_16, 97, &k, &_13$$7, &_14$$7);
			zephir_check_call_status();
			zephir_fast_strtoupper(&_12$$7, &_15$$7);
			ZEPHIR_INIT_LNVAR(_17$$7);
			ZEPHIR_CONCAT_SV(&_17$$7, "HTTP_", &_12$$7);
			zephir_update_property_array(this_ptr, SL("serverVars"), &_17$$7, &v TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
	}
	ZEPHIR_OBS_NVAR(&a);
	_18 = zephir_fetch_property(&a, swooleRequest, SL("get"), PH_SILENT_CC);
	if (_18) {
		_18 = Z_TYPE_P(&a) == IS_ARRAY;
	}
	if (_18) {
		zephir_update_property_zval(this_ptr, SL("queries"), &a);
	} else {
		ZEPHIR_INIT_VAR(&_19$$9);
		array_init(&_19$$9);
		zephir_update_property_zval(this_ptr, SL("queries"), &_19$$9);
	}
	ZEPHIR_OBS_NVAR(&a);
	_20 = zephir_fetch_property(&a, swooleRequest, SL("post"), PH_SILENT_CC);
	if (_20) {
		_20 = Z_TYPE_P(&a) == IS_ARRAY;
	}
	if (_20) {
		zephir_update_property_zval(this_ptr, SL("posts"), &a);
	} else {
		ZEPHIR_INIT_VAR(&_21$$11);
		array_init(&_21$$11);
		zephir_update_property_zval(this_ptr, SL("posts"), &_21$$11);
	}
	ZEPHIR_OBS_NVAR(&a);
	_22 = zephir_fetch_property(&a, swooleRequest, SL("cookie"), PH_SILENT_CC);
	if (_22) {
		_22 = Z_TYPE_P(&a) == IS_ARRAY;
	}
	if (_22) {
		zephir_update_property_zval(this_ptr, SL("cookies"), &a);
	} else {
		ZEPHIR_INIT_VAR(&_23$$13);
		array_init(&_23$$13);
		zephir_update_property_zval(this_ptr, SL("cookies"), &_23$$13);
	}
	ZEPHIR_OBS_NVAR(&a);
	_24 = zephir_fetch_property(&a, swooleRequest, SL("files"), PH_SILENT_CC);
	if (_24) {
		_24 = Z_TYPE_P(&a) == IS_ARRAY;
	}
	if (_24) {
		zephir_update_property_zval(this_ptr, SL("files"), &a);
	} else {
		ZEPHIR_INIT_VAR(&_25$$15);
		array_init(&_25$$15);
		zephir_update_property_zval(this_ptr, SL("files"), &_25$$15);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initargvectorfromrequesturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, getRoutingNames) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "http.swoole");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "http");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, getSwooleRequest) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "swooleRequest");

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, getSwooleResponse) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "swooleResponse");

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, getRawInput) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("swooleRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "rawcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, startSession) {

	zval _1$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sessionIdGenerator = NULL, sessionIdGenerator_sub, __$null, sessName, id, _0$$4, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sessionIdGenerator_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sessName);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sessionIdGenerator);

	if (!sessionIdGenerator) {
		sessionIdGenerator = &sessionIdGenerator_sub;
		sessionIdGenerator = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&sessName, "session_name", NULL, 112);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&id, this_ptr, "getcookie", NULL, 0, &sessName);
	zephir_check_call_status();
	if (Z_TYPE_P(&id) == IS_NULL) {
		if (Z_TYPE_P(sessionIdGenerator) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZEPHIR_CALL_USER_FUNC(&_0$$4, sessionIdGenerator);
			zephir_check_call_status();
			zephir_get_strval(&_1$$4, &_0$$4);
			ZEPHIR_CPY_WRT(&id, &_1$$4);
		}
		if (zephir_fast_strlen_ev(&id) < 1) {
			ZEPHIR_CALL_SELF(&id, "generatesessionid", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(&_2$$3, "session_get_cookie_params", NULL, 113);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cookie", NULL, 0, &sessName, &id, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 21, &id);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 22);
	zephir_check_call_status();
	RETURN_CCTOR(id);

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, status) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *status_param = NULL, _0, _1;
	long status;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &status_param);

	status = zephir_get_intval(status_param);


	zephir_read_property(&_0, this_ptr, SL("swooleResponse"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, status);
	ZEPHIR_CALL_METHOD(NULL, &_0, "status", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, cookie) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *name_param = NULL, *value_param = NULL, *options_param = NULL, a, _0, _1, _2, _3, _4, _5, _6;
	zval name, value;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
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
	zephir_read_property(&_1, this_ptr, SL("swooleResponse"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &a, SL("lifetime"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttpswoole.zep", 113 TSRMLS_CC);
	zephir_array_fetch_string(&_3, &a, SL("path"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttpswoole.zep", 113 TSRMLS_CC);
	zephir_array_fetch_string(&_4, &a, SL("domain"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttpswoole.zep", 113 TSRMLS_CC);
	zephir_array_fetch_string(&_5, &a, SL("secure"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttpswoole.zep", 113 TSRMLS_CC);
	zephir_array_fetch_string(&_6, &a, SL("httponly"), PH_NOISY | PH_READONLY, "nc/mvc/contexthttpswoole.zep", 113 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &_1, "cookie", NULL, 0, &name, &value, &_2, &_3, &_4, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, header) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, _0;
	zval name, value;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&value, value_param);


	zephir_read_property(&_0, this_ptr, SL("swooleResponse"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "header", NULL, 0, &name, &value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, sendFile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_read_property(&_0, this_ptr, SL("swooleResponse"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "sendfile", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, output) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, _0;
	zval content;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	zephir_read_property(&_0, this_ptr, SL("swooleResponse"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "write", NULL, 0, &content);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

