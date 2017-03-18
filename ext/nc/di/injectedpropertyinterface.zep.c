
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Di_InjectedPropertyInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Di, InjectedPropertyInterface, nc, di_injectedpropertyinterface, NULL);

	return SUCCESS;

}

