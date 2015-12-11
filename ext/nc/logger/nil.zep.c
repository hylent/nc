
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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Logger_Nil) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Logger, Nil, nc, logger_nil, nc_logger_loggerabstract_ce, nc_logger_nil_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Logger_Nil, log) {

	zval *context = NULL;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL;
	zval *level = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &context_param);

	zephir_get_strval(level, level_param);
	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	RETURN_MM_NULL();

}

