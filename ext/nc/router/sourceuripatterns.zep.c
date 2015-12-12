
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Router_SourceUriPatterns) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Router, SourceUriPatterns, nc, router_sourceuripatterns, nc_router_sourceuri_ce, nc_router_sourceuripatterns_method_entry, 0);

	zend_declare_property_null(nc_router_sourceuripatterns_ce, SL("typePatterns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_router_sourceuripatterns_ce, SL("replacements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_router_sourceuripatterns_ce, SL("DEFAULT_PATTERN"), "\\w+" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Router_SourceUriPatterns, __construct) {

	HashTable *_2$$3, *_12$$4;
	HashPosition _1$$3, _11$$4;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_18 = NULL, *_20 = NULL, *_24 = NULL, *_31 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rules = NULL, *typePatterns = NULL;
	zval *uri_param = NULL, *rules_param = NULL, *typePatterns_param = NULL, *callback = NULL, *prefix = NULL, *aliasGroup = NULL, *from = NULL, *to = NULL, *repls = NULL, *_0$$3, **_3$$3, *_4$$5 = NULL, *_5$$5 = NULL, **_13$$4, _8$$6 = zval_used_for_init, *_9$$6 = NULL, *_14$$7 = NULL, *_16$$7 = NULL, *_17$$7 = NULL, _19$$7 = zval_used_for_init, *_22$$7, *_23$$7 = NULL, *_25$$7, _26$$7 = zval_used_for_init, *_27$$8, *_28$$8 = NULL, *_29$$8 = NULL;
	zval *uri = NULL, *_7$$4 = NULL, *_15$$7 = NULL, *_21$$7 = NULL, *_30$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &uri_param, &rules_param, &typePatterns_param);

	zephir_get_strval(uri, uri_param);
	if (!rules_param) {
		ZEPHIR_INIT_VAR(rules);
		array_init(rules);
	} else {
		zephir_get_arrval(rules, rules_param);
	}
	if (!typePatterns_param) {
		ZEPHIR_INIT_VAR(typePatterns);
		array_init(typePatterns);
	} else {
		zephir_get_arrval(typePatterns, typePatterns_param);
	}


	ZEPHIR_INIT_VAR(repls);
	array_init(repls);
	if (zephir_fast_count_int(rules TSRMLS_CC) > 0) {
		zephir_update_property_this(this_ptr, SL("typePatterns"), typePatterns TSRMLS_CC);
		ZEPHIR_INIT_VAR(callback);
		zephir_create_array(callback, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(callback, this_ptr);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "onPregReplaceCallback", 1);
		zephir_array_fast_append(callback, _0$$3);
		zephir_is_iterable(rules, &_2$$3, &_1$$3, 0, 0, "nc/router/sourceuripatterns.zep", 49);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(prefix, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(aliasGroup, _3$$3);
			if (unlikely(Z_TYPE_P(aliasGroup) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(_4$$5);
				object_init_ex(_4$$5, nc_router_exception_ce);
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SV(_5$$5, "Invalid alias group for prefix: ", prefix);
				ZEPHIR_CALL_METHOD(NULL, _4$$5, "__construct", &_6, 2, _5$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4$$5, "nc/router/sourceuripatterns.zep", 21 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_get_strval(_7$$4, prefix);
			ZEPHIR_CPY_WRT(prefix, _7$$4);
			if (zephir_fast_strlen_ev(prefix) > 0) {
				ZEPHIR_SINIT_NVAR(_8$$6);
				ZVAL_STRING(&_8$$6, "#", 0);
				ZEPHIR_CALL_FUNCTION(&_9$$6, "preg_quote", &_10, 110, prefix, &_8$$6);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(prefix, _9$$6);
			}
			zephir_is_iterable(aliasGroup, &_12$$4, &_11$$4, 0, 0, "nc/router/sourceuripatterns.zep", 47);
			for (
			  ; zephir_hash_get_current_data_ex(_12$$4, (void**) &_13$$4, &_11$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_12$$4, &_11$$4)
			) {
				ZEPHIR_GET_HMKEY(from, _12$$4, _11$$4);
				ZEPHIR_GET_HVALUE(to, _13$$4);
				ZEPHIR_INIT_NVAR(_14$$7);
				array_init(_14$$7);
				zephir_update_property_this(this_ptr, SL("replacements"), _14$$7 TSRMLS_CC);
				zephir_get_strval(_15$$7, from);
				ZEPHIR_INIT_NVAR(_16$$7);
				ZVAL_STRING(_16$$7, "#/\\{(\\w+)(\\:\\w+)?\\}#", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_FUNCTION(&_17$$7, "preg_replace_callback", &_18, 111, _16$$7, callback, _15$$7);
				zephir_check_temp_parameter(_16$$7);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_19$$7);
				ZVAL_STRING(&_19$$7, "#^%s%s($|[/\\?])#", 0);
				ZEPHIR_CALL_FUNCTION(&from, "sprintf", &_20, 1, &_19$$7, prefix, _17$$7);
				zephir_check_call_status();
				zephir_get_strval(_21$$7, to);
				_22$$7 = zephir_fetch_nproperty_this(this_ptr, SL("replacements"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(&_23$$7, "strtr", &_24, 112, _21$$7, _22$$7);
				zephir_check_call_status();
				_25$$7 = zephir_fetch_nproperty_this(this_ptr, SL("replacements"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_19$$7);
				ZVAL_STRING(&_19$$7, "%s%s${%d}", 0);
				ZEPHIR_SINIT_NVAR(_26$$7);
				ZVAL_LONG(&_26$$7, (zephir_fast_count_int(_25$$7 TSRMLS_CC) + 1));
				ZEPHIR_CALL_FUNCTION(&to, "sprintf", &_20, 1, &_19$$7, prefix, _23$$7, &_26$$7);
				zephir_check_call_status();
				zephir_array_update_zval(&repls, from, &to, PH_COPY | PH_SEPARATE);
			}
		}
		if (zephir_fast_count_int(repls TSRMLS_CC) > 0) {
			ZEPHIR_INIT_VAR(_27$$8);
			zephir_array_keys(_27$$8, repls TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_28$$8, "array_values", NULL, 16, repls);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_29$$8, "preg_replace", NULL, 50, _27$$8, _28$$8, uri);
			zephir_check_call_status();
			zephir_get_strval(_30$$8, _29$$8);
			ZEPHIR_CPY_WRT(uri, _30$$8);
		}
	}
	ZEPHIR_CALL_PARENT(NULL, nc_router_sourceuripatterns_ce, this_ptr, "__construct", &_31, 106, uri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Router_SourceUriPatterns, onPregReplaceCallback) {

	zval *_8$$5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *matches_param = NULL, *name = NULL, *type = NULL, *pattern = NULL, *_0, *_1, *_4, _5, _6, *_7 = NULL, *_2$$4, *_3$$4, _9$$5 = zval_used_for_init, *_10$$5;
	zval *matches = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches_param);

	zephir_get_arrval(matches, matches_param);


	ZEPHIR_OBS_VAR(name);
	if (unlikely(!(zephir_array_isset_long_fetch(&name, matches, 1, 0 TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_router_exception_ce, "Invalid matches", "nc/router/sourceuripatterns.zep", 62);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "{", name, "}");
	ZEPHIR_CPY_WRT(name, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("replacements"), PH_NOISY_CC);
	if (unlikely(zephir_array_isset(_1, name))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_router_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Duplicate name: ", name);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/router/sourceuripatterns.zep", 67 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("replacements"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "${%d}", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, (zephir_fast_count_int(_4 TSRMLS_CC) + 1));
	ZEPHIR_CALL_FUNCTION(&_7, "sprintf", NULL, 1, &_5, &_6);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("replacements"), name, _7 TSRMLS_CC);
	while (1) {
		ZEPHIR_OBS_NVAR(type);
		if (!(zephir_array_isset_long_fetch(&type, matches, 2, 0 TSRMLS_CC))) {
			break;
		}
		zephir_get_strval(_8$$5, type);
		ZEPHIR_SINIT_NVAR(_9$$5);
		ZVAL_LONG(&_9$$5, 1);
		ZEPHIR_INIT_NVAR(type);
		zephir_substr(type, _8$$5, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("typePatterns"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&pattern, _10$$5, type, 1 TSRMLS_CC))) {
			break;
		}
		ZEPHIR_CONCAT_SVS(return_value, "/(", pattern, ")");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SSS(return_value, "/(", "\\w+", ")");
	RETURN_MM();

}

