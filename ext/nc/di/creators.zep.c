
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Di_Creators) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Di, Creators, nc, di_creators, nc_di_creatorabstract_ce, nc_di_creators_method_entry, 0);

	zend_declare_property_null(nc_di_creators_ce, SL("creators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_di_creators_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Nc_Di_Creators, __construct) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *creators_param = NULL, name, creator, *_0;
	zval creators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&creators);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&creator);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &creators_param);

	if (!creators_param) {
		ZEPHIR_INIT_VAR(&creators);
		array_init(&creators);
	} else {
		zephir_get_arrval(&creators, creators_param);
	}


	zephir_is_iterable(&creators, 0, "nc/di/creators.zep", 14);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&creators), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&creator);
		ZVAL_COPY(&creator, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_3, 0, &name, &creator);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&creator);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Creators, offsetSet) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *creator, creator_sub, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&creator_sub);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &creator);

	zephir_get_strval(&name, name_param);


	_0 = Z_TYPE_P(creator) != IS_OBJECT;
	if (!(_0)) {
		_0 = !((zephir_instance_of_ev(creator, nc_di_creatorabstract_ce TSRMLS_CC)));
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_di_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Invalid creator: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/di/creators.zep", 19 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("creators"), &name, creator TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Creators, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, creator, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&creator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_OBS_VAR(&creator);
	zephir_read_property(&_0, this_ptr, SL("creators"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&creator, &_0, &name, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_di_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Undefined creator: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/di/creators.zep", 30 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&creator);

}

PHP_METHOD(Nc_Di_Creators, offsetExists) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("creators"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

PHP_METHOD(Nc_Di_Creators, offsetUnset) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("creators"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di_Creators, getValidClassName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, creator, className, _0, _1$$3, *_2$$3, _3$$4;
	zval name, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&creator);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("creators"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		zephir_read_property(&_1$$3, this_ptr, SL("creators"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "nc/di/creators.zep", 57);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&creator);
			ZVAL_COPY(&creator, _2$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, &creator, "getvalidclassname", NULL, 0, &name);
			zephir_check_call_status();
			zephir_get_strval(&_4$$4, &_3$$4);
			ZEPHIR_CPY_WRT(&className, &_4$$4);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&className, "")) {
				RETURN_CCTOR(&className);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&creator);
	}
	RETURN_MM_STRING("");

}

