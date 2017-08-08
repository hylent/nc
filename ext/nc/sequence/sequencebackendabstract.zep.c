
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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Sequence_SequenceBackendAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Sequence, SequenceBackendAbstract, nc, sequence_sequencebackendabstract, nc_sequence_sequencebackendabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(nc_sequence_sequencebackendabstract_ce TSRMLS_CC, 1, nc_sequence_sequencebackendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Sequence_SequenceBackendAbstract, getSequence) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	object_init_ex(return_value, nc_sequence_sequence_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, this_ptr, &name);
	zephir_check_call_status();
	RETURN_MM();

}

