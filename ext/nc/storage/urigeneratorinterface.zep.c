
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Storage_UriGeneratorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Storage, UriGeneratorInterface, nc, storage_urigeneratorinterface, nc_storage_urigeneratorinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Storage_UriGeneratorInterface, generateUri);

