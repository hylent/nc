
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
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Factory_ClassNameClosure) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Factory, ClassNameClosure, nc, factory_classnameclosure, nc_factory_classnameabstract_ce, nc_factory_classnameclosure_method_entry, 0);

	zend_declare_property_null(nc_factory_classnameclosure_ce, SL("classNameClosure"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Factory_ClassNameClosure, __construct) {

	zval *classNameClosure;

	zephir_fetch_params(0, 1, 0, &classNameClosure);



	zephir_update_property_this(this_ptr, SL("classNameClosure"), classNameClosure TSRMLS_CC);

}

PHP_METHOD(Nc_Factory_ClassNameClosure, getClassName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("classNameClosure"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 15, _0, name);
	zephir_check_call_status();
	RETURN_MM();

}

