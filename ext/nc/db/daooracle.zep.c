
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Db_DaoOracle) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, DaoOracle, nc, db_daooracle, nc_db_daoabstract_ce, nc_db_daooracle_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_DaoOracle, upsert) {

	zval _28$$14;
	zend_bool _6$$4;
	zend_string *_15, *_25$$10;
	zend_ulong _14, _24$$10;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inserts_param = NULL, *updates_param = NULL, iPre, uPre, k, kPrefixed, v, ds, cs, iks, ivs, us, params, s, _0, _4, *_5, *_13, _19, _20, _21, _22, _33, _34, _35, _36, _1$$3, _2$$3, _3$$3, _9$$4, _10$$4, _12$$4, _7$$5, _8$$5, _16$$8, _17$$8, _18$$9, *_23$$10, _30$$10, _31$$10, _32$$10, _26$$13, _27$$13, _29$$15;
	zval inserts, updates;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inserts);
	ZVAL_UNDEF(&updates);
	ZVAL_UNDEF(&iPre);
	ZVAL_UNDEF(&uPre);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&kPrefixed);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&ds);
	ZVAL_UNDEF(&cs);
	ZVAL_UNDEF(&iks);
	ZVAL_UNDEF(&ivs);
	ZVAL_UNDEF(&us);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_28$$14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &inserts_param, &updates_param);

	zephir_get_arrval(&inserts, inserts_param);
	if (!updates_param) {
		ZEPHIR_INIT_VAR(&updates);
		array_init(&updates);
	} else {
		zephir_get_arrval(&updates, updates_param);
	}


	ZEPHIR_INIT_VAR(&iPre);
	ZVAL_STRING(&iPre, "i_");
	ZEPHIR_INIT_VAR(&uPre);
	ZVAL_STRING(&uPre, "u_");
	ZEPHIR_INIT_VAR(&ds);
	array_init(&ds);
	ZEPHIR_INIT_VAR(&cs);
	array_init(&cs);
	ZEPHIR_INIT_VAR(&iks);
	array_init(&iks);
	ZEPHIR_INIT_VAR(&ivs);
	array_init(&ivs);
	ZEPHIR_INIT_VAR(&us);
	array_init(&us);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	zephir_read_property(&_0, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_fast_count_int(&_0 TSRMLS_CC) < 1)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "upsert");
		ZVAL_LONG(&_3$$3, 7);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/db/daooracle.zep", 10 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "nc/db/daooracle.zep", 22);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
	{
		ZEPHIR_INIT_NVAR(&k);
		ZVAL_COPY(&k, _5);
		ZEPHIR_OBS_NVAR(&v);
		_6$$4 = !(zephir_array_isset_fetch(&v, &inserts, &k, 0 TSRMLS_CC));
		if (!(_6$$4)) {
			_6$$4 = Z_TYPE_P(&v) == IS_NULL;
		}
		if (UNEXPECTED(_6$$4)) {
			ZEPHIR_INIT_NVAR(&_7$$5);
			object_init_ex(&_7$$5, nc_db_exception_ce);
			ZVAL_LONG(&_8$$5, 8);
			ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 3, &k, &_8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$5, "nc/db/daooracle.zep", 15 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_9$$4);
		ZVAL_STRING(&_9$$4, ":%s%s %s");
		ZEPHIR_CALL_FUNCTION(&_10$$4, "sprintf", &_11, 2, &_9$$4, &iPre, &k, &k);
		zephir_check_call_status();
		zephir_array_append(&ds, &_10$$4, PH_SEPARATE, "nc/db/daooracle.zep", 18);
		ZEPHIR_INIT_NVAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "t1.%s = t2.%s");
		ZEPHIR_CALL_FUNCTION(&_12$$4, "sprintf", &_11, 2, &_9$$4, &k, &k);
		zephir_check_call_status();
		zephir_array_append(&cs, &_12$$4, PH_SEPARATE, "nc/db/daooracle.zep", 19);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&k);
	zephir_is_iterable(&inserts, 0, "nc/db/daooracle.zep", 35);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&inserts), _14, _15, _13)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_15 != NULL) { 
			ZVAL_STR_COPY(&k, _15);
		} else {
			ZVAL_LONG(&k, _14);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _13);
		if (!(Z_TYPE_P(&k) == IS_LONG)) {
			zephir_array_append(&iks, &k, PH_SEPARATE, "nc/db/daooracle.zep", 24);
			if (Z_TYPE_P(&v) == IS_ARRAY) {
				zephir_read_property(&_16$$8, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_17$$8, &_16$$8, "expression", NULL, 0, &v);
				zephir_check_call_status();
				zephir_array_append(&ivs, &_17$$8, PH_SEPARATE, "nc/db/daooracle.zep", 26);
			} else {
				ZEPHIR_INIT_NVAR(&kPrefixed);
				ZEPHIR_CONCAT_VV(&kPrefixed, &iPre, &k);
				ZEPHIR_INIT_LNVAR(_18$$9);
				ZEPHIR_CONCAT_SV(&_18$$9, ":", &kPrefixed);
				zephir_array_append(&ivs, &_18$$9, PH_SEPARATE, "nc/db/daooracle.zep", 29);
				zephir_array_update_zval(&params, &kPrefixed, &v, PH_COPY | PH_SEPARATE);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_19, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_20);
	zephir_fast_join_str(&_20, SL(", "), &ds TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_21);
	zephir_fast_join_str(&_21, SL(" AND "), &cs TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_22);
	ZVAL_STRING(&_22, "MERGE INTO %s t1 USING (SELECT %s FROM dual WHERE rownum < 2) t2 ON (%s)");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", &_11, 2, &_22, &_19, &_20, &_21);
	zephir_check_call_status();
	if (zephir_fast_count_int(&updates TSRMLS_CC) > 0) {
		zephir_is_iterable(&updates, 0, "nc/db/daooracle.zep", 57);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&updates), _24$$10, _25$$10, _23$$10)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_25$$10 != NULL) { 
				ZVAL_STR_COPY(&k, _25$$10);
			} else {
				ZVAL_LONG(&k, _24$$10);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _23$$10);
			if (Z_TYPE_P(&k) == IS_LONG) {
				if (Z_TYPE_P(&v) == IS_ARRAY) {
					zephir_read_property(&_26$$13, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_27$$13, &_26$$13, "expression", NULL, 0, &v);
					zephir_check_call_status();
					zephir_array_append(&us, &_27$$13, PH_SEPARATE, "nc/db/daooracle.zep", 46);
				} else {
					zephir_get_strval(&_28$$14, &v);
					zephir_array_append(&us, &_28$$14, PH_SEPARATE, "nc/db/daooracle.zep", 48);
				}
			} else {
				ZEPHIR_INIT_NVAR(&kPrefixed);
				ZEPHIR_CONCAT_VV(&kPrefixed, &uPre, &k);
				ZEPHIR_INIT_LNVAR(_29$$15);
				ZEPHIR_CONCAT_VSV(&_29$$15, &k, " = :", &kPrefixed);
				zephir_array_append(&us, &_29$$15, PH_SEPARATE, "nc/db/daooracle.zep", 52);
				zephir_array_update_zval(&params, &kPrefixed, &v, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
		ZEPHIR_INIT_VAR(&_30$$10);
		zephir_fast_join_str(&_30$$10, SL(", "), &us TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_31$$10);
		ZVAL_STRING(&_31$$10, " WHEN MATCHED THEN UPDATE SET %s");
		ZEPHIR_CALL_FUNCTION(&_32$$10, "sprintf", &_11, 2, &_31$$10, &_30$$10);
		zephir_check_call_status();
		zephir_concat_self(&s, &_32$$10 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(&_22);
	zephir_fast_join_str(&_22, SL(", "), &iks TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_33);
	zephir_fast_join_str(&_33, SL(", "), &ivs TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_34);
	ZVAL_STRING(&_34, " WHEN NOT MATCHED THEN INSERT (%s) VALUES (%s)");
	ZEPHIR_CALL_FUNCTION(&_35, "sprintf", &_11, 2, &_34, &_22, &_33);
	zephir_check_call_status();
	zephir_concat_self(&s, &_35 TSRMLS_CC);
	zephir_read_property(&_36, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_36, "execute", NULL, 0, &s, &params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoOracle, updateTop) {

	zval _5$$6;
	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *updates_param = NULL, *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, k, v, us, pks, s, *_0, _7, _8, _9, _10, _11, _12, _13, _14, _3$$5, _4$$5, _6$$7;
	zval updates;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&updates);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&us);
	ZVAL_UNDEF(&pks);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &updates_param, &where, &order, &limit_param);

	zephir_get_arrval(&updates, updates_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}
	if (!order) {
		order = &order_sub;
		order = &__$null;
	}
	if (!limit_param) {
		limit = 1;
	} else {
		limit = zephir_get_intval(limit_param);
	}


	ZEPHIR_INIT_VAR(&us);
	array_init(&us);
	zephir_is_iterable(&updates, 1, "nc/db/daooracle.zep", 89);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&updates), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		if (Z_TYPE_P(&k) == IS_LONG) {
			if (Z_TYPE_P(&v) == IS_ARRAY) {
				zephir_read_property(&_3$$5, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_4$$5, &_3$$5, "expression", NULL, 0, &v);
				zephir_check_call_status();
				zephir_array_append(&us, &_4$$5, PH_SEPARATE, "nc/db/daooracle.zep", 79);
			} else {
				zephir_get_strval(&_5$$6, &v);
				zephir_array_append(&us, &_5$$6, PH_SEPARATE, "nc/db/daooracle.zep", 81);
			}
			zephir_array_unset(&updates, &k, PH_SEPARATE);
		} else {
			ZEPHIR_INIT_LNVAR(_6$$7);
			ZEPHIR_CONCAT_VSV(&_6$$7, &k, " = :", &k);
			zephir_array_append(&us, &_6$$7, PH_SEPARATE, "nc/db/daooracle.zep", 85);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_7, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pks);
	zephir_fast_join_str(&pks, SL(", "), &_7 TSRMLS_CC);
	zephir_read_property(&_8, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	zephir_fast_join_str(&_9, SL(", "), &us TSRMLS_CC);
	zephir_read_property(&_10, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "makeorder", NULL, 0, order);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "UPDATE %s SET %s WHERE (%s) IN (SELECT %s FROM %s%s%s where rownum <= %d)");
	ZVAL_LONG(&_14, limit);
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_13, &_8, &_9, &pks, &pks, &_10, &_11, &_12, &_14);
	zephir_check_call_status();
	zephir_read_property(&_14, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_14, "execute", NULL, 0, &s, &updates);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoOracle, deleteTop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, pks, s, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&pks);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &where, &order, &limit_param);

	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}
	if (!order) {
		order = &order_sub;
		order = &__$null;
	}
	if (!limit_param) {
		limit = 1;
	} else {
		limit = zephir_get_intval(limit_param);
	}


	zephir_read_property(&_0, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pks);
	zephir_fast_join_str(&pks, SL(", "), &_0 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "makeorder", NULL, 0, order);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "DELETE FROM %s WHERE (%s) IN (SELECT %s FROM %s%s%s where rownum <= %d)");
	ZVAL_LONG(&_6, limit);
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_5, &_1, &pks, &pks, &_2, &_3, &_4, &_6);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_6, "execute", NULL, 0, &s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoOracle, makeRandomOrder) {

	zval *this_ptr = getThis();


	RETURN_STRING("dbms_random.value()");

}

PHP_METHOD(Nc_Db_DaoOracle, makePagination) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	long limit, skip;
	zval *sql_param = NULL, *limit_param = NULL, *skip_param = NULL, _0$$3, _1$$3, _3, _4, _5;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &sql_param, &limit_param, &skip_param);

	zephir_get_strval(&sql, sql_param);
	limit = zephir_get_intval(limit_param);
	skip = zephir_get_intval(skip_param);


	if (skip == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "SELECT t1.* FROM (%s) t1 WHERE rownum <= %d");
		ZVAL_LONG(&_1$$3, limit);
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 2, &_0$$3, &sql, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "SELECT * FROM (SELECT t1.*, rownum r FROM (%s) t1 WHERE rownum <= %d) t2 WHERE r > %d");
	ZVAL_LONG(&_4, (limit + skip));
	ZVAL_LONG(&_5, skip);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 2, &_3, &sql, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

