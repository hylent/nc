
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Db_DbAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, DbAbstract, nc, db_dbabstract, nc_db_dbabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_db_dbabstract_ce, SL("queries"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(nc_db_dbabstract_ce, SL("inTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_dbabstract_ce, SL("savepoints"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_db_dbabstract_ce, SL("nextFlag"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbabstract_ce, SL("NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbabstract_ce, SL("ALL"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbabstract_ce, SL("ROW"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbabstract_ce, SL("CELL"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbabstract_ce, SL("COLUMNS"), 4 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_DbAbstract, profiledQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	double t;
	zval *p = NULL;
	zval *q_param = NULL, *p_param = NULL, *t_param = NULL, _0, _1, *_2 = NULL, *_4$$3, *_5$$3;
	zval *q = NULL, *s = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &q_param, &p_param, &t_param);

	zephir_get_strval(q, q_param);
	zephir_get_arrval(p, p_param);
	t = zephir_get_doubleval(t_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "%s # %0.3fms", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, (t * 1000.0));
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_0, q, &_1);
	zephir_check_call_status();
	zephir_get_strval(_3, _2);
	ZEPHIR_CPY_WRT(s, _3);
	if (zephir_fast_count_int(p TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_json_encode(_4$$3, &(_4$$3), p, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, " ", _4$$3);
		zephir_concat_self(&s, _5$$3 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, getInternalHandler) {

}

PHP_METHOD(Nc_Db_DbAbstract, quote) {

}

PHP_METHOD(Nc_Db_DbAbstract, query) {

}

PHP_METHOD(Nc_Db_DbAbstract, getQueries) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("queries"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MEMBER(this_ptr, "queries");
	}
	array_init(return_value);
	return;

}

PHP_METHOD(Nc_Db_DbAbstract, insert) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *returningId_param = NULL, *_0 = NULL, *_2 = NULL, *_4$$3;
	zval *table = NULL, *returningId = NULL, *sql = NULL, *_1 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &returningId_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);
	if (!returningId_param) {
		ZEPHIR_INIT_VAR(returningId);
		ZVAL_STRING(returningId, "", 1);
	} else {
		zephir_get_strval(returningId, returningId_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "insertsql", NULL, 0, table, data);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(sql, _1);
	if (zephir_fast_strlen_ev(returningId) > 0) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, " RETURNING ", returningId);
		zephir_concat_self(&sql, _3$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, 3);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", &_5, 0, sql, data, _4$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_5, 0, sql, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *where_param = NULL, *_0 = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &where_param);

	zephir_get_strval(table, table_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "deletesql", NULL, 0, table, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, update) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *where = NULL;
	zval *table_param = NULL, *data_param = NULL, *where_param = NULL, *_0 = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "updatesql", NULL, 0, table, data, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _0, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, upsert) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *primaryKey, *k = NULL, *v = NULL, *where = NULL, **_2$$3, *_3$$5 = NULL, *_4$$5 = NULL, *_7$$8, *_8$$8;
	zval *table = NULL, *_6$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &table_param, &data_param, &primaryKey);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);


	ZEPHIR_INIT_VAR(where);
	array_init(where);
	if (Z_TYPE_P(primaryKey) == IS_ARRAY) {
		zephir_is_iterable(primaryKey, &_1$$3, &_0$$3, 0, 0, "nc/db/dbabstract.zep", 79);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(k, _2$$3);
			ZEPHIR_OBS_NVAR(v);
			if (unlikely(!(zephir_array_isset_fetch(&v, data, k, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_NVAR(_3$$5);
				object_init_ex(_3$$5, nc_db_exception_ce);
				ZEPHIR_INIT_LNVAR(_4$$5);
				ZEPHIR_CONCAT_SV(_4$$5, "Cannot find primary key value in data: ", k);
				ZEPHIR_CALL_METHOD(NULL, _3$$5, "__construct", &_5, 2, _4$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3$$5, "nc/db/dbabstract.zep", 75 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&where, k, &v, PH_COPY | PH_SEPARATE);
		}
		if (unlikely(!zephir_is_true(where))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Cannot upsert with empty where", "nc/db/dbabstract.zep", 80);
			return;
		}
	} else {
		zephir_get_strval(_6$$7, primaryKey);
		ZEPHIR_CPY_WRT(k, _6$$7);
		ZEPHIR_OBS_NVAR(v);
		if (unlikely(!(zephir_array_isset_fetch(&v, data, k, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_VAR(_7$$8);
			object_init_ex(_7$$8, nc_db_exception_ce);
			ZEPHIR_INIT_VAR(_8$$8);
			ZEPHIR_CONCAT_SV(_8$$8, "Cannot find primary key value in data: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$8, "__construct", &_5, 2, _8$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$8, "nc/db/dbabstract.zep", 85 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&where, k, &v, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, table, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "insert", NULL, 0, table, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, select) {

	int ZEPHIR_LAST_CALL_STATUS;
	long mode;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *mode_param = NULL, *_0 = NULL, *_1, *_2;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table_param, &options_param, &mode_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!mode_param) {
		mode = 1;
	} else {
		mode = zephir_get_intval(mode_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "selectsql", NULL, 0, table, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, mode);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, _0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, countAndSelect) {

	int ZEPHIR_LAST_CALL_STATUS;
	long mode, c = 0;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *mode_param = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3 = NULL, *_5 = NULL, *_4$$3 = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table_param, &options_param, &mode_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!mode_param) {
		mode = 1;
	} else {
		mode = zephir_get_intval(mode_param);
	}


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "selectcountsql", NULL, 0, table, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "query", NULL, 0, _1, _2, _3);
	zephir_check_call_status();
	c = zephir_get_intval(_0);
	if (c < 1) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, 0);
		zephir_array_fast_append(return_value, _4$$3);
		ZEPHIR_INIT_NVAR(_4$$3);
		array_init(_4$$3);
		zephir_array_fast_append(return_value, _4$$3);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, c);
	zephir_array_fast_append(return_value, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, mode);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "select", NULL, 0, table, options, _3);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _5);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, selectUnionAll) {

	zval *s = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, skip;
	zval *selects_param = NULL, *orderBy = NULL, *limit_param = NULL, *skip_param = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *selects = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &selects_param, &orderBy, &limit_param, &skip_param);

	zephir_get_arrval(selects, selects_param);
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


	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, limit);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, skip);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "selectunionallsql", NULL, 0, selects, orderBy, _1, _2);
	zephir_check_call_status();
	zephir_get_strval(_3, _0);
	ZEPHIR_CPY_WRT(s, _3);
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, s, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, countAndSelectUnionAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	long limit, skip, c = 0;
	zval *selects_param = NULL, *orderBy = NULL, *limit_param = NULL, *skip_param = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_6 = NULL, *_7, *_0$$3 = NULL, *_5$$4 = NULL;
	zval *selects = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &selects_param, &orderBy, &limit_param, &skip_param);

	zephir_get_arrval(selects, selects_param);
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


	if (zephir_fast_count_int(selects TSRMLS_CC) < 1) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, 0);
		zephir_array_fast_append(return_value, _0$$3);
		ZEPHIR_INIT_NVAR(_0$$3);
		array_init(_0$$3);
		zephir_array_fast_append(return_value, _0$$3);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "selectcountunionallsql", NULL, 0, selects);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 3);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "query", NULL, 0, _2, _3, _4);
	zephir_check_call_status();
	c = zephir_get_intval(_1);
	if (c < 1) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_LONG(_5$$4, 0);
		zephir_array_fast_append(return_value, _5$$4);
		ZEPHIR_INIT_NVAR(_5$$4);
		array_init(_5$$4);
		zephir_array_fast_append(return_value, _5$$4);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, c);
	zephir_array_fast_append(return_value, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, limit);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, skip);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "selectunionall", NULL, 0, selects, orderBy, _4, _7);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _6);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, aggregations) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations = NULL, *where = NULL;
	zval *table_param = NULL, *aggregations_param = NULL, *where_param = NULL, *_0 = NULL, *_1, *_2;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &aggregations_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(aggregations, aggregations_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "aggregationssql", NULL, 0, table, aggregations, where);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, _0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, aggregation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *aggregation_param = NULL, *where_param = NULL, *_0 = NULL, *_1, *_2;
	zval *table = NULL, *column = NULL, *aggregation = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &column_param, &aggregation_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	zephir_get_strval(aggregation, aggregation_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "aggregationsql", NULL, 0, table, column, aggregation, where);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 3);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, _0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0 = NULL, *_1;
	zval *table = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
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


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "COUNT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "aggregation", NULL, 0, table, column, _1, where);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(Nc_Db_DbAbstract, max) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MAX", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, table, column, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, min) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, table, column, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, sum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "SUM", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, table, column, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, avg) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "AVG", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, table, column, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, groupAggregations) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations = NULL, *options = NULL;
	zval *table_param = NULL, *groupBy_param = NULL, *aggregations_param = NULL, *options_param = NULL, *_0 = NULL, *_1, *_2;
	zval *table = NULL, *groupBy = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &groupBy_param, &aggregations_param, &options_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(groupBy, groupBy_param);
	zephir_get_arrval(aggregations, aggregations_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "groupaggregationssql", NULL, 0, table, groupBy, aggregations, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, _0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, inTransaction) {

	

	RETURN_MEMBER(this_ptr, "inTransaction");

}

PHP_METHOD(Nc_Db_DbAbstract, begin) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!(!zephir_is_true(_0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot begin when already in transaction", "nc/db/dbabstract.zep", 189);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytobegin", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot begin transaction", "nc/db/dbabstract.zep", 193);
		return;
	}
	if (1) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, commit) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot commit when not in transaction", "nc/db/dbabstract.zep", 202);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytocommit", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot commit transaction", "nc/db/dbabstract.zep", 206);
		return;
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, rollback) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback when not in transaction", "nc/db/dbabstract.zep", 215);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytorollback", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback transaction", "nc/db/dbabstract.zep", 219);
		return;
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, savepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_2$$4;
	zval *savepoint = NULL, *_4, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot acquire a savepoint when not in a transaction", "nc/db/dbabstract.zep", 228);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(zephir_array_isset(_1, savepoint))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_db_transactionexception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Duplicate savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/db/dbabstract.zep", 232 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _4);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, releaseSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_5, *_2$$4;
	zval *savepoint = NULL, *_4, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot release a savepoint when not in a transaction", "nc/db/dbabstract.zep", 242);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_1, savepoint)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_db_transactionexception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot find savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/db/dbabstract.zep", 246 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "RELEASE SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	zephir_array_unset(&_5, savepoint, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, releaseLastSavepoint) {

	zval *_0, *_1, *_2, *_3 = NULL, *_6;
	zval *savepoint = NULL, *_4 = NULL, *_5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot release last savepoint when not in a transaction", "nc/db/dbabstract.zep", 258);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Empty savepoint stack", "nc/db/dbabstract.zep", 262);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "end", NULL, 3, _2);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(savepoint, _4);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "RELEASE SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _5);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	zephir_array_unset(&_6, savepoint, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, rollbackToSavepoint) {

	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_2$$4, *_5$$5, *_6$$5 = NULL;
	zval *savepoint = NULL, *_4, *_3$$4, *_8$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback to a savepoint when not in a transaction", "nc/db/dbabstract.zep", 274);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_1, savepoint)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_db_transactionexception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot find savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/db/dbabstract.zep", 278 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "ROLLBACK TO SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _4);
	zephir_check_call_status();
	while (1) {
		_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
		ZEPHIR_MAKE_REF(_5$$5);
		ZEPHIR_CALL_FUNCTION(&_6$$5, "array_pop", &_7, 4, _5$$5);
		ZEPHIR_UNREF(_5$$5);
		zephir_check_call_status();
		zephir_get_strval(_8$$5, _6$$5);
		if (ZEPHIR_IS_IDENTICAL(_8$$5, savepoint)) {
			zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, rollbackToLastSavepoint) {

	zval *_0, *_1, *_2, *_3 = NULL;
	zval *savepoint = NULL, *_4 = NULL, *_5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback to last savepoint when not in a transaction", "nc/db/dbabstract.zep", 296);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Empty savepoint stack", "nc/db/dbabstract.zep", 300);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "end", NULL, 3, _2);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(savepoint, _4);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "ROLLBACK TO SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, insertSql) {

	HashTable *_2;
	HashPosition _1;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *k = NULL, *ks = NULL, *vs = NULL, *_0 = NULL, **_3, *_5, *_6, *_4$$3 = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &table_param, &data_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);


	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(vs);
	array_init(vs);
	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(data, &_2, &_1, 0, 0, "nc/db/dbabstract.zep", 316);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(_0, _3);
		zephir_array_append(&ks, k, PH_SEPARATE, "nc/db/dbabstract.zep", 312);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, ":", k);
		zephir_array_append(&vs, _4$$3, PH_SEPARATE, "nc/db/dbabstract.zep", 313);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), ks TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_join_str(_6, SL(", "), vs TSRMLS_CC);
	ZEPHIR_CONCAT_SVSVSVS(return_value, "INSERT INTO ", table, " (", _5, ") VALUES (", _6, ")");
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, deleteSql) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *where_param = NULL, *_0 = NULL, *_2 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_1 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &table_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(where, where_param);


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SV(s, "DELETE FROM ", table);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "wheresql", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(w, _1);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, " WHERE ", w);
		zephir_concat_self(&s, _3$$3 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, updateSql) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *where = NULL;
	zval *table_param = NULL, *data_param = NULL, *where_param = NULL, *k = NULL, *kvs = NULL, *_0 = NULL, **_3, *_5, *_6, *_7 = NULL, *_9 = NULL, *_4$$3 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_8 = NULL, *_10$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &table_param, &data_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);
	zephir_get_arrval(where, where_param);


	ZEPHIR_INIT_VAR(kvs);
	array_init(kvs);
	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(data, &_2, &_1, 0, 0, "nc/db/dbabstract.zep", 341);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(_0, _3);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_VSV(_4$$3, k, " = :", k);
		zephir_array_update_zval(&kvs, k, &_4$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), kvs TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SVSV(_6, "UPDATE ", table, " SET ", _5);
	zephir_get_strval(s, _6);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "wheresql", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_8, _7);
	ZEPHIR_CPY_WRT(w, _8);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_10$$4);
		ZEPHIR_CONCAT_SV(_10$$4, " WHERE ", w);
		zephir_concat_self(&s, _10$$4 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, selectSql) {

	zend_bool forUpdate = 0;
	long limit = 0, skip = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options = NULL, *_6 = NULL;
	zval *table_param = NULL, *options_param = NULL, *where = NULL, *orderBy = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_8, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_17$$7 = NULL, *_22$$9 = NULL, *_23$$9, *_24$$9;
	zval *table = NULL, *field = NULL, *w = NULL, *s = NULL, *_4 = NULL, *_12, *_14 = NULL, *_16$$5, *_18$$7 = NULL, *_19$$7, *_20$$8 = NULL, *_21$$8, *_25$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(s);
	ZVAL_STRING(s, "SELECT ", 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "field", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "*", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(field, _4);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_5, nc_std_ce, "valueat", &_1, 5, options, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_arrval(_6, _5);
	ZEPHIR_CPY_WRT(where, _6);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "orderBy", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_NULL(_7);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_BOOL(_8, 1);
	ZEPHIR_CALL_CE_STATIC(&orderBy, nc_std_ce, "valueat", &_1, 5, options, _3, _7, _8);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "limit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_CALL_CE_STATIC(&_9, nc_std_ce, "valueat", &_1, 5, options, _3, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	limit = zephir_get_intval(_9);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "skip", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_CALL_CE_STATIC(&_10, nc_std_ce, "valueat", &_1, 5, options, _3, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	skip = zephir_get_intval(_10);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "forUpdate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_BOOL(_7, 0);
	ZEPHIR_CALL_CE_STATIC(&_11, nc_std_ce, "valueat", &_1, 5, options, _3, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	forUpdate = zephir_get_boolval(_11);
	if (zephir_fast_strlen_ev(field) > 0) {
		zephir_concat_self(&s, field TSRMLS_CC);
	} else {
		zephir_concat_self_str(&s, "*", sizeof("*")-1 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_SV(_12, " FROM ", table);
	zephir_concat_self(&s, _12 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "wheresql", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_14, _13);
	ZEPHIR_CPY_WRT(w, _14);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_16$$5);
		ZEPHIR_CONCAT_SV(_16$$5, " WHERE ", w);
		zephir_concat_self(&s, _16$$5 TSRMLS_CC);
	}
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "randomordersql", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_18$$7, _17$$7);
			ZEPHIR_INIT_VAR(_19$$7);
			ZEPHIR_CONCAT_SV(_19$$7, " ORDER BY ", _18$$7);
			zephir_concat_self(&s, _19$$7 TSRMLS_CC);
			skip = 0;
		} else {
			zephir_get_strval(_20$$8, orderBy);
			ZEPHIR_INIT_VAR(_21$$8);
			ZEPHIR_CONCAT_SV(_21$$8, " ORDER BY ", _20$$8);
			zephir_concat_self(&s, _21$$8 TSRMLS_CC);
		}
	}
	if (limit > 0) {
		ZEPHIR_INIT_VAR(_23$$9);
		ZVAL_LONG(_23$$9, limit);
		ZEPHIR_INIT_VAR(_24$$9);
		ZVAL_LONG(_24$$9, skip);
		ZEPHIR_CALL_METHOD(&_22$$9, this_ptr, "paginationsql", NULL, 0, s, _23$$9, _24$$9);
		zephir_check_call_status();
		zephir_get_strval(_25$$9, _22$$9);
		ZEPHIR_CPY_WRT(s, _25$$9);
	}
	if (forUpdate) {
		zephir_concat_self_str(&s, " FOR UPDATE", sizeof(" FOR UPDATE")-1 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, selectCountSql) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options = NULL, *_4 = NULL;
	zval *table_param = NULL, *options_param = NULL, *where = NULL, *_0 = NULL, *_2, *_3, *_5 = NULL, *_7 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_6 = NULL, *_8$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 5, options, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_arrval(_4, _0);
	ZEPHIR_CPY_WRT(where, _4);
	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SV(s, "SELECT COUNT(*) FROM ", table);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "wheresql", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(w, _6);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_8$$3);
		ZEPHIR_CONCAT_SV(_8$$3, " WHERE ", w);
		zephir_concat_self(&s, _8$$3 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, selectUnionAllSql) {

	HashTable *_1;
	HashPosition _0;
	zval *s = NULL, *_5 = NULL, *_8 = NULL, *_10$$6 = NULL, *_11$$6, *_12$$7 = NULL, *_13$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, skip;
	zval *selects_param = NULL, *orderBy, *limit_param = NULL, *skip_param = NULL, *i = NULL, *a = NULL, **_2, *_4, *_6 = NULL, *_7 = NULL, *_14, *_3$$4 = NULL, *_9$$6 = NULL;
	zval *selects = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &selects_param, &orderBy, &limit_param, &skip_param);

	zephir_get_arrval(selects, selects_param);
	limit = zephir_get_intval(limit_param);
	skip = zephir_get_intval(skip_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	if (unlikely(zephir_fast_count_int(selects TSRMLS_CC) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid union all, empty selects", "nc/db/dbabstract.zep", 420);
		return;
	}
	zephir_is_iterable(selects, &_1, &_0, 0, 0, "nc/db/dbabstract.zep", 427);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(i, _2);
		ZEPHIR_INIT_LNVAR(_3$$4);
		ZEPHIR_CONCAT_SVS(_3$$4, "(", i, ")");
		zephir_array_append(&a, _3$$4, PH_SEPARATE, "nc/db/dbabstract.zep", 424);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(" UNION ALL "), a TSRMLS_CC);
	zephir_get_strval(_5, _4);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "u", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "nextflag", NULL, 0, _7);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	zephir_get_strval(_8, _6);
	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSV(s, "SELECT * FROM (", _5, ") AS ", _8);
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "randomordersql", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_10$$6, _9$$6);
			ZEPHIR_INIT_VAR(_11$$6);
			ZEPHIR_CONCAT_SV(_11$$6, " ORDER BY ", _10$$6);
			zephir_concat_self(&s, _11$$6 TSRMLS_CC);
			skip = 0;
		} else {
			zephir_get_strval(_12$$7, orderBy);
			ZEPHIR_INIT_VAR(_13$$7);
			ZEPHIR_CONCAT_SV(_13$$7, " ORDER BY ", _12$$7);
			zephir_concat_self(&s, _13$$7 TSRMLS_CC);
		}
	}
	if (limit < 1) {
		RETURN_CTOR(s);
	}
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, limit);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_LONG(_14, skip);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "paginationsql", NULL, 0, s, _7, _14);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, selectCountUnionAllSql) {

	zval *_5 = NULL, *_8 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *selects_param = NULL, *i = NULL, *a = NULL, **_2, *_4, *_6 = NULL, *_7, *_3$$4 = NULL;
	zval *selects = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &selects_param);

	zephir_get_arrval(selects, selects_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	if (unlikely(zephir_fast_count_int(selects TSRMLS_CC) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid union all, empty selects", "nc/db/dbabstract.zep", 450);
		return;
	}
	zephir_is_iterable(selects, &_1, &_0, 0, 0, "nc/db/dbabstract.zep", 457);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(i, _2);
		ZEPHIR_INIT_LNVAR(_3$$4);
		ZEPHIR_CONCAT_SVS(_3$$4, "(", i, ")");
		zephir_array_append(&a, _3$$4, PH_SEPARATE, "nc/db/dbabstract.zep", 454);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(" UNION ALL "), a TSRMLS_CC);
	zephir_get_strval(_5, _4);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "u", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "nextflag", NULL, 0, _7);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	zephir_get_strval(_8, _6);
	ZEPHIR_CONCAT_SVSV(return_value, "SELECT COUNT(*) FROM (", _5, ") AS ", _8);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, aggregationsSql) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations = NULL, *where = NULL;
	zval *table_param = NULL, *aggregations_param = NULL, *where_param = NULL, *k = NULL, *v = NULL, *a = NULL, **_2, *_4, *_5, *_6 = NULL, *_8 = NULL, *_3$$3 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_7 = NULL, *_9$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &table_param, &aggregations_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(aggregations, aggregations_param);
	zephir_get_arrval(where, where_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	zephir_is_iterable(aggregations, &_1, &_0, 0, 0, "nc/db/dbabstract.zep", 469);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSV(_3$$3, v, " AS ", k);
		zephir_array_append(&a, _3$$3, PH_SEPARATE, "nc/db/dbabstract.zep", 466);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), a TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVSV(_5, "SELECT ", _4, " FROM ", table);
	zephir_get_strval(s, _5);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "wheresql", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_7, _6);
	ZEPHIR_CPY_WRT(w, _7);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_9$$4);
		ZEPHIR_CONCAT_SV(_9$$4, " WHERE ", w);
		zephir_concat_self(&s, _9$$4 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, aggregationSql) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *aggregation_param = NULL, *where_param = NULL, *_0 = NULL, *_2 = NULL;
	zval *table = NULL, *column = NULL, *aggregation = NULL, *s = NULL, *w = NULL, *_1 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &table_param, &column_param, &aggregation_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	zephir_get_strval(aggregation, aggregation_param);
	zephir_get_arrval(where, where_param);


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSVSV(s, "SELECT ", aggregation, "(", column, ") FROM ", table);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "wheresql", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(w, _1);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, " WHERE ", w);
		zephir_concat_self(&s, _3$$3 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, groupAggregationsSql) {

	HashTable *_11;
	HashPosition _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_16 = NULL;
	zval *aggregations = NULL, *options = NULL, *_4 = NULL, *_7 = NULL;
	zval *table_param = NULL, *groupBy_param = NULL, *aggregations_param = NULL, *options_param = NULL, *where = NULL, *having = NULL, *orderBy = NULL, *k = NULL, *v = NULL, *a = NULL, *_0 = NULL, *_2, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_8, *_9, **_12, *_14, *_15 = NULL, *_18 = NULL, *_21 = NULL, *_23 = NULL, *_13$$3 = NULL, *_25$$7 = NULL;
	zval *table = NULL, *groupBy = NULL, *s = NULL, *w = NULL, *_17 = NULL, *_20, *_22 = NULL, *_19$$4, *_24$$5, *_26$$7 = NULL, *_27$$7, *_28$$8 = NULL, *_29$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &table_param, &groupBy_param, &aggregations_param, &options_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(groupBy, groupBy_param);
	zephir_get_arrval(aggregations, aggregations_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 5, options, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_arrval(_4, _0);
	ZEPHIR_CPY_WRT(where, _4);
	ZEPHIR_INIT_NVAR(_3);
	array_init(_3);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "having", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_5, nc_std_ce, "valueat", &_1, 5, options, _6, _3);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	zephir_get_arrval(_7, _5);
	ZEPHIR_CPY_WRT(having, _7);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "orderBy", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_NULL(_8);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_BOOL(_9, 1);
	ZEPHIR_CALL_CE_STATIC(&orderBy, nc_std_ce, "valueat", &_1, 5, options, _6, _8, _9);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	zephir_array_append(&a, groupBy, PH_SEPARATE, "nc/db/dbabstract.zep", 504);
	zephir_is_iterable(aggregations, &_11, &_10, 0, 0, "nc/db/dbabstract.zep", 510);
	for (
	  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
	  ; zephir_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HMKEY(k, _11, _10);
		ZEPHIR_GET_HVALUE(v, _12);
		ZEPHIR_INIT_LNVAR(_13$$3);
		ZEPHIR_CONCAT_VSVSV(_13$$3, v, "(", groupBy, ") AS ", k);
		zephir_array_append(&a, _13$$3, PH_SEPARATE, "nc/db/dbabstract.zep", 507);
	}
	ZEPHIR_INIT_NVAR(_6);
	zephir_fast_join_str(_6, SL(", "), a TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_SVSV(_14, "SELECT ", _6, " FROM ", table);
	zephir_get_strval(s, _14);
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "wheresql", &_16, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_17, _15);
	ZEPHIR_CPY_WRT(w, _17);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_19$$4);
		ZEPHIR_CONCAT_SV(_19$$4, " WHERE ", w);
		zephir_concat_self(&s, _19$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_20);
	ZEPHIR_CONCAT_SV(_20, " GROUP BY ", groupBy);
	zephir_concat_self(&s, _20 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "wheresql", &_16, 0, having);
	zephir_check_call_status();
	zephir_get_strval(_22, _21);
	ZEPHIR_CPY_WRT(w, _22);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_24$$5);
		ZEPHIR_CONCAT_SV(_24$$5, " HAVING ", w);
		zephir_concat_self(&s, _24$$5 TSRMLS_CC);
	}
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_25$$7, this_ptr, "randomordersql", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_26$$7, _25$$7);
			ZEPHIR_INIT_VAR(_27$$7);
			ZEPHIR_CONCAT_SV(_27$$7, " ORDER BY ", _26$$7);
			zephir_concat_self(&s, _27$$7 TSRMLS_CC);
		} else {
			zephir_get_strval(_28$$8, orderBy);
			ZEPHIR_INIT_VAR(_29$$8);
			ZEPHIR_CONCAT_SV(_29$$8, " ORDER BY ", _28$$8);
			zephir_concat_self(&s, _29$$8 TSRMLS_CC);
		}
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, whereSql) {

	zend_bool _23$$15, _24$$15, _32$$20, _48$$28, _63$$31, _68$$33, _72$$35;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL, *_39 = NULL, *_42 = NULL, *_61 = NULL, *_66 = NULL, *_78 = NULL;
	zval *sep = NULL, *k1 = NULL, *k2 = NULL, *tmp = NULL, *_5$$3 = NULL, *_7$$3 = NULL, *_8$$5 = NULL, *_12$$8 = NULL, *_45$$26 = NULL, *_54$$28 = NULL, *_55$$28 = NULL, *_77$$37 = NULL;
	zval *where_param = NULL, *sep_param = NULL, *k = NULL, *v = NULL, *ks = NULL, *ws = NULL, **_2, *_3$$3 = NULL, *_6$$3 = NULL, *_9$$6 = NULL, *_11$$6 = NULL, *_13$$9 = NULL, *_14$$9 = NULL, *_15$$10 = NULL, *_16$$10 = NULL, *_17$$11 = NULL, *_18$$11 = NULL, *_19$$12 = NULL, *_20$$12 = NULL, *_21$$13 = NULL, *_22$$13 = NULL, *_25$$15 = NULL, *_26$$15, *_27$$15 = NULL, *_28$$15, *_29$$15 = NULL, *_30$$18 = NULL, *_31$$18 = NULL, _33$$20 = zval_used_for_init, *_34$$20 = NULL, *_35$$22 = NULL, *_37$$22 = NULL, *_38$$22 = NULL, *_40$$22 = NULL, *_41$$23 = NULL, _43$$25 = zval_used_for_init, *_44$$25 = NULL, *_46$$25 = NULL, *_47$$27 = NULL, *_49$$28 = NULL, *_51$$28 = NULL, *_53$$28 = NULL, *_56$$28 = NULL, *_58$$30 = NULL, *_59$$30 = NULL, *_60$$30 = NULL, *_62$$30 = NULL, *_64$$31 = NULL, *_65$$31 = NULL, *_67$$31 = NULL, *_69$$33 = NULL, *_70$$33 = NULL, *_71$$33 = NULL, *_73$$35 = NULL, *_74$$35 = NULL, *_75$$35 = NULL, *_76$$37 = NULL;
	zval *where = NULL, *_36$$22 = NULL, *_50$$28 = NULL, *_52$$28 = NULL, *_57$$30 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &where_param, &sep_param);

	zephir_get_arrval(where, where_param);
	if (!sep_param) {
		ZEPHIR_INIT_VAR(sep);
		ZVAL_STRING(sep, " AND ", 1);
	} else {
		zephir_get_strval(sep, sep_param);
	}


	ZEPHIR_INIT_VAR(ws);
	array_init(ws);
	zephir_is_iterable(where, &_1, &_0, 0, 0, "nc/db/dbabstract.zep", 645);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_NVAR(ks);
		zephir_fast_explode_str(ks, SL("$"), k, LONG_MAX TSRMLS_CC);
		ZEPHIR_MAKE_REF(ks);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_shift", &_4, 6, ks);
		ZEPHIR_UNREF(ks);
		zephir_check_call_status();
		zephir_get_strval(_5$$3, _3$$3);
		ZEPHIR_CPY_WRT(k1, _5$$3);
		ZEPHIR_MAKE_REF(ks);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "array_shift", &_4, 6, ks);
		ZEPHIR_UNREF(ks);
		zephir_check_call_status();
		zephir_get_strval(_7$$3, _6$$3);
		ZEPHIR_CPY_WRT(k2, _7$$3);
		ZEPHIR_INIT_NVAR(tmp);
		ZVAL_EMPTY_STRING(tmp);
		do {
			if (ZEPHIR_IS_STRING(k2, "")) {
				if (Z_TYPE_P(v) == IS_NULL) {
					ZEPHIR_INIT_LNVAR(_8$$5);
					ZEPHIR_CONCAT_VS(_8$$5, k1, " IS NULL");
					zephir_array_append(&ws, _8$$5, PH_SEPARATE, "nc/db/dbabstract.zep", 549);
				} else {
					ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "quote", &_10, 0, v);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_11$$6);
					ZEPHIR_CONCAT_VSV(_11$$6, k1, " = ", _9$$6);
					zephir_array_append(&ws, _11$$6, PH_SEPARATE, "nc/db/dbabstract.zep", 551);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "neq")) {
				if (Z_TYPE_P(v) == IS_NULL) {
					ZEPHIR_INIT_LNVAR(_12$$8);
					ZEPHIR_CONCAT_VS(_12$$8, k1, "IS NOT NULL");
					zephir_array_append(&ws, _12$$8, PH_SEPARATE, "nc/db/dbabstract.zep", 556);
				} else {
					ZEPHIR_CALL_METHOD(&_13$$9, this_ptr, "quote", &_10, 0, v);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_14$$9);
					ZEPHIR_CONCAT_VSV(_14$$9, k1, " <> ", _13$$9);
					zephir_array_append(&ws, _14$$9, PH_SEPARATE, "nc/db/dbabstract.zep", 558);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "lt")) {
				ZEPHIR_CALL_METHOD(&_15$$10, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_16$$10);
				ZEPHIR_CONCAT_VSV(_16$$10, k1, " < ", _15$$10);
				zephir_array_append(&ws, _16$$10, PH_SEPARATE, "nc/db/dbabstract.zep", 562);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "lte")) {
				ZEPHIR_CALL_METHOD(&_17$$11, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_18$$11);
				ZEPHIR_CONCAT_VSV(_18$$11, k1, " <= ", _17$$11);
				zephir_array_append(&ws, _18$$11, PH_SEPARATE, "nc/db/dbabstract.zep", 565);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "gt")) {
				ZEPHIR_CALL_METHOD(&_19$$12, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20$$12);
				ZEPHIR_CONCAT_VSV(_20$$12, k1, " > ", _19$$12);
				zephir_array_append(&ws, _20$$12, PH_SEPARATE, "nc/db/dbabstract.zep", 568);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "gte")) {
				ZEPHIR_CALL_METHOD(&_21$$13, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_22$$13);
				ZEPHIR_CONCAT_VSV(_22$$13, k1, " >= ", _21$$13);
				zephir_array_append(&ws, _22$$13, PH_SEPARATE, "nc/db/dbabstract.zep", 571);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notBetween")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "between")) {
				_23$$15 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_23$$15)) {
					_23$$15 = !(zephir_array_isset_long(v, 0));
				}
				_24$$15 = _23$$15;
				if (!(_24$$15)) {
					_24$$15 = !(zephir_array_isset_long(v, 1));
				}
				if (unlikely(_24$$15)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid between", "nc/db/dbabstract.zep", 577);
					return;
				}
				zephir_array_fetch_long(&_26$$15, v, 0, PH_NOISY | PH_READONLY, "nc/db/dbabstract.zep", 579 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_25$$15, this_ptr, "quote", &_10, 0, _26$$15);
				zephir_check_call_status();
				zephir_array_fetch_long(&_28$$15, v, 1, PH_NOISY | PH_READONLY, "nc/db/dbabstract.zep", 579 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_27$$15, this_ptr, "quote", &_10, 0, _28$$15);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_29$$15);
				ZEPHIR_CONCAT_VVSVSV(_29$$15, k1, tmp, " BETWEEN ", _25$$15, " AND ", _27$$15);
				zephir_array_append(&ws, _29$$15, PH_SEPARATE, "nc/db/dbabstract.zep", 579);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notLike")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "like")) {
				ZEPHIR_CALL_METHOD(&_30$$18, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_31$$18);
				ZEPHIR_CONCAT_VVSV(_31$$18, k1, tmp, " LIKE ", _30$$18);
				zephir_array_append(&ws, _31$$18, PH_SEPARATE, "nc/db/dbabstract.zep", 584);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notIn")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "in")) {
				_32$$20 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_32$$20)) {
					_32$$20 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_32$$20)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid in", "nc/db/dbabstract.zep", 590);
					return;
				}
				ZEPHIR_SINIT_NVAR(_33$$20);
				ZVAL_STRING(&_33$$20, ",", 0);
				ZEPHIR_INIT_NVAR(_34$$20);
				zephir_fast_strpos(_34$$20, k1, &_33$$20, 0 );
				if (ZEPHIR_IS_FALSE_IDENTICAL(_34$$20)) {
					ZEPHIR_INIT_NVAR(_35$$22);
					ZEPHIR_INIT_NVAR(_36$$22);
					zephir_create_array(_36$$22, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_36$$22, this_ptr);
					ZEPHIR_INIT_NVAR(_37$$22);
					ZVAL_STRING(_37$$22, "quote", 1);
					zephir_array_fast_append(_36$$22, _37$$22);
					ZEPHIR_CALL_FUNCTION(&_38$$22, "array_map", &_39, 7, _36$$22, v);
					zephir_check_call_status();
					zephir_fast_join_str(_35$$22, SL(", "), _38$$22 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_40$$22);
					ZEPHIR_CONCAT_VVSVS(_40$$22, k1, tmp, " IN (", _35$$22, ")");
					zephir_array_append(&ws, _40$$22, PH_SEPARATE, "nc/db/dbabstract.zep", 593);
				} else {
					ZEPHIR_CALL_METHOD(&_41$$23, this_ptr, "wheremultipleinsql", &_42, 0, k1, v, tmp);
					zephir_check_call_status();
					zephir_array_append(&ws, _41$$23, PH_SEPARATE, "nc/db/dbabstract.zep", 595);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notInSelect")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "inSelect")) {
				ZEPHIR_SINIT_NVAR(_43$$25);
				ZVAL_STRING(&_43$$25, ",", 0);
				ZEPHIR_INIT_NVAR(_44$$25);
				zephir_fast_strpos(_44$$25, k1, &_43$$25, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(_44$$25)) {
					ZEPHIR_INIT_LNVAR(_45$$26);
					ZEPHIR_CONCAT_SVS(_45$$26, "(", k1, ")");
					ZEPHIR_CPY_WRT(k1, _45$$26);
				}
				ZEPHIR_INIT_LNVAR(_46$$25);
				ZEPHIR_CONCAT_VVSVS(_46$$25, k1, tmp, " IN (", v, ")");
				zephir_array_append(&ws, _46$$25, PH_SEPARATE, "nc/db/dbabstract.zep", 604);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "raw")) {
				ZEPHIR_INIT_LNVAR(_47$$27);
				ZEPHIR_CONCAT_SVS(_47$$27, "(", v, ")");
				zephir_array_append(&ws, _47$$27, PH_SEPARATE, "nc/db/dbabstract.zep", 608);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "expression")) {
				_48$$28 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_48$$28)) {
					_48$$28 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_48$$28)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid expression", "nc/db/dbabstract.zep", 612);
					return;
				}
				ZEPHIR_INIT_NVAR(_49$$28);
				ZEPHIR_INIT_NVAR(_50$$28);
				zephir_create_array(_50$$28, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_51$$28);
				ZVAL_STRING(_51$$28, "%", 1);
				zephir_array_fast_append(_50$$28, _51$$28);
				ZEPHIR_INIT_NVAR(_51$$28);
				ZVAL_STRING(_51$$28, "?", 1);
				zephir_array_fast_append(_50$$28, _51$$28);
				ZEPHIR_INIT_NVAR(_52$$28);
				zephir_create_array(_52$$28, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_51$$28);
				ZVAL_STRING(_51$$28, "%%", 1);
				zephir_array_fast_append(_52$$28, _51$$28);
				ZEPHIR_INIT_NVAR(_51$$28);
				ZVAL_STRING(_51$$28, "%s", 1);
				zephir_array_fast_append(_52$$28, _51$$28);
				ZEPHIR_MAKE_REF(v);
				ZEPHIR_CALL_FUNCTION(&_53$$28, "array_shift", &_4, 6, v);
				ZEPHIR_UNREF(v);
				zephir_check_call_status();
				zephir_get_strval(_54$$28, _53$$28);
				zephir_fast_str_replace(&_49$$28, _50$$28, _52$$28, _54$$28 TSRMLS_CC);
				zephir_get_strval(_55$$28, _49$$28);
				ZEPHIR_CPY_WRT(tmp, _55$$28);
				if (unlikely(zephir_fast_strlen_ev(tmp) > 0)) {
					ZEPHIR_INIT_NVAR(_57$$30);
					zephir_create_array(_57$$30, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_57$$30, this_ptr);
					ZEPHIR_INIT_NVAR(_58$$30);
					ZVAL_STRING(_58$$30, "quote", 1);
					zephir_array_fast_append(_57$$30, _58$$30);
					ZEPHIR_CALL_FUNCTION(&_59$$30, "array_map", &_39, 7, _57$$30, v);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_60$$30, "vsprintf", &_61, 8, tmp, _59$$30);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_62$$30);
					ZEPHIR_CONCAT_SVS(_62$$30, "(", _60$$30, ")");
					zephir_array_append(&ws, _62$$30, PH_SEPARATE, "nc/db/dbabstract.zep", 617);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "and")) {
				_63$$31 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_63$$31)) {
					_63$$31 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_63$$31)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid and", "nc/db/dbabstract.zep", 623);
					return;
				}
				ZEPHIR_INIT_NVAR(_65$$31);
				ZVAL_STRING(_65$$31, " AND ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_64$$31, this_ptr, "wheresql", &_66, 9, v, _65$$31);
				zephir_check_temp_parameter(_65$$31);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_67$$31);
				ZEPHIR_CONCAT_SVS(_67$$31, "(", _64$$31, ")");
				zephir_array_append(&ws, _67$$31, PH_SEPARATE, "nc/db/dbabstract.zep", 625);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "or")) {
				_68$$33 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_68$$33)) {
					_68$$33 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_68$$33)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid or", "nc/db/dbabstract.zep", 629);
					return;
				}
				ZEPHIR_INIT_NVAR(_70$$33);
				ZVAL_STRING(_70$$33, " OR ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_69$$33, this_ptr, "wheresql", &_66, 9, v, _70$$33);
				zephir_check_temp_parameter(_70$$33);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_71$$33);
				ZEPHIR_CONCAT_SVS(_71$$33, "(", _69$$33, ")");
				zephir_array_append(&ws, _71$$33, PH_SEPARATE, "nc/db/dbabstract.zep", 631);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "xor")) {
				_72$$35 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_72$$35)) {
					_72$$35 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_72$$35)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid xor", "nc/db/dbabstract.zep", 635);
					return;
				}
				ZEPHIR_INIT_NVAR(_74$$35);
				ZVAL_STRING(_74$$35, " XOR ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_73$$35, this_ptr, "wheresql", &_66, 9, v, _74$$35);
				zephir_check_temp_parameter(_74$$35);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_75$$35);
				ZEPHIR_CONCAT_SVS(_75$$35, "(", _73$$35, ")");
				zephir_array_append(&ws, _75$$35, PH_SEPARATE, "nc/db/dbabstract.zep", 637);
				break;
			}
			ZEPHIR_INIT_NVAR(_76$$37);
			object_init_ex(_76$$37, nc_db_exception_ce);
			ZEPHIR_INIT_LNVAR(_77$$37);
			ZEPHIR_CONCAT_SV(_77$$37, "Invalid k2: ", k2);
			ZEPHIR_CALL_METHOD(NULL, _76$$37, "__construct", &_78, 2, _77$$37);
			zephir_check_call_status();
			zephir_throw_exception_debug(_76$$37, "nc/db/dbabstract.zep", 641 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	}
	zephir_fast_join(return_value, sep, ws TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, whereMultipleInSql) {

	zend_bool _8$$4;
	HashTable *_6;
	HashPosition _5;
	long c = 0;
	zephir_fcall_cache_entry *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *columns_param = NULL, *values_param = NULL, *isNot_param = NULL, *k = NULL, *v = NULL, *vs = NULL, *quoter = NULL, _0, *_1 = NULL, *_4 = NULL, **_7, *_2$$3, *_11$$4 = NULL, *_12$$4 = NULL, *_14$$4 = NULL, *_9$$5 = NULL, *_10$$5 = NULL;
	zval *columns = NULL, *isNot = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &columns_param, &values_param, &isNot_param);

	zephir_get_strval(columns, columns_param);
	zephir_get_arrval(values, values_param);
	if (!isNot_param) {
		ZEPHIR_INIT_VAR(isNot);
		ZVAL_STRING(isNot, "", 1);
	} else {
		zephir_get_strval(isNot, isNot_param);
	}


	ZEPHIR_INIT_VAR(vs);
	array_init(vs);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, ",", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "substr_count", NULL, 10, columns, &_0);
	zephir_check_call_status();
	c = (1 + zephir_get_intval(_1));
	if (unlikely(c < 2)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid multiple in columns: ", columns);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "nc/db/dbabstract.zep", 655 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(quoter);
	zephir_create_array(quoter, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(quoter, this_ptr);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "quote", 1);
	zephir_array_fast_append(quoter, _4);
	zephir_is_iterable(values, &_6, &_5, 0, 0, "nc/db/dbabstract.zep", 667);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(k, _6, _5);
		ZEPHIR_GET_HVALUE(v, _7);
		_8$$4 = Z_TYPE_P(v) != IS_ARRAY;
		if (!(_8$$4)) {
			_8$$4 = zephir_fast_count_int(v TSRMLS_CC) != 2;
		}
		if (unlikely(_8$$4)) {
			ZEPHIR_INIT_NVAR(_9$$5);
			object_init_ex(_9$$5, nc_db_exception_ce);
			ZEPHIR_INIT_LNVAR(_10$$5);
			ZEPHIR_CONCAT_SV(_10$$5, "Invalid multiple in value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _9$$5, "__construct", NULL, 2, _10$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$5, "nc/db/dbabstract.zep", 662 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_11$$4);
		ZEPHIR_CALL_FUNCTION(&_12$$4, "array_map", &_13, 7, quoter, v);
		zephir_check_call_status();
		zephir_fast_join_str(_11$$4, SL(", "), _12$$4 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_14$$4);
		ZEPHIR_CONCAT_SVS(_14$$4, "(", _11$$4, ")");
		zephir_array_append(&vs, _14$$4, PH_SEPARATE, "nc/db/dbabstract.zep", 664);
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_fast_join_str(_4, SL(", "), vs TSRMLS_CC);
	ZEPHIR_CONCAT_SVSVSVS(return_value, "(", columns, ")", isNot, " in (", _4, ")");
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, paginationSql) {

}

PHP_METHOD(Nc_Db_DbAbstract, randomOrderSql) {

}

PHP_METHOD(Nc_Db_DbAbstract, tryToBegin) {

}

PHP_METHOD(Nc_Db_DbAbstract, tryToCommit) {

}

PHP_METHOD(Nc_Db_DbAbstract, tryToRollback) {

}

PHP_METHOD(Nc_Db_DbAbstract, nextFlag) {

	long flag = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pre_param = NULL, *_0, *_1, _2, _3;
	zval *pre = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &pre_param);

	if (!pre_param) {
		ZEPHIR_INIT_VAR(pre);
		ZVAL_STRING(pre, "", 1);
	} else {
		zephir_get_strval(pre, pre_param);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("nextFlag"), PH_NOISY_CC);
	flag = zephir_get_intval(_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, (flag + 1));
	zephir_update_property_this(this_ptr, SL("nextFlag"), _1 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "%s%d", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, flag);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 1, &_2, pre, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

