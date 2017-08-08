
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
#include "kernel/memory.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Cache_CacheBackendAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Cache, CacheBackendAbstract, nc, cache_cachebackendabstract, nc_cache_cachebackendabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(nc_cache_cachebackendabstract_ce TSRMLS_CC, 1, nc_cache_cachebackendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Cache_CacheBackendAbstract, getPool) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *poolName_param = NULL;
	zval poolName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &poolName_param);

	zephir_get_strval(&poolName, poolName_param);


	object_init_ex(return_value, nc_cache_cachepool_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 11, this_ptr, &poolName);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_CacheBackendAbstract, storeMany) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	long ttl;
	zval keyValues;
	zval *poolName_param = NULL, *keyValues_param = NULL, *ttl_param = NULL, key, value, *_0, _3$$3;
	zval poolName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&keyValues);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &poolName_param, &keyValues_param, &ttl_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_arrval(&keyValues, keyValues_param);
	if (!ttl_param) {
		ttl = 0;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	zephir_is_iterable(&keyValues, 0, "nc/cache/cachebackendabstract.zep", 17);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keyValues), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZVAL_LONG(&_3$$3, ttl);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "store", &_4, 0, &poolName, &key, &value, &_3$$3);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheBackendAbstract, fetchMany) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval keys;
	zval *poolName_param = NULL, *keys_param = NULL, key, value, keyValues, *_0;
	zval poolName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&keyValues);
	ZVAL_UNDEF(&keys);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &poolName_param, &keys_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_INIT_VAR(&keyValues);
	array_init(&keyValues);
	zephir_is_iterable(&keys, 0, "nc/cache/cachebackendabstract.zep", 30);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _0);
		ZEPHIR_CALL_METHOD(&value, this_ptr, "fetch", &_1, 0, &poolName, &key);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) != IS_NULL) {
			zephir_array_update_zval(&keyValues, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&keyValues);

}

PHP_METHOD(Nc_Cache_CacheBackendAbstract, forgetMany) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval keys;
	zval *poolName_param = NULL, *keys_param = NULL, key, *_0;
	zval poolName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &poolName_param, &keys_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_arrval(&keys, keys_param);


	zephir_is_iterable(&keys, 0, "nc/cache/cachebackendabstract.zep", 40);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "forget", &_1, 0, &poolName, &key);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

