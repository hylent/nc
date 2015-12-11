
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

	zval *readFile = NULL, *_4 = NULL, *_7$$4, *_12$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_9 = NULL;
	zval *data_param = NULL, *options_param = NULL, *_0 = NULL, *_2, *_3, *_5 = NULL, _8 = zval_used_for_init, *_10 = NULL, *_6$$4, *_11$$5;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "readFile", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 5, options, _2, _3);
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
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "Content-Description: File Transfer", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 131, &_8);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_STRING(&_8, "Content-Type: application/octet-stream", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 131, &_8);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_STRING(&_8, "Content-Transfer-Encoding: binary", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 131, &_8);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_STRING(&_8, "Expires: 0", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 131, &_8);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_STRING(&_8, "Cache-Control: must-revalidate", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 131, &_8);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_STRING(&_8, "Pragma: public", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 131, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_10, "readfile", NULL, 135, readFile);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_10))) {
		ZEPHIR_INIT_VAR(_11$$5);
		object_init_ex(_11$$5, nc_view_exception_ce);
		ZEPHIR_INIT_VAR(_12$$5);
		ZEPHIR_CONCAT_SV(_12$$5, "Cannot read file: ", readFile);
		ZEPHIR_CALL_METHOD(NULL, _11$$5, "__construct", NULL, 2, _12$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_11$$5, "nc/view/readfile.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

