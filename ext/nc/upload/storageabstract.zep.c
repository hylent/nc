
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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Upload_StorageAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Upload, StorageAbstract, nc, upload_storageabstract, nc_upload_storageabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_upload_storageabstract_ce, SL("uriGenerator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_upload_storageabstract_ce, SL("COPY"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(nc_upload_storageabstract_ce, SL("MOVE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(nc_upload_storageabstract_ce, SL("MOVE_UPLOADED_FILE"), 2 TSRMLS_CC);

	zend_class_implements(nc_upload_storageabstract_ce TSRMLS_CC, 1, nc_upload_urigeneratorinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Upload_StorageAbstract, setUriGenerator) {

	zval *uriGenerator;

	zephir_fetch_params(0, 1, 0, &uriGenerator);



	zephir_update_property_this(this_ptr, SL("uriGenerator"), uriGenerator TSRMLS_CC);

}

PHP_METHOD(Nc_Upload_StorageAbstract, getUriGenerator) {

	

	RETURN_MEMBER(this_ptr, "uriGenerator");

}

PHP_METHOD(Nc_Upload_StorageAbstract, store) {

}

PHP_METHOD(Nc_Upload_StorageAbstract, remove) {

}

PHP_METHOD(Nc_Upload_StorageAbstract, exists) {

}

PHP_METHOD(Nc_Upload_StorageAbstract, generateUri) {

	unsigned char _12, _13, _14, _15;
	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *prefix_param = NULL, *extension_param = NULL, *_0, *_2 = NULL, *_8 = NULL, *_1$$3, *_3$$4, *_4$$4, _5$$4, *_6$$5;
	zval *source = NULL, *prefix = NULL, *extension = NULL, *uri, *uuid = NULL, *_10, *_11 = NULL, *_7$$5, *_16$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &source_param, &prefix_param, &extension_param);

	zephir_get_strval(source, source_param);
	zephir_get_strval(prefix, prefix_param);
	zephir_get_strval(extension, extension_param);


	ZEPHIR_INIT_VAR(uri);
	ZVAL_STRING(uri, "/", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uriGenerator"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("uriGenerator"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_1$$3, "generateuri", NULL, 0, source, prefix, extension);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_fast_strlen_ev(prefix) > 0) {
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_STRING(&_5$$4, "#^(\\w+/)*\\w*$#", 0);
		zephir_preg_match(_4$$4, &_5$$4, prefix, _3$$4, 0, 0 , 0  TSRMLS_CC);
		if (unlikely(!zephir_is_true(_4$$4))) {
			ZEPHIR_INIT_VAR(_6$$5);
			object_init_ex(_6$$5, nc_upload_exception_ce);
			ZEPHIR_INIT_VAR(_7$$5);
			ZEPHIR_CONCAT_SV(_7$$5, "Invalid prefix: ", prefix);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", NULL, 2, _7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$5, "nc/upload/storageabstract.zep", 37 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&uri, prefix TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_VV(_10, source, extension);
	ZEPHIR_CALL_CE_STATIC(&_8, nc_std_ce, "uuid", &_9, 11, _10);
	zephir_check_call_status();
	zephir_get_strval(_11, _8);
	ZEPHIR_CPY_WRT(uuid, _11);
	_12 = ZEPHIR_STRING_OFFSET(uuid, 0);
	zephir_concat_self_char(&uri, _12 TSRMLS_CC);
	_13 = ZEPHIR_STRING_OFFSET(uuid, 1);
	zephir_concat_self_char(&uri, _13 TSRMLS_CC);
	zephir_concat_self_str(&uri, "/", sizeof("/")-1 TSRMLS_CC);
	_14 = ZEPHIR_STRING_OFFSET(uuid, 2);
	zephir_concat_self_char(&uri, _14 TSRMLS_CC);
	_15 = ZEPHIR_STRING_OFFSET(uuid, 3);
	zephir_concat_self_char(&uri, _15 TSRMLS_CC);
	zephir_concat_self_str(&uri, "/", sizeof("/")-1 TSRMLS_CC);
	zephir_concat_self(&uri, uuid TSRMLS_CC);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_16$$6);
		ZEPHIR_CONCAT_SV(_16$$6, ".", extension);
		zephir_concat_self(&uri, _16$$6 TSRMLS_CC);
	}
	RETURN_CTOR(uri);

}

