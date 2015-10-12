
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
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Router_UriEnhanced) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Router, UriEnhanced, nc, router_urienhanced, nc_router_uri_ce, nc_router_urienhanced_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Router_UriEnhanced, __construct) {

	zend_bool _2$$5;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *uri = NULL, *baseUri = NULL, *scriptName = NULL, *pos = NULL, *_0, *_1$$3, _3$$7, _4$$8, _5$$8;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_SAPI");
	ZEPHIR_INIT_VAR(baseUri);
	if (ZEPHIR_IS_STRING(_0, "cli")) {
		ZEPHIR_OBS_VAR(uri);
		zephir_array_fetch_string(&_1$$3, _SERVER, SL("argv"), PH_READONLY, "nc/router/urienhanced.zep", 10 TSRMLS_CC);
		if (!(zephir_array_isset_long_fetch(&uri, _1$$3, 1, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(uri);
			ZVAL_STRING(uri, "", 1);
		}
		ZVAL_STRING(baseUri, "", 1);
	} else {
		ZEPHIR_OBS_NVAR(uri);
		if (unlikely(!(zephir_array_isset_string_fetch(&uri, _SERVER, SS("REQUEST_URI"), 0 TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_router_exception_ce, "Cannot find request uri variable in server super globals", "nc/router/urienhanced.zep", 16);
			return;
		}
		ZVAL_STRING(baseUri, "/", 1);
		ZEPHIR_OBS_VAR(scriptName);
		_2$$5 = zephir_array_isset_string_fetch(&scriptName, _SERVER, SS("SCRIPT_NAME"), 0 TSRMLS_CC);
		if (_2$$5) {
			_2$$5 = Z_TYPE_P(scriptName) == IS_STRING;
		}
		if (_2$$5) {
			ZEPHIR_SINIT_VAR(_3$$7);
			ZVAL_STRING(&_3$$7, "/", 0);
			ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 82, scriptName, &_3$$7);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
				ZEPHIR_SINIT_VAR(_4$$8);
				ZVAL_LONG(&_4$$8, 0);
				ZEPHIR_SINIT_VAR(_5$$8);
				ZVAL_LONG(&_5$$8, (1 + zephir_get_numberval(pos)));
				ZEPHIR_INIT_NVAR(baseUri);
				zephir_substr(baseUri, scriptName, 0 , zephir_get_intval(&_5$$8), 0);
			}
		}
	}
	ZEPHIR_CALL_PARENT(NULL, nc_router_urienhanced_ce, this_ptr, "__construct", &_6, 92, uri, baseUri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

