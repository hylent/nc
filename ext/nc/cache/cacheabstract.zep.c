
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Cache_CacheAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Cache, CacheAbstract, nc, cache_cacheabstract, nc_cache_cacheabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_cache_cacheabstract_ce, SL("serializer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_cache_cacheabstract_ce TSRMLS_CC, 1, nc_cache_cacheinterface_ce);
	zend_class_implements(nc_cache_cacheabstract_ce TSRMLS_CC, 1, nc_serializer_serializerawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Cache_CacheAbstract, setSerializer) {

	zval *serializer;

	zephir_fetch_params(0, 1, 0, &serializer);



	zephir_update_property_this(this_ptr, SL("serializer"), serializer TSRMLS_CC);

}

PHP_METHOD(Nc_Cache_CacheAbstract, getSerializer) {

	

	RETURN_MEMBER(this_ptr, "serializer");

}

PHP_METHOD(Nc_Cache_CacheAbstract, setInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long value;
	zval *key_param = NULL, *value_param = NULL, *_1;
	zval *key = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(key, key_param);
	value = zephir_get_intval(value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, ":i:", key);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rawset", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, getInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0 = NULL;
	zval *key = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":i:", key);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "rawget", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(Nc_Cache_CacheAbstract, deleteInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, ":i:", key);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rawdelete", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, incrementInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long step, value = 0;
	zval *key_param = NULL, *step_param = NULL, *_0 = NULL, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &step_param);

	zephir_get_strval(key, key_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinteger", NULL, 0, key);
	zephir_check_call_status();
	value = zephir_get_intval(_0);
	value += step;
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setinteger", NULL, 0, key, _1);
	zephir_check_call_status();
	RETURN_MM_LONG(value);

}

PHP_METHOD(Nc_Cache_CacheAbstract, decrementInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long step, value = 0;
	zval *key_param = NULL, *step_param = NULL, *_0 = NULL, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &step_param);

	zephir_get_strval(key, key_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinteger", NULL, 0, key);
	zephir_check_call_status();
	value = zephir_get_intval(_0);
	value -= step;
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setinteger", NULL, 0, key, _1);
	zephir_check_call_status();
	RETURN_MM_LONG(value);

}

PHP_METHOD(Nc_Cache_CacheAbstract, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *key_param = NULL, *value, *lifetime_param = NULL, *_0, *_1 = NULL, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &lifetime_param);

	zephir_get_strval(key, key_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "serialize", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, lifetime);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rawset", NULL, 0, key, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, get) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *r = NULL, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&r, this_ptr, "rawget", NULL, 0, key);
	zephir_check_call_status();
	_0 = Z_TYPE_P(r) != IS_STRING;
	if (!(_0)) {
		_0 = !zephir_is_true(r);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "unserialize", NULL, 0, r);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Cache_CacheAbstract, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rawdelete", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, multiSet) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long expiredAt;
	zval *keyValues_param = NULL, *expiredAt_param = NULL, *k = NULL, *v = NULL, **_2, *_3$$3 = NULL;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyValues_param, &expiredAt_param);

	zephir_get_arrval(keyValues, keyValues_param);
	if (!expiredAt_param) {
		expiredAt = 0;
	} else {
		expiredAt = zephir_get_intval(expiredAt_param);
	}


	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/cache/cacheabstract.zep", 86);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_LONG(_3$$3, expiredAt);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, k, v, _3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, multiGet) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *r = NULL, *k = NULL, *v = NULL, **_2;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(r);
	array_init(r);
	zephir_is_iterable(keys, &_1, &_0, 0, 0, "nc/cache/cacheabstract.zep", 99);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(k, _2);
		ZEPHIR_CALL_METHOD(&v, this_ptr, "get", &_3, 0, k);
		zephir_check_call_status();
		if (Z_TYPE_P(v) != IS_NULL) {
			zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Cache_CacheAbstract, multiDelete) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *k = NULL, **_2;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	zephir_is_iterable(keys, &_1, &_0, 0, 0, "nc/cache/cacheabstract.zep", 109);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(k, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_3, 0, k);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, groupSetAll) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *group_param = NULL, *keyValues_param = NULL, *k = NULL, *v = NULL, *groupedKeys = NULL, *data = NULL, **_2, *_4, *_3$$3 = NULL;
	zval *group = NULL, *realGroup = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group_param, &keyValues_param);

	zephir_get_strval(group, group_param);
	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_INIT_VAR(groupedKeys);
	array_init(groupedKeys);
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_INIT_VAR(realGroup);
	ZEPHIR_CONCAT_SV(realGroup, ":g:", group);
	ZEPHIR_INIT_VAR(prefix);
	ZEPHIR_CONCAT_VS(prefix, realGroup, ":");
	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/cache/cacheabstract.zep", 124);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_array_update_zval(&groupedKeys, k, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VV(_3$$3, prefix, k);
		zephir_array_update_zval(&data, _3$$3, &v, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_zval(&data, realGroup, &groupedKeys, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "multiset", NULL, 0, data, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, groupGetAll) {

	HashTable *_3, *_8;
	HashPosition _2, _7;
	zend_bool _0;
	long prefixLen = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, *groupedKeys = NULL, *ks = NULL, *k = NULL, *v = NULL, *data = NULL, *_1, **_4, *_6 = NULL, **_9, *_5$$4 = NULL, *_10$$5 = NULL, _11$$6 = zval_used_for_init, *_12$$6 = NULL;
	zval *group = NULL, *realGroup = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group_param);

	zephir_get_strval(group, group_param);


	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_INIT_VAR(realGroup);
	ZEPHIR_CONCAT_SV(realGroup, ":g:", group);
	ZEPHIR_CALL_METHOD(&groupedKeys, this_ptr, "get", NULL, 0, realGroup);
	zephir_check_call_status();
	_0 = Z_TYPE_P(groupedKeys) != IS_ARRAY;
	if (!(_0)) {
		_0 = !zephir_is_true(groupedKeys);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(prefix);
	ZEPHIR_CONCAT_VS(prefix, realGroup, ":");
	prefixLen = zephir_fast_strlen_ev(prefix);
	ZEPHIR_INIT_VAR(_1);
	zephir_array_keys(_1, groupedKeys TSRMLS_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "nc/cache/cacheabstract.zep", 148);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(k, _4);
		ZEPHIR_INIT_LNVAR(_5$$4);
		ZEPHIR_CONCAT_VV(_5$$4, prefix, k);
		zephir_array_append(&ks, _5$$4, PH_SEPARATE, "nc/cache/cacheabstract.zep", 145);
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "multiget", NULL, 0, ks);
	zephir_check_call_status();
	zephir_is_iterable(_6, &_8, &_7, 0, 0, "nc/cache/cacheabstract.zep", 154);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(k, _8, _7);
		ZEPHIR_GET_HVALUE(v, _9);
		ZEPHIR_INIT_NVAR(_10$$5);
		zephir_fast_strpos(_10$$5, k, prefix, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(_10$$5, 0)) {
			ZEPHIR_SINIT_NVAR(_11$$6);
			ZVAL_LONG(&_11$$6, prefixLen);
			ZEPHIR_INIT_NVAR(_12$$6);
			zephir_substr(_12$$6, k, zephir_get_intval(&_11$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_array_update_zval(&data, _12$$6, &v, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Nc_Cache_CacheAbstract, groupDeleteAll) {

	HashTable *_3;
	HashPosition _2;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, *groupedKeys = NULL, *k = NULL, *ks = NULL, *_1, **_4, *_5$$4 = NULL;
	zval *group = NULL, *realGroup = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group_param);

	zephir_get_strval(group, group_param);


	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(realGroup);
	ZEPHIR_CONCAT_SV(realGroup, ":g:", group);
	ZEPHIR_CALL_METHOD(&groupedKeys, this_ptr, "get", NULL, 0, realGroup);
	zephir_check_call_status();
	_0 = Z_TYPE_P(groupedKeys) != IS_ARRAY;
	if (!(_0)) {
		_0 = !zephir_is_true(groupedKeys);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(prefix);
	ZEPHIR_CONCAT_VS(prefix, realGroup, ":");
	ZEPHIR_INIT_VAR(_1);
	zephir_array_keys(_1, groupedKeys TSRMLS_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "nc/cache/cacheabstract.zep", 175);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(k, _4);
		ZEPHIR_INIT_LNVAR(_5$$4);
		ZEPHIR_CONCAT_VV(_5$$4, prefix, k);
		zephir_array_append(&ks, _5$$4, PH_SEPARATE, "nc/cache/cacheabstract.zep", 172);
	}
	zephir_array_append(&ks, realGroup, PH_SEPARATE, "nc/cache/cacheabstract.zep", 175);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "multidelete", NULL, 0, ks);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, groupSet) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *group_param = NULL, *keyValues_param = NULL, *groupedKeys = NULL, *k = NULL, *v = NULL, *data = NULL, **_2, *_4, *_3$$4 = NULL;
	zval *group = NULL, *realGroup = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group_param, &keyValues_param);

	zephir_get_strval(group, group_param);
	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_INIT_VAR(realGroup);
	ZEPHIR_CONCAT_SV(realGroup, ":g:", group);
	ZEPHIR_CALL_METHOD(&groupedKeys, this_ptr, "get", NULL, 0, realGroup);
	zephir_check_call_status();
	if (Z_TYPE_P(groupedKeys) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(groupedKeys);
		array_init(groupedKeys);
	}
	ZEPHIR_INIT_VAR(prefix);
	ZEPHIR_CONCAT_VS(prefix, realGroup, ":");
	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/cache/cacheabstract.zep", 198);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_array_update_zval(&groupedKeys, k, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_3$$4);
		ZEPHIR_CONCAT_VV(_3$$4, prefix, k);
		zephir_array_update_zval(&data, _3$$4, &v, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_zval(&data, realGroup, &groupedKeys, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "multiset", NULL, 0, data, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_CacheAbstract, groupGet) {

	HashTable *_3, *_8;
	HashPosition _2, _7;
	zend_bool _0;
	long prefixLen = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL;
	zval *group_param = NULL, *keys_param = NULL, *groupedKeys = NULL, *ks = NULL, *k = NULL, *v = NULL, *data = NULL, *_1 = NULL, **_4, *_6 = NULL, **_9, *_5$$5 = NULL, *_10$$7 = NULL, _11$$8 = zval_used_for_init, *_12$$8 = NULL;
	zval *group = NULL, *realGroup = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group_param, &keys_param);

	zephir_get_strval(group, group_param);
	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_INIT_VAR(realGroup);
	ZEPHIR_CONCAT_SV(realGroup, ":g:", group);
	ZEPHIR_CALL_METHOD(&groupedKeys, this_ptr, "get", NULL, 0, realGroup);
	zephir_check_call_status();
	_0 = Z_TYPE_P(groupedKeys) != IS_ARRAY;
	if (!(_0)) {
		_0 = !zephir_is_true(groupedKeys);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(prefix);
	ZEPHIR_CONCAT_VS(prefix, realGroup, ":");
	prefixLen = zephir_fast_strlen_ev(prefix);
	ZEPHIR_CALL_FUNCTION(&_1, "array_unique", NULL, 1, keys);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "nc/cache/cacheabstract.zep", 224);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(k, _4);
		if (zephir_array_key_exists(groupedKeys, k TSRMLS_CC)) {
			ZEPHIR_INIT_LNVAR(_5$$5);
			ZEPHIR_CONCAT_VV(_5$$5, prefix, k);
			zephir_array_append(&ks, _5$$5, PH_SEPARATE, "nc/cache/cacheabstract.zep", 220);
		}
	}
	if (!(zephir_is_true(ks))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "multiget", NULL, 0, ks);
	zephir_check_call_status();
	zephir_is_iterable(_6, &_8, &_7, 0, 0, "nc/cache/cacheabstract.zep", 234);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(k, _8, _7);
		ZEPHIR_GET_HVALUE(v, _9);
		ZEPHIR_INIT_NVAR(_10$$7);
		zephir_fast_strpos(_10$$7, k, prefix, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(_10$$7, 0)) {
			ZEPHIR_SINIT_NVAR(_11$$8);
			ZVAL_LONG(&_11$$8, prefixLen);
			ZEPHIR_INIT_NVAR(_12$$8);
			zephir_substr(_12$$8, k, zephir_get_intval(&_11$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_array_update_zval(&data, _12$$8, &v, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Nc_Cache_CacheAbstract, groupDelete) {

	HashTable *_3;
	HashPosition _2;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL;
	zval *group_param = NULL, *keys_param = NULL, *groupedKeys = NULL, *k = NULL, *ks = NULL, *_1 = NULL, **_4, *_5$$5 = NULL;
	zval *group = NULL, *realGroup = NULL, *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group_param, &keys_param);

	zephir_get_strval(group, group_param);
	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(realGroup);
	ZEPHIR_CONCAT_SV(realGroup, ":g:", group);
	ZEPHIR_CALL_METHOD(&groupedKeys, this_ptr, "get", NULL, 0, realGroup);
	zephir_check_call_status();
	_0 = Z_TYPE_P(groupedKeys) != IS_ARRAY;
	if (!(_0)) {
		_0 = !zephir_is_true(groupedKeys);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(prefix);
	ZEPHIR_CONCAT_VS(prefix, realGroup, ":");
	ZEPHIR_CALL_FUNCTION(&_1, "array_unique", NULL, 1, keys);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "nc/cache/cacheabstract.zep", 258);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(k, _4);
		if (zephir_array_key_exists(groupedKeys, k TSRMLS_CC)) {
			zephir_array_unset(&groupedKeys, k, PH_SEPARATE);
			ZEPHIR_INIT_LNVAR(_5$$5);
			ZEPHIR_CONCAT_VV(_5$$5, prefix, k);
			zephir_array_append(&ks, _5$$5, PH_SEPARATE, "nc/cache/cacheabstract.zep", 254);
		}
	}
	if (zephir_is_true(ks)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, realGroup, groupedKeys);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "multidelete", NULL, 0, ks);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

