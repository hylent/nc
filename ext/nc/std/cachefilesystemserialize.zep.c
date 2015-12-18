
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
#include "kernel/time.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Std_CacheFileSystemSerialize) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Std, CacheFileSystemSerialize, nc, std_cachefilesystemserialize, nc_std_cachefilesystemabstract_ce, nc_std_cachefilesystemserialize_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Std_CacheFileSystemSerialize, packData) {

	zval *d;
	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *data, *lifetime_param = NULL, *_4 = NULL, *_0$$3, _1$$3, _2$$3, *_3$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &lifetime_param);

	lifetime = zephir_get_intval(lifetime_param);


	ZEPHIR_INIT_VAR(d);
	ZVAL_STRING(d, "<?php return", 1);
	if (lifetime > 0) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_time(_0$$3);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, " time() > %d ? null :", 0);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_LONG(&_2$$3, (zephir_get_intval(_0$$3) + lifetime));
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_concat_self(&d, _3$$3 TSRMLS_CC);
	}
	zephir_concat_self_str(&d, " @unserialize(file_get_contents(__FILE__, false, null, __COMPILER_HALT_OFFSET__));", sizeof(" @unserialize(file_get_contents(__FILE__, false, null, __COMPILER_HALT_OFFSET__));")-1 TSRMLS_CC);
	zephir_concat_self_str(&d, " __halt_compiler();", sizeof(" __halt_compiler();")-1 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "serialize", NULL, 124, data);
	zephir_check_call_status();
	zephir_concat_self(&d, _4 TSRMLS_CC);
	RETURN_CTOR(d);

}

