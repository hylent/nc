
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
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Sequence_RedisHash) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Sequence, RedisHash, nc, sequence_redishash, nc_sequence_sequencebackendabstract_ce, nc_sequence_redishash_method_entry, 0);

	zend_declare_property_null(nc_sequence_redishash_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_sequence_redishash_ce, SL("hashName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_sequence_redishash_ce, SL("DEFAULT_HASH_NAME"), "sequencehash");

	return SUCCESS;

}

PHP_METHOD(Nc_Sequence_RedisHash, __construct) {

	zval hashName;
	zval *redis, redis_sub, *hashName_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&redis_sub);
	ZVAL_UNDEF(&hashName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &hashName_param);

	if (!hashName_param) {
		ZEPHIR_INIT_VAR(&hashName);
		ZVAL_STRING(&hashName, "sequencehash");
	} else {
		zephir_get_strval(&hashName, hashName_param);
	}


	zephir_update_property_zval(this_ptr, SL("redis"), redis);
	zephir_update_property_zval(this_ptr, SL("hashName"), &hashName);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_RedisHash, getRedis) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "redis");

}

PHP_METHOD(Nc_Sequence_RedisHash, getHashName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "hashName");

}

PHP_METHOD(Nc_Sequence_RedisHash, next) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, s, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("hashName"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_METHOD(&s, &_0, "hincrby", NULL, 0, &_1, &name, &_2);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&s))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, nc_sequence_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Cannot get next sequence of '%s'");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", NULL, 2, &_4$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "nc/sequence/redishash.zep", 32 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(zephir_get_intval(&s));

}

PHP_METHOD(Nc_Sequence_RedisHash, restore) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	long sequence;
	zval *name_param = NULL, *sequence_param = NULL, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &sequence_param);

	zephir_get_strval(&name, name_param);
	sequence = zephir_get_intval(sequence_param);


	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("hashName"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, sequence);
	ZEPHIR_CALL_METHOD(NULL, &_0, "hset", NULL, 0, &_1, &name, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_RedisHash, clear) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("hashName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "del", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

