
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Db_DbAdapter) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, DbAdapter, nc, db_dbadapter, nc_db_dbadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_db_dbadapter_ce, SL("queryClass"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(nc_db_dbadapter_ce, SL("inTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_db_dbadapter_ce, SL("savepointSerial"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(nc_db_dbadapter_ce, SL("savepoints"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(nc_db_dbadapter_ce TSRMLS_CC, 1, nc_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Db_DbAdapter, inTransaction) {


	RETURN_MEMBER(this_ptr, "inTransaction");

}

PHP_METHOD(Nc_Db_DbAdapter, savepoint) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint = NULL, *_5 = NULL, *_7;
	zval *autoTransaction_param = NULL, *_0, *_1 = NULL, *_2, _3, *_6 = NULL, *_8;
	zend_bool autoTransaction;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &autoTransaction_param);

	if (!autoTransaction_param) {
		autoTransaction = 0;
	} else {
		autoTransaction = zephir_get_boolval(autoTransaction_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		if (unlikely(!autoTransaction)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Cannot acquire a savepoint when not in a transaction", "nc/db/dbadapter.zep", 24);
			return;
		}
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "begin", NULL);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Cannot begin an auto transaction when acquiring a savepoint", "nc/db/dbadapter.zep", 27);
			return;
		}
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("savepointSerial") TSRMLS_CC));
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("savepointSerial"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "s%06d", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", &_4, &_3, _2);
	zephir_check_call_status();
	zephir_get_strval(_5, _1);
	ZEPHIR_CPY_WRT(savepoint, _5);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SV(_7, "savepoint ", savepoint);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, 2);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "query", NULL, _8, _7);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
		RETURN_CTOR(savepoint);
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Nc_Db_DbAdapter, releaseSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_2 = NULL, *_4 = NULL, *_5;
	zval *savepoint = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Cannot release a savepoint when not in a transaction", "nc/db/dbadapter.zep", 45);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_1, savepoint)))) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SV(_3, "Invalid savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "nc/db/dbadapter.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_SV(_3, "release savepoint ", savepoint);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 2);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "query", NULL, _2, _3);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
		zephir_array_unset(&_5, savepoint, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Db_DbAdapter, releaseLastSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_0, *_1, *_2 = NULL, *_5 = NULL, *_7;
	zval *savepoint = NULL, *_4 = NULL, *_6;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Empty savepoint stack", "nc/db/dbadapter.zep", 65);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	Z_SET_ISREF_P(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "array_pop", &_3, _1);
	Z_UNSET_ISREF_P(_1);
	zephir_check_call_status();
	zephir_get_strval(_4, _2);
	ZEPHIR_CPY_WRT(savepoint, _4);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "release savepoint ", savepoint);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 2);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "query", NULL, _7, _6);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Db_DbAdapter, rollbackToSavepoint) {

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_2 = NULL, *_4 = NULL, *_5, *_6 = NULL;
	zval *savepoint = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Cannot rollback to a savepoint when not in a transaction", "nc/db/dbadapter.zep", 80);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_1, savepoint)))) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SV(_3, "Invalid savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "nc/db/dbadapter.zep", 84 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_SV(_3, "rollback to savepoint ", savepoint);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 2);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "query", NULL, _2, _3);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		while (1) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
			Z_SET_ISREF_P(_5);
			ZEPHIR_CALL_FUNCTION(&_6, "array_pop", &_7, _5);
			Z_UNSET_ISREF_P(_5);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(_6, savepoint)) {
				break;
			}
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Db_DbAdapter, rollbackToLastSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_0, *_1, *_2 = NULL, *_5 = NULL, *_7;
	zval *savepoint = NULL, *_4 = NULL, *_6;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Empty savepoint stack", "nc/db/dbadapter.zep", 104);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	Z_SET_ISREF_P(_1);
	ZEPHIR_CALL_FUNCTION(&_2, "array_pop", &_3, _1);
	Z_UNSET_ISREF_P(_1);
	zephir_check_call_status();
	zephir_get_strval(_4, _2);
	ZEPHIR_CPY_WRT(savepoint, _4);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "rollback to savepoint ", savepoint);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 2);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "query", NULL, _7, _6);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Db_DbAdapter, setQueryClass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *queryClass_param = NULL, _0, *_1 = NULL, *_3;
	zval *queryClass = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queryClass_param);

	zephir_get_strval(queryClass, queryClass_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Nc\\Db\\Query\\DbQueryAdapter", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", &_2, queryClass, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Invalid query class: ", queryClass);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "nc/db/dbadapter.zep", 119 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("queryClass"), queryClass TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAdapter, getQueryClass) {


	RETURN_MEMBER(this_ptr, "queryClass");

}

PHP_METHOD(Nc_Db_DbAdapter, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_3;
	zval *table_param = NULL, *tableAlias_param = NULL, *_0, *_2 = NULL;
	zval *table = NULL, *tableAlias = NULL, *queryClass = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &tableAlias_param);

	zephir_get_strval(table, table_param);
	if (!tableAlias_param) {
		ZEPHIR_INIT_VAR(tableAlias);
		ZVAL_STRING(tableAlias, "", 1);
	} else {
		zephir_get_strval(tableAlias, tableAlias_param);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("queryClass"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(queryClass, _1);
	zephir_fetch_safe_class(_2, queryClass);
	_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _3);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, table, tableAlias);
		zephir_check_call_status();
	}
	RETURN_MM();

}

