
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
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Db_Model) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, Model, nc, db_model, nc_db_model_method_entry, 0);

	zend_declare_property_null(nc_db_model_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_model_ce, SL("table"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_model_ce, SL("primaryKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_model_ce, SL("autoIncrement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_model_ce, SL("columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Model, __construct) {

	zval *primaryKey = NULL;
	zval *table = NULL, *autoIncrement = NULL;
	zval *db, *table_param = NULL, *primaryKey_param = NULL, *autoIncrement_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &db, &table_param, &primaryKey_param, &autoIncrement_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(primaryKey, primaryKey_param);
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
	ZEPHIR_CALL_METHOD(&r, this_ptr, "onstore", NULL, 0, updates, _0);
	zephir_check_call_status();
	if (zephir_fast_count_int(r TSRMLS_CC) > 0) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "update", NULL, 0, _2$$3, r, where);
		zephir_check_call_status();
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Db_Model, upsert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *row_param = NULL, *r = NULL, *_0, *_1, *_2;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &row_param);

	zephir_get_arrval(row, row_param);


	ZEPHIR_CALL_METHOD(&r, this_ptr, "onstore", NULL, 0, row);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("primaryKey"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "upsert", NULL, 0, _1, r, _2);
	zephir_check_call_status();
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Db_Model, newEntity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *row = NULL;
	zval *isNew_param = NULL, *row_param = NULL, *collection = NULL, *_0;
	zend_bool isNew;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &isNew_param, &row_param, &collection);

	isNew = zephir_get_boolval(isNew_param);
	if (!row_param) {
		ZEPHIR_INIT_VAR(row);
		array_init(row);
	} else {
		zephir_get_arrval(row, row_param);
	}
	if (!collection) {
		collection = ZEPHIR_GLOBAL(global_null);
	}


	object_init_ex(return_value, nc_db_entity_ce);
	ZEPHIR_INIT_VAR(_0);
	if (isNew) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 38, this_ptr, _0, row, collection);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, entity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *newRow_param = NULL, *_0;
	zval *newRow = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &newRow_param);

	if (!newRow_param) {
		ZEPHIR_INIT_VAR(newRow);
		array_init(newRow);
	} else {
		zephir_get_arrval(newRow, newRow_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newentity", NULL, 0, _0, newRow);
	zephir_check_call_status();
	RETURN_MM();

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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newentity", NULL, 0, _1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, first) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool forUpdate;
	zval *where_param = NULL, *orderBy = NULL, *forUpdate_param = NULL, *row = NULL, *_0, *_1, *_3 = NULL, *_4 = NULL;
	zval *where = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &where_param, &orderBy, &forUpdate_param);

	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}
	if (!orderBy) {
		orderBy = ZEPHIR_GLOBAL(global_null);
	}
	if (!forUpdate_param) {
		forUpdate = 0;
	} else {
		forUpdate = zephir_get_boolval(forUpdate_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("where"), &where, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("orderBy"), &orderBy, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_2, SS("limit"), 1);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, forUpdate);
	zephir_array_update_string(&_2, SL("forUpdate"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&row, _0, "selectrow", NULL, 0, _1, _2);
	zephir_check_call_status();
	if (!(zephir_is_true(row))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "onfetch", NULL, 0, row);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newentity", NULL, 0, _3, _4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, id) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool forUpdate;
	zval *id, *forUpdate_param = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &id, &forUpdate_param);

	if (!forUpdate_param) {
		forUpdate = 0;
	} else {
		forUpdate = zephir_get_boolval(forUpdate_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "packprimarykeyvalue", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_INIT_VAR(_2);
	if (forUpdate) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "first", NULL, 0, _0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, newCollection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *properties_param = NULL;
	zval *data = NULL, *properties = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &properties_param);

	zephir_get_arrval(data, data_param);
	if (!properties_param) {
		ZEPHIR_INIT_VAR(properties);
		array_init(properties);
	} else {
		zephir_get_arrval(properties, properties_param);
	}


	object_init_ex(return_value, nc_db_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 39, this_ptr, data, properties);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL;
	zval *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onFetch", 1);
	zephir_array_fast_append(_0, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "select", NULL, 0, _4, options);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "array_map", NULL, 6, _0, _3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newcollection", NULL, 0, _5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, all) {

	int ZEPHIR_LAST_CALL_STATUS;
	long limit, skip;
	zval *where_param = NULL, *orderBy = NULL, *limit_param = NULL, *skip_param = NULL, *_1 = NULL;
	zval *where = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &where_param, &orderBy, &limit_param, &skip_param);

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
	if (!skip_param) {
		skip = 0;
	} else {
		skip = zephir_get_intval(skip_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("where"), &where, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("orderBy"), &orderBy, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, limit);
	zephir_array_update_string(&_0, SL("limit"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, skip);
	zephir_array_update_string(&_0, SL("skip"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "find", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, ids) {

	zval *k = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ids_param = NULL, *_0, *_1, *_2;
	zval *ids = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ids_param);

	zephir_get_arrval(ids, ids_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("primaryKey"), PH_NOISY_CC);
	zephir_fast_join_str(_0, SL(", "), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "$in");
	zephir_get_strval(k, _2);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, Z_STRVAL_P(k), Z_STRLEN_P(k), &ids, PH_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "all", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, paged) {

	zend_bool _8;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, page, skip = 0, numRows = 0, numPages = 0;
	zval *where_param = NULL, *orderBy = NULL, *limit_param = NULL, *page_param = NULL, *nd = NULL, *data = NULL, *_0, *_1, *_3 = NULL, *_4 = NULL, *_6 = NULL, *_10$$6, *_11$$6 = NULL;
	zval *where = NULL, *_2, *_7 = NULL, *_12, *_9$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &where_param, &orderBy, &limit_param, &page_param);

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
		limit = 10;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!page_param) {
		page = 1;
	} else {
		page = zephir_get_intval(page_param);
	}


	if (limit < 1) {
		limit = 1;
	}
	if (page < 1) {
		page = 1;
	}
	skip = (limit * ((page - 1)));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("where"), &where, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("orderBy"), &orderBy, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, limit);
	zephir_array_update_string(&_2, SL("limit"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, skip);
	zephir_array_update_string(&_2, SL("skip"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&nd, _0, "countandselect", NULL, 0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(nd);
	ZEPHIR_CALL_FUNCTION(&_4, "array_shift", &_5, 5, nd);
	ZEPHIR_UNREF(nd);
	zephir_check_call_status();
	numRows = zephir_get_intval(_4);
	ZEPHIR_MAKE_REF(nd);
	ZEPHIR_CALL_FUNCTION(&_6, "array_shift", &_5, 5, nd);
	ZEPHIR_UNREF(nd);
	zephir_check_call_status();
	zephir_get_arrval(_7, _6);
	ZEPHIR_CPY_WRT(data, _7);
	_8 = numRows < 1;
	if (!(_8)) {
		_8 = zephir_fast_count_int(data TSRMLS_CC) < 1;
	}
	if (_8) {
		numRows = 0;
		numPages = 0;
		ZEPHIR_INIT_NVAR(data);
		array_init(data);
	} else {
		numPages = (1 + (long) (zephir_safe_div_long_long(((numRows - 1)), limit TSRMLS_CC)));
		ZEPHIR_INIT_VAR(_9$$6);
		zephir_create_array(_9$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_9$$6, this_ptr);
		ZEPHIR_INIT_VAR(_10$$6);
		ZVAL_STRING(_10$$6, "onFetch", 1);
		zephir_array_fast_append(_9$$6, _10$$6);
		ZEPHIR_CALL_FUNCTION(&_11$$6, "array_map", NULL, 6, _9$$6, data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(data, _11$$6);
	}
	ZEPHIR_INIT_VAR(_12);
	zephir_create_array(_12, 6, 0 TSRMLS_CC);
	zephir_array_update_string(&_12, SL("paged"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, limit);
	zephir_array_update_string(&_12, SL("limit"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, page);
	zephir_array_update_string(&_12, SL("page"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, skip);
	zephir_array_update_string(&_12, SL("skip"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, numRows);
	zephir_array_update_string(&_12, SL("numRows"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, numPages);
	zephir_array_update_string(&_12, SL("numPages"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newcollection", NULL, 0, data, _12);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, chunkByDynamicWhere) {

	zend_bool _10$$4, _11$$4;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, sum, c = 0;
	zval *where = NULL;
	zval *delegate, *where_param = NULL, *orderBy = NULL, *limit_param = NULL, *collection = NULL, *w = NULL, *_0$$3, _1$$3, *_2$$3 = NULL, *_3$$3, *_4$$4 = NULL, *_6$$4 = NULL, *_8$$4 = NULL;

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
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, nc_db_modelexception_ce);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, limit);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strval", NULL, 22, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid limit: ", _2$$3);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "nc/db/model.zep", 197 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(w, where);
	while (1) {
		ZEPHIR_INIT_NVAR(_4$$4);
		ZVAL_LONG(_4$$4, limit);
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "all", &_5, 0, w, orderBy, _4$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$4, collection, "count", &_7, 0);
		zephir_check_call_status();
		c = zephir_get_intval(_6$$4);
		if (c < 1) {
			break;
		}
		sum += c;
		ZEPHIR_CALL_FUNCTION(&_8$$4, "call_user_func", &_9, 15, delegate, collection, w);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(w, _8$$4);
		_10$$4 = Z_TYPE_P(w) != IS_ARRAY;
		if (!(_10$$4)) {
			_10$$4 = zephir_fast_count_int(w TSRMLS_CC) < 1;
		}
		_11$$4 = _10$$4;
		if (!(_11$$4)) {
			_11$$4 = c < limit;
		}
		if (_11$$4) {
			break;
		}
	}
	RETURN_MM_LONG(sum);

}

PHP_METHOD(Nc_Db_Model, chunkByFixedWhere) {

	zend_bool _11$$4;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, sum, c = 0, skip;
	zval *where = NULL;
	zval *delegate, *where_param = NULL, *orderBy = NULL, *limit_param = NULL, *collection = NULL, *_0$$3, _1$$3, *_2$$3 = NULL, *_3$$3, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$4 = NULL, *_9$$4 = NULL;

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
	skip = 0;
	if (unlikely(limit < 1)) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, nc_db_modelexception_ce);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, limit);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strval", NULL, 22, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid limit: ", _2$$3);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "nc/db/model.zep", 226 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		ZEPHIR_INIT_NVAR(_4$$4);
		ZVAL_LONG(_4$$4, limit);
		ZEPHIR_INIT_NVAR(_5$$4);
		ZVAL_LONG(_5$$4, skip);
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "all", &_6, 0, where, orderBy, _4$$4, _5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$4, collection, "count", &_8, 0);
		zephir_check_call_status();
		c = zephir_get_intval(_7$$4);
		if (c < 1) {
			break;
		}
		sum += c;
		ZEPHIR_CALL_FUNCTION(&_9$$4, "call_user_func", &_10, 15, delegate, collection);
		zephir_check_call_status();
		_11$$4 = ZEPHIR_IS_FALSE_IDENTICAL(_9$$4);
		if (!(_11$$4)) {
			_11$$4 = c < limit;
		}
		if (_11$$4) {
			break;
		}
		skip += limit;
	}
	RETURN_MM_LONG(sum);

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

PHP_METHOD(Nc_Db_Model, aggregation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *aggregationFunction_param = NULL, *column_param = NULL, *where_param = NULL, *_0, *_1;
	zval *aggregationFunction = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &aggregationFunction_param, &column_param, &where_param);

	zephir_get_strval(aggregationFunction, aggregationFunction_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "aggregation", NULL, 0, _1, aggregationFunction, column, where);
	zephir_check_call_status();
	RETURN_MM();

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

PHP_METHOD(Nc_Db_Model, groupAggregations) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations = NULL, *options = NULL;
	zval *groupBy_param = NULL, *aggregations_param = NULL, *options_param = NULL, *_0, *_1;
	zval *groupBy = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &groupBy_param, &aggregations_param, &options_param);

	zephir_get_strval(groupBy, groupBy_param);
	zephir_get_arrval(aggregations, aggregations_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "groupaggregations", NULL, 0, _1, groupBy, aggregations, options);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Model, onStore) {

	zval *_7$$10 = NULL, *_8$$11 = NULL, *_22$$4 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL, *_31 = NULL;
	zend_bool isUpdate, _9$$12, _13$$4, _16$$4, _19$$4, _25$$4, _32$$4, _35$$4, _26$$17, _27$$17;
	zval *row_param = NULL, *isUpdate_param = NULL, *k = NULL, *v = NULL, *c = NULL, *i = NULL, *r = NULL, *_0, *_1, **_4, *_5$$10 = NULL, *_10$$13 = NULL, *_11$$13 = NULL, *_20$$4 = NULL, *_21$$4 = NULL, *_14$$14 = NULL, *_15$$14 = NULL, *_17$$15 = NULL, *_18$$15 = NULL, *_23$$16 = NULL, *_24$$16 = NULL, _28$$17 = zval_used_for_init, _29$$17 = zval_used_for_init, _30$$17 = zval_used_for_init, *_33$$19 = NULL, *_34$$19 = NULL, *_36$$20 = NULL, *_37$$20 = NULL;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &row_param, &isUpdate_param);

	zephir_get_arrval(row, row_param);
	if (!isUpdate_param) {
		isUpdate = 0;
	} else {
		isUpdate = zephir_get_boolval(isUpdate_param);
	}


	ZEPHIR_INIT_VAR(r);
	array_init(r);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("columns"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_ARRAY) {
		RETURN_CTOR(row);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("columns"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "nc/db/model.zep", 360);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(k, _3, _2);
		ZEPHIR_GET_HVALUE(c, _4);
		if (Z_TYPE_P(c) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(c);
			ZVAL_NULL(c);
		}
		ZEPHIR_OBS_NVAR(v);
		if (!(zephir_array_isset_fetch(&v, row, k, 0 TSRMLS_CC))) {
			if (isUpdate) {
				continue;
			}
			ZEPHIR_OBS_NVAR(i);
			if (zephir_array_isset_string_fetch(&i, c, SS("default"), 0 TSRMLS_CC)) {
				ZEPHIR_CPY_WRT(v, i);
			} else {
				ZEPHIR_INIT_NVAR(v);
				ZVAL_NULL(v);
			}
		}
		ZEPHIR_OBS_NVAR(i);
		ZEPHIR_INIT_NVAR(v);
		if (zephir_array_isset_string_fetch(&i, c, SS("setter"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_5$$10, "call_user_func", &_6, 15, i, v, this_ptr);
			zephir_check_call_status();
			zephir_get_strval(_7$$10, _5$$10);
			ZEPHIR_CPY_WRT(v, _7$$10);
		} else {
			zephir_get_strval(_8$$11, v);
			ZEPHIR_CPY_WRT(v, _8$$11);
		}
		if (ZEPHIR_IS_STRING_IDENTICAL(v, "")) {
			ZEPHIR_OBS_NVAR(i);
			_9$$12 = !(zephir_array_isset_string_fetch(&i, c, SS("nullable"), 0 TSRMLS_CC));
			if (!(_9$$12)) {
				_9$$12 = !zephir_is_true(i);
			}
			if (unlikely(_9$$12)) {
				ZEPHIR_INIT_NVAR(_10$$13);
				object_init_ex(_10$$13, nc_db_modelexception_ce);
				ZEPHIR_INIT_LNVAR(_11$$13);
				ZEPHIR_CONCAT_SV(_11$$13, "Failed when checking nullable on column: ", k);
				ZEPHIR_CALL_METHOD(NULL, _10$$13, "__construct", &_12, 2, _11$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_10$$13, "nc/db/model.zep", 324 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&r, k, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
			continue;
		}
		ZEPHIR_OBS_NVAR(i);
		_13$$4 = zephir_array_isset_string_fetch(&i, c, SS("minlen"), 0 TSRMLS_CC);
		if (_13$$4) {
			_13$$4 = ZEPHIR_GT_LONG(i, zephir_fast_strlen_ev(v));
		}
		if (_13$$4) {
			ZEPHIR_INIT_NVAR(_14$$14);
			object_init_ex(_14$$14, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_15$$14);
			ZEPHIR_CONCAT_SV(_15$$14, "Failed when checking minlen on column: ", k);
			ZEPHIR_CALL_METHOD(NULL, _14$$14, "__construct", &_12, 2, _15$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(_14$$14, "nc/db/model.zep", 331 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(i);
		_16$$4 = zephir_array_isset_string_fetch(&i, c, SS("maxlen"), 0 TSRMLS_CC);
		if (_16$$4) {
			_16$$4 = ZEPHIR_LT_LONG(i, zephir_fast_strlen_ev(v));
		}
		if (_16$$4) {
			ZEPHIR_INIT_NVAR(_17$$15);
			object_init_ex(_17$$15, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_18$$15);
			ZEPHIR_CONCAT_SV(_18$$15, "Failed when checking maxlen on column: ", k);
			ZEPHIR_CALL_METHOD(NULL, _17$$15, "__construct", &_12, 2, _18$$15);
			zephir_check_call_status();
			zephir_throw_exception_debug(_17$$15, "nc/db/model.zep", 335 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(i);
		_19$$4 = zephir_array_isset_string_fetch(&i, c, SS("regexp"), 0 TSRMLS_CC);
		if (_19$$4) {
			ZEPHIR_INIT_NVAR(_20$$4);
			ZEPHIR_INIT_NVAR(_21$$4);
			zephir_get_strval(_22$$4, i);
			zephir_preg_match(_21$$4, _22$$4, v, _20$$4, 0, 0 , 0  TSRMLS_CC);
			_19$$4 = !zephir_is_true(_21$$4);
		}
		if (_19$$4) {
			ZEPHIR_INIT_NVAR(_23$$16);
			object_init_ex(_23$$16, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_24$$16);
			ZEPHIR_CONCAT_SV(_24$$16, "Failed when checking regexp on column: ", k);
			ZEPHIR_CALL_METHOD(NULL, _23$$16, "__construct", &_12, 2, _24$$16);
			zephir_check_call_status();
			zephir_throw_exception_debug(_23$$16, "nc/db/model.zep", 339 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(i);
		_25$$4 = zephir_array_isset_string_fetch(&i, c, SS("numeric"), 0 TSRMLS_CC);
		if (_25$$4) {
			_25$$4 = zephir_is_true(i);
		}
		if (_25$$4) {
			ZEPHIR_OBS_NVAR(i);
			_26$$17 = !(zephir_array_isset_string_fetch(&i, c, SS("decimals"), 0 TSRMLS_CC));
			if (!(_26$$17)) {
				_26$$17 = Z_TYPE_P(i) != IS_LONG;
			}
			_27$$17 = _26$$17;
			if (!(_27$$17)) {
				_27$$17 = ZEPHIR_LT_LONG(i, 0);
			}
			if (_27$$17) {
				ZEPHIR_INIT_NVAR(i);
				ZVAL_LONG(i, 0);
			}
			ZEPHIR_SINIT_NVAR(_28$$17);
			ZVAL_DOUBLE(&_28$$17, zephir_get_doubleval(v));
			ZEPHIR_SINIT_NVAR(_29$$17);
			ZVAL_STRING(&_29$$17, ".", 0);
			ZEPHIR_SINIT_NVAR(_30$$17);
			ZVAL_STRING(&_30$$17, "", 0);
			ZEPHIR_CALL_FUNCTION(&v, "number_format", &_31, 40, &_28$$17, i, &_29$$17, &_30$$17);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(i);
		_32$$4 = zephir_array_isset_string_fetch(&i, c, SS("min"), 0 TSRMLS_CC);
		if (_32$$4) {
			_32$$4 = ZEPHIR_LT(v, i);
		}
		if (_32$$4) {
			ZEPHIR_INIT_NVAR(_33$$19);
			object_init_ex(_33$$19, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_34$$19);
			ZEPHIR_CONCAT_SV(_34$$19, "Failed when checking min on column: ", k);
			ZEPHIR_CALL_METHOD(NULL, _33$$19, "__construct", &_12, 2, _34$$19);
			zephir_check_call_status();
			zephir_throw_exception_debug(_33$$19, "nc/db/model.zep", 350 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(i);
		_35$$4 = zephir_array_isset_string_fetch(&i, c, SS("max"), 0 TSRMLS_CC);
		if (_35$$4) {
			_35$$4 = ZEPHIR_GT(v, i);
		}
		if (_35$$4) {
			ZEPHIR_INIT_NVAR(_36$$20);
			object_init_ex(_36$$20, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_37$$20);
			ZEPHIR_CONCAT_SV(_37$$20, "Failed when checking max on column: ", k);
			ZEPHIR_CALL_METHOD(NULL, _36$$20, "__construct", &_12, 2, _37$$20);
			zephir_check_call_status();
			zephir_throw_exception_debug(_36$$20, "nc/db/model.zep", 354 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Db_Model, onFetch) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *row_param = NULL, *k = NULL, *v = NULL, *getter = NULL, *r = NULL, **_2, *_3$$3, *_4$$3, *_5$$4 = NULL;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &row_param);

	zephir_get_arrval(row, row_param);


	ZEPHIR_INIT_VAR(r);
	array_init(r);
	zephir_is_iterable(row, &_1, &_0, 0, 0, "nc/db/model.zep", 375);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_OBS_NVAR(getter);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("columns"), PH_NOISY_CC);
		zephir_array_fetch(&_4$$3, _3$$3, k, PH_READONLY, "nc/db/model.zep", 368 TSRMLS_CC);
		if (zephir_array_isset_string_fetch(&getter, _4$$3, SS("getter"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_5$$4, "call_user_func", &_6, 15, getter, v, this_ptr);
			zephir_check_call_status();
			zephir_array_update_zval(&r, k, &_5$$4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Db_Model, pickPrimaryKeyValue) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *row_param = NULL, *k = NULL, *v = NULL, *a = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL;
	zval *row = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &row_param);

	zephir_get_arrval(row, row_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("primaryKey"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/model.zep", 389);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		ZEPHIR_OBS_NVAR(v);
		if (unlikely(!(zephir_array_isset_fetch(&v, row, k, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, nc_db_modelexception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Cannot pick primary key values: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "nc/db/model.zep", 384 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&a, k, &v, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(a);

}

PHP_METHOD(Nc_Db_Model, packPrimaryKeyValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);

	ZEPHIR_SEPARATE_PARAM(id);


	if (Z_TYPE_P(id) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(id);
		zephir_create_array(id, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(id, id);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("primaryKey"), PH_NOISY_CC);
	if (unlikely(zephir_fast_count_int(_0 TSRMLS_CC) != zephir_fast_count_int(id TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_modelexception_ce, "Invalid id to pack", "nc/db/model.zep", 399);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("primaryKey"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_combine", NULL, 41, _1, id);
	zephir_check_call_status();
	RETURN_MM();

}

