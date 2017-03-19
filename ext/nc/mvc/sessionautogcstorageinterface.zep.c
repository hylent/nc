
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_SessionAutoGcStorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Mvc, SessionAutoGcStorageInterface, nc, mvc_sessionautogcstorageinterface, nc_mvc_sessionautogcstorageinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Mvc_SessionAutoGcStorageInterface, readSessionData);

ZEPHIR_DOC_METHOD(Nc_Mvc_SessionAutoGcStorageInterface, writeSessionData);

ZEPHIR_DOC_METHOD(Nc_Mvc_SessionAutoGcStorageInterface, destroySessionData);

