
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


ZEPHIR_INIT_CLASS(Nc_Std_StdAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, StdAbstract, nc, std_stdabstract, NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_std_stdabstract_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_std_stdabstract_ce, SL("identifier"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

