
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
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Mvc_ContextCli) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Mvc, ContextCli, nc, mvc_contextcli, nc_mvc_contextabstract_ce, nc_mvc_contextcli_method_entry, 0);

	zend_declare_property_null(nc_mvc_contextcli_ce, SL("paramMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Mvc_ContextCli, __construct) {

	zval _4$$4, _9$$4, _14$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, args, arg, pos, _0, _1, _2, *_3$$3, _5$$4, _6$$4, _7$$4, _8$$4, _10$$4, _11$$6, _12$$7, _13$$7, _15$$7, _16$$7;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&arg);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_14$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	zephir_update_property_zval(this_ptr, SL("serverVars"), &_SERVER);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("argVector"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("paramMap"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "argv");
	ZEPHIR_CALL_METHOD(&args, this_ptr, "getservervar", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&args) == IS_ARRAY) {
		ZEPHIR_MAKE_REF(&args);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 4, &args);
		ZEPHIR_UNREF(&args);
		zephir_check_call_status();
		zephir_is_iterable(&args, 0, "nc/mvc/contextcli.zep", 35);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&args), _3$$3)
		{
			ZEPHIR_INIT_NVAR(&arg);
			ZVAL_COPY(&arg, _3$$3);
			zephir_get_strval(&_4$$4, &arg);
			ZEPHIR_CPY_WRT(&arg, &_4$$4);
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "--");
			ZEPHIR_INIT_NVAR(&_6$$4);
			zephir_fast_strpos(&_6$$4, &arg, &_5$$4, 0 );
			if (!ZEPHIR_IS_LONG_IDENTICAL(&_6$$4, 0)) {
				zephir_update_property_array_append(this_ptr, SL("argVector"), &arg TSRMLS_CC);
				continue;
			}
			ZVAL_LONG(&_7$$4, 2);
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_substr(&_8$$4, &arg, 2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_get_strval(&_9$$4, &_8$$4);
			ZEPHIR_CPY_WRT(&arg, &_9$$4);
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "=");
			ZEPHIR_INIT_NVAR(&pos);
			zephir_fast_strpos(&pos, &arg, &_10$$4, 0 );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "");
				zephir_update_property_array(this_ptr, SL("paramMap"), &arg, &_11$$6 TSRMLS_CC);
			} else {
				ZVAL_LONG(&_12$$7, (zephir_get_numberval(&pos) + 1));
				ZEPHIR_INIT_NVAR(&_13$$7);
				zephir_substr(&_13$$7, &arg, zephir_get_intval(&_12$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				zephir_get_strval(&_14$$7, &_13$$7);
				ZVAL_LONG(&_15$$7, 0);
				ZEPHIR_INIT_NVAR(&_16$$7);
				zephir_substr(&_16$$7, &arg, 0 , zephir_get_intval(&pos), 0);
				zephir_update_property_array(this_ptr, SL("paramMap"), &_16$$7, &_14$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&arg);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Mvc_ContextCli, getRoutingNames) {

	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cli");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

PHP_METHOD(Nc_Mvc_ContextCli, getParamMap) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "paramMap");

}

PHP_METHOD(Nc_Mvc_ContextCli, getParam) {

	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("paramMap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

