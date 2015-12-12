
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Data_PivotBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Data, PivotBackendInterface, nc, data_pivotbackendinterface, nc_data_pivotbackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, addPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, removePivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, hasPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, addObjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, removeObjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, hasObjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, getObjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, countObjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, countAndGetObjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, addSubjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, removeSubjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, hasSubjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, getSubjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, countSubjectsPivot);

ZEPHIR_DOC_METHOD(Nc_Data_PivotBackendInterface, countAndGetSubjectsPivot);

