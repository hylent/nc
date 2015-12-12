
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


ZEPHIR_INIT_CLASS(Nc_Router_SourceArgv) {

	ZEPHIR_REGISTER_CLASS(Nc\\Router, SourceArgv, nc, router_sourceargv, nc_router_sourceargv_method_entry, 0);

	zend_class_implements(nc_router_sourceargv_ce TSRMLS_CC, 1, nc_router_sourceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Router_SourceArgv, getSource) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *argv = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(argv);
	_0 = !(zephir_array_isset_string_fetch(&argv, _SERVER, SS("argv"), 0 TSRMLS_CC));
	if (!(_0)) {
		_0 = Z_TYPE_P(argv) != IS_ARRAY;
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_router_exception_ce, "Invalid argv", "nc/router/sourceargv.zep", 10);
		return;
	}
	ZEPHIR_MAKE_REF(argv);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 6, argv);
	ZEPHIR_UNREF(argv);
	zephir_check_call_status();
	RETURN_CCTOR(argv);

}

