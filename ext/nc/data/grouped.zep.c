
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


ZEPHIR_INIT_CLASS(Nc_Data_Grouped) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Data, Grouped, nc, data_grouped, nc_data_dataabstract_ce, nc_data_grouped_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Data_Grouped, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setgrouped", NULL, 0, _1, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Grouped, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getgrouped", NULL, 0, _1, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Grouped, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "deletegrouped", NULL, 0, _1, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Grouped, setMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *_0, *_1;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setmanygrouped", NULL, 0, _1, keyValues);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Grouped, getMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *_0, *_1;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getmanygrouped", NULL, 0, _1, keys);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Grouped, deleteMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *_0, *_1;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "deletemanygrouped", NULL, 0, _1, keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Grouped, setAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *_0, *_1;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setallgrouped", NULL, 0, _1, keyValues);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Grouped, getAll) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getallgrouped", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Grouped, deleteAll) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "deleteallgrouped", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

