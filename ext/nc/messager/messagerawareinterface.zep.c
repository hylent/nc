
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Messager_MessagerAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Messager, MessagerAwareInterface, nc, messager_messagerawareinterface, nc_messager_messagerawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Messager_MessagerAwareInterface, setMessager);

ZEPHIR_DOC_METHOD(Nc_Messager_MessagerAwareInterface, getMessager);

