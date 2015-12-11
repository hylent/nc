
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Task_RunDirectly) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Task, RunDirectly, nc, task_rundirectly, nc_task_taskmanagerabstract_ce, nc_task_rundirectly_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Task_RunDirectly, produce) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *task_param = NULL;
	zval *task = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &task_param);

	zephir_get_arrval(task, task_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "runtask", NULL, 0, task);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Task_RunDirectly, consume) {

	

	RETURN_NULL();

}

