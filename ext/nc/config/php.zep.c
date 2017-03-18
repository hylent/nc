
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
#include "kernel/require.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Config_Php) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Config, Php, nc, config_php, nc_config_filesystemabstract_ce, nc_config_php_method_entry, 0);

	zend_declare_property_string(nc_config_php_ce, SL("fileExtension"), "php", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Config_Php, readFromPath) {

	zval *path_param = NULL, _0;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_0);
	if (zephir_require_zval_ret(&_0, &path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(_0);

}

