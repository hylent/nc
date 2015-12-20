
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Router_SourceRequestUri) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Router, SourceRequestUri, nc, router_sourcerequesturi, nc_router_sourceuri_ce, nc_router_sourcerequesturi_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Router_SourceRequestUri, __construct) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *_SERVER, *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(uri);
	if (unlikely(!(zephir_array_isset_string_fetch(&uri, _SERVER, SS("REQUEST_URI"), 0 TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_router_exception_ce, "Invalid request uri", "nc/router/sourcerequesturi.zep", 10);
		return;
	}
	zephir_get_strval(_1, uri);
	ZEPHIR_CALL_PARENT(NULL, nc_router_sourcerequesturi_ce, this_ptr, "__construct", &_0, 103, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

