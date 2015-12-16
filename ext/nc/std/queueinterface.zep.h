
extern zend_class_entry *nc_std_queueinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Std_QueueInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_queueinterface_pushqueue, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_queueinterface_popqueue, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_queueinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Std_QueueInterface, pushQueue, arginfo_nc_std_queueinterface_pushqueue)
	PHP_ABSTRACT_ME(Nc_Std_QueueInterface, popQueue, arginfo_nc_std_queueinterface_popqueue)
	PHP_FE_END
};
