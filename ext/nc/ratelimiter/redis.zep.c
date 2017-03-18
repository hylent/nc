
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_RateLimiter_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\RateLimiter, Redis, nc, ratelimiter_redis, nc_ratelimiter_ratelimiterbackendabstract_ce, nc_ratelimiter_redis_method_entry, 0);

	zend_declare_property_null(nc_ratelimiter_redis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_ratelimiter_redis_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_ratelimiter_redis_ce, SL("DEFAULT_PREFIX"), "ratelimiter:");

	return SUCCESS;

}

PHP_METHOD(Nc_RateLimiter_Redis, __construct) {

	zval prefix;
	zval *redis, redis_sub, *prefix_param = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&redis_sub);
	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "ratelimiter:");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	zephir_update_property_zval(this_ptr, SL("redis"), redis);
	zephir_update_property_zval(this_ptr, SL("prefix"), &prefix);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_RateLimiter_Redis, getRedis) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "redis");

}

PHP_METHOD(Nc_RateLimiter_Redis, getPrefix) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "prefix");

}

PHP_METHOD(Nc_RateLimiter_Redis, passRateLimits) {

	zend_bool _6$$4;
	zend_string *_3;
	zend_ulong _2;
	long index = 0;
	int ZEPHIR_LAST_CALL_STATUS, _4$$4, _5$$4;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL;
	zval rateLimits;
	zval *name_param = NULL, *rateLimits_param = NULL, pre, now, seconds, times, keys, argv, _0, *_1, _16, _17, _18, _19, _20, _12$$4, _13$$4, _14$$4, _15$$4, _7$$5, _8$$5, _9$$5;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&pre);
	ZVAL_UNDEF(&now);
	ZVAL_UNDEF(&seconds);
	ZVAL_UNDEF(&times);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&rateLimits);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &rateLimits_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&rateLimits, rateLimits_param);


	ZEPHIR_INIT_VAR(&keys);
	array_init(&keys);
	ZEPHIR_INIT_VAR(&argv);
	array_init(&argv);
	if (zephir_fast_count_int(&rateLimits TSRMLS_CC) < 1) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_0, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pre);
	ZEPHIR_CONCAT_VV(&pre, &_0, &name);
	ZEPHIR_INIT_VAR(&now);
	zephir_time(&now);
	zephir_is_iterable(&rateLimits, 0, "nc/ratelimiter/redis.zep", 51);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&rateLimits), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&seconds);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&seconds, _3);
		} else {
			ZVAL_LONG(&seconds, _2);
		}
		ZEPHIR_INIT_NVAR(&times);
		ZVAL_COPY(&times, _1);
		_4$$4 = zephir_get_intval(&seconds);
		ZEPHIR_INIT_NVAR(&seconds);
		ZVAL_LONG(&seconds, _4$$4);
		_5$$4 = zephir_get_intval(&times);
		ZEPHIR_INIT_NVAR(&times);
		ZVAL_LONG(&times, _5$$4);
		_6$$4 = ZEPHIR_LT_LONG(&seconds, 1);
		if (!(_6$$4)) {
			_6$$4 = ZEPHIR_LT_LONG(&times, 1);
		}
		if (unlikely(_6$$4)) {
			ZEPHIR_INIT_NVAR(&_7$$5);
			object_init_ex(&_7$$5, nc_ratelimiter_exception_ce);
			ZEPHIR_INIT_NVAR(&_8$$5);
			ZVAL_STRING(&_8$$5, "Invalid input seconds/times '%d/%d'");
			ZEPHIR_CALL_FUNCTION(&_9$$5, "sprintf", &_10, 2, &_8$$5, &seconds, &times);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", &_11, 3, &_9$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$5, "nc/ratelimiter/redis.zep", 41 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_LNVAR(_12$$4);
		div_function(&_12$$4, &now, &seconds TSRMLS_CC);
		index = zephir_get_intval(&_12$$4);
		ZEPHIR_INIT_NVAR(&_13$$4);
		ZVAL_STRING(&_13$$4, "%s:%d:%d");
		ZVAL_LONG(&_14$$4, index);
		ZEPHIR_CALL_FUNCTION(&_15$$4, "sprintf", &_10, 2, &_13$$4, &pre, &seconds, &_14$$4);
		zephir_check_call_status();
		zephir_array_append(&keys, &_15$$4, PH_SEPARATE, "nc/ratelimiter/redis.zep", 46);
		zephir_array_append(&argv, &times, PH_SEPARATE, "nc/ratelimiter/redis.zep", 47);
		ZEPHIR_INIT_NVAR(&_13$$4);
		ZVAL_LONG(&_13$$4, ((zephir_get_numberval(&seconds) * ((index + 1))) - zephir_get_numberval(&now)));
		zephir_array_append(&argv, &_13$$4, PH_SEPARATE, "nc/ratelimiter/redis.zep", 48);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&times);
	ZEPHIR_INIT_NVAR(&seconds);
	zephir_read_property(&_16, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_18);
	zephir_fast_array_merge(&_18, &keys, &argv TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_19);
	ZVAL_STRING(&_19, "local iv = {}; local v; for i, k in pairs(KEYS) do v = redis.pcall('get', k); if not v then v = 0; end if v - ARGV[i * 2 - 1] >= 0 then return 0; end iv[i] = v end for i, k in pairs(KEYS) do redis.pcall('setex', k, 1 + ARGV[i * 2], iv[i] + 1); end return 1;");
	ZVAL_LONG(&_20, zephir_fast_count_int(&keys TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_17, &_16, "eval", NULL, 0, &_19, &_18, &_20);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_17));

}

