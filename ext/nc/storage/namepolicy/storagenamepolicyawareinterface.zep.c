
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Storage_NamePolicy_StorageNamePolicyAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Storage\\NamePolicy, StorageNamePolicyAwareInterface, nc, storage_namepolicy_storagenamepolicyawareinterface, nc_storage_namepolicy_storagenamepolicyawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_NamePolicy_StorageNamePolicyAwareInterface, setStorageNamePolicy);

ZEPHIR_DOC_METHOD(Nc_Storage_NamePolicy_StorageNamePolicyAwareInterface, getStorageNamePolicy);

