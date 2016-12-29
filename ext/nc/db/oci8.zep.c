
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
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_Oci8) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, Oci8, nc, db_oci8, nc_db_dbabstract_ce, nc_db_oci8_method_entry, 0);

	zend_declare_property_null(nc_db_oci8_ce, SL("oci"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Oci8, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dsn_param = NULL, *user_param = NULL, *passwd_param = NULL, oci, _0, _1, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4;
	zval dsn, user, passwd;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&passwd);
	ZVAL_UNDEF(&oci);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &dsn_param, &user_param, &passwd_param);

	zephir_get_strval(&dsn, dsn_param);
	if (!user_param) {
		ZEPHIR_INIT_VAR(&user);
		ZVAL_STRING(&user, "");
	} else {
		zephir_get_strval(&user, user_param);
	}
	if (!passwd_param) {
		ZEPHIR_INIT_VAR(&passwd);
		ZVAL_STRING(&passwd, "");
	} else {
		zephir_get_strval(&passwd, passwd_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "oci8");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 24, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "oci8");
		ZVAL_LONG(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 7, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "nc/db/oci8.zep", 12 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "utf8");
	ZEPHIR_CALL_FUNCTION(&oci, "oci_connect", NULL, 41, &user, &passwd, &dsn, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&oci))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, nc_db_exception_ce);
		ZVAL_LONG(&_6$$4, 2);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 7, &dsn, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "nc/db/oci8.zep", 17 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("oci"), &oci);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Oci8, getOciResource) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "oci");

}

PHP_METHOD(Nc_Db_Oci8, quote) {

	zval *value_param = NULL, _0, _1, _2;
	zval value;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "'");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "''");
	zephir_fast_str_replace(&_0, &_1, &_2, &value TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "'", &_0, "'");
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci8, tryToBegin) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(1);

}

PHP_METHOD(Nc_Db_Oci8, tryToCommit) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("oci"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_commit", NULL, 42, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci8, tryToRollback) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("oci"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_rollback", NULL, 43, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Oci8, executeQuery) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_14 = NULL, *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool executionOnly, success = 0;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, *executionOnly_param = NULL, __$true, t, s, statement, k, v, mode, err, result, resultRow, _0, _6, _7, *_1$$3, _4$$5, _8$$8, _9$$8, _10$$8, _11$$8, _12$$8, _13$$9, _15$$10;
	zval sql;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sql);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&t);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&err);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&resultRow);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sql_param, &params_param, &executionOnly_param);

	zephir_get_strval(&sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	if (!executionOnly_param) {
		executionOnly = 0;
	} else {
		executionOnly = zephir_get_boolval(executionOnly_param);
	}


	ZEPHIR_INIT_VAR(&t);
	zephir_microtime(&t, &__$true TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("oci"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&statement, "oci_parse", NULL, 44, &_0, &sql);
	zephir_check_call_status();
	if (zephir_fast_count_int(&params TSRMLS_CC) > 0) {
		zephir_is_iterable(&params, 0, "nc/db/oci8.zep", 62);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&k, _3$$3);
			} else {
				ZVAL_LONG(&k, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _1$$3);
			if (!(Z_TYPE_P(&k) == IS_LONG)) {
				ZEPHIR_INIT_LNVAR(_4$$5);
				ZEPHIR_CONCAT_SV(&_4$$5, ":", &k);
				ZEPHIR_MAKE_REF(&v);
				ZEPHIR_CALL_FUNCTION(NULL, "oci_bind_by_name", &_5, 45, &statement, &_4$$5, &v);
				ZEPHIR_UNREF(&v);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
	}
	zephir_read_property(&_6, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&mode);
	if (zephir_is_true(&_6)) {
		ZVAL_LONG(&mode, 0);
	} else {
		ZVAL_LONG(&mode, 32);
	}
	ZEPHIR_CALL_FUNCTION(&_7, "oci_execute", NULL, 46, &statement, &mode);
	zephir_check_call_status();
	success = zephir_get_boolval(&_7);
	ZEPHIR_CALL_METHOD(&s, this_ptr, "addsql", NULL, 0, &sql, &params, &t);
	zephir_check_call_status();
	if (unlikely(!success)) {
		zephir_read_property(&_8$$8, this_ptr, SL("oci"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&err, "oci_error", NULL, 47, &_8$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$8);
		object_init_ex(&_9$$8, nc_db_exception_ce);
		zephir_array_fetch_string(&_10$$8, &err, SL("message"), PH_NOISY | PH_READONLY, "nc/db/oci8.zep", 75 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_11$$8);
		ZEPHIR_CONCAT_VSV(&_11$$8, &_10$$8, " [SQL] ", &s);
		ZVAL_LONG(&_12$$8, 3);
		ZEPHIR_CALL_METHOD(NULL, &_9$$8, "__construct", NULL, 7, &_11$$8, &_12$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$8, "nc/db/oci8.zep", 75 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (executionOnly) {
		ZEPHIR_CALL_FUNCTION(&_13$$9, "oci_num_rows", NULL, 48, &statement);
		zephir_check_call_status();
		RETURN_MM_LONG(zephir_get_intval(&_13$$9));
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_NVAR(&mode);
	ZVAL_LONG(&mode, ((4 + 8) + 1));
	while (1) {
		ZEPHIR_CALL_FUNCTION(&resultRow, "oci_fetch_array", &_14, 49, &statement, &mode);
		zephir_check_call_status();
		if (!(zephir_is_true(&resultRow))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&_15$$10, "array_change_key_case", &_16, 50, &resultRow);
		zephir_check_call_status();
		zephir_array_append(&result, &_15$$10, PH_SEPARATE, "nc/db/oci8.zep", 90);
	}
	RETURN_CCTOR(result);

}

