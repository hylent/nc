
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Data_SingleValueBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Data, SingleValueBackendInterface, nc, data_singlevaluebackendinterface, nc_data_singlevaluebackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Data_SingleValueBackendInterface, setSingleValue);

ZEPHIR_DOC_METHOD(Nc_Data_SingleValueBackendInterface, getSingleValue);

ZEPHIR_DOC_METHOD(Nc_Data_SingleValueBackendInterface, deleteSingleValue);

