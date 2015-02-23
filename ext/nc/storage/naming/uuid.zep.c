
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Naming_Uuid) {

	ZEPHIR_REGISTER_CLASS(Nc\\Storage\\Naming, Uuid, nc, storage_naming_uuid, nc_storage_naming_uuid_method_entry, 0);

	zend_class_implements(nc_storage_naming_uuid_ce TSRMLS_CC, 1, nc_storage_naming_storagenaminginterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Storage_Naming_Uuid, generateName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_CE_STATIC(nc_std_ce, "uuid", &_0);
	zephir_check_call_status();
	RETURN_MM();

}

