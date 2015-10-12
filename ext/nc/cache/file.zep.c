
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
#include "kernel/string.h"
#include "kernel/time.h"
#include "kernel/variables.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Nc_Cache_File) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Cache, File, nc, cache_file, nc_cache_cacheabstract_ce, nc_cache_file_method_entry, 0);

	zend_declare_property_null(nc_cache_file_ce, SL("directory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Cache_File, __construct) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *directory_param = NULL, *_0 = NULL, *_2 = NULL;
	zval *directory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory_param);

	zephir_get_strval(directory, directory_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 21, directory);
	zephir_check_call_status();
	_1 = !zephir_is_true(_0);
	if (!(_1)) {
		ZEPHIR_CALL_FUNCTION(&_2, "is_writable", NULL, 22, directory);
		zephir_check_call_status();
		_1 = !zephir_is_true(_2);
	}
	if (unlikely(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Invalid cache directory", "nc/cache/file.zep", 10);
		return;
	}
	zephir_update_property_this(this_ptr, SL("directory"), directory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_File, flush) {

	zend_bool _9$$3;
	HashTable *_4;
	HashPosition _3;
	zval *p = NULL, *_0, *_1, *_2 = NULL, **_5, *_6$$3 = NULL, *_7$$3 = NULL, _8$$3 = zval_used_for_init, *_10$$3 = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("directory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "/*.php");
	ZEPHIR_CALL_FUNCTION(&_2, "glob", NULL, 23, _1);
	zephir_check_call_status();
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "nc/cache/file.zep", 25);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(p, _5);
		ZEPHIR_INIT_NVAR(_6$$3);
		ZEPHIR_INIT_NVAR(_7$$3);
		ZEPHIR_SINIT_NVAR(_8$$3);
		ZVAL_STRING(&_8$$3, ";/[0-9a-f]{32}\\.php$;", 0);
		zephir_preg_match(_7$$3, &_8$$3, p, _6$$3, 0, 0 , 0  TSRMLS_CC);
		_9$$3 = zephir_is_true(_7$$3);
		if (_9$$3) {
			ZEPHIR_CALL_FUNCTION(&_10$$3, "is_writable", &_11, 22, p);
			zephir_check_call_status();
			_9$$3 = zephir_is_true(_10$$3);
		}
		if (_9$$3) {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_12, 24, p);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_File, rawSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *key_param = NULL, *value, *lifetime_param = NULL, *path = NULL, *data = NULL, _5, *_0$$3, *_1$$3 = NULL, _2$$3, _3$$3, *_4$$4 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &lifetime_param);

	zephir_get_strval(key, key_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0, key);
	zephir_check_call_status();
	if (lifetime > 0) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_time(_0$$3);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_INIT_NVAR(_1$$3);
		zephir_var_export_ex(_1$$3, &value TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "<?php return %ld < time() ? false : %s;", 0);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, (zephir_get_numberval(_0$$3) + lifetime));
		ZEPHIR_CALL_FUNCTION(&data, "sprintf", NULL, 6, &_2$$3, &_3$$3, _1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_INIT_NVAR(_4$$4);
		zephir_var_export_ex(_4$$4, &value TSRMLS_CC);
		ZEPHIR_INIT_NVAR(data);
		ZEPHIR_CONCAT_SVS(data, "<?php return ", _4$$4, ";");
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 25, path, data, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_File, rawGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *path = NULL, *data = NULL, *_0 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0, key);
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
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 24, path);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Nc_Cache_File, rawDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *path = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0, key);
	zephir_check_call_status();
	if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 24, path);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rawset", NULL, 0, key, value, _0);
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rawget", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_File, getPath) {

	zval *key_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("directory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_md5(_1, key);
	ZEPHIR_CONCAT_VSVS(return_value, _0, "/", _1, ".php");
	RETURN_MM();

}

