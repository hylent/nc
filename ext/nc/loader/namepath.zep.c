
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
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Loader_NamePath) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, NamePath, nc, loader_namepath, nc_loader_loaderabstract_ce, nc_loader_namepath_method_entry, 0);

	zend_declare_property_null(nc_loader_namepath_ce, SL("namePaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_NamePath, __construct) {

	zval *_5$$3 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *namePaths = NULL;
	zval *registerSelf_param = NULL, *namePaths_param = NULL, *n = NULL, *p = NULL, *_1, **_4, *_6$$3 = NULL;
	zend_bool registerSelf;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &registerSelf_param, &namePaths_param);

	if (!registerSelf_param) {
		registerSelf = 0;
	} else {
		registerSelf = zephir_get_boolval(registerSelf_param);
	}
	if (!namePaths_param) {
		ZEPHIR_INIT_VAR(namePaths);
		array_init(namePaths);
	} else {
		zephir_get_arrval(namePaths, namePaths_param);
	}


	ZEPHIR_INIT_VAR(_1);
	if (registerSelf) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, nc_loader_namepath_ce, this_ptr, "__construct", &_0, 81, _1);
	zephir_check_call_status();
	zephir_is_iterable(namePaths, &_3, &_2, 0, 0, "nc/loader/namepath.zep", 16);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(n, _3, _2);
		ZEPHIR_GET_HVALUE(p, _4);
		zephir_get_strval(_5$$3, p);
		ZEPHIR_INIT_NVAR(_6$$3);
		zephir_fast_strtolower(_6$$3, n);
		zephir_update_property_array(this_ptr, SL("namePaths"), _6$$3, _5$$3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamePath, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *name_param = NULL, *path = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_5$$5, *_6$$5;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(path);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("namePaths"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strtolower(_2, name);
	if (!(zephir_array_isset_fetch(&path, _0, _2, 0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_CE_STATIC(&_3, nc_loader_loaderabstract_ce, "isloaded", &_4, 82, name);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_3))) {
		ZEPHIR_INIT_VAR(_5$$5);
		object_init_ex(_5$$5, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_6$$5);
		ZEPHIR_CONCAT_SVSV(_6$$5, "Cannot load: ", name, ", in path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _5$$5, "__construct", NULL, 2, _6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$5, "nc/loader/namepath.zep", 33 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Loader_NamePath, set) {

	zval *name_param = NULL, *path_param = NULL, *_0 = NULL, *_1;
	zval *name = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &path_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(path, path_param);


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, name);
	zephir_update_property_array(this_ptr, SL("namePaths"), _1, path TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

