
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


ZEPHIR_INIT_CLASS(Nc_Di_CreatorAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Di, CreatorAbstract, nc, di_creatorabstract, nc_di_creatorabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_di_creatorabstract_ce, SL("injector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_di_creatorabstract_ce TSRMLS_CC, 1, nc_di_containerinterface_ce);
	zend_class_implements(nc_di_creatorabstract_ce TSRMLS_CC, 1, nc_di_injectedsetupmethodinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Di_CreatorAbstract, setupByInjector) {

	zval *injector, injector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injector_sub);

	zephir_fetch_params(0, 1, 0, &injector);



	zephir_update_property_zval(this_ptr, SL("injector"), injector);

}

PHP_METHOD(Nc_Di_CreatorAbstract, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalidclassname", NULL, 0, &name);
	zephir_check_call_status();
	zephir_get_strval(&_1, &_0);
	RETURN_MM_BOOL(!ZEPHIR_IS_STRING_IDENTICAL(&_1, ""));

}

PHP_METHOD(Nc_Di_CreatorAbstract, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, className, _0, _2;
	zval name, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalidclassname", NULL, 0, &name);
	zephir_check_call_status();
	zephir_get_strval(&_1, &_0);
	ZEPHIR_CPY_WRT(&className, &_1);
	zephir_read_property(&_2, this_ptr, SL("injector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "__invoke", NULL, 0, &className);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Di_CreatorAbstract, getValidClassName) {

}

