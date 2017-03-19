
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Di_Injector) {

	ZEPHIR_REGISTER_CLASS(Nc\\Di, Injector, nc, di_injector, nc_di_injector_method_entry, 0);

	zend_declare_property_null(nc_di_injector_ce, SL("objects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_di_injector_ce, SL("delegates"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_di_injector_ce, SL("nameLocks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_di_injector_ce, SL("ANNOTATION_PATTERN"), "/^[ \\t]*\\*[ \\t]*@@[ \\t]*(\\S*)[ \\t]*(\\S*)[ \\t]*$/m");

	zend_class_implements(nc_di_injector_ce TSRMLS_CC, 1, nc_di_containerinterface_ce);
	zend_class_implements(nc_di_injector_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Nc_Di_Injector, __isset) {

	zend_bool _5$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, pos, containerName, container, subName, _0, _1, _2, _3$$5, _4$$5, _6$$7, _7$$7;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&containerName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&subName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_1, this_ptr, SL("delegates"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &name)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ".");
	ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 57, &name, &_2);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
		ZVAL_LONG(&_3$$5, 0);
		ZEPHIR_INIT_VAR(&containerName);
		zephir_substr(&containerName, &name, 0 , zephir_get_intval(&pos), 0);
		ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "__isset", NULL, 58, &containerName);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$5)) {
			ZEPHIR_CALL_METHOD(&container, this_ptr, "__get", NULL, 0, &containerName);
			zephir_check_call_status();
			_5$$6 = Z_TYPE_P(&container) == IS_OBJECT;
			if (_5$$6) {
				_5$$6 = (zephir_instance_of_ev(&container, nc_di_containerinterface_ce TSRMLS_CC));
			}
			if (_5$$6) {
				ZVAL_LONG(&_6$$7, (zephir_get_numberval(&pos) + 1));
				ZEPHIR_INIT_VAR(&subName);
				zephir_substr(&subName, &name, zephir_get_intval(&_6$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_METHOD(&_7$$7, &container, "__isset", NULL, 0, &subName);
				zephir_check_call_status();
				if (zephir_is_true(&_7$$7)) {
					RETURN_MM_BOOL(1);
				}
			}
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Di_Injector, __get) {

	zend_bool _8$$6, _13$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_10 = NULL, *_12 = NULL;
	zval *name_param = NULL, __$true, obj, delegate, pos, containerName, container, subName, _0, _1, _17, _2$$4, _3$$4, _4$$4, _6$$5, _9$$5, _15$$5, _16$$5, _11$$8, _14$$9;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&delegate);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&containerName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&subName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_14$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_OBS_VAR(&obj);
	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&obj, &_0, &name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(obj);
	}
	zephir_read_property(&_1, this_ptr, SL("nameLocks"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(zephir_array_isset(&_1, &name))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, nc_di_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Initializing %s");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", &_5, 2, &_3$$4, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 3, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "nc/di/injector.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("nameLocks"), &name, &__$true TSRMLS_CC);
	while (1) {
		ZEPHIR_OBS_NVAR(&delegate);
		zephir_read_property(&_6$$5, this_ptr, SL("delegates"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_fetch(&delegate, &_6$$5, &name, 0 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&obj, "call_user_func", &_7, 59, &delegate, this_ptr, &name);
			zephir_check_call_status();
			_8$$6 = Z_TYPE_P(&obj) == IS_OBJECT;
			if (_8$$6) {
				_8$$6 = (zephir_instance_of_ev(&obj, nc_di_injectedsetupmethodinterface_ce TSRMLS_CC));
			}
			if (_8$$6) {
				ZEPHIR_CALL_METHOD(NULL, &obj, "setupbyinjector", NULL, 0, this_ptr);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_INIT_NVAR(&_9$$5);
		ZVAL_STRING(&_9$$5, ".");
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_10, 57, &name, &_9$$5);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
			ZVAL_LONG(&_11$$8, 0);
			ZEPHIR_INIT_NVAR(&containerName);
			zephir_substr(&containerName, &name, 0 , zephir_get_intval(&pos), 0);
			ZEPHIR_CALL_METHOD(&container, this_ptr, "__get", &_12, 60, &containerName);
			zephir_check_call_status();
			_13$$8 = Z_TYPE_P(&container) == IS_OBJECT;
			if (_13$$8) {
				_13$$8 = (zephir_instance_of_ev(&container, nc_di_containerinterface_ce TSRMLS_CC));
			}
			if (_13$$8) {
				ZVAL_LONG(&_14$$9, (zephir_get_numberval(&pos) + 1));
				ZEPHIR_INIT_NVAR(&subName);
				zephir_substr(&subName, &name, zephir_get_intval(&_14$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_METHOD(&obj, &container, "__get", NULL, 0, &subName);
				zephir_check_call_status();
				break;
			}
		}
		ZEPHIR_INIT_NVAR(&_9$$5);
		object_init_ex(&_9$$5, nc_di_exception_ce);
		ZEPHIR_INIT_NVAR(&_15$$5);
		ZVAL_STRING(&_15$$5, "CannotResolveDependency %s");
		ZEPHIR_CALL_FUNCTION(&_16$$5, "sprintf", &_5, 2, &_15$$5, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", NULL, 3, &_16$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$5, "nc/di/injector.zep", 74 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_17, this_ptr, SL("nameLocks"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_17, &name, PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("objects"), &name, &obj TSRMLS_CC);
	RETURN_CCTOR(obj);

}

PHP_METHOD(Nc_Di_Injector, __set) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *obj, obj_sub;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&obj_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &obj);

	zephir_get_strval(&name, name_param);


	_0 = Z_TYPE_P(obj) == IS_OBJECT;
	if (_0) {
		_0 = (zephir_instance_of_ev(obj, nc_di_injectedsetupmethodinterface_ce TSRMLS_CC));
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(NULL, obj, "setupbyinjector", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("objects"), &name, obj TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Injector, __unset) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Injector, __invoke) {

	zend_bool _0, _9$$5, _14$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_26 = NULL;
	zval *className_param = NULL, *type_param = NULL, refClass, obj, refProperty, resolvedValue, refCtor, params, _5, _27, _28, _1$$3, _2$$3, _3$$3, _6$$4, _7$$4, _8$$4, _13$$5, _15$$5, _10$$6, _11$$6, _12$$6, _16$$7, _17$$7, _18$$7, _19$$8, *_20$$8, _21$$9, _22$$9, _24$$9, _23$$11, _25$$12, _29$$14, _31$$14, _30$$15;
	zval className, type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&refClass);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&refProperty);
	ZVAL_UNDEF(&resolvedValue);
	ZVAL_UNDEF(&refCtor);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_30$$15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &className_param, &type_param);

	zephir_get_strval(&className, className_param);
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}


	_0 = zephir_fast_strlen_ev(&className) < 1;
	if (!(_0)) {
		_0 = !(zephir_class_exists(&className, 1 TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_di_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "InvalidClass %s");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", &_4, 2, &_2$$3, &className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/di/injector.zep", 102 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&refClass);
	object_init_ex(&refClass, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &refClass, "__construct", NULL, 14, &className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &refClass, "isinstantiable", NULL, 61);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, nc_di_exception_ce);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "NotInstantiable %s");
		ZEPHIR_CALL_FUNCTION(&_8$$4, "sprintf", &_4, 2, &_7$$4, &className);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 3, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$4, "nc/di/injector.zep", 107 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_strlen_ev(&type) > 0) {
		_9$$5 = !(zephir_class_exists(&type, 1 TSRMLS_CC));
		if (_9$$5) {
			_9$$5 = !(zephir_interface_exists(&type, 1  TSRMLS_CC));
		}
		if (unlikely(_9$$5)) {
			ZEPHIR_INIT_VAR(&_10$$6);
			object_init_ex(&_10$$6, nc_di_exception_ce);
			ZEPHIR_INIT_VAR(&_11$$6);
			ZVAL_STRING(&_11$$6, "InvalidType %s");
			ZEPHIR_CALL_FUNCTION(&_12$$6, "sprintf", &_4, 2, &_11$$6, &type);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", NULL, 3, &_12$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$6, "nc/di/injector.zep", 112 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_13$$5, &refClass, "issubclassof", NULL, 62, &type);
		zephir_check_call_status();
		_14$$5 = !zephir_is_true(&_13$$5);
		if (_14$$5) {
			ZEPHIR_CALL_FUNCTION(&_15$$5, "strcasecmp", NULL, 63, &className, &type);
			zephir_check_call_status();
			_14$$5 = !ZEPHIR_IS_LONG(&_15$$5, 0);
		}
		if (unlikely(_14$$5)) {
			ZEPHIR_INIT_VAR(&_16$$7);
			object_init_ex(&_16$$7, nc_di_exception_ce);
			ZEPHIR_INIT_VAR(&_17$$7);
			ZVAL_STRING(&_17$$7, "InvalidClassType: %s provided, %s required");
			ZEPHIR_CALL_FUNCTION(&_18$$7, "sprintf", &_4, 2, &_17$$7, &className, &type);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", NULL, 3, &_18$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_16$$7, "nc/di/injector.zep", 115 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&obj, &refClass, "newinstancewithoutconstructor", NULL, 15);
	zephir_check_call_status();
	if (zephir_instance_of_ev(&obj, nc_di_injectedpropertyinterface_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_19$$8, &refClass, "getproperties", NULL, 64);
		zephir_check_call_status();
		zephir_is_iterable(&_19$$8, 0, "nc/di/injector.zep", 136);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_19$$8), _20$$8)
		{
			ZEPHIR_INIT_NVAR(&refProperty);
			ZVAL_COPY(&refProperty, _20$$8);
			ZEPHIR_CALL_METHOD(&_21$$9, &refProperty, "isstatic", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_21$$9)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&_22$$9, &refProperty, "ispublic", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_22$$9))) {
				ZVAL_BOOL(&_23$$11, 1);
				ZEPHIR_CALL_METHOD(NULL, &refProperty, "setaccessible", NULL, 0, &_23$$11);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_24$$9, &refProperty, "getvalue", NULL, 0, &obj);
			zephir_check_call_status();
			if (Z_TYPE_P(&_24$$9) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&_25$$12, &refProperty, "getdoccomment", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&resolvedValue, this_ptr, "resolvefirst", &_26, 0, &_25$$12);
				zephir_check_call_status();
				if (Z_TYPE_P(&resolvedValue) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &refProperty, "setvalue", NULL, 0, &obj, &resolvedValue);
					zephir_check_call_status();
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&refProperty);
	}
	ZEPHIR_INIT_VAR(&_28);
	ZVAL_STRING(&_28, "__construct");
	ZEPHIR_CALL_METHOD(&_27, &refClass, "hasmethod", NULL, 65, &_28);
	zephir_check_call_status();
	if (zephir_is_true(&_27)) {
		ZEPHIR_INIT_VAR(&_29$$14);
		ZVAL_STRING(&_29$$14, "__construct");
		ZEPHIR_CALL_METHOD(&refCtor, &refClass, "getmethod", NULL, 66, &_29$$14);
		zephir_check_call_status();
		if (zephir_instance_of_ev(&obj, nc_di_injectedctorparamsinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_30$$15, &refCtor, "getdoccomment", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&params, this_ptr, "resolveall", NULL, 0, &_30$$15);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&params);
			array_init(&params);
		}
		ZEPHIR_CALL_METHOD(&_31$$14, &refCtor, "getnumberofrequiredparameters", NULL, 0);
		zephir_check_call_status();
		if (unlikely(ZEPHIR_GT_LONG(&_31$$14, zephir_fast_count_int(&params TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_di_exception_ce, "MissingRequiredParam", "nc/di/injector.zep", 146);
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, &refCtor, "invokeargs", NULL, 0, &obj, &params);
		zephir_check_call_status();
	}
	if (zephir_instance_of_ev(&obj, nc_di_injectedsetupmethodinterface_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &obj, "setupbyinjector", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	RETURN_CCTOR(obj);

}

PHP_METHOD(Nc_Di_Injector, offsetSet) {

	zval *name_param = NULL, *delegate, delegate_sub;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&delegate_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &delegate);

	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("delegates"), &name, delegate TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Injector, offsetGet) {

	zval *name_param = NULL, delegate, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&delegate);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("delegates"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&delegate, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(delegate);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Injector, offsetExists) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("delegates"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

PHP_METHOD(Nc_Di_Injector, offsetUnset) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("delegates"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Injector, setClassMapper) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval classMapper;
	zval *name_param = NULL, *classMapper_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&classMapper);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &classMapper_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&classMapper, classMapper_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_di_creatorclassmapper_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 67, &classMapper);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", NULL, 0, &name, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Injector, setClassPrefix) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *prefix_param = NULL, _0;
	zval name, prefix;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &prefix_param);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&prefix, prefix_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_di_creatorclassprefix_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 56, &prefix);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", NULL, 0, &name, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Injector, setClassNamespace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *ns_param = NULL, _0;
	zval name, ns;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &ns_param);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&ns, ns_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_di_creatorclassnamespace_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 68, &ns);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", NULL, 0, &name, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Injector, resolveFirst) {

	zend_bool _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *annotation_param = NULL, m, m1, m2, obj, _0, _1, _2, _4, _7;
	zval annotation, _3, _5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&m1);
	ZVAL_UNDEF(&m2);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &annotation_param);

	zephir_get_strval(&annotation, annotation_param);


	ZEPHIR_INIT_VAR(&m);
	ZVAL_NULL(&m);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/^[ \\t]*\\*[ \\t]*@@[ \\t]*(\\S*)[ \\t]*(\\S*)[ \\t]*$/m");
	zephir_preg_match(&_0, &_1, &annotation, &m, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch_long(&_2, &m, 1, PH_NOISY, "nc/di/injector.zep", 205 TSRMLS_CC);
	zephir_get_strval(&_3, &_2);
	ZEPHIR_CPY_WRT(&m1, &_3);
	ZEPHIR_OBS_VAR(&_4);
	zephir_array_fetch_long(&_4, &m, 2, PH_NOISY, "nc/di/injector.zep", 206 TSRMLS_CC);
	zephir_get_strval(&_5, &_4);
	ZEPHIR_CPY_WRT(&m2, &_5);
	if (ZEPHIR_IS_STRING_IDENTICAL(&m1, "")) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&obj, this_ptr, "__get", NULL, 0, &m1);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(&m2, "")) {
		RETURN_CCTOR(obj);
	}
	_6 = Z_TYPE_P(&obj) != IS_OBJECT;
	if (!(_6)) {
		_6 = !((zephir_instance_of_ev(&obj, nc_di_containerinterface_ce TSRMLS_CC)));
	}
	if (_6) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_di_exception_ce, "InvalidContainer", "nc/di/injector.zep", 218);
		return;
	}
	ZEPHIR_CALL_METHOD(&_7, &obj, "__isset", NULL, 0, &m2);
	zephir_check_call_status();
	if (!(zephir_is_true(&_7))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_METHOD(&obj, "__get", NULL, 0, &m2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Di_Injector, resolveAll) {

	zend_bool _9$$4;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *annotation_param = NULL, __$null, r, mVec, m, m1, m2, obj, _0, _1, _2, *_3$$3, _4$$4, _6$$4, _10$$4, _11$$4;
	zval annotation, _5$$4, _7$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&mVec);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&m1);
	ZVAL_UNDEF(&m2);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &annotation_param);

	zephir_get_strval(&annotation, annotation_param);


	ZEPHIR_INIT_VAR(&r);
	array_init(&r);
	ZEPHIR_INIT_VAR(&mVec);
	ZVAL_NULL(&mVec);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/^[ \\t]*\\*[ \\t]*@@[ \\t]*(\\S*)[ \\t]*(\\S*)[ \\t]*$/m");
	ZVAL_LONG(&_1, 2);
	ZEPHIR_MAKE_REF(&mVec);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match_all", NULL, 69, &_0, &annotation, &mVec, &_1);
	ZEPHIR_UNREF(&mVec);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		zephir_is_iterable(&mVec, 0, "nc/di/injector.zep", 259);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&mVec), _3$$3)
		{
			ZEPHIR_INIT_NVAR(&m);
			ZVAL_COPY(&m, _3$$3);
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_array_fetch_long(&_4$$4, &m, 1, PH_NOISY, "nc/di/injector.zep", 234 TSRMLS_CC);
			zephir_get_strval(&_5$$4, &_4$$4);
			ZEPHIR_CPY_WRT(&m1, &_5$$4);
			ZEPHIR_OBS_NVAR(&_6$$4);
			zephir_array_fetch_long(&_6$$4, &m, 2, PH_NOISY, "nc/di/injector.zep", 235 TSRMLS_CC);
			zephir_get_strval(&_7$$4, &_6$$4);
			ZEPHIR_CPY_WRT(&m2, &_7$$4);
			if (ZEPHIR_IS_STRING_IDENTICAL(&m1, "")) {
				zephir_array_append(&r, &__$null, PH_SEPARATE, "nc/di/injector.zep", 238);
				continue;
			}
			ZEPHIR_CALL_METHOD(&obj, this_ptr, "__get", &_8, 0, &m1);
			zephir_check_call_status();
			if (ZEPHIR_IS_STRING_IDENTICAL(&m2, "")) {
				zephir_array_append(&r, &obj, PH_SEPARATE, "nc/di/injector.zep", 244);
				continue;
			}
			_9$$4 = Z_TYPE_P(&obj) != IS_OBJECT;
			if (!(_9$$4)) {
				_9$$4 = !((zephir_instance_of_ev(&obj, nc_di_containerinterface_ce TSRMLS_CC)));
			}
			if (_9$$4) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_di_exception_ce, "InvalidContainer", "nc/di/injector.zep", 249);
				return;
			}
			ZEPHIR_CALL_METHOD(&_10$$4, &obj, "__isset", NULL, 0, &m2);
			zephir_check_call_status();
			if (!(zephir_is_true(&_10$$4))) {
				zephir_array_append(&r, &__$null, PH_SEPARATE, "nc/di/injector.zep", 253);
				continue;
			}
			ZEPHIR_CALL_METHOD(&_11$$4, &obj, "__get", NULL, 0, &m2);
			zephir_check_call_status();
			zephir_array_append(&r, &_11$$4, PH_SEPARATE, "nc/di/injector.zep", 257);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&m);
	}
	RETURN_CCTOR(r);

}

