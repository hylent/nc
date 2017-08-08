
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


ZEPHIR_INIT_CLASS(Nc_Di_CreatorClassPrefix) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Di, CreatorClassPrefix, nc, di_creatorclassprefix, nc_di_creatorabstract_ce, nc_di_creatorclassprefix_method_entry, 0);

	zend_declare_property_null(nc_di_creatorclassprefix_ce, SL("classPrefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Di_CreatorClassPrefix, __construct) {

	zval *classPrefix_param = NULL;
	zval classPrefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classPrefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classPrefix_param);

	zephir_get_strval(&classPrefix, classPrefix_param);


	zephir_update_property_zval(this_ptr, SL("classPrefix"), &classPrefix);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_CreatorClassPrefix, getValidClassName) {

	zval *name_param = NULL, className, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("classPrefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &name);
	ZEPHIR_INIT_VAR(&className);
	ZEPHIR_CONCAT_VV(&className, &_0, &_1);
	if (zephir_class_exists(&className, 1 TSRMLS_CC)) {
		RETURN_CCTOR(&className);
	}
	RETURN_MM_STRING("");

}

