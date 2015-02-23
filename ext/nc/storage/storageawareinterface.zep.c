
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Storage_StorageAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Storage, StorageAwareInterface, nc, storage_storageawareinterface, nc_storage_storageawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_StorageAwareInterface, setStorage);

ZEPHIR_DOC_METHOD(Nc_Storage_StorageAwareInterface, getStorage);

