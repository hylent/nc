
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Storage_NamePolicy_StorageNamePolicyInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Storage\\NamePolicy, StorageNamePolicyInterface, nc, storage_namepolicy_storagenamepolicyinterface, nc_storage_namepolicy_storagenamepolicyinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_NamePolicy_StorageNamePolicyInterface, generateName);

