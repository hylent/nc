
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS(Nc\\Mvc, Application, nc, mvc_application, nc_mvc_application_method_entry, 0);

	zend_declare_property_null(nc_mvc_application_ce, SL("autoloads"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_application_ce, SL("routingRules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_Application, autoloadCompareFunction) {

	zval *a_param = NULL, *b_param = NULL;
	zval a, b;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&b);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a_param, &b_param);

	zephir_get_strval(&a, a_param);
	zephir_get_strval(&b, b_param);


	RETURN_MM_LONG((zephir_fast_strlen_ev(&b) - zephir_fast_strlen_ev(&a)));

}

PHP_METHOD(Nc_Mvc_Application, __construct) {

	zval _5$$4;
	zend_string *_2, *_10;
	zend_ulong _1, _9;
	zephir_fcall_cache_entry *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *autoloads_param = NULL, *routingRules_param = NULL, __$false, __$true, a, k, v, *_0, _7, *_8, _3$$3, _4$$3, _11$$5, _12$$5, _14$$6;
	zval autoloads, routingRules, _6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&autoloads);
	ZVAL_UNDEF(&routingRules);
	ZVAL_UNDEF(&_6);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &autoloads_param, &routingRules_param);

	zephir_get_arrval(&autoloads, autoloads_param);
	zephir_get_arrval(&routingRules, routingRules_param);


	ZEPHIR_INIT_VAR(&a);
	array_init(&a);
	zephir_is_iterable(&autoloads, 0, "nc/mvc/application.zep", 23);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&autoloads), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_fast_strtolower(&_3$$3, &k);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_VS(&_4$$3, &_3$$3, "\\");
		zephir_array_update_zval(&a, &_4$$3, &v, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	if (zephir_fast_count_int(&a TSRMLS_CC) > 1) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SS(&_5$$4, "Nc\\Mvc\\Application", "::autoloadCompareFunction");
		ZEPHIR_MAKE_REF(&a);
		ZEPHIR_CALL_FUNCTION(NULL, "uksort", NULL, 97, &a, &_5$$4);
		ZEPHIR_UNREF(&a);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("autoloads"), &a);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_6, this_ptr);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "autoload");
	zephir_array_fast_append(&_6, &_7);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 98, &_6, &__$false, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&a);
	array_init(&a);
	zephir_is_iterable(&routingRules, 0, "nc/mvc/application.zep", 34);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&routingRules), _9, _10, _8)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_10 != NULL) { 
			ZVAL_STR_COPY(&k, _10);
		} else {
			ZVAL_LONG(&k, _9);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _8);
		ZEPHIR_INIT_NVAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "/");
		ZEPHIR_CALL_FUNCTION(&_12$$5, "substr_count", &_13, 99, &k, &_11$$5);
		zephir_check_call_status();
		zephir_array_update_multi(&a, &v TSRMLS_CC, SL("zz"), 2, &_12$$5, &k);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	if (zephir_fast_count_int(&a TSRMLS_CC) > 1) {
		ZVAL_LONG(&_14$$6, 1);
		ZEPHIR_MAKE_REF(&a);
		ZEPHIR_CALL_FUNCTION(NULL, "krsort", NULL, 100, &a, &_14$$6);
		ZEPHIR_UNREF(&a);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("routingRules"), &a);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_Application, __destruct) {

	zval _1;
	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "autoload");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 101, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_Application, autoload) {

	zend_string *_5$$3;
	zend_ulong _4$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_12 = NULL;
	zval *name_param = NULL, lcName, p, d, path, _0, _1$$3, _2$$3, *_3$$3, _6$$4, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&lcName);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&d);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("autoloads"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strtolower(&_1$$3, &name);
		ZEPHIR_CPY_WRT(&lcName, &_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("autoloads"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_2$$3, 0, "nc/mvc/application.zep", 62);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2$$3), _4$$3, _5$$3, _3$$3)
		{
			ZEPHIR_INIT_NVAR(&p);
			if (_5$$3 != NULL) { 
				ZVAL_STR_COPY(&p, _5$$3);
			} else {
				ZVAL_LONG(&p, _4$$3);
			}
			ZEPHIR_INIT_NVAR(&d);
			ZVAL_COPY(&d, _3$$3);
			ZEPHIR_INIT_NVAR(&_6$$4);
			zephir_fast_strpos(&_6$$4, &lcName, &p, 0 );
			if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$4, 0)) {
				ZVAL_LONG(&_7$$5, zephir_fast_strlen_ev(&p));
				ZEPHIR_INIT_NVAR(&_8$$5);
				zephir_substr(&_8$$5, &name, zephir_get_intval(&_7$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_STRING(&_9$$5, "\\");
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "/");
				ZEPHIR_CALL_FUNCTION(&_11$$5, "strtr", &_12, 94, &_8$$5, &_9$$5, &_10$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&path);
				ZEPHIR_CONCAT_VSVS(&path, &d, "/", &_11$$5, ".php");
				if ((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)) {
					if (zephir_require_zval(&path TSRMLS_CC) == FAILURE) {
						RETURN_MM_NULL();
					}
					RETURN_MM_BOOL(1);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&d);
		ZEPHIR_INIT_NVAR(&p);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Mvc_Application, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL, context_sub, __$null, injector, controllerClass, _4, _5, _0$$3, _1$$6, _2$$6, _3$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&injector);
	ZVAL_UNDEF(&controllerClass);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &context);

	if (!context) {
		context = &context_sub;
		ZEPHIR_CPY_WRT(context, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(context);
	}


	if (Z_TYPE_P(context) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_GET_CONSTANT(&_0$$3, "PHP_SAPI");
		ZEPHIR_INIT_NVAR(context);
		if (ZEPHIR_IS_STRING(&_0$$3, "cli")) {
			object_init_ex(context, nc_mvc_contextcli_ce);
			ZEPHIR_CALL_METHOD(NULL, context, "__construct", NULL, 102);
			zephir_check_call_status();
		} else {
			object_init_ex(context, nc_mvc_contexthttp_ce);
			ZEPHIR_CALL_METHOD(NULL, context, "__construct", NULL, 103);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&controllerClass, this_ptr, "route", NULL, 0, context);
	zephir_check_call_status();
	if (zephir_fast_strlen_ev(&controllerClass) < 1) {
		ZEPHIR_INIT_VAR(&_1$$6);
		object_init_ex(&_1$$6, nc_mvc_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$6);
		ZVAL_STRING(&_2$$6, "__invoke");
		ZVAL_LONG(&_3$$6, 404);
		ZEPHIR_CALL_METHOD(NULL, &_1$$6, "__construct", NULL, 3, &_2$$6, &_3$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$6, "nc/mvc/application.zep", 83 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&injector);
	object_init_ex(&injector, nc_di_injector_ce);
	if (zephir_has_constructor(&injector TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &injector, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Nc\\Mvc\\ControllerInterface");
	ZEPHIR_CALL_METHOD(&_4, &injector, "__invoke", NULL, 104, &controllerClass, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__invoke", NULL, 0, &injector, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_Application, onSwooleRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *req, req_sub, *resp, resp_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&req_sub);
	ZVAL_UNDEF(&resp_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &req, &resp);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_mvc_contexthttpswoole_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 105, req, resp);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__invoke", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_Application, route) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context, context_sub, args, numArgs, routingNames, n, rules, uri, routingName, controllerClass, _0, _1$$3, *_2$$3, _5$$6, _6$$6, _7$$6, *_9$$4, _10$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&numArgs);
	ZVAL_UNDEF(&routingNames);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&rules);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routingName);
	ZVAL_UNDEF(&controllerClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &context);



	ZEPHIR_CALL_METHOD(&args, context, "getargvector", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&numArgs);
	ZVAL_LONG(&numArgs, zephir_fast_count_int(&args TSRMLS_CC));
	zephir_read_property(&_0, this_ptr, SL("routingRules"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&routingNames, context, "getroutingnames", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, SL("routingRules"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "nc/mvc/application.zep", 122);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$3), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&n);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&n, _4$$3);
			} else {
				ZVAL_LONG(&n, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&rules);
			ZVAL_COPY(&rules, _2$$3);
			if (ZEPHIR_GT(&n, &numArgs)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&uri);
			if (ZEPHIR_GT_LONG(&n, 0)) {
				ZEPHIR_INIT_NVAR(&_5$$6);
				ZVAL_LONG(&_6$$6, 0);
				ZEPHIR_CALL_FUNCTION(&_7$$6, "array_slice", &_8, 106, &args, &_6$$6, &n);
				zephir_check_call_status();
				zephir_fast_join_str(&_5$$6, SL("/"), &_7$$6 TSRMLS_CC);
				ZEPHIR_CONCAT_SV(&uri, "/", &_5$$6);
			} else {
				ZVAL_STRING(&uri, "");
			}
			zephir_is_iterable(&routingNames, 0, "nc/mvc/application.zep", 121);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&routingNames), _9$$4)
			{
				ZEPHIR_INIT_NVAR(&routingName);
				ZVAL_COPY(&routingName, _9$$4);
				ZEPHIR_INIT_LNVAR(_10$$8);
				ZEPHIR_CONCAT_VV(&_10$$8, &routingName, &uri);
				if (zephir_array_isset_fetch(&controllerClass, &rules, &_10$$8, 1 TSRMLS_CC)) {
					RETURN_CTOR(controllerClass);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&routingName);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&rules);
		ZEPHIR_INIT_NVAR(&n);
	}
	RETURN_MM_STRING("");

}

