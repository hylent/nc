
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Log_RedisList) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Log, RedisList, nc, log_redislist, nc_log_writerbufferedabstract_ce, nc_log_redislist_method_entry, 0);

	zend_declare_property_null(nc_log_redislist_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_redislist_ce, SL("keyName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_redislist_ce, SL("ttl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Log_RedisList, __construct) {

	long ttl;
	zval keyName;
	zval *redis, redis_sub, *keyName_param = NULL, *ttl_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&redis_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&keyName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &redis, &keyName_param, &ttl_param);

	zephir_get_strval(&keyName, keyName_param);
	if (!ttl_param) {
		ttl = 3600;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	zephir_update_property_zval(this_ptr, SL("redis"), redis);
	zephir_update_property_zval(this_ptr, SL("keyName"), &keyName);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, ttl);
	zephir_update_property_zval(this_ptr, SL("ttl"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_RedisList, getRedis) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "redis");

}

PHP_METHOD(Nc_Log_RedisList, getKeyName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "keyName");

}

PHP_METHOD(Nc_Log_RedisList, getTtl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "ttl");

}

PHP_METHOD(Nc_Log_RedisList, retrieveLogs) {

	zend_bool _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *maxLogs_param = NULL, *blocking_param = NULL, log, logs, _0$$3, _1$$3, _2$$3, _4$$3, _5$$5, _6$$5;
	long maxLogs, blocking, c;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&log);
	ZVAL_UNDEF(&logs);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &maxLogs_param, &blocking_param);

	if (!maxLogs_param) {
		maxLogs = 1000;
	} else {
		maxLogs = zephir_get_intval(maxLogs_param);
	}
	if (!blocking_param) {
		blocking = 10;
	} else {
		blocking = zephir_get_intval(blocking_param);
	}


	ZEPHIR_INIT_VAR(&logs);
	array_init(&logs);
	c = 0;
	if (blocking > 0) {
		zephir_read_property(&_0$$3, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, blocking);
		ZEPHIR_CALL_METHOD(&log, &_0$$3, "brpop", NULL, 0, &_1$$3, &_2$$3);
		zephir_check_call_status();
		_3$$3 = Z_TYPE_P(&log) != IS_ARRAY;
		if (!(_3$$3)) {
			_3$$3 = zephir_fast_count_int(&log TSRMLS_CC) != 2;
		}
		if (_3$$3) {
			RETURN_CCTOR(&logs);
		}
		zephir_array_fetch_long(&_4$$3, &log, 1, PH_NOISY | PH_READONLY, "nc/log/redislist.zep", 42 TSRMLS_CC);
		zephir_array_append(&logs, &_4$$3, PH_SEPARATE, "nc/log/redislist.zep", 42);
		c++;
	}
	while (1) {
		if (c >= maxLogs) {
			break;
		}
		zephir_read_property(&_5$$5, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$5, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&log, &_5$$5, "rpop", NULL, 0, &_6$$5);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&log)) {
			break;
		}
		zephir_array_append(&logs, &log, PH_SEPARATE, "nc/log/redislist.zep", 56);
		c++;
	}
	RETURN_CCTOR(&logs);

}

PHP_METHOD(Nc_Log_RedisList, writeLogs) {

	long numCmds;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *logs_param = NULL, redis, log, res, _0, _1, *_2, _7, _3$$4, _5$$5, _6$$5;
	zval logs;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logs);
	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&log);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &logs_param);

	zephir_get_arrval(&logs, logs_param);


	numCmds = 0;
	if (zephir_fast_count_int(&logs TSRMLS_CC) < 1) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(&redis, &_0, "multi", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&logs, 0, "nc/log/redislist.zep", 79);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&logs), _2)
	{
		ZEPHIR_INIT_NVAR(&log);
		ZVAL_COPY(&log, _2);
		zephir_read_property(&_3$$4, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &redis, "lpush", &_4, 0, &_3$$4, &log);
		zephir_check_call_status();
		numCmds++;
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&log);
	zephir_read_property(&_1, this_ptr, SL("ttl"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_1, 0)) {
		zephir_read_property(&_5$$5, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$5, this_ptr, SL("ttl"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &redis, "expire", NULL, 0, &_5$$5, &_6$$5);
		zephir_check_call_status();
		numCmds++;
	}
	ZEPHIR_CALL_METHOD(&res, &redis, "exec", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "array_filter", NULL, 98, &res);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_fast_count_int(&_7 TSRMLS_CC) != numCmds)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_log_exception_ce, "Failed to write logs", "nc/log/redislist.zep", 87);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

