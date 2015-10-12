
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Messager_MessagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Messager, MessagerInterface, nc, messager_messagerinterface, nc_messager_messagerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Messager_MessagerInterface, send);

