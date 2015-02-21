
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
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Cache_Apc) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Cache, Apc, nc, cache_apc, nc_cache_cacheadapter_ce, nc_cache_apc_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Cache_Apc, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval _0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apc", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Missing extension: apc", "nc/cache/apc.zep", 10);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apc, flush) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _0;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "user", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "apc_clear_cache", NULL, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apc, rawSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *key_param = NULL, *value, *lifetime_param = NULL, _0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &lifetime_param);

	zephir_get_strval(key, key_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, lifetime);
	ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, key, value, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apc, rawGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *r = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_FUNCTION(&r, "apc_fetch", NULL, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(r)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Cache_Apc, rawDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_FUNCTION(NULL, "apc_delete", NULL, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apc, incrementInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long step;
	zval *key_param = NULL, *step_param = NULL, *value = NULL, *_0, _1;
	zval *key = NULL, *realKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &step_param);

	zephir_get_strval(key, key_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	ZEPHIR_INIT_VAR(realKey);
	ZEPHIR_CONCAT_SV(realKey, ":i:", key);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, step);
	ZEPHIR_CALL_FUNCTION(&value, "apc_inc", NULL, realKey, _0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, step);
		ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, realKey, &_1);
		zephir_check_call_status();
		RETURN_MM_LONG(step);
	}
	RETURN_MM_LONG(zephir_get_intval(value));

}

PHP_METHOD(Nc_Cache_Apc, decrementInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long step;
	zval *key_param = NULL, *step_param = NULL, *value = NULL, *_0, _1;
	zval *key = NULL, *realKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &step_param);

	zephir_get_strval(key, key_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	ZEPHIR_INIT_VAR(realKey);
	ZEPHIR_CONCAT_SV(realKey, ":i:", key);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, step);
	ZEPHIR_CALL_FUNCTION(&value, "apc_dec", NULL, realKey, _0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, -step);
		ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, realKey, &_1);
		zephir_check_call_status();
		RETURN_MM_LONG(-step);
	}
	RETURN_MM_LONG(zephir_get_intval(value));

}

PHP_METHOD(Nc_Cache_Apc, multiSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	long expiredAt;
	zval *keyValues_param = NULL, *expiredAt_param = NULL, *k = NULL, *v = NULL, *data, **_2, *_3, *_4 = NULL, _5;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyValues_param, &expiredAt_param);

	zephir_get_arrval(keyValues, keyValues_param);
	if (!expiredAt_param) {
		expiredAt = 0;
	} else {
		expiredAt = zephir_get_intval(expiredAt_param);
	}
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/cache/apc.zep", 81);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4, _3, "serialize", NULL, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_FUNCTION(&_4, "time", NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, (expiredAt - zephir_get_numberval(_4)));
	ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, data, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Apc, multiGet) {

	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *r = NULL, *k = NULL, *v = NULL, *data, **_3, *_4, *_5 = NULL;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	ZEPHIR_CALL_FUNCTION(&r, "apc_fetch", NULL, keys);
	zephir_check_call_status();
	_0 = Z_TYPE_P(r) == IS_ARRAY;
	if (_0) {
		_0 = zephir_is_true(r);
	}
	if (_0) {
		zephir_is_iterable(r, &_2, &_1, 0, 0, "nc/cache/apc.zep", 93);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(k, _2, _1);
			ZEPHIR_GET_HVALUE(v, _3);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_5, _4, "unserialize", NULL, v);
			zephir_check_call_status();
			zephir_array_update_zval(&data, k, &_5, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

