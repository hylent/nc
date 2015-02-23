
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

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *returningId = NULL, *sql = NULL, *_9;
	zval *data_param = NULL, *returningId_param = NULL, *k = NULL, *ks, *vs, *_0, **_3, *_4 = NULL, *_5, *_6, *_7, *_8 = NULL, *_10, *_11 = NULL;
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
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, ":", k);
		zephir_array_append(&vs, _4, PH_SEPARATE, "nc/db/query/oracle.zep", 14);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_join_str(_6, SL(", "), ks TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_fast_join_str(_7, SL(", "), vs TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_SVSVSVS(_4, "insert into ", _5, " (", _6, ") values (", _7, ")");
	zephir_get_strval(sql, _4);
	if (zephir_fast_strlen_ev(returningId) > 0) {
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SV(_9, " returning ", returningId);
		zephir_concat_self(&sql, _9 TSRMLS_CC);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_LONG(_11, (2 | 0x30));
		ZEPHIR_RETURN_CALL_METHOD(_10, "query", NULL, _11, sql, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, 2);
	ZEPHIR_RETURN_CALL_METHOD(_10, "query", NULL, _11, sql, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_Oracle, replace) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_9;
	HashPosition _1, _8;
	zval *sql, *_0 = NULL, *_14 = NULL, *_16 = NULL, *_18 = NULL, *_20 = NULL, *_22 = NULL;
	zval *data_param = NULL, *primaryKey = NULL, *pks = NULL, *k = NULL, *a, *b, *ks, *vs, *kvs, **_3, *_4 = NULL, *_5 = NULL, *_7 = NULL, **_10, *_11 = NULL, *_12, *_13, *_15, *_17, *_19, *_21, *_23, *_24;
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
	ZVAL_STRING(sql, "", 1);


	if (Z_TYPE_P(primaryKey) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(pks, primaryKey);
	} else {
		ZEPHIR_INIT_NVAR(pks);
		array_init(pks);
		zephir_get_strval(_0, primaryKey);
		zephir_array_append(&pks, _0, PH_SEPARATE, "nc/db/query/oracle.zep", 36);
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
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, nc_db_query_exception_ce);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SV(_5, "Cannot find pk value in replacing data: ", k);
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4, "nc/db/query/oracle.zep", 44 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SVSV(_5, ":", k, " as ", k);
		zephir_array_append(&a, _5, PH_SEPARATE, "nc/db/query/oracle.zep", 46);
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SVSV(_7, "a.", k, " = b.", k);
		zephir_array_append(&b, _7, PH_SEPARATE, "nc/db/query/oracle.zep", 47);
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_array_keys(_4, data TSRMLS_CC);
	zephir_is_iterable(_4, &_9, &_8, 0, 0, "nc/db/query/oracle.zep", 56);
	for (
	  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zephir_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HVALUE(k, _10);
		zephir_array_append(&ks, k, PH_SEPARATE, "nc/db/query/oracle.zep", 51);
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SV(_7, ":", k);
		zephir_array_append(&vs, _7, PH_SEPARATE, "nc/db/query/oracle.zep", 52);
		ZEPHIR_INIT_LNVAR(_11);
		ZEPHIR_CONCAT_VSV(_11, k, " = :", k);
		zephir_array_append(&kvs, _11, PH_SEPARATE, "nc/db/query/oracle.zep", 53);
	}
	zephir_concat_self_str(&sql, "merge into ", sizeof("merge into ")-1 TSRMLS_CC);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	zephir_concat_self(&sql, _12 TSRMLS_CC);
	zephir_concat_self_str(&sql, " a using (select ", sizeof(" a using (select ")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	zephir_fast_join_str(_13, SL(", "), a TSRMLS_CC);
	zephir_get_strval(_14, _13);
	zephir_concat_self(&sql, _14 TSRMLS_CC);
	zephir_concat_self_str(&sql, " from dual where rownum < 2) b on (", sizeof(" from dual where rownum < 2) b on (")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_15);
	zephir_fast_join_str(_15, SL(" and "), b TSRMLS_CC);
	zephir_get_strval(_16, _15);
	zephir_concat_self(&sql, _16 TSRMLS_CC);
	zephir_concat_self_str(&sql, ") when matched then update set ", sizeof(") when matched then update set ")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_17);
	zephir_fast_join_str(_17, SL(", "), kvs TSRMLS_CC);
	zephir_get_strval(_18, _17);
	zephir_concat_self(&sql, _18 TSRMLS_CC);
	zephir_concat_self_str(&sql, " when not matched then insert (", sizeof(" when not matched then insert (")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_19);
	zephir_fast_join_str(_19, SL(", "), ks TSRMLS_CC);
	zephir_get_strval(_20, _19);
	zephir_concat_self(&sql, _20 TSRMLS_CC);
	zephir_concat_self_str(&sql, ") values (", sizeof(") values (")-1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_21);
	zephir_fast_join_str(_21, SL(", "), vs TSRMLS_CC);
	zephir_get_strval(_22, _21);
	zephir_concat_self(&sql, _22 TSRMLS_CC);
	zephir_concat_self_str(&sql, ")", sizeof(")")-1 TSRMLS_CC);
	_23 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_24);
	ZVAL_LONG(_24, 2);
	ZEPHIR_RETURN_CALL_METHOD(_23, "query", NULL, _24, sql, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_Oracle, getSelectAsString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, *_9;
	zval *s = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(s);
	ZVAL_STRING(s, "select ", 1);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildfield", NULL);
	zephir_check_call_status();
	zephir_concat_self(&s, _0 TSRMLS_CC);
	zephir_concat_self_str(&s, " from ", sizeof(" from ")-1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildtableandjoin", NULL);
	zephir_check_call_status();
	zephir_concat_self(&s, _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildwhere", NULL);
	zephir_check_call_status();
	zephir_concat_self(&s, _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "buildgroupby", NULL);
	zephir_check_call_status();
	zephir_concat_self(&s, _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "buildhaving", NULL);
	zephir_check_call_status();
	zephir_concat_self(&s, _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "buildorderby", NULL);
	zephir_check_call_status();
	zephir_concat_self(&s, _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("pageSize"), PH_NOISY_CC);
	if (ZEPHIR_GT_LONG(_6, 0)) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("pageSize"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("rowOffset"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SVSVSV(_9, "select * from (select a.*, rownum r from (", s, ") a where rownum <= ", _7, ") b where r > ", _8);
		zephir_get_strval(s, _9);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_Query_Oracle, selectAndCount) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2, *_3, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL;
	long numRows;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildtableandjoin", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildwhere", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVV(_2, "select count(*) from ", _0, _1);
	zephir_get_strval(sql, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, (1 | 0x30));
	ZEPHIR_CALL_METHOD(&_4, _3, "query", NULL, _5, sql);
	zephir_check_call_status();
	numRows = zephir_get_intval(_4);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, numRows);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setnumrows", NULL, _5);
	zephir_check_call_status();
	if (numRows > 0) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("db"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "getselectasstring", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, (1 | 0x10));
		ZEPHIR_RETURN_CALL_METHOD(_6, "query", NULL, _5, _7);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Query_Oracle, buildOrderBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		RETURN_MM_STRING(" order by dbms_random.value()", 1);
	}
	ZEPHIR_RETURN_CALL_PARENT(nc_db_query_oracle_ce, this_ptr, "buildorderby", &_1);
	zephir_check_call_status();
	RETURN_MM();

}

