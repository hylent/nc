
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


ZEPHIR_INIT_CLASS(Nc_Cache_CachePool) {

	ZEPHIR_REGISTER_CLASS(Nc\\Cache, CachePool, nc, cache_cachepool, nc_cache_cachepool_method_entry, 0);

	zend_declare_property_null(nc_cache_cachepool_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_cache_cachepool_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Cache_CachePool, __construct) {

	zval name;
	zval *backend, backend_sub, *name_param = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&backend_sub);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &backend, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, SL("backend"), backend);
	zephir_update_property_zval(this_ptr, SL("name"), &name);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CachePool, getBackend) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "backend");

}

PHP_METHOD(Nc_Cache_CachePool, getName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "name");

}

PHP_METHOD(Nc_Cache_CachePool, clear) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clear", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CachePool, store) {

	int ZEPHIR_LAST_CALL_STATUS;
	long ttl;
	zval *key_param = NULL, *value, value_sub, *ttl_param = NULL, _0, _1, _2;
	zval key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &ttl_param);

	zephir_get_strval(&key, key_param);
	if (!ttl_param) {
		ttl = 0;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, ttl);
	ZEPHIR_CALL_METHOD(NULL, &_0, "store", NULL, 0, &_1, &key, value, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CachePool, storeMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	long ttl;
	zval *keyValues_param = NULL, *ttl_param = NULL, _0, _1, _2;
	zval keyValues;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyValues);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyValues_param, &ttl_param);

	zephir_get_arrval(&keyValues, keyValues_param);
	if (!ttl_param) {
		ttl = 0;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, ttl);
	ZEPHIR_CALL_METHOD(NULL, &_0, "storemany", NULL, 0, &_1, &keyValues, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CachePool, fetch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "fetch", NULL, 0, &_1, &key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_CachePool, fetchMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0, _1;
	zval keys;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "fetchmany", NULL, 0, &_1, &keys);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_CachePool, forget) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "forget", NULL, 0, &_1, &key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CachePool, forgetMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0, _1;
	zval keys;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "forgetmany", NULL, 0, &_1, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

