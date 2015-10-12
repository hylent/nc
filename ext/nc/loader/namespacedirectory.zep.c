
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
	zval *namespaceDirectories_param = NULL, *n = NULL, *a = NULL, **_2, *_3$$4 = NULL, *_5$$5 = NULL;
	zval *namespaceDirectories = NULL, *_4$$5 = NULL;

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
			ZEPHIR_INIT_NVAR(_3$$4);
			zephir_fast_strtolower(_3$$4, n);
			zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _3$$4, a TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_4$$5);
			zephir_create_array(_4$$5, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_4$$5, a);
			zephir_array_fast_append(_4$$5, ZEPHIR_GLOBAL(global_true));
			ZEPHIR_INIT_NVAR(_5$$5);
			zephir_fast_strtolower(_5$$5, n);
			zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _5$$5, _4$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, __invoke) {

	zend_bool found, _6, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *className_param = NULL, *match = NULL, *pos = NULL, *arr = NULL, *_0 = NULL, _9, *_11, *_13, *_14, _15, _16, *_17, _1$$3 = zval_used_for_init, *_4$$3 = NULL, *_5$$3, *_7$$7, *_8$$7, *_12$$8, *_18$$10;
	zval *className = NULL, *path = NULL, *_10 = NULL, *_19$$10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	found = 0;
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, className);
	ZEPHIR_CPY_WRT(match, _0);
	while (1) {
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_STRING(&_1$$3, "\\", 0);
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_2, 82, match, &_1$$3);
		zephir_check_call_status();
		_3$$3 = ZEPHIR_IS_FALSE_IDENTICAL(pos);
		if (!(_3$$3)) {
			_3$$3 = ZEPHIR_LT_LONG(pos, 1);
		}
		if (_3$$3) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_LONG(&_1$$3, 0);
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_substr(_4$$3, match, 0 , zephir_get_intval(pos), 0);
		ZEPHIR_CPY_WRT(match, _4$$3);
		ZEPHIR_OBS_NVAR(arr);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("namespaceDirectories"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&arr, _5$$3, match, 0 TSRMLS_CC)) {
			found = 1;
			break;
		}
	}
	if (!(found)) {
		RETURN_MM_BOOL(0);
	}
	_6 = Z_TYPE_P(arr) != IS_ARRAY;
	if (!(_6)) {
		_6 = zephir_fast_count_int(arr TSRMLS_CC) != 2;
	}
	if (unlikely(_6)) {
		ZEPHIR_INIT_VAR(_7$$7);
		object_init_ex(_7$$7, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_8$$7);
		ZEPHIR_CONCAT_SV(_8$$7, "Invalid namespace directory options: ", match);
		ZEPHIR_CALL_METHOD(NULL, _7$$7, "__construct", NULL, 2, _8$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$7, "nc/loader/namespacedirectory.zep", 44 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, (zephir_get_numberval(pos) + 1));
	ZEPHIR_INIT_NVAR(_0);
	zephir_substr(_0, className, zephir_get_intval(&_9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(_10, _0);
	ZEPHIR_CPY_WRT(path, _10);
	zephir_array_fetch_long(&_11, arr, 1, PH_NOISY | PH_READONLY, "nc/loader/namespacedirectory.zep", 48 TSRMLS_CC);
	if (zephir_is_true(_11)) {
		ZEPHIR_INIT_VAR(_12$$8);
		zephir_fast_strtolower(_12$$8, path);
		zephir_get_strval(path, _12$$8);
	}
	zephir_array_fetch_long(&_13, arr, 0, PH_NOISY | PH_READONLY, "nc/loader/namespacedirectory.zep", 51 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_STRING(&_15, "\\", 0);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_STRING(&_16, "/", 0);
	zephir_fast_str_replace(&_14, &_15, &_16, path TSRMLS_CC);
	ZEPHIR_INIT_VAR(_17);
	ZEPHIR_CONCAT_VSVS(_17, _13, "/", _14, ".php");
	zephir_get_strval(path, _17);
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (unlikely(!(zephir_class_exists(className, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_18$$10);
		object_init_ex(_18$$10, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_19$$10);
		ZEPHIR_CONCAT_SVSV(_19$$10, "Cannot find class: ", className, ", in path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _18$$10, "__construct", NULL, 2, _19$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(_18$$10, "nc/loader/namespacedirectory.zep", 60 TSRMLS_CC);
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
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, dir);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, lcase);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_fast_strtolower(_1, ns);
	zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _1, _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

