
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Loader_LoaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Loader, LoaderInterface, nc, loader_loaderinterface, nc_loader_loaderinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Loader_LoaderInterface, register);

ZEPHIR_DOC_METHOD(Nc_Loader_LoaderInterface, unregister);

ZEPHIR_DOC_METHOD(Nc_Loader_LoaderInterface, __invoke);

ZEPHIR_DOC_METHOD(Nc_Loader_LoaderInterface, findPath);

ZEPHIR_DOC_METHOD(Nc_Loader_LoaderInterface, getLoadedNamePaths);

