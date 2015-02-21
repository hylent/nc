
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
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Serializer_Json) {

	ZEPHIR_REGISTER_CLASS(Nc\\Serializer, Json, nc, serializer_json, nc_serializer_json_method_entry, 0);

	zend_declare_property_null(nc_serializer_json_ce, SL("serializeFlag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_serializer_json_ce, SL("unserializeToArray"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_serializer_json_ce TSRMLS_CC, 1, nc_serializer_serializerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Serializer_Json, __construct) {

	zend_bool unserializeToArray;
	zval *serializeFlag_param = NULL, *unserializeToArray_param = NULL, *_0;
	long serializeFlag;

	zephir_fetch_params(0, 0, 2, &serializeFlag_param, &unserializeToArray_param);

	if (!serializeFlag_param) {
		serializeFlag = 0;
	} else {
		serializeFlag = zephir_get_intval(serializeFlag_param);
	}
	if (!unserializeToArray_param) {
		unserializeToArray = 1;
	} else {
		unserializeToArray = zephir_get_boolval(unserializeToArray_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, serializeFlag);
	zephir_update_property_this(this_ptr, SL("serializeFlag"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("unserializeToArray"), unserializeToArray ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

PHP_METHOD(Nc_Serializer_Json, serialize) {

	zval *data, *_0;

	zephir_fetch_params(0, 1, 0, &data);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("serializeFlag"), PH_NOISY_CC);
	zephir_json_encode(return_value, &(return_value), data, zephir_get_intval(_0)  TSRMLS_CC);
	return;

}

PHP_METHOD(Nc_Serializer_Json, unserialize) {

	zval *str_param = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("unserializeToArray"), PH_NOISY_CC);
	zephir_json_decode(return_value, &(return_value), str, zephir_get_intval(_0)  TSRMLS_CC);
	RETURN_MM();

}

