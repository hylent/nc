
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Cache_CacheBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Cache, CacheBackendInterface, nc, cache_cachebackendinterface, nc_cache_cachebackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Cache_CacheBackendInterface, getPool);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheBackendInterface, clear);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheBackendInterface, store);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheBackendInterface, storeMany);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheBackendInterface, fetch);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheBackendInterface, fetchMany);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheBackendInterface, forget);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheBackendInterface, forgetMany);

