
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


ZEPHIR_INIT_CLASS(Nc_Data_DataAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Data, DataAbstract, nc, data_dataabstract, nc_data_dataabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_data_dataabstract_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_data_dataabstract_ce, SL("identifier"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Data_DataAbstract, __construct) {

	zval *identifier = NULL;
	zval *backend, *identifier_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &backend, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	zephir_update_property_this(this_ptr, SL("backend"), backend TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("identifier"), identifier TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

