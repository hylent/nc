
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Queue_QueueInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Queue, QueueInterface, nc, queue_queueinterface, nc_queue_queueinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Queue_QueueInterface, put);

ZEPHIR_DOC_METHOD(Nc_Queue_QueueInterface, reserve);

ZEPHIR_DOC_METHOD(Nc_Queue_QueueInterface, delete);

