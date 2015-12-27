
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
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Router_Action) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Router, Action, nc, router_action, nc_router_routerabstract_ce, nc_router_action_method_entry, 0);

	zend_declare_property_null(nc_router_action_ce, SL("actionFactory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(nc_router_action_ce, SL("defaultAction"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_router_action_ce, SL("DEFAULT_ACTION"), "index" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Router_Action, __construct) {

	zval *actionFactory;

	zephir_fetch_params(0, 1, 0, &actionFactory);



	zephir_update_property_this(this_ptr, SL("actionFactory"), actionFactory TSRMLS_CC);

}

PHP_METHOD(Nc_Router_Action, getActionFactory) {

	

	RETURN_MEMBER(this_ptr, "actionFactory");

}

PHP_METHOD(Nc_Router_Action, setDefaultAction) {

	zval *defaultAction_param = NULL;
	zval *defaultAction = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultAction_param);

	zephir_get_strval(defaultAction, defaultAction_param);


	zephir_update_property_this(this_ptr, SL("defaultAction"), defaultAction TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Router_Action, getDefaultAction) {

	

	RETURN_MEMBER(this_ptr, "defaultAction");

}

PHP_METHOD(Nc_Router_Action, route) {

	zval *action = NULL, *actionName = NULL, *_6 = NULL, *_1$$3 = NULL, *_3$$4 = NULL, *_10$$5, *_13$$6;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, *actionVar = NULL, *_4 = NULL, *_7, *_8 = NULL, *_11, *_14, *_0$$3, *_2$$4 = NULL, *_9$$5, *_12$$6;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(params, params_param);


	if (zephir_fast_count_int(params TSRMLS_CC) < 1) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("defaultAction"), PH_NOISY_CC);
		zephir_get_strval(_1$$3, _0$$3);
		ZEPHIR_CPY_WRT(action, _1$$3);
	} else {
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_2$$4, "array_shift", NULL, 5, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_get_strval(_3$$4, _2$$4);
		ZEPHIR_CPY_WRT(action, _3$$4);
	}
	zephir_update_property_this(this_ptr, SL("id"), action TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_4, nc_std_ce, "camelcase", &_5, 17, action);
	zephir_check_call_status();
	zephir_get_strval(_6, _4);
	ZEPHIR_CPY_WRT(actionName, _6);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("actionFactory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_8, _7, "__isset", NULL, 0, actionName);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_8))) {
		ZEPHIR_INIT_VAR(_9$$5);
		object_init_ex(_9$$5, nc_router_notfoundexception_ce);
		ZEPHIR_INIT_VAR(_10$$5);
		ZEPHIR_CONCAT_SV(_10$$5, "Action not found: ", action);
		ZEPHIR_CALL_METHOD(NULL, _9$$5, "__construct", NULL, 2, _10$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9$$5, "nc/router/action.zep", 48 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("actionFactory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&actionVar, _11, "__get", NULL, 0, actionName);
	zephir_check_call_status();
	if (unlikely(!(zephir_is_callable(actionVar TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_12$$6);
		object_init_ex(_12$$6, nc_router_exception_ce);
		ZEPHIR_INIT_VAR(_13$$6);
		ZEPHIR_CONCAT_SV(_13$$6, "Invalid action: ", action);
		ZEPHIR_CALL_METHOD(NULL, _12$$6, "__construct", NULL, 2, _13$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12$$6, "nc/router/action.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_14, actionVar, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

