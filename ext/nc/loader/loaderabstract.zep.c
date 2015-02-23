
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Loader_LoaderAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Loader, LoaderAbstract, nc, loader_loaderabstract, nc_loader_loaderabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(nc_loader_loaderabstract_ce TSRMLS_CC, 1, nc_loader_loaderinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Loader_LoaderAbstract, register) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_register", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Loader_LoaderAbstract, unregister) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_unregister", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

