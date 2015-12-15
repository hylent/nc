
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Db_Collection) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, Collection, nc, db_collection, nc_db_collection_method_entry, 0);

	zend_declare_property_null(nc_db_collection_ce, SL("model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_collection_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_collection_ce, SL("properties"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_db_collection_ce, SL("internalIndex"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_collection_ce, SL("indexes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_db_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(nc_db_collection_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Nc_Db_Collection, __construct) {

	zval *data = NULL, *properties = NULL;
	zval *model, *data_param = NULL, *properties_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &model, &data_param, &properties_param);

	zephir_get_arrval(data, data_param);
	if (!properties_param) {
		ZEPHIR_INIT_VAR(properties);
		array_init(properties);
	} else {
		zephir_get_arrval(properties, properties_param);
	}


	zephir_update_property_this(this_ptr, SL("model"), model TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("properties"), properties TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, (zephir_fast_count_int(data TSRMLS_CC) - 1));
	zephir_update_property_this(this_ptr, SL("internalIndex"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Collection, getModel) {

	

	RETURN_MEMBER(this_ptr, "model");

}

PHP_METHOD(Nc_Db_Collection, __get) {

	zval *name_param = NULL, *prop = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("properties"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&prop, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(prop);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Collection, at) {

	zval *_6$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool asArray;
	zval *index_param = NULL, *asArray_param = NULL, *row = NULL, *_0$$3, *_1$$5, *_4$$5, _5$$5, *_2$$6, *_3$$6;
	long index;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &index_param, &asArray_param);

	index = zephir_get_intval(index_param);
	if (!asArray_param) {
		asArray = 0;
	} else {
		asArray = zephir_get_boolval(asArray_param);
	}


	if (asArray) {
		ZEPHIR_OBS_VAR(row);
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (zephir_array_isset_long_fetch(&row, _0$$3, index, 0 TSRMLS_CC)) {
			RETURN_CCTOR(row);
		}
	} else {
		ZEPHIR_OBS_NVAR(row);
		_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (zephir_array_isset_long_fetch(&row, _1$$5, index, 0 TSRMLS_CC)) {
			_2$$6 = zephir_fetch_nproperty_this(this_ptr, SL("model"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_3$$6);
			ZVAL_BOOL(_3$$6, 0);
			ZEPHIR_RETURN_CALL_METHOD(_2$$6, "newentity", NULL, 0, _3$$6, row, this_ptr);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_4$$5);
		object_init_ex(_4$$5, nc_db_modelexception_ce);
		ZEPHIR_SINIT_VAR(_5$$5);
		ZVAL_LONG(&_5$$5, index);
		ZEPHIR_INIT_VAR(_6$$5);
		ZEPHIR_CONCAT_SV(_6$$5, "Cannot find entity at: ", &_5$$5);
		ZEPHIR_CALL_METHOD(NULL, _4$$5, "__construct", NULL, 2, _6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$5, "nc/db/collection.zep", 45 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Collection, id) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool asArray;
	zval *id, *asArray_param = NULL, *k = NULL, *v = NULL, *indexes = NULL, *_0, *_8, *_9 = NULL, *_10, *_11, *_1$$3, **_4$$3, *_5$$4 = NULL, *_6$$4, *_7$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &id, &asArray_param);

	if (!asArray_param) {
		asArray = 0;
	} else {
		asArray = zephir_get_boolval(asArray_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("indexes"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(indexes);
		array_init(indexes);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "nc/db/collection.zep", 58);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(k, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(v, _4$$3);
			ZEPHIR_INIT_NVAR(_5$$4);
			_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("model"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_7$$4, _6$$4, "pickprimarykeyvalue", NULL, 0, v);
			zephir_check_call_status();
			zephir_fast_join_str(_5$$4, SL(":"), _7$$4 TSRMLS_CC);
			zephir_array_update_zval(&indexes, _5$$4, &k, PH_COPY | PH_SEPARATE);
		}
		zephir_update_property_this(this_ptr, SL("indexes"), indexes TSRMLS_CC);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("model"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_9, _8, "packprimarykeyvalue", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(k);
	zephir_fast_join_str(k, SL(":"), _9 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(v);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("indexes"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset_fetch(&v, _10, k, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_NVAR(v);
		ZVAL_LONG(v, -1);
	}
	ZEPHIR_INIT_VAR(_11);
	if (asArray) {
		ZVAL_BOOL(_11, 1);
	} else {
		ZVAL_BOOL(_11, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "at", NULL, 0, v, _11);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Collection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

PHP_METHOD(Nc_Db_Collection, rewind) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("internalIndex"), _0 TSRMLS_CC);

}

PHP_METHOD(Nc_Db_Collection, valid) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("internalIndex"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, _1));

}

PHP_METHOD(Nc_Db_Collection, current) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *asArray_param = NULL, *_0, *_1;
	zend_bool asArray;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &asArray_param);

	if (!asArray_param) {
		asArray = 0;
	} else {
		asArray = zephir_get_boolval(asArray_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("internalIndex"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (asArray) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "at", NULL, 0, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Collection, key) {

	

	RETURN_MEMBER(this_ptr, "internalIndex");

}

PHP_METHOD(Nc_Db_Collection, next) {

	

	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("internalIndex") TSRMLS_CC));

}

PHP_METHOD(Nc_Db_Collection, data) {

	

	RETURN_MEMBER(this_ptr, "data");

}

PHP_METHOD(Nc_Db_Collection, indexedData) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *indexKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *indexValue = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$5 = NULL, *_8$$5 = NULL;
	zval *indexKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &indexKey_param);

	zephir_get_strval(indexKey, indexKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/collection.zep", 119);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Invalid item type, array required: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "nc/db/collection.zep", 110 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_8$$5);
			ZEPHIR_CONCAT_SV(_8$$5, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_6, 2, _8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "nc/db/collection.zep", 113 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&arr, indexValue, &v, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Db_Collection, groupedData) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *groupValue = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$5 = NULL, *_8$$5 = NULL;
	zval *groupKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &groupKey_param);

	zephir_get_strval(groupKey, groupKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/collection.zep", 137);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "nc/db/collection.zep", 128 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_8$$5);
			ZEPHIR_CONCAT_SV(_8$$5, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_6, 2, _8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "nc/db/collection.zep", 131 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &v TSRMLS_CC, SL("za"), 2, groupValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Db_Collection, groupIndexedData) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupKey_param = NULL, *indexKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *groupValue = NULL, *indexValue = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$6 = NULL, *_10$$6 = NULL;
	zval *groupKey = NULL, *indexKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &groupKey_param, &indexKey_param);

	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(indexKey, indexKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/collection.zep", 158);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "nc/db/collection.zep", 146 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_8$$5);
			ZEPHIR_CONCAT_SV(_8$$5, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_6, 2, _8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "nc/db/collection.zep", 149 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_9$$6);
			object_init_ex(_9$$6, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_10$$6);
			ZEPHIR_CONCAT_SV(_10$$6, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _9$$6, "__construct", &_6, 2, _10$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$6, "nc/db/collection.zep", 152 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &v TSRMLS_CC, SL("zz"), 2, groupValue, indexValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Db_Collection, values) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *valueKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *valueValue = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$5 = NULL, *_8$$5 = NULL;
	zval *valueKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &valueKey_param);

	zephir_get_strval(valueKey, valueKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/collection.zep", 176);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "nc/db/collection.zep", 167 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_8$$5);
			ZEPHIR_CONCAT_SV(_8$$5, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_6, 2, _8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "nc/db/collection.zep", 170 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&arr, valueValue, PH_SEPARATE, "nc/db/collection.zep", 173);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Db_Collection, uniqueValues) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *valueKey_param = NULL, *_0 = NULL;
	zval *valueKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &valueKey_param);

	zephir_get_strval(valueKey, valueKey_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "values", NULL, 0, valueKey);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_unique", NULL, 36, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Collection, indexedValues) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *indexKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *indexValue = NULL, *valueValue = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$6 = NULL, *_10$$6 = NULL;
	zval *indexKey = NULL, *valueKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &indexKey_param, &valueKey_param);

	zephir_get_strval(indexKey, indexKey_param);
	zephir_get_strval(valueKey, valueKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/collection.zep", 202);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "nc/db/collection.zep", 190 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_8$$5);
			ZEPHIR_CONCAT_SV(_8$$5, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_6, 2, _8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "nc/db/collection.zep", 193 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_9$$6);
			object_init_ex(_9$$6, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_10$$6);
			ZEPHIR_CONCAT_SV(_10$$6, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _9$$6, "__construct", &_6, 2, _10$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$6, "nc/db/collection.zep", 196 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&arr, indexValue, &valueValue, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Db_Collection, groupedValues) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *groupValue = NULL, *valueValue = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$6 = NULL, *_10$$6 = NULL;
	zval *groupKey = NULL, *valueKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &groupKey_param, &valueKey_param);

	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(valueKey, valueKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/collection.zep", 223);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "nc/db/collection.zep", 211 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_8$$5);
			ZEPHIR_CONCAT_SV(_8$$5, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_6, 2, _8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "nc/db/collection.zep", 214 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_9$$6);
			object_init_ex(_9$$6, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_10$$6);
			ZEPHIR_CONCAT_SV(_10$$6, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _9$$6, "__construct", &_6, 2, _10$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$6, "nc/db/collection.zep", 217 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &valueValue TSRMLS_CC, SL("za"), 2, groupValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Db_Collection, groupIndexedValues) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupKey_param = NULL, *indexKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *groupValue = NULL, *indexValue = NULL, *valueValue = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$6 = NULL, *_10$$6 = NULL, *_11$$7 = NULL, *_12$$7 = NULL;
	zval *groupKey = NULL, *indexKey = NULL, *valueKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &groupKey_param, &indexKey_param, &valueKey_param);

	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(indexKey, indexKey_param);
	zephir_get_strval(valueKey, valueKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/collection.zep", 247);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "nc/db/collection.zep", 232 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_7$$5);
			object_init_ex(_7$$5, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_8$$5);
			ZEPHIR_CONCAT_SV(_8$$5, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", &_6, 2, _8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$5, "nc/db/collection.zep", 235 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_9$$6);
			object_init_ex(_9$$6, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_10$$6);
			ZEPHIR_CONCAT_SV(_10$$6, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _9$$6, "__construct", &_6, 2, _10$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$6, "nc/db/collection.zep", 238 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_11$$7);
			object_init_ex(_11$$7, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_12$$7);
			ZEPHIR_CONCAT_SV(_12$$7, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _11$$7, "__construct", &_6, 2, _12$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_11$$7, "nc/db/collection.zep", 241 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &valueValue TSRMLS_CC, SL("zz"), 2, groupValue, indexValue);
	}
	RETURN_CCTOR(arr);

}

