
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
#include "kernel/time.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Db_DbAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, DbAbstract, nc, db_dbabstract, nc_db_dbabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_db_dbabstract_ce, SL("queries"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(nc_db_dbabstract_ce, SL("inTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_dbabstract_ce, SL("savepoints"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_db_dbabstract_ce, SL("nextFlag"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_db_dbabstract_ce TSRMLS_CC, 1, nc_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Db_DbAbstract, profiledQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	double t;
	zval *p = NULL;
	zval *q_param = NULL, *p_param = NULL, *t_param = NULL, *_0, _1, _2, *_3 = NULL, *_5$$3, *_6$$3;
	zval *q = NULL, *s = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &q_param, &p_param, &t_param);

	zephir_get_strval(q, q_param);
	zephir_get_arrval(p, p_param);
	t = zephir_get_doubleval(t_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	t = (double) (zephir_get_doubleval(_0) - t);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "%s # %0.3fms", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_DOUBLE(&_2, (t * 1000.0));
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 1, &_1, q, &_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(s, _4);
	if (zephir_fast_count_int(p TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_json_encode(_5$$3, &(_5$$3), p, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CONCAT_SV(_6$$3, " ", _5$$3);
		zephir_concat_self(&s, _6$$3 TSRMLS_CC);
	}
	RETURN_CTOR(s);

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

PHP_METHOD(Nc_Db_DbAbstract, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryandfetch", NULL, 0, _0, sql, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, queryAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryandfetch", NULL, 0, _0, sql, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, queryRow) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryandfetch", NULL, 0, _0, sql, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, queryCell) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryandfetch", NULL, 0, _0, sql, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, queryColumns) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryandfetch", NULL, 0, _0, sql, params);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot begin when already in transaction", "nc/db/dbabstract.zep", 67);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytobegin", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot begin transaction", "nc/db/dbabstract.zep", 71);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot commit when not in transaction", "nc/db/dbabstract.zep", 80);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytocommit", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot commit transaction", "nc/db/dbabstract.zep", 84);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback when not in transaction", "nc/db/dbabstract.zep", 93);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytorollback", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback transaction", "nc/db/dbabstract.zep", 97);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot acquire a savepoint when not in a transaction", "nc/db/dbabstract.zep", 106);
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
		zephir_throw_exception_debug(_2$$4, "nc/db/dbabstract.zep", 110 TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot release a savepoint when not in a transaction", "nc/db/dbabstract.zep", 120);
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
		zephir_throw_exception_debug(_2$$4, "nc/db/dbabstract.zep", 124 TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot release last savepoint when not in a transaction", "nc/db/dbabstract.zep", 136);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Empty savepoint stack", "nc/db/dbabstract.zep", 140);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback to a savepoint when not in a transaction", "nc/db/dbabstract.zep", 152);
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
		zephir_throw_exception_debug(_2$$4, "nc/db/dbabstract.zep", 156 TSRMLS_CC);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback to last savepoint when not in a transaction", "nc/db/dbabstract.zep", 174);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Empty savepoint stack", "nc/db/dbabstract.zep", 178);
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

PHP_METHOD(Nc_Db_DbAbstract, insert) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *returningId_param = NULL, *k = NULL, *ks = NULL, *vs = NULL, *_0 = NULL, **_3, *_5, *_6, *_7, *_8 = NULL, *_4$$3 = NULL;
	zval *table = NULL, *returningId = NULL, *s = NULL, *_9$$4;

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


	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(vs);
	array_init(vs);
	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(data, &_2, &_1, 0, 0, "nc/db/dbabstract.zep", 195);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(_0, _3);
		zephir_array_append(&ks, k, PH_SEPARATE, "nc/db/dbabstract.zep", 191);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, ":", k);
		zephir_array_append(&vs, _4$$3, PH_SEPARATE, "nc/db/dbabstract.zep", 192);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), ks TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_join_str(_6, SL(", "), vs TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVSVSVS(_7, "INSERT INTO ", table, " (", _5, ") VALUES (", _6, ")");
	zephir_get_strval(s, _7);
	if (zephir_fast_strlen_ev(returningId) > 0) {
		ZEPHIR_INIT_VAR(_9$$4);
		ZEPHIR_CONCAT_SV(_9$$4, " RETURNING ", returningId);
		zephir_concat_self(&s, _9$$4 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "querycell", NULL, 0, s, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, s, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *where_param = NULL, *_0$$3 = NULL, *_2$$3 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_1$$3 = NULL, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &where_param);

	zephir_get_strval(table, table_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SV(s, "DELETE FROM ", table);
	if (zephir_fast_count_int(where TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "parsewhere", NULL, 0, where);
		zephir_check_call_status();
		zephir_get_strval(_1$$3, _0$$3);
		ZEPHIR_CPY_WRT(w, _1$$3);
		if (zephir_fast_strlen_ev(w) > 0) {
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_CONCAT_SV(_3$$4, " WHERE ", w);
			zephir_concat_self(&s, _3$$4 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, s);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, update) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *where = NULL;
	zval *table_param = NULL, *data_param = NULL, *where_param = NULL, *k = NULL, *kvs = NULL, *_0 = NULL, **_3, *_5, *_6, *_4$$3 = NULL, *_7$$4 = NULL, *_9$$4 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_8$$4 = NULL, *_10$$5;

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


	ZEPHIR_INIT_VAR(kvs);
	array_init(kvs);
	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(data, &_2, &_1, 0, 0, "nc/db/dbabstract.zep", 229);
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
	if (zephir_fast_count_int(where TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "parsewhere", NULL, 0, where);
		zephir_check_call_status();
		zephir_get_strval(_8$$4, _7$$4);
		ZEPHIR_CPY_WRT(w, _8$$4);
		if (zephir_fast_strlen_ev(w) > 0) {
			ZEPHIR_INIT_VAR(_10$$5);
			ZEPHIR_CONCAT_SV(_10$$5, " WHERE ", w);
			zephir_concat_self(&s, _10$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, s, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, upsert) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *primaryKey = NULL, *k = NULL, *v = NULL, *where = NULL, **_2$$3, *_3$$5 = NULL, *_4$$5 = NULL, *_7$$8, *_8$$8;
	zval *table = NULL, *_6$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &primaryKey);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);
	if (!primaryKey) {
		ZEPHIR_INIT_VAR(primaryKey);
		ZVAL_STRING(primaryKey, "id", 1);
	}


	ZEPHIR_INIT_VAR(where);
	array_init(where);
	if (Z_TYPE_P(primaryKey) == IS_ARRAY) {
		zephir_is_iterable(primaryKey, &_1$$3, &_0$$3, 0, 0, "nc/db/dbabstract.zep", 252);
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
				zephir_throw_exception_debug(_3$$5, "nc/db/dbabstract.zep", 248 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&where, k, &v, PH_COPY | PH_SEPARATE);
		}
		if (unlikely(!zephir_is_true(where))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Cannot upsert with empty where", "nc/db/dbabstract.zep", 253);
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
			zephir_throw_exception_debug(_7$$8, "nc/db/dbabstract.zep", 258 TSRMLS_CC);
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

PHP_METHOD(Nc_Db_DbAbstract, parseSelect) {

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
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "parsewhere", NULL, 0, where);
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
			ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "parserandomorder", NULL, 0);
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
		ZEPHIR_CALL_METHOD(&_22$$9, this_ptr, "parsepagination", NULL, 0, s, _23$$9, _24$$9);
		zephir_check_call_status();
		zephir_get_strval(_25$$9, _22$$9);
		ZEPHIR_CPY_WRT(s, _25$$9);
	}
	if (forUpdate) {
		zephir_concat_self_str(&s, " FOR UPDATE", sizeof(" FOR UPDATE")-1 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_Db_DbAbstract, select) {

	int ZEPHIR_LAST_CALL_STATUS;
	long fetch;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *fetch_param = NULL, *_0 = NULL, *_1;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table_param, &options_param, &fetch_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fetch_param) {
		fetch = 1;
	} else {
		fetch = zephir_get_intval(fetch_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseselect", NULL, 0, table, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, fetch);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryandfetch", NULL, 0, _1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, selectRow) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *_0;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "select", NULL, 0, table, options, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, selectCell) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *_0;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "select", NULL, 0, table, options, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, selectColumns) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *_0;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "select", NULL, 0, table, options, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, countAndSelect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	long fetch, c = 0;
	zval *options = NULL, *_4 = NULL;
	zval *table_param = NULL, *options_param = NULL, *fetch_param = NULL, *where = NULL, *_0 = NULL, *_2, *_3 = NULL, *_9 = NULL, *_11 = NULL, *_5$$3 = NULL, *_7$$3 = NULL, *_10$$5 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_6$$3 = NULL, *_8$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table_param, &options_param, &fetch_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fetch_param) {
		fetch = 1;
	} else {
		fetch = zephir_get_intval(fetch_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SV(s, "SELECT COUNT(*) FROM ", table);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 5, options, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_arrval(_4, _0);
	ZEPHIR_CPY_WRT(where, _4);
	if (zephir_fast_count_int(where TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "parsewhere", NULL, 0, where);
		zephir_check_call_status();
		zephir_get_strval(_6$$3, _5$$3);
		ZEPHIR_CPY_WRT(w, _6$$3);
		if (zephir_fast_strlen_ev(w) > 0) {
			ZEPHIR_INIT_VAR(_8$$4);
			ZEPHIR_CONCAT_SV(_8$$4, " WHERE ", w);
			zephir_concat_self(&s, _8$$4 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	c = zephir_get_intval(_9);
	if (c < 1) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10$$5);
		ZVAL_LONG(_10$$5, 0);
		zephir_array_fast_append(return_value, _10$$5);
		ZEPHIR_INIT_NVAR(_10$$5);
		array_init(_10$$5);
		zephir_array_fast_append(return_value, _10$$5);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, c);
	zephir_array_fast_append(return_value, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, fetch);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "select", NULL, 0, table, options, _3);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _11);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, selectUnionAll) {

	zend_bool _3$$4;
	HashTable *_1;
	HashPosition _0;
	zval *s = NULL, *_8 = NULL, *_11 = NULL, *_18$$7 = NULL, *_19$$7, *_20$$8 = NULL, *_21$$8, *_25$$9 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long fetch, limit = 0, skip = 0;
	zval *selects_param = NULL, *options_param = NULL, *fetch_param = NULL, *i = NULL, *t = NULL, *a = NULL, *orderBy = NULL, **_2, *_7, *_9 = NULL, *_10 = NULL, *_13 = NULL, *_14, *_15 = NULL, *_16 = NULL, *_6$$4 = NULL, *_4$$5 = NULL, *_17$$7 = NULL, *_22$$9 = NULL, *_23$$9, *_24$$9;
	zval *selects = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &selects_param, &options_param, &fetch_param);

	zephir_get_arrval(selects, selects_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fetch_param) {
		fetch = 1;
	} else {
		fetch = zephir_get_intval(fetch_param);
	}


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	if (zephir_fast_count_int(selects TSRMLS_CC) < 1) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_is_iterable(selects, &_1, &_0, 0, 0, "nc/db/dbabstract.zep", 380);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(i, _2);
		_3$$4 = Z_TYPE_P(i) == IS_ARRAY;
		if (_3$$4) {
			ZEPHIR_OBS_NVAR(t);
			_3$$4 = zephir_array_isset_string_fetch(&t, i, SS("table"), 0 TSRMLS_CC);
		}
		if (_3$$4) {
			ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "parseselect", &_5, 0, t, i);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(i, _4$$5);
		}
		ZEPHIR_INIT_LNVAR(_6$$4);
		ZEPHIR_CONCAT_SVS(_6$$4, "(", i, ")");
		zephir_array_append(&a, _6$$4, PH_SEPARATE, "nc/db/dbabstract.zep", 377);
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_fast_join_str(_7, SL(" UNION ALL "), a TSRMLS_CC);
	zephir_get_strval(_8, _7);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "u", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "nextflag", NULL, 0, _10);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	zephir_get_strval(_11, _9);
	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSV(s, "SELECT * FROM (", _8, ") AS ", _11);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "orderBy", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_13);
	ZVAL_NULL(_13);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_BOOL(_14, 1);
	ZEPHIR_CALL_CE_STATIC(&orderBy, nc_std_ce, "valueat", &_12, 5, options, _10, _13, _14);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "limit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_13);
	ZVAL_LONG(_13, 0);
	ZEPHIR_CALL_CE_STATIC(&_15, nc_std_ce, "valueat", &_12, 5, options, _10, _13);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	limit = zephir_get_intval(_15);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "skip", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_13);
	ZVAL_LONG(_13, 0);
	ZEPHIR_CALL_CE_STATIC(&_16, nc_std_ce, "valueat", &_12, 5, options, _10, _13);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	skip = zephir_get_intval(_16);
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "parserandomorder", NULL, 0);
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
		ZEPHIR_CALL_METHOD(&_22$$9, this_ptr, "parsepagination", NULL, 0, s, _23$$9, _24$$9);
		zephir_check_call_status();
		zephir_get_strval(_25$$9, _22$$9);
		ZEPHIR_CPY_WRT(s, _25$$9);
	}
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_LONG(_10, fetch);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryandfetch", NULL, 0, _10, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, countAndSelectUnionAll) {

	zend_bool _4$$4;
	HashTable *_2;
	HashPosition _1;
	zval *s = NULL, *_9 = NULL, *_12 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long fetch, c = 0;
	zval *selects_param = NULL, *options_param = NULL, *fetch_param = NULL, *i = NULL, *t = NULL, *a = NULL, **_3, *_8, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_0$$3 = NULL, *_7$$4 = NULL, *_5$$5 = NULL, *_14$$6 = NULL;
	zval *selects = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &selects_param, &options_param, &fetch_param);

	zephir_get_arrval(selects, selects_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fetch_param) {
		fetch = 1;
	} else {
		fetch = zephir_get_intval(fetch_param);
	}


	ZEPHIR_INIT_VAR(a);
	array_init(a);
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
	zephir_is_iterable(selects, &_2, &_1, 0, 0, "nc/db/dbabstract.zep", 419);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(i, _3);
		_4$$4 = Z_TYPE_P(i) == IS_ARRAY;
		if (_4$$4) {
			ZEPHIR_OBS_NVAR(t);
			_4$$4 = zephir_array_isset_string_fetch(&t, i, SS("table"), 0 TSRMLS_CC);
		}
		if (_4$$4) {
			ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "parseselect", &_6, 0, t, i);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(i, _5$$5);
		}
		ZEPHIR_INIT_LNVAR(_7$$4);
		ZEPHIR_CONCAT_SVS(_7$$4, "(", i, ")");
		zephir_array_append(&a, _7$$4, PH_SEPARATE, "nc/db/dbabstract.zep", 416);
	}
	ZEPHIR_INIT_VAR(_8);
	zephir_fast_join_str(_8, SL(" UNION ALL "), a TSRMLS_CC);
	zephir_get_strval(_9, _8);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "u", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "nextflag", NULL, 0, _11);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	zephir_get_strval(_12, _10);
	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSV(s, "SELECT COUNT(*) FROM (", _9, ") AS ", _12);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	c = zephir_get_intval(_13);
	if (c < 1) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_14$$6);
		ZVAL_LONG(_14$$6, 0);
		zephir_array_fast_append(return_value, _14$$6);
		ZEPHIR_INIT_NVAR(_14$$6);
		array_init(_14$$6);
		zephir_array_fast_append(return_value, _14$$6);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, c);
	zephir_array_fast_append(return_value, _11);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, fetch);
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "selectunionall", NULL, 0, selects, options, _11);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _15);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "aggregation", NULL, 0, table, _1, column, where);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, table, _0, column, where);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, table, _0, column, where);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, table, _0, column, where);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregation", NULL, 0, table, _0, column, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, aggregation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *aggregationFunction_param = NULL, *column_param = NULL, *where_param = NULL, *_0$$3 = NULL, *_2$$3 = NULL;
	zval *table = NULL, *aggregationFunction = NULL, *column = NULL, *s = NULL, *w = NULL, *_1$$3 = NULL, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &aggregationFunction_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(aggregationFunction, aggregationFunction_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSVSV(s, "SELECT ", aggregationFunction, "(", column, ") FROM ", table);
	if (zephir_fast_count_int(where TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "parsewhere", NULL, 0, where);
		zephir_check_call_status();
		zephir_get_strval(_1$$3, _0$$3);
		ZEPHIR_CPY_WRT(w, _1$$3);
		if (zephir_fast_strlen_ev(w) > 0) {
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_CONCAT_SV(_3$$4, " WHERE ", w);
			zephir_concat_self(&s, _3$$4 TSRMLS_CC);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, aggregations) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations = NULL, *where = NULL;
	zval *table_param = NULL, *aggregations_param = NULL, *where_param = NULL, *k = NULL, *v = NULL, *a = NULL, **_2, *_4, *_5, *_3$$3 = NULL, *_6$$4 = NULL, *_8$$4 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_7$$4 = NULL, *_9$$5;

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


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	zephir_is_iterable(aggregations, &_1, &_0, 0, 0, "nc/db/dbabstract.zep", 482);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSV(_3$$3, v, " AS ", k);
		zephir_array_append(&a, _3$$3, PH_SEPARATE, "nc/db/dbabstract.zep", 479);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), a TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVSV(_5, "SELECT ", _4, " FROM ", table);
	zephir_get_strval(s, _5);
	if (zephir_fast_count_int(where TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "parsewhere", NULL, 0, where);
		zephir_check_call_status();
		zephir_get_strval(_7$$4, _6$$4);
		ZEPHIR_CPY_WRT(w, _7$$4);
		if (zephir_fast_strlen_ev(w) > 0) {
			ZEPHIR_INIT_VAR(_9$$5);
			ZEPHIR_CONCAT_SV(_9$$5, " WHERE ", w);
			zephir_concat_self(&s, _9$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryrow", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, groupAggregations) {

	HashTable *_11;
	HashPosition _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_16 = NULL;
	zval *aggregations = NULL, *options = NULL, *_4 = NULL, *_7 = NULL;
	zval *table_param = NULL, *groupBy_param = NULL, *aggregations_param = NULL, *options_param = NULL, *where = NULL, *having = NULL, *orderBy = NULL, *k = NULL, *v = NULL, *a = NULL, *_0 = NULL, *_2, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_8, *_9, **_12, *_14, *_13$$3 = NULL, *_15$$4 = NULL, *_18$$4 = NULL, *_21$$6 = NULL, *_23$$6 = NULL, *_25$$9 = NULL;
	zval *table = NULL, *groupBy = NULL, *s = NULL, *w = NULL, *_20, *_17$$4 = NULL, *_19$$5, *_22$$6 = NULL, *_24$$7, *_26$$9 = NULL, *_27$$9, *_28$$10 = NULL, *_29$$10;

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
	zephir_array_append(&a, groupBy, PH_SEPARATE, "nc/db/dbabstract.zep", 505);
	zephir_is_iterable(aggregations, &_11, &_10, 0, 0, "nc/db/dbabstract.zep", 511);
	for (
	  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
	  ; zephir_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HMKEY(k, _11, _10);
		ZEPHIR_GET_HVALUE(v, _12);
		ZEPHIR_INIT_LNVAR(_13$$3);
		ZEPHIR_CONCAT_VSVSV(_13$$3, v, "(", groupBy, ") AS ", k);
		zephir_array_append(&a, _13$$3, PH_SEPARATE, "nc/db/dbabstract.zep", 508);
	}
	ZEPHIR_INIT_NVAR(_6);
	zephir_fast_join_str(_6, SL(", "), a TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_SVSV(_14, "SELECT ", _6, " FROM ", table);
	zephir_get_strval(s, _14);
	if (zephir_fast_count_int(where TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_15$$4, this_ptr, "parsewhere", &_16, 0, where);
		zephir_check_call_status();
		zephir_get_strval(_17$$4, _15$$4);
		ZEPHIR_CPY_WRT(w, _17$$4);
		if (zephir_fast_strlen_ev(w) > 0) {
			ZEPHIR_INIT_VAR(_19$$5);
			ZEPHIR_CONCAT_SV(_19$$5, " WHERE ", w);
			zephir_concat_self(&s, _19$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(_20);
	ZEPHIR_CONCAT_SV(_20, " GROUP BY ", groupBy);
	zephir_concat_self(&s, _20 TSRMLS_CC);
	if (zephir_fast_count_int(having TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_21$$6, this_ptr, "parsewhere", &_16, 0, having);
		zephir_check_call_status();
		zephir_get_strval(_22$$6, _21$$6);
		ZEPHIR_CPY_WRT(w, _22$$6);
		if (zephir_fast_strlen_ev(w) > 0) {
			ZEPHIR_INIT_VAR(_24$$7);
			ZEPHIR_CONCAT_SV(_24$$7, " HAVING ", w);
			zephir_concat_self(&s, _24$$7 TSRMLS_CC);
		}
	}
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_25$$9, this_ptr, "parserandomorder", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_26$$9, _25$$9);
			ZEPHIR_INIT_VAR(_27$$9);
			ZEPHIR_CONCAT_SV(_27$$9, " ORDER BY ", _26$$9);
			zephir_concat_self(&s, _27$$9 TSRMLS_CC);
		} else {
			zephir_get_strval(_28$$10, orderBy);
			ZEPHIR_INIT_VAR(_29$$10);
			ZEPHIR_CONCAT_SV(_29$$10, " ORDER BY ", _28$$10);
			zephir_concat_self(&s, _29$$10 TSRMLS_CC);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryall", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, parseWhere) {

	zend_bool _28$$15, _29$$15, _40$$20, _56$$28, _71$$31, _76$$33, _80$$35;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL, *_14 = NULL, *_17 = NULL, *_20 = NULL, *_23 = NULL, *_26 = NULL, *_32 = NULL, *_35 = NULL, *_38 = NULL, *_47 = NULL, *_50 = NULL, *_69 = NULL, *_74 = NULL, *_86 = NULL;
	zval *sep = NULL, *k1 = NULL, *k2 = NULL, *tmp = NULL, *_5$$3 = NULL, *_7$$3 = NULL, *_8$$5 = NULL, *_12$$8 = NULL, *_53$$26 = NULL, *_62$$28 = NULL, *_63$$28 = NULL, *_85$$37 = NULL;
	zval *where_param = NULL, *sep_param = NULL, *k = NULL, *v = NULL, *ks = NULL, *ws = NULL, **_2, *_3$$3 = NULL, *_6$$3 = NULL, *_9$$6 = NULL, *_11$$6 = NULL, *_13$$9 = NULL, *_15$$9 = NULL, *_16$$10 = NULL, *_18$$10 = NULL, *_19$$11 = NULL, *_21$$11 = NULL, *_22$$12 = NULL, *_24$$12 = NULL, *_25$$13 = NULL, *_27$$13 = NULL, *_30$$15 = NULL, *_31$$15, *_33$$15 = NULL, *_34$$15, *_36$$15 = NULL, *_37$$18 = NULL, *_39$$18 = NULL, _41$$20 = zval_used_for_init, *_42$$20 = NULL, *_43$$22 = NULL, *_45$$22 = NULL, *_46$$22 = NULL, *_48$$22 = NULL, *_49$$23 = NULL, _51$$25 = zval_used_for_init, *_52$$25 = NULL, *_54$$25 = NULL, *_55$$27 = NULL, *_57$$28 = NULL, *_59$$28 = NULL, *_61$$28 = NULL, *_64$$28 = NULL, *_66$$30 = NULL, *_67$$30 = NULL, *_68$$30 = NULL, *_70$$30 = NULL, *_72$$31 = NULL, *_73$$31 = NULL, *_75$$31 = NULL, *_77$$33 = NULL, *_78$$33 = NULL, *_79$$33 = NULL, *_81$$35 = NULL, *_82$$35 = NULL, *_83$$35 = NULL, *_84$$37 = NULL;
	zval *where = NULL, *_44$$22 = NULL, *_58$$28 = NULL, *_60$$28 = NULL, *_65$$30 = NULL;

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
	zephir_is_iterable(where, &_1, &_0, 0, 0, "nc/db/dbabstract.zep", 650);
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
					zephir_array_append(&ws, _8$$5, PH_SEPARATE, "nc/db/dbabstract.zep", 554);
				} else {
					ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "quote", &_10, 0, v);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_11$$6);
					ZEPHIR_CONCAT_VSV(_11$$6, k1, " = ", _9$$6);
					zephir_array_append(&ws, _11$$6, PH_SEPARATE, "nc/db/dbabstract.zep", 556);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "neq")) {
				if (Z_TYPE_P(v) == IS_NULL) {
					ZEPHIR_INIT_LNVAR(_12$$8);
					ZEPHIR_CONCAT_VS(_12$$8, k1, "IS NOT NULL");
					zephir_array_append(&ws, _12$$8, PH_SEPARATE, "nc/db/dbabstract.zep", 561);
				} else {
					ZEPHIR_CALL_METHOD(&_13$$9, this_ptr, "quote", &_14, 0, v);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_15$$9);
					ZEPHIR_CONCAT_VSV(_15$$9, k1, " <> ", _13$$9);
					zephir_array_append(&ws, _15$$9, PH_SEPARATE, "nc/db/dbabstract.zep", 563);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "lt")) {
				ZEPHIR_CALL_METHOD(&_16$$10, this_ptr, "quote", &_17, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_18$$10);
				ZEPHIR_CONCAT_VSV(_18$$10, k1, " < ", _16$$10);
				zephir_array_append(&ws, _18$$10, PH_SEPARATE, "nc/db/dbabstract.zep", 567);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "lte")) {
				ZEPHIR_CALL_METHOD(&_19$$11, this_ptr, "quote", &_20, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_21$$11);
				ZEPHIR_CONCAT_VSV(_21$$11, k1, " <= ", _19$$11);
				zephir_array_append(&ws, _21$$11, PH_SEPARATE, "nc/db/dbabstract.zep", 570);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "gt")) {
				ZEPHIR_CALL_METHOD(&_22$$12, this_ptr, "quote", &_23, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_24$$12);
				ZEPHIR_CONCAT_VSV(_24$$12, k1, " > ", _22$$12);
				zephir_array_append(&ws, _24$$12, PH_SEPARATE, "nc/db/dbabstract.zep", 573);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "gte")) {
				ZEPHIR_CALL_METHOD(&_25$$13, this_ptr, "quote", &_26, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_27$$13);
				ZEPHIR_CONCAT_VSV(_27$$13, k1, " >= ", _25$$13);
				zephir_array_append(&ws, _27$$13, PH_SEPARATE, "nc/db/dbabstract.zep", 576);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notBetween")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "between")) {
				_28$$15 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_28$$15)) {
					_28$$15 = !(zephir_array_isset_long(v, 0));
				}
				_29$$15 = _28$$15;
				if (!(_29$$15)) {
					_29$$15 = !(zephir_array_isset_long(v, 1));
				}
				if (unlikely(_29$$15)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid between", "nc/db/dbabstract.zep", 582);
					return;
				}
				zephir_array_fetch_long(&_31$$15, v, 0, PH_NOISY | PH_READONLY, "nc/db/dbabstract.zep", 584 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_30$$15, this_ptr, "quote", &_32, 0, _31$$15);
				zephir_check_call_status();
				zephir_array_fetch_long(&_34$$15, v, 1, PH_NOISY | PH_READONLY, "nc/db/dbabstract.zep", 584 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_33$$15, this_ptr, "quote", &_35, 0, _34$$15);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_36$$15);
				ZEPHIR_CONCAT_VVSVSV(_36$$15, k1, tmp, " BETWEEN ", _30$$15, " AND ", _33$$15);
				zephir_array_append(&ws, _36$$15, PH_SEPARATE, "nc/db/dbabstract.zep", 584);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notLike")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "like")) {
				ZEPHIR_CALL_METHOD(&_37$$18, this_ptr, "quote", &_38, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_39$$18);
				ZEPHIR_CONCAT_VVSV(_39$$18, k1, tmp, " LIKE ", _37$$18);
				zephir_array_append(&ws, _39$$18, PH_SEPARATE, "nc/db/dbabstract.zep", 589);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notIn")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "in")) {
				_40$$20 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_40$$20)) {
					_40$$20 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_40$$20)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid in", "nc/db/dbabstract.zep", 595);
					return;
				}
				ZEPHIR_SINIT_NVAR(_41$$20);
				ZVAL_STRING(&_41$$20, ",", 0);
				ZEPHIR_INIT_NVAR(_42$$20);
				zephir_fast_strpos(_42$$20, k1, &_41$$20, 0 );
				if (ZEPHIR_IS_FALSE_IDENTICAL(_42$$20)) {
					ZEPHIR_INIT_NVAR(_43$$22);
					ZEPHIR_INIT_NVAR(_44$$22);
					zephir_create_array(_44$$22, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_44$$22, this_ptr);
					ZEPHIR_INIT_NVAR(_45$$22);
					ZVAL_STRING(_45$$22, "quote", 1);
					zephir_array_fast_append(_44$$22, _45$$22);
					ZEPHIR_CALL_FUNCTION(&_46$$22, "array_map", &_47, 7, _44$$22, v);
					zephir_check_call_status();
					zephir_fast_join_str(_43$$22, SL(", "), _46$$22 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_48$$22);
					ZEPHIR_CONCAT_VVSVS(_48$$22, k1, tmp, " IN (", _43$$22, ")");
					zephir_array_append(&ws, _48$$22, PH_SEPARATE, "nc/db/dbabstract.zep", 598);
				} else {
					ZEPHIR_CALL_METHOD(&_49$$23, this_ptr, "parsewheremultiplein", &_50, 0, k1, v, tmp);
					zephir_check_call_status();
					zephir_array_append(&ws, _49$$23, PH_SEPARATE, "nc/db/dbabstract.zep", 600);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notInSelect")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "inSelect")) {
				ZEPHIR_SINIT_NVAR(_51$$25);
				ZVAL_STRING(&_51$$25, ",", 0);
				ZEPHIR_INIT_NVAR(_52$$25);
				zephir_fast_strpos(_52$$25, k1, &_51$$25, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(_52$$25)) {
					ZEPHIR_INIT_LNVAR(_53$$26);
					ZEPHIR_CONCAT_SVS(_53$$26, "(", k1, ")");
					ZEPHIR_CPY_WRT(k1, _53$$26);
				}
				ZEPHIR_INIT_LNVAR(_54$$25);
				ZEPHIR_CONCAT_VVSVS(_54$$25, k1, tmp, " IN (", v, ")");
				zephir_array_append(&ws, _54$$25, PH_SEPARATE, "nc/db/dbabstract.zep", 609);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "raw")) {
				ZEPHIR_INIT_LNVAR(_55$$27);
				ZEPHIR_CONCAT_SVS(_55$$27, "(", v, ")");
				zephir_array_append(&ws, _55$$27, PH_SEPARATE, "nc/db/dbabstract.zep", 613);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "expression")) {
				_56$$28 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_56$$28)) {
					_56$$28 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_56$$28)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid expression", "nc/db/dbabstract.zep", 617);
					return;
				}
				ZEPHIR_INIT_NVAR(_57$$28);
				ZEPHIR_INIT_NVAR(_58$$28);
				zephir_create_array(_58$$28, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_59$$28);
				ZVAL_STRING(_59$$28, "%", 1);
				zephir_array_fast_append(_58$$28, _59$$28);
				ZEPHIR_INIT_NVAR(_59$$28);
				ZVAL_STRING(_59$$28, "?", 1);
				zephir_array_fast_append(_58$$28, _59$$28);
				ZEPHIR_INIT_NVAR(_60$$28);
				zephir_create_array(_60$$28, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_59$$28);
				ZVAL_STRING(_59$$28, "%%", 1);
				zephir_array_fast_append(_60$$28, _59$$28);
				ZEPHIR_INIT_NVAR(_59$$28);
				ZVAL_STRING(_59$$28, "%s", 1);
				zephir_array_fast_append(_60$$28, _59$$28);
				ZEPHIR_MAKE_REF(v);
				ZEPHIR_CALL_FUNCTION(&_61$$28, "array_shift", &_4, 6, v);
				ZEPHIR_UNREF(v);
				zephir_check_call_status();
				zephir_get_strval(_62$$28, _61$$28);
				zephir_fast_str_replace(&_57$$28, _58$$28, _60$$28, _62$$28 TSRMLS_CC);
				zephir_get_strval(_63$$28, _57$$28);
				ZEPHIR_CPY_WRT(tmp, _63$$28);
				if (unlikely(zephir_fast_strlen_ev(tmp) > 0)) {
					ZEPHIR_INIT_NVAR(_65$$30);
					zephir_create_array(_65$$30, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_65$$30, this_ptr);
					ZEPHIR_INIT_NVAR(_66$$30);
					ZVAL_STRING(_66$$30, "quote", 1);
					zephir_array_fast_append(_65$$30, _66$$30);
					ZEPHIR_CALL_FUNCTION(&_67$$30, "array_map", &_47, 7, _65$$30, v);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_68$$30, "vsprintf", &_69, 8, tmp, _67$$30);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_70$$30);
					ZEPHIR_CONCAT_SVS(_70$$30, "(", _68$$30, ")");
					zephir_array_append(&ws, _70$$30, PH_SEPARATE, "nc/db/dbabstract.zep", 622);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "and")) {
				_71$$31 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_71$$31)) {
					_71$$31 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_71$$31)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid and", "nc/db/dbabstract.zep", 628);
					return;
				}
				ZEPHIR_INIT_NVAR(_73$$31);
				ZVAL_STRING(_73$$31, " AND ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_72$$31, this_ptr, "parsewhere", &_74, 9, v, _73$$31);
				zephir_check_temp_parameter(_73$$31);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_75$$31);
				ZEPHIR_CONCAT_SVS(_75$$31, "(", _72$$31, ")");
				zephir_array_append(&ws, _75$$31, PH_SEPARATE, "nc/db/dbabstract.zep", 630);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "or")) {
				_76$$33 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_76$$33)) {
					_76$$33 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_76$$33)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid or", "nc/db/dbabstract.zep", 634);
					return;
				}
				ZEPHIR_INIT_NVAR(_78$$33);
				ZVAL_STRING(_78$$33, " OR ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_77$$33, this_ptr, "parsewhere", &_74, 9, v, _78$$33);
				zephir_check_temp_parameter(_78$$33);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_79$$33);
				ZEPHIR_CONCAT_SVS(_79$$33, "(", _77$$33, ")");
				zephir_array_append(&ws, _79$$33, PH_SEPARATE, "nc/db/dbabstract.zep", 636);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "xor")) {
				_80$$35 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_80$$35)) {
					_80$$35 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_80$$35)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid xor", "nc/db/dbabstract.zep", 640);
					return;
				}
				ZEPHIR_INIT_NVAR(_82$$35);
				ZVAL_STRING(_82$$35, " XOR ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_81$$35, this_ptr, "parsewhere", &_74, 9, v, _82$$35);
				zephir_check_temp_parameter(_82$$35);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_83$$35);
				ZEPHIR_CONCAT_SVS(_83$$35, "(", _81$$35, ")");
				zephir_array_append(&ws, _83$$35, PH_SEPARATE, "nc/db/dbabstract.zep", 642);
				break;
			}
			ZEPHIR_INIT_NVAR(_84$$37);
			object_init_ex(_84$$37, nc_db_exception_ce);
			ZEPHIR_INIT_LNVAR(_85$$37);
			ZEPHIR_CONCAT_SV(_85$$37, "Invalid k2: ", k2);
			ZEPHIR_CALL_METHOD(NULL, _84$$37, "__construct", &_86, 2, _85$$37);
			zephir_check_call_status();
			zephir_throw_exception_debug(_84$$37, "nc/db/dbabstract.zep", 646 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	}
	zephir_fast_join(return_value, sep, ws TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, parseWhereMultipleIn) {

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
		zephir_throw_exception_debug(_2$$3, "nc/db/dbabstract.zep", 660 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(quoter);
	zephir_create_array(quoter, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(quoter, this_ptr);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "quote", 1);
	zephir_array_fast_append(quoter, _4);
	zephir_is_iterable(values, &_6, &_5, 0, 0, "nc/db/dbabstract.zep", 672);
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
			zephir_throw_exception_debug(_9$$5, "nc/db/dbabstract.zep", 667 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_11$$4);
		ZEPHIR_CALL_FUNCTION(&_12$$4, "array_map", &_13, 7, quoter, v);
		zephir_check_call_status();
		zephir_fast_join_str(_11$$4, SL(", "), _12$$4 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_14$$4);
		ZEPHIR_CONCAT_SVS(_14$$4, "(", _11$$4, ")");
		zephir_array_append(&vs, _14$$4, PH_SEPARATE, "nc/db/dbabstract.zep", 669);
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_fast_join_str(_4, SL(", "), vs TSRMLS_CC);
	ZEPHIR_CONCAT_SVSVSVS(return_value, "(", columns, ")", isNot, " in (", _4, ")");
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, parsePagination) {

}

PHP_METHOD(Nc_Db_DbAbstract, parseRandomOrder) {

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
	zval *prefix_param = NULL, *_0, *_1, _2, _3;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
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
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 1, &_2, prefix, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

