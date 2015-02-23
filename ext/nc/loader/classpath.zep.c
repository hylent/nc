
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Nc_Loader_ClassPath) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, ClassPath, nc, loader_classpath, nc_loader_loaderabstract_ce, nc_loader_classpath_method_entry, 0);

	zend_declare_property_null(nc_loader_classpath_ce, SL("classPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_ClassPath, __construct) {

	zval *classPaths_param = NULL;
	zval *classPaths = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &classPaths_param);

	if (!classPaths_param) {
	ZEPHIR_INIT_VAR(classPaths);
	array_init(classPaths);
	} else {
		zephir_get_arrval(classPaths, classPaths_param);
	}


	zephir_update_property_this(this_ptr, SL("classPaths"), classPaths TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_ClassPath, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *path, *_0, *_1 = NULL, *_2, *_3 = NULL, *_5;
	zval *className = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_OBS_VAR(path);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("classPaths"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strtolower(_2, className);
	if (!(zephir_array_isset_fetch(&path, _0, _2, 0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	if (unlikely(Z_TYPE_P(path) != IS_STRING)) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Invalid class path option: ", className);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "nc/loader/classpath.zep", 21 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (unlikely(!(zephir_class_exists(className, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC)))) {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, nc_loader_exception_ce);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVSV(_5, "Cannot find class: ", className, ", in path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "nc/loader/classpath.zep", 31 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Loader_ClassPath, set) {

	zval *className_param = NULL, *path_param = NULL, *_0 = NULL, *_1;
	zval *className = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &path_param);

	zephir_get_strval(className, className_param);
	zephir_get_strval(path, path_param);


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, className);
	zephir_update_property_array(this_ptr, SL("classPaths"), _1, path TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

