
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Factory_ClassNameAbstract) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Factory, ClassNameAbstract, nc, factory_classnameabstract, nc_factory_factoryabstract_ce, nc_factory_classnameabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_factory_classnameabstract_ce, SL("args"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_factory_classnameabstract_ce, SL("lazyArgs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, newInstanceOf) {

	zend_class_entry *_1$$3, *_4$$5, *_7$$6, *_11$$7, *_16$$8, *_22$$9;
	long c = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *className_param = NULL, *args_param = NULL, a, _28, _29, _30, _0$$3, _2$$4, _3$$5, _5$$5, _6$$6, _8$$6, _9$$6, _10$$7, _12$$7, _13$$7, _14$$7, _15$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$9, _23$$9, _24$$9, _25$$9, _26$$9, _27$$9;
	zval className;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &className_param, &args_param);

	zephir_get_strval(&className, className_param);
	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	c = zephir_fast_count_int(&args TSRMLS_CC);
	if (c < 1) {
		zephir_fetch_safe_class(&_0$$3, &className);
		_1$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0$$3), Z_STRLEN_P(&_0$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(return_value, _1$$3);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	if (c > 5) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, zephir_get_internal_ce(SL("reflectionclass")));
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 16, &className);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_2$$4, "newinstanceargs", NULL, 20, &args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&a, "array_values", NULL, 21, &args);
	zephir_check_call_status();
	do {
		if (c == 1) {
			zephir_fetch_safe_class(&_3$$5, &className);
			_4$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$5), Z_STRLEN_P(&_3$$5), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(return_value, _4$$5);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_5$$5, &a, 0, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 24 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_5$$5);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 2) {
			zephir_fetch_safe_class(&_6$$6, &className);
			_7$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6$$6), Z_STRLEN_P(&_6$$6), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(return_value, _7$$6);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_8$$6, &a, 0, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 26 TSRMLS_CC);
				zephir_array_fetch_long(&_9$$6, &a, 1, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 26 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_8$$6, &_9$$6);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 3) {
			zephir_fetch_safe_class(&_10$$7, &className);
			_11$$7 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_10$$7), Z_STRLEN_P(&_10$$7), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(return_value, _11$$7);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_12$$7, &a, 0, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 28 TSRMLS_CC);
				zephir_array_fetch_long(&_13$$7, &a, 1, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 28 TSRMLS_CC);
				zephir_array_fetch_long(&_14$$7, &a, 2, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 28 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_12$$7, &_13$$7, &_14$$7);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 4) {
			zephir_fetch_safe_class(&_15$$8, &className);
			_16$$8 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_15$$8), Z_STRLEN_P(&_15$$8), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(return_value, _16$$8);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_17$$8, &a, 0, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 30 TSRMLS_CC);
				zephir_array_fetch_long(&_18$$8, &a, 1, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 30 TSRMLS_CC);
				zephir_array_fetch_long(&_19$$8, &a, 2, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 30 TSRMLS_CC);
				zephir_array_fetch_long(&_20$$8, &a, 3, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 30 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_17$$8, &_18$$8, &_19$$8, &_20$$8);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 5) {
			zephir_fetch_safe_class(&_21$$9, &className);
			_22$$9 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_21$$9), Z_STRLEN_P(&_21$$9), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(return_value, _22$$9);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_23$$9, &a, 0, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 32 TSRMLS_CC);
				zephir_array_fetch_long(&_24$$9, &a, 1, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 32 TSRMLS_CC);
				zephir_array_fetch_long(&_25$$9, &a, 2, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 32 TSRMLS_CC);
				zephir_array_fetch_long(&_26$$9, &a, 3, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 32 TSRMLS_CC);
				zephir_array_fetch_long(&_27$$9, &a, 4, PH_NOISY | PH_READONLY, "nc/factory/classnameabstract.zep", 32 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_23$$9, &_24$$9, &_25$$9, &_26$$9, &_27$$9);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_28);
	object_init_ex(&_28, nc_factory_exception_ce);
	ZEPHIR_INIT_VAR(&_29);
	ZVAL_STRING(&_29, "Fail to fetch a new instance of class '%s'");
	ZEPHIR_CALL_FUNCTION(&_30, "sprintf", NULL, 6, &_29, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_28, "__construct", NULL, 7, &_30);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_28, "nc/factory/classnameabstract.zep", 38 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, getClassName) {

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, __isset) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *name_param = NULL, _0, _3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_PARENT(&_0, nc_factory_classnameabstract_ce, this_ptr, "__isset", &_1, 22, &name);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (!(_2)) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getclassname", NULL, 0, &name);
		zephir_check_call_status();
		_2 = zephir_class_exists(&_3, 1 TSRMLS_CC);
	}
	RETURN_MM_BOOL(_2);

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, setArgs) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 23);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("args"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, setArgsByArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args_param = NULL, _0;
	zval args;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args_param);

	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_FUNCTION(&_0, "array_values", NULL, 21, &args);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("args"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, getArgs) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("args"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		RETURN_MEMBER(this_ptr, "args");
	}
	array_init(return_value);
	return;

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, setLazyArg) {

	zval *index_param = NULL, *lazyArg, lazyArg_sub, _0;
	long index;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&lazyArg_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &lazyArg);

	index = zephir_get_intval(index_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, index);
	zephir_update_property_array(this_ptr, SL("lazyArgs"), &_0, lazyArg TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, getLazyArgs) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("lazyArgs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		RETURN_MEMBER(this_ptr, "lazyArgs");
	}
	array_init(return_value);
	return;

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, createInternally) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _5, _2$$3, _3$$3, _4$$3;
	zval name, className, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclassname", NULL, 0, &name);
	zephir_check_call_status();
	zephir_get_strval(&_1, &_0);
	ZEPHIR_CPY_WRT(&className, &_1);
	if (unlikely(!(zephir_class_exists(&className, 1 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, nc_factory_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Cannot create object '%s', missing class '%s'");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 6, &_3$$3, &name, &className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 7, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "nc/factory/classnameabstract.zep", 91 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "processlazyargs", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("args"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_SELF("newinstanceof", NULL, 0, &className, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, processLazyArgs) {

	zend_bool _6$$4;
	zend_string *_4;
	zend_ulong _3;
	zval __$null, index, lazyArg, _0, _1, *_2, _5$$4, _7$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_8 = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&lazyArg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("lazyArgs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) < 1) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("lazyArgs"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "nc/factory/classnameabstract.zep", 113);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&index);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&index, _4);
		} else {
			ZVAL_LONG(&index, _3);
		}
		ZEPHIR_INIT_NVAR(&lazyArg);
		ZVAL_COPY(&lazyArg, _2);
		zephir_read_property(&_5$$4, this_ptr, SL("args"), PH_NOISY_CC | PH_READONLY);
		_6$$4 = zephir_array_isset(&_5$$4, &index);
		if (_6$$4) {
			_6$$4 = zephir_is_callable(&lazyArg TSRMLS_CC);
		}
		if (_6$$4) {
			ZEPHIR_CALL_FUNCTION(&_7$$5, "call_user_func", &_8, 2, &lazyArg, this_ptr, &index);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("args"), &index, &_7$$5 TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&lazyArg);
	ZEPHIR_INIT_NVAR(&index);
	zephir_update_property_zval(this_ptr, SL("lazyArgs"), &__$null);
	ZEPHIR_MM_RESTORE();

}

