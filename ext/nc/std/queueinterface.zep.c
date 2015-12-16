
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Std_QueueInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Std, QueueInterface, nc, std_queueinterface, nc_std_queueinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Std_QueueInterface, pushQueue);

ZEPHIR_DOC_METHOD(Nc_Std_QueueInterface, popQueue);

