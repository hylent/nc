
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Std_SequenceMysql) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, SequenceMysql, nc, std_sequencemysql, nc_std_sequencemysql_method_entry, 0);

	zend_declare_property_null(nc_std_sequencemysql_ce, SL("mysql"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_std_sequencemysql_ce, SL("table"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_sequencemysql_ce, SL("DEFAULT_TABLE"), "sequencetable" TSRMLS_CC);

	zend_class_implements(nc_std_sequencemysql_ce TSRMLS_CC, 1, nc_std_sequenceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_SequenceMysql, __construct) {

	zval *table = NULL;
	zval *mysql, *table_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &mysql, &table_param);

	if (!table_param) {
		ZEPHIR_INIT_VAR(table);
		ZVAL_STRING(table, "sequencetable", 1);
	} else {
		zephir_get_strval(table, table_param);
	}


	zephir_update_property_this(this_ptr, SL("mysql"), mysql TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("table"), table TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_SequenceMysql, getNextSequence) {

	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0, *_1 = NULL, *_2, *_4, *_5;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mysql"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("identifier"), &identifier, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "sequence", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 1);
	ZEPHIR_CALL_METHOD(&_1, _0, "insert", NULL, 0, _2, _3, _4, _5);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_1));

}

PHP_METHOD(Nc_Std_SequenceMysql, restoreSequence) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	long sequence;
	zval *identifier_param = NULL, *sequence_param = NULL, *_0, *_1, *_3 = NULL, *_4;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &sequence_param);

	zephir_get_strval(identifier, identifier_param);
	sequence = zephir_get_intval(sequence_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mysql"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("identifier"), &identifier, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, sequence);
	zephir_array_update_string(&_2, SL("sequence"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 1);
	ZEPHIR_CALL_METHOD(NULL, _0, "insert", NULL, 0, _1, _2, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

