
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Db_DaoAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, DaoAbstract, nc, db_daoabstract, nc_db_daoabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_db_daoabstract_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_daoabstract_ce, SL("table"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_daoabstract_ce, SL("primaryKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_daoabstract_ce, SL("sequenceField"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(nc_db_daoabstract_ce, SL("lastSequence"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_DaoAbstract, __construct) {

	zval pk;
	zval tb, sf;
	zval *db, db_sub, *tb_param = NULL, *pk_param = NULL, *sf_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&db_sub);
	ZVAL_UNDEF(&tb);
	ZVAL_UNDEF(&sf);
	ZVAL_UNDEF(&pk);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &db, &tb_param, &pk_param, &sf_param);

	zephir_get_strval(&tb, tb_param);
	zephir_get_arrval(&pk, pk_param);
	zephir_get_strval(&sf, sf_param);


	zephir_update_property_zval(this_ptr, SL("db"), db);
	zephir_update_property_zval(this_ptr, SL("table"), &tb);
	zephir_update_property_zval(this_ptr, SL("primaryKey"), &pk);
	zephir_update_property_zval(this_ptr, SL("sequenceField"), &sf);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DaoAbstract, getDb) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "db");

}

PHP_METHOD(Nc_Db_DaoAbstract, getTable) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "table");

}

PHP_METHOD(Nc_Db_DaoAbstract, getPrimaryKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "primaryKey");

}

PHP_METHOD(Nc_Db_DaoAbstract, getSequenceField) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sequenceField");

}

PHP_METHOD(Nc_Db_DaoAbstract, lastSequence) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "lastSequence");

}

PHP_METHOD(Nc_Db_DaoAbstract, insert) {

	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ignoreSequence, _10;
	zval *inserts_param = NULL, *ignoreSequence_param = NULL, s, k, v, ks, vs, _0, *_1, _7, _8, _9, _11, _13, _14, _15, _16, _4$$5, _5$$5, _6$$6, _12$$7;
	zval inserts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inserts);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&ks);
	ZVAL_UNDEF(&vs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_12$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &inserts_param, &ignoreSequence_param);

	zephir_get_arrval(&inserts, inserts_param);
	if (!ignoreSequence_param) {
		ignoreSequence = 0;
	} else {
		ignoreSequence = zephir_get_boolval(ignoreSequence_param);
	}


	ZEPHIR_INIT_VAR(&ks);
	array_init(&ks);
	ZEPHIR_INIT_VAR(&vs);
	array_init(&vs);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("lastSequence"), &_0);
	zephir_is_iterable(&inserts, 1, "nc/db/daoabstract.zep", 66);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&inserts), _2, _3, _1)
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
			zephir_array_unset(&inserts, &k, PH_SEPARATE);
			continue;
		}
		zephir_array_append(&ks, &k, PH_SEPARATE, "nc/db/daoabstract.zep", 57);
		if (Z_TYPE_P(&v) == IS_ARRAY) {
			zephir_read_property(&_4$$5, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_5$$5, &_4$$5, "expression", NULL, 0, &v);
			zephir_check_call_status();
			zephir_array_append(&vs, &_5$$5, PH_SEPARATE, "nc/db/daoabstract.zep", 59);
			zephir_array_unset(&inserts, &k, PH_SEPARATE);
		} else {
			ZEPHIR_INIT_LNVAR(_6$$6);
			ZEPHIR_CONCAT_SV(&_6$$6, ":", &k);
			zephir_array_append(&vs, &_6$$6, PH_SEPARATE, "nc/db/daoabstract.zep", 62);
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
	ZVAL_STRING(&_9, "INSERT INTO %s (%s) VALUES (%s)");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_9, &_7, &_0, &_8);
	zephir_check_call_status();
	_10 = ignoreSequence;
	if (!(_10)) {
		zephir_read_property(&_11, this_ptr, SL("sequenceField"), PH_NOISY_CC | PH_READONLY);
		_10 = zephir_fast_strlen_ev(&_11) < 1;
	}
	if (_10) {
		zephir_read_property(&_12$$7, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_12$$7, "execute", NULL, 0, &s, &inserts);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_13, this_ptr, SL("sequenceField"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_CONCAT_SV(&_14, " RETURNING ", &_13);
	zephir_concat_self(&s, &_14 TSRMLS_CC);
	zephir_read_property(&_15, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_16, &_15, "querycell", NULL, 0, &s, &inserts);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("lastSequence"), &_16);
	RETURN_MM_LONG(1);

}

PHP_METHOD(Nc_Db_DaoAbstract, upsert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inserts_param = NULL, *updates_param = NULL, _0, _1, _2;
	zval inserts, updates;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inserts);
	ZVAL_UNDEF(&updates);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &inserts_param, &updates_param);

	zephir_get_arrval(&inserts, inserts_param);
	if (!updates_param) {
		ZEPHIR_INIT_VAR(&updates);
		array_init(&updates);
	} else {
		zephir_get_arrval(&updates, updates_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_db_exception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "upsert");
	ZVAL_LONG(&_2, 5);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_1, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "nc/db/daoabstract.zep", 85 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Db_DaoAbstract, update) {

	zval _5$$6;
	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *updates_param = NULL, *where = NULL, where_sub, s, k, v, kvs, *_0, _7, _8, _9, _10, _11, _3$$5, _4$$5, _6$$7;
	zval updates;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&updates);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&kvs);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &updates_param, &where);

	zephir_get_arrval(&updates, updates_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	ZEPHIR_INIT_VAR(&kvs);
	array_init(&kvs);
	zephir_is_iterable(&updates, 1, "nc/db/daoabstract.zep", 105);
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
				zephir_array_update_zval(&kvs, &k, &_4$$5, PH_COPY | PH_SEPARATE);
			} else {
				zephir_get_strval(&_5$$6, &v);
				zephir_array_update_zval(&kvs, &k, &_5$$6, PH_COPY | PH_SEPARATE);
			}
			zephir_array_unset(&updates, &k, PH_SEPARATE);
		} else {
			ZEPHIR_INIT_LNVAR(_6$$7);
			ZEPHIR_CONCAT_VSV(&_6$$7, &k, " = :", &k);
			zephir_array_update_zval(&kvs, &k, &_6$$7, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_7, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_join_str(&_8, SL(", "), &kvs TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "UPDATE %s SET %s%s");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_10, &_7, &_8, &_9);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_11, "execute", NULL, 0, &s, &updates);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, updateTop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *updates_param = NULL, *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, _0, _1, _2;
	zval updates;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&updates);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

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


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_db_exception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "updateTop");
	ZVAL_LONG(&_2, 5);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_1, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "nc/db/daoabstract.zep", 117 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Db_DaoAbstract, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL, where_sub, s, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &where);

	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	zephir_read_property(&_0, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "DELETE FROM %s%s");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_2, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "execute", NULL, 0, &s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, deleteTop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

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


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_db_exception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "deleteTop");
	ZVAL_LONG(&_2, 5);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_1, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "nc/db/daoabstract.zep", 135 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Db_DaoAbstract, find) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lock;
	long limit, skip;
	zval *fields_param = NULL, *where, where_sub, *order, order_sub, *limit_param = NULL, *skip_param = NULL, *lock_param = NULL, s, _0, _1, _2, _3, _8, _4$$3, _5$$3, _6$$3;
	zval fields, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
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
	ZVAL_STRING(&_3, "SELECT %s FROM %s%s%s");
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
	ZEPHIR_RETURN_CALL_METHOD(&_8, "query", NULL, 0, &s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, countAndFind) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lock, _0;
	long limit, skip;
	zval *fields_param = NULL, *where, where_sub, *order, order_sub, *limit_param = NULL, *skip_param = NULL, *lock_param = NULL, numRows, data, _1$$3, _2$$3, _3$$3;
	zval fields;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&numRows);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 0, &fields_param, &where, &order, &limit_param, &skip_param, &lock_param);

	zephir_get_strval(&fields, fields_param);
	limit = zephir_get_intval(limit_param);
	skip = zephir_get_intval(skip_param);
	lock = zephir_get_boolval(lock_param);


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&numRows, this_ptr, "countall", NULL, 0, where);
	zephir_check_call_status();
	_0 = ZEPHIR_GT_LONG(&numRows, 0);
	if (_0) {
		_0 = ZEPHIR_GT_LONG(&numRows, skip);
	}
	if (_0) {
		ZVAL_LONG(&_1$$3, limit);
		ZVAL_LONG(&_2$$3, skip);
		if (lock) {
			ZVAL_BOOL(&_3$$3, 1);
		} else {
			ZVAL_BOOL(&_3$$3, 0);
		}
		ZEPHIR_CALL_METHOD(&data, this_ptr, "find", NULL, 0, &fields, where, order, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &numRows);
	zephir_array_fast_append(return_value, &data);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, findAll) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit, skip;
	zval *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, *skip_param = NULL, __$null, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &where, &order, &limit_param, &skip_param);

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
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!skip_param) {
		skip = 0;
	} else {
		skip = zephir_get_intval(skip_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	ZVAL_LONG(&_1, limit);
	ZVAL_LONG(&_2, skip);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "find", NULL, 0, &_0, where, order, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, findPaged) {

	zend_bool _6;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit, page, skip = 0, numRows = 0, numPages = 0;
	zval *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, *page_param = NULL, __$null, result, data, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &where, &order, &limit_param, &page_param);

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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	ZVAL_LONG(&_1, limit);
	ZVAL_LONG(&_2, skip);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "countandfind", NULL, 0, &_0, where, order, &_1, &_2, &_3);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&result) != IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(&result);
		array_init(&result);
	}
	ZEPHIR_MAKE_REF(&result);
	ZEPHIR_CALL_FUNCTION(&_4, "array_shift", &_5, 4, &result);
	ZEPHIR_UNREF(&result);
	zephir_check_call_status();
	numRows = zephir_get_intval(&_4);
	ZEPHIR_MAKE_REF(&result);
	ZEPHIR_CALL_FUNCTION(&data, "array_shift", &_5, 4, &result);
	ZEPHIR_UNREF(&result);
	zephir_check_call_status();
	_6 = numRows < 1;
	if (!(_6)) {
		_6 = zephir_fast_count_int(&data TSRMLS_CC) < 1;
	}
	if (_6) {
		numPages = 0;
	} else {
		numPages = (1 + (long) (zephir_safe_div_long_long(((numRows - 1)), limit TSRMLS_CC)));
	}
	zephir_create_array(return_value, 6, 0 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("data"), &data, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, limit);
	zephir_array_update_string(return_value, SL("limit"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, page);
	zephir_array_update_string(return_value, SL("page"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, skip);
	zephir_array_update_string(return_value, SL("skip"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, numRows);
	zephir_array_update_string(return_value, SL("numRows"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, numPages);
	zephir_array_update_string(return_value, SL("numPages"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, findTop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lock;
	long limit;
	zval *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, *lock_param = NULL, __$null, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &where, &order, &limit_param, &lock_param);

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
	if (!lock_param) {
		lock = 0;
	} else {
		lock = zephir_get_boolval(lock_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	ZVAL_LONG(&_1, limit);
	ZVAL_LONG(&_2, 0);
	if (lock) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "find", NULL, 0, &_0, where, order, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, findFirst) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lock;
	zval *where = NULL, where_sub, *order = NULL, order_sub, *lock_param = NULL, __$null, data, row, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &where, &order, &lock_param);

	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}
	if (!order) {
		order = &order_sub;
		order = &__$null;
	}
	if (!lock_param) {
		lock = 0;
	} else {
		lock = zephir_get_boolval(lock_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	ZVAL_LONG(&_1, 1);
	ZVAL_LONG(&_2, 0);
	if (lock) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "find", NULL, 0, &_0, where, order, &_1, &_2, &_3);
	zephir_check_call_status();
	if (zephir_array_isset_long_fetch(&row, &data, 0, 1 TSRMLS_CC)) {
		RETURN_CTOR(&row);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DaoAbstract, findVector) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *field_param = NULL, *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, data, row, result, _0, _1, _2, *_3, _4$$4;
	zval field, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &field_param, &where, &order, &limit_param);

	zephir_get_strval(&field, field_param);
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
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZVAL_LONG(&_0, limit);
	ZVAL_LONG(&_1, 0);
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "find", NULL, 0, &field, where, order, &_0, &_1, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "nc/db/daoabstract.zep", 244);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _3)
	{
		ZEPHIR_INIT_NVAR(&row);
		ZVAL_COPY(&row, _3);
		if (Z_TYPE_P(&row) == IS_ARRAY) {
			ZEPHIR_MAKE_REF(&row);
			ZEPHIR_CALL_FUNCTION(&_4$$4, "array_shift", &_5, 4, &row);
			ZEPHIR_UNREF(&row);
			zephir_check_call_status();
			zephir_get_strval(&_6$$4, &_4$$4);
			zephir_array_append(&result, &_6$$4, PH_SEPARATE, "nc/db/daoabstract.zep", 240);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&row);
	RETURN_CCTOR(&result);

}

PHP_METHOD(Nc_Db_DaoAbstract, findMap) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit;
	zval *kField_param = NULL, *vField_param = NULL, *where = NULL, where_sub, *order = NULL, order_sub, *limit_param = NULL, __$null, data, row, k, v, result, _1, _2, _3, *_4, _5$$4, _8$$4;
	zval kField, vField, _0, _7$$4, _9$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&kField);
	ZVAL_UNDEF(&vField);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &kField_param, &vField_param, &where, &order, &limit_param);

	zephir_get_strval(&kField, kField_param);
	zephir_get_strval(&vField, vField_param);
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
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSV(&_0, &kField, ", ", &vField);
	ZVAL_LONG(&_1, limit);
	ZVAL_LONG(&_2, 0);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "find", NULL, 0, &_0, where, order, &_1, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "nc/db/daoabstract.zep", 261);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _4)
	{
		ZEPHIR_INIT_NVAR(&row);
		ZVAL_COPY(&row, _4);
		if (Z_TYPE_P(&row) == IS_ARRAY) {
			ZEPHIR_MAKE_REF(&row);
			ZEPHIR_CALL_FUNCTION(&_5$$4, "array_shift", &_6, 4, &row);
			ZEPHIR_UNREF(&row);
			zephir_check_call_status();
			zephir_get_strval(&_7$$4, &_5$$4);
			ZEPHIR_CPY_WRT(&k, &_7$$4);
			ZEPHIR_MAKE_REF(&row);
			ZEPHIR_CALL_FUNCTION(&_8$$4, "array_shift", &_6, 4, &row);
			ZEPHIR_UNREF(&row);
			zephir_check_call_status();
			zephir_get_strval(&_9$$4, &_8$$4);
			ZEPHIR_CPY_WRT(&v, &_9$$4);
			zephir_array_update_zval(&result, &k, &v, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&row);
	RETURN_CCTOR(&result);

}

PHP_METHOD(Nc_Db_DaoAbstract, findCell) {

	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *where = NULL, where_sub, *order = NULL, order_sub, __$null, data, row, _0, _1, _2, _4$$3;
	zval field, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field_param, &where, &order);

	zephir_get_strval(&field, field_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}
	if (!order) {
		order = &order_sub;
		order = &__$null;
	}


	ZVAL_LONG(&_0, 1);
	ZVAL_LONG(&_1, 0);
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "find", NULL, 0, &field, where, order, &_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&row);
	_3 = zephir_array_isset_long_fetch(&row, &data, 0, 0 TSRMLS_CC);
	if (_3) {
		_3 = Z_TYPE_P(&row) == IS_ARRAY;
	}
	if (_3) {
		ZEPHIR_MAKE_REF(&row);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "array_shift", NULL, 4, &row);
		ZEPHIR_UNREF(&row);
		zephir_check_call_status();
		zephir_get_strval(&_5$$3, &_4$$3);
		RETURN_CTOR(&_5$$3);
	}
	RETURN_MM_STRING("");

}

PHP_METHOD(Nc_Db_DaoAbstract, group) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval aggrs;
	zval *byField_param = NULL, *aggrs_param = NULL, *where = NULL, where_sub, *having = NULL, having_sub, *order = NULL, order_sub, __$null, f, k, v, s, *_0, _4, _5, _7, _8, _9, _10, _3$$3;
	zval byField;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&byField);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&having_sub);
	ZVAL_UNDEF(&order_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&f);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&aggrs);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &byField_param, &aggrs_param, &where, &having, &order);

	zephir_get_strval(&byField, byField_param);
	zephir_get_arrval(&aggrs, aggrs_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}
	if (!having) {
		having = &having_sub;
		ZEPHIR_INIT_VAR(having);
		ZVAL_STRING(having, "");
	}
	if (!order) {
		order = &order_sub;
		order = &__$null;
	}


	ZEPHIR_CPY_WRT(&f, &byField);
	zephir_is_iterable(&aggrs, 0, "nc/db/daoabstract.zep", 286);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&aggrs), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SVSV(&_3$$3, ", ", &v, " AS ", &k);
		zephir_concat_self(&f, &_3$$3 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_4, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "makewhere", &_6, 0, where);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, " HAVING ");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "makewhere", &_6, 0, having, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "makeorder", NULL, 0, order);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "SELECT %s FROM %s%s GROUP BY %s%s%s");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_8, &f, &_4, &_5, &byField, &_7, &_9);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_10, "query", NULL, 0, &s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, aggregations) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *aggrs_param = NULL, *where = NULL, where_sub, k, v, a, s, *_0, _4, _5, _6, _7, _8, _3$$3;
	zval aggrs;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&aggrs);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aggrs_param, &where);

	zephir_get_arrval(&aggrs, aggrs_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	ZEPHIR_INIT_VAR(&a);
	array_init(&a);
	zephir_is_iterable(&aggrs, 0, "nc/db/daoabstract.zep", 307);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&aggrs), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSV(&_3$$3, &v, " AS ", &k);
		zephir_array_append(&a, &_3$$3, PH_SEPARATE, "nc/db/daoabstract.zep", 304);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_join_str(&_4, SL(", "), &a TSRMLS_CC);
	zephir_read_property(&_5, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "SELECT %s FROM %s%s");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_7, &_4, &_5, &_6);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_8, "queryrow", NULL, 0, &s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, aggregation) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *aggrFunction_param = NULL, *field_param = NULL, *where = NULL, where_sub, s, _0, _1, _2, _3;
	zval aggrFunction, field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&aggrFunction);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &aggrFunction_param, &field_param, &where);

	zephir_get_strval(&aggrFunction, aggrFunction_param);
	zephir_get_strval(&field, field_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	zephir_read_property(&_0, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "makewhere", NULL, 0, where);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "SELECT %s(%s) FROM %s%s");
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_2, &aggrFunction, &field, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "querycell", NULL, 0, &s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, countAll) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL, where_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &where);

	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "COUNT");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "*");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "aggregation", NULL, 0, &_1, &_2, where);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_0));

}

PHP_METHOD(Nc_Db_DaoAbstract, count) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *where = NULL, where_sub, _0, _1;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &where);

	zephir_get_strval(&field, field_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "COUNT");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "aggregation", NULL, 0, &_1, &field, where);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_0));

}

PHP_METHOD(Nc_Db_DaoAbstract, max) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *where = NULL, where_sub, _0;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &where);

	zephir_get_strval(&field, field_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "MAX");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, &_0, &field, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, min) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *where = NULL, where_sub, _0;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &where);

	zephir_get_strval(&field, field_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "MIN");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, &_0, &field, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, sum) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *where = NULL, where_sub, _0;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &where);

	zephir_get_strval(&field, field_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SUM");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, &_0, &field, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, avg) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *where = NULL, where_sub, _0;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field_param, &where);

	zephir_get_strval(&field, field_param);
	if (!where) {
		where = &where_sub;
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "AVG");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, &_0, &field, where);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, makeWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval connector, _0$$4;
	zval *where, where_sub, *connector_param = NULL, s;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&connector);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &where, &connector_param);

	if (!connector_param) {
		ZEPHIR_INIT_VAR(&connector);
		ZVAL_STRING(&connector, " WHERE ");
	} else {
		zephir_get_strval(&connector, connector_param);
	}


	if (Z_TYPE_P(where) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&s, this_ptr, "parsewhere", NULL, 0, where);
		zephir_check_call_status();
	} else {
		zephir_get_strval(&_0$$4, where);
		ZEPHIR_CPY_WRT(&s, &_0$$4);
	}
	if (zephir_fast_strlen_ev(&s) > 0) {
		ZEPHIR_CONCAT_VV(return_value, &connector, &s);
		RETURN_MM();
	}
	RETURN_CCTOR(&s);

}

PHP_METHOD(Nc_Db_DaoAbstract, parseWhere) {

	zend_bool _15$$8, _22$$10, _27$$12, _33$$14, _38$$16, _45$$18, _51$$20;
	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_8 = NULL, *_18 = NULL, *_21 = NULL, *_32 = NULL, *_43 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sep, _9$$3, _11$$3;
	zval *where_param = NULL, *sep_param = NULL, k, v, ws, ks, k1, k2, *_0, _3$$5, _4$$5, _5$$5, _6$$6, _7$$3, _10$$3, _12$$7, _13$$7, _14$$7, _19$$8, _20$$8, _16$$9, _17$$9, _25$$10, _26$$10, _23$$11, _24$$11, _30$$12, _31$$12, _28$$13, _29$$13, _36$$14, _37$$14, _34$$15, _35$$15, _41$$16, _42$$16, _44$$16, _39$$17, _40$$17, _48$$18, _49$$18, _50$$18, _46$$19, _47$$19, _54$$20, _55$$20, _56$$20, _52$$21, _53$$21, _57$$22, _58$$22;
	zval where;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&ws);
	ZVAL_UNDEF(&ks);
	ZVAL_UNDEF(&k1);
	ZVAL_UNDEF(&k2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_41$$16);
	ZVAL_UNDEF(&_42$$16);
	ZVAL_UNDEF(&_44$$16);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_48$$18);
	ZVAL_UNDEF(&_49$$18);
	ZVAL_UNDEF(&_50$$18);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&_55$$20);
	ZVAL_UNDEF(&_56$$20);
	ZVAL_UNDEF(&_52$$21);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_57$$22);
	ZVAL_UNDEF(&_58$$22);
	ZVAL_UNDEF(&sep);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &where_param, &sep_param);

	zephir_get_arrval(&where, where_param);
	if (!sep_param) {
		ZEPHIR_INIT_VAR(&sep);
		ZVAL_STRING(&sep, " AND ");
	} else {
		zephir_get_strval(&sep, sep_param);
	}


	ZEPHIR_INIT_VAR(&ws);
	array_init(&ws);
	zephir_is_iterable(&where, 0, "nc/db/daoabstract.zep", 453);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&where), _1, _2, _0)
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
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SVS(&_5$$5, "(", &_4$$5, ")");
				zephir_array_append(&ws, &_5$$5, PH_SEPARATE, "nc/db/daoabstract.zep", 386);
			} else {
				ZEPHIR_INIT_LNVAR(_6$$6);
				ZEPHIR_CONCAT_SVS(&_6$$6, "(", &v, ")");
				zephir_array_append(&ws, &_6$$6, PH_SEPARATE, "nc/db/daoabstract.zep", 388);
			}
			continue;
		}
		ZEPHIR_INIT_NVAR(&ks);
		zephir_fast_explode_str(&ks, SL("$"), &k, 3  TSRMLS_CC);
		ZEPHIR_MAKE_REF(&ks);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "array_shift", &_8, 4, &ks);
		ZEPHIR_UNREF(&ks);
		zephir_check_call_status();
		zephir_get_strval(&_9$$3, &_7$$3);
		ZEPHIR_CPY_WRT(&k1, &_9$$3);
		ZEPHIR_MAKE_REF(&ks);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "array_shift", &_8, 4, &ks);
		ZEPHIR_UNREF(&ks);
		zephir_check_call_status();
		zephir_get_strval(&_11$$3, &_10$$3);
		ZEPHIR_CPY_WRT(&k2, &_11$$3);
		if (ZEPHIR_IS_STRING_IDENTICAL(&k2, "")) {
			zephir_read_property(&_12$$7, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_13$$7, &_12$$7, "quote", NULL, 0, &v);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_14$$7);
			ZEPHIR_CONCAT_VSV(&_14$$7, &k1, " ", &_13$$7);
			zephir_array_append(&ws, &_14$$7, PH_SEPARATE, "nc/db/daoabstract.zep", 398);
			continue;
		}
		do {
			if (ZEPHIR_IS_STRING(&k2, "in")) {
				_15$$8 = Z_TYPE_P(&v) == IS_ARRAY;
				if (_15$$8) {
					_15$$8 = zephir_fast_count_int(&v TSRMLS_CC) < 1;
				}
				if (UNEXPECTED(_15$$8)) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					object_init_ex(&_16$$9, nc_db_exception_ce);
					ZVAL_LONG(&_17$$9, 6);
					ZEPHIR_CALL_METHOD(NULL, &_16$$9, "__construct", &_18, 3, &k2, &_17$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$9, "nc/db/daoabstract.zep", 405 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_BOOL(&_20$$8, 0);
				ZEPHIR_CALL_METHOD(&_19$$8, this_ptr, "parsewherein", &_21, 0, &k1, &v, &_20$$8);
				zephir_check_call_status();
				zephir_array_append(&ws, &_19$$8, PH_SEPARATE, "nc/db/daoabstract.zep", 407);
				break;
			}
			if (ZEPHIR_IS_STRING(&k2, "notIn")) {
				_22$$10 = Z_TYPE_P(&v) == IS_ARRAY;
				if (_22$$10) {
					_22$$10 = zephir_fast_count_int(&v TSRMLS_CC) < 1;
				}
				if (UNEXPECTED(_22$$10)) {
					ZEPHIR_INIT_NVAR(&_23$$11);
					object_init_ex(&_23$$11, nc_db_exception_ce);
					ZVAL_LONG(&_24$$11, 6);
					ZEPHIR_CALL_METHOD(NULL, &_23$$11, "__construct", &_18, 3, &k2, &_24$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_23$$11, "nc/db/daoabstract.zep", 411 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_BOOL(&_26$$10, 1);
				ZEPHIR_CALL_METHOD(&_25$$10, this_ptr, "parsewherein", &_21, 0, &k1, &v, &_26$$10);
				zephir_check_call_status();
				zephir_array_append(&ws, &_25$$10, PH_SEPARATE, "nc/db/daoabstract.zep", 413);
				break;
			}
			if (ZEPHIR_IS_STRING(&k2, "between")) {
				_27$$12 = Z_TYPE_P(&v) != IS_ARRAY;
				if (!(_27$$12)) {
					_27$$12 = zephir_fast_count_int(&v TSRMLS_CC) != 2;
				}
				if (UNEXPECTED(_27$$12)) {
					ZEPHIR_INIT_NVAR(&_28$$13);
					object_init_ex(&_28$$13, nc_db_exception_ce);
					ZVAL_LONG(&_29$$13, 6);
					ZEPHIR_CALL_METHOD(NULL, &_28$$13, "__construct", &_18, 3, &k2, &_29$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_28$$13, "nc/db/daoabstract.zep", 418 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_BOOL(&_31$$12, 0);
				ZEPHIR_CALL_METHOD(&_30$$12, this_ptr, "parsewherebetween", &_32, 0, &k1, &v, &_31$$12);
				zephir_check_call_status();
				zephir_array_append(&ws, &_30$$12, PH_SEPARATE, "nc/db/daoabstract.zep", 420);
				break;
			}
			if (ZEPHIR_IS_STRING(&k2, "notBetween")) {
				_33$$14 = Z_TYPE_P(&v) != IS_ARRAY;
				if (!(_33$$14)) {
					_33$$14 = zephir_fast_count_int(&v TSRMLS_CC) != 2;
				}
				if (UNEXPECTED(_33$$14)) {
					ZEPHIR_INIT_NVAR(&_34$$15);
					object_init_ex(&_34$$15, nc_db_exception_ce);
					ZVAL_LONG(&_35$$15, 6);
					ZEPHIR_CALL_METHOD(NULL, &_34$$15, "__construct", &_18, 3, &k2, &_35$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_34$$15, "nc/db/daoabstract.zep", 424 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_BOOL(&_37$$14, 1);
				ZEPHIR_CALL_METHOD(&_36$$14, this_ptr, "parsewherebetween", &_32, 0, &k1, &v, &_37$$14);
				zephir_check_call_status();
				zephir_array_append(&ws, &_36$$14, PH_SEPARATE, "nc/db/daoabstract.zep", 426);
				break;
			}
			if (ZEPHIR_IS_STRING(&k2, "and")) {
				_38$$16 = Z_TYPE_P(&v) != IS_ARRAY;
				if (!(_38$$16)) {
					_38$$16 = zephir_fast_count_int(&v TSRMLS_CC) < 1;
				}
				if (UNEXPECTED(_38$$16)) {
					ZEPHIR_INIT_NVAR(&_39$$17);
					object_init_ex(&_39$$17, nc_db_exception_ce);
					ZVAL_LONG(&_40$$17, 6);
					ZEPHIR_CALL_METHOD(NULL, &_39$$17, "__construct", &_18, 3, &k2, &_40$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_39$$17, "nc/db/daoabstract.zep", 431 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_42$$16);
				ZVAL_STRING(&_42$$16, " AND ");
				ZEPHIR_CALL_METHOD(&_41$$16, this_ptr, "parsewhere", &_43, 5, &v, &_42$$16);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_44$$16);
				ZEPHIR_CONCAT_SVS(&_44$$16, "(", &_41$$16, ")");
				zephir_array_append(&ws, &_44$$16, PH_SEPARATE, "nc/db/daoabstract.zep", 433);
				break;
			}
			if (ZEPHIR_IS_STRING(&k2, "or")) {
				_45$$18 = Z_TYPE_P(&v) != IS_ARRAY;
				if (!(_45$$18)) {
					_45$$18 = zephir_fast_count_int(&v TSRMLS_CC) < 1;
				}
				if (UNEXPECTED(_45$$18)) {
					ZEPHIR_INIT_NVAR(&_46$$19);
					object_init_ex(&_46$$19, nc_db_exception_ce);
					ZVAL_LONG(&_47$$19, 6);
					ZEPHIR_CALL_METHOD(NULL, &_46$$19, "__construct", &_18, 3, &k2, &_47$$19);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_46$$19, "nc/db/daoabstract.zep", 437 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_49$$18);
				ZVAL_STRING(&_49$$18, " OR ");
				ZEPHIR_CALL_METHOD(&_48$$18, this_ptr, "parsewhere", &_43, 5, &v, &_49$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_50$$18);
				ZEPHIR_CONCAT_SVS(&_50$$18, "(", &_48$$18, ")");
				zephir_array_append(&ws, &_50$$18, PH_SEPARATE, "nc/db/daoabstract.zep", 439);
				break;
			}
			if (ZEPHIR_IS_STRING(&k2, "xor")) {
				_51$$20 = Z_TYPE_P(&v) != IS_ARRAY;
				if (!(_51$$20)) {
					_51$$20 = zephir_fast_count_int(&v TSRMLS_CC) < 1;
				}
				if (UNEXPECTED(_51$$20)) {
					ZEPHIR_INIT_NVAR(&_52$$21);
					object_init_ex(&_52$$21, nc_db_exception_ce);
					ZVAL_LONG(&_53$$21, 6);
					ZEPHIR_CALL_METHOD(NULL, &_52$$21, "__construct", &_18, 3, &k2, &_53$$21);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_52$$21, "nc/db/daoabstract.zep", 443 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_55$$20);
				ZVAL_STRING(&_55$$20, " XOR ");
				ZEPHIR_CALL_METHOD(&_54$$20, this_ptr, "parsewhere", &_43, 5, &v, &_55$$20);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_56$$20);
				ZEPHIR_CONCAT_SVS(&_56$$20, "(", &_54$$20, ")");
				zephir_array_append(&ws, &_56$$20, PH_SEPARATE, "nc/db/daoabstract.zep", 445);
				break;
			}
			ZEPHIR_INIT_NVAR(&_57$$22);
			object_init_ex(&_57$$22, nc_db_exception_ce);
			ZVAL_LONG(&_58$$22, 6);
			ZEPHIR_CALL_METHOD(NULL, &_57$$22, "__construct", &_18, 3, &k2, &_58$$22);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_57$$22, "nc/db/daoabstract.zep", 449 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_fast_join(return_value, &sep, &ws TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, parseWhereIn) {

	zval _0$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool not;
	zval *field_param = NULL, *values, values_sub, *not_param = NULL, v, _7, _1$$3, _2$$3, _3$$3, _5$$5;
	zval field, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &values, &not_param);

	zephir_get_strval(&field, field_param);
	if (!not_param) {
		not = 0;
	} else {
		not = zephir_get_boolval(not_param);
	}


	if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("db"), PH_NOISY_CC);
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "quote");
		zephir_array_fast_append(&_0$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_map", NULL, 6, &_0$$3, values);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&v);
		zephir_fast_join_str(&v, SL(", "), &_3$$3 TSRMLS_CC);
	} else {
		zephir_get_strval(&_4$$4, values);
		ZEPHIR_CPY_WRT(&v, &_4$$4);
	}
	if (not) {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "%s NOT IN (%s)");
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_6, 2, &_5$$5, &field, &v);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "%s IN (%s)");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_6, 2, &_7, &field, &v);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, parseWhereBetween) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	zend_bool not;
	zval values;
	zval *field_param = NULL, *values_param = NULL, *not_param = NULL, v1, v2, _0, _1, _3, _4, _7, _5$$3;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&v1);
	ZVAL_UNDEF(&v2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &field_param, &values_param, &not_param);

	zephir_get_strval(&field, field_param);
	zephir_get_arrval(&values, values_param);
	if (!not_param) {
		not = 0;
	} else {
		not = zephir_get_boolval(not_param);
	}


	zephir_read_property(&_0, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&values);
	ZEPHIR_CALL_FUNCTION(&_1, "array_shift", &_2, 4, &values);
	ZEPHIR_UNREF(&values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&v1, &_0, "quote", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&values);
	ZEPHIR_CALL_FUNCTION(&_4, "array_shift", &_2, 4, &values);
	ZEPHIR_UNREF(&values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&v2, &_3, "quote", NULL, 0, &_4);
	zephir_check_call_status();
	if (not) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "%s NOT BETWEEN %s AND %s");
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_6, 2, &_5$$3, &field, &v1, &v2);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "%s BETWEEN %s AND %s");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_6, 2, &_7, &field, &v1, &v2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DaoAbstract, makeOrder) {

	zval _8$$10;
	zend_string *_4$$5;
	zend_ulong _3$$5;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *order, order_sub, s, a, k, v, _0$$4, *_2$$5, _7$$5, _5$$8, _6$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &order);



	ZEPHIR_INIT_VAR(&s);
	ZVAL_STRING(&s, " ORDER BY ");
	while (1) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(order)) {
			ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "makerandomorder", &_1, 0);
			zephir_check_call_status();
			zephir_concat_self(&s, &_0$$4 TSRMLS_CC);
			break;
		}
		if (Z_TYPE_P(order) == IS_ARRAY) {
			if (UNEXPECTED(zephir_fast_count_int(order TSRMLS_CC) < 1)) {
				RETURN_MM_STRING("");
			}
			ZEPHIR_INIT_NVAR(&a);
			array_init(&a);
			zephir_is_iterable(order, 0, "nc/db/daoabstract.zep", 509);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(order), _3$$5, _4$$5, _2$$5)
			{
				ZEPHIR_INIT_NVAR(&k);
				if (_4$$5 != NULL) { 
					ZVAL_STR_COPY(&k, _4$$5);
				} else {
					ZVAL_LONG(&k, _3$$5);
				}
				ZEPHIR_INIT_NVAR(&v);
				ZVAL_COPY(&v, _2$$5);
				if (zephir_is_true(&v)) {
					ZEPHIR_INIT_LNVAR(_5$$8);
					ZEPHIR_CONCAT_VS(&_5$$8, &k, " ASC");
					zephir_array_append(&a, &_5$$8, PH_SEPARATE, "nc/db/daoabstract.zep", 504);
				} else {
					ZEPHIR_INIT_LNVAR(_6$$9);
					ZEPHIR_CONCAT_VS(&_6$$9, &k, " DESC");
					zephir_array_append(&a, &_6$$9, PH_SEPARATE, "nc/db/daoabstract.zep", 506);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&v);
			ZEPHIR_INIT_NVAR(&k);
			ZEPHIR_INIT_NVAR(&_7$$5);
			zephir_fast_join_str(&_7$$5, SL(", "), &a TSRMLS_CC);
			zephir_concat_self(&s, &_7$$5 TSRMLS_CC);
			break;
		}
		if (zephir_is_true(order)) {
			zephir_get_strval(&_8$$10, order);
			zephir_concat_self(&s, &_8$$10 TSRMLS_CC);
			break;
		}
		RETURN_MM_STRING("");
	}
	RETURN_CCTOR(&s);

}

PHP_METHOD(Nc_Db_DaoAbstract, makeRandomOrder) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_db_exception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "makeRandomOrder");
	ZVAL_LONG(&_2, 5);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_1, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "nc/db/daoabstract.zep", 526 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Db_DaoAbstract, makePagination) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	long limit, skip;
	zval *sql_param = NULL, *limit_param = NULL, *skip_param = NULL, _0, _1, _2;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &sql_param, &limit_param, &skip_param);

	zephir_get_strval(&sql, sql_param);
	limit = zephir_get_intval(limit_param);
	skip = zephir_get_intval(skip_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_db_exception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "makePagination");
	ZVAL_LONG(&_2, 5);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_1, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "nc/db/daoabstract.zep", 531 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

