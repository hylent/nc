
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/variables.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(Nc_Cache_FileSystem) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Cache, FileSystem, nc, cache_filesystem, nc_cache_cachebackendabstract_ce, nc_cache_filesystem_method_entry, 0);

	zend_declare_property_null(nc_cache_filesystem_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_cache_filesystem_ce, SL("mode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Cache_FileSystem, rmDirRecursively) {

	zend_bool _1$$4;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dir_param = NULL, handle, path, _2$$4, _3$$4;
	zval dir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(&dir, dir_param);


	ZEPHIR_CALL_FUNCTION(&handle, "opendir", NULL, 36, &dir);
	zephir_check_call_status();
	if (!(zephir_is_true(&handle))) {
		RETURN_MM_NULL();
	}
	while (1) {
		ZEPHIR_CALL_FUNCTION(&path, "readdir", &_0, 37, &handle);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&path)) {
			break;
		}
		_1$$4 = ZEPHIR_IS_STRING(&path, ".");
		if (!(_1$$4)) {
			_1$$4 = ZEPHIR_IS_STRING(&path, "..");
		}
		if (_1$$4) {
			continue;
		}
		ZEPHIR_INIT_LNVAR(_2$$4);
		ZEPHIR_CONCAT_VSV(&_2$$4, &dir, "/", &path);
		ZEPHIR_CPY_WRT(&path, &_2$$4);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "is_dir", &_4, 38, &path);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$4)) {
			ZEPHIR_CALL_SELF(NULL, "rmdirrecursively", &_5, 0, &path);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_6, 39, &path);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "rmdir", NULL, 40, &dir);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_FileSystem, __construct) {

	long mode;
	zval *baseDirectory_param = NULL, *mode_param = NULL, _0;
	zval baseDirectory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseDirectory);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &baseDirectory_param, &mode_param);

	zephir_get_strval(&baseDirectory, baseDirectory_param);
	if (!mode_param) {
		mode = 0777;
	} else {
		mode = zephir_get_intval(mode_param);
	}


	zephir_update_property_zval(this_ptr, SL("baseDirectory"), &baseDirectory);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, mode);
	zephir_update_property_zval(this_ptr, SL("mode"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_FileSystem, getBaseDirectory) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "baseDirectory");

}

PHP_METHOD(Nc_Cache_FileSystem, getMode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "mode");

}

PHP_METHOD(Nc_Cache_FileSystem, clear) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *poolName_param = NULL, _0, _2, _1$$3;
	zval poolName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &poolName_param);

	if (!poolName_param) {
		ZEPHIR_INIT_VAR(&poolName);
		ZVAL_STRING(&poolName, "");
	} else {
		zephir_get_strval(&poolName, poolName_param);
	}


	if (zephir_fast_strlen_ev(&poolName) < 1) {
		zephir_read_property(&_1$$3, this_ptr, SL("baseDirectory"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_SELF(NULL, "rmdirrecursively", NULL, 0, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getdir", NULL, 0, &poolName);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(NULL, "rmdirrecursively", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_FileSystem, store) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	long ttl;
	zval *poolName_param = NULL, *key_param = NULL, *value, value_sub, *ttl_param = NULL, path, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zval poolName, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &poolName_param, &key_param, &value, &ttl_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_strval(&key, key_param);
	if (!ttl_param) {
		ttl = 0;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0, &poolName, &key, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, ttl);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "packdata", NULL, 0, value, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&_2, "file_put_contents", NULL, 41, &path, &_1, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, nc_cache_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Cannot write cache value to path '%s'");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", NULL, 2, &_4$$3, &path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "nc/cache/filesystem.zep", 72 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_FileSystem, fetch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *poolName_param = NULL, *key_param = NULL, path, _0$$3;
	zval poolName, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &poolName_param, &key_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0, &poolName, &key);
	zephir_check_call_status();
	if ((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_0$$3);
		if (zephir_require_zval_ret(&_0$$3, &path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_CCTOR(&_0$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_FileSystem, forget) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *poolName_param = NULL, *key_param = NULL, path, _1, _2$$3, _3$$3, _4$$3;
	zval poolName, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &poolName_param, &key_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0, &poolName, &key);
	zephir_check_call_status();
	_0 = (zephir_file_exists(&path TSRMLS_CC) == SUCCESS);
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "unlink", NULL, 39, &path);
		zephir_check_call_status();
		_0 = !zephir_is_true(&_1);
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, nc_cache_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Cannot forget cache value in path '%s'");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 2, &_3$$3, &path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "nc/cache/filesystem.zep", 94 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_FileSystem, getDir) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *poolName_param = NULL, _0, _1;
	zval poolName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &poolName_param);

	zephir_get_strval(&poolName, poolName_param);


	zephir_read_property(&_0, this_ptr, SL("baseDirectory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "urlencode", NULL, 42, &poolName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_0, "/", &_1);
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_FileSystem, getPath) {

	unsigned char _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool mkDirIfNeeded, _6$$3;
	zval *poolName_param = NULL, *key_param = NULL, *mkDirIfNeeded_param = NULL, __$true, dirname, _0, _2, _7$$3, _8$$3, _9$$4, _10$$4, _11$$4;
	zval poolName, key, hash, path, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&dirname);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &poolName_param, &key_param, &mkDirIfNeeded_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_strval(&key, key_param);
	if (!mkDirIfNeeded_param) {
		mkDirIfNeeded = 0;
	} else {
		mkDirIfNeeded = zephir_get_boolval(mkDirIfNeeded_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "sha1", NULL, 10, &key);
	zephir_check_call_status();
	zephir_get_strval(&_1, &_0);
	ZEPHIR_CPY_WRT(&hash, &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getdir", NULL, 0, &poolName);
	zephir_check_call_status();
	zephir_get_strval(&_3, &_2);
	ZEPHIR_CPY_WRT(&path, &_3);
	zephir_concat_self_str(&path, "/", sizeof("/")-1 TSRMLS_CC);
	_4 = ZEPHIR_STRING_OFFSET(&hash, 0);
	zephir_concat_self_char(&path, _4 TSRMLS_CC);
	_5 = ZEPHIR_STRING_OFFSET(&hash, 1);
	zephir_concat_self_char(&path, _5 TSRMLS_CC);
	zephir_concat_self_str(&path, "/", sizeof("/")-1 TSRMLS_CC);
	zephir_concat_self(&path, &hash TSRMLS_CC);
	zephir_concat_self_str(&path, ".php", sizeof(".php")-1 TSRMLS_CC);
	if (mkDirIfNeeded) {
		ZEPHIR_CALL_FUNCTION(&dirname, "dirname", NULL, 43, &path);
		zephir_check_call_status();
		_6$$3 = !((zephir_file_exists(&dirname TSRMLS_CC) == SUCCESS));
		if (_6$$3) {
			zephir_read_property(&_7$$3, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_8$$3, "mkdir", NULL, 44, &dirname, &_7$$3, &__$true);
			zephir_check_call_status();
			_6$$3 = !zephir_is_true(&_8$$3);
		}
		if (UNEXPECTED(_6$$3)) {
			ZEPHIR_INIT_VAR(&_9$$4);
			object_init_ex(&_9$$4, nc_cache_exception_ce);
			ZEPHIR_INIT_VAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "Cannot mkdir '%s'");
			ZEPHIR_CALL_FUNCTION(&_11$$4, "sprintf", NULL, 2, &_10$$4, &dirname);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", NULL, 3, &_11$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$4, "nc/cache/filesystem.zep", 121 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&path);

}

PHP_METHOD(Nc_Cache_FileSystem, packData) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	long ttl;
	zval *value, value_sub, *ttl_param = NULL, _0$$3, _1$$3, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &ttl_param);

	ttl = zephir_get_intval(ttl_param);


	if (ttl < 1) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_var_export_ex(&_0$$3, value TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "<?php return %s;\n");
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 2, &_1$$3, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_time(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_var_export_ex(&_4, value TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "<?php return time() > %d ? null : %s;\n");
	ZVAL_LONG(&_6, (ttl + zephir_get_numberval(&_3)));
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 2, &_5, &_6, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

