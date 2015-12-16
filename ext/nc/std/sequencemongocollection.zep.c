
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Std_SequenceMongoCollection) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, SequenceMongoCollection, nc, std_sequencemongocollection, nc_std_sequencemongocollection_method_entry, 0);

	zend_declare_property_null(nc_std_sequencemongocollection_ce, SL("mongoCollection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_std_sequencemongocollection_ce TSRMLS_CC, 1, nc_std_sequenceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_SequenceMongoCollection, __construct) {

	zval *mongoCollection;

	zephir_fetch_params(0, 1, 0, &mongoCollection);



	zephir_update_property_this(this_ptr, SL("mongoCollection"), mongoCollection TSRMLS_CC);

}

PHP_METHOD(Nc_Std_SequenceMongoCollection, getNextSequence) {

	zend_bool _5;
	zval *_1, *_2, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *r = NULL, *s = NULL, *_0, *_4, *_6$$3;
	zval *identifier = NULL, *_7$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &identifier, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	add_assoc_long_ex(_3, SS("sequence"), 1);
	zephir_array_update_string(&_2, SL("$inc"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("upsert"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("new"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_CALL_METHOD(&r, _0, "findandmodify", NULL, 0, _1, _2, _4, _3);
	zephir_check_call_status();
	_5 = Z_TYPE_P(r) != IS_ARRAY;
	if (!(_5)) {
		ZEPHIR_OBS_VAR(s);
		_5 = !(zephir_array_isset_string_fetch(&s, r, SS("sequence"), 0 TSRMLS_CC));
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_VAR(_6$$3);
		object_init_ex(_6$$3, nc_std_exception_ce);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, "Cannot get next sequence of: ", identifier);
		ZEPHIR_CALL_METHOD(NULL, _6$$3, "__construct", NULL, 2, _7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$3, "nc/std/sequencemongocollection.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(zephir_get_intval(s));

}

PHP_METHOD(Nc_Std_SequenceMongoCollection, restoreSequence) {

	zval *_1, *_2, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long sequence;
	zval *identifier_param = NULL, *sequence_param = NULL, *_0, *_4;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &sequence_param);

	zephir_get_strval(identifier, identifier_param);
	sequence = zephir_get_intval(sequence_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &identifier, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, sequence);
	zephir_array_update_string(&_3, SL("sequence"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("$set"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("upsert"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "insert", NULL, 0, _1, _2, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

