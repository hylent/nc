
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Data_Sequence) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Data, Sequence, nc, data_sequence, nc_data_dataabstract_ce, nc_data_sequence_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Data_Sequence, next) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "nextsequence", NULL, 0, _1, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Sequence, restore) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequences_param = NULL, *_0, *_1;
	zval *sequences = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sequences_param);

	zephir_get_arrval(sequences, sequences_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "restoresequence", NULL, 0, _1, sequences);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

