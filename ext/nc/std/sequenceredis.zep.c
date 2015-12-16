
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
#include "kernel/concat.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Std_SequenceRedis) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, SequenceRedis, nc, std_sequenceredis, nc_std_sequenceredis_method_entry, 0);

	zend_declare_property_null(nc_std_sequenceredis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_std_sequenceredis_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_sequenceredis_ce, SL("DEFAULT_PREFIX"), "sequence:" TSRMLS_CC);

	zend_class_implements(nc_std_sequenceredis_ce TSRMLS_CC, 1, nc_std_sequenceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_SequenceRedis, __construct) {

	zval *prefix = NULL;
	zval *redis, *prefix_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "sequence:", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_SequenceRedis, getNextSequence) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *s = NULL, *_0, *_1, *_2, *_3, *_4$$3;
	zval *identifier = NULL, *_5$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 1);
	ZEPHIR_CALL_METHOD(&s, _0, "incr", NULL, 0, _2, _3);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(s))) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, nc_std_exception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, "Cannot get next sequence of: ", identifier);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 2, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "nc/std/sequenceredis.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(zephir_get_intval(s));

}

PHP_METHOD(Nc_Std_SequenceRedis, restoreSequence) {

	int ZEPHIR_LAST_CALL_STATUS;
	long sequence;
	zval *identifier_param = NULL, *sequence_param = NULL, *_0, *_1, *_2, *_3;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &sequence_param);

	zephir_get_strval(identifier, identifier_param);
	sequence = zephir_get_intval(sequence_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, identifier);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, sequence);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, _2, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

