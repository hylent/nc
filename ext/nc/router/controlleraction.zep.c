
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Router_ControllerAction) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Router, ControllerAction, nc, router_controlleraction, nc_router_routerabstract_ce, nc_router_controlleraction_method_entry, 0);

	zend_declare_property_null(nc_router_controlleraction_ce, SL("controllerFactory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(nc_router_controlleraction_ce, SL("defaultController"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(nc_router_controlleraction_ce, SL("defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(nc_router_controlleraction_ce, SL("actionSuffix"), "Action", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_router_controlleraction_ce, SL("DEFAULT_CONTROLLER"), "index" TSRMLS_CC);

	zend_declare_class_constant_string(nc_router_controlleraction_ce, SL("DEFAULT_ACTION"), "index" TSRMLS_CC);

	zend_declare_class_constant_string(nc_router_controlleraction_ce, SL("DEFAULT_ACTION_SUFFIX"), "Action" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Router_ControllerAction, __construct) {

	zval *controllerFactory;

	zephir_fetch_params(0, 1, 0, &controllerFactory);



	zephir_update_property_this(this_ptr, SL("controllerFactory"), controllerFactory TSRMLS_CC);

}

PHP_METHOD(Nc_Router_ControllerAction, getControllerFactory) {

	

	RETURN_MEMBER(this_ptr, "controllerFactory");

}

PHP_METHOD(Nc_Router_ControllerAction, setDefaultController) {

	zval *defaultController_param = NULL;
	zval *defaultController = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultController_param);

	zephir_get_strval(defaultController, defaultController_param);


	zephir_update_property_this(this_ptr, SL("defaultController"), defaultController TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Router_ControllerAction, getDefaultController) {

	

	RETURN_MEMBER(this_ptr, "defaultController");

}

PHP_METHOD(Nc_Router_ControllerAction, setDefaultAction) {

	zval *defaultAction_param = NULL;
	zval *defaultAction = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultAction_param);

	zephir_get_strval(defaultAction, defaultAction_param);


	zephir_update_property_this(this_ptr, SL("defaultAction"), defaultAction TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Router_ControllerAction, getDefaultAction) {

	

	RETURN_MEMBER(this_ptr, "defaultAction");

}

PHP_METHOD(Nc_Router_ControllerAction, setActionSuffix) {

	zval *actionSuffix_param = NULL;
	zval *actionSuffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	zephir_get_strval(actionSuffix, actionSuffix_param);


	zephir_update_property_this(this_ptr, SL("actionSuffix"), actionSuffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Router_ControllerAction, getActionSuffix) {

	

	RETURN_MEMBER(this_ptr, "actionSuffix");

}

PHP_METHOD(Nc_Router_ControllerAction, route) {

	zval *_1 = NULL;
	zval *controller = NULL, *action = NULL, *controllerName = NULL, *actionName = NULL, *_16, *_19 = NULL, *_21 = NULL, *_4$$3 = NULL, *_6$$3 = NULL, *_9$$4 = NULL, *_11$$4 = NULL, *_13$$5 = NULL, *_15$$5 = NULL, *_25$$6;
	zval *source = NULL, *actionVar = NULL, *_0 = NULL, *_17 = NULL, *_20 = NULL, *_22, *_23 = NULL, *_26, *_27 = NULL, *_28, *_29, *_33, *_3$$3, *_5$$3, *_7$$4 = NULL, *_10$$4, *_12$$5 = NULL, *_14$$5 = NULL, *_24$$6, *_30$$7, *_31$$7, *_32$$7;
	zephir_fcall_cache_entry *_8 = NULL, *_18 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	zephir_get_arrval(_1, _0);
	ZEPHIR_CPY_WRT(source, _1);
	do {
		_2 = zephir_fast_count_int(source TSRMLS_CC);
		if (_2 == 0) {
			ZEPHIR_OBS_VAR(_3$$3);
			zephir_read_property_this(&_3$$3, this_ptr, SL("defaultController"), PH_NOISY_CC);
			zephir_get_strval(_4$$3, _3$$3);
			ZEPHIR_CPY_WRT(controller, _4$$3);
			ZEPHIR_OBS_VAR(_5$$3);
			zephir_read_property_this(&_5$$3, this_ptr, SL("defaultAction"), PH_NOISY_CC);
			zephir_get_strval(_6$$3, _5$$3);
			ZEPHIR_CPY_WRT(action, _6$$3);
			break;
		}
		if (_2 == 1) {
			ZEPHIR_MAKE_REF(source);
			ZEPHIR_CALL_FUNCTION(&_7$$4, "array_shift", &_8, 6, source);
			ZEPHIR_UNREF(source);
			zephir_check_call_status();
			zephir_get_strval(_9$$4, _7$$4);
			ZEPHIR_CPY_WRT(controller, _9$$4);
			ZEPHIR_OBS_VAR(_10$$4);
			zephir_read_property_this(&_10$$4, this_ptr, SL("defaultAction"), PH_NOISY_CC);
			zephir_get_strval(_11$$4, _10$$4);
			ZEPHIR_CPY_WRT(action, _11$$4);
			break;
		}
		ZEPHIR_MAKE_REF(source);
		ZEPHIR_CALL_FUNCTION(&_12$$5, "array_shift", &_8, 6, source);
		ZEPHIR_UNREF(source);
		zephir_check_call_status();
		zephir_get_strval(_13$$5, _12$$5);
		ZEPHIR_CPY_WRT(controller, _13$$5);
		ZEPHIR_MAKE_REF(source);
		ZEPHIR_CALL_FUNCTION(&_14$$5, "array_shift", &_8, 6, source);
		ZEPHIR_UNREF(source);
		zephir_check_call_status();
		zephir_get_strval(_15$$5, _14$$5);
		ZEPHIR_CPY_WRT(action, _15$$5);
		break;
	} while(0);

	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_VSV(_16, controller, "/", action);
	zephir_update_property_this(this_ptr, SL("id"), _16 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_17, nc_std_ce, "camelcase", &_18, 104, controller);
	zephir_check_call_status();
	zephir_get_strval(_19, _17);
	ZEPHIR_CPY_WRT(controllerName, _19);
	ZEPHIR_CALL_CE_STATIC(&_20, nc_std_ce, "camelcase", &_18, 104, action);
	zephir_check_call_status();
	zephir_get_strval(_21, _20);
	ZEPHIR_CPY_WRT(actionName, _21);
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("controllerFactory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_23, _22, "__isset", NULL, 0, actionName);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_23))) {
		ZEPHIR_INIT_VAR(_24$$6);
		object_init_ex(_24$$6, nc_router_notfoundexception_ce);
		ZEPHIR_INIT_VAR(_25$$6);
		ZEPHIR_CONCAT_SV(_25$$6, "Controller not found: ", controller);
		ZEPHIR_CALL_METHOD(NULL, _24$$6, "__construct", NULL, 2, _25$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_24$$6, "nc/router/controlleraction.zep", 85 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(actionVar);
	array_init(actionVar);
	_26 = zephir_fetch_nproperty_this(this_ptr, SL("controllerFactory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_27, _26, "__get", NULL, 0, controllerName);
	zephir_check_call_status();
	zephir_array_append(&actionVar, _27, PH_SEPARATE, "nc/router/controlleraction.zep", 89);
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("actionSuffix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_29);
	ZEPHIR_CONCAT_VV(_29, actionName, _28);
	zephir_array_append(&actionVar, _29, PH_SEPARATE, "nc/router/controlleraction.zep", 90);
	if (unlikely(!(zephir_is_callable(actionVar TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_30$$7);
		object_init_ex(_30$$7, nc_router_notfoundexception_ce);
		_31$$7 = zephir_fetch_nproperty_this(this_ptr, SL("id"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_32$$7);
		ZEPHIR_CONCAT_SV(_32$$7, "Invalid action: ", _31$$7);
		ZEPHIR_CALL_METHOD(NULL, _30$$7, "__construct", NULL, 2, _32$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_30$$7, "nc/router/controlleraction.zep", 93 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_33);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_33, actionVar, source);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

