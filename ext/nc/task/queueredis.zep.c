
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
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Task_QueueRedis) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Task, QueueRedis, nc, task_queueredis, nc_task_taskmanagerabstract_ce, nc_task_queueredis_method_entry, 0);

	zend_declare_property_null(nc_task_queueredis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_task_queueredis_ce, SL("queueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Task_QueueRedis, __construct) {

	zval *queueKey = NULL;
	zval *redis, *queueKey_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &redis, &queueKey_param);

	zephir_get_strval(queueKey, queueKey_param);


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("queueKey"), queueKey TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Task_QueueRedis, produce) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *task_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL;
	zval *task = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &task_param);

	zephir_get_arrval(task, task_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("queueKey"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "serializetask", NULL, 0, task);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, _0, "lpush", NULL, 0, _2, _3);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_task_exception_ce, "Fail when redis lpush", "nc/task/queueredis.zep", 17);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Task_QueueRedis, consume) {

	zval *task = NULL, *_0, *_1, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("queueKey"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&task, _0, "rpop", NULL, 0, _1);
	zephir_check_call_status();
	if (!(zephir_is_true(task))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "unserializetask", NULL, 0, task);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(task, _2);
	if (unlikely(Z_TYPE_P(task) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_task_exception_ce, "Invalid task from redis", "nc/task/queueredis.zep", 32);
		return;
	}
	RETURN_CCTOR(task);

}

