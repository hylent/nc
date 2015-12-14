
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
#include "kernel/object.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_PdoAbstract) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, PdoAbstract, nc, db_pdoabstract, nc_db_dbabstract_ce, nc_db_pdoabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_db_pdoabstract_ce, SL("pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_PdoAbstract, __construct) {

	zval _0, *_1 = NULL, *_2, *_3, *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "pdo", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 19, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Missing extension: pdo", "nc/db/pdoabstract.zep", 10);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Pdo", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 20, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "func_get_args", NULL, 15);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _2, "newinstanceargs", NULL, 21, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pdo"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_PdoAbstract, getInternalHandler) {

	

	RETURN_MEMBER(this_ptr, "pdo");

}

PHP_METHOD(Nc_Db_PdoAbstract, quote) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *_0;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "quote", NULL, 0, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_PdoAbstract, query) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool success = 0, _24$$14;
	double startMt = 0;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_13 = NULL, *_23 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql = NULL, *profiledQuery = NULL, *_15 = NULL, *_22$$12 = NULL;
	zval *mode_param = NULL, *sql_param = NULL, *params_param = NULL, *statement = NULL, *k = NULL, *v = NULL, *err = NULL, *resultItem = NULL, *result = NULL, *_0, *_1, *_12 = NULL, *_14 = NULL, _25, *_26 = NULL, *_27, **_4$$3, *_5$$5 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_10$$6 = NULL, *_16$$7, *_17$$7, *_18$$7, *_19$$9, *_20$$10, *_21$$12 = NULL;
	long mode;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &mode_param, &sql_param, &params_param);

	mode = zephir_get_intval(mode_param);
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
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&statement, _1, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		zephir_is_iterable(params, &_3$$3, &_2$$3, 0, 0, "nc/db/pdoabstract.zep", 45);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(k, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(v, _4$$3);
			if (Z_TYPE_P(v) == IS_STRING) {
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SV(_5$$5, ":", k);
				ZEPHIR_INIT_LNVAR(_6$$5);
				ZEPHIR_CONCAT_SV(_6$$5, "", v);
				ZEPHIR_INIT_NVAR(_7$$5);
				ZVAL_LONG(_7$$5, 2);
				ZEPHIR_INIT_NVAR(_8$$5);
				ZVAL_LONG(_8$$5, zephir_fast_strlen_ev(v));
				ZEPHIR_CALL_METHOD(NULL, statement, "bindparam", &_9, 0, _5$$5, _6$$5, _7$$5, _8$$5);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_LNVAR(_10$$6);
				ZEPHIR_CONCAT_SV(_10$$6, ":", k);
				ZEPHIR_CALL_METHOD(NULL, statement, "bindvalue", &_11, 0, _10$$6, v);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_12, statement, "execute", NULL, 0);
	zephir_check_call_status();
	success = zephir_get_boolval(_12);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_DOUBLE(_14, startMt);
	ZEPHIR_CALL_CE_STATIC(&_12, nc_db_dbabstract_ce, "profiledquery", &_13, 22, sql, params, _14);
	zephir_check_call_status();
	zephir_get_strval(_15, _12);
	ZEPHIR_CPY_WRT(profiledQuery, _15);
	zephir_update_property_array_append(this_ptr, SL("queries"), profiledQuery TSRMLS_CC);
	if (unlikely(!success)) {
		ZEPHIR_CALL_METHOD(&err, statement, "errorinfo", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_16$$7);
		object_init_ex(_16$$7, nc_db_queryexception_ce);
		zephir_array_fetch_long(&_17$$7, err, 2, PH_NOISY | PH_READONLY, "nc/db/pdoabstract.zep", 54 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_18$$7);
		ZEPHIR_CONCAT_VSV(_18$$7, _17$$7, " [SQL] ", profiledQuery);
		ZEPHIR_CALL_METHOD(NULL, _16$$7, "__construct", NULL, 2, _18$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_16$$7, "nc/db/pdoabstract.zep", 54 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (mode == 0) {
			RETURN_MM_NULL();
		}
		if (mode == 1) {
			ZEPHIR_INIT_VAR(_19$$9);
			ZVAL_LONG(_19$$9, 2);
			ZEPHIR_RETURN_CALL_METHOD(statement, "fetchall", NULL, 0, _19$$9);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (mode == 2) {
			ZEPHIR_INIT_VAR(_20$$10);
			ZVAL_LONG(_20$$10, 2);
			ZEPHIR_CALL_METHOD(&resultItem, statement, "fetch", NULL, 0, _20$$10);
			zephir_check_call_status();
			if (zephir_is_true(resultItem)) {
				RETURN_CCTOR(resultItem);
			}
			RETURN_MM_NULL();
		}
		if (mode == 3) {
			ZEPHIR_CALL_METHOD(&_21$$12, statement, "fetchcolumn", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_22$$12, _21$$12);
			RETURN_CTOR(_22$$12);
		}
		if (mode == 4) {
			ZEPHIR_INIT_VAR(result);
			array_init(result);
			while (1) {
				ZEPHIR_CALL_METHOD(&resultItem, statement, "fetchcolumn", &_23, 0);
				zephir_check_call_status();
				_24$$14 = ZEPHIR_IS_FALSE_IDENTICAL(resultItem);
				if (!(_24$$14)) {
					_24$$14 = Z_TYPE_P(resultItem) != IS_STRING;
				}
				if (_24$$14) {
					break;
				}
				zephir_array_append(&result, resultItem, PH_SEPARATE, "nc/db/pdoabstract.zep", 81);
			}
			RETURN_CCTOR(result);
		}
	} while(0);

	ZEPHIR_INIT_NVAR(_14);
	object_init_ex(_14, nc_db_exception_ce);
	ZEPHIR_SINIT_VAR(_25);
	ZVAL_LONG(&_25, mode);
	ZEPHIR_CALL_FUNCTION(&_26, "strval", NULL, 23, &_25);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_27);
	ZEPHIR_CONCAT_SV(_27, "Invalid fetch mode: ", _26);
	ZEPHIR_CALL_METHOD(NULL, _14, "__construct", NULL, 2, _27);
	zephir_check_call_status();
	zephir_throw_exception_debug(_14, "nc/db/pdoabstract.zep", 86 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Db_PdoAbstract, tryToBegin) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "begintransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_PdoAbstract, tryToCommit) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "commit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_PdoAbstract, tryToRollback) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "rollback", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

