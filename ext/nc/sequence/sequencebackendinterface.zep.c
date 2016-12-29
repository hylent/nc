
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Sequence_SequenceBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Sequence, SequenceBackendInterface, nc, sequence_sequencebackendinterface, nc_sequence_sequencebackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Sequence_SequenceBackendInterface, getSequence);

ZEPHIR_DOC_METHOD(Nc_Sequence_SequenceBackendInterface, next);

ZEPHIR_DOC_METHOD(Nc_Sequence_SequenceBackendInterface, restore);

ZEPHIR_DOC_METHOD(Nc_Sequence_SequenceBackendInterface, clear);

