
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Nc_Std) {

	ZEPHIR_REGISTER_CLASS(Nc, Std, nc, std, nc_std_method_entry, 0);

	zend_declare_class_constant_string(nc_std_ce, SL("CHAR_LIST"), "0123456789abcdefghijklmnopqrstuvwxyz" TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_ce, SL("IGNORE_ERROR"), "Nc\\Std::ignoreError" TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_ce, SL("THROW_ERROR"), "Nc\\Std::throwError" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Std, sizeToByte) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zval *size_param = NULL, *match = NULL, *_0 = NULL, *_1, *_2, *_3 = NULL, *_5, *_6 = NULL;
	zval *size = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &size_param);

	zephir_get_strval(size, size_param);
	ZEPHIR_INIT_VAR(match);
	ZVAL_NULL(match);


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtoupper(_1, size);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "/^([\\d\\.]+)([KMGT])B?$/", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(match);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_match", &_4, _2, _1, match);
	zephir_check_temp_parameter(_2);
	Z_UNSET_ISREF_P(match);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		zephir_array_fetch_long(&_5, match, 2, PH_NOISY | PH_READONLY, "nc/std.zep", 15 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_STRING(_5, "T")) {
				ZEPHIR_OBS_VAR(_6);
				zephir_array_fetch_long(&_6, match, 1, PH_NOISY, "nc/std.zep", 17 TSRMLS_CC);
				RETURN_MM_DOUBLE((1099511627776.0 * zephir_get_doubleval(_6)));
			}
			if (ZEPHIR_IS_STRING(_5, "G")) {
				ZEPHIR_OBS_NVAR(_6);
				zephir_array_fetch_long(&_6, match, 1, PH_NOISY, "nc/std.zep", 19 TSRMLS_CC);
				RETURN_MM_DOUBLE((1073741824.0 * zephir_get_doubleval(_6)));
			}
			if (ZEPHIR_IS_STRING(_5, "M")) {
				ZEPHIR_OBS_NVAR(_6);
				zephir_array_fetch_long(&_6, match, 1, PH_NOISY, "nc/std.zep", 21 TSRMLS_CC);
				RETURN_MM_DOUBLE((1048576.0 * zephir_get_doubleval(_6)));
			}
			if (ZEPHIR_IS_STRING(_5, "K")) {
				ZEPHIR_OBS_NVAR(_6);
				zephir_array_fetch_long(&_6, match, 1, PH_NOISY, "nc/std.zep", 23 TSRMLS_CC);
				RETURN_MM_DOUBLE((1024.0 * zephir_get_doubleval(_6)));
			}
		} while(0);

	}
	ZEPHIR_RETURN_CALL_FUNCTION("floatval", &_7, size);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std, uuid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_5 = NULL;
	zval *salt_param = NULL, *_0 = NULL, *_2 = NULL, *_4;
	zval *salt = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &salt_param);

	if (!salt_param) {
		ZEPHIR_INIT_VAR(salt);
		ZVAL_STRING(salt, "", 1);
	} else {
		zephir_get_strval(salt, salt_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "mt_rand", &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "uniqid", &_3, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, _2, salt);
	ZEPHIR_RETURN_CALL_FUNCTION("md5", &_5, _4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std, randString) {

	zephir_fcall_cache_entry *_6 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *charList = NULL, *result;
	zval *len_param = NULL, *charList_param = NULL, _0 = zval_used_for_init, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_5 = NULL;
	long len, maxIndex;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &len_param, &charList_param);

	len = zephir_get_intval(len_param);
	if (!charList_param) {
		ZEPHIR_INIT_VAR(charList);
		ZVAL_STRING(charList, "", 1);
	} else {
		zephir_get_strval(charList, charList_param);
	}
	ZEPHIR_INIT_VAR(result);
	ZVAL_STRING(result, "", 1);


	if (unlikely(len < 1)) {
		RETURN_MM_STRING("", 1);
	}
	if (!(charList && Z_STRLEN_P(charList))) {
		ZEPHIR_INIT_NVAR(charList);
		ZVAL_STRING(charList, "0123456789abcdefghijklmnopqrstuvwxyz", 1);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "utf-8", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strlen", NULL, charList, &_0);
	zephir_check_call_status();
	maxIndex = (zephir_get_intval(_1) - 1);
	while (1) {
		if (!(len)) {
			break;
		}
		len--;
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, maxIndex);
		ZEPHIR_CALL_FUNCTION(&_3, "mt_rand", &_4, &_0, &_2);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 1);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "utf-8", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "mb_substr", &_6, charList, _3, &_0, &_2);
		zephir_check_call_status();
		zephir_concat_self(&result, _5 TSRMLS_CC);
	}
	RETURN_CTOR(result);

}

PHP_METHOD(Nc_Std, camelCase) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zend_bool upper, _5, _6;
	zval *from_param = NULL, *upper_param = NULL, *c = NULL, *_0 = NULL, **_4, *_7 = NULL;
	zval *from = NULL, *to;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &upper_param);

	zephir_get_strval(from, from_param);
	if (!upper_param) {
		upper = 0;
	} else {
		upper = zephir_get_boolval(upper_param);
	}
	ZEPHIR_INIT_VAR(to);
	ZVAL_STRING(to, "", 1);


	ZEPHIR_CALL_FUNCTION(&_0, "str_split", &_1, from);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "nc/std.zep", 78);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(c, _4);
		_5 = ZEPHIR_IS_STRING(c, " ");
		if (!(_5)) {
			_5 = ZEPHIR_IS_STRING(c, "_");
		}
		_6 = _5;
		if (!(_6)) {
			_6 = ZEPHIR_IS_STRING(c, "-");
		}
		if (_6) {
			upper = 1;
			continue;
		}
		if (upper) {
			ZEPHIR_INIT_NVAR(_7);
			zephir_fast_strtoupper(_7, c);
			zephir_concat_self(&to, _7 TSRMLS_CC);
			upper = 0;
			continue;
		}
		ZEPHIR_INIT_NVAR(_7);
		zephir_fast_strtolower(_7, c);
		zephir_concat_self(&to, _7 TSRMLS_CC);
	}
	RETURN_CTOR(to);

}

PHP_METHOD(Nc_Std, uncamelCase) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zval *from_param = NULL, *sep_param = NULL, *_1 = NULL, *_3, *_4 = NULL;
	zval *from = NULL, *sep = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &sep_param);

	zephir_get_strval(from, from_param);
	if (!sep_param) {
		ZEPHIR_INIT_VAR(sep);
		ZVAL_STRING(sep, "-", 1);
	} else {
		zephir_get_strval(sep, sep_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VS(_0, sep, "$1");
	ZEPHIR_CALL_FUNCTION(&_1, "lcfirst", &_2, from);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "/([A-Z])/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace", &_5, _3, _0, _1);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_fast_strtolower(return_value, _4);
	RETURN_MM();

}

PHP_METHOD(Nc_Std, valueOfArray) {

	zend_bool _3;
	HashTable *_1;
	HashPosition _0;
	zval *key = NULL;
	zval *data_param = NULL, *key_param = NULL, *defaultValue = NULL, *parts, *part = NULL, *value = NULL, *tmpValue, **_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &data_param, &key_param, &defaultValue);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL("."), key, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(value, data);
	zephir_is_iterable(parts, &_1, &_0, 0, 0, "nc/std.zep", 100);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(part, _2);
		_3 = Z_TYPE_P(value) != IS_ARRAY;
		if (!(_3)) {
			_3 = !(zephir_array_isset_fetch(&tmpValue, value, part, 1 TSRMLS_CC));
		}
		if (_3) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		ZEPHIR_CPY_WRT(value, tmpValue);
	}
	RETURN_CCTOR(value);

}

PHP_METHOD(Nc_Std, indexedData) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *indexKey = NULL;
	zval *data_param = NULL, *indexKey_param = NULL, *k = NULL, *v = NULL, *arr, *indexValue = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &indexKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(indexKey, indexKey_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 118);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Invalid item type, array required: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 109 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 112 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&arr, indexValue, &v, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, indexedValues) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *indexKey = NULL, *valueKey = NULL;
	zval *data_param = NULL, *indexKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr, *indexValue = NULL, *valueValue = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &indexKey_param, &valueKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(indexKey, indexKey_param);
	zephir_get_strval(valueKey, valueKey_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 139);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 127 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 130 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 133 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&arr, indexValue, &valueValue, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, groupedData) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *groupKey = NULL;
	zval *data_param = NULL, *groupKey_param = NULL, *k = NULL, *v = NULL, *arr, *groupValue = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &groupKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(groupKey, groupKey_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 157);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 148 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 151 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &v TSRMLS_CC, SL("za"), 2, groupValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, groupedValues) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *groupKey = NULL, *valueKey = NULL;
	zval *data_param = NULL, *groupKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr, *groupValue = NULL, *valueValue = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &groupKey_param, &valueKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(valueKey, valueKey_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 178);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 166 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 169 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 172 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &valueValue TSRMLS_CC, SL("za"), 2, groupValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, groupIndexedData) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *groupKey = NULL, *indexKey = NULL;
	zval *data_param = NULL, *groupKey_param = NULL, *indexKey_param = NULL, *k = NULL, *v = NULL, *arr, *groupValue = NULL, *indexValue = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &groupKey_param, &indexKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(indexKey, indexKey_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 199);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 187 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 190 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 193 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &v TSRMLS_CC, SL("zz"), 2, groupValue, indexValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, groupIndexedValues) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *groupKey = NULL, *indexKey = NULL, *valueKey = NULL;
	zval *data_param = NULL, *groupKey_param = NULL, *indexKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr, *groupValue = NULL, *indexValue = NULL, *valueValue = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &data_param, &groupKey_param, &indexKey_param, &valueKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(indexKey, indexKey_param);
	zephir_get_strval(valueKey, valueKey_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 223);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 208 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 211 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 214 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 217 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &valueValue TSRMLS_CC, SL("zz"), 2, groupValue, indexValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, uniqueValues) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *uniqueKey = NULL;
	zval *data_param = NULL, *uniqueKey_param = NULL, *k = NULL, *v = NULL, *arr, *uniqueValue = NULL, **_2, *_3 = NULL, *_4 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &uniqueKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(uniqueKey, uniqueKey_param);
	ZEPHIR_INIT_VAR(arr);
	array_init(arr);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 241);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 232 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(uniqueValue);
		if (unlikely(!(zephir_array_isset_fetch(&uniqueValue, v, uniqueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SV(_4, "Cannot find value of unique at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "nc/std.zep", 235 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&arr, uniqueValue, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	}
	zephir_array_keys(return_value, arr TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Nc_Std, newInstanceOf) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1, *_5, *_8, *_11, *_14, *_17;
	long c;
	zval *args = NULL;
	zval *className_param = NULL, *args_param = NULL, *a = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, *_6, *_7 = NULL, *_9, *_10 = NULL, *_12, *_13 = NULL, *_15, *_16 = NULL, *_18;
	zval *className = NULL, *_19;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &className_param, &args_param);

	zephir_get_strval(className, className_param);
	if (!args_param) {
	ZEPHIR_INIT_VAR(args);
	array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}


	c = zephir_fast_count_int(args TSRMLS_CC);
	if (c < 1) {
		zephir_fetch_safe_class(_0, className);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _1);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	if (c > 5) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, className);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_2, "newinstanceargs", NULL, args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&a, "array_values", &_3, args);
	zephir_check_call_status();
	do {
		if (c == 1) {
			zephir_fetch_safe_class(_4, className);
			_5 = zend_fetch_class(Z_STRVAL_P(_4), Z_STRLEN_P(_4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _5);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_6, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 260 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _6);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 2) {
			zephir_fetch_safe_class(_7, className);
			_8 = zend_fetch_class(Z_STRVAL_P(_7), Z_STRLEN_P(_7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _8);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_6, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 262 TSRMLS_CC);
				zephir_array_fetch_long(&_9, a, 1, PH_NOISY | PH_READONLY, "nc/std.zep", 262 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _6, _9);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 3) {
			zephir_fetch_safe_class(_10, className);
			_11 = zend_fetch_class(Z_STRVAL_P(_10), Z_STRLEN_P(_10), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _11);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_6, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 264 TSRMLS_CC);
				zephir_array_fetch_long(&_9, a, 1, PH_NOISY | PH_READONLY, "nc/std.zep", 264 TSRMLS_CC);
				zephir_array_fetch_long(&_12, a, 2, PH_NOISY | PH_READONLY, "nc/std.zep", 264 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _6, _9, _12);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 4) {
			zephir_fetch_safe_class(_13, className);
			_14 = zend_fetch_class(Z_STRVAL_P(_13), Z_STRLEN_P(_13), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _14);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_6, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 266 TSRMLS_CC);
				zephir_array_fetch_long(&_9, a, 1, PH_NOISY | PH_READONLY, "nc/std.zep", 266 TSRMLS_CC);
				zephir_array_fetch_long(&_12, a, 2, PH_NOISY | PH_READONLY, "nc/std.zep", 266 TSRMLS_CC);
				zephir_array_fetch_long(&_15, a, 3, PH_NOISY | PH_READONLY, "nc/std.zep", 266 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _6, _9, _12, _15);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 5) {
			zephir_fetch_safe_class(_16, className);
			_17 = zend_fetch_class(Z_STRVAL_P(_16), Z_STRLEN_P(_16), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _17);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_6, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 268 TSRMLS_CC);
				zephir_array_fetch_long(&_9, a, 1, PH_NOISY | PH_READONLY, "nc/std.zep", 268 TSRMLS_CC);
				zephir_array_fetch_long(&_12, a, 2, PH_NOISY | PH_READONLY, "nc/std.zep", 268 TSRMLS_CC);
				zephir_array_fetch_long(&_15, a, 3, PH_NOISY | PH_READONLY, "nc/std.zep", 268 TSRMLS_CC);
				zephir_array_fetch_long(&_18, a, 4, PH_NOISY | PH_READONLY, "nc/std.zep", 268 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _6, _9, _12, _15, _18);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, nc_exception_ce);
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_CONCAT_SV(_19, "Fail to fetch a new instance of class: ", className);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _19);
	zephir_check_call_status();
	zephir_throw_exception_debug(_2, "nc/std.zep", 271 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Std, ignoreError) {

	zval *context = NULL;
	zval *s = NULL, *f = NULL, *l = NULL;
	zval *n_param = NULL, *s_param = NULL, *f_param = NULL, *l_param = NULL, *context_param = NULL;
	long n;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &n_param, &s_param, &f_param, &l_param, &context_param);

	n = zephir_get_intval(n_param);
	zephir_get_strval(s, s_param);
	zephir_get_strval(f, f_param);
	zephir_get_strval(l, l_param);
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	RETURN_MM_NULL();

}

PHP_METHOD(Nc_Std, throwError) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *s = NULL, *f = NULL, *l = NULL, *_1;
	zval *n_param = NULL, *s_param = NULL, *f_param = NULL, *l_param = NULL, *context_param = NULL, *_0, *_2;
	long n;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &n_param, &s_param, &f_param, &l_param, &context_param);

	n = zephir_get_intval(n_param);
	zephir_get_strval(s, s_param);
	zephir_get_strval(f, f_param);
	zephir_get_strval(l, l_param);
	if (!context_param) {
	ZEPHIR_INIT_VAR(context);
	array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("errorexception") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSVSVS(_1, s, " (", f, ":", l, ")");
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, n);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "nc/std.zep", 281 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Std, outputScript) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *path_param = NULL, *data_param = NULL, *_0 = NULL, *_2;
	zval *path = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &data_param);

	zephir_get_strval(path, path_param);
	zephir_get_arrval(data, data_param);


	if (unlikely(!((zephir_file_exists(path TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, nc_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Cannot find script path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "nc/std.zep", 287 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 4);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(data);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", &_3, data, _0, _2);
	zephir_check_temp_parameter(_2);
	Z_UNSET_ISREF_P(data);
	zephir_check_call_status();
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std, renderScript) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *data = NULL;
	zval *path_param = NULL, *data_param = NULL, *ex = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &data_param);

	zephir_get_strval(path, path_param);
	zephir_get_arrval(data, data_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_implicit_flush", &_1, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_SELF(NULL, "outputscript", NULL, path, data);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", &_2);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(ex, EG(exception));
		if (zephir_instance_of_ev(ex, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", &_3);
			zephir_check_call_status();
			zephir_throw_exception_debug(ex, "nc/std.zep", 306 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_STRING("", 1);

}

