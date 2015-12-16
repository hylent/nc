
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/variables.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Nc_Std_CacheFileSystem) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, CacheFileSystem, nc, std_cachefilesystem, nc_std_cachefilesystem_method_entry, 0);

	zend_declare_property_null(nc_std_cachefilesystem_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_std_cachefilesystem_ce TSRMLS_CC, 1, nc_std_cacheinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_CacheFileSystem, __construct) {

	zval *baseDirectory_param = NULL;
	zval *baseDirectory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseDirectory_param);

	zephir_get_strval(baseDirectory, baseDirectory_param);


	zephir_update_property_this(this_ptr, SL("baseDirectory"), baseDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_CacheFileSystem, setCache) {

	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *identifier_param = NULL, *data, *lifetime_param = NULL, *_0 = NULL, *_1, _14, *_15 = NULL, *_3$$3, *_4$$3 = NULL, _5$$3, _6$$3, *_7$$3 = NULL, *_10$$4 = NULL, _11$$4, *_12$$4 = NULL, *_16$$5;
	zval *identifier = NULL, *path = NULL, *d = NULL, *_2 = NULL, *_9$$3 = NULL, *_13$$4 = NULL, *_17$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &identifier_param, &data, &lifetime_param);

	zephir_get_strval(identifier, identifier_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "path", NULL, 0, identifier, _1);
	zephir_check_call_status();
	zephir_get_strval(_2, _0);
	ZEPHIR_CPY_WRT(path, _2);
	if (lifetime > 0) {
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_time(_3$$3);
		lifetime += zephir_get_intval(_3$$3);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_var_export_ex(_4$$3, &data TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_STRING(&_5$$3, "<?php return time() > %d ? null : %s;\n", 0);
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_LONG(&_6$$3, lifetime);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "sprintf", &_8, 1, &_5$$3, &_6$$3, _4$$3);
		zephir_check_call_status();
		zephir_get_strval(_9$$3, _7$$3);
		ZEPHIR_CPY_WRT(d, _9$$3);
	} else {
		ZEPHIR_INIT_VAR(_10$$4);
		ZEPHIR_INIT_NVAR(_10$$4);
		zephir_var_export_ex(_10$$4, &data TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_11$$4);
		ZVAL_STRING(&_11$$4, "<?php return %s;\n", 0);
		ZEPHIR_CALL_FUNCTION(&_12$$4, "sprintf", &_8, 1, &_11$$4, _10$$4);
		zephir_check_call_status();
		zephir_get_strval(_13$$4, _12$$4);
		ZEPHIR_CPY_WRT(d, _13$$4);
	}
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, 2);
	ZEPHIR_CALL_FUNCTION(&_15, "file_put_contents", NULL, 84, path, d, &_14);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_15))) {
		ZEPHIR_INIT_VAR(_16$$5);
		object_init_ex(_16$$5, nc_std_exception_ce);
		ZEPHIR_INIT_VAR(_17$$5);
		ZEPHIR_CONCAT_SV(_17$$5, "Cannot write data to path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _16$$5, "__construct", NULL, 2, _17$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_16$$5, "nc/std/cachefilesystem.zep", 26 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_CacheFileSystem, getCache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0 = NULL, *_2$$3 = NULL;
	zval *identifier = NULL, *path = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "path", NULL, 0, identifier);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(path, _1);
	if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_2$$3);
		if (zephir_require_zval_ret(&_2$$3, path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_CCTOR(_2$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_CacheFileSystem, deleteCache) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0 = NULL, *_3 = NULL, *_4$$3;
	zval *identifier = NULL, *path = NULL, *_1 = NULL, *_5$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "path", NULL, 0, identifier);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(path, _1);
	_2 = (zephir_file_exists(path TSRMLS_CC) == SUCCESS);
	if (_2) {
		ZEPHIR_CALL_FUNCTION(&_3, "unlink", NULL, 121, path);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (unlikely(_2)) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, nc_std_exception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, "Cannot forget data in path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 2, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "nc/std/cachefilesystem.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_CacheFileSystem, path) {

	unsigned char _4, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool mkdirIfNeeded, _8$$3;
	zval *identifier_param = NULL, *mkdirIfNeeded_param = NULL, *_0 = NULL, *_2, *_6$$3 = NULL, _9$$3, *_10$$3 = NULL, *_11$$4;
	zval *identifier = NULL, *hash = NULL, *path = NULL, *dirname = NULL, *_1 = NULL, *_3 = NULL, *_7$$3 = NULL, *_12$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &identifier_param, &mkdirIfNeeded_param);

	zephir_get_strval(identifier, identifier_param);
	if (!mkdirIfNeeded_param) {
		mkdirIfNeeded = 0;
	} else {
		mkdirIfNeeded = zephir_get_boolval(mkdirIfNeeded_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "sha1", NULL, 115, identifier);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(hash, _1);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	zephir_get_strval(_3, _2);
	ZEPHIR_CPY_WRT(path, _3);
	zephir_concat_self_str(&path, "/", sizeof("/")-1 TSRMLS_CC);
	_4 = ZEPHIR_STRING_OFFSET(hash, 0);
	zephir_concat_self_char(&path, _4 TSRMLS_CC);
	_5 = ZEPHIR_STRING_OFFSET(hash, 1);
	zephir_concat_self_char(&path, _5 TSRMLS_CC);
	zephir_concat_self_str(&path, "/", sizeof("/")-1 TSRMLS_CC);
	zephir_concat_self(&path, hash TSRMLS_CC);
	zephir_concat_self_str(&path, ".php", sizeof(".php")-1 TSRMLS_CC);
	if (mkdirIfNeeded) {
		ZEPHIR_CALL_FUNCTION(&_6$$3, "dirname", NULL, 122, path);
		zephir_check_call_status();
		zephir_get_strval(_7$$3, _6$$3);
		ZEPHIR_CPY_WRT(dirname, _7$$3);
		_8$$3 = !((zephir_file_exists(dirname TSRMLS_CC) == SUCCESS));
		if (_8$$3) {
			ZEPHIR_SINIT_VAR(_9$$3);
			ZVAL_LONG(&_9$$3, 0755);
			ZEPHIR_CALL_FUNCTION(&_10$$3, "mkdir", NULL, 123, dirname, &_9$$3, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			_8$$3 = !zephir_is_true(_10$$3);
		}
		if (unlikely(_8$$3)) {
			ZEPHIR_INIT_VAR(_11$$4);
			object_init_ex(_11$$4, nc_std_exception_ce);
			ZEPHIR_INIT_VAR(_12$$4);
			ZEPHIR_CONCAT_SV(_12$$4, "Cannot mkdir: ", dirname);
			ZEPHIR_CALL_METHOD(NULL, _11$$4, "__construct", NULL, 2, _12$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_11$$4, "nc/std/cachefilesystem.zep", 67 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(path);

}

