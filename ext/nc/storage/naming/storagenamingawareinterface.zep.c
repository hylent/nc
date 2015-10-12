
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Naming_StorageNamingAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Storage\\Naming, StorageNamingAwareInterface, nc, storage_naming_storagenamingawareinterface, nc_storage_naming_storagenamingawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_Naming_StorageNamingAwareInterface, setStorageNaming);

ZEPHIR_DOC_METHOD(Nc_Storage_Naming_StorageNamingAwareInterface, getStorageNaming);

