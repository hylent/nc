
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Cache_Apcu) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Cache, Apcu, nc, cache_apcu, nc_cache_cachebackendabstract_ce, nc_cache_apcu_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Cache_Apcu, __construct) {

	zend_bool _2;
	zval _0, _1, _3, _4;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "apcu");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 28, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Missing extension 'apcu'", "nc/cache/apcu.zep", 8);
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	_2 = ZEPHIR_IS_STRING(&_0, "cli");
	if (_2) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "apc.enable_cli");
		ZEPHIR_CALL_FUNCTION(&_4, "ini_get", NULL, 29, &_3);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_LONG(&_4, 1);
	}
	if (unlikely(_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Missing apcu support in cli mode, check ini item 'apc.enable_cli'", "nc/cache/apcu.zep", 12);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apcu, clear) {

	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *poolName_param = NULL, iter, _0, _4, _5, _6, _7, _8, _9, _1$$3, _2$$3, _11$$5;
	zval poolName, _3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&iter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_11$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &poolName_param);

	if (!poolName_param) {
		ZEPHIR_INIT_VAR(&poolName);
		ZVAL_STRING(&poolName, "");
	} else {
		zephir_get_strval(&poolName, poolName_param);
	}


	if (zephir_fast_strlen_ev(&poolName) < 1) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "user");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "apcu_clear_cache", NULL, 30, &_1$$3);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(&_2$$3))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Cannot clear all user caches", "nc/cache/apcu.zep", 22);
			return;
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&iter);
	object_init_ex(&iter, zephir_get_internal_ce(SL("apcuiterator")));
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &poolName, ":");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/");
	ZEPHIR_CALL_FUNCTION(&_5, "preg_quote", NULL, 31, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVS(&_6, "/^", &_5, "/");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "user");
	ZVAL_LONG(&_7, 2);
	ZVAL_LONG(&_8, 1000);
	ZEPHIR_CALL_METHOD(NULL, &iter, "__construct", NULL, 0, &_4, &_6, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &iter, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_9, &iter, "valid", &_10, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_9))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&_11$$5, &iter, "key", &_12, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "apcu_delete", &_13, 32, &_11$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &iter, "next", &_14, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apcu, store) {

	int ZEPHIR_LAST_CALL_STATUS;
	long ttl;
	zval *poolName_param = NULL, *key_param = NULL, *value, value_sub, *ttl_param = NULL, _1, _2, _3$$3, _4$$3, _5$$3;
	zval poolName, key, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&value_sub);
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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSV(&_0, &poolName, ":", &key);
	ZVAL_LONG(&_1, ttl);
	ZEPHIR_CALL_FUNCTION(&_2, "apcu_store", NULL, 33, &_0, value, &_1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, nc_cache_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Cannot store cache key '%s'");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", NULL, 2, &_4$$3, &key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "nc/cache/apcu.zep", 39 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apcu, storeMany) {

	zend_string *_2;
	zend_ulong _1;
	int ZEPHIR_LAST_CALL_STATUS;
	long ttl;
	zval keyValues;
	zval *poolName_param = NULL, *keyValues_param = NULL, *ttl_param = NULL, __$null, k, v, kvs, *_0, _4, _5, _3$$3;
	zval poolName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&poolName);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&kvs);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
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


	ZEPHIR_INIT_VAR(&kvs);
	array_init(&kvs);
	zephir_is_iterable(&keyValues, 0, "nc/cache/apcu.zep", 51);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&keyValues), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSV(&_3$$3, &poolName, ":", &k);
		zephir_array_update_zval(&kvs, &_3$$3, &v, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZVAL_LONG(&_4, ttl);
	ZEPHIR_CALL_FUNCTION(&_5, "apcu_store", NULL, 33, &kvs, &__$null, &_4);
	zephir_check_call_status();
	if (unlikely(!(!zephir_is_true(&_5)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Cannot store cache keys", "nc/cache/apcu.zep", 52);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apcu, fetch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *poolName_param = NULL, *key_param = NULL, value, success;
	zval poolName, key, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&success);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &poolName_param, &key_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&success);
	ZVAL_NULL(&success);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSV(&_0, &poolName, ":", &key);
	ZEPHIR_MAKE_REF(&success);
	ZEPHIR_CALL_FUNCTION(&value, "apcu_fetch", NULL, 34, &_0, &success);
	ZEPHIR_UNREF(&success);
	zephir_check_call_status();
	if (zephir_is_true(&success)) {
		RETURN_CCTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apcu, fetchMany) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval keys;
	zval *poolName_param = NULL, *keys_param = NULL, pre, k, ks, success, kvs, v, len, r, *_1, _2$$3, *_3$$4, _6$$5;
	zval poolName, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pre);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&ks);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&kvs);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&len);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&keys);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &poolName_param, &keys_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_INIT_VAR(&ks);
	array_init(&ks);
	ZEPHIR_INIT_VAR(&success);
	ZVAL_NULL(&success);
	ZEPHIR_INIT_VAR(&r);
	array_init(&r);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VS(&_0, &poolName, ":");
	ZEPHIR_CPY_WRT(&pre, &_0);
	zephir_is_iterable(&keys, 0, "nc/cache/apcu.zep", 76);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _1)
	{
		ZEPHIR_INIT_NVAR(&k);
		ZVAL_COPY(&k, _1);
		ZEPHIR_INIT_LNVAR(_2$$3);
		ZEPHIR_CONCAT_VV(&_2$$3, &pre, &k);
		zephir_array_append(&ks, &_2$$3, PH_SEPARATE, "nc/cache/apcu.zep", 73);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_MAKE_REF(&success);
	ZEPHIR_CALL_FUNCTION(&kvs, "apcu_fetch", NULL, 34, &ks, &success);
	ZEPHIR_UNREF(&success);
	zephir_check_call_status();
	if (zephir_is_true(&success)) {
		ZEPHIR_INIT_VAR(&len);
		ZVAL_LONG(&len, zephir_fast_strlen_ev(&pre));
		zephir_is_iterable(&kvs, 0, "nc/cache/apcu.zep", 82);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&kvs), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&k, _5$$4);
			} else {
				ZVAL_LONG(&k, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _3$$4);
			ZEPHIR_INIT_NVAR(&_6$$5);
			zephir_substr(&_6$$5, &k, zephir_get_intval(&len), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_array_update_zval(&r, &_6$$5, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Cache_Apcu, forget) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *poolName_param = NULL, *key_param = NULL;
	zval poolName, key, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&poolName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &poolName_param, &key_param);

	zephir_get_strval(&poolName, poolName_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSV(&_0, &poolName, ":", &key);
	ZEPHIR_CALL_FUNCTION(NULL, "apcu_delete", NULL, 32, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

