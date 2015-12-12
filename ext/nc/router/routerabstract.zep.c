
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Router_RouterAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Router, RouterAbstract, nc, router_routerabstract, nc_router_routerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_router_routerabstract_ce, SL("source"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_router_routerabstract_ce, SL("id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_router_routerabstract_ce TSRMLS_CC, 1, nc_router_sourceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Router_RouterAbstract, setSource) {

	zval *source;

	zephir_fetch_params(0, 1, 0, &source);



	zephir_update_property_this(this_ptr, SL("source"), source TSRMLS_CC);

}

PHP_METHOD(Nc_Router_RouterAbstract, getSource) {

	zval *_3 = NULL;
	zend_bool _1;
	zval *source = NULL, *_0, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("source"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(source, _0);
	if (Z_TYPE_P(source) == IS_ARRAY) {
		RETURN_CCTOR(source);
	}
	_1 = Z_TYPE_P(source) != IS_OBJECT;
	if (!(_1)) {
		_1 = !((zephir_instance_of_ev(source, nc_router_sourceinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_router_exception_ce, "Invalid source", "nc/router/routerabstract.zep", 24);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, source, "getsource", NULL, 0);
	zephir_check_call_status();
	zephir_get_arrval(_3, _2);
	ZEPHIR_CPY_WRT(source, _3);
	zephir_update_property_this(this_ptr, SL("source"), source TSRMLS_CC);
	RETURN_CCTOR(source);

}

PHP_METHOD(Nc_Router_RouterAbstract, route) {

}

PHP_METHOD(Nc_Router_RouterAbstract, getId) {

	zval *_2 = NULL;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("id"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(_0) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_router_exception_ce, "Id not ready", "nc/router/routerabstract.zep", 38);
		return;
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("id"), PH_NOISY_CC);
	zephir_get_strval(_2, _1);
	RETURN_CTOR(_2);

}

