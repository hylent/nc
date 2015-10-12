
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
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Filter_Uploader) {

	ZEPHIR_REGISTER_CLASS(Nc\\Filter, Uploader, nc, filter_uploader, nc_filter_uploader_method_entry, 0);

	zend_declare_property_null(nc_filter_uploader_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_filter_uploader_ce, SL("validExtensions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_filter_uploader_ce, SL("maxSize"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_filter_uploader_ce, SL("lastError"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_filter_uploader_ce, SL("fileArray"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_filter_uploader_ce, SL("FILE_ARRAY_NOT_FOUND"), 0x11 TSRMLS_CC);

	zend_declare_class_constant_long(nc_filter_uploader_ce, SL("FILE_ARRAY_MISSING_VALUE"), 0x12 TSRMLS_CC);

	zend_declare_class_constant_long(nc_filter_uploader_ce, SL("SIZE_TOO_LARGE"), 0x13 TSRMLS_CC);

	zend_declare_class_constant_long(nc_filter_uploader_ce, SL("EXTENSION_INVALID"), 0x14 TSRMLS_CC);

	zend_declare_class_constant_long(nc_filter_uploader_ce, SL("STORAGE_FAILED"), 0x15 TSRMLS_CC);

	zend_class_implements(nc_filter_uploader_ce TSRMLS_CC, 1, nc_storage_storageawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Filter_Uploader, __construct) {

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *validExtensions_param = NULL, *maxSize_param = NULL, *_0 = NULL, *_1, _2, _3, _4, *_5 = NULL, *_6 = NULL, *_7 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&_5, "preg_split", NULL, 5, &_2, _1, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "array_flip", NULL, 49, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("validExtensions"), _6 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_7, nc_std_ce, "sizetobyte", &_8, 50, maxSize);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("maxSize"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Filter_Uploader, setStorage) {

	zval *storage;

	zephir_fetch_params(0, 1, 0, &storage);



	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);

}

PHP_METHOD(Nc_Filter_Uploader, getStorage) {

	

	RETURN_MEMBER(this_ptr, "storage");

}

PHP_METHOD(Nc_Filter_Uploader, upload) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool reserveTmp, _1, _3, _4, _5, _7;
	zval *index_param = NULL, *group_param = NULL, *reserveTmp_param = NULL, *_FILES, *fa = NULL, *error = NULL, *tmpName = NULL, *name = NULL, *size = NULL, *extension = NULL, *uri = NULL, *_0, *_8, _10, *_11 = NULL, *_12, *_14, *_15 = NULL, *_17, *_18, *_2$$3, *_6$$4, *_9$$6, *_13$$7, *_16$$8;
	zval *index = NULL, *group = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
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
	_1 = !(zephir_array_isset_fetch(&fa, _FILES, index, 0 TSRMLS_CC));
	if (!(_1)) {
		_1 = Z_TYPE_P(fa) != IS_ARRAY;
	}
	if (unlikely(_1)) {
		ZEPHIR_INIT_ZVAL_NREF(_2$$3);
		ZVAL_LONG(_2$$3, 0x11);
		zephir_update_property_this(this_ptr, SL("lastError"), _2$$3 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(error);
	_3 = !(zephir_array_isset_string_fetch(&error, fa, SS("error"), 0 TSRMLS_CC));
	if (!(_3)) {
		ZEPHIR_OBS_VAR(size);
		_3 = !(zephir_array_isset_string_fetch(&size, fa, SS("size"), 0 TSRMLS_CC));
	}
	_4 = _3;
	if (!(_4)) {
		ZEPHIR_OBS_VAR(tmpName);
		_4 = !(zephir_array_isset_string_fetch(&tmpName, fa, SS("tmp_name"), 0 TSRMLS_CC));
	}
	_5 = _4;
	if (!(_5)) {
		ZEPHIR_OBS_VAR(name);
		_5 = !(zephir_array_isset_string_fetch(&name, fa, SS("name"), 0 TSRMLS_CC));
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_ZVAL_NREF(_6$$4);
		ZVAL_LONG(_6$$4, 0x12);
		zephir_update_property_this(this_ptr, SL("lastError"), _6$$4 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (unlikely(!ZEPHIR_IS_LONG(error, 0))) {
		zephir_update_property_this(this_ptr, SL("lastError"), error TSRMLS_CC);
		RETURN_MM_NULL();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
	_7 = ZEPHIR_GT_LONG(_0, 0);
	if (_7) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
		_7 = ZEPHIR_GT(size, _8);
	}
	if (unlikely(_7)) {
		ZEPHIR_INIT_ZVAL_NREF(_9$$6);
		ZVAL_LONG(_9$$6, 0x13);
		zephir_update_property_this(this_ptr, SL("lastError"), _9$$6 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 4);
	ZEPHIR_CALL_FUNCTION(&_11, "pathinfo", NULL, 51, name, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(extension);
	zephir_fast_strtolower(extension, _11);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("validExtensions"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_12, extension)))) {
		ZEPHIR_INIT_ZVAL_NREF(_13$$7);
		ZVAL_LONG(_13$$7, 0x14);
		zephir_update_property_this(this_ptr, SL("lastError"), _13$$7 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_BOOL(_15, !reserveTmp);
	ZEPHIR_CALL_METHOD(&uri, _14, "store", NULL, 0, tmpName, group, extension, _15);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(uri))) {
		ZEPHIR_INIT_ZVAL_NREF(_16$$8);
		ZVAL_LONG(_16$$8, 0x15);
		zephir_update_property_this(this_ptr, SL("lastError"), _16$$8 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	zephir_update_property_this(this_ptr, SL("fileArray"), fa TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "tmpName", 1);
	zephir_update_property_array(this_ptr, SL("fileArray"), _15, tmpName TSRMLS_CC);
	ZEPHIR_INIT_VAR(_17);
	ZVAL_STRING(_17, "extension", 1);
	zephir_update_property_array(this_ptr, SL("fileArray"), _17, extension TSRMLS_CC);
	ZEPHIR_INIT_VAR(_18);
	ZVAL_STRING(_18, "uri", 1);
	zephir_update_property_array(this_ptr, SL("fileArray"), _18, uri TSRMLS_CC);
	RETURN_CCTOR(uri);

}

PHP_METHOD(Nc_Filter_Uploader, lastError) {

	

	RETURN_MEMBER(this_ptr, "lastError");

}

PHP_METHOD(Nc_Filter_Uploader, fileArray) {

	

	RETURN_MEMBER(this_ptr, "fileArray");

}

PHP_METHOD(Nc_Filter_Uploader, __get) {

	zval *name_param = NULL, *value = NULL, *_0;
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

