
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
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *dsn_param = NULL, *user_param = NULL, *passwd_param = NULL, *oci = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3, *_5;
	zval *dsn = NULL, *user = NULL, *passwd = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dsn_param, &user_param, &passwd_param);

	zephir_get_strval(dsn, dsn_param);
	zephir_get_strval(user, user_param);
	zephir_get_strval(passwd, passwd_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "oci8", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Missing extension: oci8", "nc/db/oci.zep", 12);
		return;
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "utf8", 0);
	ZEPHIR_CALL_FUNCTION(&oci, "oci_connect", NULL, user, passwd, dsn, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(oci))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Cannot connect: ", dsn);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "nc/db/oci.zep", 17 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("oci"), oci TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_STRING(_5, "Nc\\Db\\Query\\Oracle", 1);
	zephir_update_property_this(this_ptr, SL("queryClass"), _5 TSRMLS_CC);
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
	zephir_fast_str_replace(_0, &_1, &_2, value TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "'", _0, "'");
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci, query) {

	zephir_nts_static zephir_fcall_cache_entry *_12 = NULL;
	zend_bool _8, _15, _16;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql = NULL;
	zval *flag_param = NULL, *sql_param = NULL, *params_param = NULL, *stmt = NULL, *k = NULL, *v = NULL, *success = NULL, *err = NULL, *errMsg = NULL, *mode, *data = NULL, *row = NULL, *item = NULL, *flagVar = NULL, *_0, *_1, **_4, *_5 = NULL, *_7, *_9 = NULL, *_11 = NULL, _13 = zval_used_for_init, *_14 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&stmt, "oci_parse", NULL, _1, sql);
	zephir_check_call_status();
	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		zephir_is_iterable(params, &_3, &_2, 0, 0, "nc/db/oci.zep", 45);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(k, _3, _2);
			ZEPHIR_GET_HVALUE(v, _4);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SV(_5, ":", k);
			Z_SET_ISREF_P(v);
			ZEPHIR_CALL_FUNCTION(NULL, "oci_bind_by_name", &_6, stmt, _5, v);
			Z_UNSET_ISREF_P(v);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(&success, "oci_execute", NULL, stmt, flagVar);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(success))) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&err, "oci_error", NULL, _7);
		zephir_check_call_status();
		_8 = Z_TYPE_P(err) != IS_ARRAY;
		if (!(_8)) {
			ZEPHIR_OBS_VAR(errMsg);
			_8 = !(zephir_array_isset_string_fetch(&errMsg, err, SS("message"), 0 TSRMLS_CC));
		}
		if (_8) {
			ZEPHIR_INIT_NVAR(errMsg);
			ZVAL_STRING(errMsg, "", 1);
		}
		ZEPHIR_INIT_VAR(_9);
		object_init_ex(_9, nc_db_queryexception_ce);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_VSV(_5, errMsg, "[SQL:] ", sql);
		ZEPHIR_CALL_METHOD(NULL, _9, "__construct", NULL, _5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9, "nc/db/oci.zep", 54 TSRMLS_CC);
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
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 1);
				ZEPHIR_ADD_ASSIGN(mode, _9);
				ZEPHIR_INIT_VAR(data);
				array_init(data);
				while (1) {
					ZEPHIR_CALL_FUNCTION(&row, "oci_fetch_array", &_10, stmt, mode);
					zephir_check_call_status();
					if (!(zephir_is_true(row))) {
						break;
					}
					ZEPHIR_CALL_FUNCTION(&_11, "array_change_key_case", &_12, row);
					zephir_check_call_status();
					zephir_array_append(&data, _11, PH_SEPARATE, "nc/db/oci.zep", 71);
				}
				RETURN_CCTOR(data);
			}
			if (ZEPHIR_IS_LONG(flagVar, 0x20)) {
				ZEPHIR_SINIT_VAR(_13);
				ZVAL_LONG(&_13, (zephir_get_numberval(mode) + 1));
				ZEPHIR_CALL_FUNCTION(&row, "oci_fetch_array", &_10, stmt, &_13);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_14);
				if (zephir_is_true(row)) {
					ZEPHIR_CALL_FUNCTION(&_14, "array_change_key_case", &_12, row);
					zephir_check_call_status();
				} else {
					ZVAL_NULL(_14);
				}
				RETURN_CCTOR(_14);
			}
			if (ZEPHIR_IS_LONG(flagVar, 0x30)) {
				ZEPHIR_SINIT_NVAR(_13);
				ZVAL_LONG(&_13, (zephir_get_numberval(mode) + 2));
				ZEPHIR_CALL_FUNCTION(&row, "oci_fetch_array", &_10, stmt, &_13);
				zephir_check_call_status();
				_8 = zephir_is_true(row);
				if (_8) {
					_8 = Z_TYPE_P(row) == IS_ARRAY;
				}
				_15 = _8;
				if (_15) {
					ZEPHIR_OBS_VAR(item);
					_15 = zephir_array_isset_long_fetch(&item, row, 0, 0 TSRMLS_CC);
				}
				if (_15) {
					RETURN_CCTOR(item);
				}
				RETURN_MM_STRING("", 1);
			}
			if (ZEPHIR_IS_LONG(flagVar, 0x40)) {
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_LONG(_14, 2);
				ZEPHIR_ADD_ASSIGN(mode, _14);
				ZEPHIR_INIT_NVAR(data);
				array_init(data);
				while (1) {
					ZEPHIR_CALL_FUNCTION(&row, "oci_fetch_array", &_10, stmt, mode);
					zephir_check_call_status();
					_15 = !zephir_is_true(row);
					if (!(_15)) {
						_15 = Z_TYPE_P(row) != IS_ARRAY;
					}
					_16 = _15;
					if (!(_16)) {
						ZEPHIR_OBS_NVAR(item);
						_16 = !(zephir_array_isset_long_fetch(&item, row, 0, 0 TSRMLS_CC));
					}
					if (_16) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_commit", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci, tryToRollback) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_rollback", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

