
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Ftp) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Storage, Ftp, nc, storage_ftp, nc_storage_storageabstract_ce, nc_storage_ftp_method_entry, 0);

	zend_declare_property_null(nc_storage_ftp_ce, SL("ftp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_storage_ftp_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Storage_Ftp, ignoreError) {

	zval context;
	zval s, f, l;
	zval *n_param = NULL, *s_param = NULL, *f_param = NULL, *l_param = NULL, *context_param = NULL;
	long n;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&f);
	ZVAL_UNDEF(&l);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &n_param, &s_param, &f_param, &l_param, &context_param);

	n = zephir_get_intval(n_param);
	zephir_get_strval(&s, s_param);
	zephir_get_strval(&f, f_param);
	zephir_get_strval(&l, l_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	RETURN_MM_NULL();

}

PHP_METHOD(Nc_Storage_Ftp, __construct) {

	zend_bool ssl, _9;
	long port, timeout;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *host_param = NULL, *user_param = NULL, *passwd_param = NULL, *options_param = NULL, __$true, o, ftp, _10, _14, _1$$7, _2$$7, _3$$9, _4$$9, _5$$11, _6$$11, _7$$11, _11$$12, _12$$12, _13$$12;
	zval host, user, passwd, baseDirectory, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&passwd);
	ZVAL_UNDEF(&baseDirectory);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&o);
	ZVAL_UNDEF(&ftp);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &host_param, &user_param, &passwd_param, &options_param);

	zephir_get_strval(&host, host_param);
	zephir_get_strval(&user, user_param);
	zephir_get_strval(&passwd, passwd_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&baseDirectory);
	ZVAL_STRING(&baseDirectory, "");
	port = 21;
	timeout = 10;
	ssl = 0;
	ZEPHIR_OBS_VAR(&o);
	if (zephir_array_isset_string_fetch(&o, &options, SL("baseDirectory"), 0)) {
		zephir_get_strval(&_0$$3, &o);
		ZEPHIR_CPY_WRT(&baseDirectory, &_0$$3);
	}
	ZEPHIR_OBS_NVAR(&o);
	if (zephir_array_isset_string_fetch(&o, &options, SL("port"), 0)) {
		port = zephir_get_intval(&o);
	}
	ZEPHIR_OBS_NVAR(&o);
	if (zephir_array_isset_string_fetch(&o, &options, SL("timeout"), 0)) {
		timeout = zephir_get_intval(&o);
	}
	ZEPHIR_OBS_NVAR(&o);
	if (zephir_array_isset_string_fetch(&o, &options, SL("ssl"), 0)) {
		ssl = zephir_get_boolval(&o);
	}
	if (ssl) {
		if (unlikely(!((zephir_function_exists_ex(SL("ftp_ssl_connect") TSRMLS_CC) == SUCCESS)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_exception_ce, "Missing ssl ftp support", "nc/storage/ftp.zep", 35);
			return;
		}
		ZVAL_LONG(&_1$$7, port);
		ZVAL_LONG(&_2$$7, timeout);
		ZEPHIR_CALL_FUNCTION(&ftp, "ftp_ssl_connect", NULL, 140, &host, &_1$$7, &_2$$7);
		zephir_check_call_status();
	} else {
		if (unlikely(!((zephir_function_exists_ex(SL("ftp_connect") TSRMLS_CC) == SUCCESS)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_exception_ce, "Missing ftp support", "nc/storage/ftp.zep", 41);
			return;
		}
		ZVAL_LONG(&_3$$9, port);
		ZVAL_LONG(&_4$$9, timeout);
		ZEPHIR_CALL_FUNCTION(&ftp, "ftp_connect", NULL, 141, &host, &_3$$9, &_4$$9);
		zephir_check_call_status();
	}
	if (unlikely(!zephir_is_true(&ftp))) {
		ZEPHIR_INIT_VAR(&_5$$11);
		object_init_ex(&_5$$11, nc_storage_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$11);
		ZVAL_STRING(&_6$$11, "Cannot connect to ftp server '%s'");
		ZEPHIR_CALL_FUNCTION(&_7$$11, "sprintf", &_8, 2, &_6$$11, &host);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$11, "__construct", NULL, 3, &_7$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$11, "nc/storage/ftp.zep", 48 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_9 = zephir_is_true(&user);
	if (_9) {
		ZEPHIR_CALL_FUNCTION(&_10, "ftp_login", NULL, 142, &ftp, &user, &passwd);
		zephir_check_call_status();
		_9 = !zephir_is_true(&_10);
	}
	if (unlikely(_9)) {
		ZEPHIR_INIT_VAR(&_11$$12);
		object_init_ex(&_11$$12, nc_storage_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$12);
		ZVAL_STRING(&_12$$12, "Cannot login ftp server '%s@%s'");
		ZEPHIR_CALL_FUNCTION(&_13$$12, "sprintf", &_8, 2, &_12$$12, &user, &host);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", NULL, 3, &_13$$12);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$12, "nc/storage/ftp.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_14, "ftp_pasv", NULL, 143, &ftp, &__$true);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_14))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_storage_exception_ce, "Cannot set PASV mode", "nc/storage/ftp.zep", 56);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("ftp"), &ftp);
	zephir_update_property_zval(this_ptr, SL("baseDirectory"), &baseDirectory);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Ftp, getInternalHandler) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "ftp");

}

PHP_METHOD(Nc_Storage_Ftp, getBaseDirectory) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "baseDirectory");

}

PHP_METHOD(Nc_Storage_Ftp, store) {

	int ZEPHIR_LAST_CALL_STATUS;
	long type;
	zval *src_param = NULL, *pre_param = NULL, *ext_param = NULL, *type_param = NULL, _0, _2, _3, _4, _5, _6, _7, _8$$3;
	zval src, pre, ext, destUri, destPath, _1, _9$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&pre);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&destUri);
	ZVAL_UNDEF(&destPath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &src_param, &pre_param, &ext_param, &type_param);

	zephir_get_strval(&src, src_param);
	if (!pre_param) {
		ZEPHIR_INIT_VAR(&pre);
		ZVAL_STRING(&pre, "");
	} else {
		zephir_get_strval(&pre, pre_param);
	}
	if (!ext_param) {
		ZEPHIR_INIT_VAR(&ext);
		ZVAL_STRING(&ext, "");
	} else {
		zephir_get_strval(&ext, ext_param);
	}
	if (!type_param) {
		type = 0;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generateuri", NULL, 0, &src, &pre, &ext);
	zephir_check_call_status();
	zephir_get_strval(&_1, &_0);
	ZEPHIR_CPY_WRT(&destUri, &_1);
	zephir_read_property(&_2, this_ptr, SL("baseDirectory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_2, &destUri);
	zephir_get_strval(&destPath, &_3);
	ZEPHIR_CALL_FUNCTION(&_4, "dirname", NULL, 42, &destPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mkdirifnotexists", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("ftp"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_6, 2);
	ZEPHIR_CALL_FUNCTION(&_7, "ftp_put", NULL, 144, &_5, &destPath, &src, &_6);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_7))) {
		ZEPHIR_INIT_VAR(&_8$$3);
		object_init_ex(&_8$$3, nc_storage_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_SV(&_9$$3, "Cannot store file to: ", &destPath);
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "__construct", NULL, 3, &_9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$3, "nc/storage/ftp.zep", 83 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (type == 3 || type == 2) {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 38, &src);
			zephir_check_call_status();
			break;
		}
	} while(0);

	RETURN_CTOR(destUri);

}

PHP_METHOD(Nc_Storage_Ftp, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, _0;
	zval uri;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(&uri, uri_param);


	zephir_read_property(&_0, this_ptr, SL("ftp"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("ftp_delete", NULL, 145, &_0, &uri);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Storage_Ftp, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, _0, _1;
	zval uri;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(&uri, uri_param);


	zephir_read_property(&_0, this_ptr, SL("ftp"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "ftp_mdtm", NULL, 146, &_0, &uri);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG_IDENTICAL(&_1, -1));

}

PHP_METHOD(Nc_Storage_Ftp, __destruct) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("ftp"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "ftp_close", NULL, 147, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Ftp, mkDirIfNotExists) {

	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dir_param = NULL, ftp, parts, cur, stack, _0, _1, _2, *_8, _4$$3, _5$$3;
	zval dir, _3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&ftp);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&cur);
	ZVAL_UNDEF(&stack);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(&dir, dir_param);


	ZEPHIR_INIT_VAR(&stack);
	array_init(&stack);
	zephir_read_property(&_0, this_ptr, SL("ftp"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ftp, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "#/+#");
	ZVAL_LONG(&_0, -1);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&parts, "preg_split", NULL, 27, &_1, &dir, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SS(&_3, "Nc\\Storage\\Ftp", "::ignoreError");
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 148, &_3);
	zephir_check_call_status();
	while (1) {
		if (!(zephir_fast_count_int(&parts TSRMLS_CC) > 0)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_fast_join_str(&_4$$3, SL("/"), &parts TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&cur);
		ZEPHIR_CONCAT_SV(&cur, "/", &_4$$3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "ftp_chdir", &_6, 149, &ftp, &cur);
		zephir_check_call_status();
		if (!(zephir_is_true(&_5$$3))) {
			zephir_array_append(&stack, &cur, PH_SEPARATE, "nc/storage/ftp.zep", 123);
		}
		ZEPHIR_MAKE_REF(&parts);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_7, 150, &parts);
		ZEPHIR_UNREF(&parts);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 151);
	zephir_check_call_status();
	zephir_is_iterable(&stack, 0, "nc/storage/ftp.zep", 133);
	ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&stack), _8)
	{
		ZEPHIR_INIT_NVAR(&cur);
		ZVAL_COPY(&cur, _8);
		ZEPHIR_CALL_FUNCTION(NULL, "ftp_mkdir", &_9, 152, &ftp, &cur);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&cur);
	ZEPHIR_MM_RESTORE();

}

