
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
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Sequence_MongoCollection) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Sequence, MongoCollection, nc, sequence_mongocollection, nc_sequence_sequencebackendabstract_ce, nc_sequence_mongocollection_method_entry, 0);

	zend_declare_property_null(nc_sequence_mongocollection_ce, SL("mongoCollection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Sequence_MongoCollection, __construct) {

	zval *mongoCollection, mongoCollection_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&mongoCollection_sub);

	zephir_fetch_params(0, 1, 0, &mongoCollection);



	zephir_update_property_zval(this_ptr, SL("mongoCollection"), mongoCollection);

}

PHP_METHOD(Nc_Sequence_MongoCollection, getMongoCollection) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "mongoCollection");

}

PHP_METHOD(Nc_Sequence_MongoCollection, next) {

	zend_bool _5;
	zval _1, _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, __$true, r, s, _0, _4, _6$$3, _7$$3, _8$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("mongoCollection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0 TSRMLS_CC);
	add_assoc_long_ex(&_3, SL("sequence"), 1);
	zephir_array_update_string(&_2, SL("$inc"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("upsert"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("new"), &__$true, PH_COPY | PH_SEPARATE);
	ZVAL_NULL(&_4);
	ZEPHIR_CALL_METHOD(&r, &_0, "findandmodify", NULL, 0, &_1, &_2, &_4, &_3);
	zephir_check_call_status();
	_5 = Z_TYPE_P(&r) != IS_ARRAY;
	if (!(_5)) {
		ZEPHIR_OBS_VAR(&s);
		_5 = !(zephir_array_isset_string_fetch(&s, &r, SL("sequence"), 0));
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_VAR(&_6$$3);
		object_init_ex(&_6$$3, nc_sequence_exception_ce);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Cannot get next sequence of '%s'");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "sprintf", NULL, 2, &_7$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "__construct", NULL, 3, &_8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$3, "nc/sequence/mongocollection.zep", 33 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(zephir_get_intval(&s));

}

PHP_METHOD(Nc_Sequence_MongoCollection, restore) {

	zval _1, _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	long sequence;
	zval *name_param = NULL, *sequence_param = NULL, __$true, _0, _4;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &sequence_param);

	zephir_get_strval(&name, name_param);
	sequence = zephir_get_intval(sequence_param);


	zephir_read_property(&_0, this_ptr, SL("mongoCollection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_4, sequence);
	zephir_array_update_string(&_3, SL("sequence"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("$set"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_array(&_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("upsert"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_0, "insert", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_MongoCollection, clear) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("mongoCollection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "drop", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

