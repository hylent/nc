
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


ZEPHIR_INIT_CLASS(Nc_Db_Query_Pgsql) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db\\Query, Pgsql, nc, db_query_pgsql, nc_db_query_dbqueryadapter_ce, nc_db_query_pgsql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Query_Pgsql, insert) {

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
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "nc/db/query/pgsql.zep", 17);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		zephir_array_append(&ks, k, PH_SEPARATE, "nc/db/query/pgsql.zep", 13);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, ":", k);
		zephir_array_append(&vs, _4, PH_SEPARATE, "nc/db/query/pgsql.zep", 14);
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

PHP_METHOD(Nc_Db_Query_Pgsql, getSelectAsString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7, *_8, *_9;
	zval *s;

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
		ZEPHIR_CONCAT_SVSV(_9, " limit ", _7, " offset ", _8);
		zephir_concat_self(&s, _9 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_Query_Pgsql, selectAndCount) {

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

PHP_METHOD(Nc_Db_Query_Pgsql, buildOrderBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		RETURN_MM_STRING(" order by random()", 1);
	}
	ZEPHIR_RETURN_CALL_PARENT(nc_db_query_pgsql_ce, this_ptr, "buildorderby", &_1);
	zephir_check_call_status();
	RETURN_MM();

}

