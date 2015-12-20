
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Factory_FactoryAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Factory, FactoryAbstract, nc, factory_factoryabstract, nc_factory_factoryabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_factory_factoryabstract_ce, SL("productions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_factory_factoryabstract_ce TSRMLS_CC, 1, nc_factory_factoryinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Factory_FactoryAbstract, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *production = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(production);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("productions"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&production, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(production);
	}
	ZEPHIR_CALL_METHOD(&production, this_ptr, "newproduction", NULL, 0, name);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("productions"), name, production TSRMLS_CC);
	RETURN_CCTOR(production);

}

