
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Storage_StorageAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Storage, StorageAbstract, nc, storage_storageabstract, nc_storage_storageabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_storage_storageabstract_ce, SL("uriGenerator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_storage_storageabstract_ce TSRMLS_CC, 1, nc_storage_storageinterface_ce);
	zend_class_implements(nc_storage_storageabstract_ce TSRMLS_CC, 1, nc_storage_urigeneratorinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Storage_StorageAbstract, uuid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *salt_param = NULL, __$true, _0, _1, _2, _3, _4, _5, _6, _7;
	zval salt;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&salt);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &salt_param);

	if (!salt_param) {
		ZEPHIR_INIT_VAR(&salt);
		ZVAL_STRING(&salt, "");
	} else {
		zephir_get_strval(&salt, salt_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "mt_rand", NULL, 11);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 12, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &salt);
	ZEPHIR_CALL_FUNCTION(&_3, "sha1", NULL, 13, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_time(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "%04x");
	ZVAL_LONG(&_6, (zephir_get_intval(&_4) & 0xffff));
	ZEPHIR_CALL_FUNCTION(&_7, "sprintf", NULL, 6, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_3, &_7);
	RETURN_MM();

}

PHP_METHOD(Nc_Storage_StorageAbstract, setUriGenerator) {

	zval *uriGenerator = NULL, uriGenerator_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&uriGenerator_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &uriGenerator);

	if (!uriGenerator) {
		uriGenerator = &uriGenerator_sub;
		uriGenerator = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("uriGenerator"), uriGenerator);

}

PHP_METHOD(Nc_Storage_StorageAbstract, getUriGenerator) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "uriGenerator");

}

PHP_METHOD(Nc_Storage_StorageAbstract, generateUri) {

	unsigned char _12, _13, _14, _15;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *src_param = NULL, *pre_param = NULL, *ext_param = NULL, uriGenerator, _0, _2, _9, _16, _3$$4, _4$$4, _5$$4, _6$$5, _7$$5, _8$$5;
	zval src, pre, ext, uri, uuid, _10, _11, _17$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&pre);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&uuid);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&uriGenerator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &src_param, &pre_param, &ext_param);

	zephir_get_strval(&src, src_param);
	zephir_get_strval(&pre, pre_param);
	zephir_get_strval(&ext, ext_param);


	ZEPHIR_INIT_VAR(&uri);
	ZVAL_STRING(&uri, "/");
	zephir_read_property(&_0, this_ptr, SL("uriGenerator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uriGenerator, &_0);
	_1 = Z_TYPE_P(&uriGenerator) == IS_OBJECT;
	if (_1) {
		_1 = (zephir_instance_of_ev(&uriGenerator, nc_storage_urigeneratorinterface_ce TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(&uriGenerator, "generateuri", NULL, 0, &src, &pre, &ext);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_fast_strlen_ev(&pre) > 0) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "#^(\\w+/)*\\w*$#");
		zephir_preg_match(&_4$$4, &_5$$4, &pre, &_3$$4, 0, 0 , 0  TSRMLS_CC);
		if (unlikely(!zephir_is_true(&_4$$4))) {
			ZEPHIR_INIT_VAR(&_6$$5);
			object_init_ex(&_6$$5, nc_storage_exception_ce);
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "Invalid uri prefix '%s'");
			ZEPHIR_CALL_FUNCTION(&_8$$5, "sprintf", NULL, 6, &_7$$5, &pre);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 7, &_8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$5, "nc/storage/storageabstract.zep", 34 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&uri, &pre TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_VV(&_10, &src, &ext);
	ZEPHIR_CALL_SELF(&_9, "uuid", NULL, 0, &_10);
	zephir_check_call_status();
	zephir_get_strval(&_11, &_9);
	ZEPHIR_CPY_WRT(&uuid, &_11);
	_12 = ZEPHIR_STRING_OFFSET(&uuid, 0);
	zephir_concat_self_char(&uri, _12 TSRMLS_CC);
	_13 = ZEPHIR_STRING_OFFSET(&uuid, 1);
	zephir_concat_self_char(&uri, _13 TSRMLS_CC);
	zephir_concat_self_str(&uri, "/", sizeof("/")-1 TSRMLS_CC);
	_14 = ZEPHIR_STRING_OFFSET(&uuid, 2);
	zephir_concat_self_char(&uri, _14 TSRMLS_CC);
	_15 = ZEPHIR_STRING_OFFSET(&uuid, 3);
	zephir_concat_self_char(&uri, _15 TSRMLS_CC);
	zephir_concat_self_str(&uri, "/", sizeof("/")-1 TSRMLS_CC);
	zephir_concat_self(&uri, &uuid TSRMLS_CC);
	if (zephir_fast_strlen_ev(&ext) > 0) {
		ZEPHIR_INIT_VAR(&_17$$6);
		ZEPHIR_CONCAT_SV(&_17$$6, ".", &ext);
		zephir_concat_self(&uri, &_17$$6 TSRMLS_CC);
	}
	RETURN_CTOR(uri);

}

