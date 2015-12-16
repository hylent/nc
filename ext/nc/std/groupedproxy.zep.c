
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Std_GroupedProxy) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, GroupedProxy, nc, std_groupedproxy, nc_std_groupedproxy_method_entry, 0);

	zend_declare_property_null(nc_std_groupedproxy_ce, SL("frontend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_std_groupedproxy_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_bool(nc_std_groupedproxy_ce, SL("NON_EXISTENT_VALUE"), 0 TSRMLS_CC);

	zend_class_implements(nc_std_groupedproxy_ce TSRMLS_CC, 1, nc_std_groupedinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_GroupedProxy, __construct) {

	zval *frontend, *backend;

	zephir_fetch_params(0, 2, 0, &frontend, &backend);



	zephir_update_property_this(this_ptr, SL("frontend"), frontend TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("backend"), backend TSRMLS_CC);

}

PHP_METHOD(Nc_Std_GroupedProxy, setGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *value, *_0, *_1;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &identifier_param, &key_param, &value);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setgrouped", NULL, 0, identifier, key, value);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "deletegrouped", NULL, 0, identifier, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedProxy, getGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *value = NULL, *_0, *_1, *_3, *_4, *_2$$6;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &key_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&value, _0, "getgrouped", NULL, 0, identifier, key);
	zephir_check_call_status();
	if (Z_TYPE_P(value) != IS_NULL) {
		if (!ZEPHIR_IS_FALSE_IDENTICAL(value)) {
			RETURN_CCTOR(value);
		}
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&value, _1, "getgrouped", NULL, 0, identifier, key);
	zephir_check_call_status();
	if (Z_TYPE_P(value) != IS_NULL) {
		if (!ZEPHIR_IS_FALSE_IDENTICAL(value)) {
			_2$$6 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _2$$6, "setgrouped", NULL, 0, identifier, key, value);
			zephir_check_call_status();
		}
		RETURN_CCTOR(value);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, _3, "setgrouped", NULL, 0, identifier, key, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedProxy, deleteGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *key_param = NULL, *_0, *_1, *_2;
	zval *identifier = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &key_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "deletegrouped", NULL, 0, identifier, key);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, _1, "setgrouped", NULL, 0, identifier, key, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedProxy, setManyGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *identifier_param = NULL, *keyValues_param = NULL, *_0, *_1, *_2;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keyValues_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keyValues, keyValues_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setmanygrouped", NULL, 0, identifier, keyValues);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_array_keys(_2, keyValues TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "deletemanygrouped", NULL, 0, identifier, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedProxy, getManyGrouped) {

	HashTable *_2, *_6$$7;
	HashPosition _1, _5$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL;
	zval *identifier_param = NULL, *keys_param = NULL, *k = NULL, *v = NULL, *a = NULL, *r = NULL, *x = NULL, *_0, **_3, *_4$$7, **_7$$7, *_8$$10, *_9$$11, *_10$$11 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keys_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(r);
	array_init(r);
	ZEPHIR_INIT_VAR(x);
	array_init(x);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&a, _0, "getmanygrouped", NULL, 0, identifier, keys);
	zephir_check_call_status();
	zephir_is_iterable(keys, &_2, &_1, 0, 0, "nc/std/groupedproxy.zep", 74);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		ZEPHIR_OBS_NVAR(v);
		if (zephir_array_isset_fetch(&v, a, k, 0 TSRMLS_CC)) {
			if (!ZEPHIR_IS_FALSE_IDENTICAL(v)) {
				zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_append(&x, k, PH_SEPARATE, "nc/std/groupedproxy.zep", 69);
			zephir_array_update_zval(&r, k, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	if (zephir_fast_count_int(x TSRMLS_CC) > 0) {
		_4$$7 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&a, _4$$7, "getmanygrouped", NULL, 0, identifier, x);
		zephir_check_call_status();
		zephir_is_iterable(x, &_6$$7, &_5$$7, 0, 0, "nc/std/groupedproxy.zep", 88);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$7, (void**) &_7$$7, &_5$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$7, &_5$$7)
		) {
			ZEPHIR_GET_HVALUE(k, _7$$7);
			ZEPHIR_OBS_NVAR(v);
			if (zephir_array_isset_fetch(&v, a, k, 0 TSRMLS_CC)) {
				zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
				if (!ZEPHIR_IS_FALSE_IDENTICAL(v)) {
					_8$$10 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(NULL, _8$$10, "setgrouped", NULL, 0, identifier, k, v);
					zephir_check_call_status();
				}
			} else {
				zephir_array_unset(&r, k, PH_SEPARATE);
				_9$$11 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_10$$11);
				ZVAL_BOOL(_10$$11, 0);
				ZEPHIR_CALL_METHOD(NULL, _9$$11, "setgrouped", NULL, 0, identifier, k, _10$$11);
				zephir_check_call_status();
			}
		}
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Nc_Std_GroupedProxy, deleteManyGrouped) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL;
	zval *identifier_param = NULL, *keys_param = NULL, *k = NULL, *_0, **_3, *_4$$3, *_5$$3 = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keys_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keys, keys_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "deletemany", NULL, 0, keys);
	zephir_check_call_status();
	zephir_is_iterable(keys, &_2, &_1, 0, 0, "nc/std/groupedproxy.zep", 102);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_BOOL(_5$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "setgrouped", NULL, 0, identifier, k, _5$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedProxy, setAllGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues = NULL;
	zval *identifier_param = NULL, *keyValues_param = NULL, *_0, *_1;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &identifier_param, &keyValues_param);

	zephir_get_strval(identifier, identifier_param);
	zephir_get_arrval(keyValues, keyValues_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setallgrouped", NULL, 0, identifier, keyValues);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "deleteallgrouped", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_GroupedProxy, getAllGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getallgrouped", NULL, 0, identifier);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std_GroupedProxy, deleteAllGrouped) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL, *_0, *_1;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "deleteallgrouped", NULL, 0, identifier);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "deleteallgrouped", NULL, 0, identifier);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

