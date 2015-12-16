
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
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Std_GroupedMongoCollections) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, GroupedMongoCollections, nc, std_groupedmongocollections, nc_std_groupedmongocollections_method_entry, 0);

	zend_declare_property_null(nc_std_groupedmongocollections_ce, SL("mongoDb"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_std_groupedmongocollections_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_groupedmongocollections_ce, SL("DEFAULT_PREFIX"), "grouped_" TSRMLS_CC);

	zend_class_implements(nc_std_groupedmongocollections_ce TSRMLS_CC, 1, nc_std_groupedinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, __construct) {

	zval *prefix = NULL;
	zval *mongoDb, *prefix_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &mongoDb, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "grouped_", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	zephir_update_property_this(this_ptr, SL("mongoDb"), mongoDb TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, setGrouped) {

	zval *_1, *_2, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *value, *_0 = NULL;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &identifier_param, &key_param, &value);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "collection", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &key, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("value"), &value, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("$set"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("upsert"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "update", NULL, 0, _1, _2, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, getGrouped) {

	zend_bool _2;
	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *row = NULL, *value = NULL, *_0 = NULL;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &key_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "collection", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &key, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&row, _0, "findone", NULL, 0, _1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(row) == IS_ARRAY;
	if (_2) {
		_2 = zephir_array_isset_string_fetch(&value, row, SS("value"), 1 TSRMLS_CC);
	}
	if (_2) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, deleteGrouped) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *_0 = NULL;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &key_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "collection", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &key, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, setManyGrouped) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *identifier_param = NULL, *keyValues_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keyValues_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keyValues, keyValues_param);


	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "nc/std/groupedmongocollections.zep", 56);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setgrouped", &_3, 0, identifier, k, v);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, getManyGrouped) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL, *_1, *_2;
	zval *identifier_param = NULL, *keys_param = NULL, *rows = NULL, *row = NULL, *a = NULL, *k = NULL, *v = NULL, *_0 = NULL, *_3 = NULL, **_6;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keys_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	if (unlikely(zephir_fast_count_int(keys TSRMLS_CC) < 1)) {
		RETURN_CCTOR(a);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "collection", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("$in"), &keys, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_id"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&rows, _0, "find", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, 124, rows);
	zephir_check_call_status();
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "nc/std/groupedmongocollections.zep", 80);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(row, _6);
		if (zephir_array_isset_string_fetch(&k, row, SS("_id"), 1 TSRMLS_CC)) {
			if (zephir_array_isset_string_fetch(&v, row, SS("value"), 1 TSRMLS_CC)) {
				zephir_array_update_zval(&a, k, &v, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(a);

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, deleteManyGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL, *_1, *_2;
	zval *identifier_param = NULL, *keys_param = NULL, *_0 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keys_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "collection", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("$in"), &keys, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_id"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, setAllGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *identifier_param = NULL, *keyValues_param = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keyValues_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteallgrouped", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmanygrouped", NULL, 0, identifier, keyValues);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, getAllGrouped) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *rows = NULL, *row = NULL, *a = NULL, *k = NULL, *v = NULL, *_0 = NULL, *_1 = NULL, **_4;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "collection", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&rows, _0, "find", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "iterator_to_array", NULL, 124, rows);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "nc/std/groupedmongocollections.zep", 112);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(row, _4);
		if (zephir_array_isset_string_fetch(&k, row, SS("_id"), 1 TSRMLS_CC)) {
			if (zephir_array_isset_string_fetch(&v, row, SS("value"), 1 TSRMLS_CC)) {
				zephir_array_update_zval(&a, k, &v, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(a);

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, deleteAllGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "collection", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "drop", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedMongoCollections, collection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0, *_1, *_2;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoDb"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_RETURN_CALL_METHOD(_0, "selectcollection", NULL, 0, _2);
	zephir_check_call_status();
	RETURN_MM();

}

