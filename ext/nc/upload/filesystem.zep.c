
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


ZEPHIR_INIT_CLASS(Nc_Upload_FileSystem) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Upload, FileSystem, nc, upload_filesystem, nc_upload_storageabstract_ce, nc_upload_filesystem_method_entry, 0);

	zend_declare_property_null(nc_upload_filesystem_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Upload_FileSystem, __construct) {

	zval *baseDirectory_param = NULL;
	zval *baseDirectory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseDirectory_param);

	zephir_get_strval(baseDirectory, baseDirectory_param);


	zephir_update_property_this(this_ptr, SL("baseDirectory"), baseDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Upload_FileSystem, store) {

	zend_bool _5;
	int ZEPHIR_LAST_CALL_STATUS;
	long flag;
	zval *source_param = NULL, *prefix_param = NULL, *extension_param = NULL, *flag_param = NULL, *temp = NULL, *success = NULL, *_0 = NULL, *_2, *_3, *_4 = NULL, _6, *_7 = NULL, *_8$$3, *_9$$3;
	zval *source = NULL, *prefix = NULL, *extension = NULL, *destUri = NULL, *destPath = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &source_param, &prefix_param, &extension_param, &flag_param);

	zephir_get_strval(source, source_param);
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}
	if (!flag_param) {
		flag = 0;
	} else {
		flag = zephir_get_intval(flag_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generateuri", NULL, 0, source, prefix, extension);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(destUri, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, destUri);
	zephir_get_strval(destPath, _3);
	ZEPHIR_CALL_FUNCTION(&temp, "dirname", NULL, 120, destPath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "is_dir", NULL, 131, temp);
	zephir_check_call_status();
	_5 = !zephir_is_true(_4);
	if (_5) {
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, 0755);
		ZEPHIR_CALL_FUNCTION(&_7, "mkdir", NULL, 121, temp, &_6, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_5 = !zephir_is_true(_7);
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_VAR(_8$$3);
		object_init_ex(_8$$3, nc_upload_exception_ce);
		ZEPHIR_INIT_VAR(_9$$3);
		ZEPHIR_CONCAT_SV(_9$$3, "Cannot mkdir: ", temp);
		ZEPHIR_CALL_METHOD(NULL, _8$$3, "__construct", NULL, 2, _9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$3, "nc/upload/filesystem.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (flag == 2) {
			ZEPHIR_CALL_FUNCTION(&success, "move_uploaded_file", NULL, 132, source, destPath);
			zephir_check_call_status();
			break;
		}
		if (flag == 1) {
			ZEPHIR_CALL_FUNCTION(&success, "rename", NULL, 133, source, destPath);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_CALL_FUNCTION(&success, "copy", NULL, 134, source, destPath);
		zephir_check_call_status();
		break;
	} while(0);

	if (zephir_is_true(success)) {
		RETURN_CTOR(destUri);
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Nc_Upload_FileSystem, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *path = NULL, *_0;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VV(path, _0, uri);
	if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 119, path);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Upload_FileSystem, exists) {

	zval *uri_param = NULL, *_0, *_1;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, uri);
	RETURN_MM_BOOL((zephir_file_exists(_1 TSRMLS_CC) == SUCCESS));

}

