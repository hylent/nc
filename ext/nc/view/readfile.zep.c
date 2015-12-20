
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
#include "kernel/file.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_View_ReadFile) {

	ZEPHIR_REGISTER_CLASS(Nc\\View, ReadFile, nc, view_readfile, nc_view_readfile_method_entry, 0);

	zend_class_implements(nc_view_readfile_ce TSRMLS_CC, 1, nc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_View_ReadFile, run) {

	zval *readFile = NULL, *readFileContentType = NULL, *_4 = NULL, *_9 = NULL, *_7$$4, *_11$$5, *_17$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_12 = NULL;
	zval *data_param = NULL, *options_param = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_8 = NULL, *_10 = NULL, _14 = zval_used_for_init, *_15 = NULL, *_6$$4, _13$$6 = zval_used_for_init, *_16$$7;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "readFile", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 4, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(readFile, _4);
	if (unlikely(zephir_fast_strlen_ev(readFile) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_view_exception_ce, "Missing option: readFile", "nc/view/readfile.zep", 13);
		return;
	}
	if (unlikely(!((zephir_file_exists(readFile TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, nc_view_exception_ce);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_SV(_7$$4, "Cannot find file in path: ", readFile);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 2, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "nc/view/readfile.zep", 17 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "readFileContentType", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_8, nc_std_ce, "valueat", &_1, 4, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_9, _8);
	ZEPHIR_CPY_WRT(readFileContentType, _9);
	if (zephir_fast_strlen_ev(readFileContentType) > 0) {
		ZEPHIR_INIT_VAR(_11$$5);
		ZEPHIR_CONCAT_SV(_11$$5, "Content-Type: ", readFileContentType);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, 150, _11$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_13$$6);
		ZVAL_STRING(&_13$$6, "Content-Description: File Transfer", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, 150, &_13$$6);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_13$$6);
		ZVAL_STRING(&_13$$6, "Content-Type: application/octet-stream", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, 150, &_13$$6);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_13$$6);
		ZVAL_STRING(&_13$$6, "Content-Transfer-Encoding: binary", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, 150, &_13$$6);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_STRING(&_14, "Expires: 0", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, 150, &_14);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_14);
	ZVAL_STRING(&_14, "Cache-Control: must-revalidate", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, 150, &_14);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_14);
	ZVAL_STRING(&_14, "Pragma: public", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_12, 150, &_14);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_15, "readfile", NULL, 154, readFile);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_15))) {
		ZEPHIR_INIT_VAR(_16$$7);
		object_init_ex(_16$$7, nc_view_exception_ce);
		ZEPHIR_INIT_VAR(_17$$7);
		ZEPHIR_CONCAT_SV(_17$$7, "Cannot read file: ", readFile);
		ZEPHIR_CALL_METHOD(NULL, _16$$7, "__construct", NULL, 2, _17$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_16$$7, "nc/view/readfile.zep", 34 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

