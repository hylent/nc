
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/variables.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Nc_Cache_File) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Cache, File, nc, cache_file, nc_cache_cacheabstract_ce, nc_cache_file_method_entry, 0);

	zend_declare_property_null(nc_cache_file_ce, SL("directory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Cache_File, __construct) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *directory_param = NULL, *_0 = NULL, *_3 = NULL;
	zval *directory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory_param);

	zephir_get_strval(directory, directory_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", &_1, directory);
	zephir_check_call_status();
	_2 = !zephir_is_true(_0);
	if (!(_2)) {
		ZEPHIR_CALL_FUNCTION(&_3, "is_writable", &_4, directory);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (unlikely(_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Invalid cache directory", "nc/cache/file.zep", 10);
		return;
	}
	zephir_update_property_this(this_ptr, SL("directory"), directory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_File, flush) {

	zend_bool _10;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL, *_12 = NULL, *_13 = NULL;
	zval *p = NULL, *_0, *_1, *_2 = NULL, **_6, *_7 = NULL, *_8 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("directory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "/*.php");
	ZEPHIR_CALL_FUNCTION(&_2, "glob", &_3, _1);
	zephir_check_call_status();
	zephir_is_iterable(_2, &_5, &_4, 0, 0, "nc/cache/file.zep", 25);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(p, _6);
		ZEPHIR_INIT_NVAR(_7);
		ZVAL_STRING(_7, ";/[0-9a-f]{32}\\.php$;", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_8, "preg_match", &_9, _7, p);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		_10 = zephir_is_true(_8);
		if (_10) {
			ZEPHIR_CALL_FUNCTION(&_11, "is_writable", &_12, p);
			zephir_check_call_status();
			_10 = zephir_is_true(_11);
		}
		if (_10) {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_13, p);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_File, rawSet) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *key_param = NULL, *value, *lifetime_param = NULL, *path = NULL, *data = NULL, *_0 = NULL, *_1 = NULL, _2 = zval_used_for_init, _3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &lifetime_param);

	zephir_get_strval(key, key_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, key);
	zephir_check_call_status();
	if (lifetime > 0) {
		ZEPHIR_CALL_FUNCTION(&_0, "time", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1);
		zephir_var_export_ex(_1, &(value) TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "<?php return %ld < time() ? false : %s;", 0);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, (zephir_get_numberval(_0) + lifetime));
		ZEPHIR_CALL_FUNCTION(&data, "sprintf", &_4, &_2, &_3, _1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		zephir_var_export_ex(_1, &(value) TSRMLS_CC);
		ZEPHIR_INIT_NVAR(data);
		ZEPHIR_CONCAT_SVS(data, "<?php return ", _1, ";");
	}
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", &_5, path, data, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_File, rawGet) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *path = NULL, *data = NULL, *_0 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, key);
	zephir_check_call_status();
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_0);
	if (zephir_require_zval_ret(&_0, path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(data, _0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(data)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_1, path);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Nc_Cache_File, rawDelete) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *path = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, key);
	zephir_check_call_status();
	if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_0, path);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_File, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *key_param = NULL, *value, *lifetime_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &lifetime_param);

	zephir_get_strval(key, key_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, lifetime);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rawset", NULL, key, value, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_File, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rawget", NULL, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_File, getPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *key_param = NULL, *_0, *_1 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("directory"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "md5", &_2, key);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, _0, "/", _1, ".php");
	RETURN_MM();

}

