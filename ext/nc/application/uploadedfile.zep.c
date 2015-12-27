
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Application_UploadedFile) {

	ZEPHIR_REGISTER_CLASS(Nc\\Application, UploadedFile, nc, application_uploadedfile, nc_application_uploadedfile_method_entry, 0);

	zend_declare_property_null(nc_application_uploadedfile_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_application_uploadedfile_ce, SL("size"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_application_uploadedfile_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_application_uploadedfile_ce, SL("tmpName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_application_uploadedfile_ce, SL("extension"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Application_UploadedFile, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *tmpName = NULL;
	zval *error_param = NULL, *size_param = NULL, *name_param = NULL, *tmpName_param = NULL, *_0, *_1, _2, *_3 = NULL;
	long error, size;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &error_param, &size_param, &name_param, &tmpName_param);

	error = zephir_get_intval(error_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(name, name_param);
	zephir_get_strval(tmpName, tmpName_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, error);
	zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, size);
	zephir_update_property_this(this_ptr, SL("size"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("tmpName"), tmpName TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 4);
	ZEPHIR_CALL_FUNCTION(&_3, "pathinfo", NULL, 33, name, &_2);
	zephir_check_call_status();
	zephir_fast_strtolower(_1, _3);
	zephir_update_property_this(this_ptr, SL("extension"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Application_UploadedFile, getError) {

	

	RETURN_MEMBER(this_ptr, "error");

}

PHP_METHOD(Nc_Application_UploadedFile, getSize) {

	

	RETURN_MEMBER(this_ptr, "size");

}

PHP_METHOD(Nc_Application_UploadedFile, getName) {

	

	RETURN_MEMBER(this_ptr, "name");

}

PHP_METHOD(Nc_Application_UploadedFile, getTmpName) {

	

	RETURN_MEMBER(this_ptr, "tmpName");

}

PHP_METHOD(Nc_Application_UploadedFile, getExtension) {

	

	RETURN_MEMBER(this_ptr, "extension");

}

