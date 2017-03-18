
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Config_ConfigInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Config, ConfigInterface, nc, config_configinterface, nc_config_configinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Config_ConfigInterface, get);

