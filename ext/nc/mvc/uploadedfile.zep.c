
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_UploadedFile) {

	ZEPHIR_REGISTER_CLASS(Nc\\Mvc, UploadedFile, nc, mvc_uploadedfile, nc_mvc_uploadedfile_method_entry, 0);

	zend_declare_property_null(nc_mvc_uploadedfile_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_uploadedfile_ce, SL("size"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_uploadedfile_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_uploadedfile_ce, SL("tmpName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(nc_mvc_uploadedfile_ce, SL("extension"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_mvc_uploadedfile_ce, SL("imageType"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_UploadedFile, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval name, tmpName;
	zval *error_param = NULL, *size_param = NULL, *name_param = NULL, *tmpName_param = NULL, __$false, imageType, _0, _1$$4, _2$$4, _3$$4, _4$$6, _5$$7;
	long error, size;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&imageType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tmpName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &error_param, &size_param, &name_param, &tmpName_param);

	error = zephir_get_intval(error_param);
	size = zephir_get_intval(size_param);
	zephir_get_strval(&name, name_param);
	zephir_get_strval(&tmpName, tmpName_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, error);
	zephir_update_property_zval(this_ptr, SL("error"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, size);
	zephir_update_property_zval(this_ptr, SL("size"), &_0);
	zephir_update_property_zval(this_ptr, SL("name"), &name);
	zephir_update_property_zval(this_ptr, SL("tmpName"), &tmpName);
	if (error == 0) {
		ZEPHIR_CALL_FUNCTION(&imageType, "exif_imagetype", NULL, 77, &tmpName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&imageType)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_LONG(&_2$$4, 4);
			ZEPHIR_CALL_FUNCTION(&_3$$4, "pathinfo", NULL, 12, &name, &_2$$4);
			zephir_check_call_status();
			zephir_fast_strtolower(&_1$$4, &_3$$4);
			zephir_update_property_zval(this_ptr, SL("extension"), &_1$$4);
		} else {
			if (ZEPHIR_IS_LONG(&imageType, 2)) {
				ZEPHIR_INIT_VAR(&_4$$6);
				ZEPHIR_INIT_NVAR(&_4$$6);
				ZVAL_STRING(&_4$$6, "jpg");
				zephir_update_property_zval(this_ptr, SL("extension"), &_4$$6);
			} else {
				ZEPHIR_CALL_FUNCTION(&_5$$7, "image_type_to_extension", NULL, 117, &imageType, &__$false);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("extension"), &_5$$7);
			}
			zephir_update_property_zval(this_ptr, SL("imageType"), &imageType);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_UploadedFile, getError) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "error");

}

PHP_METHOD(Nc_Mvc_UploadedFile, getSize) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "size");

}

PHP_METHOD(Nc_Mvc_UploadedFile, getName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "name");

}

PHP_METHOD(Nc_Mvc_UploadedFile, getTmpName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "tmpName");

}

PHP_METHOD(Nc_Mvc_UploadedFile, getExtension) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "extension");

}

PHP_METHOD(Nc_Mvc_UploadedFile, getImageType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "imageType");

}

PHP_METHOD(Nc_Mvc_UploadedFile, isImage) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("imageType"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_GT_LONG(&_0, 0));

}

