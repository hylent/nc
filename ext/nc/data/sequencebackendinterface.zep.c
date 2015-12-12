
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Data_SequenceBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Data, SequenceBackendInterface, nc, data_sequencebackendinterface, nc_data_sequencebackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Data_SequenceBackendInterface, nextSequence);

ZEPHIR_DOC_METHOD(Nc_Data_SequenceBackendInterface, restoreSequence);

