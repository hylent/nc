
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Di_ContainerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Di, ContainerInterface, nc, di_containerinterface, nc_di_containerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Di_ContainerInterface, __isset);

ZEPHIR_DOC_METHOD(Nc_Di_ContainerInterface, __get);

