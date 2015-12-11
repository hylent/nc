
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Task_TaskExecutorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Task, TaskExecutorInterface, nc, task_taskexecutorinterface, nc_task_taskexecutorinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Task_TaskExecutorInterface, executeTask);

ZEPHIR_DOC_METHOD(Nc_Task_TaskExecutorInterface, onTaskReturn);

ZEPHIR_DOC_METHOD(Nc_Task_TaskExecutorInterface, onTaskException);

