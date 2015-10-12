
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_Oci) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, Oci, nc, db_oci, nc_db_dbabstract_ce, nc_db_oci_method_entry, 0);

	zend_declare_property_null(nc_db_oci_ce, SL("oci"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Oci, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dsn_param = NULL, *user_param = NULL, *passwd_param = NULL, *oci = NULL, _0 = zval_used_for_init, *_1 = NULL, *_4, *_2$$4;
	zval *dsn = NULL, *user = NULL, *passwd = NULL, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dsn_param, &user_param, &passwd_param);

	zephir_get_strval(dsn, dsn_param);
	zephir_get_strval(user, user_param);
	zephir_get_strval(passwd, passwd_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "oci8", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 14, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Missing extension: oci8", "nc/db/oci.zep", 12);
		return;
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "utf8", 0);
	ZEPHIR_CALL_FUNCTION(&oci, "oci_connect", NULL, 28, user, passwd, dsn, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(oci))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot connect: ", dsn);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/db/oci.zep", 17 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("oci"), oci TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_STRING(_4, "Nc\\Db\\Query\\Oracle", 1);
	zephir_update_property_this(this_ptr, SL("queryClass"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Oci, quote) {

	zval *value_param = NULL, *_0, _1, _2;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "'", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "''", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, value TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "'", _0, "'");
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci, query) {

	zend_bool _8$$7, _18$$14, _19$$14, _21$$17, _22$$17;
	HashTable *_3$$5;
	HashPosition _2$$5;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql = NULL;
	zval *flag_param = NULL, *sql_param = NULL, *params_param = NULL, *stmt = NULL, *k = NULL, *v = NULL, *success = NULL, *err = NULL, *errMsg = NULL, *mode = NULL, *data = NULL, *row = NULL, *item = NULL, *flagVar = NULL, *_0, *_1, **_4$$5, *_5$$6 = NULL, *_7$$7, *_9$$7, *_10$$7, *_11$$10, *_13$$11 = NULL, _15$$13, *_16$$13 = NULL, _17$$14, *_20$$16;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(flagVar);
	if (zephir_is_true(_0)) {
		ZVAL_LONG(flagVar, 0);
	} else {
		ZVAL_LONG(flagVar, 32);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&stmt, "oci_parse", NULL, 29, _1, sql);
	zephir_check_call_status();
	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		zephir_is_iterable(params, &_3$$5, &_2$$5, 0, 0, "nc/db/oci.zep", 45);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$5, (void**) &_4$$5, &_2$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$5, &_2$$5)
		) {
			ZEPHIR_GET_HMKEY(k, _3$$5, _2$$5);
			ZEPHIR_GET_HVALUE(v, _4$$5);
			ZEPHIR_INIT_LNVAR(_5$$6);
			ZEPHIR_CONCAT_SV(_5$$6, ":", k);
			ZEPHIR_MAKE_REF(v);
			ZEPHIR_CALL_FUNCTION(NULL, "oci_bind_by_name", &_6, 30, stmt, _5$$6, v);
			ZEPHIR_UNREF(v);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(&success, "oci_execute", NULL, 31, stmt, flagVar);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(success))) {
		_7$$7 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&err, "oci_error", NULL, 32, _7$$7);
		zephir_check_call_status();
		_8$$7 = Z_TYPE_P(err) != IS_ARRAY;
		if (!(_8$$7)) {
			ZEPHIR_OBS_VAR(errMsg);
			_8$$7 = !(zephir_array_isset_string_fetch(&errMsg, err, SS("message"), 0 TSRMLS_CC));
		}
		if (_8$$7) {
			ZEPHIR_INIT_NVAR(errMsg);
			ZVAL_STRING(errMsg, "", 1);
		}
		ZEPHIR_INIT_VAR(_9$$7);
		object_init_ex(_9$$7, nc_db_queryexception_ce);
		ZEPHIR_INIT_VAR(_10$$7);
		ZEPHIR_CONCAT_VSV(_10$$7, errMsg, "[SQL:] ", sql);
		ZEPHIR_CALL_METHOD(NULL, _9$$7, "__construct", NULL, 2, _10$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9$$7, "nc/db/oci.zep", 54 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(flagVar);
	ZVAL_LONG(flagVar, (flag & 0xf0));
	if (zephir_is_true(flagVar)) {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_LONG(mode, (4 + 8));
		do {
			if (ZEPHIR_IS_LONG(flagVar, 0x10)) {
				ZEPHIR_INIT_VAR(_11$$10);
				ZVAL_LONG(_11$$10, 1);
				ZEPHIR_ADD_ASSIGN(mode, _11$$10);
				ZEPHIR_INIT_VAR(data);
				array_init(data);
				while (1) {
					ZEPHIR_CALL_FUNCTION(&row, "oci_fetch_array", &_12, 33, stmt, mode);
					zephir_check_call_status();
					if (!(zephir_is_true(row))) {
						break;
					}
					ZEPHIR_CALL_FUNCTION(&_13$$11, "array_change_key_case", &_14, 34, row);
					zephir_check_call_status();
					zephir_array_append(&data, _13$$11, PH_SEPARATE, "nc/db/oci.zep", 71);
				}
				RETURN_CCTOR(data);
			}
			if (ZEPHIR_IS_LONG(flagVar, 0x20)) {
				ZEPHIR_SINIT_VAR(_15$$13);
				ZVAL_LONG(&_15$$13, (zephir_get_numberval(mode) + 1));
				ZEPHIR_CALL_FUNCTION(&row, "oci_fetch_array", &_12, 33, stmt, &_15$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_16$$13);
				if (zephir_is_true(row)) {
					ZEPHIR_CALL_FUNCTION(&_16$$13, "array_change_key_case", &_14, 34, row);
					zephir_check_call_status();
				} else {
					ZVAL_NULL(_16$$13);
				}
				RETURN_CCTOR(_16$$13);
			}
			if (ZEPHIR_IS_LONG(flagVar, 0x30)) {
				ZEPHIR_SINIT_VAR(_17$$14);
				ZVAL_LONG(&_17$$14, (zephir_get_numberval(mode) + 2));
				ZEPHIR_CALL_FUNCTION(&row, "oci_fetch_array", &_12, 33, stmt, &_17$$14);
				zephir_check_call_status();
				_18$$14 = zephir_is_true(row);
				if (_18$$14) {
					_18$$14 = Z_TYPE_P(row) == IS_ARRAY;
				}
				_19$$14 = _18$$14;
				if (_19$$14) {
					ZEPHIR_OBS_VAR(item);
					_19$$14 = zephir_array_isset_long_fetch(&item, row, 0, 0 TSRMLS_CC);
				}
				if (_19$$14) {
					RETURN_CCTOR(item);
				}
				RETURN_MM_STRING("", 1);
			}
			if (ZEPHIR_IS_LONG(flagVar, 0x40)) {
				ZEPHIR_INIT_VAR(_20$$16);
				ZVAL_LONG(_20$$16, 2);
				ZEPHIR_ADD_ASSIGN(mode, _20$$16);
				ZEPHIR_INIT_NVAR(data);
				array_init(data);
				while (1) {
					ZEPHIR_CALL_FUNCTION(&row, "oci_fetch_array", &_12, 33, stmt, mode);
					zephir_check_call_status();
					_21$$17 = !zephir_is_true(row);
					if (!(_21$$17)) {
						_21$$17 = Z_TYPE_P(row) != IS_ARRAY;
					}
					_22$$17 = _21$$17;
					if (!(_22$$17)) {
						ZEPHIR_OBS_NVAR(item);
						_22$$17 = !(zephir_array_isset_long_fetch(&item, row, 0, 0 TSRMLS_CC));
					}
					if (_22$$17) {
						break;
					}
					zephir_array_append(&data, item, PH_SEPARATE, "nc/db/oci.zep", 94);
				}
				RETURN_CCTOR(data);
			}
		} while(0);

	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Db_Oci, tryToBegin) {

	

	RETURN_BOOL(1);

}

PHP_METHOD(Nc_Db_Oci, tryToCommit) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_commit", NULL, 35, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci, tryToRollback) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_rollback", NULL, 36, _0);
	zephir_check_call_status();
	RETURN_MM();

}

