
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Std_CacheApc) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, CacheApc, nc, std_cacheapc, nc_std_cacheapc_method_entry, 0);

	zend_declare_property_null(nc_std_cacheapc_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_cacheapc_ce, SL("DEFAULT_PREFIX"), "cache:" TSRMLS_CC);

	zend_class_implements(nc_std_cacheapc_ce TSRMLS_CC, 1, nc_std_cacheinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_CacheApc, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, _0, *_1 = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "cache:", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apc", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 19, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_std_exception_ce, "Missing extension: apc", "nc/std/cacheapc.zep", 12);
		return;
	}
	zephir_update_property_this(this_ptr, SL("prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_CacheApc, setCache) {

	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *identifier_param = NULL, *data, *lifetime_param = NULL, *_0, *_1, _2, *_3 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &identifier_param, &data, &lifetime_param);

	zephir_get_strval(identifier, identifier_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, identifier);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, lifetime);
	ZEPHIR_CALL_FUNCTION(&_3, "apc_store", NULL, 118, _1, data, &_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_std_exception_ce, "Cannot store data: apc_store", "nc/std/cacheapc.zep", 21);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_CacheApc, getCache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *data = NULL, *success = NULL, *_0, *_1;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	ZEPHIR_INIT_VAR(success);
	ZVAL_NULL(success);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, identifier);
	ZEPHIR_MAKE_REF(success);
	ZEPHIR_CALL_FUNCTION(&data, "apc_fetch", NULL, 119, _1, success);
	ZEPHIR_UNREF(success);
	zephir_check_call_status();
	if (zephir_is_true(success)) {
		RETURN_CCTOR(data);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_CacheApc, deleteCache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0, *_1, *_2 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, identifier);
	ZEPHIR_CALL_FUNCTION(&_2, "apc_delete", NULL, 120, _1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_std_exception_ce, "Cannot forget data: apc_delete", "nc/std/cacheapc.zep", 38);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

