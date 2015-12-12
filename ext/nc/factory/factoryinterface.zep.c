
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Factory_FactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Factory, FactoryInterface, nc, factory_factoryinterface, nc_factory_factoryinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Factory_FactoryInterface, __isset);

ZEPHIR_DOC_METHOD(Nc_Factory_FactoryInterface, __get);

ZEPHIR_DOC_METHOD(Nc_Factory_FactoryInterface, newProduction);

