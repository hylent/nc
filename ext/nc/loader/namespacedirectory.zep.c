
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Loader_NamespaceDirectory) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Loader, NamespaceDirectory, nc, loader_namespacedirectory, nc_loader_loaderabstract_ce, nc_loader_namespacedirectory_method_entry, 0);

	zend_declare_property_null(nc_loader_namespacedirectory_ce, SL("namespaceDirectories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_loader_namespacedirectory_ce, SL("delimiter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_loader_namespacedirectory_ce, SL("DEFAULT_DELIMITER"), "\\");

	return SUCCESS;

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval delimiter;
	zval *namespaceDirectories_param = NULL, *delimiter_param = NULL;
	zval namespaceDirectories;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&namespaceDirectories);
	ZVAL_UNDEF(&delimiter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &namespaceDirectories_param, &delimiter_param);

	if (!namespaceDirectories_param) {
		ZEPHIR_INIT_VAR(&namespaceDirectories);
		array_init(&namespaceDirectories);
	} else {
		zephir_get_arrval(&namespaceDirectories, namespaceDirectories_param);
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_STRING(&delimiter, "\\");
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}


	if (zephir_fast_count_int(&namespaceDirectories TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setnamespacedirectories", NULL, 0, &namespaceDirectories);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("delimiter"), &delimiter);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, setNamespaceDirectories) {

	zend_string *_2;
	zend_ulong _1;
	zval *namespaceDirectories_param = NULL, n, d, *_0, _3$$3;
	zval namespaceDirectories;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&namespaceDirectories);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&d);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceDirectories_param);

	zephir_get_arrval(&namespaceDirectories, namespaceDirectories_param);


	zephir_is_iterable(&namespaceDirectories, 0, "nc/loader/namespacedirectory.zep", 26);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&namespaceDirectories), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&n);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&n, _2);
		} else {
			ZVAL_LONG(&n, _1);
		}
		ZEPHIR_INIT_NVAR(&d);
		ZVAL_COPY(&d, _0);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_fast_strtolower(&_3$$3, &n);
		zephir_update_property_array(this_ptr, SL("namespaceDirectories"), &_3$$3, &d TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&d);
	ZEPHIR_INIT_NVAR(&n);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, setNamespaceDirectory) {

	zval *ns_param = NULL, *dir_param = NULL, _0, _1;
	zval ns, dir;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns_param, &dir_param);

	zephir_get_strval(&ns, ns_param);
	zephir_get_strval(&dir, dir_param);


	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &ns);
	zephir_update_property_array(this_ptr, SL("namespaceDirectories"), &_1, &dir TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, hasNamespace) {

	zval *ns_param = NULL, _0, _1, _2;
	zval ns;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ns_param);

	zephir_get_strval(&ns, ns_param);


	zephir_read_property(&_0, this_ptr, SL("namespaceDirectories"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strtolower(&_2, &ns);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_2));

}

PHP_METHOD(Nc_Loader_NamespaceDirectory, findPath) {

	zend_bool found, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *name_param = NULL, match, pos, dir, _0, _1$$3, _4$$3, _5$$3, _6$$3, _7$$6, _8$$6, _9$$6, _10$$6, _11$$6;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&match);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	found = 0;
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &name);
	ZEPHIR_CPY_WRT(&match, &_0);
	while (1) {
		zephir_read_property(&_1$$3, this_ptr, SL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_2, 77, &match, &_1$$3);
		zephir_check_call_status();
		_3$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&pos);
		if (!(_3$$3)) {
			_3$$3 = ZEPHIR_LT_LONG(&pos, 1);
		}
		if (_3$$3) {
			break;
		}
		ZVAL_LONG(&_4$$3, 0);
		ZEPHIR_INIT_NVAR(&_5$$3);
		zephir_substr(&_5$$3, &match, 0 , zephir_get_intval(&pos), 0);
		ZEPHIR_CPY_WRT(&match, &_5$$3);
		ZEPHIR_OBS_NVAR(&dir);
		zephir_read_property(&_6$$3, this_ptr, SL("namespaceDirectories"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_fetch(&dir, &_6$$3, &match, 0 TSRMLS_CC)) {
			found = 1;
			break;
		}
	}
	if (found) {
		ZVAL_LONG(&_7$$6, (zephir_get_numberval(&pos) + 1));
		ZEPHIR_INIT_VAR(&_8$$6);
		zephir_substr(&_8$$6, &name, zephir_get_intval(&_7$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_read_property(&_9$$6, this_ptr, SL("delimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_10$$6);
		ZVAL_STRING(&_10$$6, "/");
		ZEPHIR_CALL_FUNCTION(&_11$$6, "strtr", NULL, 78, &_8$$6, &_9$$6, &_10$$6);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSVS(return_value, &dir, "/", &_11$$6, ".php");
		RETURN_MM();
	}
	RETURN_MM_STRING("");

}

