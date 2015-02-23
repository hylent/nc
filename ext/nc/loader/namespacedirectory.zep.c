
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
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Nc_Loader_NamespaceDirectory) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, NamespaceDirectory, nc, loader_namespacedirectory, nc_loader_loaderabstract_ce, nc_loader_namespacedirectory_method_entry, 0);

	zend_declare_property_null(nc_loader_namespacedirectory_ce, SL("namespaceDirectories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, __construct) {

	HashTable *_1;
	HashPosition _0;
	zval *namespaceDirectories_param = NULL, *n = NULL, *a = NULL, **_2, *_3 = NULL;
	zval *namespaceDirectories = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &namespaceDirectories_param);

	if (!namespaceDirectories_param) {
		ZEPHIR_INIT_VAR(namespaceDirectories);
		array_init(namespaceDirectories);
	} else {
		zephir_get_arrval(namespaceDirectories, namespaceDirectories_param);
	}


	zephir_is_iterable(namespaceDirectories, &_1, &_0, 0, 0, "nc/loader/namespacedirectory.zep", 18);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(n, _1, _0);
		ZEPHIR_GET_HVALUE(a, _2);
		if (Z_TYPE_P(a) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_3);
			zephir_fast_strtolower(_3, n);
			zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _3, a TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_4);
			array_init_size(_4, 3);
			zephir_array_fast_append(_4, a);
			zephir_array_fast_append(_4, ZEPHIR_GLOBAL(global_true));
			ZEPHIR_INIT_NVAR(_3);
			zephir_fast_strtolower(_3, n);
			zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _3, _4 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zend_bool found = 0, _3;
	zval *className_param = NULL, *match = NULL, *pos = NULL, *arr = NULL, *_0 = NULL, _1 = zval_used_for_init, *_4 = NULL, *_6, *_7 = NULL, *_9, *_10, *_11, _12, *_13;
	zval *className = NULL, *path = NULL, *_8 = NULL, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, className);
	ZEPHIR_CPY_WRT(match, _0);
	while (1) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "\\", 0);
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_2, match, &_1);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(pos);
		if (!(_3)) {
			_3 = ZEPHIR_LT_LONG(pos, 1);
		}
		if (_3) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_5, match, &_1, pos);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(match, _4);
		ZEPHIR_OBS_NVAR(arr);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("namespaceDirectories"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&arr, _6, match, 0 TSRMLS_CC)) {
			found = 1;
			break;
		}
	}
	if (!(found)) {
		RETURN_MM_BOOL(0);
	}
	_3 = Z_TYPE_P(arr) != IS_ARRAY;
	if (!(_3)) {
		_3 = zephir_fast_count_int(arr TSRMLS_CC) != 2;
	}
	if (unlikely(_3)) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, "Invalid namespace directory options: ", match);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "nc/loader/namespacedirectory.zep", 44 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(pos) + 1));
	ZEPHIR_CALL_FUNCTION(&_4, "substr", &_5, className, &_1);
	zephir_check_call_status();
	zephir_get_strval(_8, _4);
	ZEPHIR_CPY_WRT(path, _8);
	zephir_array_fetch_long(&_9, arr, 1, PH_NOISY | PH_READONLY, "nc/loader/namespacedirectory.zep", 48 TSRMLS_CC);
	if (zephir_is_true(_9)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_strtolower(_0, path);
		zephir_get_strval(path, _0);
	}
	zephir_array_fetch_long(&_10, arr, 0, PH_NOISY | PH_READONLY, "nc/loader/namespacedirectory.zep", 51 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "/", 0);
	zephir_fast_str_replace(_11, &_1, &_12, path TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_7);
	ZEPHIR_CONCAT_VSVS(_7, _10, "/", _11, ".php");
	zephir_get_strval(path, _7);
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (unlikely(!(zephir_class_exists(className, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_13);
		object_init_ex(_13, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_14);
		ZEPHIR_CONCAT_SVSV(_14, "Cannot find class: ", className, ", in path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _13, "__construct", NULL, _14);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13, "nc/loader/namespacedirectory.zep", 60 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, set) {

	zval *_0;
	zend_bool lcase;
	zval *ns_param = NULL, *dir_param = NULL, *lcase_param = NULL, *_1 = NULL, *_2 = NULL;
	zval *ns = NULL, *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &ns_param, &dir_param, &lcase_param);

	zephir_get_strval(ns, ns_param);
	zephir_get_strval(dir, dir_param);
	if (!lcase_param) {
		lcase = 1;
	} else {
		lcase = zephir_get_boolval(lcase_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, dir);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, lcase);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_fast_strtolower(_1, ns);
	zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _1, _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

