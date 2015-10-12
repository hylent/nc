
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
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_Pdo) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, Pdo, nc, db_pdo, nc_db_dbabstract_ce, nc_db_pdo_method_entry, 0);

	zend_declare_property_null(nc_db_pdo_ce, SL("pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Pdo, __construct) {

	zval *pdo = NULL, _0, *_1 = NULL, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "pdo", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 14, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Missing extension: pdo", "nc/db/pdo.zep", 12);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "PDO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 26, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "func_get_args", NULL, 13);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&pdo, _2, "newinstanceargs", NULL, 37, _4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pdo"), pdo TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 16);
	ZEPHIR_CALL_METHOD(&_5, pdo, "getattribute", NULL, 0, _6);
	zephir_check_call_status();
	zephir_ucfirst(_3, _5);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SV(_7, "Nc\\Db\\Query\\", _3);
	zephir_update_property_this(this_ptr, SL("queryClass"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Pdo, quote) {

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

PHP_METHOD(Nc_Db_Pdo, query) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL, *_17 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _14;
	zval *params = NULL;
	zval *sql = NULL;
	zval *flag_param = NULL, *sql_param = NULL, *params_param = NULL, *stmt = NULL, *k = NULL, *v = NULL, *success = NULL, *err = NULL, *data = NULL, *row = NULL, *item = NULL, *_0, **_3$$3, *_4$$5 = NULL, *_5$$5 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_9$$6 = NULL, *_11$$7, *_12$$7, *_13$$7, *_15$$8, *_16$$9 = NULL;
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
	ZEPHIR_CALL_METHOD(&stmt, _0, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		zephir_is_iterable(params, &_2$$3, &_1$$3, 0, 0, "nc/db/pdo.zep", 40);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(k, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(v, _3$$3);
			if (Z_TYPE_P(v) == IS_STRING) {
				ZEPHIR_INIT_LNVAR(_4$$5);
				ZEPHIR_CONCAT_SV(_4$$5, ":", k);
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SV(_5$$5, "", v);
				ZEPHIR_INIT_NVAR(_6$$5);
				ZVAL_LONG(_6$$5, 2);
				ZEPHIR_INIT_NVAR(_7$$5);
				ZVAL_LONG(_7$$5, zephir_fast_strlen_ev(v));
				ZEPHIR_CALL_METHOD(NULL, stmt, "bindparam", &_8, 0, _4$$5, _5$$5, _6$$5, _7$$5);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_LNVAR(_9$$6);
				ZEPHIR_CONCAT_SV(_9$$6, ":", k);
				ZEPHIR_CALL_METHOD(NULL, stmt, "bindvalue", &_10, 0, _9$$6, v);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&success, stmt, "execute", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(success))) {
		ZEPHIR_CALL_METHOD(&err, stmt, "errorinfo", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_11$$7);
		object_init_ex(_11$$7, nc_db_queryexception_ce);
		zephir_array_fetch_long(&_12$$7, err, 2, PH_NOISY | PH_READONLY, "nc/db/pdo.zep", 46 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_13$$7);
		ZEPHIR_CONCAT_VSV(_13$$7, _12$$7, "[SQL:] ", sql);
		ZEPHIR_CALL_METHOD(NULL, _11$$7, "__construct", NULL, 2, _13$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_11$$7, "nc/db/pdo.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		_14 = ((flag & 0xf0));
		if (_14 == 0x10) {
			ZEPHIR_INIT_VAR(_15$$8);
			ZVAL_LONG(_15$$8, 2);
			ZEPHIR_RETURN_CALL_METHOD(stmt, "fetchall", NULL, 0, _15$$8);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (_14 == 0x20) {
			ZEPHIR_INIT_VAR(_16$$9);
			ZVAL_LONG(_16$$9, 2);
			ZEPHIR_CALL_METHOD(&row, stmt, "fetch", NULL, 0, _16$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_16$$9);
			if (zephir_is_true(row)) {
				ZEPHIR_CPY_WRT(_16$$9, row);
			} else {
				ZVAL_NULL(_16$$9);
			}
			RETURN_CCTOR(_16$$9);
		}
		if (_14 == 0x30) {
			ZEPHIR_CALL_METHOD(&item, stmt, "fetchcolumn", NULL, 0);
			zephir_check_call_status();
			RETURN_CCTOR(item);
		}
		if (_14 == 0x40) {
			ZEPHIR_INIT_VAR(data);
			array_init(data);
			while (1) {
				ZEPHIR_CALL_METHOD(&item, stmt, "fetchcolumn", &_17, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(item) != IS_STRING) {
					break;
				}
				zephir_array_append(&data, item, PH_SEPARATE, "nc/db/pdo.zep", 68);
			}
			RETURN_CCTOR(data);
		}
	} while(0);

	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Db_Pdo, tryToBegin) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "begintransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Pdo, tryToCommit) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "commit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Pdo, tryToRollback) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "rollback", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

