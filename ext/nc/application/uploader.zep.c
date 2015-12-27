
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
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Application_Uploader) {

	ZEPHIR_REGISTER_CLASS(Nc\\Application, Uploader, nc, application_uploader, nc_application_uploader_method_entry, 0);

	zend_declare_property_null(nc_application_uploader_ce, SL("validExtensions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_application_uploader_ce, SL("maxSize"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_application_uploader_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_application_uploader_ce, SL("INVALID_EXTENSION"), -1 TSRMLS_CC);

	zend_declare_class_constant_long(nc_application_uploader_ce, SL("INVALID_SIZE"), -2 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Application_Uploader, __construct) {

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
	ZVAL_STRING(&_2, "#[,/\\s\\|\\.]+#", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, -1);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_split", NULL, 34, &_2, _1, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "array_flip", NULL, 35, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("validExtensions"), _6 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_7, nc_std_ce, "sizetobytes", &_8, 36, maxSize);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("maxSize"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Application_Uploader, setStorage) {

	zval *storage;

	zephir_fetch_params(0, 1, 0, &storage);



	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);

}

PHP_METHOD(Nc_Application_Uploader, getStorage) {

	

	RETURN_MEMBER(this_ptr, "storage");

}

PHP_METHOD(Nc_Application_Uploader, saveUploadedFile) {

	long flag = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool keep, _6;
	zval *prefix = NULL;
	zval *uploadedFile, *prefix_param = NULL, *keep_param = NULL, *error = NULL, *size = NULL, *name = NULL, *tmpName = NULL, *extension = NULL, *_2, *_7, *_11, *_12, *_0$$3, *_1$$3, *_3$$4, *_4$$4, *_5$$4, *_8$$5, *_9$$5, *_10$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &uploadedFile, &prefix_param, &keep_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}
	if (!keep_param) {
		keep = 0;
	} else {
		keep = zephir_get_boolval(keep_param);
	}


	ZEPHIR_CALL_METHOD(&error, uploadedFile, "geterror", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&size, uploadedFile, "getsize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&name, uploadedFile, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&tmpName, uploadedFile, "gettmpname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&extension, uploadedFile, "getextension", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!ZEPHIR_IS_LONG_IDENTICAL(error, 0))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, nc_application_uploaderexception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, "Invalid uploaded file with error: ", error);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _1$$3, error);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "nc/application/uploader.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("validExtensions"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_2, extension)))) {
		ZEPHIR_INIT_VAR(_3$$4);
		object_init_ex(_3$$4, nc_application_uploaderexception_ce);
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_CONCAT_SV(_4$$4, "Invalid uploaded file extension: ", extension);
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_LONG(_5$$4, -1);
		ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 2, _4$$4, _5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$4, "nc/application/uploader.zep", 50 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = ZEPHIR_LT_LONG(size, 1);
	if (!(_6)) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
		_6 = ZEPHIR_GT(size, _7);
	}
	if (unlikely(_6)) {
		ZEPHIR_INIT_VAR(_8$$5);
		object_init_ex(_8$$5, nc_application_uploaderexception_ce);
		ZEPHIR_INIT_VAR(_9$$5);
		ZEPHIR_CONCAT_SV(_9$$5, "Invalid uploaded file size: ", size);
		ZEPHIR_INIT_VAR(_10$$5);
		ZVAL_LONG(_10$$5, -2);
		ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 2, _9$$5, _10$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$5, "nc/application/uploader.zep", 54 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (keep) {
		flag = 0;
	} else {
		flag = 2;
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, flag);
	ZEPHIR_RETURN_CALL_METHOD(_11, "store", NULL, 0, tmpName, prefix, extension, _12);
	zephir_check_call_status();
	RETURN_MM();

}

