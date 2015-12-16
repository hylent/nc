
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


ZEPHIR_INIT_CLASS(Nc_Std_QueueRedis) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, QueueRedis, nc, std_queueredis, nc_std_queueredis_method_entry, 0);

	zend_declare_property_null(nc_std_queueredis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_std_queueredis_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_queueredis_ce, SL("DEFAULT_PREFIX"), "queue:" TSRMLS_CC);

	zend_class_implements(nc_std_queueredis_ce TSRMLS_CC, 1, nc_std_queueinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_QueueRedis, __construct) {

	zval *prefix = NULL;
	zval *redis, *prefix_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "queue:", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_QueueRedis, pushQueue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *data_param = NULL, *_0, *_1 = NULL, *_2, *_3, *_4$$3;
	zval *identifier = NULL, *data = NULL, *_5$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &data_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(data, data_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, identifier);
	ZEPHIR_CALL_METHOD(&_1, _0, "lpush", NULL, 0, _3, data);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, nc_std_exception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, "Cannot lpush data to queue: ", identifier);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 2, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "nc/std/queueredis.zep", 19 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_QueueRedis, popQueue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *data = NULL, *_0, *_1, *_2;
	zval *identifier = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_CALL_METHOD(&data, _0, "rpop", NULL, 0, _2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(data)) {
		RETURN_MM_NULL();
	}
	zephir_get_strval(_3, data);
	RETURN_CTOR(_3);

}

