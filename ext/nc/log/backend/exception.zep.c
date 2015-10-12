
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Log_Backend_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Log\\Backend, Exception, nc, log_backend_exception, nc_log_exception_ce, NULL, 0);

	return SUCCESS;

}

