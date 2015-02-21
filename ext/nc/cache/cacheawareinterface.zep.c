
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Cache_CacheAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Cache, CacheAwareInterface, nc, cache_cacheawareinterface, nc_cache_cacheawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Cache_CacheAwareInterface, setCache);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheAwareInterface, getCache);

