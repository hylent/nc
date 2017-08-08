
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


ZEPHIR_INIT_CLASS(Nc_Mvc_ControllerCliSwoole) {

	ZEPHIR_REGISTER_CLASS(Nc\\Mvc, ControllerCliSwoole, nc, mvc_controllercliswoole, nc_mvc_controllercliswoole_method_entry, 0);

	zend_class_implements(nc_mvc_controllercliswoole_ce TSRMLS_CC, 1, nc_mvc_controllerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_ControllerCliSwoole, __invoke) {

	zval _9, _13;
	zend_bool _5, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *injector, injector_sub, *context, context_sub, dbg, obj, opts, serv, _0, _1, _2, _3, _4, _10, _11, _12, _7$$4, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injector_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&dbg);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&serv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &injector, &context);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "swoole");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 29, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_mvc_exception_ce, "ExtensionMissing swoole", "nc/mvc/controllercliswoole.zep", 12);
		return;
	}
	ZVAL_LONG(&_2, (2 | 1));
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_FUNCTION(&dbg, "debug_backtrace", NULL, 113, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&obj);
	zephir_array_fetch_long(&_4, &dbg, 1, PH_READONLY, "nc/mvc/controllercliswoole.zep", 16 TSRMLS_CC);
	_5 = !(zephir_array_isset_string_fetch(&obj, &_4, SL("object"), 0));
	if (!(_5)) {
		_5 = Z_TYPE_P(&obj) != IS_OBJECT;
	}
	_6 = _5;
	if (!(_6)) {
		_6 = !((zephir_instance_of_ev(&obj, nc_mvc_application_ce TSRMLS_CC)));
	}
	if (UNEXPECTED(_6)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		object_init_ex(&_7$$4, nc_mvc_exception_ce);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "__invoke");
		ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 3, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$4, "nc/mvc/controllercliswoole.zep", 17 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_9, SL("host"), SL("127.0.0.1"));
	add_assoc_long_ex(&_9, SL("port"), 9527);
	add_assoc_long_ex(&_9, SL("daemonize"), 1);
	add_assoc_long_ex(&_9, SL("max_request"), 32);
	ZEPHIR_CALL_METHOD(&_10, context, "getparammap", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&opts);
	zephir_fast_array_merge(&opts, &_9, &_10 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&serv);
	object_init_ex(&serv, zephir_get_internal_ce(SL("swoole_http_server")));
	zephir_array_fetch_string(&_11, &opts, SL("host"), PH_NOISY | PH_READONLY, "nc/mvc/controllercliswoole.zep", 30 TSRMLS_CC);
	zephir_array_fetch_string(&_12, &opts, SL("port"), PH_NOISY | PH_READONLY, "nc/mvc/controllercliswoole.zep", 30 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &serv, "__construct", NULL, 0, &_11, &_12);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &serv, "set", NULL, 0, &opts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_13, &obj);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "onSwooleRequest");
	zephir_array_fast_append(&_13, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "request");
	ZEPHIR_CALL_METHOD(NULL, &serv, "on", NULL, 0, &_0, &_13);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &serv, "start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

