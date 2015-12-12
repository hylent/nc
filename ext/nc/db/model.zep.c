
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Db_Model) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, Model, nc, db_model, nc_db_model_method_entry, 0);

	zend_declare_property_null(nc_db_model_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_model_ce, SL("table"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_model_ce, SL("primaryKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_model_ce, SL("autoIncrement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Model, __construct) {

	zval *table = NULL, *autoIncrement = NULL;
	zval *db, *table_param = NULL, *primaryKey, *autoIncrement_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &db, &table_param, &primaryKey, &autoIncrement_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(autoIncrement, autoIncrement_param);


	zephir_update_property_this(this_ptr, SL("db"), db TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("table"), table TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("primaryKey"), primaryKey TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("autoIncrement"), autoIncrement TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Model, setDb) {

	zval *db;

	zephir_fetch_params(0, 1, 0, &db);



	zephir_update_property_this(this_ptr, SL("db"), db TSRMLS_CC);

}

PHP_METHOD(Nc_Db_Model, getDb) {

	

	RETURN_MEMBER(this_ptr, "db");

}

PHP_METHOD(Nc_Db_Model, insert) {

	zend_bool _3;
	zval *ai = NULL, *aiValue = NULL, *_1 = NULL, *_7$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *row_param = NULL, *r = NULL, *_0, *_2 = NULL, *_4$$3, *_5$$3 = NULL, *_6$$3, *_8$$4, *_9$$4;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &row_param);

	zephir_get_arrval(row, row_param);


	ZEPHIR_CALL_METHOD(&r, this_ptr, "onstore", NULL, 0, row);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("autoIncrement"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(ai, _1);
	_3 = zephir_fast_strlen_ev(ai) > 0;
	if (_3) {
		_3 = !(zephir_array_isset(r, ai));
	}
	if (_3) {
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5$$3, _4$$3, "insert", NULL, 0, _6$$3, r, ai);
		zephir_check_call_status();
		zephir_get_strval(_7$$3, _5$$3);
		ZEPHIR_CPY_WRT(aiValue, _7$$3);
		zephir_array_update_zval(&r, ai, &aiValue, PH_COPY | PH_SEPARATE);
	} else {
		_8$$4 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _8$$4, "insert", NULL, 0, _9$$4, r);
		zephir_check_call_status();
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Db_Model, update) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *updates_param = NULL, *where_param = NULL, *r = NULL, *_0, *_1$$3, *_2$$3;
	zval *updates = NULL, *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &updates_param, &where_param);

	zephir_get_arrval(updates, updates_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_CALL_METHOD(&r, this_ptr, "onstore", NULL, 0, updates, _0, where);
	zephir_check_call_status();
	if (zephir_fast_count_int(r TSRMLS_CC) > 0) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "update", NULL, 0, _2$$3, r, where);
		zephir_check_call_status();
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Db_Model, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where_param = NULL, *_0, *_1;
	zval *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &where_param);

	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, 0, _1, where);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Model, newEntity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool isNew;
	zval *row_param = NULL, *isNew_param = NULL, *collection = NULL, *entity = NULL, *_0;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &row_param, &isNew_param, &collection);

	if (!row_param) {
		ZEPHIR_INIT_VAR(row);
		array_init(row);
	} else {
		zephir_get_arrval(row, row_param);
	}
	if (!isNew_param) {
		isNew = 1;
	} else {
		isNew = zephir_get_boolval(isNew_param);
	}
	if (!collection) {
		collection = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(entity);
	object_init_ex(entity, nc_db_entity_ce);
	ZEPHIR_INIT_VAR(_0);
	if (isNew) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, entity, "__construct", NULL, 37, this_ptr, row, _0);
	zephir_check_call_status();
	if (zephir_is_true(collection)) {
		ZEPHIR_CALL_METHOD(NULL, entity, "setcollection", NULL, 38, collection);
		zephir_check_call_status();
	}
	RETURN_CCTOR(entity);

}

PHP_METHOD(Nc_Db_Model, create) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *row_param = NULL, *_0 = NULL, *_1;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &row_param);

	zephir_get_arrval(row, row_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "insert", NULL, 0, row);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newentity", NULL, 0, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, first) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where_param = NULL, *orderBy = NULL, *row = NULL, *_0, *_1, *_3 = NULL, *_4 = NULL;
	zval *where = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &where_param, &orderBy);

	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}
	if (!orderBy) {
		orderBy = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("where"), &where, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("orderBy"), &orderBy, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_2, SS("limit"), 1);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 2);
	ZEPHIR_CALL_METHOD(&row, _0, "select", NULL, 0, _1, _2, _3);
	zephir_check_call_status();
	if (!(zephir_is_true(row))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "onfetch", NULL, 0, row);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newentity", NULL, 0, _4, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, id) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "packprimarykeyvalue", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "first", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, newCollection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	object_init_ex(return_value, nc_db_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 39, this_ptr, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, all) {

	int ZEPHIR_LAST_CALL_STATUS;
	long limit, offset;
	zval *where_param = NULL, *orderBy = NULL, *limit_param = NULL, *offset_param = NULL, *_1 = NULL, *_2, *_3 = NULL, *_4, *_6 = NULL;
	zval *where = NULL, *_0, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &where_param, &orderBy, &limit_param, &offset_param);

	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}
	if (!orderBy) {
		orderBy = ZEPHIR_GLOBAL(global_null);
	}
	if (!limit_param) {
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onFetch", 1);
	zephir_array_fast_append(_0, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("where"), &where, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("orderBy"), &orderBy, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, limit);
	zephir_array_update_string(&_5, SL("limit"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, offset);
	zephir_array_update_string(&_5, SL("offset"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, _2, "select", NULL, 0, _4, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "array_map", NULL, 7, _0, _3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newcollection", NULL, 0, _6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, ids) {

	zval *k = NULL, *_3$$3 = NULL, *_5$$4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ids_param = NULL, *_0, *_1$$3, *_2$$3, *_4$$4;
	zval *ids = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ids_param);

	zephir_get_arrval(ids, ids_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("primaryKey"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1$$3);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("primaryKey"), PH_NOISY_CC);
		zephir_fast_join_str(_1$$3, SL(", "), _2$$3 TSRMLS_CC);
		zephir_get_strval(_3$$3, _1$$3);
		ZEPHIR_CPY_WRT(k, _3$$3);
	} else {
		ZEPHIR_OBS_VAR(_4$$4);
		zephir_read_property_this(&_4$$4, this_ptr, SL("primaryKey"), PH_NOISY_CC);
		zephir_get_strval(_5$$4, _4$$4);
		ZEPHIR_CPY_WRT(k, _5$$4);
	}
	zephir_concat_self_str(&k, "$in", sizeof("$in")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, Z_STRVAL_P(k), Z_STRLEN_P(k), &ids, PH_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "all", NULL, 0, _6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, chunkByDynamicWhere) {

	zend_bool _6$$4, _7$$4;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, sum, c = 0;
	zval *where = NULL;
	zval *delegate, *where_param = NULL, *orderBy = NULL, *limit_param = NULL, *collection = NULL, *w = NULL, *_0$$4 = NULL, *_2$$4 = NULL, *_4$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &delegate, &where_param, &orderBy, &limit_param);

	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}
	if (!orderBy) {
		orderBy = ZEPHIR_GLOBAL(global_null);
	}
	if (!limit_param) {
		limit = 5000;
	} else {
		limit = zephir_get_intval(limit_param);
	}


	sum = 0;
	if (unlikely(limit < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid limit", "nc/db/model.zep", 143);
		return;
	}
	ZEPHIR_CPY_WRT(w, where);
	while (1) {
		ZEPHIR_INIT_NVAR(_0$$4);
		ZVAL_LONG(_0$$4, limit);
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "all", &_1, 0, w, orderBy, _0$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$4, collection, "count", &_3, 0);
		zephir_check_call_status();
		c = zephir_get_intval(_2$$4);
		if (c < 1) {
			break;
		}
		sum += c;
		ZEPHIR_CALL_FUNCTION(&_4$$4, "call_user_func", &_5, 17, delegate, collection, w);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(w, _4$$4);
		_6$$4 = Z_TYPE_P(w) != IS_ARRAY;
		if (!(_6$$4)) {
			_6$$4 = zephir_fast_count_int(w TSRMLS_CC) < 1;
		}
		_7$$4 = _6$$4;
		if (!(_7$$4)) {
			_7$$4 = c < limit;
		}
		if (_7$$4) {
			break;
		}
	}
	RETURN_MM_LONG(sum);

}

PHP_METHOD(Nc_Db_Model, chunkByFixedWhere) {

	zend_bool _7$$4;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, sum, c = 0, offset;
	zval *where = NULL;
	zval *delegate, *where_param = NULL, *orderBy = NULL, *limit_param = NULL, *collection = NULL, *_0$$4 = NULL, *_1$$4 = NULL, *_3$$4 = NULL, *_5$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &delegate, &where_param, &orderBy, &limit_param);

	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}
	if (!orderBy) {
		orderBy = ZEPHIR_GLOBAL(global_null);
	}
	if (!limit_param) {
		limit = 5000;
	} else {
		limit = zephir_get_intval(limit_param);
	}


	sum = 0;
	offset = 0;
	if (unlikely(limit < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid limit", "nc/db/model.zep", 172);
		return;
	}
	while (1) {
		ZEPHIR_INIT_NVAR(_0$$4);
		ZVAL_LONG(_0$$4, limit);
		ZEPHIR_INIT_NVAR(_1$$4);
		ZVAL_LONG(_1$$4, offset);
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "all", &_2, 0, where, orderBy, _0$$4, _1$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$4, collection, "count", &_4, 0);
		zephir_check_call_status();
		c = zephir_get_intval(_3$$4);
		if (c < 1) {
			break;
		}
		sum += c;
		ZEPHIR_CALL_FUNCTION(&_5$$4, "call_user_func", &_6, 17, delegate, collection);
		zephir_check_call_status();
		_7$$4 = ZEPHIR_IS_FALSE_IDENTICAL(_5$$4);
		if (!(_7$$4)) {
			_7$$4 = c < limit;
		}
		if (_7$$4) {
			break;
		}
		offset += limit;
	}
	RETURN_MM_LONG(sum);

}

PHP_METHOD(Nc_Db_Model, aggregations) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations_param = NULL, *where_param = NULL, *_0, *_1;
	zval *aggregations = NULL, *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aggregations_param, &where_param);

	zephir_get_arrval(aggregations, aggregations_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "aggregations", NULL, 0, _1, aggregations, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, countAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where_param = NULL, *_0;
	zval *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &where_param);

	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "*", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "count", NULL, 0, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *column_param = NULL, *where_param = NULL, *_0, *_1;
	zval *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &column_param, &where_param);

	if (!column_param) {
		ZEPHIR_INIT_VAR(column);
		ZVAL_STRING(column, "*", 1);
	} else {
		zephir_get_strval(column, column_param);
	}
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "count", NULL, 0, _1, column, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, max) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *column_param = NULL, *where_param = NULL, *_0, *_1;
	zval *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &column_param, &where_param);

	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "max", NULL, 0, _1, column, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, min) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *column_param = NULL, *where_param = NULL, *_0, *_1;
	zval *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &column_param, &where_param);

	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "min", NULL, 0, _1, column, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, sum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *column_param = NULL, *where_param = NULL, *_0, *_1;
	zval *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &column_param, &where_param);

	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "sum", NULL, 0, _1, column, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, avg) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *column_param = NULL, *where_param = NULL, *_0, *_1;
	zval *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &column_param, &where_param);

	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "avg", NULL, 0, _1, column, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, onStore) {

	zend_bool isUpdate;
	zval *row_param = NULL, *isUpdate_param = NULL, *where_param = NULL;
	zval *row = NULL, *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &row_param, &isUpdate_param, &where_param);

	zephir_get_arrval(row, row_param);
	if (!isUpdate_param) {
		isUpdate = 0;
	} else {
		isUpdate = zephir_get_boolval(isUpdate_param);
	}
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	RETURN_CTOR(row);

}

PHP_METHOD(Nc_Db_Model, onFetch) {

	zval *row_param = NULL;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &row_param);

	zephir_get_arrval(row, row_param);


	RETURN_CTOR(row);

}

PHP_METHOD(Nc_Db_Model, pickPrimaryKeyValue) {

	zval *_6$$7 = NULL;
	HashTable *_1$$4;
	HashPosition _0$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *row_param = NULL, *pk = NULL, *k = NULL, *v = NULL, *a = NULL, **_2$$4, *_3$$6 = NULL, *_4$$6 = NULL, *_7$$8, *_8$$8;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &row_param);

	zephir_get_arrval(row, row_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	ZEPHIR_OBS_VAR(pk);
	zephir_read_property_this(&pk, this_ptr, SL("primaryKey"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(pk))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Empty primary key", "nc/db/model.zep", 245);
		return;
	}
	if (Z_TYPE_P(pk) == IS_ARRAY) {
		zephir_is_iterable(pk, &_1$$4, &_0$$4, 0, 0, "nc/db/model.zep", 255);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$4, &_0$$4)
		) {
			ZEPHIR_GET_HVALUE(k, _2$$4);
			ZEPHIR_OBS_NVAR(v);
			if (unlikely(!(zephir_array_isset_fetch(&v, row, k, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_NVAR(_3$$6);
				object_init_ex(_3$$6, nc_db_exception_ce);
				ZEPHIR_INIT_LNVAR(_4$$6);
				ZEPHIR_CONCAT_SV(_4$$6, "Cannot pick primary key values: ", k);
				ZEPHIR_CALL_METHOD(NULL, _3$$6, "__construct", &_5, 2, _4$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3$$6, "nc/db/model.zep", 251 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&a, k, &v, PH_COPY | PH_SEPARATE);
		}
	} else {
		zephir_get_strval(_6$$7, pk);
		ZEPHIR_CPY_WRT(k, _6$$7);
		ZEPHIR_OBS_NVAR(v);
		if (unlikely(!(zephir_array_isset_fetch(&v, row, k, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_VAR(_7$$8);
			object_init_ex(_7$$8, nc_db_exception_ce);
			ZEPHIR_INIT_VAR(_8$$8);
			ZEPHIR_CONCAT_SV(_8$$8, "Cannot pick primary key value: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$8, "__construct", &_5, 2, _8$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$8, "nc/db/model.zep", 258 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&a, k, &v, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(a);

}

PHP_METHOD(Nc_Db_Model, packPrimaryKeyValue) {

	zend_bool _0$$4;
	zval *_1 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *pk = NULL, *a = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_OBS_VAR(pk);
	zephir_read_property_this(&pk, this_ptr, SL("primaryKey"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(pk))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Empty primary key", "nc/db/model.zep", 273);
		return;
	}
	if (Z_TYPE_P(pk) == IS_ARRAY) {
		_0$$4 = Z_TYPE_P(id) != IS_ARRAY;
		if (!(_0$$4)) {
			_0$$4 = zephir_fast_count_int(id TSRMLS_CC) != zephir_fast_count_int(pk TSRMLS_CC);
		}
		if (unlikely(_0$$4)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid id to pack", "nc/db/model.zep", 278);
			return;
		}
		ZEPHIR_RETURN_CALL_FUNCTION("array_combine", NULL, 40, pk, id);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(a);
	array_init(a);
	zephir_get_strval(_1, id);
	zephir_get_strval(_2, pk);
	zephir_array_update_zval(&a, _2, &_1, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(a);

}

