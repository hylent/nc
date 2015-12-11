
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
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_Entity) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, Entity, nc, db_entity, nc_db_entity_method_entry, 0);

	zend_declare_property_null(nc_db_entity_ce, SL("model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_entity_ce, SL("row"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_entity_ce, SL("isNew"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_entity_ce, SL("updates"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_entity_ce, SL("collection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Entity, __construct) {

	zend_bool isNew;
	zval *row = NULL;
	zval *model, *row_param = NULL, *isNew_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &row_param, &isNew_param);

	zephir_get_arrval(row, row_param);
	isNew = zephir_get_boolval(isNew_param);


	zephir_update_property_this(this_ptr, SL("model"), model TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("row"), row TSRMLS_CC);
	if (isNew) {
		zephir_update_property_this(this_ptr, SL("isNew"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("isNew"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Entity, getModel) {

	

	RETURN_MEMBER(this_ptr, "model");

}

PHP_METHOD(Nc_Db_Entity, asArray) {

	

	RETURN_MEMBER(this_ptr, "row");

}

PHP_METHOD(Nc_Db_Entity, isNew) {

	

	RETURN_MEMBER(this_ptr, "isNew");

}

PHP_METHOD(Nc_Db_Entity, isDirty) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("updates"), PH_NOISY_CC);
	RETURN_BOOL(zephir_fast_count_int(_0 TSRMLS_CC) > 0);

}

PHP_METHOD(Nc_Db_Entity, setCollection) {

	zval *collection = NULL;

	zephir_fetch_params(0, 0, 1, &collection);

	if (!collection) {
		collection = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("collection"), collection TSRMLS_CC);

}

PHP_METHOD(Nc_Db_Entity, hasCollection) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("collection"), PH_NOISY_CC);
	RETURN_BOOL(Z_TYPE_P(_0) != IS_NULL);

}

PHP_METHOD(Nc_Db_Entity, getCollection) {

	

	RETURN_MEMBER(this_ptr, "collection");

}

PHP_METHOD(Nc_Db_Entity, primaryKeyValue) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("model"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("row"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "pickprimarykeyvalue", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Entity, set) {

	HashTable *_1;
	HashPosition _0;
	zval *updates_param = NULL, *k = NULL, *v = NULL, **_2, *_3$$3;
	zval *updates = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &updates_param);

	zephir_get_arrval(updates, updates_param);


	zephir_is_iterable(updates, &_1, &_0, 0, 0, "nc/db/entity.zep", 70);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_update_property_array(this_ptr, SL("row"), k, v TSRMLS_CC);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("isNew"), PH_NOISY_CC);
		if (!(zephir_is_true(_3$$3))) {
			zephir_update_property_array(this_ptr, SL("updates"), k, v TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Entity, __set) {

	zval *name_param = NULL, *value, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("row"), name, value TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("isNew"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_update_property_array(this_ptr, SL("updates"), name, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Entity, __get) {

	zval *name_param = NULL, *value = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("row"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Entity, save) {

	HashTable *_10;
	HashPosition _9;
	zval *k = NULL, *v = NULL, *row = NULL, *_0, **_11, *_1$$3, *_2$$3, *_3$$4, *_5$$4, *_6$$4, *_7$$4 = NULL, *_8$$4, *_4$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("isNew"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("model"), PH_NOISY_CC);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("row"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&row, _1$$3, "insert", NULL, 0, _2$$3);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_this(this_ptr, SL("isNew"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("isNew"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	} else {
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("updates"), PH_NOISY_CC);
		if (unlikely(zephir_fast_count_int(_3$$4 TSRMLS_CC) < 1)) {
			ZEPHIR_INIT_VAR(_4$$5);
			array_init(_4$$5);
			zephir_update_property_this(this_ptr, SL("updates"), _4$$5 TSRMLS_CC);
		}
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("model"), PH_NOISY_CC);
		_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("updates"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "primarykeyvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&row, _5$$4, "update", NULL, 0, _6$$4, _7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$4);
		array_init(_8$$4);
		zephir_update_property_this(this_ptr, SL("updates"), _8$$4 TSRMLS_CC);
	}
	zephir_is_iterable(row, &_10, &_9, 0, 0, "nc/db/entity.zep", 114);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(k, _10, _9);
		ZEPHIR_GET_HVALUE(v, _11);
		zephir_update_property_array(this_ptr, SL("row"), k, v TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Entity, drop) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("model"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "primarykeyvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

