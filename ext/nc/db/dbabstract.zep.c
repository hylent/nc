
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(Nc_Db_DbAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, DbAbstract, nc, db_dbabstract, nc_db_dbabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_bool(nc_db_dbabstract_ce, SL("inTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_dbabstract_ce, SL("sqls"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_db_dbabstract_ce TSRMLS_CC, 1, nc_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Db_DbAbstract, inTransaction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "inTransaction");

}

PHP_METHOD(Nc_Db_DbAbstract, begin) {

	zend_bool _1;
	zval __$true, __$false, _0, _2, _3$$3, _4$$3, _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	_1 = !(!zephir_is_true(&_0));
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "trytobegin", NULL, 0);
		zephir_check_call_status();
		_1 = !zephir_is_true(&_2);
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "begin");
		ZVAL_LONG(&_5$$3, 4);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "nc/db/dbabstract.zep", 16 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("inTransaction"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("inTransaction"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, commit) {

	zend_bool _1;
	zval __$true, __$false, _0, _2, _3$$3, _4$$3, _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	_1 = !zephir_is_true(&_0);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "trytocommit", NULL, 0);
		zephir_check_call_status();
		_1 = !zephir_is_true(&_2);
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "commit");
		ZVAL_LONG(&_5$$3, 4);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "nc/db/dbabstract.zep", 25 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("inTransaction"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("inTransaction"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, rollback) {

	zend_bool _1;
	zval __$true, __$false, _0, _2, _3$$3, _4$$3, _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	_1 = !zephir_is_true(&_0);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "trytorollback", NULL, 0);
		zephir_check_call_status();
		_1 = !zephir_is_true(&_2);
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "rollback");
		ZVAL_LONG(&_5$$3, 4);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "nc/db/dbabstract.zep", 34 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("inTransaction"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("inTransaction"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, savepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, _0, _1$$3, _2$$3, _3$$3;
	zval savepoint, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savepoint);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(&savepoint, savepoint_param);


	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "savepoint");
		ZVAL_LONG(&_3$$3, 4);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/db/dbabstract.zep", 43 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "SAVEPOINT ", &savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, releaseSavepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, _0, _1$$3, _2$$3, _3$$3;
	zval savepoint, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savepoint);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(&savepoint, savepoint_param);


	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "releaseSavepoint");
		ZVAL_LONG(&_3$$3, 4);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/db/dbabstract.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "RELEASE SAVEPOINT ", &savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, rollbackToSavepoint) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, _0, _1$$3, _2$$3, _3$$3;
	zval savepoint, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savepoint);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(&savepoint, savepoint_param);


	zephir_read_property(&_0, this_ptr, SL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "rollbackToSavepoint");
		ZVAL_LONG(&_3$$3, 4);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/db/dbabstract.zep", 61 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "ROLLBACK TO SAVEPOINT ", &savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, expression) {

	zval _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0, _2, _4, _7;
	zval input, _1, _3, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);

	zephir_get_arrval(&input, input_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "%");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "?");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "%%");
	zephir_array_fast_append(&_3, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "%s");
	zephir_array_fast_append(&_3, &_2);
	ZEPHIR_MAKE_REF(&input);
	ZEPHIR_CALL_FUNCTION(&_4, "array_shift", NULL, 4, &input);
	ZEPHIR_UNREF(&input);
	zephir_check_call_status();
	zephir_get_strval(&_5, &_4);
	zephir_fast_str_replace(&_0, &_1, &_3, &_5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_6, this_ptr);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "quote");
	zephir_array_fast_append(&_6, &_2);
	ZEPHIR_CALL_FUNCTION(&_7, "array_map", NULL, 6, &_6, &input);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("vsprintf", NULL, 14, &_0, &_7);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, execute) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, _0;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(&sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZVAL_BOOL(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "executequery", NULL, 0, &sql, &params, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, query) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, _0;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(&sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZVAL_BOOL(&_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "executequery", NULL, 0, &sql, &params, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, queryRow) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, data, row;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(&sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_CALL_METHOD(&data, this_ptr, "query", NULL, 0, &sql, &params);
	zephir_check_call_status();
	_0 = zephir_array_isset_long_fetch(&row, &data, 0, 1 TSRMLS_CC);
	if (_0) {
		_0 = Z_TYPE_P(&row) == IS_ARRAY;
	}
	if (_0) {
		RETURN_CTOR(&row);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, queryCell) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, data, row, _1$$3;
	zval sql, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(&sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_CALL_METHOD(&data, this_ptr, "query", NULL, 0, &sql, &params);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&row);
	_0 = zephir_array_isset_long_fetch(&row, &data, 0, 0 TSRMLS_CC);
	if (_0) {
		_0 = Z_TYPE_P(&row) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_MAKE_REF(&row);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "array_shift", NULL, 4, &row);
		ZEPHIR_UNREF(&row);
		zephir_check_call_status();
		zephir_get_strval(&_2$$3, &_1$$3);
		RETURN_CTOR(&_2$$3);
	}
	RETURN_MM_STRING("");

}

PHP_METHOD(Nc_Db_DbAbstract, queryVector) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, data, row, result, *_0, _1$$4;
	zval sql, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(&sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "query", NULL, 0, &sql, &params);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "nc/db/dbabstract.zep", 121);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _0)
	{
		ZEPHIR_INIT_NVAR(&row);
		ZVAL_COPY(&row, _0);
		if (Z_TYPE_P(&row) == IS_ARRAY) {
			ZEPHIR_MAKE_REF(&row);
			ZEPHIR_CALL_FUNCTION(&_1$$4, "array_shift", &_2, 4, &row);
			ZEPHIR_UNREF(&row);
			zephir_check_call_status();
			zephir_get_strval(&_3$$4, &_1$$4);
			zephir_array_append(&result, &_3$$4, PH_SEPARATE, "nc/db/dbabstract.zep", 117);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&row);
	RETURN_CCTOR(&result);

}

PHP_METHOD(Nc_Db_DbAbstract, queryMap) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, data, row, k, v, result, *_0, _1$$4, _4$$4;
	zval sql, _3$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(&sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_CALL_METHOD(&data, this_ptr, "query", NULL, 0, &sql, &params);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "nc/db/dbabstract.zep", 138);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _0)
	{
		ZEPHIR_INIT_NVAR(&row);
		ZVAL_COPY(&row, _0);
		if (Z_TYPE_P(&row) == IS_ARRAY) {
			ZEPHIR_MAKE_REF(&row);
			ZEPHIR_CALL_FUNCTION(&_1$$4, "array_shift", &_2, 4, &row);
			ZEPHIR_UNREF(&row);
			zephir_check_call_status();
			zephir_get_strval(&_3$$4, &_1$$4);
			ZEPHIR_CPY_WRT(&k, &_3$$4);
			ZEPHIR_MAKE_REF(&row);
			ZEPHIR_CALL_FUNCTION(&_4$$4, "array_shift", &_2, 4, &row);
			ZEPHIR_UNREF(&row);
			zephir_check_call_status();
			zephir_get_strval(&_5$$4, &_4$$4);
			ZEPHIR_CPY_WRT(&v, &_5$$4);
			zephir_array_update_zval(&result, &k, &v, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&row);
	RETURN_CCTOR(&result);

}

PHP_METHOD(Nc_Db_DbAbstract, getSqls) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("sqls"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		RETURN_MEMBER(getThis(), "sqls");
	}
	array_init(return_value);
	return;

}

PHP_METHOD(Nc_Db_DbAbstract, tryToBegin) {

}

PHP_METHOD(Nc_Db_DbAbstract, tryToCommit) {

}

PHP_METHOD(Nc_Db_DbAbstract, tryToRollback) {

}

PHP_METHOD(Nc_Db_DbAbstract, executeQuery) {

}

PHP_METHOD(Nc_Db_DbAbstract, addSql) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	double startTime;
	zval params;
	zval *sql_param = NULL, *params_param = NULL, *startTime_param = NULL, __$true, s, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zval sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &sql_param, &params_param, &startTime_param);

	zephir_get_strval(&sql, sql_param);
	zephir_get_arrval(&params, params_param);
	startTime = zephir_get_doubleval(startTime_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "%s # %0.3fms");
	ZVAL_DOUBLE(&_2, (1000.0 * (double) (zephir_get_doubleval(&_0) - startTime)));
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", NULL, 2, &_1, &sql, &_2);
	zephir_check_call_status();
	if (zephir_fast_count_int(&params TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_LONG(&_4$$3, 256);
		zephir_json_encode(&_3$$3, &params, zephir_get_intval(&_4$$3) );
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, " ", &_3$$3);
		zephir_concat_self(&s, &_5$$3 TSRMLS_CC);
	}
	zephir_update_property_array_append(this_ptr, SL("sqls"), &s TSRMLS_CC);
	RETURN_CCTOR(&s);

}

