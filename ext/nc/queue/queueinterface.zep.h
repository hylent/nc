
extern zend_class_entry *nc_queue_queueinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Queue_QueueInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_queueinterface_put, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, delay)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_queueinterface_reserve, 0, 0, 1)
	ZEND_ARG_INFO(0, ttr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_queueinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_queue_queueinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Queue_QueueInterface, put, arginfo_nc_queue_queueinterface_put)
	PHP_ABSTRACT_ME(Nc_Queue_QueueInterface, reserve, arginfo_nc_queue_queueinterface_reserve)
	PHP_ABSTRACT_ME(Nc_Queue_QueueInterface, delete, arginfo_nc_queue_queueinterface_delete)
	PHP_FE_END
};
