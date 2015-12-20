
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
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_View_Content) {

	ZEPHIR_REGISTER_CLASS(Nc\\View, Content, nc, view_content, nc_view_content_method_entry, 0);

	zend_class_implements(nc_view_content_ce TSRMLS_CC, 1, nc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_View_Content, run) {

	zval *content = NULL, *contentType = NULL, *_4 = NULL, *_6 = NULL, *_8$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, *options_param = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 4, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(content, _4);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "contentType", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_5, nc_std_ce, "valueat", &_1, 4, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(contentType, _6);
	if (zephir_fast_strlen_ev(contentType) > 0) {
		ZEPHIR_INIT_VAR(_8$$3);
		ZEPHIR_CONCAT_SV(_8$$3, "Content-Type: ", contentType);
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 150, _8$$3);
		zephir_check_call_status();
	}
	zend_print_zval(content, 0);
	ZEPHIR_MM_RESTORE();

}

