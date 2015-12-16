
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Std_SequenceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Std, SequenceInterface, nc, std_sequenceinterface, nc_std_sequenceinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Std_SequenceInterface, getNextSequence);

ZEPHIR_DOC_METHOD(Nc_Std_SequenceInterface, restoreSequence);

