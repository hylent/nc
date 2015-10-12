
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Ftp) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Storage, Ftp, nc, storage_ftp, nc_storage_storageabstract_ce, nc_storage_ftp_method_entry, 0);

	zend_declare_property_null(nc_storage_ftp_ce, SL("ftp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_storage_ftp_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Storage_Ftp, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool ssl, _6;
	long port, timeout;
	zval *host_param = NULL, *user_param = NULL, *passwd_param = NULL, *baseDirectory_param = NULL, *port_param = NULL, *timeout_param = NULL, *ssl_param = NULL, *ftp = NULL, *_7 = NULL, *_10 = NULL, _0$$4, _1$$4, _2$$5, _3$$5, *_4$$6, *_8$$7;
	zval *host = NULL, *user = NULL, *passwd = NULL, *baseDirectory = NULL, *_5$$6, *_9$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 4, &host_param, &user_param, &passwd_param, &baseDirectory_param, &port_param, &timeout_param, &ssl_param);

	zephir_get_strval(host, host_param);
	zephir_get_strval(user, user_param);
	zephir_get_strval(passwd, passwd_param);
	if (!baseDirectory_param) {
		ZEPHIR_INIT_VAR(baseDirectory);
		ZVAL_STRING(baseDirectory, "", 1);
	} else {
		zephir_get_strval(baseDirectory, baseDirectory_param);
	}
	if (!port_param) {
		port = 0;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!timeout_param) {
		timeout = 30;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}
	if (!ssl_param) {
		ssl = 0;
	} else {
		ssl = zephir_get_boolval(ssl_param);
	}


	if (unlikely(!((zephir_function_exists_ex(SS("ftp_connect") TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_exception_ce, "Missing ftp support", "nc/storage/ftp.zep", 16);
		return;
	}
	if (ssl) {
		ZEPHIR_SINIT_VAR(_0$$4);
		ZVAL_LONG(&_0$$4, port);
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_LONG(&_1$$4, timeout);
		ZEPHIR_CALL_FUNCTION(&ftp, "ftp_ssl_connect", NULL, 107, host, &_0$$4, &_1$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_2$$5);
		ZVAL_LONG(&_2$$5, port);
		ZEPHIR_SINIT_VAR(_3$$5);
		ZVAL_LONG(&_3$$5, timeout);
		ZEPHIR_CALL_FUNCTION(&ftp, "ftp_connect", NULL, 108, host, &_2$$5, &_3$$5);
		zephir_check_call_status();
	}
	if (unlikely(!zephir_is_true(ftp))) {
		ZEPHIR_INIT_VAR(_4$$6);
		object_init_ex(_4$$6, nc_storage_exception_ce);
		ZEPHIR_INIT_VAR(_5$$6);
		ZEPHIR_CONCAT_SV(_5$$6, "Cannot connect to ftp server: ", host);
		ZEPHIR_CALL_METHOD(NULL, _4$$6, "__construct", NULL, 2, _5$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$6, "nc/storage/ftp.zep", 26 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = zephir_is_true(user);
	if (_6) {
		ZEPHIR_CALL_FUNCTION(&_7, "ftp_login", NULL, 109, ftp, user, passwd);
		zephir_check_call_status();
		_6 = !zephir_is_true(_7);
	}
	if (unlikely(_6)) {
		ZEPHIR_INIT_VAR(_8$$7);
		object_init_ex(_8$$7, nc_storage_exception_ce);
		ZEPHIR_INIT_VAR(_9$$7);
		ZEPHIR_CONCAT_SVSV(_9$$7, "Cannot login ftp server: ", user, "@", host);
		ZEPHIR_CALL_METHOD(NULL, _8$$7, "__construct", NULL, 2, _9$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$7, "nc/storage/ftp.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_10, "ftp_pasv", NULL, 110, ftp, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_10))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_exception_ce, "Cannot set PASV mode", "nc/storage/ftp.zep", 34);
		return;
	}
	zephir_update_property_this(this_ptr, SL("ftp"), ftp TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("baseDirectory"), baseDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Ftp, store) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool rm;
	zval *source_param = NULL, *group_param = NULL, *extension_param = NULL, *rm_param = NULL, *_0 = NULL, *_2, *_3, *_4 = NULL, *_5, _6, *_7 = NULL;
	zval *source = NULL, *group = NULL, *extension = NULL, *destUri = NULL, *destPath = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &source_param, &group_param, &extension_param, &rm_param);

	zephir_get_strval(source, source_param);
	if (!group_param) {
		ZEPHIR_INIT_VAR(group);
		ZVAL_STRING(group, "", 1);
	} else {
		zephir_get_strval(group, group_param);
	}
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}
	if (!rm_param) {
		rm = 0;
	} else {
		rm = zephir_get_boolval(rm_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generateuri", NULL, 0, source, group, extension);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(destUri, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, destUri);
	zephir_get_strval(destPath, _3);
	ZEPHIR_CALL_FUNCTION(&_4, "dirname", NULL, 103, destPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mkdirifnotexists", NULL, 0, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 2);
	ZEPHIR_CALL_FUNCTION(&_7, "ftp_put", NULL, 111, _5, destPath, source, &_6);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		if (rm) {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 24, source);
			zephir_check_call_status();
		}
		RETURN_CTOR(destUri);
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Nc_Storage_Ftp, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *_0;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ftp_delete", NULL, 112, _0, uri);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Storage_Ftp, __destruct) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "ftp_close", NULL, 113, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Ftp, mkDirIfNotExists) {

	HashTable *_9;
	HashPosition _8;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dir_param = NULL, *ftp = NULL, *parts = NULL, *cur = NULL, *stack = NULL, *_0, _1 = zval_used_for_init, _2, _3, **_10, *_4$$3 = NULL, *_5$$3 = NULL;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(dir, dir_param);


	ZEPHIR_INIT_VAR(stack);
	array_init(stack);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(ftp, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "#/+#", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, -1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&parts, "preg_split", NULL, 5, &_1, dir, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "Nc\\Std::ignoreError", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 114, &_1);
	zephir_check_call_status();
	while (1) {
		if (!(zephir_is_true(parts))) {
			break;
		}
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_fast_join_str(_4$$3, SL("/"), parts TSRMLS_CC);
		ZEPHIR_INIT_NVAR(cur);
		ZEPHIR_CONCAT_SV(cur, "/", _4$$3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "ftp_chdir", &_6, 115, ftp, cur);
		zephir_check_call_status();
		if (!(zephir_is_true(_5$$3))) {
			zephir_array_append(&stack, cur, PH_SEPARATE, "nc/storage/ftp.zep", 83);
		}
		ZEPHIR_MAKE_REF(parts);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_7, 7, parts);
		ZEPHIR_UNREF(parts);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 116);
	zephir_check_call_status();
	zephir_is_iterable(stack, &_9, &_8, 0, 1, "nc/storage/ftp.zep", 93);
	for (
	  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zephir_hash_move_backwards_ex(_9, &_8)
	) {
		ZEPHIR_GET_HVALUE(cur, _10);
		ZEPHIR_CALL_FUNCTION(NULL, "ftp_mkdir", &_11, 117, ftp, cur);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

