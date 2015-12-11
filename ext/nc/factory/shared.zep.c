
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Factory_Shared) {

	ZEPHIR_REGISTER_CLASS(Nc\\Factory, Shared, nc, factory_shared, nc_factory_shared_method_entry, 0);

	zend_declare_property_null(nc_factory_shared_ce, SL("factory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_factory_shared_ce, SL("productions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_factory_shared_ce TSRMLS_CC, 1, nc_factory_factoryinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Factory_Shared, __construct) {

	zval *factory;

	zephir_fetch_params(0, 1, 0, &factory);



	zephir_update_property_this(this_ptr, SL("factory"), factory TSRMLS_CC);

}

PHP_METHOD(Nc_Factory_Shared, getFactory) {

	

	RETURN_MEMBER(this_ptr, "factory");

}

PHP_METHOD(Nc_Factory_Shared, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("productions"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		RETURN_MM_BOOL(1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("factory"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "__isset", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Factory_Shared, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *production = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(production);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("productions"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&production, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(production);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("factory"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&production, _1, "__get", NULL, 0, name);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("productions"), name, production TSRMLS_CC);
	RETURN_CCTOR(production);

}

