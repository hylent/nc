
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Di_InjectedCtorParamsInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Di, InjectedCtorParamsInterface, nc, di_injectedctorparamsinterface, NULL);

	return SUCCESS;

}

