
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/math.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Nc_Std) {

	ZEPHIR_REGISTER_CLASS(Nc, Std, nc, std, nc_std_method_entry, 0);

	zend_declare_class_constant_string(nc_std_ce, SL("CHARSET"), "UTF-8" TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_ce, SL("CHAR_LIST"), "0123456789abcdefghijklmnopqrstuvwxyz" TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_ce, SL("IGNORE_ERROR"), "Nc\\Std::ignoreError" TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_ce, SL("THROW_ERROR"), "Nc\\Std::throwError" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Std, sizeToBytes) {

	unsigned char _6$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *size_param = NULL, *match = NULL, *_0, *_1 = NULL, *_2, _3, *_4$$3, *_7$$4, *_8$$5, *_9$$6, *_10$$7;
	zval *size = NULL, *unit = NULL, *_5$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &size_param);

	zephir_get_strval(size, size_param);


	ZEPHIR_INIT_VAR(match);
	ZVAL_NULL(match);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strtoupper(_2, size);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/^([\\d\\.]+)([KMGT])B?$/", 0);
	zephir_preg_match(_0, &_3, _2, match, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(_4$$3);
		zephir_array_fetch_long(&_4$$3, match, 2, PH_NOISY, "nc/std.zep", 17 TSRMLS_CC);
		zephir_get_strval(_5$$3, _4$$3);
		ZEPHIR_CPY_WRT(unit, _5$$3);
		_6$$3 = ZEPHIR_STRING_OFFSET(unit, 0);
		do {
			if (_6$$3 == 'T') {
				ZEPHIR_OBS_VAR(_7$$4);
				zephir_array_fetch_long(&_7$$4, match, 1, PH_NOISY, "nc/std.zep", 20 TSRMLS_CC);
				RETURN_MM_DOUBLE((1099511627776.0 * zephir_get_doubleval(_7$$4)));
			}
			if (_6$$3 == 'G') {
				ZEPHIR_OBS_VAR(_8$$5);
				zephir_array_fetch_long(&_8$$5, match, 1, PH_NOISY, "nc/std.zep", 22 TSRMLS_CC);
				RETURN_MM_DOUBLE((1073741824.0 * zephir_get_doubleval(_8$$5)));
			}
			if (_6$$3 == 'M') {
				ZEPHIR_OBS_VAR(_9$$6);
				zephir_array_fetch_long(&_9$$6, match, 1, PH_NOISY, "nc/std.zep", 24 TSRMLS_CC);
				RETURN_MM_DOUBLE((1048576.0 * zephir_get_doubleval(_9$$6)));
			}
			if (_6$$3 == 'K') {
				ZEPHIR_OBS_VAR(_10$$7);
				zephir_array_fetch_long(&_10$$7, match, 1, PH_NOISY, "nc/std.zep", 26 TSRMLS_CC);
				RETURN_MM_DOUBLE((1024.0 * zephir_get_doubleval(_10$$7)));
			}
		} while(0);

	}
	ZEPHIR_RETURN_CALL_FUNCTION("floatval", NULL, 84, size);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std, bytesToSize) {

	zend_bool _0;
	zval *size;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	long decimal;
	zval *bytes_param = NULL, *decimal_param = NULL, _1$$4 = zval_used_for_init, _2$$4, *_3$$4 = NULL, _5$$5 = zval_used_for_init, _6$$5, *_7$$5 = NULL, _8$$6 = zval_used_for_init, _9$$6, *_10$$6 = NULL, _11$$7 = zval_used_for_init, _12$$7, *_13$$7 = NULL, _14$$8 = zval_used_for_init, _15$$8, *_16$$8 = NULL;
	double bytes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &bytes_param, &decimal_param);

	bytes = zephir_get_doubleval(bytes_param);
	if (!decimal_param) {
		decimal = 3;
	} else {
		decimal = zephir_get_intval(decimal_param);
	}


	ZEPHIR_INIT_VAR(size);
	ZVAL_STRING(size, "0", 1);
	_0 = decimal < 0;
	if (!(_0)) {
		_0 = decimal > 6;
	}
	if (_0) {
		decimal = 3;
	}
	if (bytes > 1099511627776.0) {
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_STRING(&_1$$4, "%%0.%dfT", 0);
		ZEPHIR_SINIT_VAR(_2$$4);
		ZVAL_LONG(&_2$$4, decimal);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "sprintf", &_4, 1, &_1$$4, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_1$$4);
		ZVAL_DOUBLE(&_1$$4, zephir_safe_div_double_long(bytes, 1099511627776.0 TSRMLS_CC));
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_4, 1, _3$$4, &_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (bytes > 1073741824.0) {
		ZEPHIR_SINIT_VAR(_5$$5);
		ZVAL_STRING(&_5$$5, "%%0.%dfG", 0);
		ZEPHIR_SINIT_VAR(_6$$5);
		ZVAL_LONG(&_6$$5, decimal);
		ZEPHIR_CALL_FUNCTION(&_7$$5, "sprintf", &_4, 1, &_5$$5, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_DOUBLE(&_5$$5, zephir_safe_div_double_long(bytes, 1073741824.0 TSRMLS_CC));
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_4, 1, _7$$5, &_5$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (bytes > 1048576.0) {
		ZEPHIR_SINIT_VAR(_8$$6);
		ZVAL_STRING(&_8$$6, "%%0.%dfM", 0);
		ZEPHIR_SINIT_VAR(_9$$6);
		ZVAL_LONG(&_9$$6, decimal);
		ZEPHIR_CALL_FUNCTION(&_10$$6, "sprintf", &_4, 1, &_8$$6, &_9$$6);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_8$$6);
		ZVAL_DOUBLE(&_8$$6, zephir_safe_div_double_long(bytes, 1048576.0 TSRMLS_CC));
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_4, 1, _10$$6, &_8$$6);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (bytes > 1024.0) {
		ZEPHIR_SINIT_VAR(_11$$7);
		ZVAL_STRING(&_11$$7, "%%0.%dfK", 0);
		ZEPHIR_SINIT_VAR(_12$$7);
		ZVAL_LONG(&_12$$7, decimal);
		ZEPHIR_CALL_FUNCTION(&_13$$7, "sprintf", &_4, 1, &_11$$7, &_12$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_11$$7);
		ZVAL_DOUBLE(&_11$$7, zephir_safe_div_double_long(bytes, 1024.0 TSRMLS_CC));
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_4, 1, _13$$7, &_11$$7);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (bytes > 1.0) {
		ZEPHIR_SINIT_VAR(_14$$8);
		ZVAL_STRING(&_14$$8, "%%0.%dfB", 0);
		ZEPHIR_SINIT_VAR(_15$$8);
		ZVAL_LONG(&_15$$8, decimal);
		ZEPHIR_CALL_FUNCTION(&_16$$8, "sprintf", &_4, 1, &_14$$8, &_15$$8);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_14$$8);
		ZVAL_DOUBLE(&_14$$8, bytes);
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_4, 1, _16$$8, &_14$$8);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(size);

}

PHP_METHOD(Nc_Std, pascalCase) {

	long _0;
	zend_bool found, upper, _1$$3, _2$$3, _3$$3;
	char c = 0;
	zval *from_param = NULL;
	zval *from = NULL, *to;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &from_param);

	zephir_get_strval(from, from_param);


	ZEPHIR_INIT_VAR(to);
	ZVAL_EMPTY_STRING(to);
	found = 0;
	upper = 1;
	for (_0 = 0; _0 < Z_STRLEN_P(from); _0++) {
		c = ZEPHIR_STRING_OFFSET(from, _0);
		_1$$3 = c >= '0';
		if (_1$$3) {
			_1$$3 = c <= '9';
		}
		if (_1$$3) {
			if (found) {
				zephir_concat_self_char(&to, c TSRMLS_CC);
			}
			continue;
		}
		_2$$3 = c >= 'a';
		if (_2$$3) {
			_2$$3 = c <= 'z';
		}
		if (_2$$3) {
			if (upper) {
				upper = 0;
				c -= 32;
			}
			zephir_concat_self_char(&to, c TSRMLS_CC);
			found = 1;
			continue;
		}
		_3$$3 = c >= 'A';
		if (_3$$3) {
			_3$$3 = c <= 'Z';
		}
		if (_3$$3) {
			if (upper) {
				upper = 0;
			} else {
				c += 32;
			}
			zephir_concat_self_char(&to, c TSRMLS_CC);
			found = 1;
			continue;
		}
		if (found) {
			upper = 1;
		}
	}
	RETURN_CTOR(to);

}

PHP_METHOD(Nc_Std, camelCase) {

	long _0;
	zend_bool found, upper, _1$$3, _2$$3, _3$$3;
	char c = 0;
	zval *from_param = NULL;
	zval *from = NULL, *to;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &from_param);

	zephir_get_strval(from, from_param);


	ZEPHIR_INIT_VAR(to);
	ZVAL_EMPTY_STRING(to);
	found = 0;
	upper = 0;
	for (_0 = 0; _0 < Z_STRLEN_P(from); _0++) {
		c = ZEPHIR_STRING_OFFSET(from, _0);
		_1$$3 = c >= '0';
		if (_1$$3) {
			_1$$3 = c <= '9';
		}
		if (_1$$3) {
			if (found) {
				zephir_concat_self_char(&to, c TSRMLS_CC);
			}
			continue;
		}
		_2$$3 = c >= 'a';
		if (_2$$3) {
			_2$$3 = c <= 'z';
		}
		if (_2$$3) {
			if (upper) {
				upper = 0;
				c -= 32;
			}
			zephir_concat_self_char(&to, c TSRMLS_CC);
			found = 1;
			continue;
		}
		_3$$3 = c >= 'A';
		if (_3$$3) {
			_3$$3 = c <= 'Z';
		}
		if (_3$$3) {
			if (upper) {
				upper = 0;
			} else {
				c += 32;
			}
			zephir_concat_self_char(&to, c TSRMLS_CC);
			found = 1;
			continue;
		}
		if (found) {
			upper = 1;
		}
	}
	RETURN_CTOR(to);

}

PHP_METHOD(Nc_Std, normalCase) {

	long _0;
	zend_bool found, _1$$3, _2$$3, _3$$3, _4$$3;
	char c = 0;
	zval *from_param = NULL, *sep_param = NULL;
	zval *from = NULL, *sep = NULL, *to;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &sep_param);

	zephir_get_strval(from, from_param);
	if (!sep_param) {
		ZEPHIR_INIT_VAR(sep);
		ZVAL_STRING(sep, "-", 1);
	} else {
		zephir_get_strval(sep, sep_param);
	}


	ZEPHIR_INIT_VAR(to);
	ZVAL_EMPTY_STRING(to);
	found = 0;
	for (_0 = 0; _0 < Z_STRLEN_P(from); _0++) {
		c = ZEPHIR_STRING_OFFSET(from, _0);
		_1$$3 = c >= '0';
		if (_1$$3) {
			_1$$3 = c <= '9';
		}
		_2$$3 = _1$$3;
		if (!(_2$$3)) {
			_3$$3 = c >= 'a';
			if (_3$$3) {
				_3$$3 = c <= 'z';
			}
			_2$$3 = _3$$3;
		}
		if (_2$$3) {
			zephir_concat_self_char(&to, c TSRMLS_CC);
			found = 1;
			continue;
		}
		_4$$3 = c >= 'A';
		if (_4$$3) {
			_4$$3 = c <= 'Z';
		}
		if (_4$$3) {
			if (found) {
				zephir_concat_self(&to, sep TSRMLS_CC);
			}
			c += 32;
			zephir_concat_self_char(&to, c TSRMLS_CC);
			found = 1;
			continue;
		}
	}
	RETURN_CTOR(to);

}

PHP_METHOD(Nc_Std, uuid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *salt_param = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3 = NULL, *_4, _5, _6, *_7 = NULL;
	zval *salt = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &salt_param);

	if (!salt_param) {
		ZEPHIR_INIT_VAR(salt);
		ZVAL_STRING(salt, "", 1);
	} else {
		zephir_get_strval(salt, salt_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "mt_rand", NULL, 85);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 86, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, salt);
	ZEPHIR_CALL_FUNCTION(&_3, "sha1", NULL, 87, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	zephir_time(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "%04x", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, (zephir_get_intval(_4) & 0xffff));
	ZEPHIR_CALL_FUNCTION(&_7, "sprintf", NULL, 1, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, _3, _7);
	RETURN_MM();

}

PHP_METHOD(Nc_Std, randString) {

	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *charList = NULL, *result;
	zval *len_param = NULL, *charList_param = NULL, *_0 = NULL, _1, *_2 = NULL, _3$$5 = zval_used_for_init, _4$$5 = zval_used_for_init, _5$$5 = zval_used_for_init, _6$$5 = zval_used_for_init, _7$$5 = zval_used_for_init, *_8$$5 = NULL;
	long len, maxIndex = 0;

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
	ZVAL_EMPTY_STRING(result);
	if (unlikely(len < 1)) {
		RETURN_MM_STRING("", 1);
	}
	if (zephir_fast_strlen_ev(charList) < 1) {
		ZEPHIR_INIT_NVAR(charList);
		ZVAL_STRING(charList, "0123456789abcdefghijklmnopqrstuvwxyz", 1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "UTF-8", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strlen", NULL, 59, charList, &_1);
	zephir_check_call_status();
	maxIndex = (zephir_get_intval(_2) - 1);
	while (1) {
		if (!(len)) {
			break;
		}
		len--;
		ZEPHIR_SINIT_NVAR(_3$$5);
		ZVAL_LONG(&_3$$5, 0);
		ZEPHIR_SINIT_NVAR(_4$$5);
		ZVAL_LONG(&_4$$5, maxIndex);
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_LONG(&_5$$5, zephir_mt_rand(zephir_get_intval(&_3$$5), zephir_get_intval(&_4$$5) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_6$$5);
		ZVAL_LONG(&_6$$5, 1);
		ZEPHIR_SINIT_NVAR(_7$$5);
		ZVAL_STRING(&_7$$5, "UTF-8", 0);
		ZEPHIR_CALL_FUNCTION(&_8$$5, "mb_substr", &_9, 62, charList, &_5$$5, &_6$$5, &_7$$5);
		zephir_check_call_status();
		zephir_concat_self(&result, _8$$5 TSRMLS_CC);
	}
	RETURN_CTOR(result);

}

PHP_METHOD(Nc_Std, tr) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *k = NULL, *v = NULL, *r = NULL, **_2, *_4$$3 = NULL;
	zval *message = NULL, *_3$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(r);
	array_init(r);
	zephir_is_iterable(context, &_1, &_0, 0, 0, "nc/std.zep", 204);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_get_strval(_3$$3, v);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVS(_4$$3, "{", k, "}");
		zephir_array_update_zval(&r, _4$$3, &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 88, message, r);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std, valueAt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool noException, _0;
	zval *key = NULL, *_2$$4;
	zval *arr_param = NULL, *key_param = NULL, *defaultValue = NULL, *noException_param = NULL, *value = NULL, *_1$$4;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &arr_param, &key_param, &defaultValue, &noException_param);

	zephir_get_arrval(arr, arr_param);
	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!noException_param) {
		noException = 0;
	} else {
		noException = zephir_get_boolval(noException_param);
	}


	ZEPHIR_OBS_VAR(value);
	if (zephir_array_isset_fetch(&value, arr, key, 0 TSRMLS_CC)) {
		RETURN_CCTOR(value);
	}
	_0 = Z_TYPE_P(defaultValue) == IS_NULL;
	if (_0) {
		_0 = !noException;
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, nc_exception_ce);
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SV(_2$$4, "Missing value at: ", key);
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 2, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "nc/std.zep", 216 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Nc_Std, valueOf) {

	zend_bool _3$$3;
	HashTable *_1;
	HashPosition _0;
	zval *key = NULL;
	zval *arr_param = NULL, *key_param = NULL, *defaultValue = NULL, *parts = NULL, *part = NULL, *returnValue = NULL, *tmpValue = NULL, **_2;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &arr_param, &key_param, &defaultValue);

	zephir_get_arrval(arr, arr_param);
	zephir_get_strval(key, key_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL("."), key, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(returnValue, arr);
	zephir_is_iterable(parts, &_1, &_0, 0, 0, "nc/std.zep", 236);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(part, _2);
		_3$$3 = Z_TYPE_P(returnValue) != IS_ARRAY;
		if (!(_3$$3)) {
			_3$$3 = !(zephir_array_isset_fetch(&tmpValue, returnValue, part, 1 TSRMLS_CC));
		}
		if (_3$$3) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		ZEPHIR_CPY_WRT(returnValue, tmpValue);
	}
	RETURN_CCTOR(returnValue);

}

PHP_METHOD(Nc_Std, indexedData) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *indexKey = NULL;
	zval *data_param = NULL, *indexKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *indexValue = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_7$$5 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &indexKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(indexKey, indexKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 254);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3$$4);
			object_init_ex(_3$$4, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SV(_4$$4, "Invalid item type, array required: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", &_5, 2, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "nc/std.zep", 245 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_6$$5);
			object_init_ex(_6$$5, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_7$$5);
			ZEPHIR_CONCAT_SV(_7$$5, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", &_5, 2, _7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$5, "nc/std.zep", 248 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&arr, indexValue, &v, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, indexedValues) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *indexKey = NULL, *valueKey = NULL;
	zval *data_param = NULL, *indexKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *indexValue = NULL, *valueValue = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_8$$6 = NULL, *_9$$6 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &indexKey_param, &valueKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(indexKey, indexKey_param);
	zephir_get_strval(valueKey, valueKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 275);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3$$4);
			object_init_ex(_3$$4, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SV(_4$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", &_5, 2, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "nc/std.zep", 263 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_6$$5);
			object_init_ex(_6$$5, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_7$$5);
			ZEPHIR_CONCAT_SV(_7$$5, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", &_5, 2, _7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$5, "nc/std.zep", 266 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_8$$6);
			object_init_ex(_8$$6, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_9$$6);
			ZEPHIR_CONCAT_SV(_9$$6, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _8$$6, "__construct", &_5, 2, _9$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8$$6, "nc/std.zep", 269 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&arr, indexValue, &valueValue, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, groupedData) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupKey = NULL;
	zval *data_param = NULL, *groupKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *groupValue = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_7$$5 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &groupKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(groupKey, groupKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 293);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3$$4);
			object_init_ex(_3$$4, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SV(_4$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", &_5, 2, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "nc/std.zep", 284 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_6$$5);
			object_init_ex(_6$$5, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_7$$5);
			ZEPHIR_CONCAT_SV(_7$$5, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", &_5, 2, _7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$5, "nc/std.zep", 287 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &v TSRMLS_CC, SL("za"), 2, groupValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, groupedValues) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupKey = NULL, *valueKey = NULL;
	zval *data_param = NULL, *groupKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *groupValue = NULL, *valueValue = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_8$$6 = NULL, *_9$$6 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &groupKey_param, &valueKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(valueKey, valueKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 314);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3$$4);
			object_init_ex(_3$$4, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SV(_4$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", &_5, 2, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "nc/std.zep", 302 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_6$$5);
			object_init_ex(_6$$5, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_7$$5);
			ZEPHIR_CONCAT_SV(_7$$5, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", &_5, 2, _7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$5, "nc/std.zep", 305 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_8$$6);
			object_init_ex(_8$$6, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_9$$6);
			ZEPHIR_CONCAT_SV(_9$$6, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _8$$6, "__construct", &_5, 2, _9$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8$$6, "nc/std.zep", 308 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &valueValue TSRMLS_CC, SL("za"), 2, groupValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, groupIndexedData) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupKey = NULL, *indexKey = NULL;
	zval *data_param = NULL, *groupKey_param = NULL, *indexKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *groupValue = NULL, *indexValue = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_8$$6 = NULL, *_9$$6 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &groupKey_param, &indexKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(indexKey, indexKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 335);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3$$4);
			object_init_ex(_3$$4, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SV(_4$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", &_5, 2, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "nc/std.zep", 323 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_6$$5);
			object_init_ex(_6$$5, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_7$$5);
			ZEPHIR_CONCAT_SV(_7$$5, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", &_5, 2, _7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$5, "nc/std.zep", 326 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_8$$6);
			object_init_ex(_8$$6, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_9$$6);
			ZEPHIR_CONCAT_SV(_9$$6, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _8$$6, "__construct", &_5, 2, _9$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8$$6, "nc/std.zep", 329 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &v TSRMLS_CC, SL("zz"), 2, groupValue, indexValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, groupIndexedValues) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupKey = NULL, *indexKey = NULL, *valueKey = NULL;
	zval *data_param = NULL, *groupKey_param = NULL, *indexKey_param = NULL, *valueKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *groupValue = NULL, *indexValue = NULL, *valueValue = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_8$$6 = NULL, *_9$$6 = NULL, *_10$$7 = NULL, *_11$$7 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &data_param, &groupKey_param, &indexKey_param, &valueKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(groupKey, groupKey_param);
	zephir_get_strval(indexKey, indexKey_param);
	zephir_get_strval(valueKey, valueKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 359);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3$$4);
			object_init_ex(_3$$4, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SV(_4$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", &_5, 2, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "nc/std.zep", 344 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(groupValue);
		if (unlikely(!(zephir_array_isset_fetch(&groupValue, v, groupKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_6$$5);
			object_init_ex(_6$$5, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_7$$5);
			ZEPHIR_CONCAT_SV(_7$$5, "Cannot find value of group at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", &_5, 2, _7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$5, "nc/std.zep", 347 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(indexValue);
		if (unlikely(!(zephir_array_isset_fetch(&indexValue, v, indexKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_8$$6);
			object_init_ex(_8$$6, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_9$$6);
			ZEPHIR_CONCAT_SV(_9$$6, "Cannot find value of index at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _8$$6, "__construct", &_5, 2, _9$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8$$6, "nc/std.zep", 350 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(valueValue);
		if (unlikely(!(zephir_array_isset_fetch(&valueValue, v, valueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_10$$7);
			object_init_ex(_10$$7, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_11$$7);
			ZEPHIR_CONCAT_SV(_11$$7, "Cannot find value of value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _10$$7, "__construct", &_5, 2, _11$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_10$$7, "nc/std.zep", 353 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&arr, &valueValue TSRMLS_CC, SL("zz"), 2, groupValue, indexValue);
	}
	RETURN_CCTOR(arr);

}

PHP_METHOD(Nc_Std, uniqueValues) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uniqueKey = NULL;
	zval *data_param = NULL, *uniqueKey_param = NULL, *k = NULL, *v = NULL, *arr = NULL, *uniqueValue = NULL, **_2, *_3$$4 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_7$$5 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &uniqueKey_param);

	zephir_get_arrval(data, data_param);
	zephir_get_strval(uniqueKey, uniqueKey_param);


	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/std.zep", 377);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		if (unlikely(Z_TYPE_P(v) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3$$4);
			object_init_ex(_3$$4, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SV(_4$$4, "Invalid item type, array required at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", &_5, 2, _4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$4, "nc/std.zep", 368 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(uniqueValue);
		if (unlikely(!(zephir_array_isset_fetch(&uniqueValue, v, uniqueKey, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_NVAR(_6$$5);
			object_init_ex(_6$$5, nc_exception_ce);
			ZEPHIR_INIT_LNVAR(_7$$5);
			ZEPHIR_CONCAT_SV(_7$$5, "Cannot find value of unique at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", &_5, 2, _7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$5, "nc/std.zep", 371 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&arr, uniqueValue, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	}
	zephir_array_keys(return_value, arr TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Nc_Std, newInstanceOf) {

	zend_class_entry *_1$$3, *_4$$5, *_7$$6, *_11$$7, *_16$$8, *_22$$9;
	long c = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *className_param = NULL, *args_param = NULL, *a = NULL, *_28, *_0$$3 = NULL, *_2$$4, *_3$$5 = NULL, *_5$$5, *_6$$6 = NULL, *_8$$6, *_9$$6, *_10$$7 = NULL, *_12$$7, *_13$$7, *_14$$7, *_15$$8 = NULL, *_17$$8, *_18$$8, *_19$$8, *_20$$8, *_21$$9 = NULL, *_23$$9, *_24$$9, *_25$$9, *_26$$9, *_27$$9;
	zval *className = NULL, *_29;

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
		zephir_fetch_safe_class(_0$$3, className);
			_1$$3 = zend_fetch_class(Z_STRVAL_P(_0$$3), Z_STRLEN_P(_0$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _1$$3);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	if (c > 5) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 13, className);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_2$$4, "newinstanceargs", NULL, 15, args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&a, "array_values", NULL, 24, args);
	zephir_check_call_status();
	do {
		if (c == 1) {
			zephir_fetch_safe_class(_3$$5, className);
				_4$$5 = zend_fetch_class(Z_STRVAL_P(_3$$5), Z_STRLEN_P(_3$$5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _4$$5);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_5$$5, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 396 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _5$$5);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 2) {
			zephir_fetch_safe_class(_6$$6, className);
				_7$$6 = zend_fetch_class(Z_STRVAL_P(_6$$6), Z_STRLEN_P(_6$$6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _7$$6);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_8$$6, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 398 TSRMLS_CC);
				zephir_array_fetch_long(&_9$$6, a, 1, PH_NOISY | PH_READONLY, "nc/std.zep", 398 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _8$$6, _9$$6);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 3) {
			zephir_fetch_safe_class(_10$$7, className);
				_11$$7 = zend_fetch_class(Z_STRVAL_P(_10$$7), Z_STRLEN_P(_10$$7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _11$$7);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_12$$7, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 400 TSRMLS_CC);
				zephir_array_fetch_long(&_13$$7, a, 1, PH_NOISY | PH_READONLY, "nc/std.zep", 400 TSRMLS_CC);
				zephir_array_fetch_long(&_14$$7, a, 2, PH_NOISY | PH_READONLY, "nc/std.zep", 400 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _12$$7, _13$$7, _14$$7);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 4) {
			zephir_fetch_safe_class(_15$$8, className);
				_16$$8 = zend_fetch_class(Z_STRVAL_P(_15$$8), Z_STRLEN_P(_15$$8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _16$$8);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_17$$8, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 402 TSRMLS_CC);
				zephir_array_fetch_long(&_18$$8, a, 1, PH_NOISY | PH_READONLY, "nc/std.zep", 402 TSRMLS_CC);
				zephir_array_fetch_long(&_19$$8, a, 2, PH_NOISY | PH_READONLY, "nc/std.zep", 402 TSRMLS_CC);
				zephir_array_fetch_long(&_20$$8, a, 3, PH_NOISY | PH_READONLY, "nc/std.zep", 402 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _17$$8, _18$$8, _19$$8, _20$$8);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 5) {
			zephir_fetch_safe_class(_21$$9, className);
				_22$$9 = zend_fetch_class(Z_STRVAL_P(_21$$9), Z_STRLEN_P(_21$$9), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _22$$9);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_23$$9, a, 0, PH_NOISY | PH_READONLY, "nc/std.zep", 404 TSRMLS_CC);
				zephir_array_fetch_long(&_24$$9, a, 1, PH_NOISY | PH_READONLY, "nc/std.zep", 404 TSRMLS_CC);
				zephir_array_fetch_long(&_25$$9, a, 2, PH_NOISY | PH_READONLY, "nc/std.zep", 404 TSRMLS_CC);
				zephir_array_fetch_long(&_26$$9, a, 3, PH_NOISY | PH_READONLY, "nc/std.zep", 404 TSRMLS_CC);
				zephir_array_fetch_long(&_27$$9, a, 4, PH_NOISY | PH_READONLY, "nc/std.zep", 404 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _23$$9, _24$$9, _25$$9, _26$$9, _27$$9);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(_28);
	object_init_ex(_28, nc_exception_ce);
	ZEPHIR_INIT_VAR(_29);
	ZEPHIR_CONCAT_SV(_29, "Fail to fetch a new instance of class: ", className);
	ZEPHIR_CALL_METHOD(NULL, _28, "__construct", NULL, 2, _29);
	zephir_check_call_status();
	zephir_throw_exception_debug(_28, "nc/std.zep", 407 TSRMLS_CC);
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
	zval *s = NULL, *f = NULL, *l = NULL;
	zval *n_param = NULL, *s_param = NULL, *f_param = NULL, *l_param = NULL, *context_param = NULL, *_0, _1, *_2 = NULL, *_3;
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
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "%s (%s:%d)", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_1, s, f, l);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, n);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 89, _2, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "nc/std.zep", 417 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Nc_Std, outputScript) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *path_param = NULL, *data_param = NULL, *_0$$3, *_2, *_3;
	zval *path = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &data_param);

	zephir_get_strval(path, path_param);
	zephir_get_arrval(data, data_param);


	if (unlikely(!((zephir_file_exists(path TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, nc_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, "Cannot find script path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "nc/std.zep", 423 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 4);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_MAKE_REF(data);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 90, data, _2, _3);
	zephir_check_temp_parameter(_3);
	ZEPHIR_UNREF(data);
	zephir_check_call_status();
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std, renderScript) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *path_param = NULL, *data_param = NULL, *ex = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &data_param);

	zephir_get_strval(path, path_param);
	zephir_get_arrval(data, data_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 25);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_implicit_flush", NULL, 26, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_SELF(NULL, "outputscript", NULL, 0, path, data);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 27);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(ex, EG(exception));
		if (zephir_instance_of_ev(ex, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 28);
			zephir_check_call_status();
			zephir_throw_exception_debug(ex, "nc/std.zep", 442 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_STRING("", 1);

}

