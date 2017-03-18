
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_ContextAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Mvc, ContextAbstract, nc, mvc_contextabstract, nc_mvc_contextabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_mvc_contextabstract_ce, SL("serverVars"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_contextabstract_ce, SL("argVector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_ContextAbstract, getRoutingNames) {

	ZEPHIR_INIT_THIS();


	array_init(return_value);
	return;

}

PHP_METHOD(Nc_Mvc_ContextAbstract, getServerVar) {

	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("serverVars"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextAbstract, getArgVector) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "argVector");

}

PHP_METHOD(Nc_Mvc_ContextAbstract, getParamMap) {

	ZEPHIR_INIT_THIS();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(nc_mvc_exception_ce, "Unaccomplished", "nc/mvc/contextabstract.zep", 31);
	return;

}

PHP_METHOD(Nc_Mvc_ContextAbstract, getParam) {

	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_mvc_exception_ce, "Unaccomplished", "nc/mvc/contextabstract.zep", 36);
	return;

}

PHP_METHOD(Nc_Mvc_ContextAbstract, getRequestTime) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "REQUEST_TIME");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getservervar", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextAbstract, getRequestTimeFloat) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "REQUEST_TIME_FLOAT");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getservervar", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextAbstract, output) {

	zval *content_param = NULL;
	zval content;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	zend_print_zval(&content, 0);
	ZEPHIR_MM_RESTORE();

}

