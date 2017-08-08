
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_ControllerDefault) {

	ZEPHIR_REGISTER_CLASS(Nc\\Mvc, ControllerDefault, nc, mvc_controllerdefault, nc_mvc_controllerdefault_method_entry, 0);

	zend_declare_property_null(nc_mvc_controllerdefault_ce, SL("injector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_controllerdefault_ce, SL("context"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_mvc_controllerdefault_ce TSRMLS_CC, 1, nc_mvc_controllerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_ControllerDefault, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *injector, injector_sub, *context, context_sub, re, ex, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injector_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&re);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &injector, &context);



	ZEPHIR_INIT_VAR(&re);
	ZVAL_NULL(&re);
	ZEPHIR_INIT_VAR(&ex);
	ZVAL_NULL(&ex);
	zephir_update_property_zval(this_ptr, SL("injector"), injector);
	zephir_update_property_zval(this_ptr, SL("context"), context);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&re, this_ptr, "execute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_OBJ(&_0, EG(exception));
		Z_ADDREF_P(&_0);
		if (zephir_instance_of_ev(&_0, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&ex, &_0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "onexception", NULL, 0, &ex);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "onreturn", NULL, 0, &re);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ControllerDefault, initialize) {

	zval *this_ptr = getThis();


	RETURN_NULL();

}

PHP_METHOD(Nc_Mvc_ControllerDefault, execute) {

	zval *this_ptr = getThis();


	RETURN_NULL();

}

PHP_METHOD(Nc_Mvc_ControllerDefault, onReturn) {

	zval *re, re_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&re_sub);

	zephir_fetch_params(0, 1, 0, &re);



	RETURN_NULL();

}

PHP_METHOD(Nc_Mvc_ControllerDefault, onException) {

	zval *ex, ex_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ex_sub);

	zephir_fetch_params(0, 1, 0, &ex);



	zephir_throw_exception_debug(ex, "nc/mvc/controllerdefault.zep", 46 TSRMLS_CC);
	return;

}

