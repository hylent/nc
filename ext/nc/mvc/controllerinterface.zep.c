
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_ControllerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Mvc, ControllerInterface, nc, mvc_controllerinterface, nc_mvc_controllerinterface_method_entry);

	zephir_declare_class_constant_string(nc_mvc_controllerinterface_ce, SL("TYPE"), "Nc\\Mvc\\ControllerInterface");

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Mvc_ControllerInterface, __invoke);

