
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
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Cache_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Cache, Redis, nc, cache_redis, nc_cache_cacheabstract_ce, nc_cache_redis_method_entry, 0);

	zend_declare_property_null(nc_cache_redis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Cache_Redis, __construct) {

	zend_bool _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	long port, db, timeout;
	zval *host_param = NULL, *port_param = NULL, *db_param = NULL, *timeout_param = NULL, *redis = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_6, *_8 = NULL;
	zval *host = NULL, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &host_param, &port_param, &db_param, &timeout_param);

	zephir_get_strval(host, host_param);
	if (!port_param) {
		port = 6379;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!db_param) {
		db = 0;
	} else {
		db = zephir_get_intval(db_param);
	}
	if (!timeout_param) {
		timeout = 5;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "redis", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Missing extension: redis", "nc/cache/redis.zep", 14);
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Redis", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&redis, _3, "newinstance", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, port);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, timeout);
	ZEPHIR_CALL_METHOD(&_5, redis, "connect", NULL, host, _4, _6);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Cannot connect to redis server", "nc/cache/redis.zep", 19);
		return;
	}
	_7 = db > 0;
	if (_7) {
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, db);
		ZEPHIR_CALL_METHOD(&_8, redis, "select", NULL, _4);
		zephir_check_call_status();
		_7 = !zephir_is_true(_8);
	}
	if (unlikely(_7)) {
		ZEPHIR_INIT_NVAR(_4);
		object_init_ex(_4, nc_cache_exception_ce);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, db);
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SV(_9, "Cannot select db to ", &_0);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "nc/cache/redis.zep", 23 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Redis, flush) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "flushdb", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Redis, rawSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *key_param = NULL, *value, *lifetime_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &lifetime_param);

	zephir_get_strval(key, key_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, lifetime);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, key, value, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Redis, rawGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *r = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&r, _0, "get", NULL, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(r)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Cache_Redis, rawDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "del", NULL, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Redis, incrementInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long step;
	zval *key_param = NULL, *step_param = NULL, *_0, *_2;
	zval *key = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &step_param);

	zephir_get_strval(key, key_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":i:", key);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, step);
	ZEPHIR_RETURN_CALL_METHOD(_0, "incrby", NULL, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_Redis, decrementInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long step;
	zval *key_param = NULL, *step_param = NULL, *_0, *_2;
	zval *key = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &step_param);

	zephir_get_strval(key, key_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":i:", key);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, step);
	ZEPHIR_RETURN_CALL_METHOD(_0, "decrby", NULL, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_Redis, multiGet) {

	zend_bool _4;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *a = NULL, *i = NULL, *k = NULL, *v = NULL, *data, *_0, **_3, *_5, *_6 = NULL;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&a, _0, "mget", NULL, keys);
	zephir_check_call_status();
	zephir_is_iterable(keys, &_2, &_1, 0, 0, "nc/cache/redis.zep", 77);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(i, _2, _1);
		ZEPHIR_GET_HVALUE(k, _3);
		ZEPHIR_OBS_NVAR(v);
		_4 = zephir_array_isset_fetch(&v, a, i, 0 TSRMLS_CC);
		if (_4) {
			_4 = !ZEPHIR_IS_FALSE_IDENTICAL(v);
		}
		if (_4) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_6, _5, "unserialize", NULL, v);
			zephir_check_call_status();
			zephir_array_update_zval(&data, k, &_6, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Nc_Cache_Redis, multiDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *_0;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "del", NULL, keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Redis, groupSetAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *keyValues = NULL;
	zval *group_param = NULL, *keyValues_param = NULL, *k = NULL, *v = NULL, *data, **_2, *_3, *_4 = NULL, *_5;
	zval *group = NULL, *realGroup = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group_param, &keyValues_param);

	zephir_get_strval(group, group_param);
	zephir_get_arrval(keyValues, keyValues_param);
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	ZEPHIR_INIT_VAR(realGroup);
	ZEPHIR_CONCAT_SV(realGroup, ":g:", group);
	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/cache/redis.zep", 96);
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
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "delete", NULL, realGroup);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _5, "hmset", NULL, realGroup, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Redis, groupGetAll) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, *a = NULL, *k = NULL, *v = NULL, *data, *_0, **_4, *_5, *_6 = NULL;
	zval *group = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group_param);

	zephir_get_strval(group, group_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":g:", group);
	ZEPHIR_CALL_METHOD(&a, _0, "hgetall", NULL, _1);
	zephir_check_call_status();
	if (Z_TYPE_P(a) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	zephir_is_iterable(a, &_3, &_2, 0, 0, "nc/cache/redis.zep", 114);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(k, _3, _2);
		ZEPHIR_GET_HVALUE(v, _4);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_6, _5, "unserialize", NULL, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_6, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Nc_Cache_Redis, groupDeleteAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, *_0;
	zval *group = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group_param);

	zephir_get_strval(group, group_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":g:", group);
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Redis, groupSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *keyValues = NULL;
	zval *group_param = NULL, *keyValues_param = NULL, *k = NULL, *v = NULL, *data, **_2, *_3, *_4 = NULL;
	zval *group = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group_param, &keyValues_param);

	zephir_get_strval(group, group_param);
	zephir_get_arrval(keyValues, keyValues_param);
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/cache/redis.zep", 130);
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
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, ":g:", group);
	ZEPHIR_CALL_METHOD(NULL, _3, "hmset", NULL, _5, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Redis, groupGet) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL;
	zval *group_param = NULL, *keys_param = NULL, *a = NULL, *k = NULL, *v = NULL, *data, *_0, **_4, *_5, *_6 = NULL;
	zval *group = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group_param, &keys_param);

	zephir_get_strval(group, group_param);
	zephir_get_arrval(keys, keys_param);
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":g:", group);
	ZEPHIR_CALL_METHOD(&a, _0, "hmget", NULL, _1, keys);
	zephir_check_call_status();
	if (unlikely(Z_TYPE_P(a) != IS_ARRAY)) {
		RETURN_MM_NULL();
	}
	zephir_is_iterable(a, &_3, &_2, 0, 0, "nc/cache/redis.zep", 148);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(k, _3, _2);
		ZEPHIR_GET_HVALUE(v, _4);
		if (!ZEPHIR_IS_FALSE_IDENTICAL(v)) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_6, _5, "unserialize", NULL, v);
			zephir_check_call_status();
			zephir_array_update_zval(&data, k, &_6, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Nc_Cache_Redis, groupDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *keys = NULL;
	zval *group_param = NULL, *keys_param = NULL, *k = NULL, **_2, *_3;
	zval *group = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group_param, &keys_param);

	zephir_get_strval(group, group_param);
	zephir_get_arrval(keys, keys_param);


	zephir_is_iterable(keys, &_1, &_0, 0, 0, "nc/cache/redis.zep", 158);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(k, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, ":g:", group);
		ZEPHIR_CALL_METHOD(NULL, _3, "hdel", NULL, _4, k);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

