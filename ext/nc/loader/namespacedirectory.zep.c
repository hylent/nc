
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
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Loader_NamespaceDirectory) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, NamespaceDirectory, nc, loader_namespacedirectory, nc_loader_loaderabstract_ce, nc_loader_namespacedirectory_method_entry, 0);

	zend_declare_property_null(nc_loader_namespacedirectory_ce, SL("namespaceDirectories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, __construct) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *namespaceDirectories = NULL;
	zval *registerSelf_param = NULL, *namespaceDirectories_param = NULL, *n = NULL, *d = NULL, *_1, **_4, *_5$$3 = NULL;
	zend_bool registerSelf;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &registerSelf_param, &namespaceDirectories_param);

	if (!registerSelf_param) {
		registerSelf = 0;
	} else {
		registerSelf = zephir_get_boolval(registerSelf_param);
	}
	if (!namespaceDirectories_param) {
		ZEPHIR_INIT_VAR(namespaceDirectories);
		array_init(namespaceDirectories);
	} else {
		zephir_get_arrval(namespaceDirectories, namespaceDirectories_param);
	}


	ZEPHIR_INIT_VAR(_1);
	if (registerSelf) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, nc_loader_namespacedirectory_ce, this_ptr, "__construct", &_0, 80, _1);
	zephir_check_call_status();
	zephir_is_iterable(namespaceDirectories, &_3, &_2, 0, 0, "nc/loader/namespacedirectory.zep", 16);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(n, _3, _2);
		ZEPHIR_GET_HVALUE(d, _4);
		ZEPHIR_INIT_NVAR(_5$$3);
		zephir_fast_strtolower(_5$$3, n);
		zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _5$$3, d TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, __invoke) {

	zend_bool found, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_13 = NULL;
	zval *name_param = NULL, *match = NULL, *pos = NULL, *dir = NULL, *_0 = NULL, _6, *_8, _9, _10, *_11, *_12 = NULL, _1$$3 = zval_used_for_init, *_4$$3 = NULL, *_5$$3, *_14$$8;
	zval *name = NULL, *path = NULL, *_7 = NULL, *_15$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	found = 0;
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, name);
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
		ZEPHIR_OBS_NVAR(dir);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("namespaceDirectories"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&dir, _5$$3, match, 0 TSRMLS_CC)) {
			found = 1;
			break;
		}
	}
	if (!(found)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, (zephir_get_numberval(pos) + 1));
	ZEPHIR_INIT_NVAR(_0);
	zephir_substr(_0, name, zephir_get_intval(&_6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(_7, _0);
	ZEPHIR_CPY_WRT(path, _7);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "\\", 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "/", 0);
	zephir_fast_str_replace(&_8, &_9, &_10, path TSRMLS_CC);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_VSVS(_11, dir, "/", _8, ".php");
	zephir_get_strval(path, _11);
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_CE_STATIC(&_12, nc_loader_loaderabstract_ce, "isloaded", &_13, 81, name);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_12))) {
		ZEPHIR_INIT_VAR(_14$$8);
		object_init_ex(_14$$8, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_15$$8);
		ZEPHIR_CONCAT_SVSV(_15$$8, "Cannot load: ", name, ", in path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _14$$8, "__construct", NULL, 2, _15$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_14$$8, "nc/loader/namespacedirectory.zep", 51 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, set) {

	zval *ns_param = NULL, *dir_param = NULL, *_0 = NULL, *_1;
	zval *ns = NULL, *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns_param, &dir_param);

	zephir_get_strval(ns, ns_param);
	zephir_get_strval(dir, dir_param);


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, ns);
	zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _1, dir TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

