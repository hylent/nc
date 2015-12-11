
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_View_ViewInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\View, ViewInterface, nc, view_viewinterface, nc_view_viewinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_View_ViewInterface, run);

