
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Serializer_Php) {

	ZEPHIR_REGISTER_CLASS(Nc\\Serializer, Php, nc, serializer_php, nc_serializer_php_method_entry, 0);

	zend_class_implements(nc_serializer_php_ce TSRMLS_CC, 1, nc_serializer_serializerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Serializer_Php, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 95, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Serializer_Php, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 96, str);
	zephir_check_call_status();
	RETURN_MM();

}

