
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
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Db_DaoPgsql) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, DaoPgsql, nc, db_daopgsql, nc_db_daoabstract_ce, nc_db_daopgsql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_DaoPgsql, upsert) {

	zval _27$$15;
	zend_bool _6$$4;
	zend_string *_11, *_24$$11;
	zend_ulong _10, _23$$11;
	zephir_fcall_cache_entry *_21 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *inserts_param = NULL, *updates_param = NULL, iPre, uPre, k, kPrefixed, v, iks, ivs, us, params, s, _0, _4, *_5, *_9, _15, _16, _17, _18, _19, _20, _32, _1$$3, _2$$3, _3$$3, _7$$5, _8$$5, _12$$8, _13$$8, _14$$9, *_22$$11, _29$$11, _30$$11, _31$$11, _25$$14, _26$$14, _28$$16;
	zval inserts, updates;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&inserts);
	ZVAL_UNDEF(&updates);
	ZVAL_UNDEF(&iPre);
	ZVAL_UNDEF(&uPre);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&kPrefixed);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&iks);
	ZVAL_UNDEF(&ivs);
	ZVAL_UNDEF(&us);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_27$$15);

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
	ZEPHIR_INIT_VAR(&iks);
	array_init(&iks);
	ZEPHIR_INIT_VAR(&ivs);
	array_init(&ivs);
	ZEPHIR_INIT_VAR(&us);
	array_init(&us);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	zephir_read_property(&_0, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(zephir_fast_count_int(&_0 TSRMLS_CC) < 1)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "upsert");
		ZVAL_LONG(&_3$$3, 7);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/db/daopgsql.zep", 10 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "nc/db/daopgsql.zep", 18);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
	{
		ZEPHIR_INIT_NVAR(&k);
		ZVAL_COPY(&k, _5);
		ZEPHIR_OBS_NVAR(&v);
		_6$$4 = !(zephir_array_isset_fetch(&v, &inserts, &k, 0 TSRMLS_CC));
		if (!(_6$$4)) {
			_6$$4 = Z_TYPE_P(&v) == IS_NULL;
		}
		if (unlikely(_6$$4)) {
			ZEPHIR_INIT_NVAR(&_7$$5);
			object_init_ex(&_7$$5, nc_db_exception_ce);
			ZVAL_LONG(&_8$$5, 8);
			ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 7, &k, &_8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$5, "nc/db/daopgsql.zep", 14 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&k);
	zephir_is_iterable(&inserts, 0, "nc/db/daopgsql.zep", 31);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&inserts), _10, _11, _9)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_11 != NULL) { 
			ZVAL_STR_COPY(&k, _11);
		} else {
			ZVAL_LONG(&k, _10);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _9);
		if (!(Z_TYPE_P(&k) == IS_LONG)) {
			zephir_array_append(&iks, &k, PH_SEPARATE, "nc/db/daopgsql.zep", 20);
			if (Z_TYPE_P(&v) == IS_ARRAY) {
				zephir_read_property(&_12$$8, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_13$$8, &_12$$8, "expression", NULL, 0, &v);
				zephir_check_call_status();
				zephir_array_append(&ivs, &_13$$8, PH_SEPARATE, "nc/db/daopgsql.zep", 22);
			} else {
				ZEPHIR_INIT_NVAR(&kPrefixed);
				ZEPHIR_CONCAT_VV(&kPrefixed, &iPre, &k);
				ZEPHIR_INIT_LNVAR(_14$$9);
				ZEPHIR_CONCAT_SV(&_14$$9, ":", &kPrefixed);
				zephir_array_append(&ivs, &_14$$9, PH_SEPARATE, "nc/db/daopgsql.zep", 25);
				zephir_array_update_zval(&params, &kPrefixed, &v, PH_COPY | PH_SEPARATE);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_15, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_16);
	zephir_fast_join_str(&_16, SL(", "), &iks TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_17);
	zephir_fast_join_str(&_17, SL(", "), &ivs TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_18);
	zephir_read_property(&_19, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_join_str(&_18, SL(", "), &_19 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_STRING(&_20, "INSERT INTO %s (%s) VALUES (%s) ON CONFLICT (%s) DO");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", &_21, 6, &_20, &_15, &_16, &_17, &_18);
	zephir_check_call_status();
	if (zephir_fast_count_int(&updates TSRMLS_CC) < 1) {
		zephir_concat_self_str(&s, SL(" NOTHING") TSRMLS_CC);
	} else {
		zephir_is_iterable(&updates, 0, "nc/db/daopgsql.zep", 56);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&updates), _23$$11, _24$$11, _22$$11)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_24$$11 != NULL) { 
				ZVAL_STR_COPY(&k, _24$$11);
			} else {
				ZVAL_LONG(&k, _23$$11);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _22$$11);
			if (Z_TYPE_P(&k) == IS_LONG) {
				if (Z_TYPE_P(&v) == IS_ARRAY) {
					zephir_read_property(&_25$$14, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_26$$14, &_25$$14, "expression", NULL, 0, &v);
					zephir_check_call_status();
					zephir_array_append(&us, &_26$$14, PH_SEPARATE, "nc/db/daopgsql.zep", 45);
				} else {
					zephir_get_strval(&_27$$15, &v);
					zephir_array_append(&us, &_27$$15, PH_SEPARATE, "nc/db/daopgsql.zep", 47);
				}
			} else {
				ZEPHIR_INIT_NVAR(&kPrefixed);
				ZEPHIR_CONCAT_VV(&kPrefixed, &uPre, &k);
				ZEPHIR_INIT_LNVAR(_28$$16);
				ZEPHIR_CONCAT_VSV(&_28$$16, &k, " = :", &kPrefixed);
				zephir_array_append(&us, &_28$$16, PH_SEPARATE, "nc/db/daopgsql.zep", 51);
				zephir_array_update_zval(&params, &kPrefixed, &v, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
		ZEPHIR_INIT_VAR(&_29$$11);
		zephir_fast_join_str(&_29$$11, SL(", "), &us TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_30$$11);
		ZVAL_STRING(&_30$$11, " UPDATE SET %s");
		ZEPHIR_CALL_FUNCTION(&_31$$11, "sprintf", &_21, 6, &_30$$11, &_29$$11);
		zephir_check_call_status();
		zephir_concat_self(&s, &_31$$11 TSRMLS_CC);
	}
	zephir_read_property(&_32, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_32, "execute", NULL, 0, &s, &params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoPgsql, updateTop) {

	zval _5$$6;
	zend_string *_2;
	zend_ulong _1;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *updates_param = NULL, *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, k, v, us, pks, s, *_0, _7, _8, _9, _10, _11, _12, _13, _14, _3$$5, _4$$5, _6$$7;
	zval updates;
	ZEPHIR_INIT_THIS();

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
	zephir_is_iterable(&updates, 1, "nc/db/daopgsql.zep", 82);
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
				zephir_array_append(&us, &_4$$5, PH_SEPARATE, "nc/db/daopgsql.zep", 72);
			} else {
				zephir_get_strval(&_5$$6, &v);
				zephir_array_append(&us, &_5$$6, PH_SEPARATE, "nc/db/daopgsql.zep", 74);
			}
			zephir_array_unset(&updates, &k, PH_SEPARATE);
		} else {
			ZEPHIR_INIT_LNVAR(_6$$7);
			ZEPHIR_CONCAT_VSV(&_6$$7, &k, " = :", &k);
			zephir_array_append(&us, &_6$$7, PH_SEPARATE, "nc/db/daopgsql.zep", 78);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_7, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pks);
	zephir_fast_join_str(&pks, SL(", "), &_7 TSRMLS_CC);
	zephir_read_property(&_8, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "makeorder", NULL, 0, order);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_join_str(&_12, SL(", "), &us TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "WITH t1 AS (SELECT %s FROM %s%s%s LIMIT %d) UPDATE %s SET %s WHERE (%s) IN (SELECT %s FROM t1)");
	ZVAL_LONG(&_14, limit);
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 6, &_13, &pks, &_8, &_9, &_10, &_14, &_11, &_12, &pks, &pks);
	zephir_check_call_status();
	zephir_read_property(&_14, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_14, "execute", NULL, 0, &s, &updates);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoPgsql, deleteTop) {

	int ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, pks, s, _0, _1, _2, _3, _4, _5, _6;
	ZEPHIR_INIT_THIS();

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
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "makeorder", NULL, 0, order);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "WITH t1 AS (SELECT %s FROM %s%s%s LIMIT %d) DELETE FROM %s WHERE (%s) IN (SELECT %s FROM t1)");
	ZVAL_LONG(&_6, limit);
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 6, &_5, &pks, &_1, &_2, &_3, &_6, &_4, &pks, &pks);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_6, "execute", NULL, 0, &s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoPgsql, makeRandomOrder) {

	ZEPHIR_INIT_THIS();


	RETURN_STRING("RANDOM()");

}

PHP_METHOD(Nc_Db_DaoPgsql, makePagination) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	long limit, skip;
	zval *sql_param = NULL, *limit_param = NULL, *skip_param = NULL, _0$$3, _1$$3, _3, _4, _5;
	zval sql;
	ZEPHIR_INIT_THIS();

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
		ZVAL_STRING(&_0$$3, "%s LIMIT %d");
		ZVAL_LONG(&_1$$3, limit);
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 6, &_0$$3, &sql, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "%s LIMIT %d OFFSET %d");
	ZVAL_LONG(&_4, limit);
	ZVAL_LONG(&_5, skip);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 6, &_3, &sql, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

