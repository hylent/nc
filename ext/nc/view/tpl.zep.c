
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
#include "kernel/file.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_View_Tpl) {

	ZEPHIR_REGISTER_CLASS(Nc\\View, Tpl, nc, view_tpl, nc_view_tpl_method_entry, 0);

	zend_class_implements(nc_view_tpl_ce TSRMLS_CC, 1, nc_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_View_Tpl, run) {

	zend_bool _13;
	zval *tplBaseDirectory = NULL, *tplLayoutDirectory = NULL, *tplId = NULL, *tplExtension = NULL, *tplLayout = NULL, *path = NULL, *_4 = NULL, *_7, *_8 = NULL, *_11 = NULL, *_17 = NULL, *_19 = NULL, *_23 = NULL, *_25$$6, *_31$$7 = NULL, *_33$$9;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_22 = NULL, *_35 = NULL;
	zval *data_param = NULL, *options_param = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_9 = NULL, *_10 = NULL, *_12 = NULL, _14, *_15 = NULL, *_16 = NULL, *_18 = NULL, _20, *_21 = NULL, *_26 = NULL, *_34 = NULL, *_24$$6, _27$$7, *_28$$7, _29$$7, *_30$$7 = NULL, *_32$$9;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "tplBaseDirectory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(tplBaseDirectory, _4);
	if (unlikely(zephir_fast_strlen_ev(tplBaseDirectory) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_view_exception_ce, "Missing option: tplBaseDirectory", "nc/view/tpl.zep", 13);
		return;
	}
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_VS(_7, tplBaseDirectory, "/layout");
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "tplLayoutDirectory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_6, nc_std_ce, "valueat", &_1, 5, options, _2, _7);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_8, _6);
	ZEPHIR_CPY_WRT(tplLayoutDirectory, _8);
	if (unlikely(zephir_fast_strlen_ev(tplLayoutDirectory) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_view_exception_ce, "Invalid option: tplLayoutDirectory", "nc/view/tpl.zep", 18);
		return;
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "tplId", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_10, nc_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_11, _10);
	ZEPHIR_CPY_WRT(tplId, _11);
	_13 = zephir_fast_strlen_ev(tplId) < 1;
	if (!(_13)) {
		ZEPHIR_SINIT_VAR(_14);
		ZVAL_STRING(&_14, "..", 0);
		ZEPHIR_INIT_NVAR(_2);
		zephir_fast_strpos(_2, tplId, &_14, 0 );
		_13 = !ZEPHIR_IS_FALSE_IDENTICAL(_2);
	}
	if (unlikely(_13)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_view_exception_ce, "Invalid option: tplId", "nc/view/tpl.zep", 23);
		return;
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "tplExtension", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_STRING(_16, "phtml", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_15, nc_std_ce, "valueat", &_1, 5, options, _3, _16);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	zephir_get_strval(_17, _15);
	ZEPHIR_CPY_WRT(tplExtension, _17);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "tplLayout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_STRING(_16, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_18, nc_std_ce, "valueat", &_1, 5, options, _3, _16);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_16);
	zephir_check_call_status();
	zephir_get_strval(_19, _18);
	ZEPHIR_CPY_WRT(tplLayout, _19);
	ZEPHIR_SINIT_VAR(_20);
	ZVAL_STRING(&_20, "%s/%s.%s", 0);
	ZEPHIR_CALL_FUNCTION(&_21, "sprintf", &_22, 1, &_20, tplBaseDirectory, tplId, tplExtension);
	zephir_check_call_status();
	zephir_get_strval(_23, _21);
	ZEPHIR_CPY_WRT(path, _23);
	if (unlikely(!((zephir_file_exists(path TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(_24$$6);
		object_init_ex(_24$$6, nc_view_exception_ce);
		ZEPHIR_INIT_VAR(_25$$6);
		ZEPHIR_CONCAT_SV(_25$$6, "Cannot find tpl path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _24$$6, "__construct", NULL, 2, _25$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_24$$6, "nc/view/tpl.zep", 31 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_strlen_ev(tplLayout) > 0) {
		ZEPHIR_SINIT_VAR(_27$$7);
		ZVAL_STRING(&_27$$7, "..", 0);
		ZEPHIR_INIT_VAR(_28$$7);
		zephir_fast_strpos(_28$$7, tplLayout, &_27$$7, 0 );
		if (unlikely(!ZEPHIR_IS_FALSE_IDENTICAL(_28$$7))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_view_exception_ce, "Invalid option: tplLayout", "nc/view/tpl.zep", 36);
			return;
		}
		zephir_array_update_string(&data, SL("__tpl_path"), &path, PH_COPY | PH_SEPARATE);
		ZEPHIR_SINIT_VAR(_29$$7);
		ZVAL_STRING(&_29$$7, "%s/%s.%s", 0);
		ZEPHIR_CALL_FUNCTION(&_30$$7, "sprintf", &_22, 1, &_29$$7, tplLayoutDirectory, tplLayout, tplExtension);
		zephir_check_call_status();
		zephir_get_strval(_31$$7, _30$$7);
		ZEPHIR_CPY_WRT(path, _31$$7);
		if (unlikely(!((zephir_file_exists(path TSRMLS_CC) == SUCCESS)))) {
			ZEPHIR_INIT_VAR(_32$$9);
			object_init_ex(_32$$9, nc_view_exception_ce);
			ZEPHIR_INIT_VAR(_33$$9);
			ZEPHIR_CONCAT_SV(_33$$9, "Cannot find layout path: ", path);
			ZEPHIR_CALL_METHOD(NULL, _32$$9, "__construct", NULL, 2, _33$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_32$$9, "nc/view/tpl.zep", 41 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_CE_STATIC(&_34, nc_std_ce, "renderscript", &_35, 147, path, data);
	zephir_check_call_status();
	zend_print_zval(_34, 0);
	ZEPHIR_MM_RESTORE();

}

