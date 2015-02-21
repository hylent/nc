
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Backend_StorageBackendAdapter) {

	ZEPHIR_REGISTER_CLASS(Nc\\Storage\\Backend, StorageBackendAdapter, nc, storage_backend_storagebackendadapter, nc_storage_backend_storagebackendadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_storage_backend_storagebackendadapter_ce, SL("storageNamePolicy"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_storage_backend_storagebackendadapter_ce TSRMLS_CC, 1, nc_storage_backend_storagebackendinterface_ce);
	zend_class_implements(nc_storage_backend_storagebackendadapter_ce TSRMLS_CC, 1, nc_storage_namepolicy_storagenamepolicyawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Storage_Backend_StorageBackendAdapter, setStorageNamePolicy) {

	zval *storageNamePolicy;

	zephir_fetch_params(0, 1, 0, &storageNamePolicy);



	if (!(zephir_instance_of_ev(storageNamePolicy, nc_storage_namepolicy_storagenamepolicyinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'storageNamePolicy' must be an instance of 'Nc\\Storage\\NamePolicy\\StorageNamePolicyInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("storageNamePolicy"), storageNamePolicy TSRMLS_CC);

}

PHP_METHOD(Nc_Storage_Backend_StorageBackendAdapter, getStorageNamePolicy) {


	RETURN_MEMBER(this_ptr, "storageNamePolicy");

}

PHP_METHOD(Nc_Storage_Backend_StorageBackendAdapter, generateUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zend_bool _0;
	zval *source_param = NULL, *group_param = NULL, *extension_param = NULL, *_1, *_2 = NULL, *_5, *_6 = NULL;
	zval *source = NULL, *group = NULL, *extension = NULL, *uri, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &source_param, &group_param, &extension_param);

	zephir_get_strval(source, source_param);
	zephir_get_strval(group, group_param);
	zephir_get_strval(extension, extension_param);
	ZEPHIR_INIT_VAR(uri);
	ZVAL_STRING(uri, "/", 1);


	_0 = zephir_is_true(group);
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "#^\\w+(/\\w+)*$#", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, group);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		_0 = zephir_is_true(_2);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VS(_4, group, "/");
		zephir_concat_self(&uri, _4 TSRMLS_CC);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("storageNamePolicy"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _5, "generatename", NULL);
	zephir_check_call_status();
	zephir_concat_self(&uri, _6 TSRMLS_CC);
	if (extension && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, ".", extension);
		zephir_concat_self(&uri, _4 TSRMLS_CC);
	}
	RETURN_CTOR(uri);

}

