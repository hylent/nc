
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Factory_FactoryAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Factory, FactoryAbstract, nc, factory_factoryabstract, nc_factory_factoryabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_factory_factoryabstract_ce, SL("onCreated"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_factory_factoryabstract_ce, SL("objects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_factory_factoryabstract_ce TSRMLS_CC, 1, nc_factory_factoryinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Factory_FactoryAbstract, onCreated) {

	zval *onCreated = NULL, onCreated_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&onCreated_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &onCreated);

	if (!onCreated) {
		onCreated = &onCreated_sub;
		onCreated = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("onCreated"), onCreated);

}

PHP_METHOD(Nc_Factory_FactoryAbstract, __isset) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

PHP_METHOD(Nc_Factory_FactoryAbstract, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZVAL_BOOL(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "create", NULL, 0, &name, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Factory_FactoryAbstract, create) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool shared, _0;
	zval *name_param = NULL, *shared_param = NULL, obj, onCreated, _1, _2;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&onCreated);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &shared_param);

	zephir_get_strval(&name, name_param);
	if (!shared_param) {
		shared = 0;
	} else {
		shared = zephir_get_boolval(shared_param);
	}


	_0 = shared;
	if (_0) {
		ZEPHIR_OBS_VAR(&obj);
		zephir_read_property(&_1, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset_fetch(&obj, &_1, &name, 0 TSRMLS_CC);
	}
	if (_0) {
		RETURN_CCTOR(obj);
	}
	ZEPHIR_CALL_METHOD(&obj, this_ptr, "createinternally", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("onCreated"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&onCreated, &_2);
	if (zephir_is_callable(&onCreated TSRMLS_CC)) {
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", NULL, 2, &onCreated, &name, &obj, this_ptr);
		zephir_check_call_status();
	}
	if (shared) {
		zephir_update_property_array(this_ptr, SL("objects"), &name, &obj TSRMLS_CC);
	}
	RETURN_CCTOR(obj);

}

PHP_METHOD(Nc_Factory_FactoryAbstract, createInternally) {

}

