
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Loader_NamePath) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, NamePath, nc, loader_namepath, nc_loader_loaderabstract_ce, nc_loader_namepath_method_entry, 0);

	zend_declare_property_null(nc_loader_namepath_ce, SL("namePaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_NamePath, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *namePaths_param = NULL;
	zval namePaths;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&namePaths);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &namePaths_param);

	if (!namePaths_param) {
		ZEPHIR_INIT_VAR(&namePaths);
		array_init(&namePaths);
	} else {
		zephir_get_arrval(&namePaths, namePaths_param);
	}


	if (zephir_fast_count_int(&namePaths TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setnamepaths", NULL, 0, &namePaths);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamePath, setNamePaths) {

	zval _3$$3;
	zend_string *_2;
	zend_ulong _1;
	zval *namePaths_param = NULL, n, p, *_0, _4$$3;
	zval namePaths;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&namePaths);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&p);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namePaths_param);

	zephir_get_arrval(&namePaths, namePaths_param);


	zephir_is_iterable(&namePaths, 0, "nc/loader/namepath.zep", 21);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namePaths), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&n);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&n, _2);
		} else {
			ZVAL_LONG(&n, _1);
		}
		ZEPHIR_INIT_NVAR(&p);
		ZVAL_COPY(&p, _0);
		zephir_get_strval(&_3$$3, &p);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_fast_strtolower(&_4$$3, &n);
		zephir_update_property_array(this_ptr, SL("namePaths"), &_4$$3, &_3$$3 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&p);
	ZEPHIR_INIT_NVAR(&n);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamePath, setNamePath) {

	zval *name_param = NULL, *path_param = NULL, _0, _1;
	zval name, path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &path_param);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&path, path_param);


	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &name);
	zephir_update_property_array(this_ptr, SL("namePaths"), &_1, &path TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamePath, hasName) {

	zval *name_param = NULL, _0, _1, _2;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("namePaths"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtolower(&_2, &name);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_2));

}

PHP_METHOD(Nc_Loader_NamePath, findPath) {

	zval *name_param = NULL, path, _0, _1, _2;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("namePaths"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtolower(&_2, &name);
	if (zephir_array_isset_fetch(&path, &_0, &_2, 1 TSRMLS_CC)) {
		RETURN_CTOR(path);
	}
	RETURN_MM_STRING("");

}

