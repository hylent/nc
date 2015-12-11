
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
#include "kernel/exception.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Upload_UploadedFile) {

	ZEPHIR_REGISTER_CLASS(Nc\\Upload, UploadedFile, nc, upload_uploadedfile, nc_upload_uploadedfile_method_entry, 0);

	zend_declare_property_null(nc_upload_uploadedfile_ce, SL("error"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(nc_upload_uploadedfile_ce, SL("size"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(nc_upload_uploadedfile_ce, SL("name"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(nc_upload_uploadedfile_ce, SL("extension"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(nc_upload_uploadedfile_ce, SL("tmpName"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(nc_upload_uploadedfile_ce, SL("uploader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Upload_UploadedFile, __construct) {

	zval *uploader;

	zephir_fetch_params(0, 1, 0, &uploader);



	zephir_update_property_this(this_ptr, SL("uploader"), uploader TSRMLS_CC);

}

PHP_METHOD(Nc_Upload_UploadedFile, isValid) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("error"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 0));

}

PHP_METHOD(Nc_Upload_UploadedFile, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool keep;
	zval *prefix_param = NULL, *keep_param = NULL, *_0, *_1, *_2;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &prefix_param, &keep_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("error"), PH_NOISY_CC);
	if (unlikely(!ZEPHIR_IS_LONG_IDENTICAL(_0, 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_upload_exception_ce, "Invalid uploaded file cannot be saved", "nc/upload/uploadedfile.zep", 26);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	if (keep) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(_1, "saveuploadedfile", NULL, 0, this_ptr, prefix, _2);
	zephir_check_call_status();
	RETURN_MM();

}

