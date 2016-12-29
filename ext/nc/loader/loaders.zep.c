
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Loader_Loaders) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, Loaders, nc, loader_loaders, nc_loader_loaderabstract_ce, nc_loader_loaders_method_entry, 0);

	zend_declare_property_null(nc_loader_loaders_ce, SL("loaders"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_loader_loaders_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Nc_Loader_Loaders, offsetSet) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *loader, loader_sub, _1$$3;
	zval name, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&loader_sub);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &loader);

	zephir_get_strval(&name, name_param);


	_0 = Z_TYPE_P(loader) != IS_OBJECT;
	if (!(_0)) {
		_0 = !((zephir_instance_of_ev(loader, nc_loader_loaderinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Invalid loader: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/loader/loaders.zep", 10 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("loaders"), &name, loader TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_Loaders, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, loader, _0, _1$$3;
	zval name, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_OBS_VAR(&loader);
	zephir_read_property(&_0, this_ptr, SL("loaders"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!(zephir_array_isset_fetch(&loader, &_0, &name, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Undefined loader: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/loader/loaders.zep", 21 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(loader);

}

PHP_METHOD(Nc_Loader_Loaders, offsetExists) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("loaders"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

PHP_METHOD(Nc_Loader_Loaders, offsetUnset) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("loaders"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_Loaders, findPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, loader, path, _0, _1$$3, *_2$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("loaders"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		zephir_read_property(&_1$$3, this_ptr, SL("loaders"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "nc/loader/loaders.zep", 48);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&loader);
			ZVAL_COPY(&loader, _2$$3);
			ZEPHIR_CALL_METHOD(&path, &loader, "findpath", NULL, 0, &name);
			zephir_check_call_status();
			if (zephir_fast_strlen_ev(&path) > 0) {
				RETURN_CCTOR(path);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&loader);
	}
	RETURN_MM_STRING("");

}

