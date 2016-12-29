
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

	zephir_declare_class_constant_long(nc_storage_storageinterface_ce, SL("COPY"), 1);

	zephir_declare_class_constant_long(nc_storage_storageinterface_ce, SL("MOVE"), 2);

	zephir_declare_class_constant_long(nc_storage_storageinterface_ce, SL("MOVE_UPLOADED_FILE"), 3);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_StorageInterface, store);

ZEPHIR_DOC_METHOD(Nc_Storage_StorageInterface, remove);

ZEPHIR_DOC_METHOD(Nc_Storage_StorageInterface, exists);

