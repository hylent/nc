
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Db_DbAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Db, DbAbstract, nc, db_dbabstract, nc_db_dbabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_bool(nc_db_dbabstract_ce, SL("inTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_db_dbabstract_ce, SL("savepointSerial"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_dbabstract_ce, SL("savepoints"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_db_dbabstract_ce, SL("queryClass"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_db_dbabstract_ce TSRMLS_CC, 1, nc_db_dbinterface_ce);
	return SUCCESS;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot begin when already in transaction", "nc/db/dbabstract.zep", 18);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytobegin", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot begin transaction", "nc/db/dbabstract.zep", 22);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot commit when not in transaction", "nc/db/dbabstract.zep", 31);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytocommit", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot commit transaction", "nc/db/dbabstract.zep", 35);
		return;
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("savepoints"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, rollback) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback when not in transaction", "nc/db/dbabstract.zep", 45);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytorollback", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot rollback transaction", "nc/db/dbabstract.zep", 49);
		return;
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("savepoints"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, savepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1 = NULL, *_6, *_9 = NULL, *_11, *_2$$4, _3$$4, *_4$$4 = NULL, *_7$$5, *_12$$6;
	zval *savepoint = NULL, *_10, *_5$$4 = NULL, *_8$$5, *_13$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &savepoint_param);

	if (!savepoint_param) {
		ZEPHIR_INIT_VAR(savepoint);
		ZVAL_STRING(savepoint, "", 1);
	} else {
		zephir_get_strval(savepoint, savepoint_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_savepointexception_ce, "Cannot acquire a savepoint when not in a transaction", "nc/db/dbabstract.zep", 59);
		return;
	}
	if (zephir_fast_strlen_ev(savepoint) < 1) {
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("savepointSerial") TSRMLS_CC));
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("savepointSerial"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_3$$4);
		ZVAL_STRING(&_3$$4, "s%06d", 0);
		ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", NULL, 6, &_3$$4, _2$$4);
		zephir_check_call_status();
		zephir_get_strval(_5$$4, _4$$4);
		ZEPHIR_CPY_WRT(savepoint, _5$$4);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(zephir_array_isset(_6, savepoint))) {
		ZEPHIR_INIT_VAR(_7$$5);
		object_init_ex(_7$$5, nc_db_savepointexception_ce);
		ZEPHIR_INIT_VAR(_8$$5);
		ZEPHIR_CONCAT_SV(_8$$5, "Duplicate savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", NULL, 2, _8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$5, "nc/db/dbabstract.zep", 68 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SV(_10, "savepoint ", savepoint);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, 2);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "query", NULL, 0, _11, _10);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_9))) {
		ZEPHIR_INIT_VAR(_12$$6);
		object_init_ex(_12$$6, nc_db_savepointexception_ce);
		ZEPHIR_INIT_VAR(_13$$6);
		ZEPHIR_CONCAT_SV(_13$$6, "Cannot acquire savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _12$$6, "__construct", NULL, 2, _13$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12$$6, "nc/db/dbabstract.zep", 72 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
	RETURN_CTOR(savepoint);

}

PHP_METHOD(Nc_Db_DbAbstract, releaseSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_4 = NULL, *_6, *_9, *_2$$4, *_7$$5;
	zval *savepoint = NULL, *_5, *_3$$4, *_8$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_savepointexception_ce, "Cannot release a savepoint when not in a transaction", "nc/db/dbabstract.zep", 82);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_1, savepoint)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_db_savepointexception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot find savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/db/dbabstract.zep", 86 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "release savepoint ", savepoint);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 2);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "query", NULL, 0, _6, _5);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_INIT_VAR(_7$$5);
		object_init_ex(_7$$5, nc_db_savepointexception_ce);
		ZEPHIR_INIT_VAR(_8$$5);
		ZEPHIR_CONCAT_SV(_8$$5, "Cannot release savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", NULL, 2, _8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$5, "nc/db/dbabstract.zep", 90 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	zephir_array_unset(&_9, savepoint, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, releaseLastSavepoint) {

	zval *_0, *_1, *_2, *_3 = NULL, *_5 = NULL, *_7, *_8$$5;
	zval *savepoint = NULL, *_4 = NULL, *_6, *_9$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_savepointexception_ce, "Cannot release last savepoint when not in a transaction", "nc/db/dbabstract.zep", 101);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_savepointexception_ce, "Empty savepoint stack", "nc/db/dbabstract.zep", 105);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "array_pop", NULL, 7, _2);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(savepoint, _4);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "release savepoint ", savepoint);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 2);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "query", NULL, 0, _7, _6);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$5);
		object_init_ex(_8$$5, nc_db_savepointexception_ce);
		ZEPHIR_INIT_VAR(_9$$5);
		ZEPHIR_CONCAT_SV(_9$$5, "Cannot release last savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 2, _9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$5, "nc/db/dbabstract.zep", 112 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, rollbackToSavepoint) {

	zephir_fcall_cache_entry *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_4 = NULL, *_6, *_2$$4, *_7$$5, *_9$$6, *_10$$6 = NULL;
	zval *savepoint = NULL, *_5, *_3$$4, *_8$$5, *_12$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_savepointexception_ce, "Cannot rollback to a savepoint when not in a transaction", "nc/db/dbabstract.zep", 119);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_1, savepoint)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_db_savepointexception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot find savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/db/dbabstract.zep", 123 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "rollback to savepoint ", savepoint);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 2);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "query", NULL, 0, _6, _5);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_INIT_VAR(_7$$5);
		object_init_ex(_7$$5, nc_db_savepointexception_ce);
		ZEPHIR_INIT_VAR(_8$$5);
		ZEPHIR_CONCAT_SV(_8$$5, "Cannot rollback to savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", NULL, 2, _8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$5, "nc/db/dbabstract.zep", 127 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		_9$$6 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_10$$6, "array_pop", &_11, 7, _9$$6);
		zephir_check_call_status();
		zephir_get_strval(_12$$6, _10$$6);
		if (ZEPHIR_IS_EQUAL(_12$$6, savepoint)) {
			zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, rollbackToLastSavepoint) {

	zval *_0, *_1, *_2, *_3 = NULL, *_5 = NULL, *_7, *_8$$5;
	zval *savepoint = NULL, *_4 = NULL, *_6, *_9$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_savepointexception_ce, "Cannot rollback to last savepoint when not in a transaction", "nc/db/dbabstract.zep", 143);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_savepointexception_ce, "Empty savepoint stack", "nc/db/dbabstract.zep", 147);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "array_pop", NULL, 7, _2);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(savepoint, _4);
	zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "rollback to savepoint ", savepoint);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 2);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "query", NULL, 0, _7, _6);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_8$$5);
		object_init_ex(_8$$5, nc_db_savepointexception_ce);
		ZEPHIR_INIT_VAR(_9$$5);
		ZEPHIR_CONCAT_SV(_9$$5, "Cannot rollback to last savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 2, _9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$5, "nc/db/dbabstract.zep", 154 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, transactionAtomic) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *callback, *args_param = NULL, *result = NULL, *ex = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}


	if (unlikely(!(zephir_is_callable(callback TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid callback", "nc/db/dbabstract.zep", 163);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!(!zephir_is_true(_0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_transactionexception_ce, "Cannot do transaction atomic operations when in a transaction", "nc/db/dbabstract.zep", 167);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_INIT_VAR(result);
		ZEPHIR_CALL_USER_FUNC_ARRAY(result, callback, args);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "commit", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_CCTOR(result);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(ex, EG(exception));
		if (zephir_instance_of_ev(ex, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(ex, "nc/db/dbabstract.zep", 178 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, savepointAtomic) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepointIfNeeded = NULL, *savepoint = NULL, *_2 = NULL;
	zval *args = NULL;
	zval *callback, *args_param = NULL, *savepointIfNeeded_param = NULL, *ex = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &callback, &args_param, &savepointIfNeeded_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}
	if (!savepointIfNeeded_param) {
		ZEPHIR_INIT_VAR(savepointIfNeeded);
		ZVAL_STRING(savepointIfNeeded, "", 1);
	} else {
		zephir_get_strval(savepointIfNeeded, savepointIfNeeded_param);
	}


	if (unlikely(!(zephir_is_callable(callback TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_exception_ce, "Invalid callback", "nc/db/dbabstract.zep", 188);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_db_savepointexception_ce, "Cannot do savepoint atomic operations when not in a transaction", "nc/db/dbabstract.zep", 192);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "savepoint", NULL, 0, savepointIfNeeded);
	zephir_check_call_status();
	zephir_get_strval(_2, _1);
	ZEPHIR_CPY_WRT(savepoint, _2);

	/* try_start_1: */

		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, callback, args);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(ex, EG(exception));
		if (zephir_instance_of_ev(ex, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollbacktosavepoint", NULL, 0, savepoint);
			zephir_check_call_status();
			zephir_throw_exception_debug(ex, "nc/db/dbabstract.zep", 201 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}

}

PHP_METHOD(Nc_Db_DbAbstract, atomic) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *callback, *args_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "savepointatomic", NULL, 0, callback, args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "transactionatomic", NULL, 0, callback, args);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, setQueryClass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *queryClass_param = NULL, _0, *_1 = NULL, *_2$$3;
	zval *queryClass = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queryClass_param);

	zephir_get_strval(queryClass, queryClass_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Nc\\Db\\Query\\DbQueryAbstract", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", NULL, 8, queryClass, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, nc_db_exception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid query class: ", queryClass);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "nc/db/dbabstract.zep", 217 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("queryClass"), queryClass TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Db_DbAbstract, getQueryClass) {

	

	RETURN_MEMBER(this_ptr, "queryClass");

}

PHP_METHOD(Nc_Db_DbAbstract, __invoke) {

	zend_class_entry *_3;
	int ZEPHIR_LAST_CALL_STATUS;
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
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr, table, tableAlias);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Nc_Db_DbAbstract, tryToBegin) {

}

PHP_METHOD(Nc_Db_DbAbstract, tryToCommit) {

}

PHP_METHOD(Nc_Db_DbAbstract, tryToRollback) {

}

