
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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


ZEPHIR_INIT_CLASS(Nc_Storage_Backend_Ftp) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Storage\\Backend, Ftp, nc, storage_backend_ftp, nc_storage_backend_storagebackendadapter_ce, nc_storage_backend_ftp_method_entry, 0);

	zend_declare_property_null(nc_storage_backend_ftp_ce, SL("ftp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_storage_backend_ftp_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Storage_Backend_Ftp, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool ssl, _5;
	long port, timeout;
	zval *host_param = NULL, *user_param = NULL, *passwd_param = NULL, *baseDirectory_param = NULL, *port_param = NULL, *timeout_param = NULL, *ssl_param = NULL, *ftp = NULL, *_0 = NULL, *_1, _2, _3, *_6 = NULL, *_7 = NULL;
	zval *host = NULL, *user = NULL, *passwd = NULL, *baseDirectory = NULL, *_4 = NULL;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_backend_exception_ce, "Missing ftp support", "nc/storage/backend/ftp.zep", 16);
		return;
	}
	if (ssl) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_LONG(_0, port);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, timeout);
		ZEPHIR_CALL_FUNCTION(&ftp, "ftp_ssl_connect", NULL, host, _0, _1);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, port);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, timeout);
		ZEPHIR_CALL_FUNCTION(&ftp, "ftp_connect", NULL, host, &_2, &_3);
		zephir_check_call_status();
	}
	if (unlikely(!zephir_is_true(ftp))) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, nc_storage_backend_exception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Cannot connect to ftp server: ", host);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "nc/storage/backend/ftp.zep", 26 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_is_true(user);
	if (_5) {
		ZEPHIR_CALL_FUNCTION(&_6, "ftp_login", NULL, ftp, user, passwd);
		zephir_check_call_status();
		_5 = !zephir_is_true(_6);
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, nc_storage_backend_exception_ce);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVSV(_4, "Cannot login ftp server: ", user, "@", host);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "nc/storage/backend/ftp.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_7, "ftp_pasv", NULL, ftp, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_7))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_backend_exception_ce, "Cannot set PASV mode", "nc/storage/backend/ftp.zep", 34);
		return;
	}
	zephir_update_property_this(this_ptr, SL("ftp"), ftp TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("baseDirectory"), baseDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Backend_Ftp, store) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool mv;
	zval *source_param = NULL, *group_param = NULL, *extension_param = NULL, *mv_param = NULL, *_0 = NULL, *_2, *_3, *_4 = NULL, *_6, _7, *_8 = NULL;
	zval *source = NULL, *group = NULL, *extension = NULL, *destUri = NULL, *destPath = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &source_param, &group_param, &extension_param, &mv_param);

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
	if (!mv_param) {
		mv = 0;
	} else {
		mv = zephir_get_boolval(mv_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generateuri", NULL, source, group, extension);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(destUri, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, destUri);
	zephir_get_strval(destPath, _3);
	ZEPHIR_CALL_FUNCTION(&_4, "dirname", &_5, destPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mkdirifnotexists", NULL, _4);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 2);
	ZEPHIR_CALL_FUNCTION(&_8, "ftp_put", NULL, _6, destPath, source, &_7);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		if (mv) {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_9, source);
			zephir_check_call_status();
		}
		RETURN_CTOR(destUri);
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Nc_Storage_Backend_Ftp, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *_0;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ftp_delete", NULL, _0, uri);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Storage_Backend_Ftp, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "ftp_close", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Backend_Ftp, mkDirIfNotExists) {

	HashTable *_12;
	HashPosition _11;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_9 = NULL, *_10 = NULL;
	zval *dir_param = NULL, *ftp = NULL, *parts = NULL, *cur = NULL, *stack, *_0, _1 = zval_used_for_init, _2, _3, *_6 = NULL, *_7 = NULL, **_13;
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
	ZEPHIR_CALL_FUNCTION(&parts, "preg_split", &_4, &_1, dir, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "Nc\\Std::ignoreError", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", &_5, &_1);
	zephir_check_call_status();
	while (1) {
		if (!(zephir_is_true(parts))) {
			break;
		}
		ZEPHIR_INIT_NVAR(_6);
		zephir_fast_join_str(_6, SL("/"), parts TSRMLS_CC);
		ZEPHIR_INIT_NVAR(cur);
		ZEPHIR_CONCAT_SV(cur, "/", _6);
		ZEPHIR_CALL_FUNCTION(&_7, "ftp_chdir", &_8, ftp, cur);
		zephir_check_call_status();
		if (!(zephir_is_true(_7))) {
			zephir_array_append(&stack, cur, PH_SEPARATE, "nc/storage/backend/ftp.zep", 83);
		}
		Z_SET_ISREF_P(parts);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_9, parts);
		Z_UNSET_ISREF_P(parts);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", &_10);
	zephir_check_call_status();
	zephir_is_iterable(stack, &_12, &_11, 0, 1, "nc/storage/backend/ftp.zep", 93);
	for (
	  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
	  ; zephir_hash_move_backwards_ex(_12, &_11)
	) {
		ZEPHIR_GET_HVALUE(cur, _13);
		ZEPHIR_CALL_FUNCTION(NULL, "ftp_mkdir", &_14, ftp, cur);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

