
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
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Cache_Memcache) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Cache, Memcache, nc, cache_memcache, nc_cache_cacheabstract_ce, nc_cache_memcache_method_entry, 0);

	zend_declare_property_null(nc_cache_memcache_ce, SL("memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_cache_memcache_ce, SL("INCREMENT_MAX"), 1000000000 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Cache_Memcache, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	long port, timeout;
	zval *host_param = NULL, *port_param = NULL, *timeout_param = NULL, *mc, _0, *_1 = NULL, *_3 = NULL, *_4, *_5;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &host_param, &port_param, &timeout_param);

	zephir_get_strval(host, host_param);
	if (!port_param) {
		port = 11211;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!timeout_param) {
		timeout = 5;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "memcache", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Missing extension: memcache", "nc/cache/memcache.zep", 16);
		return;
	}
	ZEPHIR_INIT_VAR(mc);
	object_init_ex(mc, zephir_get_internal_ce(SS("memcache") TSRMLS_CC));
	if (zephir_has_constructor(mc TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, mc, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, port);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, timeout);
	ZEPHIR_CALL_METHOD(&_3, mc, "connect", NULL, host, _4, _5);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_cache_exception_ce, "Cannot connect to memcache server", "nc/cache/memcache.zep", 21);
		return;
	}
	zephir_update_property_this(this_ptr, SL("memcache"), mc TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Memcache, flush) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "flush", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Memcache, rawSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	long lifetime;
	zval *key_param = NULL, *value, *lifetime_param = NULL, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &lifetime_param);

	zephir_get_strval(key, key_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, lifetime);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, key, value, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Memcache, rawGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *r = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&r, _0, "get", NULL, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(r)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Cache_Memcache, rawDelete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Memcache, setInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long value;
	zval *key_param = NULL, *value_param = NULL, *_1;
	zval *key = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(key, key_param);
	value = zephir_get_intval(value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, ":i:", key);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, (1000000000 + value));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rawset", NULL, _0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Cache_Memcache, getInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value = NULL;
	zval *key = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, ":i:", key);
	ZEPHIR_CALL_METHOD(&value, this_ptr, "rawget", NULL, _0);
	zephir_check_call_status();
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_LONG(0);
	}
	RETURN_MM_LONG(((zephir_get_numberval(value) - 1000000000)));

}

PHP_METHOD(Nc_Cache_Memcache, incrementInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long step;
	zval *key_param = NULL, *step_param = NULL, *value = NULL, *_0, *_2 = NULL;
	zval *key = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &step_param);

	zephir_get_strval(key, key_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":i:", key);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, step);
	ZEPHIR_CALL_METHOD(&value, _0, "increment", NULL, _1, _2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, step);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setinteger", NULL, key, _2);
		zephir_check_call_status();
		RETURN_MM_LONG(step);
	}
	RETURN_MM_LONG(((zephir_get_numberval(value) - 1000000000)));

}

PHP_METHOD(Nc_Cache_Memcache, decrementInteger) {

	int ZEPHIR_LAST_CALL_STATUS;
	long step;
	zval *key_param = NULL, *step_param = NULL, *value = NULL, *_0, *_2 = NULL;
	zval *key = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &step_param);

	zephir_get_strval(key, key_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, ":i:", key);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, step);
	ZEPHIR_CALL_METHOD(&value, _0, "decrement", NULL, _1, _2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, -step);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setinteger", NULL, key, _2);
		zephir_check_call_status();
		RETURN_MM_LONG(-step);
	}
	RETURN_MM_LONG(((zephir_get_numberval(value) - 1000000000)));

}

PHP_METHOD(Nc_Cache_Memcache, multiGet) {

	HashTable *_3;
	HashPosition _2;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *a = NULL, *k = NULL, *v = NULL, *data, *_0, **_4, *_5, *_6 = NULL;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("memcache"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&a, _0, "get", NULL, keys);
	zephir_check_call_status();
	_1 = Z_TYPE_P(a) == IS_ARRAY;
	if (_1) {
		_1 = zephir_is_true(a);
	}
	if (_1) {
		zephir_is_iterable(a, &_3, &_2, 0, 0, "nc/cache/memcache.zep", 106);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(k, _3, _2);
			ZEPHIR_GET_HVALUE(v, _4);
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_6, _5, "unserialize", NULL, v);
			zephir_check_call_status();
			zephir_array_update_zval(&data, k, &_6, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

