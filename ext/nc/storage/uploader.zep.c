
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Uploader) {

	ZEPHIR_REGISTER_CLASS(Nc\\Storage, Uploader, nc, storage_uploader, nc_storage_uploader_method_entry, 0);

	zend_declare_property_null(nc_storage_uploader_ce, SL("storageBackend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_storage_uploader_ce, SL("validExtensions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_storage_uploader_ce, SL("maxSize"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_storage_uploader_ce, SL("lastError"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_storage_uploader_ce, SL("fileArray"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_storage_uploader_ce, SL("FILE_ARRAY_NOT_FOUND"), 0x11 TSRMLS_CC);

	zend_declare_class_constant_long(nc_storage_uploader_ce, SL("FILE_ARRAY_MISSING_VALUE"), 0x12 TSRMLS_CC);

	zend_declare_class_constant_long(nc_storage_uploader_ce, SL("SIZE_TOO_LARGE"), 0x13 TSRMLS_CC);

	zend_declare_class_constant_long(nc_storage_uploader_ce, SL("EXTENSION_INVALID"), 0x14 TSRMLS_CC);

	zend_declare_class_constant_long(nc_storage_uploader_ce, SL("STORAGE_FAILED"), 0x15 TSRMLS_CC);

	zend_class_implements(nc_storage_uploader_ce TSRMLS_CC, 1, nc_storage_backend_storagebackendawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Storage_Uploader, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_10 = NULL;
	zval *validExtensions_param = NULL, *maxSize_param = NULL, *_0 = NULL, *_1, _2, _3, _4, *_5 = NULL, *_7 = NULL, *_9 = NULL;
	zval *validExtensions = NULL, *maxSize = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &validExtensions_param, &maxSize_param);

	zephir_get_strval(validExtensions, validExtensions_param);
	if (!maxSize_param) {
		ZEPHIR_INIT_VAR(maxSize);
		ZVAL_STRING(maxSize, "2M", 1);
	} else {
		zephir_get_strval(maxSize, maxSize_param);
	}


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, validExtensions);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "@[,/\\s\\|]+@", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, -1);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_split", &_6, &_2, _1, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "array_flip", &_8, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("validExtensions"), _7 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_9, nc_std_ce, "sizetobyte", &_10, maxSize);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("maxSize"), _9 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Uploader, setStorageBackend) {

	zval *storageBackend;

	zephir_fetch_params(0, 1, 0, &storageBackend);



	if (!(zephir_instance_of_ev(storageBackend, nc_storage_backend_storagebackendinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'storageBackend' must be an instance of 'Nc\\Storage\\Backend\\StorageBackendInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("storageBackend"), storageBackend TSRMLS_CC);

}

PHP_METHOD(Nc_Storage_Uploader, getStorageBackend) {


	RETURN_MEMBER(this_ptr, "storageBackend");

}

PHP_METHOD(Nc_Storage_Uploader, upload) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	zend_bool reserveTmp, _1, _2, _3, _4, _5;
	zval *index_param = NULL, *group_param = NULL, *reserveTmp_param = NULL, *fa, *error, *tmpName, *name, *size, *extension, *uri = NULL, *_0, *_FILES, *_6, *_7, _8, *_9 = NULL, *_11, *_12 = NULL, *_13, *_14;
	zval *index = NULL, *group = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &index_param, &group_param, &reserveTmp_param);

	zephir_get_strval(index, index_param);
	if (!group_param) {
		ZEPHIR_INIT_VAR(group);
		ZVAL_STRING(group, "", 1);
	} else {
		zephir_get_strval(group, group_param);
	}
	if (!reserveTmp_param) {
		reserveTmp = 0;
	} else {
		reserveTmp = zephir_get_boolval(reserveTmp_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("lastError"), _0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(fa);
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	_1 = !(zephir_array_isset_fetch(&fa, _FILES, index, 0 TSRMLS_CC));
	if (!(_1)) {
		_1 = Z_TYPE_P(fa) != IS_ARRAY;
	}
	if (unlikely(_1)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, 0x11);
		zephir_update_property_this(this_ptr, SL("lastError"), _0 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(error);
	_2 = !(zephir_array_isset_string_fetch(&error, fa, SS("error"), 0 TSRMLS_CC));
	if (!(_2)) {
		ZEPHIR_OBS_VAR(size);
		_2 = !(zephir_array_isset_string_fetch(&size, fa, SS("size"), 0 TSRMLS_CC));
	}
	_3 = _2;
	if (!(_3)) {
		ZEPHIR_OBS_VAR(tmpName);
		_3 = !(zephir_array_isset_string_fetch(&tmpName, fa, SS("tmp_name"), 0 TSRMLS_CC));
	}
	_4 = _3;
	if (!(_4)) {
		ZEPHIR_OBS_VAR(name);
		_4 = !(zephir_array_isset_string_fetch(&name, fa, SS("name"), 0 TSRMLS_CC));
	}
	if (unlikely(_4)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_LONG(_0, 0x12);
		zephir_update_property_this(this_ptr, SL("lastError"), _0 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (unlikely(!ZEPHIR_IS_LONG(error, 0))) {
		zephir_update_property_this(this_ptr, SL("lastError"), error TSRMLS_CC);
		RETURN_MM_NULL();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
	_5 = ZEPHIR_GT_LONG(_0, 0);
	if (_5) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
		_5 = ZEPHIR_GT(size, _6);
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_ZVAL_NREF(_7);
		ZVAL_LONG(_7, 0x13);
		zephir_update_property_this(this_ptr, SL("lastError"), _7 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(extension);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 4);
	ZEPHIR_CALL_FUNCTION(&_9, "pathinfo", &_10, name, &_8);
	zephir_check_call_status();
	zephir_fast_strtolower(extension, _9);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("validExtensions"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_7, extension)))) {
		ZEPHIR_INIT_ZVAL_NREF(_11);
		ZVAL_LONG(_11, 0x14);
		zephir_update_property_this(this_ptr, SL("lastError"), _11 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("storageBackend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_BOOL(_12, !reserveTmp);
	ZEPHIR_CALL_METHOD(&uri, _7, "store", NULL, tmpName, group, extension, _12);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(uri))) {
		ZEPHIR_INIT_ZVAL_NREF(_11);
		ZVAL_LONG(_11, 0x15);
		zephir_update_property_this(this_ptr, SL("lastError"), _11 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	zephir_update_property_this(this_ptr, SL("fileArray"), fa TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "tmpName", 1);
	zephir_update_property_array(this_ptr, SL("fileArray"), _12, tmpName TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	ZVAL_STRING(_13, "extension", 1);
	zephir_update_property_array(this_ptr, SL("fileArray"), _13, extension TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_STRING(_14, "uri", 1);
	zephir_update_property_array(this_ptr, SL("fileArray"), _14, uri TSRMLS_CC);
	RETURN_CCTOR(uri);

}

PHP_METHOD(Nc_Storage_Uploader, lastError) {


	RETURN_MEMBER(this_ptr, "lastError");

}

PHP_METHOD(Nc_Storage_Uploader, fileArray) {


	RETURN_MEMBER(this_ptr, "fileArray");

}

PHP_METHOD(Nc_Storage_Uploader, __get) {

	zval *name_param = NULL, *value, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fileArray"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

