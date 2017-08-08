
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
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Di_CreatorClassMapper) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Di, CreatorClassMapper, nc, di_creatorclassmapper, nc_di_creatorabstract_ce, nc_di_creatorclassmapper_method_entry, 0);

	zend_declare_property_null(nc_di_creatorclassmapper_ce, SL("classMapper"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Di_CreatorClassMapper, __construct) {

	zval *classMapper_param = NULL;
	zval classMapper;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classMapper);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classMapper_param);

	zephir_get_arrval(&classMapper, classMapper_param);


	zephir_update_property_zval(this_ptr, SL("classMapper"), &classMapper);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_CreatorClassMapper, getValidClassName) {

	zval *name_param = NULL, className, _0;
	zval name, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_OBS_VAR(&className);
	zephir_read_property(&_0, this_ptr, SL("classMapper"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&className, &_0, &name, 0 TSRMLS_CC)) {
		zephir_get_strval(&_1$$3, &className);
		RETURN_CTOR(&_1$$3);
	}
	if (zephir_class_exists(&className, 1 TSRMLS_CC)) {
		RETURN_CCTOR(&className);
	}
	RETURN_MM_STRING("");

}

