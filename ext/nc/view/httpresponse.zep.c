
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


ZEPHIR_INIT_CLASS(Nc_View_HttpResponse) {

	ZEPHIR_REGISTER_CLASS(Nc\\View, HttpResponse, nc, view_httpresponse, nc_view_httpresponse_method_entry, 0);

	zend_class_implements(nc_view_httpresponse_ce TSRMLS_CC, 1, nc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_View_HttpResponse, run) {

	zval *httpResponseContent = NULL, *_6 = NULL;
	long httpResponseCode = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, *options_param = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, _4, *_5 = NULL;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "httpResponseCode", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 200);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 4, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	httpResponseCode = zephir_get_intval(_0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, httpResponseCode);
	ZEPHIR_CALL_FUNCTION(NULL, "http_response_code", NULL, 146, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "httpResponseContent", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_5, nc_std_ce, "valueat", &_1, 4, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(httpResponseContent, _6);
	zend_print_zval(httpResponseContent, 0);
	ZEPHIR_MM_RESTORE();

}

