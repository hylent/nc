
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Std_GroupedRedisHash) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, GroupedRedisHash, nc, std_groupedredishash, nc_std_groupedredishash_method_entry, 0);

	zend_declare_property_null(nc_std_groupedredishash_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_std_groupedredishash_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_groupedredishash_ce, SL("DEFAULT_PREFIX"), "groupedhash:" TSRMLS_CC);

	zend_class_implements(nc_std_groupedredishash_ce TSRMLS_CC, 1, nc_std_groupedinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_GroupedRedisHash, __construct) {

	zval *prefix = NULL;
	zval *redis, *prefix_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "groupedhash:", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHash, setGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *value, *_0, *_1, *_2;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &identifier_param, &key_param, &value);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_CALL_METHOD(NULL, _0, "hset", NULL, 0, _2, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHash, getGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *value = NULL, *_0, *_1, *_2;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &key_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_CALL_METHOD(&value, _0, "hget", NULL, 0, _2, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(value);

}

PHP_METHOD(Nc_Std_GroupedRedisHash, deleteGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *_0, *_1, *_2;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &key_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_CALL_METHOD(NULL, _0, "hdel", NULL, 0, _2, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHash, setManyGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *identifier_param = NULL, *keyValues_param = NULL, *_0, *_1, *_2;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keyValues_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keyValues, keyValues_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_CALL_METHOD(NULL, _0, "hmset", NULL, 0, _2, keyValues);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHash, getManyGrouped) {

	zend_bool _6$$5;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL;
	zval *identifier_param = NULL, *keys_param = NULL, *a = NULL, *k = NULL, *v = NULL, *r = NULL, *_0, *_1, *_2, **_5;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keys_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(r);
	array_init(r);
	if (unlikely(zephir_fast_count_int(keys TSRMLS_CC) < 1)) {
		RETURN_CCTOR(r);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_CALL_METHOD(&a, _0, "hmget", NULL, 0, _2, keys);
	zephir_check_call_status();
	if (unlikely(Z_TYPE_P(a) != IS_ARRAY)) {
		RETURN_CCTOR(r);
	}
	zephir_is_iterable(keys, &_4, &_3, 0, 0, "nc/std/groupedredishash.zep", 62);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(k, _5);
		_6$$5 = zephir_array_isset_fetch(&v, a, k, 1 TSRMLS_CC);
		if (_6$$5) {
			_6$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(v);
		}
		if (_6$$5) {
			zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Std_GroupedRedisHash, deleteManyGrouped) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL;
	zval *identifier_param = NULL, *keys_param = NULL, *k = NULL, *_0, *_1, **_4, *_5$$3;
	zval *identifier = NULL, *hashName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keys_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keys, keys_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, identifier);
	zephir_get_strval(hashName, _1);
	zephir_is_iterable(keys, &_3, &_2, 0, 0, "nc/std/groupedredishash.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(k, _4);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "hdel", NULL, 0, hashName, k);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHash, setAllGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *identifier_param = NULL, *keyValues_param = NULL, *_0, *_1, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	zval *identifier = NULL, *hashName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keyValues_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keyValues, keyValues_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, identifier);
	zephir_get_strval(hashName, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "multi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _3, "delete", NULL, 0, hashName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, _4, "hmset", NULL, 0, hashName, keyValues);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _5, "exec", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHash, getAllGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *a = NULL, *_0, *_1, *_2;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_CALL_METHOD(&a, _0, "hgetall", NULL, 0, _2);
	zephir_check_call_status();
	if (Z_TYPE_P(a) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CCTOR(a);

}

PHP_METHOD(Nc_Std_GroupedRedisHash, deleteAllGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0, *_1, *_2;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

