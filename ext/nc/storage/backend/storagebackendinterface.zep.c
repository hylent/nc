
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Backend_StorageBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Storage\\Backend, StorageBackendInterface, nc, storage_backend_storagebackendinterface, nc_storage_backend_storagebackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_Backend_StorageBackendInterface, store);

ZEPHIR_DOC_METHOD(Nc_Storage_Backend_StorageBackendInterface, remove);

