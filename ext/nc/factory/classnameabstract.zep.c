
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Factory_ClassNameAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Factory, ClassNameAbstract, nc, factory_classnameabstract, nc_factory_classnameabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_factory_classnameabstract_ce, SL("args"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_factory_classnameabstract_ce TSRMLS_CC, 1, nc_factory_factoryinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclassname", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_class_exists(_0, 1 TSRMLS_CC));

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, __get) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL, *_5, *_2$$3;
	zval *name = NULL, *className = NULL, *_1 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclassname", NULL, 0, name);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(className, _1);
	if (unlikely(!(zephir_class_exists(className, 1 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, nc_factory_exception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid product: ", name);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "nc/factory/classnameabstract.zep", 20 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("args"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(nc_std_ce, "newinstanceof", &_4, 23, className, _5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, setArgs) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "func_get_args", NULL, 14);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("args"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, setArgArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args_param = NULL, *_0 = NULL;
	zval *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args_param);

	zephir_get_arrval(args, args_param);


	ZEPHIR_CALL_FUNCTION(&_0, "array_values", NULL, 24, args);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("args"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, getArgArray) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("args"), PH_NOISY_CC);
	if (zephir_fast_count_int(_0 TSRMLS_CC) > 0) {
		RETURN_MEMBER(this_ptr, "args");
	}
	array_init(return_value);
	return;

}

PHP_METHOD(Nc_Factory_ClassNameAbstract, getClassName) {

}

