
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Storage_Naming_Date) {

	ZEPHIR_REGISTER_CLASS(Nc\\Storage\\Naming, Date, nc, storage_naming_date, nc_storage_naming_date_method_entry, 0);

	zend_declare_property_null(nc_storage_naming_date_ce, SL("dateFormat"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_storage_naming_date_ce, SL("randStringLength"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_storage_naming_date_ce TSRMLS_CC, 1, nc_storage_naming_storagenaminginterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Storage_Naming_Date, __construct) {

	long randStringLength;
	zval *dateFormat_param = NULL, *randStringLength_param = NULL, *_0;
	zval *dateFormat = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dateFormat_param, &randStringLength_param);

	if (!dateFormat_param) {
		ZEPHIR_INIT_VAR(dateFormat);
		ZVAL_STRING(dateFormat, "Y/m/d/His_", 1);
	} else {
		zephir_get_strval(dateFormat, dateFormat_param);
	}
	if (!randStringLength_param) {
		randStringLength = 6;
	} else {
		randStringLength = zephir_get_intval(randStringLength_param);
	}


	zephir_update_property_this(this_ptr, SL("dateFormat"), dateFormat TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, randStringLength);
	zephir_update_property_this(this_ptr, SL("randStringLength"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Storage_Naming_Date, generateName) {

	zval *_0, *_1 = NULL, *_2 = NULL, *_4;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dateFormat"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 83, _0);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("randStringLength"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_2, nc_std_ce, "randstring", &_3, 118, _4);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, _1, _2);
	RETURN_MM();

}

