
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
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/object.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_Pdo) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, Pdo, nc, db_pdo, nc_db_dbabstract_ce, nc_db_pdo_method_entry, 0);

	zend_declare_property_null(nc_db_pdo_ce, SL("pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Db_Pdo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval driverOptions;
	zval *dsn_param = NULL, *user_param = NULL, *passwd_param = NULL, *driverOptions_param = NULL, ex, _0, _1, _2$$3, _3$$3, _4$$3, _5$$4, _6$$5, _7$$5, _8$$5;
	zval dsn, user, passwd;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&passwd);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&driverOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &dsn_param, &user_param, &passwd_param, &driverOptions_param);

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
	if (!driverOptions_param) {
		ZEPHIR_INIT_VAR(&driverOptions);
		array_init(&driverOptions);
	} else {
		zephir_get_arrval(&driverOptions, driverOptions_param);
	}


	ZEPHIR_INIT_VAR(&ex);
	ZVAL_NULL(&ex);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "pdo");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 28, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "pdo");
		ZVAL_LONG(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "nc/db/pdo.zep", 12 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, php_pdo_get_dbh_ce());
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 0, &dsn, &user, &passwd, &driverOptions);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_update_property_zval(this_ptr, SL("pdo"), &_5$$4);

	try_end_1:

	if (EG(exception)) {
		ZVAL_OBJ(&ex, EG(exception));
		Z_ADDREF_P(&ex);
		if (zephir_instance_of_ev(&ex, php_pdo_get_exception() TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_INIT_VAR(&_6$$5);
			object_init_ex(&_6$$5, nc_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_7$$5, &ex, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_8$$5, 2);
			ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 3, &_7$$5, &_8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$5, "nc/db/pdo.zep", 18 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_Pdo, getPdo) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "pdo");

}

PHP_METHOD(Nc_Db_Pdo, quote) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0;
	zval value;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(&value, value_param);


	zephir_read_property(&_0, this_ptr, SL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "quote", NULL, 0, &value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Pdo, tryToBegin) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "begintransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Pdo, tryToCommit) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "commit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Pdo, tryToRollback) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "rollback", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_Pdo, executeQuery) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool executionOnly, success = 0;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, *executionOnly_param = NULL, __$true, t, s, statement, k, v, err, _0, _7, _13, *_1$$3, _4$$5, _5$$5, _8$$6, _9$$6, _10$$6, _11$$6, _12$$7;
	zval sql;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sql);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&t);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&err);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
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
	zephir_read_property(&_0, this_ptr, SL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&statement, &_0, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	if (zephir_fast_count_int(&params TSRMLS_CC) > 0) {
		zephir_is_iterable(&params, 0, "nc/db/pdo.zep", 61);
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
				ZVAL_LONG(&_5$$5, 2);
				ZEPHIR_CALL_METHOD(NULL, &statement, "bindvalue", &_6, 0, &_4$$5, &v, &_5$$5);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
	}
	ZEPHIR_CALL_METHOD(&_7, &statement, "execute", NULL, 0);
	zephir_check_call_status();
	success = zephir_get_boolval(&_7);
	ZEPHIR_CALL_METHOD(&s, this_ptr, "addsql", NULL, 0, &sql, &params, &t);
	zephir_check_call_status();
	if (unlikely(!success)) {
		ZEPHIR_CALL_METHOD(&err, &statement, "errorinfo", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$6);
		object_init_ex(&_8$$6, nc_db_exception_ce);
		zephir_array_fetch_long(&_9$$6, &err, 2, PH_NOISY | PH_READONLY, "nc/db/pdo.zep", 68 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_10$$6);
		ZEPHIR_CONCAT_VSV(&_10$$6, &_9$$6, " [SQL] ", &s);
		ZVAL_LONG(&_11$$6, 3);
		ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", NULL, 3, &_10$$6, &_11$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$6, "nc/db/pdo.zep", 68 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (executionOnly) {
		ZEPHIR_CALL_METHOD(&_12$$7, &statement, "rowcount", NULL, 0);
		zephir_check_call_status();
		RETURN_MM_LONG(zephir_get_intval(&_12$$7));
	}
	ZVAL_LONG(&_13, 2);
	ZEPHIR_RETURN_CALL_METHOD(&statement, "fetchall", NULL, 0, &_13);
	zephir_check_call_status();
	RETURN_MM();

}

