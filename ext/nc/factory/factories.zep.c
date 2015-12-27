
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Factory_Factories) {

	ZEPHIR_REGISTER_CLASS(Nc\\Factory, Factories, nc, factory_factories, nc_factory_factories_method_entry, 0);

	zend_declare_property_null(nc_factory_factories_ce, SL("factories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_factory_factories_ce, SL("priorities"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_factory_factories_ce, SL("DEFAULT_PRIORITY"), 0 TSRMLS_CC);

	zend_class_implements(nc_factory_factories_ce TSRMLS_CC, 1, nc_factory_factoryinterface_ce);
	zend_class_implements(nc_factory_factories_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Nc_Factory_Factories, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	long priority;
	zval *index_param = NULL, *factory, *priority_param = NULL, *_0, *_1, *_2;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &index_param, &factory, &priority_param);

	zephir_get_strval(index, index_param);
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	zephir_update_property_array(this_ptr, SL("factories"), index, factory TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, priority);
	zephir_update_property_array(this_ptr, SL("priorities"), index, _0 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("priorities"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_MAKE_REF(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "asort", NULL, 52, _1, _2);
	ZEPHIR_UNREF(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Factories, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *factory;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &factory);

	zephir_get_strval(index, index_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, index, factory);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Factories, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *factory = NULL, *_0, *_1;
	zval *index = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_OBS_VAR(factory);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&factory, _0, index, 0 TSRMLS_CC)) {
		RETURN_CCTOR(factory);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, nc_factory_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "Invalid index: ", index);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "nc/factory/factories.zep", 31 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Factory_Factories, offsetExists) {

	zval *index_param = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, index));

}

PHP_METHOD(Nc_Factory_Factories, offsetUnset) {

	zval *index_param = NULL, *_0, *_1;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
	zephir_array_unset(&_0, index, PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("priorities"), PH_NOISY_CC);
	zephir_array_unset(&_1, index, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Factories, __isset) {

	HashTable *_4$$3;
	HashPosition _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *index = NULL, *factory = NULL, *_0, *_1$$3, *_2$$3 = NULL, **_5$$3, *_6$$4, *_7$$4, *_8$$4 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("priorities"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("priorities"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_is_iterable(_1$$3, &_4$$3, &_3$$3, 0, 0, "nc/factory/factories.zep", 56);
		for (
		  ; zephir_hash_get_current_data_ex(_4$$3, (void**) &_5$$3, &_3$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4$$3, &_3$$3)
		) {
			ZEPHIR_GET_HMKEY(index, _4$$3, _3$$3);
			ZEPHIR_GET_HVALUE(_2$$3, _5$$3);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
			zephir_array_fetch(&_7$$4, _6$$4, index, PH_NOISY | PH_READONLY, "nc/factory/factories.zep", 51 TSRMLS_CC);
			ZEPHIR_CPY_WRT(factory, _7$$4);
			ZEPHIR_CALL_METHOD(&_8$$4, factory, "__isset", NULL, 0, name);
			zephir_check_call_status();
			if (zephir_is_true(_8$$4)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Factory_Factories, __get) {

	HashTable *_4$$3;
	HashPosition _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *index = NULL, *factory = NULL, *_0, *_9, *_1$$3, *_2$$3 = NULL, **_5$$3, *_6$$4, *_7$$4, *_8$$4 = NULL;
	zval *name = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("priorities"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("priorities"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_is_iterable(_1$$3, &_4$$3, &_3$$3, 0, 0, "nc/factory/factories.zep", 72);
		for (
		  ; zephir_hash_get_current_data_ex(_4$$3, (void**) &_5$$3, &_3$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4$$3, &_3$$3)
		) {
			ZEPHIR_GET_HMKEY(index, _4$$3, _3$$3);
			ZEPHIR_GET_HVALUE(_2$$3, _5$$3);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
			zephir_array_fetch(&_7$$4, _6$$4, index, PH_NOISY | PH_READONLY, "nc/factory/factories.zep", 67 TSRMLS_CC);
			ZEPHIR_CPY_WRT(factory, _7$$4);
			ZEPHIR_CALL_METHOD(&_8$$4, factory, "__isset", NULL, 0, name);
			zephir_check_call_status();
			if (zephir_is_true(_8$$4)) {
				ZEPHIR_RETURN_CALL_METHOD(factory, "__get", NULL, 0, name);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	}
	ZEPHIR_INIT_VAR(_9);
	object_init_ex(_9, nc_factory_exception_ce);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SV(_10, "Invalid production: ", name);
	ZEPHIR_CALL_METHOD(NULL, _9, "__construct", NULL, 2, _10);
	zephir_check_call_status();
	zephir_throw_exception_debug(_9, "nc/factory/factories.zep", 74 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Factory_Factories, newProduction) {

	HashTable *_4$$3;
	HashPosition _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *index = NULL, *factory = NULL, *_0, *_9, *_1$$3, *_2$$3 = NULL, **_5$$3, *_6$$4, *_7$$4, *_8$$4 = NULL;
	zval *name = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("priorities"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("priorities"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_is_iterable(_1$$3, &_4$$3, &_3$$3, 0, 0, "nc/factory/factories.zep", 88);
		for (
		  ; zephir_hash_get_current_data_ex(_4$$3, (void**) &_5$$3, &_3$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4$$3, &_3$$3)
		) {
			ZEPHIR_GET_HMKEY(index, _4$$3, _3$$3);
			ZEPHIR_GET_HVALUE(_2$$3, _5$$3);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("factories"), PH_NOISY_CC);
			zephir_array_fetch(&_7$$4, _6$$4, index, PH_NOISY | PH_READONLY, "nc/factory/factories.zep", 83 TSRMLS_CC);
			ZEPHIR_CPY_WRT(factory, _7$$4);
			ZEPHIR_CALL_METHOD(&_8$$4, factory, "__isset", NULL, 0, name);
			zephir_check_call_status();
			if (zephir_is_true(_8$$4)) {
				ZEPHIR_RETURN_CALL_METHOD(factory, "newproduction", NULL, 0, name);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	}
	ZEPHIR_INIT_VAR(_9);
	object_init_ex(_9, nc_factory_exception_ce);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SV(_10, "Invalid production: ", name);
	ZEPHIR_CALL_METHOD(NULL, _9, "__construct", NULL, 2, _10);
	zephir_check_call_status();
	zephir_throw_exception_debug(_9, "nc/factory/factories.zep", 90 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

