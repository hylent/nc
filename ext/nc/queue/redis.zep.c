
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Queue_Redis) {

	ZEPHIR_REGISTER_CLASS(Nc\\Queue, Redis, nc, queue_redis, nc_queue_redis_method_entry, 0);

	zend_declare_property_null(nc_queue_redis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_queue_redis_ce, SL("keyName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_queue_redis_ce TSRMLS_CC, 1, nc_queue_queueinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Queue_Redis, __construct) {

	zval keyName;
	zval *redis, redis_sub, *keyName_param = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&redis_sub);
	ZVAL_UNDEF(&keyName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &redis, &keyName_param);

	zephir_get_strval(&keyName, keyName_param);


	zephir_update_property_zval(this_ptr, SL("redis"), redis);
	zephir_update_property_zval(this_ptr, SL("keyName"), &keyName);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Queue_Redis, getRedis) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "redis");

}

PHP_METHOD(Nc_Queue_Redis, getKeyName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "keyName");

}

PHP_METHOD(Nc_Queue_Redis, put) {

	int ZEPHIR_LAST_CALL_STATUS;
	long delay;
	zval *id_param = NULL, *delay_param = NULL, r, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zval id;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &id_param, &delay_param);

	zephir_get_strval(&id, id_param);
	if (!delay_param) {
		delay = 0;
	} else {
		delay = zephir_get_intval(delay_param);
	}


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	ZVAL_LONG(&_3, (zephir_get_numberval(&_2) + delay));
	ZEPHIR_CALL_METHOD(&r, &_0, "zadd", NULL, 0, &_1, &_3, &id);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&r))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, nc_queue_exception_ce);
		zephir_read_property(&_5$$3, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 7, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "nc/queue/redis.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Queue_Redis, reserve) {

	zval _9, _13;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ttr_param = NULL, args, r, _3, _4, _5, _6, _7, _8, _0$$3, _1$$3, _2$$3, _10$$4, _11$$4, _12$$4;
	long ttr;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ttr_param);

	ttr = zephir_get_intval(ttr_param);


	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	if (unlikely(ttr < 1)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, nc_queue_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "reserve");
		ZVAL_LONG(&_2$$3, 3);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 7, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "nc/queue/redis.zep", 39 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
	zephir_array_append(&args, &_3, PH_SEPARATE, "nc/queue/redis.zep", 42);
	ZEPHIR_INIT_VAR(&_4);
	zephir_time(&_4);
	zephir_array_append(&args, &_4, PH_SEPARATE, "nc/queue/redis.zep", 43);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_LONG(&_5, ttr);
	zephir_array_append(&args, &_5, PH_SEPARATE, "nc/queue/redis.zep", 44);
	zephir_read_property(&_6, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "local t = redis.pcall('zrangebyscore', KEYS[1], 1, ARGV[1], 'limit', 0, 1); if type(t) == 'table' and t[1] then redis.pcall('zadd', KEYS[1], ARGV[1] + ARGV[2], t[1]); return t[1]; end");
	ZVAL_LONG(&_8, 1);
	ZEPHIR_CALL_METHOD(&_7, &_6, "eval", NULL, 0, &_5, &args, &_8);
	zephir_check_call_status();
	zephir_get_strval(&_9, &_7);
	ZEPHIR_CPY_WRT(&r, &_9);
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&r))) {
		ZEPHIR_INIT_VAR(&_10$$4);
		object_init_ex(&_10$$4, nc_queue_exception_ce);
		zephir_read_property(&_11$$4, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_12$$4, 2);
		ZEPHIR_CALL_METHOD(NULL, &_10$$4, "__construct", NULL, 7, &_11$$4, &_12$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$4, "nc/queue/redis.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&_13, &r);
	RETURN_CTOR(_13);

}

PHP_METHOD(Nc_Queue_Redis, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, r, _0, _1, _2$$3, _3$$3, _4$$3;
	zval id;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&r, &_0, "zrem", NULL, 0, &_1, &id);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&r))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, nc_queue_exception_ce);
		zephir_read_property(&_3$$3, this_ptr, SL("keyName"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_4$$3, 4);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 7, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "nc/queue/redis.zep", 65 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

