
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

	zval *_1 = NULL;
	zval *action = NULL, *actionName = NULL, *_8 = NULL, *_3$$3 = NULL, *_5$$4 = NULL, *_12$$5, *_15$$6;
	zval *source = NULL, *actionVar = NULL, *_0 = NULL, *_6 = NULL, *_9, *_10 = NULL, *_13, *_16, *_2$$3, *_4$$4 = NULL, *_11$$5, *_14$$6;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	zephir_get_arrval(_1, _0);
	ZEPHIR_CPY_WRT(source, _1);
	if (zephir_fast_count_int(source TSRMLS_CC) < 1) {
		ZEPHIR_OBS_VAR(_2$$3);
		zephir_read_property_this(&_2$$3, this_ptr, SL("defaultAction"), PH_NOISY_CC);
		zephir_get_strval(_3$$3, _2$$3);
		ZEPHIR_CPY_WRT(action, _3$$3);
	} else {
		ZEPHIR_MAKE_REF(source);
		ZEPHIR_CALL_FUNCTION(&_4$$4, "array_shift", NULL, 6, source);
		ZEPHIR_UNREF(source);
		zephir_check_call_status();
		zephir_get_strval(_5$$4, _4$$4);
		ZEPHIR_CPY_WRT(action, _5$$4);
	}
	zephir_update_property_this(this_ptr, SL("id"), action TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_6, nc_std_ce, "camelcase", &_7, 105, action);
	zephir_check_call_status();
	zephir_get_strval(_8, _6);
	ZEPHIR_CPY_WRT(actionName, _8);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("actionFactory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_10, _9, "__isset", NULL, 0, actionName);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_10))) {
		ZEPHIR_INIT_VAR(_11$$5);
		object_init_ex(_11$$5, nc_router_notfoundexception_ce);
		ZEPHIR_INIT_VAR(_12$$5);
		ZEPHIR_CONCAT_SV(_12$$5, "Action not found: ", action);
		ZEPHIR_CALL_METHOD(NULL, _11$$5, "__construct", NULL, 2, _12$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_11$$5, "nc/router/action.zep", 51 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("actionFactory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&actionVar, _13, "__get", NULL, 0, actionName);
	zephir_check_call_status();
	if (unlikely(!(zephir_is_callable(actionVar TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_14$$6);
		object_init_ex(_14$$6, nc_router_notfoundexception_ce);
		ZEPHIR_INIT_VAR(_15$$6);
		ZEPHIR_CONCAT_SV(_15$$6, "Invalid action: ", action);
		ZEPHIR_CALL_METHOD(NULL, _14$$6, "__construct", NULL, 2, _15$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_14$$6, "nc/router/action.zep", 56 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CALL_USER_FUNC_ARRAY(_16, actionVar, source);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

