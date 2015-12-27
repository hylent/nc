
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_View_Json) {

	ZEPHIR_REGISTER_CLASS(Nc\\View, Json, nc, view_json, nc_view_json_method_entry, 0);

	zend_class_implements(nc_view_json_ce TSRMLS_CC, 1, nc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_View_Json, run) {

	zend_bool jsonCors = 0, jsonHeaderPlain = 0;
	zval *jsonCallback = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_7 = NULL;
	zval *data_param = NULL, *options_param = NULL, *jsonFlag = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, _6$$3, _8$$4, *_9$$5, _10$$5, *_11$$5 = NULL, *_12$$6;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "jsonFlag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_CE_STATIC(&jsonFlag, nc_std_ce, "valueat", &_0, 4, options, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "jsonCallback", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_3, nc_std_ce, "valueat", &_0, 4, options, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(jsonCallback, _4);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "jsonCors", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_CE_STATIC(&_5, nc_std_ce, "valueat", &_0, 4, options, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	jsonCors = zephir_get_boolval(_5);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "jsonHeaderPlain", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_CE_STATIC(&_5, nc_std_ce, "valueat", &_0, 4, options, _1, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	jsonHeaderPlain = zephir_get_boolval(_5);
	if (jsonCors) {
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_STRING(&_6$$3, "Access-Control-Allow-Origin: *", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, 143, &_6$$3);
		zephir_check_call_status();
	}
	if (jsonHeaderPlain) {
		ZEPHIR_SINIT_VAR(_8$$4);
		ZVAL_STRING(&_8$$4, "Content-type: text/plain; charset=UTF-8", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_7, 143, &_8$$4);
		zephir_check_call_status();
	}
	if (zephir_fast_strlen_ev(jsonCallback) > 0) {
		ZEPHIR_INIT_VAR(_9$$5);
		zephir_json_encode(_9$$5, &(_9$$5), data, zephir_get_intval(jsonFlag)  TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_10$$5);
		ZVAL_STRING(&_10$$5, "%s(%s);", 0);
		ZEPHIR_CALL_FUNCTION(&_11$$5, "sprintf", NULL, 1, &_10$$5, jsonCallback, _9$$5);
		zephir_check_call_status();
		zend_print_zval(_11$$5, 0);
	} else {
		ZEPHIR_INIT_VAR(_12$$6);
		zephir_json_encode(_12$$6, &(_12$$6), data, zephir_get_intval(jsonFlag)  TSRMLS_CC);
		zend_print_zval(_12$$6, 0);
	}
	ZEPHIR_MM_RESTORE();

}

