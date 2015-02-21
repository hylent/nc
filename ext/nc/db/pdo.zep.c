
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
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_Pdo) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, Pdo, nc, db_pdo, nc_db_dbadapter_ce, nc_db_pdo_method_entry, 0);

	zend_declare_property_null(nc_db_pdo_ce, SL("pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Pdo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL, *_9 = NULL;
	zval *pdo = NULL, _0, *_1 = NULL, *_3, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_10;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "pdo", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Missing extension: pdo", "nc/db/pdo.zep", 12);
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "PDO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "func_get_args", &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&pdo, _3, "newinstanceargs", NULL, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pdo"), pdo TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 16);
	ZEPHIR_CALL_METHOD(&_7, pdo, "getattribute", NULL, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_8, "ucfirst", &_9, _7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SV(_10, "Nc\\Db\\Query\\", _8);
	zephir_update_property_this(this_ptr, SL("queryClass"), _10 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Pdo, begin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!(!zephir_is_true(_0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Already in transaction", "nc/db/pdo.zep", 24);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "begintransaction", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Db_Pdo, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "commit", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Db_Pdo, rollback) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "rollback", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Db_Pdo, quote) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *_0;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "quote", NULL, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Pdo, query) {

	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL, *_12 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS, _11;
	zval *params = NULL;
	zval *sql = NULL;
	zval *flag_param = NULL, *sql_param = NULL, *params_param = NULL, *stmt = NULL, *k = NULL, *v = NULL, *success = NULL, *err = NULL, *data, *row = NULL, *item = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_10;
	long flag;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &flag_param, &sql_param, &params_param);

	flag = zephir_get_intval(flag_param);
	zephir_get_strval(sql, sql_param);
	if (!params_param) {
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&stmt, _0, "prepare", NULL, sql);
	zephir_check_call_status();
	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		zephir_is_iterable(params, &_2, &_1, 0, 0, "nc/db/pdo.zep", 74);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(k, _2, _1);
			ZEPHIR_GET_HVALUE(v, _3);
			if (Z_TYPE_P(v) == IS_STRING) {
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, ":", k);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SV(_5, "", v);
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 2);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, zephir_fast_strlen_ev(v));
				ZEPHIR_CALL_METHOD(NULL, stmt, "bindparam", &_8, _4, _5, _6, _7);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, ":", k);
				ZEPHIR_CALL_METHOD(NULL, stmt, "bindvalue", &_9, _4, v);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&success, stmt, "execute", NULL);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(success))) {
		ZEPHIR_CALL_METHOD(&err, stmt, "errorinfo", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6);
		object_init_ex(_6, nc_db_queryexception_ce);
		zephir_array_fetch_long(&_10, err, 2, PH_NOISY | PH_READONLY, "nc/db/pdo.zep", 80 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VSV(_4, _10, "[SQL:] ", sql);
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6, "nc/db/pdo.zep", 80 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		_11 = ((flag & 0xf0));
		if (_11 == 0x10) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 2);
			ZEPHIR_RETURN_CALL_METHOD(stmt, "fetchall", NULL, _6);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (_11 == 0x20) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 2);
			ZEPHIR_CALL_METHOD(&row, stmt, "fetch", NULL, _6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_6);
			if (zephir_is_true(row)) {
				ZEPHIR_CPY_WRT(_6, row);
			} else {
				ZVAL_NULL(_6);
			}
			RETURN_CCTOR(_6);
		}
		if (_11 == 0x30) {
			ZEPHIR_CALL_METHOD(&item, stmt, "fetchcolumn", NULL);
			zephir_check_call_status();
			RETURN_CCTOR(item);
		}
		if (_11 == 0x40) {
			ZEPHIR_INIT_VAR(data);
			array_init(data);
			while (1) {
				ZEPHIR_CALL_METHOD(&item, stmt, "fetchcolumn", &_12);
				zephir_check_call_status();
				if (Z_TYPE_P(item) != IS_STRING) {
					break;
				}
				zephir_array_append(&data, item, PH_SEPARATE, "nc/db/pdo.zep", 102);
			}
			RETURN_CCTOR(data);
		}
	} while(0);

	RETURN_MM_BOOL(1);

}

