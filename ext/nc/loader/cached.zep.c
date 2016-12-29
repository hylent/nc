
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Loader_Cached) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, Cached, nc, loader_cached, nc_loader_loaderabstract_ce, nc_loader_cached_method_entry, 0);

	zend_declare_property_null(nc_loader_cached_ce, SL("loader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_loader_cached_ce, SL("cachePool"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_loader_cached_ce, SL("cacheTtl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(nc_loader_cached_ce, SL("DEFAULT_TTL"), 900);

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_Cached, __construct) {

	long ttl;
	zval *loader, loader_sub, *pool, pool_sub, *ttl_param = NULL, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&loader_sub);
	ZVAL_UNDEF(&pool_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 2, 1, &loader, &pool, &ttl_param);

	if (!ttl_param) {
		ttl = 900;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	zephir_update_property_zval(this_ptr, SL("loader"), loader);
	zephir_update_property_zval(this_ptr, SL("cachePool"), pool);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, ttl);
	zephir_update_property_zval(this_ptr, SL("cacheTtl"), &_0);

}

PHP_METHOD(Nc_Loader_Cached, setLoader) {

	zval *loader, loader_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&loader_sub);

	zephir_fetch_params(0, 1, 0, &loader);



	zephir_update_property_zval(this_ptr, SL("loader"), loader);

}

PHP_METHOD(Nc_Loader_Cached, getLoader) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "loader");

}

PHP_METHOD(Nc_Loader_Cached, setCachePool) {

	zval *cachePool, cachePool_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&cachePool_sub);

	zephir_fetch_params(0, 1, 0, &cachePool);



	zephir_update_property_zval(this_ptr, SL("cachePool"), cachePool);

}

PHP_METHOD(Nc_Loader_Cached, getCachePool) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "cachePool");

}

PHP_METHOD(Nc_Loader_Cached, setCacheTtl) {

	zval *cacheTtl_param = NULL, _0;
	long cacheTtl;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &cacheTtl_param);

	cacheTtl = zephir_get_intval(cacheTtl_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, cacheTtl);
	zephir_update_property_zval(this_ptr, SL("cacheTtl"), &_0);

}

PHP_METHOD(Nc_Loader_Cached, getCacheTtl) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "cacheTtl");

}

PHP_METHOD(Nc_Loader_Cached, clearCache) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("cachePool"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_Cached, findPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, path, _0, _1$$3, _2$$3, _3$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("cachePool"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&path, &_0, "fetch", NULL, 0, &name);
	zephir_check_call_status();
	if (Z_TYPE_P(&path) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, SL("loader"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&path, &_1$$3, "findpath", NULL, 0, &name);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("cachePool"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, this_ptr, SL("cacheTtl"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "store", NULL, 0, &name, &path, &_3$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(path);

}

