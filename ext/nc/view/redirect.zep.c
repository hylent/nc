
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
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_View_Redirect) {

	ZEPHIR_REGISTER_CLASS(Nc\\View, Redirect, nc, view_redirect, nc_view_redirect_method_entry, 0);

	zend_class_implements(nc_view_redirect_ce TSRMLS_CC, 1, nc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_View_Redirect, run) {

	zend_bool redirectDataAsQueries = 0, _7;
	zval *redirectUrl = NULL, *_4 = NULL, *_11;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, *options_param = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, _8$$4, *_9$$4, *_10$$4 = NULL;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "redirectUrl", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(redirectUrl, _4);
	if (unlikely(zephir_fast_strlen_ev(redirectUrl) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_view_exception_ce, "Missing option: redirectUrl", "nc/view/redirect.zep", 14);
		return;
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "redirectDataAsQueries", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_CALL_CE_STATIC(&_6, nc_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	redirectDataAsQueries = zephir_get_boolval(_6);
	_7 = redirectDataAsQueries;
	if (_7) {
		_7 = zephir_fast_count_int(data TSRMLS_CC) > 0;
	}
	if (_7) {
		ZEPHIR_SINIT_VAR(_8$$4);
		ZVAL_STRING(&_8$$4, "?", 0);
		ZEPHIR_INIT_VAR(_9$$4);
		zephir_fast_strpos(_9$$4, redirectUrl, &_8$$4, 0 );
		if (ZEPHIR_IS_FALSE_IDENTICAL(_9$$4)) {
			zephir_concat_self_str(&redirectUrl, "?", sizeof("?")-1 TSRMLS_CC);
		} else {
			zephir_concat_self_str(&redirectUrl, "&", sizeof("&")-1 TSRMLS_CC);
		}
		ZEPHIR_CALL_FUNCTION(&_10$$4, "http_build_query", NULL, 146, data);
		zephir_check_call_status();
		zephir_concat_self(&redirectUrl, _10$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_SV(_11, "Location: ", redirectUrl);
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 141, _11);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

