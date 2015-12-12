
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Router_SourceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Router, SourceInterface, nc, router_sourceinterface, nc_router_sourceinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Router_SourceInterface, getSource);

