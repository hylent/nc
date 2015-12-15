
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Factory_Namespaced) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Factory, Namespaced, nc, factory_namespaced, nc_factory_prefixed_ce, nc_factory_namespaced_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Factory_Namespaced, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *ns_param = NULL;
	zval *ns = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ns_param);

	zephir_get_strval(ns, ns_param);


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, ns, "\\");
	ZEPHIR_CALL_PARENT(NULL, nc_factory_namespaced_ce, this_ptr, "__construct", &_0, 51, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

