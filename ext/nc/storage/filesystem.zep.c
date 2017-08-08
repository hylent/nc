
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
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Nc_Storage_FileSystem) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Storage, FileSystem, nc, storage_filesystem, nc_storage_storageabstract_ce, nc_storage_filesystem_method_entry, 0);

	zend_declare_property_null(nc_storage_filesystem_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_storage_filesystem_ce, SL("mode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Storage_FileSystem, __construct) {

	long mode;
	zval *baseDirectory_param = NULL, *mode_param = NULL, _0;
	zval baseDirectory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseDirectory);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &baseDirectory_param, &mode_param);

	zephir_get_strval(&baseDirectory, baseDirectory_param);
	if (!mode_param) {
		mode = 0777;
	} else {
		mode = zephir_get_intval(mode_param);
	}


	zephir_update_property_zval(this_ptr, SL("baseDirectory"), &baseDirectory);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, mode);
	zephir_update_property_zval(this_ptr, SL("mode"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_FileSystem, getBaseDirectory) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "baseDirectory");

}

PHP_METHOD(Nc_Storage_FileSystem, getMode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "mode");

}

PHP_METHOD(Nc_Storage_FileSystem, getPath) {

	zval *uri_param = NULL, _0;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(&uri, uri_param);


	zephir_read_property(&_0, this_ptr, SL("baseDirectory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &uri);
	RETURN_MM();

}

PHP_METHOD(Nc_Storage_FileSystem, store) {

	zend_bool _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	long type;
	zval *src_param = NULL, *pre_param = NULL, *ext_param = NULL, *type_param = NULL, __$true, temp, success, _0, _2, _3, _4, _6, _7, _8$$3, _9$$3, _10$$7;
	zval src, pre, ext, destUri, destPath, _1, _11$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&pre);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&destUri);
	ZVAL_UNDEF(&destPath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$7);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generateuri", NULL, 0, &src, &pre, &ext);
	zephir_check_call_status();
	zephir_get_strval(&_1, &_0);
	ZEPHIR_CPY_WRT(&destUri, &_1);
	zephir_read_property(&_2, this_ptr, SL("baseDirectory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_2, &destUri);
	zephir_get_strval(&destPath, &_3);
	ZEPHIR_CALL_FUNCTION(&temp, "dirname", NULL, 43, &destPath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "is_dir", NULL, 38, &temp);
	zephir_check_call_status();
	_5 = !zephir_is_true(&_4);
	if (_5) {
		zephir_read_property(&_6, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_7, "mkdir", NULL, 44, &temp, &_6, &__$true);
		zephir_check_call_status();
		_5 = !zephir_is_true(&_7);
	}
	if (UNEXPECTED(_5)) {
		ZEPHIR_INIT_VAR(&_8$$3);
		object_init_ex(&_8$$3, nc_storage_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_SV(&_9$$3, "Cannot mkdir: ", &temp);
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "__construct", NULL, 3, &_9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$3, "nc/storage/filesystem.zep", 39 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (type == 3) {
			ZEPHIR_CALL_FUNCTION(&success, "move_uploaded_file", NULL, 136, &src, &destPath);
			zephir_check_call_status();
			break;
		}
		if (type == 2) {
			ZEPHIR_CALL_FUNCTION(&success, "rename", NULL, 137, &src, &destPath);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_CALL_FUNCTION(&success, "copy", NULL, 138, &src, &destPath);
		zephir_check_call_status();
		break;
	} while(0);

	if (UNEXPECTED(!zephir_is_true(&success))) {
		ZEPHIR_INIT_VAR(&_10$$7);
		object_init_ex(&_10$$7, nc_storage_exception_ce);
		ZEPHIR_INIT_VAR(&_11$$7);
		ZEPHIR_CONCAT_SV(&_11$$7, "Cannot store file to path: ", &destPath);
		ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", NULL, 3, &_11$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$7, "nc/storage/filesystem.zep", 57 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&destUri);

}

PHP_METHOD(Nc_Storage_FileSystem, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, path;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(&uri, uri_param);


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0, &uri);
	zephir_check_call_status();
	if ((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 39, &path);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Storage_FileSystem, exists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, _0;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(&uri, uri_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpath", NULL, 0, &uri);
	zephir_check_call_status();
	RETURN_MM_BOOL((zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS));

}

