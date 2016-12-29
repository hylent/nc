
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
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Sequence_Sequence) {

	ZEPHIR_REGISTER_CLASS(Nc\\Sequence, Sequence, nc, sequence_sequence, nc_sequence_sequence_method_entry, 0);

	zend_declare_property_null(nc_sequence_sequence_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_sequence_sequence_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Sequence_Sequence, __construct) {

	zval name;
	zval *backend, backend_sub, *name_param = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&backend_sub);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &backend, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, SL("backend"), backend);
	zephir_update_property_zval(this_ptr, SL("name"), &name);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_Sequence, getBackend) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "backend");

}

PHP_METHOD(Nc_Sequence_Sequence, getName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "name");

}

PHP_METHOD(Nc_Sequence_Sequence, next) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "next", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Sequence_Sequence, restore) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequence_param = NULL, _0, _1, _2;
	long sequence;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sequence_param);

	sequence = zephir_get_intval(sequence_param);


	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, sequence);
	ZEPHIR_CALL_METHOD(NULL, &_0, "restore", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

