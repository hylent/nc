
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Nc_Loader_NamePath) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, NamePath, nc, loader_namepath, nc_loader_loaderabstract_ce, nc_loader_namepath_method_entry, 0);

	zend_declare_property_null(nc_loader_namepath_ce, SL("namePaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_NamePath, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *namePaths = NULL;
	zval *registerSelf_param = NULL, *namePaths_param = NULL, *_1;
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
	ZEPHIR_CALL_PARENT(NULL, nc_loader_namepath_ce, this_ptr, "__construct", &_0, 76, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("namePaths"), namePaths TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamePath, __invoke) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path = NULL, *_0, *_1 = NULL, *_2, *_5 = NULL, *_3$$4, *_7$$6, *_8$$6;
	zval *name = NULL, *_4$$4;

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
	if (unlikely(Z_TYPE_P(path) != IS_STRING)) {
		ZEPHIR_INIT_VAR(_3$$4);
		object_init_ex(_3$$4, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_CONCAT_SV(_4$$4, "Invalid autoload path option: ", name);
		ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 2, _4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$4, "nc/loader/namepath.zep", 23 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_CE_STATIC(&_5, nc_loader_loaderabstract_ce, "isloaded", &_6, 77, name);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_7$$6);
		object_init_ex(_7$$6, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_8$$6);
		ZEPHIR_CONCAT_SVSV(_8$$6, "Cannot load: ", name, ", in path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _7$$6, "__construct", NULL, 2, _8$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$6, "nc/loader/namepath.zep", 33 TSRMLS_CC);
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

