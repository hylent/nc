
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Db_Query_DbQueryAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db\\Query, DbQueryAbstract, nc, db_query_dbqueryabstract, nc_db_query_dbqueryabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("table"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("tableAlias"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("where"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("join"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("field"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("groupBy"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("having"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("orderBy"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("pageSize"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("rowOffset"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("numRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("numPages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("updates"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_query_dbqueryabstract_ce, SL("updateParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table = NULL, *tableAlias = NULL;
	zval *db, *table_param = NULL, *tableAlias_param = NULL, *a = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &db, &table_param, &tableAlias_param);

	zephir_get_strval(table, table_param);
	if (!tableAlias_param) {
		ZEPHIR_INIT_VAR(tableAlias);
		ZVAL_STRING(tableAlias, "", 1);
	} else {
		zephir_get_strval(tableAlias, tableAlias_param);
	}


	if (!(zephir_instance_of_ev(db, nc_db_dbinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'db' must be an instance of 'Nc\\Db\\DbInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("db"), db TSRMLS_CC);
	if (zephir_fast_strlen_ev(tableAlias) > 0) {
		zephir_update_property_this(this_ptr, SL("table"), table TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("tableAlias"), tableAlias TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&a, this_ptr, "parsetablealias", NULL, table);
		zephir_check_call_status();
		zephir_array_fetch_long(&_1, a, 0, PH_NOISY | PH_READONLY, "nc/db/query/dbqueryabstract.zep", 37 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("table"), _1 TSRMLS_CC);
		zephir_array_fetch_long(&_2, a, 1, PH_NOISY | PH_READONLY, "nc/db/query/dbqueryabstract.zep", 38 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("tableAlias"), _2 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getDb) {


	RETURN_MEMBER(this_ptr, "db");

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getTable) {


	RETURN_MEMBER(this_ptr, "table");

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getTableAlias) {


	RETURN_MEMBER(this_ptr, "tableAlias");

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, duplicate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *_0 = NULL, *_2, *_3, *_4;
	zval *queryClass = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(queryClass);
	zephir_get_class(queryClass, this_ptr, 0 TSRMLS_CC);
	zephir_fetch_safe_class(_0, queryClass);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("tableAlias"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _2, _3, _4);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clear) {


	zephir_update_property_this(this_ptr, SL("where"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("join"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("field"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("groupBy"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("having"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("orderBy"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("page"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("pageSize"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("rowOffset"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("numRows"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("numPages"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("updates"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("updateParams"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sql = NULL;
	zval *forUpdate_param = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL;
	zend_bool forUpdate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &forUpdate_param);

	if (!forUpdate_param) {
		forUpdate = 0;
	} else {
		forUpdate = zephir_get_boolval(forUpdate_param);
	}


	if (forUpdate) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildwhere", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVVS(_2, "select * from ", _0, _1, " for update");
		zephir_get_strval(sql, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, (2 | 0x20));
		ZEPHIR_RETURN_CALL_METHOD(_3, "query", NULL, _4, sql);
		zephir_check_call_status();
		RETURN_MM();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildwhere", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_2);
	ZEPHIR_CONCAT_SVV(_2, "select * from ", _0, _1);
	zephir_get_strval(sql, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, (1 | 0x20));
	ZEPHIR_RETURN_CALL_METHOD(_3, "query", NULL, _4, sql);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, findMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sql = NULL;
	zval *forUpdate_param = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL;
	zend_bool forUpdate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &forUpdate_param);

	if (!forUpdate_param) {
		forUpdate = 0;
	} else {
		forUpdate = zephir_get_boolval(forUpdate_param);
	}


	if (forUpdate) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildwhere", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVVS(_2, "select * from ", _0, _1, " for update");
		zephir_get_strval(sql, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, (2 | 0x10));
		ZEPHIR_RETURN_CALL_METHOD(_3, "query", NULL, _4, sql);
		zephir_check_call_status();
		RETURN_MM();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildwhere", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_2);
	ZEPHIR_CONCAT_SVV(_2, "select * from ", _0, _1);
	zephir_get_strval(sql, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, (1 | 0x10));
	ZEPHIR_RETURN_CALL_METHOD(_3, "query", NULL, _4, sql);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2, *_3, *_4;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildwhere", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVV(_2, "delete from ", _0, _1);
	zephir_get_strval(sql, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 2);
	ZEPHIR_RETURN_CALL_METHOD(_3, "query", NULL, _4, sql);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, insert) {

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, expression) {

	zval *field_param = NULL, *expression_param = NULL;
	zval *field = NULL, *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &expression_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(expression, expression_param);


	zephir_update_property_array(this_ptr, SL("updates"), field, expression TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, increment) {

	zval *field_param = NULL, *deta = NULL;
	zval *field = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &deta);

	zephir_get_strval(field, field_param);
	if (!deta) {
		ZEPHIR_INIT_VAR(deta);
		ZVAL_LONG(deta, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VSVS(_0, field, " + (:", field, ")");
	zephir_update_property_array(this_ptr, SL("updates"), field, _0 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("updateParams"), field, deta TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, decrement) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *deta = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &deta);

	zephir_get_strval(field, field_param);
	if (!deta) {
		ZEPHIR_INIT_VAR(deta);
		ZVAL_LONG(deta, 1);
	}


	zephir_negate(deta TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "increment", NULL, field, deta);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, concat) {

	zend_bool prepend;
	zval *field_param = NULL, *value_param = NULL, *prepend_param = NULL;
	zval *field = NULL, *value = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &value_param, &prepend_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	if (prepend) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSV(_0, ":", field, " || ", field);
		zephir_update_property_array(this_ptr, SL("updates"), field, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_VSV(_0, field, " || :", field);
		zephir_update_property_array(this_ptr, SL("updates"), field, _0 TSRMLS_CC);
	}
	zephir_update_property_array(this_ptr, SL("updateParams"), field, value TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearUpdates) {


	zephir_update_property_this(this_ptr, SL("updates"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("updateParams"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, update) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3, *_8, *_11;
	HashPosition _2, _7, _10;
	zval *sql = NULL;
	zval *data_param = NULL, *k = NULL, *v = NULL, *kvs, *params, *_0, *_1, **_4, *_5 = NULL, *_6, **_9, **_12, *_13, *_14 = NULL, *_15;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}
	ZEPHIR_INIT_VAR(kvs);
	array_init(kvs);
	ZEPHIR_INIT_VAR(params);
	array_init(params);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("updates"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("updates"), PH_NOISY_CC);
		zephir_is_iterable(_1, &_3, &_2, 0, 0, "nc/db/query/dbqueryabstract.zep", 168);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(k, _3, _2);
			ZEPHIR_GET_HVALUE(v, _4);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_VSV(_5, k, " = ", v);
			zephir_array_update_zval(&kvs, k, &_5, PH_COPY | PH_SEPARATE);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("updateParams"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("updateParams"), PH_NOISY_CC);
		zephir_is_iterable(_6, &_8, &_7, 0, 0, "nc/db/query/dbqueryabstract.zep", 174);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HMKEY(k, _8, _7);
			ZEPHIR_GET_HVALUE(v, _9);
			zephir_array_update_zval(&params, k, &v, PH_COPY | PH_SEPARATE);
		}
	}
	if (zephir_fast_count_int(data TSRMLS_CC) > 0) {
		zephir_is_iterable(data, &_11, &_10, 0, 0, "nc/db/query/dbqueryabstract.zep", 181);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HMKEY(k, _11, _10);
			ZEPHIR_GET_HVALUE(v, _12);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_VSV(_5, k, " = :", k);
			zephir_array_update_zval(&kvs, k, &_5, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&params, k, &v, PH_COPY | PH_SEPARATE);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_13);
	zephir_fast_join_str(_13, SL(", "), kvs TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "buildwhere", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_5);
	ZEPHIR_CONCAT_SVSVV(_5, "update ", _1, " set ", _13, _14);
	zephir_get_strval(sql, _5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_LONG(_15, 2);
	ZEPHIR_RETURN_CALL_METHOD(_6, "query", NULL, _15, sql, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, replace) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *primaryKey = NULL, *k = NULL, *v = NULL, *pks = NULL, *q = NULL, *c = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &primaryKey);

	zephir_get_arrval(data, data_param);
	if (!primaryKey) {
		ZEPHIR_INIT_VAR(primaryKey);
		ZVAL_STRING(primaryKey, "id", 1);
	}
	ZEPHIR_INIT_VAR(pks);
	array_init(pks);


	if (Z_TYPE_P(primaryKey) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(pks, primaryKey);
	} else {
		ZEPHIR_INIT_NVAR(pks);
		array_init_size(pks, 2);
		zephir_array_fast_append(pks, primaryKey);
	}
	if (unlikely(!zephir_is_true(pks))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_query_exception_ce, "Cannot replace when primary key is empty", "nc/db/query/dbqueryabstract.zep", 198);
		return;
	}
	ZEPHIR_CALL_METHOD(&q, this_ptr, "duplicate", NULL);
	zephir_check_call_status();
	zephir_is_iterable(pks, &_1, &_0, 0, 0, "nc/db/query/dbqueryabstract.zep", 210);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(k, _2);
		ZEPHIR_OBS_NVAR(v);
		if (unlikely(!(zephir_array_isset_fetch(&v, data, k, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_db_query_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot replace when missing value in data: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/db/query/dbqueryabstract.zep", 205 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, q, "eq", &_6, k, v);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&c, q, "count", NULL);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_GT_LONG(c, 1))) {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, nc_db_query_exception_ce);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Cannot replace when primary key is not provided properly, records found: ", c);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "nc/db/query/dbqueryabstract.zep", 213 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_LT_LONG(c, 1)) {
		ZEPHIR_RETURN_CALL_METHOD(q, "insert", NULL, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(q, "update", NULL, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, aggregate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregateFunction_param = NULL, *field_param = NULL, *_0, *_1 = NULL, *_2, *_3, *_4;
	zval *aggregateFunction = NULL, *field = NULL, *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &aggregateFunction_param, &field_param);

	zephir_get_strval(aggregateFunction, aggregateFunction_param);
	zephir_get_strval(field, field_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildwhere", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSVSVV(_2, "select ", aggregateFunction, "(", field, ") from ", _0, _1);
	zephir_get_strval(sql, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, (1 | 0x30));
	ZEPHIR_RETURN_CALL_METHOD(_3, "query", NULL, _4, sql);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0 = NULL, *_1;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &field_param);

	if (!field_param) {
		ZEPHIR_INIT_VAR(field);
		ZVAL_STRING(field, "*", 1);
	} else {
		zephir_get_strval(field, field_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "count", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "aggregate", NULL, _1, field);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, sum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "sum", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregate", NULL, _0, field);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, max) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "max", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregate", NULL, _0, field);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, min) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "min", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregate", NULL, _0, field);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupAggregate) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregateFunction_param = NULL, *groupField_param = NULL, *aggregateField_param = NULL, *a = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	zval *aggregateFunction = NULL, *groupField = NULL, *aggregateField = NULL, *gaf = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &aggregateFunction_param, &groupField_param, &aggregateField_param);

	zephir_get_strval(aggregateFunction, aggregateFunction_param);
	zephir_get_strval(groupField, groupField_param);
	zephir_get_strval(aggregateField, aggregateField_param);


	ZEPHIR_INIT_VAR(gaf);
	ZEPHIR_CONCAT_SV(gaf, "nc_gaf_", aggregateFunction);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "duplicate", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSVSVSV(_2, groupField, ", ", aggregateFunction, "(", aggregateField, ") as ", gaf);
	ZEPHIR_CALL_METHOD(&_1, _0, "field", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, _1, "groupby", NULL, groupField);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getwhere", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _3, "where", NULL, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&a, _4, "select", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(nc_std_ce, "indexedvalues", &_6, a, groupField, gaf);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupCount) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupField_param = NULL, *aggregateField_param = NULL, *_0;
	zval *groupField = NULL, *aggregateField = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &groupField_param, &aggregateField_param);

	zephir_get_strval(groupField, groupField_param);
	if (!aggregateField_param) {
		ZEPHIR_INIT_VAR(aggregateField);
		ZVAL_STRING(aggregateField, "*", 1);
	} else {
		zephir_get_strval(aggregateField, aggregateField_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "count", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "groupaggregate", NULL, _0, groupField, aggregateField);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupSum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupField_param = NULL, *aggregateField_param = NULL, *_0;
	zval *groupField = NULL, *aggregateField = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &groupField_param, &aggregateField_param);

	zephir_get_strval(groupField, groupField_param);
	zephir_get_strval(aggregateField, aggregateField_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "sum", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "groupaggregate", NULL, _0, groupField, aggregateField);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupMax) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupField_param = NULL, *aggregateField_param = NULL, *_0;
	zval *groupField = NULL, *aggregateField = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &groupField_param, &aggregateField_param);

	zephir_get_strval(groupField, groupField_param);
	zephir_get_strval(aggregateField, aggregateField_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "max", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "groupaggregate", NULL, _0, groupField, aggregateField);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupMin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupField_param = NULL, *aggregateField_param = NULL, *_0;
	zval *groupField = NULL, *aggregateField = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &groupField_param, &aggregateField_param);

	zephir_get_strval(groupField, groupField_param);
	zephir_get_strval(aggregateField, aggregateField_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "min", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "groupaggregate", NULL, _0, groupField, aggregateField);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getSelectAsString) {

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, select) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getselectasstring", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, (1 | 0x10));
	ZEPHIR_RETURN_CALL_METHOD(_0, "query", NULL, _2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, selectRow) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getselectasstring", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, (1 | 0x20));
	ZEPHIR_RETURN_CALL_METHOD(_0, "query", NULL, _2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, selectOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getselectasstring", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, (1 | 0x30));
	ZEPHIR_RETURN_CALL_METHOD(_0, "query", NULL, _2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, selectColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getselectasstring", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, (1 | 0x40));
	ZEPHIR_RETURN_CALL_METHOD(_0, "query", NULL, _2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, selectAndCount) {

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, join) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *on_param = NULL, *type_param = NULL, *a = NULL, *_0, *_1, *_2;
	zval *table = NULL, *on = NULL, *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &table_param, &on_param, &type_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(on, on_param);
	zephir_get_strval(type, type_param);


	ZEPHIR_CALL_METHOD(&a, this_ptr, "parsetablealias", NULL, table);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, a, 0, PH_NOISY | PH_READONLY, "nc/db/query/dbqueryabstract.zep", 315 TSRMLS_CC);
	zephir_array_fetch_long(&_1, a, 1, PH_NOISY | PH_READONLY, "nc/db/query/dbqueryabstract.zep", 315 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSVSVSV(_2, " ", type, " join ", _0, " ", _1, " on ", on);
	zephir_update_property_this(this_ptr, SL("join"), _2 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, innerJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *on_param = NULL, *_0;
	zval *table = NULL, *on = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &table_param, &on_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(on, on_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "inner", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, table, on, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, leftJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *on_param = NULL, *_0;
	zval *table = NULL, *on = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &table_param, &on_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(on, on_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "left", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, table, on, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearJoin) {


	zephir_update_property_this(this_ptr, SL("join"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, field) {

	zend_bool overwrite, _0;
	zval *field_param = NULL, *overwrite_param = NULL, *_1;
	zval *field = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &overwrite_param);

	zephir_get_strval(field, field_param);
	if (!overwrite_param) {
		overwrite = 0;
	} else {
		overwrite = zephir_get_boolval(overwrite_param);
	}


	_0 = !overwrite;
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("field"), PH_NOISY_CC);
		_0 = zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, ", ", field);
		zephir_update_property_this(this_ptr, SL("field"), _2 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("field"), field TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearField) {


	zephir_update_property_this(this_ptr, SL("field"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, where) {

	zval *_1;
	zval *where_param = NULL, *_0 = NULL, *_2;
	zval *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &where_param);

	zephir_get_strval(where, where_param);


	if (zephir_fast_strlen_ev(where) > 0) {
		ZEPHIR_INIT_VAR(_1);
		array_init_size(_1, 2);
		zephir_array_fast_append(_1, where);
		zephir_update_property_this(this_ptr, SL("where"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		zephir_update_property_this(this_ptr, SL("where"), _2 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, raw) {

	zval *raw_param = NULL;
	zval *raw = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &raw_param);

	zephir_get_strval(raw, raw_param);


	zephir_update_property_array_append(this_ptr, SL("where"), raw TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, eq) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value_param = NULL, *_0, *_1 = NULL, *_2;
	zval *field = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "quote", NULL, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, field, " = ", _1);
	zephir_update_property_array_append(this_ptr, SL("where"), _2 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, neq) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value_param = NULL, *_0, *_1 = NULL, *_2;
	zval *field = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "quote", NULL, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, field, " <> ", _1);
	zephir_update_property_array_append(this_ptr, SL("where"), _2 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, gt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value_param = NULL, *_0, *_1 = NULL, *_2;
	zval *field = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "quote", NULL, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, field, " > ", _1);
	zephir_update_property_array_append(this_ptr, SL("where"), _2 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, gte) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value_param = NULL, *_0, *_1 = NULL, *_2;
	zval *field = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "quote", NULL, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, field, " >= ", _1);
	zephir_update_property_array_append(this_ptr, SL("where"), _2 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, lt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value_param = NULL, *_0, *_1 = NULL, *_2;
	zval *field = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "quote", NULL, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, field, " < ", _1);
	zephir_update_property_array_append(this_ptr, SL("where"), _2 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, lte) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *value_param = NULL, *_0, *_1 = NULL, *_2;
	zval *field = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field_param, &value_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "quote", NULL, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSV(_2, field, " <= ", _1);
	zephir_update_property_array_append(this_ptr, SL("where"), _2 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, between) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *v1_param = NULL, *v2_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4;
	zval *field = NULL, *v1 = NULL, *v2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &field_param, &v1_param, &v2_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(v1, v1_param);
	zephir_get_strval(v2, v2_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "quote", NULL, v1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "quote", NULL, v2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VSVSV(_4, field, " between ", _1, " and ", _3);
	zephir_update_property_array_append(this_ptr, SL("where"), _4 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, in) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_4, *_8, *_16;
	HashPosition _0, _3, _7, _15;
	long len;
	zend_bool notIn, _6;
	zval *value = NULL;
	zval *field, *value_param = NULL, *notIn_param = NULL, *ks, *vs, *vvs = NULL, *i = NULL, *ii = NULL, **_2, **_5, **_9, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, **_17;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field, &value_param, &notIn_param);

	zephir_get_arrval(value, value_param);
	if (!notIn_param) {
		notIn = 0;
	} else {
		notIn = zephir_get_boolval(notIn_param);
	}


	ZEPHIR_INIT_VAR(vs);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		len = zephir_fast_count_int(field TSRMLS_CC);
		if (unlikely(len < 2)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_query_exception_ce, "Invalid multi-in item", "nc/db/query/dbqueryabstract.zep", 420);
			return;
		}
		ZEPHIR_INIT_VAR(ks);
		array_init(ks);
		zephir_is_iterable(field, &_1, &_0, 0, 0, "nc/db/query/dbqueryabstract.zep", 426);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(i, _2);
			zephir_array_append(&ks, i, PH_SEPARATE, "nc/db/query/dbqueryabstract.zep", 424);
		}
		array_init(vs);
		zephir_is_iterable(value, &_4, &_3, 0, 0, "nc/db/query/dbqueryabstract.zep", 437);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(i, _5);
			_6 = Z_TYPE_P(i) != IS_ARRAY;
			if (!(_6)) {
				_6 = zephir_fast_count_int(i TSRMLS_CC) != len;
			}
			if (_6) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_query_exception_ce, "Invalid multi-in item value", "nc/db/query/dbqueryabstract.zep", 429);
				return;
			}
			ZEPHIR_INIT_NVAR(vvs);
			array_init(vvs);
			zephir_is_iterable(i, &_8, &_7, 0, 0, "nc/db/query/dbqueryabstract.zep", 435);
			for (
			  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
			  ; zephir_hash_move_forward_ex(_8, &_7)
			) {
				ZEPHIR_GET_HVALUE(ii, _9);
				_10 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&_11, _10, "quote", NULL, ii);
				zephir_check_call_status();
				zephir_array_append(&vvs, _11, PH_SEPARATE, "nc/db/query/dbqueryabstract.zep", 433);
			}
			ZEPHIR_INIT_NVAR(_12);
			zephir_fast_join_str(_12, SL(", "), vvs TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_SVS(_13, "(", _12, ")");
			zephir_array_append(&vs, _13, PH_SEPARATE, "nc/db/query/dbqueryabstract.zep", 435);
		}
		if (notIn) {
			ZEPHIR_INIT_NVAR(_12);
			zephir_fast_join_str(_12, SL(", "), ks TSRMLS_CC);
			ZEPHIR_INIT_VAR(_14);
			zephir_fast_join_str(_14, SL(", "), vs TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_SVSVS(_13, "(", _12, ") not in (", _14, ")");
			zephir_update_property_array_append(this_ptr, SL("where"), _13 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_12);
			zephir_fast_join_str(_12, SL(", "), ks TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_14);
			zephir_fast_join_str(_14, SL(", "), vs TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_SVSVS(_13, "(", _12, ") in (", _14, ")");
			zephir_update_property_array_append(this_ptr, SL("where"), _13 TSRMLS_CC);
		}
	} else {
		array_init(vs);
		zephir_is_iterable(value, &_16, &_15, 0, 0, "nc/db/query/dbqueryabstract.zep", 447);
		for (
		  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
		  ; zephir_hash_move_forward_ex(_16, &_15)
		) {
			ZEPHIR_GET_HVALUE(i, _17);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_11, _10, "quote", NULL, i);
			zephir_check_call_status();
			zephir_array_append(&vs, _11, PH_SEPARATE, "nc/db/query/dbqueryabstract.zep", 445);
		}
		if (notIn) {
			ZEPHIR_INIT_NVAR(_12);
			zephir_fast_join_str(_12, SL(", "), vs TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VSVS(_13, field, " not in (", _12, ")");
			zephir_update_property_array_append(this_ptr, SL("where"), _13 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_12);
			zephir_fast_join_str(_12, SL(", "), vs TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_VSVS(_13, field, " in (", _12, ")");
			zephir_update_property_array_append(this_ptr, SL("where"), _13 TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, notIn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL;
	zval *field, *value_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &value_param);

	zephir_get_arrval(value, value_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "in", NULL, field, value, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, inSelect) {

	zend_bool notInSelect;
	zval *select = NULL, *f = NULL, *_2 = NULL, *_3 = NULL;
	zval *field, *select_param = NULL, *notInSelect_param = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field, &select_param, &notInSelect_param);

	zephir_get_strval(select, select_param);
	if (!notInSelect_param) {
		notInSelect = 0;
	} else {
		notInSelect = zephir_get_boolval(notInSelect_param);
	}


	if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_join_str(_0, SL(", "), field TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "(", _0, ")");
		zephir_get_strval(f, _1);
	} else {
		zephir_get_strval(_2, field);
		ZEPHIR_CPY_WRT(f, _2);
	}
	if (notInSelect) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VSVS(_3, f, " not in (", select, ")");
		zephir_update_property_array_append(this_ptr, SL("where"), _3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSVS(_3, f, " in (", select, ")");
		zephir_update_property_array_append(this_ptr, SL("where"), _3 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, notInSelect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *select = NULL;
	zval *field, *select_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &field, &select_param);

	zephir_get_strval(select, select_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "inselect", NULL, field, select, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, like) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool half, notLike;
	zval *field_param = NULL, *value_param = NULL, *half_param = NULL, *notLike_param = NULL, *_1, *_2 = NULL, *_3 = NULL;
	zval *field = NULL, *value = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &field_param, &value_param, &half_param, &notLike_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);
	if (!half_param) {
		half = 0;
	} else {
		half = zephir_get_boolval(half_param);
	}
	if (!notLike_param) {
		notLike = 0;
	} else {
		notLike = zephir_get_boolval(notLike_param);
	}


	if (half) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, value, "%");
		ZEPHIR_CPY_WRT(value, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "%", value, "%");
		ZEPHIR_CPY_WRT(value, _0);
	}
	if (notLike) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "quote", NULL, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VSV(_3, field, " not like ", _2);
		zephir_update_property_array_append(this_ptr, SL("where"), _3 TSRMLS_CC);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "quote", NULL, value);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSV(_3, field, " like ", _2);
		zephir_update_property_array_append(this_ptr, SL("where"), _3 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, notLike) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool half;
	zval *field_param = NULL, *value_param = NULL, *half_param = NULL, *_0;
	zval *field = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &value_param, &half_param);

	zephir_get_strval(field, field_param);
	zephir_get_strval(value, value_param);
	if (!half_param) {
		half = 0;
	} else {
		half = zephir_get_boolval(half_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "like", NULL, field, value, (half ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, isNull) {

	zend_bool isNotNull;
	zval *field_param = NULL, *isNotNull_param = NULL;
	zval *field = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &isNotNull_param);

	zephir_get_strval(field, field_param);
	if (!isNotNull_param) {
		isNotNull = 0;
	} else {
		isNotNull = zephir_get_boolval(isNotNull_param);
	}


	if (isNotNull) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, field, " is not null");
		zephir_update_property_array_append(this_ptr, SL("where"), _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_VS(_0, field, " is null");
		zephir_update_property_array_append(this_ptr, SL("where"), _0 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, isNotNull) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *_0;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

	zephir_get_strval(field, field_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "isnull", NULL, field, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, setAnd) {

	zval *_2;
	zval *w, *_0, *_1, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(w);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
		zephir_fast_join_str(w, SL(" and "), _1 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 2);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "(", w, ")");
		zephir_array_fast_append(_2, _3);
		zephir_update_property_this(this_ptr, SL("where"), _2 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, setOr) {

	zval *_2;
	zval *w, *_0, *_1, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(w);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
		zephir_fast_join_str(w, SL(" or "), _1 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 2);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "(", w, ")");
		zephir_array_fast_append(_2, _3);
		zephir_update_property_this(this_ptr, SL("where"), _2 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearWhere) {


	zephir_update_property_this(this_ptr, SL("where"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getWhere) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
		zephir_fast_join_str(return_value, SL(" and "), _1 TSRMLS_CC);
		return;
	}
	RETURN_STRING("", 1);

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupBy) {

	zend_bool overwrite, _0;
	zval *field_param = NULL, *overwrite_param = NULL, *_1;
	zval *field = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &overwrite_param);

	zephir_get_strval(field, field_param);
	if (!overwrite_param) {
		overwrite = 0;
	} else {
		overwrite = zephir_get_boolval(overwrite_param);
	}


	_0 = !overwrite;
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("groupBy"), PH_NOISY_CC);
		_0 = zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, ", ", field);
		zephir_update_property_this(this_ptr, SL("groupBy"), _2 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("groupBy"), field TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearGroupBy) {


	zephir_update_property_this(this_ptr, SL("groupBy"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, having) {

	zval *having_param = NULL;
	zval *having = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &having_param);

	zephir_get_strval(having, having_param);


	zephir_update_property_this(this_ptr, SL("having"), having TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearHaving) {


	zephir_update_property_this(this_ptr, SL("having"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, orderBy) {

	zend_bool asc, prepend;
	zval *field_param = NULL, *asc_param = NULL, *prepend_param = NULL, *_0, *_1, *_2;
	zval *field = NULL, *sort = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field_param, &asc_param, &prepend_param);

	zephir_get_strval(field, field_param);
	if (!asc_param) {
		asc = 0;
	} else {
		asc = zephir_get_boolval(asc_param);
	}
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	if (asc) {
		ZEPHIR_INIT_VAR(sort);
		ZVAL_STRING(sort, " asc", 1);
	} else {
		ZEPHIR_INIT_NVAR(sort);
		ZVAL_STRING(sort, " desc", 1);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		if (prepend) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_VVSV(_2, field, sort, ", ", _1);
			zephir_update_property_this(this_ptr, SL("orderBy"), _2 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVV(_3, ", ", field, sort);
			zephir_update_property_this(this_ptr, SL("orderBy"), _3 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VV(_3, field, sort);
		zephir_update_property_this(this_ptr, SL("orderBy"), _3 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, orderByRand) {


	zephir_update_property_this(this_ptr, SL("orderBy"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearOrderBy) {


	zephir_update_property_this(this_ptr, SL("orderBy"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, paginate) {

	zval *page_param = NULL, *pageSize_param = NULL, *_0;
	long page, pageSize;

	zephir_fetch_params(0, 0, 2, &page_param, &pageSize_param);

	if (!page_param) {
		page = 1;
	} else {
		page = zephir_get_intval(page_param);
	}
	if (!pageSize_param) {
		pageSize = 10;
	} else {
		pageSize = zephir_get_intval(pageSize_param);
	}


	if (page < 1) {
		page = 1;
	}
	if (pageSize < 1) {
		pageSize = 1;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, page);
	zephir_update_property_this(this_ptr, SL("page"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, pageSize);
	zephir_update_property_this(this_ptr, SL("pageSize"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, (pageSize * ((page - 1))));
	zephir_update_property_this(this_ptr, SL("rowOffset"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, top) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *num_param = NULL, *_0, *_1, *_2, *_3 = NULL;
	long num;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &num_param);

	if (!num_param) {
		num = 1;
	} else {
		num = zephir_get_intval(num_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("page"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, num);
	ZEPHIR_CALL_FUNCTION(&_3, "max", &_4, _1, _2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pageSize"), _3 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("rowOffset"), _0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearPagination) {


	zephir_update_property_this(this_ptr, SL("page"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("pageSize"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("rowOffset"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("numRows"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("numPages"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, setNumRows) {

	zval *numRows_param = NULL, *_0, *_1;
	long numRows, numPages;

	zephir_fetch_params(0, 1, 0, &numRows_param);

	numRows = zephir_get_intval(numRows_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pageSize"), PH_NOISY_CC);
	if (unlikely(ZEPHIR_LT_LONG(_0, 1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(nc_db_query_exception_ce, "Cannot set num rows when not paginating", "nc/db/query/dbqueryabstract.zep", 667);
		return;
	}
	if (numRows < 1) {
		numRows = 0;
		numPages = 0;
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("pageSize"), PH_NOISY_CC);
		numPages = (1 + (long) (zephir_safe_div_long_zval(((numRows - 1)), _1 TSRMLS_CC)));
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, numRows);
	zephir_update_property_this(this_ptr, SL("numRows"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, numPages);
	zephir_update_property_this(this_ptr, SL("numPages"), _1 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getPage) {


	RETURN_MEMBER(this_ptr, "page");

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getPageSize) {


	RETURN_MEMBER(this_ptr, "pageSize");

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getRowOffset) {


	RETURN_MEMBER(this_ptr, "rowOffset");

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getNumRows) {


	RETURN_MEMBER(this_ptr, "numRows");

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getNumPages) {


	RETURN_MEMBER(this_ptr, "numPages");

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, parseTableAlias) {

	int ZEPHIR_LAST_CALL_STATUS, _4;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *s_param = NULL, *a = NULL, _0, _1, _2, *_5, *_6;
	zval *s = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s_param);

	zephir_get_strval(s, s_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "/\\s+/", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, -1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&a, "preg_split", &_3, &_0, s, &_1, &_2);
	zephir_check_call_status();
	do {
		_4 = zephir_fast_count_int(a TSRMLS_CC);
		if (_4 == 1) {
			zephir_array_fetch_long(&_5, a, 0, PH_NOISY | PH_READONLY, "nc/db/query/dbqueryabstract.zep", 716 TSRMLS_CC);
			zephir_array_update_long(&a, 1, &_5, PH_COPY | PH_SEPARATE, "nc/db/query/dbqueryabstract.zep", 716);
			break;
		}
		if (_4 == 2) {
			break;
		}
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, nc_db_query_exception_ce);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, "Cannot parse table alias: ", s);
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6, "nc/db/query/dbqueryabstract.zep", 722 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	RETURN_CCTOR(a);

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildField) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("field"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MEMBER(this_ptr, "field");
	}
	RETURN_STRING("*", 1);

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildTableAndJoin) {

	zval *_0, *_1, *_2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("tableAlias"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("join"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VSVV(return_value, _0, " ", _1, _2);
	return;

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildWhere) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
		zephir_fast_join_str(_1, SL(" and "), _2 TSRMLS_CC);
		ZEPHIR_CONCAT_SV(return_value, " where ", _1);
		RETURN_MM();
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildGroupBy) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("groupBy"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("groupBy"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SV(return_value, " group by ", _1);
		return;
	}
	RETURN_STRING("", 1);

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildHaving) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("having"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("having"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SV(return_value, " having ", _1);
		return;
	}
	RETURN_STRING("", 1);

}

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildOrderBy) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SV(return_value, " order by ", _1);
		return;
	}
	RETURN_STRING("", 1);

}

