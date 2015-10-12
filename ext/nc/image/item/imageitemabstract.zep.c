
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Image_Item_ImageItemAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Image\\Item, ImageItemAbstract, nc, image_item_imageitemabstract, nc_image_item_imageitemabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_image_item_imageitemabstract_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_image_item_imageitemabstract_ce, SL("properties"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Item_ImageItemAbstract, __construct) {

	zval *properties = NULL;
	zval *backend, *properties_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &backend, &properties_param);

	if (!properties_param) {
		ZEPHIR_INIT_VAR(properties);
		array_init(properties);
	} else {
		zephir_get_arrval(properties, properties_param);
	}


	zephir_update_property_this(this_ptr, SL("backend"), backend TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("properties"), properties TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Item_ImageItemAbstract, __set) {

	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("properties"), name, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Item_ImageItemAbstract, __get) {

	zval *name_param = NULL, *value = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("properties"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Image_Item_ImageItemAbstract, __destruct) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "destroy", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

