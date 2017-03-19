
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Db_DaoMysql) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, DaoMysql, nc, db_daomysql, nc_db_daoabstract_ce, nc_db_daomysql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_DaoMysql, queryLastInsertId) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "SELECT last_insert_id()");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "querycell", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoMysql, replace) {

	zend_string *_3;
	zend_ulong _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, s, k, v, ks, vs, _0, *_1, _7, _8, _9, _10, _4$$5, _5$$5, _6$$6;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&ks);
	ZVAL_UNDEF(&vs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&ks);
	array_init(&ks);
	ZEPHIR_INIT_VAR(&vs);
	array_init(&vs);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("lastSequence"), &_0);
	zephir_is_iterable(&data, 1, "nc/db/daomysql.zep", 31);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&k, _3);
		} else {
			ZVAL_LONG(&k, _2);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		if (Z_TYPE_P(&k) == IS_LONG) {
			zephir_array_unset(&data, &k, PH_SEPARATE);
			continue;
		}
		zephir_array_append(&ks, &k, PH_SEPARATE, "nc/db/daomysql.zep", 22);
		if (Z_TYPE_P(&v) == IS_ARRAY) {
			zephir_read_property(&_4$$5, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_5$$5, &_4$$5, "expression", NULL, 0, &v);
			zephir_check_call_status();
			zephir_array_append(&vs, &_5$$5, PH_SEPARATE, "nc/db/daomysql.zep", 24);
			zephir_array_unset(&data, &k, PH_SEPARATE);
		} else {
			ZEPHIR_INIT_LNVAR(_6$$6);
			ZEPHIR_CONCAT_SV(&_6$$6, ":", &k);
			zephir_array_append(&vs, &_6$$6, PH_SEPARATE, "nc/db/daomysql.zep", 27);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_7, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_join_str(&_0, SL(", "), &ks TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_join_str(&_8, SL(", "), &vs TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "REPLACE INTO %s (%s) VALUES (%s)");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_9, &_7, &_0, &_8);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_10, "execute", NULL, 0, &s, &data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoMysql, insert) {

	zval _6$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL;
	zend_bool ignoreSequence, _2$$3, _5$$3;
	zval *inserts_param = NULL, *ignoreSequence_param = NULL, rc, sequence, _1, _3$$3, _4$$3, _7$$3;
	zval inserts;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&inserts);
	ZVAL_UNDEF(&rc);
	ZVAL_UNDEF(&sequence);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &inserts_param, &ignoreSequence_param);

	zephir_get_arrval(&inserts, inserts_param);
	if (!ignoreSequence_param) {
		ignoreSequence = 0;
	} else {
		ignoreSequence = zephir_get_boolval(ignoreSequence_param);
	}


	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_PARENT(&rc, nc_db_daomysql_ce, this_ptr, "insert", &_0, 45, &inserts, &_1);
	zephir_check_call_status();
	while (1) {
		_2$$3 = ignoreSequence;
		if (!(_2$$3)) {
			zephir_read_property(&_3$$3, this_ptr, SL("sequenceField"), PH_NOISY_CC | PH_READONLY);
			_2$$3 = zephir_fast_strlen_ev(&_3$$3) < 1;
		}
		if (_2$$3) {
			break;
		}
		ZEPHIR_OBS_NVAR(&sequence);
		zephir_read_property(&_4$$3, this_ptr, SL("sequenceField"), PH_NOISY_CC | PH_READONLY);
		_5$$3 = zephir_array_isset_fetch(&sequence, &inserts, &_4$$3, 0 TSRMLS_CC);
		if (_5$$3) {
			_5$$3 = Z_TYPE_P(&sequence) != IS_NULL;
		}
		if (_5$$3) {
			zephir_get_strval(&_6$$5, &sequence);
			zephir_update_property_zval(this_ptr, SL("lastSequence"), &_6$$5);
			break;
		}
		ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "querylastinsertid", &_8, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("lastSequence"), &_7$$3);
		break;
	}
	RETURN_CCTOR(rc);

}

PHP_METHOD(Nc_Db_DaoMysql, upsert) {

	zval _23$$16;
	zend_bool _6$$4;
	zend_string *_11, *_20$$12;
	zend_ulong _10, _19$$12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *inserts_param = NULL, *updates_param = NULL, iPre, uPre, k, kPrefixed, v, iks, ivs, us, params, s, _0, _4, *_5, *_9, _25, _26, _27, _28, _29, _30, _1$$3, _2$$3, _3$$3, _7$$5, _8$$5, _12$$8, _13$$8, _14$$9, _15$$10, *_16$$10, _17$$11, *_18$$12, _21$$15, _22$$15, _24$$17;
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
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_23$$16);

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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/db/daomysql.zep", 69 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "nc/db/daomysql.zep", 77);
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
			ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 3, &k, &_8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$5, "nc/db/daomysql.zep", 73 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&k);
	zephir_is_iterable(&inserts, 0, "nc/db/daomysql.zep", 90);
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
			zephir_array_append(&iks, &k, PH_SEPARATE, "nc/db/daomysql.zep", 79);
			if (Z_TYPE_P(&v) == IS_ARRAY) {
				zephir_read_property(&_12$$8, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_13$$8, &_12$$8, "expression", NULL, 0, &v);
				zephir_check_call_status();
				zephir_array_append(&ivs, &_13$$8, PH_SEPARATE, "nc/db/daomysql.zep", 81);
			} else {
				ZEPHIR_INIT_NVAR(&kPrefixed);
				ZEPHIR_CONCAT_VV(&kPrefixed, &iPre, &k);
				ZEPHIR_INIT_LNVAR(_14$$9);
				ZEPHIR_CONCAT_SV(&_14$$9, ":", &kPrefixed);
				zephir_array_append(&ivs, &_14$$9, PH_SEPARATE, "nc/db/daomysql.zep", 84);
				zephir_array_update_zval(&params, &kPrefixed, &v, PH_COPY | PH_SEPARATE);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	if (zephir_fast_count_int(&updates TSRMLS_CC) < 1) {
		zephir_read_property(&_15$$10, this_ptr, SL("primaryKey"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_15$$10, 0, "nc/db/daomysql.zep", 95);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_15$$10), _16$$10)
		{
			ZEPHIR_INIT_NVAR(&k);
			ZVAL_COPY(&k, _16$$10);
			ZEPHIR_INIT_LNVAR(_17$$11);
			ZEPHIR_CONCAT_VSV(&_17$$11, &k, " = ", &k);
			zephir_array_append(&us, &_17$$11, PH_SEPARATE, "nc/db/daomysql.zep", 92);
			break;
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&k);
	} else {
		zephir_is_iterable(&updates, 0, "nc/db/daomysql.zep", 109);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&updates), _19$$12, _20$$12, _18$$12)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_20$$12 != NULL) { 
				ZVAL_STR_COPY(&k, _20$$12);
			} else {
				ZVAL_LONG(&k, _19$$12);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _18$$12);
			if (Z_TYPE_P(&k) == IS_LONG) {
				if (Z_TYPE_P(&v) == IS_ARRAY) {
					zephir_read_property(&_21$$15, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_22$$15, &_21$$15, "expression", NULL, 0, &v);
					zephir_check_call_status();
					zephir_array_append(&us, &_22$$15, PH_SEPARATE, "nc/db/daomysql.zep", 99);
				} else {
					zephir_get_strval(&_23$$16, &v);
					zephir_array_append(&us, &_23$$16, PH_SEPARATE, "nc/db/daomysql.zep", 101);
				}
			} else {
				ZEPHIR_INIT_NVAR(&kPrefixed);
				ZEPHIR_CONCAT_VV(&kPrefixed, &uPre, &k);
				ZEPHIR_INIT_LNVAR(_24$$17);
				ZEPHIR_CONCAT_VSV(&_24$$17, &k, " = :", &kPrefixed);
				zephir_array_append(&us, &_24$$17, PH_SEPARATE, "nc/db/daomysql.zep", 105);
				zephir_array_update_zval(&params, &kPrefixed, &v, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
	}
	zephir_read_property(&_25, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_26);
	zephir_fast_join_str(&_26, SL(", "), &iks TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_27);
	zephir_fast_join_str(&_27, SL(", "), &ivs TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_28);
	zephir_fast_join_str(&_28, SL(", "), &us TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_29);
	ZVAL_STRING(&_29, "INSERT INTO %s (%s) VALUES (%s) ON DUPLICATE KEY UPDATE %s");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_29, &_25, &_26, &_27, &_28);
	zephir_check_call_status();
	zephir_read_property(&_30, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_30, "execute", NULL, 0, &s, &params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoMysql, updateTop) {

	zval _5$$6;
	zend_string *_2;
	zend_ulong _1;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *updates_param = NULL, *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, k, v, us, s, *_0, _7, _8, _9, _10, _11, _12, _3$$5, _4$$5, _6$$7;
	zval updates;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&updates);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&us);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
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
	zephir_is_iterable(&updates, 1, "nc/db/daomysql.zep", 139);
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
				zephir_array_append(&us, &_4$$5, PH_SEPARATE, "nc/db/daomysql.zep", 129);
			} else {
				zephir_get_strval(&_5$$6, &v);
				zephir_array_append(&us, &_5$$6, PH_SEPARATE, "nc/db/daomysql.zep", 131);
			}
			zephir_array_unset(&updates, &k, PH_SEPARATE);
		} else {
			ZEPHIR_INIT_LNVAR(_6$$7);
			ZEPHIR_CONCAT_VSV(&_6$$7, &k, " = :", &k);
			zephir_array_append(&us, &_6$$7, PH_SEPARATE, "nc/db/daomysql.zep", 135);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_7, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_join_str(&_8, SL(", "), &us TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "makeorder", NULL, 0, order);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "UPDATE %s SET %s%s%s LIMIT %d");
	ZVAL_LONG(&_12, limit);
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_11, &_7, &_8, &_9, &_10, &_12);
	zephir_check_call_status();
	zephir_read_property(&_12, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_12, "execute", NULL, 0, &s, &updates);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoMysql, deleteTop) {

	int ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, s, _0, _1, _2, _3, _4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

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


	zephir_read_property(&_0, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "makeorder", NULL, 0, order);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "DELETE FROM %s%s%s LIMIT %d");
	ZVAL_LONG(&_4, limit);
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_3, &_0, &_1, &_2, &_4);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_4, "execute", NULL, 0, &s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoMysql, countAndFind) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool lock;
	long limit, skip, numRows = 0;
	zval *fields_param = NULL, *where, where_sub, *order, order_sub, *limit_param = NULL, *skip_param = NULL, *lock_param = NULL, s, data, _0, _1, _2, _3, _8, _9, _10, _4$$3, _5$$3, _6$$3;
	zval fields, _7$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 0, &fields_param, &where, &order, &limit_param, &skip_param, &lock_param);

	zephir_get_strval(&fields, fields_param);
	limit = zephir_get_intval(limit_param);
	skip = zephir_get_intval(skip_param);
	lock = zephir_get_boolval(lock_param);


	zephir_read_property(&_0, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "makeorder", NULL, 0, order);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "SELECT SQL_CALC_FOUND_ROWS %s FROM %s%s%s");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_3, &fields, &_0, &_1, &_2);
	zephir_check_call_status();
	if (limit > 0) {
		ZVAL_LONG(&_5$$3, limit);
		ZVAL_LONG(&_6$$3, skip);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "makepagination", NULL, 0, &s, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_get_strval(&_7$$3, &_4$$3);
		ZEPHIR_CPY_WRT(&s, &_7$$3);
	}
	if (lock) {
		zephir_concat_self_str(&s, SL(" FOR UPDATE") TSRMLS_CC);
	}
	zephir_read_property(&_8, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_8, "query", NULL, 0, &s);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "SELECT found_rows()");
	ZEPHIR_CALL_METHOD(&_10, &_9, "querycell", NULL, 0, &_3);
	zephir_check_call_status();
	numRows = zephir_get_intval(&_10);
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, numRows);
	zephir_array_fast_append(return_value, &_3);
	zephir_array_fast_append(return_value, &data);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoMysql, makeRandomOrder) {

	ZEPHIR_INIT_THIS();


	RETURN_STRING("RAND()");

}

PHP_METHOD(Nc_Db_DaoMysql, makePagination) {

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
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 2, &_0$$3, &sql, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "%s LIMIT %d, %d");
	ZVAL_LONG(&_4, skip);
	ZVAL_LONG(&_5, limit);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 2, &_3, &sql, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

