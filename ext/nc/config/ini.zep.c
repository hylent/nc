
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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Config_Ini) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Config, Ini, nc, config_ini, nc_config_filesystemabstract_ce, nc_config_ini_method_entry, 0);

	zend_declare_property_string(nc_config_ini_ce, SL("fileExtension"), "ini", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Config_Ini, readFromPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, __$true, _0;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_ini_file", NULL, 44, &path, &__$true, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

