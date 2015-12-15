
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
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_Oci8) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, Oci8, nc, db_oci8, nc_db_dbabstract_ce, nc_db_oci8_method_entry, 0);

	zend_declare_property_null(nc_db_oci8_ce, SL("oci"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Oci8, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dsn_param = NULL, *user_param = NULL, *passwd_param = NULL, *oci = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2$$4;
	zval *dsn = NULL, *user = NULL, *passwd = NULL, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dsn_param, &user_param, &passwd_param);

	zephir_get_strval(dsn, dsn_param);
	zephir_get_strval(user, user_param);
	zephir_get_strval(passwd, passwd_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "oci8", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 19, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Missing extension: oci8", "nc/db/oci8.zep", 12);
		return;
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "utf8", 0);
	ZEPHIR_CALL_FUNCTION(&oci, "oci_connect", NULL, 40, user, passwd, dsn, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(oci))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot connect: ", dsn);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/db/oci8.zep", 17 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("oci"), oci TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Oci8, getInternalHandler) {

	

	RETURN_MEMBER(this_ptr, "oci");

}

PHP_METHOD(Nc_Db_Oci8, quote) {

	zval *value_param = NULL, *_0, _1, _2;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "'", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "''", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, value TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "'", _0, "'");
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci8, queryAndFetch) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool success = 0, _13$$7, _21$$15, _22$$15, _23$$18, _24$$18;
	double startMt = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_16 = NULL, *_18 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql = NULL, *profiledQuery = NULL, *_11 = NULL;
	zval *fetch_param = NULL, *sql_param = NULL, *params_param = NULL, *statement = NULL, *k = NULL, *v = NULL, *err = NULL, *errMessage = NULL, *queryMode = NULL, *result = NULL, *resultRow = NULL, *resultCell = NULL, *_0, *_1, *_7, *_8 = NULL, *_10 = NULL, _25, *_26 = NULL, *_27, **_4$$3, *_5$$4 = NULL, *_12$$7, *_14$$7, *_15$$7, *_17$$11 = NULL, _19$$13, _20$$15;
	long fetch;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &fetch_param, &sql_param, &params_param);

	fetch = zephir_get_intval(fetch_param);
	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	startMt = zephir_get_doubleval(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&statement, "oci_parse", NULL, 41, _1, sql);
	zephir_check_call_status();
	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		zephir_is_iterable(params, &_3$$3, &_2$$3, 0, 0, "nc/db/oci8.zep", 48);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(k, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(v, _4$$3);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, ":", k);
			ZEPHIR_MAKE_REF(v);
			ZEPHIR_CALL_FUNCTION(NULL, "oci_bind_by_name", &_6, 42, statement, _5$$4, v);
			ZEPHIR_UNREF(v);
			zephir_check_call_status();
		}
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(queryMode);
	if (zephir_is_true(_7)) {
		ZVAL_LONG(queryMode, 0);
	} else {
		ZVAL_LONG(queryMode, 32);
	}
	ZEPHIR_CALL_FUNCTION(&_8, "oci_execute", NULL, 43, statement, queryMode);
	zephir_check_call_status();
	success = zephir_get_boolval(_8);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_DOUBLE(_10, startMt);
	ZEPHIR_CALL_CE_STATIC(&_8, nc_db_dbabstract_ce, "profiledquery", &_9, 22, sql, params, _10);
	zephir_check_call_status();
	zephir_get_strval(_11, _8);
	ZEPHIR_CPY_WRT(profiledQuery, _11);
	zephir_update_property_array_append(this_ptr, SL("queries"), profiledQuery TSRMLS_CC);
	if (unlikely(!success)) {
		_12$$7 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&err, "oci_error", NULL, 44, _12$$7);
		zephir_check_call_status();
		_13$$7 = Z_TYPE_P(err) != IS_ARRAY;
		if (!(_13$$7)) {
			ZEPHIR_OBS_VAR(errMessage);
			_13$$7 = !(zephir_array_isset_string_fetch(&errMessage, err, SS("message"), 0 TSRMLS_CC));
		}
		if (_13$$7) {
			ZEPHIR_INIT_NVAR(errMessage);
			ZVAL_STRING(errMessage, "Unknown Error", 1);
		}
		ZEPHIR_INIT_VAR(_14$$7);
		object_init_ex(_14$$7, nc_db_queryexception_ce);
		ZEPHIR_INIT_VAR(_15$$7);
		ZEPHIR_CONCAT_VSV(_15$$7, errMessage, " [SQL] ", profiledQuery);
		ZEPHIR_CALL_METHOD(NULL, _14$$7, "__construct", NULL, 2, _15$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_14$$7, "nc/db/oci8.zep", 66 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (fetch == 0) {
			RETURN_MM_NULL();
		}
		if (fetch == 1) {
			ZEPHIR_INIT_VAR(result);
			array_init(result);
			ZEPHIR_INIT_NVAR(queryMode);
			ZVAL_LONG(queryMode, ((4 + 8) + 1));
			while (1) {
				ZEPHIR_CALL_FUNCTION(&resultRow, "oci_fetch_array", &_16, 45, statement, queryMode);
				zephir_check_call_status();
				if (!(zephir_is_true(resultRow))) {
					break;
				}
				ZEPHIR_CALL_FUNCTION(&_17$$11, "array_change_key_case", &_18, 46, resultRow);
				zephir_check_call_status();
				zephir_array_append(&result, _17$$11, PH_SEPARATE, "nc/db/oci8.zep", 81);
			}
			RETURN_CCTOR(result);
		}
		if (fetch == 2) {
			ZEPHIR_SINIT_VAR(_19$$13);
			ZVAL_LONG(&_19$$13, ((4 + 8) + 1));
			ZEPHIR_CALL_FUNCTION(&resultRow, "oci_fetch_array", &_16, 45, statement, &_19$$13);
			zephir_check_call_status();
			if (zephir_is_true(resultRow)) {
				ZEPHIR_RETURN_CALL_FUNCTION("array_change_key_case", &_18, 46, resultRow);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETURN_MM_NULL();
		}
		if (fetch == 3) {
			ZEPHIR_SINIT_VAR(_20$$15);
			ZVAL_LONG(&_20$$15, ((4 + 8) + 2));
			ZEPHIR_CALL_FUNCTION(&resultRow, "oci_fetch_array", &_16, 45, statement, &_20$$15);
			zephir_check_call_status();
			_21$$15 = zephir_is_true(resultRow);
			if (_21$$15) {
				_21$$15 = Z_TYPE_P(resultRow) == IS_ARRAY;
			}
			_22$$15 = _21$$15;
			if (_22$$15) {
				ZEPHIR_OBS_VAR(resultCell);
				_22$$15 = zephir_array_isset_long_fetch(&resultCell, resultRow, 0, 0 TSRMLS_CC);
			}
			if (_22$$15) {
				RETURN_CCTOR(resultCell);
			}
			RETURN_MM_STRING("", 1);
		}
		if (fetch == 4) {
			ZEPHIR_INIT_NVAR(result);
			array_init(result);
			ZEPHIR_INIT_NVAR(queryMode);
			ZVAL_LONG(queryMode, ((4 + 8) + 2));
			while (1) {
				ZEPHIR_CALL_FUNCTION(&resultRow, "oci_fetch_array", &_16, 45, statement, queryMode);
				zephir_check_call_status();
				_23$$18 = !zephir_is_true(resultRow);
				if (!(_23$$18)) {
					_23$$18 = Z_TYPE_P(resultRow) != IS_ARRAY;
				}
				_24$$18 = _23$$18;
				if (!(_24$$18)) {
					ZEPHIR_OBS_NVAR(resultCell);
					_24$$18 = !(zephir_array_isset_long_fetch(&resultCell, resultRow, 0, 0 TSRMLS_CC));
				}
				if (_24$$18) {
					break;
				}
				zephir_array_append(&result, resultCell, PH_SEPARATE, "nc/db/oci8.zep", 107);
			}
			RETURN_CCTOR(result);
		}
	} while(0);

	ZEPHIR_INIT_NVAR(_10);
	object_init_ex(_10, nc_db_exception_ce);
	ZEPHIR_SINIT_VAR(_25);
	ZVAL_LONG(&_25, fetch);
	ZEPHIR_CALL_FUNCTION(&_26, "strval", NULL, 23, &_25);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_27);
	ZEPHIR_CONCAT_SV(_27, "Invalid fetch mode: ", _26);
	ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, 2, _27);
	zephir_check_call_status();
	zephir_throw_exception_debug(_10, "nc/db/oci8.zep", 112 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Db_Oci8, parsePagination) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, skip;
	zval *query_param = NULL, *limit_param = NULL, *skip_param = NULL, *_0 = NULL, *_1 = NULL, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL, *_8 = NULL, *_10 = NULL, _12;
	zval *query = NULL, *s = NULL, *t1 = NULL, *t2 = NULL, *r3 = NULL, *_2 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &query_param, &limit_param, &skip_param);

	zephir_get_strval(query, query_param);
	limit = zephir_get_intval(limit_param);
	skip = zephir_get_intval(skip_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "t", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "nextflag", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_get_strval(_2, _0);
	ZEPHIR_CPY_WRT(t1, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "SELECT %s.* FROM (%s) %s WHERE rownum <= %d", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, limit);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_6, 1, &_3, t1, query, t1, &_4);
	zephir_check_call_status();
	zephir_get_strval(_7, _5);
	ZEPHIR_CPY_WRT(s, _7);
	if (skip == 0) {
		RETURN_CTOR(s);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "t", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "nextflag", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_get_strval(_9, _8);
	ZEPHIR_CPY_WRT(t2, _9);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "r", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "nextflag", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_get_strval(_11, _10);
	ZEPHIR_CPY_WRT(r3, _11);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "SELECT * FROM (SELECT %s.*, rownum %s FROM (%s) %s WHERE rownum <= %d) %s WHERE %s > %d", 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, limit);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, skip);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_6, 1, &_3, t1, r3, query, t1, &_4, t2, r3, &_12);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci8, parseRandomOrder) {

	

	RETURN_STRING("dbms_random.value()", 1);

}

PHP_METHOD(Nc_Db_Oci8, tryToBegin) {

	

	RETURN_BOOL(1);

}

PHP_METHOD(Nc_Db_Oci8, tryToCommit) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_commit", NULL, 47, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci8, tryToRollback) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_rollback", NULL, 48, _0);
	zephir_check_call_status();
	RETURN_MM();

}

