
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Nc_Storage_FileSystem) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Storage, FileSystem, nc, storage_filesystem, nc_storage_storageabstract_ce, nc_storage_filesystem_method_entry, 0);

	zend_declare_property_null(nc_storage_filesystem_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Storage_FileSystem, __construct) {

	zval *baseDirectory_param = NULL;
	zval *baseDirectory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseDirectory_param);

	zephir_get_strval(baseDirectory, baseDirectory_param);


	zephir_update_property_this(this_ptr, SL("baseDirectory"), baseDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_FileSystem, store) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_10 = NULL, *_13 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool rm, _7;
	zval *source_param = NULL, *group_param = NULL, *extension_param = NULL, *rm_param = NULL, *temp = NULL, *success = NULL, *_0 = NULL, *_2, *_3, *_5 = NULL, _8, *_9 = NULL, *_11, *_12;
	zval *source = NULL, *group = NULL, *extension = NULL, *destUri = NULL, *destPath = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &source_param, &group_param, &extension_param, &rm_param);

	zephir_get_strval(source, source_param);
	if (!group_param) {
		ZEPHIR_INIT_VAR(group);
		ZVAL_STRING(group, "", 1);
	} else {
		zephir_get_strval(group, group_param);
	}
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}
	if (!rm_param) {
		rm = 0;
	} else {
		rm = zephir_get_boolval(rm_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generateuri", NULL, source, group, extension);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(destUri, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, destUri);
	zephir_get_strval(destPath, _3);
	ZEPHIR_CALL_FUNCTION(&temp, "dirname", &_4, destPath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "is_dir", &_6, temp);
	zephir_check_call_status();
	_7 = !zephir_is_true(_5);
	if (_7) {
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, 0755);
		ZEPHIR_CALL_FUNCTION(&_9, "mkdir", &_10, temp, &_8, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_7 = !zephir_is_true(_9);
	}
	if (unlikely(_7)) {
		ZEPHIR_INIT_VAR(_11);
		object_init_ex(_11, nc_storage_exception_ce);
		ZEPHIR_INIT_VAR(_12);
		ZEPHIR_CONCAT_SV(_12, "Cannot mkdir: ", temp);
		ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, _12);
		zephir_check_call_status();
		zephir_throw_exception_debug(_11, "nc/storage/filesystem.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (rm) {
		ZEPHIR_CALL_FUNCTION(&success, "rename", &_13, source, destPath);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&success, "copy", &_14, source, destPath);
		zephir_check_call_status();
	}
	if (zephir_is_true(success)) {
		RETURN_CTOR(destUri);
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Nc_Storage_FileSystem, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *uri_param = NULL, *path, *_0;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VV(path, _0, uri);
	if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("unlink", &_1, path);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

