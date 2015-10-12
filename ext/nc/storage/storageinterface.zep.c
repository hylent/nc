
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Storage_StorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Storage, StorageInterface, nc, storage_storageinterface, nc_storage_storageinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_StorageInterface, store);

ZEPHIR_DOC_METHOD(Nc_Storage_StorageInterface, remove);

