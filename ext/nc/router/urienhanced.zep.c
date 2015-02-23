
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Router_UriEnhanced) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Router, UriEnhanced, nc, router_urienhanced, nc_router_uri_ce, nc_router_urienhanced_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Router_UriEnhanced, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_7 = NULL;
	zend_bool _2;
	zval *uri = NULL, *baseUri = NULL, *scriptName, *pos = NULL, *_0, *_SERVER, *_1, _3 = zval_used_for_init, _5;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_SAPI");
	ZEPHIR_INIT_VAR(baseUri);
	if (ZEPHIR_IS_STRING(_0, "cli")) {
		ZEPHIR_OBS_VAR(uri);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		zephir_array_fetch_string(&_1, _SERVER, SL("argv"), PH_READONLY, "nc/router/urienhanced.zep", 10 TSRMLS_CC);
		if (!(zephir_array_isset_long_fetch(&uri, _1, 1, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(uri);
			ZVAL_STRING(uri, "", 1);
		}
		ZVAL_STRING(baseUri, "", 1);
	} else {
		ZEPHIR_OBS_NVAR(uri);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (unlikely(!(zephir_array_isset_string_fetch(&uri, _SERVER, SS("REQUEST_URI"), 0 TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_router_exception_ce, "Cannot find request uri variable in server super globals", "nc/router/urienhanced.zep", 16);
			return;
		}
		ZVAL_STRING(baseUri, "/", 1);
		ZEPHIR_OBS_VAR(scriptName);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		_2 = zephir_array_isset_string_fetch(&scriptName, _SERVER, SS("SCRIPT_NAME"), 0 TSRMLS_CC);
		if (_2) {
			_2 = Z_TYPE_P(scriptName) == IS_STRING;
		}
		if (_2) {
			ZEPHIR_SINIT_VAR(_3);
			ZVAL_STRING(&_3, "/", 0);
			ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_4, scriptName, &_3);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, 0);
				ZEPHIR_SINIT_VAR(_5);
				ZVAL_LONG(&_5, (1 + zephir_get_numberval(pos)));
				ZEPHIR_CALL_FUNCTION(&baseUri, "substr", &_6, scriptName, &_3, &_5);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_PARENT(NULL, nc_router_urienhanced_ce, this_ptr, "__construct", &_7, uri, baseUri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

