
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Std_CacheInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Std, CacheInterface, nc, std_cacheinterface, nc_std_cacheinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Std_CacheInterface, setCache);

ZEPHIR_DOC_METHOD(Nc_Std_CacheInterface, getCache);

ZEPHIR_DOC_METHOD(Nc_Std_CacheInterface, deleteCache);

