
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Application_ControllerAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Application, ControllerAbstract, nc, application_controllerabstract, nc_application_controllerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_application_controllerabstract_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Application_ControllerAbstract, dispatch) {

	zval *controller = NULL, *controllerName = NULL, *_4 = NULL, *_1$$3 = NULL, *_7$$5, *_9$$6;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *controllerFactory, *params_param = NULL, *controllerVar = NULL, *_2 = NULL, *_5 = NULL, *_0$$3 = NULL, *_6$$5, *_8$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &controllerFactory, &params_param);

	zephir_get_arrval(params, params_param);


	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_0$$3, "array_shift", NULL, 5, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_get_strval(_1$$3, _0$$3);
		ZEPHIR_CPY_WRT(controller, _1$$3);
	} else {
		ZEPHIR_INIT_NVAR(controller);
		ZVAL_STRING(controller, "index", 1);
	}
	ZEPHIR_CALL_CE_STATIC(&_2, nc_std_ce, "camelcase", &_3, 17, controller);
	zephir_check_call_status();
	zephir_get_strval(_4, _2);
	ZEPHIR_CPY_WRT(controllerName, _4);
	ZEPHIR_CALL_METHOD(&_5, controllerFactory, "__isset", NULL, 0, controllerName);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_6$$5);
		object_init_ex(_6$$5, nc_application_notfoundexception_ce);
		ZEPHIR_INIT_VAR(_7$$5);
		ZEPHIR_CONCAT_SV(_7$$5, "Controller not found: ", controller);
		ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", NULL, 2, _7$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$5, "nc/application/controllerabstract.zep", 23 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&controllerVar, controllerFactory, "__get", NULL, 0, controllerName);
	zephir_check_call_status();
	if (unlikely(!(zephir_is_callable(controllerVar TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_8$$6);
		object_init_ex(_8$$6, nc_application_exception_ce);
		ZEPHIR_INIT_VAR(_9$$6);
		ZEPHIR_CONCAT_SV(_9$$6, "Invalid controller: ", controller);
		ZEPHIR_CALL_METHOD(NULL, _8$$6, "__construct", NULL, 2, _9$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$6, "nc/application/controllerabstract.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", NULL, 15, controllerVar, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Application_ControllerAbstract, __construct) {

	zval *di;

	zephir_fetch_params(0, 1, 0, &di);



	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);

}

PHP_METHOD(Nc_Application_ControllerAbstract, __invoke) {

	zval *action = NULL, *_1$$3 = NULL, *_6$$5;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *actionVar = NULL, *_2 = NULL, *_4, *_7, *_0$$3 = NULL, *_5$$5;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(params, params_param);


	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_0$$3, "array_shift", NULL, 5, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_get_strval(_1$$3, _0$$3);
		ZEPHIR_CPY_WRT(action, _1$$3);
	} else {
		ZEPHIR_INIT_NVAR(action);
		ZVAL_STRING(action, "index", 1);
	}
	ZEPHIR_INIT_VAR(actionVar);
	array_init(actionVar);
	zephir_array_append(&actionVar, this_ptr, PH_SEPARATE, "nc/application/controllerabstract.zep", 51);
	ZEPHIR_CALL_CE_STATIC(&_2, nc_std_ce, "camelcase", &_3, 17, action);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _2, "Action");
	zephir_array_append(&actionVar, _4, PH_SEPARATE, "nc/application/controllerabstract.zep", 52);
	if (unlikely(!(zephir_is_callable(actionVar TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_5$$5);
		object_init_ex(_5$$5, nc_application_notfoundexception_ce);
		ZEPHIR_INIT_VAR(_6$$5);
		ZEPHIR_CONCAT_SV(_6$$5, "Controller action not found: ", action);
		ZEPHIR_CALL_METHOD(NULL, _5$$5, "__construct", NULL, 2, _6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$5, "nc/application/controllerabstract.zep", 55 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_7, actionVar, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Application_ControllerAbstract, getServer) {

	zval *name_param = NULL, *defaultValue = NULL, *_SERVER, *value = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(name, name_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_fetch(&value, _SERVER, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

