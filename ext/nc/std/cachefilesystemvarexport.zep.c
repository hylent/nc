
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
#include "kernel/variables.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Std_CacheFileSystemVarExport) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Std, CacheFileSystemVarExport, nc, std_cachefilesystemvarexport, nc_std_cachefilesystemabstract_ce, nc_std_cachefilesystemvarexport_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Std_CacheFileSystemVarExport, packData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	long lifetime;
	zval *data, *lifetime_param = NULL, *_0$$3 = NULL, _1$$3, *_3, *_4 = NULL, _5, _6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &lifetime_param);

	lifetime = zephir_get_intval(lifetime_param);


	if (lifetime < 1) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_INIT_NVAR(_0$$3);
		zephir_var_export_ex(_0$$3, &data TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "<?php return %s;\n", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 1, &_1$$3, _0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_time(_3);
	lifetime += zephir_get_intval(_3);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_NVAR(_4);
	zephir_var_export_ex(_4, &data TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "<?php return time() > %d ? null : %s;\n", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, lifetime);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 1, &_5, &_6, _4);
	zephir_check_call_status();
	RETURN_MM();

}

