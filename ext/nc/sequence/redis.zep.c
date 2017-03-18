
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
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Sequence_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Sequence, Redis, nc, sequence_redis, nc_sequence_sequencebackendabstract_ce, nc_sequence_redis_method_entry, 0);

	zend_declare_property_null(nc_sequence_redis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_sequence_redis_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_sequence_redis_ce, SL("DEFAULT_PREFIX"), "sequence:");

	return SUCCESS;

}

PHP_METHOD(Nc_Sequence_Redis, __construct) {

	zval prefix;
	zval *redis, redis_sub, *prefix_param = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&redis_sub);
	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "sequence:");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	zephir_update_property_zval(this_ptr, SL("redis"), redis);
	zephir_update_property_zval(this_ptr, SL("prefix"), &prefix);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_Redis, getRedis) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "redis");

}

PHP_METHOD(Nc_Sequence_Redis, getPrefix) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "prefix");

}

PHP_METHOD(Nc_Sequence_Redis, next) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, s, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &name);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_METHOD(&s, &_0, "incr", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&s))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, nc_sequence_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Cannot get next sequence of '%s'");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", NULL, 2, &_5$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "nc/sequence/redis.zep", 32 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(zephir_get_intval(&s));

}

PHP_METHOD(Nc_Sequence_Redis, restore) {

	int ZEPHIR_LAST_CALL_STATUS;
	long sequence;
	zval *name_param = NULL, *sequence_param = NULL, _0, _1, _2, _3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &sequence_param);

	zephir_get_strval(&name, name_param);
	sequence = zephir_get_intval(sequence_param);


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &name);
	ZVAL_LONG(&_3, sequence);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_Redis, clear) {

	zval redis, pat, iter, ks, k, _0, _1, _2, _3$$3, *_6$$3;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&redis);
	ZVAL_UNDEF(&pat);
	ZVAL_UNDEF(&iter);
	ZVAL_UNDEF(&ks);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&iter);
	ZVAL_NULL(&iter);
	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&redis, &_0);
	zephir_read_property(&_0, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pat);
	ZEPHIR_CONCAT_VS(&pat, &_0, "*");
	ZVAL_LONG(&_1, 4);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_METHOD(NULL, &redis, "setoption", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	while (1) {
		ZVAL_LONG(&_3$$3, 1000);
		ZEPHIR_CALL_METHOD(&ks, &redis, "scan", &_4, 0, &iter, &pat, &_3$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&ks))) {
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, &redis, "multi", &_5, 0);
		zephir_check_call_status();
		zephir_is_iterable(&ks, 0, "nc/sequence/redis.zep", 62);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&ks), _6$$3)
		{
			ZEPHIR_INIT_NVAR(&k);
			ZVAL_COPY(&k, _6$$3);
			ZEPHIR_CALL_METHOD(NULL, &redis, "del", &_7, 0, &k);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&k);
		ZEPHIR_CALL_METHOD(NULL, &redis, "exec", &_8, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

