
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_SessionAutoGcSaveHandler) {

	ZEPHIR_REGISTER_CLASS(Nc\\Mvc, SessionAutoGcSaveHandler, nc, mvc_sessionautogcsavehandler, nc_mvc_sessionautogcsavehandler_method_entry, 0);

	zend_declare_property_null(nc_mvc_sessionautogcsavehandler_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_mvc_sessionautogcsavehandler_ce, SL("gcMaxLifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_mvc_sessionautogcsavehandler_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *storage, storage_sub, _0, _1, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&storage_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &storage);



	zephir_update_property_zval(this_ptr, SL("storage"), storage);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.gc_maxlifetime");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 29, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, zephir_get_intval(&_1));
	zephir_update_property_zval(this_ptr, SL("gcMaxLifetime"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, register) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 115, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.gc_probability");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 116, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, getStorage) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "storage");

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, open) {

	zval *savePath_param = NULL, *sessionName_param = NULL;
	zval savePath, sessionName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&savePath);
	ZVAL_UNDEF(&sessionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &savePath_param, &sessionName_param);

	zephir_get_strval(&savePath, savePath_param);
	zephir_get_strval(&sessionName, sessionName_param);


	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0$$3, _1$$3;
	zval id, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);



	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, SL("storage"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "readsessiondata", NULL, 0, &id);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_get_strval(&_2$$3, &_1$$3);
		RETURN_CTOR(_2$$3);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_STRING("");

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, write) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *data_param = NULL, _0$$3, _1$$3;
	zval id, data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &data_param);

	zephir_get_strval(&id, id_param);
	zephir_get_strval(&data, data_param);



	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, SL("storage"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, this_ptr, SL("gcMaxLifetime"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "writesessiondata", NULL, 0, &id, &data, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM_BOOL(1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0$$3;
	zval id;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);



	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, SL("storage"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "destroysessiondata", NULL, 0, &id);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM_BOOL(1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, close) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(1);

}

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, gc) {

	zval *maxLifetime_param = NULL;
	long maxLifetime;
	ZEPHIR_INIT_THIS();


	zephir_fetch_params(0, 1, 0, &maxLifetime_param);

	maxLifetime = zephir_get_intval(maxLifetime_param);


	RETURN_BOOL(1);

}

