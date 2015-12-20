
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Loader_LoaderAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Loader, LoaderAbstract, nc, loader_loaderabstract, nc_loader_loaderabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_LoaderAbstract, isLoaded) {

	zend_bool x;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1, _2, *_3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	x = 0;
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (x ? 1 : 0));
	if (zephir_class_exists(name, zephir_is_true(&_0)  TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (x ? 1 : 0));
	if (zephir_interface_exists(name, zephir_is_true(&_1)  TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_BOOL(&_2, (x ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&_3, "trait_exists", NULL, 23, name, &_2);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(x);

}

PHP_METHOD(Nc_Loader_LoaderAbstract, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *registerSelf_param = NULL, *_1 = NULL;
	zend_bool registerSelf, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &registerSelf_param);

	if (!registerSelf_param) {
		registerSelf = 0;
	} else {
		registerSelf = zephir_get_boolval(registerSelf_param);
	}


	_0 = registerSelf;
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "register", NULL, 0);
		zephir_check_call_status();
		_0 = !zephir_is_true(_1);
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_loader_exception_ce, "Cannot register loader", "nc/loader/loaderabstract.zep", 27);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_LoaderAbstract, register) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_register", NULL, 24, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Loader_LoaderAbstract, unregister) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_unregister", NULL, 25, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Loader_LoaderAbstract, __invoke) {

}

