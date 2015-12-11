
extern zend_class_entry *nc_task_rundirectly_ce;

ZEPHIR_INIT_CLASS(Nc_Task_RunDirectly);

PHP_METHOD(Nc_Task_RunDirectly, produce);
PHP_METHOD(Nc_Task_RunDirectly, consume);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_rundirectly_produce, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_task_rundirectly_method_entry) {
	PHP_ME(Nc_Task_RunDirectly, produce, arginfo_nc_task_rundirectly_produce, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_RunDirectly, consume, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
