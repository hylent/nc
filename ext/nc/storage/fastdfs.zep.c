
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Fastdfs) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Storage, Fastdfs, nc, storage_fastdfs, nc_storage_storageabstract_ce, nc_storage_fastdfs_method_entry, 0);

	zend_declare_property_null(nc_storage_fastdfs_ce, SL("prefixGroups"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Storage_Fastdfs, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefixGroups_param = NULL, _0, _1;
	zval prefixGroups;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefixGroups);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefixGroups_param);

	if (!prefixGroups_param) {
		ZEPHIR_INIT_VAR(&prefixGroups);
		array_init(&prefixGroups);
	} else {
		zephir_get_arrval(&prefixGroups, prefixGroups_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "fastdfs_client");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 29, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_exception_ce, "Missing extension 'fastdfs_client'", "nc/storage/fastdfs.zep", 10);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("prefixGroups"), &prefixGroups);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Fastdfs, store) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	long type;
	zval *src_param = NULL, *pre_param = NULL, *ext_param = NULL, *type_param = NULL, extArg, groupArg, destUri, _0, _1, _2;
	zval src, pre, ext, fun;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&pre);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&fun);
	ZVAL_UNDEF(&extArg);
	ZVAL_UNDEF(&groupArg);
	ZVAL_UNDEF(&destUri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &src_param, &pre_param, &ext_param, &type_param);

	zephir_get_strval(&src, src_param);
	if (!pre_param) {
		ZEPHIR_INIT_VAR(&pre);
		ZVAL_STRING(&pre, "");
	} else {
		zephir_get_strval(&pre, pre_param);
	}
	if (!ext_param) {
		ZEPHIR_INIT_VAR(&ext);
		ZVAL_STRING(&ext, "");
	} else {
		zephir_get_strval(&ext, ext_param);
	}
	if (!type_param) {
		type = 1;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_INIT_VAR(&extArg);
	ZVAL_NULL(&extArg);
	ZEPHIR_INIT_VAR(&fun);
	ZVAL_STRING(&fun, "fastdfs_storage_upload_by_filename1");
	if (zephir_fast_strlen_ev(&ext) > 0) {
		ZEPHIR_CPY_WRT(&extArg, &ext);
	}
	ZEPHIR_OBS_VAR(&groupArg);
	zephir_read_property(&_1, this_ptr, SL("prefixGroups"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&groupArg, &_1, &pre, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(&groupArg);
		ZVAL_NULL(&groupArg);
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_ZVAL_FUNCTION(&destUri, &fun, NULL, 0, &src, &extArg, &_2, &groupArg);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&destUri))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_exception_ce, "Cannot store file", "nc/storage/fastdfs.zep", 30);
		return;
	}
	do {
		if (type == 3 || type == 2) {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 39, &src);
			zephir_check_call_status();
			break;
		}
	} while(0);

	ZEPHIR_CONCAT_SV(return_value, "/", &destUri);
	RETURN_MM();

}

PHP_METHOD(Nc_Storage_Fastdfs, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, _0, _1;
	zval uri, fun;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&fun);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(&uri, uri_param);


	ZEPHIR_INIT_VAR(&fun);
	ZVAL_STRING(&fun, "fastdfs_storage_delete_file1");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &uri, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&fun, NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Storage_Fastdfs, exists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, _0, _1;
	zval uri, fun;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&fun);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(&uri, uri_param);


	ZEPHIR_INIT_VAR(&fun);
	ZVAL_STRING(&fun, "fastdfs_storage_file_exist1");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &uri, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&fun, NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

