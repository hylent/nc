
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Di_InjectedSetupMethodInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Di, InjectedSetupMethodInterface, nc, di_injectedsetupmethodinterface, nc_di_injectedsetupmethodinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Di_InjectedSetupMethodInterface, setupByInjector);

