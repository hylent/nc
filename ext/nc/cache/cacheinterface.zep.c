
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Cache_CacheInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Cache, CacheInterface, nc, cache_cacheinterface, nc_cache_cacheinterface_method_entry);

	zend_declare_class_constant_string(nc_cache_cacheinterface_ce, SL("NONE"), "" TSRMLS_CC);

	zend_declare_class_constant_string(nc_cache_cacheinterface_ce, SL("INTEGER_PREFIX"), ":i:" TSRMLS_CC);

	zend_declare_class_constant_string(nc_cache_cacheinterface_ce, SL("GROUP_PREFIX"), ":g:" TSRMLS_CC);

	zend_declare_class_constant_string(nc_cache_cacheinterface_ce, SL("GROUP_SEPARATOR"), ":" TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, flush);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, rawSet);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, rawGet);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, rawDelete);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, setInteger);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, getInteger);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, deleteInteger);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, incrementInteger);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, decrementInteger);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, set);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, get);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, delete);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, multiSet);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, multiGet);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, multiDelete);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, groupSetAll);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, groupGetAll);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, groupDeleteAll);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, groupSet);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, groupGet);

ZEPHIR_DOC_METHOD(Nc_Cache_CacheInterface, groupDelete);

