
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Db_Query_Oracle) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db\\Query, Oracle, nc, db_query_oracle, nc_db_query_dbqueryabstract_ce, nc_db_query_oracle_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Query_Oracle, insert) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *returningId = NULL, *sql = NULL, *_10$$4;
	zval *data_param = NULL, *returningId_param = NULL, *k = NULL, *ks = NULL, *vs = NULL, *_0, **_3, *_5, *_6, *_7, *_8, *_9 = NULL, *_13, *_14, *_4$$3 = NULL, *_11$$4, *_12$$4;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &returningId_param);

	zephir_get_arrval(data, data_param);
	if (!returningId_param) {
		ZEPHIR_INIT_VAR(returningId);
		ZVAL_STRING(returningId, "", 1);
	} else {
		zephir_get_strval(returningId, returningId_param);
	}


	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(vs);
	array_init(vs);
	ZEPHIR_INIT_VAR(_0);
	zephir_array_keys(_0, data TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/query/oracle.zep", 17);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		zephir_array_append(&ks, k, PH_SEPARATE, "nc/db/query/oracle.zep", 13);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, ":", k);
		zephir_array_append(&vs, _4$$3, PH_SEPARATE, "nc/db/query/oracle.zep", 14);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_join_str(_6, SL(", "), ks TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_fast_join_str(_7, SL(", "), vs TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SVSVSVS(_8, "insert into ", _5, " (", _6, ") values (", _7, ")");
	zephir_get_strval(sql, _8);
	if (zephir_fast_strlen_ev(returningId) > 0) {
		ZEPHIR_INIT_VAR(_10$$4);
		ZEPHIR_CONCAT_SV(_10$$4, " returning ", returningId);
		zephir_concat_self(&sql, _10$$4 TSRMLS_CC);
		_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_12$$4);
		ZVAL_LONG(_12$$4, (2 | 0x30));
		ZEPHIR_RETURN_CALL_METHOD(_11$$4, "query", NULL, 0, _12$$4, sql, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_LONG(_14, 2);
	ZEPHIR_RETURN_CALL_METHOD(_13, "query", NULL, 0, _14, sql, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_Oracle, replace) {

	HashTable *_2, *_11;
	HashPosition _1, _10;
	zval *sql, *_17 = NULL, *_19 = NULL, *_21 = NULL, *_23 = NULL, *_25 = NULL, *_0$$4 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *primaryKey = NULL, *pks = NULL, *k = NULL, *a = NULL, *b = NULL, *ks = NULL, *vs = NULL, *kvs = NULL, **_3, *_9, **_12, *_15, *_16, *_18, *_20, *_22, *_24, *_26, *_27, *_4$$7 = NULL, *_5$$7 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_13$$8 = NULL, *_14$$8 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &primaryKey);

	zephir_get_arrval(data, data_param);
	if (!primaryKey) {
		ZEPHIR_INIT_VAR(primaryKey);
		ZVAL_STRING(primaryKey, "id", 1);
	}


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	ZEPHIR_INIT_VAR(b);
	array_init(b);
	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(vs);
	array_init(vs);
	ZEPHIR_INIT_VAR(kvs);
	array_init(kvs);
	ZEPHIR_INIT_VAR(sql);
	ZVAL_EMPTY_STRING(sql);
	if (Z_TYPE_P(primaryKey) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(pks, primaryKey);
	} else {
		ZEPHIR_INIT_NVAR(pks);
		array_init(pks);
		zephir_get_strval(_0$$4, primaryKey);
		zephir_array_append(&pks, _0$$4, PH_SEPARATE, "nc/db/query/oracle.zep", 36);
	}
	zephir_is_iterable(pks, &_2, &_1, 0, 0, "nc/db/query/oracle.zep", 50);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		if (unlikely(Z_TYPE_P(k) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_query_exception_ce, "Invalid pk type, string or string array required", "nc/db/query/oracle.zep", 41);
			return;
		}
		if (unlikely(!(zephir_array_isset(data, k)))) {
			ZEPHIR_INIT_NVAR(_4$$7);
			object_init_ex(_4$$7, nc_db_query_exception_ce);
			ZEPHIR_INIT_LNVAR(_5$$7);
			ZEPHIR_CONCAT_SV(_5$$7, "Cannot find pk value in replacing data: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4$$7, "__construct", &_6, 2, _5$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$7, "nc/db/query/oracle.zep", 44 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_LNVAR(_7$$5);
		ZEPHIR_CONCAT_SVSV(_7$$5, ":", k, " as ", k);
		zephir_array_append(&a, _7$$5, PH_SEPARATE, "nc/db/query/oracle.zep", 46);
		ZEPHIR_INIT_LNVAR(_8$$5);
		ZEPHIR_CONCAT_SVSV(_8$$5, "a.", k, " = b.", k);
		zephir_array_append(&b, _8$$5, PH_SEPARATE, "nc/db/query/oracle.zep", 47);
	}
	ZEPHIR_INIT_VAR(_9);
	zephir_array_keys(_9, data TSRMLS_CC);
	zephir_is_iterable(_9, &_11, &_10, 0, 0, "nc/db/query/oracle.zep", 56);
	for (
	  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
	  ; zephir_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HVALUE(k, _12);
		zephir_array_append(&ks, k, PH_SEPARATE, "nc/db/query/oracle.zep", 51);
		ZEPHIR_INIT_LNVAR(_13$$8);
		ZEPHIR_CONCAT_SV(_13$$8, ":", k);
		zephir_array_append(&vs, _13$$8, PH_SEPARATE, "nc/db/query/oracle.zep", 52);
		ZEPHIR_INIT_LNVAR(_14$$8);
		ZEPHIR_CONCAT_VSV(_14$$8, k, " = :", k);
		zephir_array_append(&kvs, _14$$8, PH_SEPARATE, "nc/db/query/oracle.zep", 53);
	}
	zephir_concat_self_str(&sql, "merge into ", sizeof("merge into ")-1 TSRMLS_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	zephir_concat_self(&sql, _15 TSRMLS_CC);
	zephir_concat_self_str(&sql, " a using (select ", sizeof(" a using (select ")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_16);
	zephir_fast_join_str(_16, SL(", "), a TSRMLS_CC);
	zephir_get_strval(_17, _16);
	zephir_concat_self(&sql, _17 TSRMLS_CC);
	zephir_concat_self_str(&sql, " from dual where rownum < 2) b on (", sizeof(" from dual where rownum < 2) b on (")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_18);
	zephir_fast_join_str(_18, SL(" and "), b TSRMLS_CC);
	zephir_get_strval(_19, _18);
	zephir_concat_self(&sql, _19 TSRMLS_CC);
	zephir_concat_self_str(&sql, ") when matched then update set ", sizeof(") when matched then update set ")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_20);
	zephir_fast_join_str(_20, SL(", "), kvs TSRMLS_CC);
	zephir_get_strval(_21, _20);
	zephir_concat_self(&sql, _21 TSRMLS_CC);
	zephir_concat_self_str(&sql, " when not matched then insert (", sizeof(" when not matched then insert (")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_22);
	zephir_fast_join_str(_22, SL(", "), ks TSRMLS_CC);
	zephir_get_strval(_23, _22);
	zephir_concat_self(&sql, _23 TSRMLS_CC);
	zephir_concat_self_str(&sql, ") values (", sizeof(") values (")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_24);
	zephir_fast_join_str(_24, SL(", "), vs TSRMLS_CC);
	zephir_get_strval(_25, _24);
	zephir_concat_self(&sql, _25 TSRMLS_CC);
	zephir_concat_self_str(&sql, ")", sizeof(")")-1 TSRMLS_CC);
	_26 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_27);
	ZVAL_LONG(_27, 2);
	ZEPHIR_RETURN_CALL_METHOD(_26, "query", NULL, 0, _27, sql, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_Oracle, getSelectAsString) {

	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, _9;
	zval *s;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(s);
	ZVAL_STRING(s, "select ", 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildfield", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&s, _0 TSRMLS_CC);
	zephir_concat_self_str(&s, " from ", sizeof(" from ")-1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildtableandjoin", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&s, _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildwhere", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&s, _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "buildgroupby", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&s, _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "buildhaving", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&s, _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "buildorderby", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&s, _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("pageSize"), PH_NOISY_CC);
	if (ZEPHIR_LT_LONG(_6, 1)) {
		RETURN_CTOR(s);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("pageSize"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("rowOffset"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "select * from (select a.*, rownum r from (%s) a where rownum <= %d) b where r > %d", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 6, &_9, s, _7, _8);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_Oracle, selectAndCount) {

	zval *_0 = NULL, *_1 = NULL, *_2, *_3, *_4 = NULL, *_5 = NULL, *_6$$3, *_7$$3 = NULL, *_8$$3;
	long numRows = 0;
	zval *sql = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildtableandjoin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildwhere", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVV(_2, "select count(*) from ", _0, _1);
	zephir_get_strval(sql, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, (1 | 0x30));
	ZEPHIR_CALL_METHOD(&_4, _3, "query", NULL, 0, _5, sql);
	zephir_check_call_status();
	numRows = zephir_get_intval(_4);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, numRows);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setnumrows", NULL, 0, _5);
	zephir_check_call_status();
	if (numRows > 0) {
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "getselectasstring", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$3);
		ZVAL_LONG(_8$$3, (1 | 0x10));
		ZEPHIR_RETURN_CALL_METHOD(_6$$3, "query", NULL, 0, _8$$3, _7$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_Oracle, buildOrderBy) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		RETURN_MM_STRING(" order by dbms_random.value()", 1);
	}
	ZEPHIR_RETURN_CALL_PARENT(nc_db_query_oracle_ce, this_ptr, "buildorderby", &_1, 39);
	zephir_check_call_status();
	RETURN_MM();

}

