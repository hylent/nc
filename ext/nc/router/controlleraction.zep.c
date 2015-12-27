
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

	zval *controller = NULL, *action = NULL, *controllerName = NULL, *_14, *_17 = NULL, *_2$$3 = NULL, *_4$$3 = NULL, *_7$$4 = NULL, *_9$$4 = NULL, *_11$$5 = NULL, *_13$$5 = NULL, *_21$$6;
	int ZEPHIR_LAST_CALL_STATUS, _0;
	zephir_fcall_cache_entry *_6 = NULL, *_16 = NULL;
	zval *params_param = NULL, *actionVar = NULL, *_15 = NULL, *_18, *_19 = NULL, *_22, *_23 = NULL, *_24 = NULL, *_25, *_26, *_30, *_1$$3, *_3$$3, *_5$$4 = NULL, *_8$$4, *_10$$5 = NULL, *_12$$5 = NULL, *_20$$6, *_27$$7, *_28$$7, *_29$$7;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(params, params_param);


	do {
		_0 = zephir_fast_count_int(params TSRMLS_CC);
		if (_0 == 0) {
			ZEPHIR_OBS_VAR(_1$$3);
			zephir_read_property_this(&_1$$3, this_ptr, SL("defaultController"), PH_NOISY_CC);
			zephir_get_strval(_2$$3, _1$$3);
			ZEPHIR_CPY_WRT(controller, _2$$3);
			ZEPHIR_OBS_VAR(_3$$3);
			zephir_read_property_this(&_3$$3, this_ptr, SL("defaultAction"), PH_NOISY_CC);
			zephir_get_strval(_4$$3, _3$$3);
			ZEPHIR_CPY_WRT(action, _4$$3);
			break;
		}
		if (_0 == 1) {
			ZEPHIR_MAKE_REF(params);
			ZEPHIR_CALL_FUNCTION(&_5$$4, "array_shift", &_6, 5, params);
			ZEPHIR_UNREF(params);
			zephir_check_call_status();
			zephir_get_strval(_7$$4, _5$$4);
			ZEPHIR_CPY_WRT(controller, _7$$4);
			ZEPHIR_OBS_VAR(_8$$4);
			zephir_read_property_this(&_8$$4, this_ptr, SL("defaultAction"), PH_NOISY_CC);
			zephir_get_strval(_9$$4, _8$$4);
			ZEPHIR_CPY_WRT(action, _9$$4);
			break;
		}
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_10$$5, "array_shift", &_6, 5, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_get_strval(_11$$5, _10$$5);
		ZEPHIR_CPY_WRT(controller, _11$$5);
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_12$$5, "array_shift", &_6, 5, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_get_strval(_13$$5, _12$$5);
		ZEPHIR_CPY_WRT(action, _13$$5);
		break;
	} while(0);

	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_VSV(_14, controller, "/", action);
	zephir_update_property_this(this_ptr, SL("id"), _14 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_15, nc_std_ce, "camelcase", &_16, 17, controller);
	zephir_check_call_status();
	zephir_get_strval(_17, _15);
	ZEPHIR_CPY_WRT(controllerName, _17);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("controllerFactory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_19, _18, "__isset", NULL, 0, controllerName);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_19))) {
		ZEPHIR_INIT_VAR(_20$$6);
		object_init_ex(_20$$6, nc_router_notfoundexception_ce);
		ZEPHIR_INIT_VAR(_21$$6);
		ZEPHIR_CONCAT_SV(_21$$6, "Controller not found: ", controller);
		ZEPHIR_CALL_METHOD(NULL, _20$$6, "__construct", NULL, 2, _21$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_20$$6, "nc/router/controlleraction.zep", 81 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(actionVar);
	array_init(actionVar);
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("controllerFactory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_23, _22, "__get", NULL, 0, controllerName);
	zephir_check_call_status();
	zephir_array_append(&actionVar, _23, PH_SEPARATE, "nc/router/controlleraction.zep", 85);
	ZEPHIR_CALL_CE_STATIC(&_24, nc_std_ce, "camelcase", &_16, 17, action);
	zephir_check_call_status();
	_25 = zephir_fetch_nproperty_this(this_ptr, SL("actionSuffix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_26);
	ZEPHIR_CONCAT_VV(_26, _24, _25);
	zephir_array_append(&actionVar, _26, PH_SEPARATE, "nc/router/controlleraction.zep", 86);
	if (unlikely(!(zephir_is_callable(actionVar TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_27$$7);
		object_init_ex(_27$$7, nc_router_notfoundexception_ce);
		_28$$7 = zephir_fetch_nproperty_this(this_ptr, SL("id"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_29$$7);
		ZEPHIR_CONCAT_SV(_29$$7, "Action not found: ", _28$$7);
		ZEPHIR_CALL_METHOD(NULL, _27$$7, "__construct", NULL, 2, _29$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_27$$7, "nc/router/controlleraction.zep", 89 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_30);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_30, actionVar, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

