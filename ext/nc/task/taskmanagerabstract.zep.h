
extern zend_class_entry *nc_task_taskmanagerabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Task_TaskManagerAbstract);

PHP_METHOD(Nc_Task_TaskManagerAbstract, produce);
PHP_METHOD(Nc_Task_TaskManagerAbstract, consume);
PHP_METHOD(Nc_Task_TaskManagerAbstract, setTaskExecutor);
PHP_METHOD(Nc_Task_TaskManagerAbstract, getTaskExecutor);
PHP_METHOD(Nc_Task_TaskManagerAbstract, setIdles);
PHP_METHOD(Nc_Task_TaskManagerAbstract, getIdles);
PHP_METHOD(Nc_Task_TaskManagerAbstract, setSleep);
PHP_METHOD(Nc_Task_TaskManagerAbstract, getSleep);
PHP_METHOD(Nc_Task_TaskManagerAbstract, run);
PHP_METHOD(Nc_Task_TaskManagerAbstract, runTask);
PHP_METHOD(Nc_Task_TaskManagerAbstract, serializeTask);
PHP_METHOD(Nc_Task_TaskManagerAbstract, unserializeTask);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_taskmanagerabstract_produce, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_taskmanagerabstract_settaskexecutor, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, taskExecutor, Nc\\Task\\TaskExecutorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_taskmanagerabstract_setidles, 0, 0, 1)
	ZEND_ARG_INFO(0, idles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_taskmanagerabstract_setsleep, 0, 0, 1)
	ZEND_ARG_INFO(0, sleep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_taskmanagerabstract_runtask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_taskmanagerabstract_serializetask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_taskmanagerabstract_unserializetask, 0, 0, 1)
	ZEND_ARG_INFO(0, task)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_task_taskmanagerabstract_method_entry) {
	PHP_ME(Nc_Task_TaskManagerAbstract, produce, arginfo_nc_task_taskmanagerabstract_produce, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, consume, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, setTaskExecutor, arginfo_nc_task_taskmanagerabstract_settaskexecutor, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, getTaskExecutor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, setIdles, arginfo_nc_task_taskmanagerabstract_setidles, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, getIdles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, setSleep, arginfo_nc_task_taskmanagerabstract_setsleep, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, getSleep, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, runTask, arginfo_nc_task_taskmanagerabstract_runtask, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, serializeTask, arginfo_nc_task_taskmanagerabstract_serializetask, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_TaskManagerAbstract, unserializeTask, arginfo_nc_task_taskmanagerabstract_unserializetask, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
