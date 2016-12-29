
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


ZEPHIR_INIT_CLASS(Nc_Queue_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Queue, Exception, nc, queue_exception, nc_exception_ce, NULL, 0);

	zephir_declare_class_constant_long(nc_queue_exception_ce, SL("PUT_FAILURE"), 1);

	zephir_declare_class_constant_long(nc_queue_exception_ce, SL("RESERVE_FAILURE"), 2);

	zephir_declare_class_constant_long(nc_queue_exception_ce, SL("RESERVE_INVALID_TTR"), 3);

	zephir_declare_class_constant_long(nc_queue_exception_ce, SL("DELETE_FAILURE"), 4);

	return SUCCESS;

}

