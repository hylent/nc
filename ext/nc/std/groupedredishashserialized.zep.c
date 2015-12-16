
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Std_GroupedRedisHashSerialized) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Std, GroupedRedisHashSerialized, nc, std_groupedredishashserialized, nc_std_groupedredishash_ce, nc_std_groupedredishashserialized_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, serializeValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 125, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, unserializeValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 126, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, setGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *identifier_param = NULL, *key_param = NULL, *value, *_1 = NULL;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &identifier_param, &key_param, &value);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "serializevalue", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, nc_std_groupedredishashserialized_ce, this_ptr, "setgrouped", &_0, 127, identifier, key, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, getGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *identifier_param = NULL, *key_param = NULL, *value = NULL;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &key_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_PARENT(&value, nc_std_groupedredishashserialized_ce, this_ptr, "getgrouped", &_0, 128, identifier, key);
	zephir_check_call_status();
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "unserializevalue", NULL, 0, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, setManyGrouped) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *identifier_param = NULL, *keyValues_param = NULL, *k = NULL, *v = NULL, *data = NULL, **_2, *_3$$3 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keyValues_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/std/groupedredishashserialized.zep", 40);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "serializevalue", &_4, 0, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, nc_std_groupedredishashserialized_ce, this_ptr, "setmanygrouped", &_5, 129, identifier, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, getManyGrouped) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *keys = NULL;
	zval *identifier_param = NULL, *keys_param = NULL, *a = NULL, *k = NULL, *v = NULL, *data = NULL, **_3, *_4$$3 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keys_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_PARENT(&a, nc_std_groupedredishashserialized_ce, this_ptr, "getmanygrouped", &_0, 130, identifier, keys);
	zephir_check_call_status();
	zephir_is_iterable(a, &_2, &_1, 0, 0, "nc/std/groupedredishashserialized.zep", 52);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "unserializevalue", &_5, 0, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_4$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, setAllGrouped) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *identifier_param = NULL, *keyValues_param = NULL, *k = NULL, *v = NULL, *data = NULL, **_2, *_3$$3 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keyValues_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/std/groupedredishashserialized.zep", 63);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "serializevalue", &_4, 0, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, nc_std_groupedredishashserialized_ce, this_ptr, "setallgrouped", &_5, 131, identifier, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedRedisHashSerialized, getAllGrouped) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *identifier_param = NULL, *a = NULL, *k = NULL, *v = NULL, *data = NULL, **_3, *_4$$3 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_PARENT(&a, nc_std_groupedredishashserialized_ce, this_ptr, "getallgrouped", &_0, 132, identifier);
	zephir_check_call_status();
	zephir_is_iterable(a, &_2, &_1, 0, 0, "nc/std/groupedredishashserialized.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "unserializevalue", &_5, 0, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_4$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

