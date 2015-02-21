
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Backend_StorageBackendAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Storage\\Backend, StorageBackendAwareInterface, nc, storage_backend_storagebackendawareinterface, nc_storage_backend_storagebackendawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_Backend_StorageBackendAwareInterface, setStorageBackend);

ZEPHIR_DOC_METHOD(Nc_Storage_Backend_StorageBackendAwareInterface, getStorageBackend);

