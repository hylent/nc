
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


ZEPHIR_INIT_CLASS(Nc_Di_CreatorClassNamespace) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Di, CreatorClassNamespace, nc, di_creatorclassnamespace, nc_di_creatorclassprefix_ce, nc_di_creatorclassnamespace_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Di_CreatorClassNamespace, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *classNamespace_param = NULL;
	zval classNamespace, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classNamespace);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classNamespace_param);

	zephir_get_strval(&classNamespace, classNamespace_param);


	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &classNamespace, "\\");
	ZEPHIR_CALL_PARENT(NULL, nc_di_creatorclassnamespace_ce, getThis(), "__construct", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

