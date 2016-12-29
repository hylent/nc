
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Loader_LoaderAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Loader, LoaderAbstract, nc, loader_loaderabstract, nc_loader_loaderabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_loader_loaderabstract_ce, SL("loadedNamePaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_loader_loaderabstract_ce TSRMLS_CC, 1, nc_loader_loaderinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Loader_LoaderAbstract, register) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, __$false, _0;
	zend_bool prepend;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prepend_param);

	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZVAL_BOOL(&_0, (prepend ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_register", NULL, 3, this_ptr, &__$false, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Loader_LoaderAbstract, unregister) {

	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_unregister", NULL, 4, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Loader_LoaderAbstract, __invoke) {

	zend_bool x, _0, _2, _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, path, _1, _3, _5, _6, _7$$4, _8$$4, _9$$4;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	x = 0;
	ZEPHIR_CALL_METHOD(&path, this_ptr, "findpath", NULL, 0, &name);
	zephir_check_call_status();
	_0 = zephir_fast_strlen_ev(&path) < 1;
	if (!(_0)) {
		_0 = !((zephir_file_exists(&path TSRMLS_CC) == SUCCESS));
	}
	if (_0) {
		RETURN_MM_BOOL(x);
	}
	if (zephir_require_zval(&path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZVAL_BOOL(&_1, (x ? 1 : 0));
	_2 = !(zephir_class_exists(&name, zephir_is_true(&_1)  TSRMLS_CC));
	if (_2) {
		ZVAL_BOOL(&_3, (x ? 1 : 0));
		_2 = !(zephir_interface_exists(&name, zephir_is_true(&_3)  TSRMLS_CC));
	}
	_4 = _2;
	if (_4) {
		ZVAL_BOOL(&_5, (x ? 1 : 0));
		ZEPHIR_CALL_FUNCTION(&_6, "trait_exists", NULL, 5, &name, &_5);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_6);
	}
	if (unlikely(_4)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		object_init_ex(&_7$$4, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "Cannot load '%s' in path '%s'");
		ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", NULL, 6, &_8$$4, &name, &path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 7, &_9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$4, "nc/loader/loaderabstract.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("loadedNamePaths"), &name, &path TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Loader_LoaderAbstract, getLoadedNamePaths) {

	zval loadedNamePaths, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&loadedNamePaths);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("loadedNamePaths"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&loadedNamePaths, &_0);
	if (zephir_fast_count_int(&loadedNamePaths TSRMLS_CC) > 0) {
		RETURN_CCTOR(loadedNamePaths);
	}
	array_init(return_value);
	RETURN_MM();

}

