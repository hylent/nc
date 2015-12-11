
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Factory_Namespaced) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Factory, Namespaced, nc, factory_namespaced, nc_factory_classnameabstract_ce, nc_factory_namespaced_method_entry, 0);

	zend_declare_property_null(nc_factory_namespaced_ce, SL("ns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Factory_Namespaced, __construct) {

	zval *ns_param = NULL;
	zval *ns = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ns_param);

	zephir_get_strval(ns, ns_param);


	zephir_update_property_this(this_ptr, SL("ns"), ns TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Namespaced, getClassName) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ns"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_ucfirst(_1, name);
	ZEPHIR_CONCAT_VSV(return_value, _0, "\\", _1);
	RETURN_MM();

}

