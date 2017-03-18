
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Config_FileSystemAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Config, FileSystemAbstract, nc, config_filesystemabstract, nc_config_filesystemabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_config_filesystemabstract_ce, SL("configs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_config_filesystemabstract_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(nc_config_filesystemabstract_ce, SL("fileExtension"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_config_filesystemabstract_ce, SL("VALID_FILENAME_PATTERN"), "#^[\\w]+$#");

	zend_class_implements(nc_config_filesystemabstract_ce TSRMLS_CC, 1, nc_config_configinterface_ce);
	zend_class_implements(nc_config_filesystemabstract_ce TSRMLS_CC, 1, nc_di_containerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Config_FileSystemAbstract, __construct) {

	zval *baseDirectory_param = NULL;
	zval baseDirectory;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&baseDirectory);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseDirectory_param);

	zephir_get_strval(&baseDirectory, baseDirectory_param);


	zephir_update_property_zval(this_ptr, SL("baseDirectory"), &baseDirectory);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Config_FileSystemAbstract, __isset) {

	zval *name_param = NULL;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	RETURN_MM_BOOL(1);

}

PHP_METHOD(Nc_Config_FileSystemAbstract, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Config_FileSystemAbstract, get) {

	zend_bool _7$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, parts, part, value, path, tmpValue, _0, *_6, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&tmpValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(&name, name_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("."), &name, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&parts);
	ZEPHIR_CALL_FUNCTION(&part, "array_shift", NULL, 4, &parts);
	ZEPHIR_UNREF(&parts);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&value);
	zephir_read_property(&_0, this_ptr, SL("configs"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &part, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "#^[\\w]+$#");
		zephir_preg_match(&_2$$3, &_3$$3, &part, &_1$$3, 0, 0 , 0  TSRMLS_CC);
		if (unlikely(!zephir_is_true(&_2$$3))) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		zephir_read_property(&_4$$3, this_ptr, SL("baseDirectory"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$3, this_ptr, SL("fileExtension"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&path);
		ZEPHIR_CONCAT_VSVSV(&path, &_4$$3, "/", &part, ".", &_5$$3);
		if ((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&value, this_ptr, "readfrompath", NULL, 0, &path);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_NULL(&value);
		}
		zephir_update_property_array(this_ptr, SL("configs"), &part, &value TSRMLS_CC);
	}
	zephir_is_iterable(&parts, 0, "nc/config/filesystemabstract.zep", 56);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _6)
	{
		ZEPHIR_INIT_NVAR(&part);
		ZVAL_COPY(&part, _6);
		_7$$7 = Z_TYPE_P(&value) != IS_ARRAY;
		if (!(_7$$7)) {
			_7$$7 = !(zephir_array_isset_fetch(&tmpValue, &value, &part, 1 TSRMLS_CC));
		}
		if (_7$$7) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		ZEPHIR_CPY_WRT(&value, &tmpValue);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&part);
	RETURN_CCTOR(value);

}

PHP_METHOD(Nc_Config_FileSystemAbstract, loadAll) {

	zval _7$$4;
	zval paths, path, name, value, configs, _0, _1, _2, *_3$$3, _4$$4, _5$$4, _8$$4, _9$$4, _10$$4;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&configs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&configs);
	array_init(&configs);
	zephir_read_property(&_0, this_ptr, SL("baseDirectory"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("fileExtension"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &_0, "/*.", &_1);
	ZEPHIR_CALL_FUNCTION(&paths, "glob", NULL, 11, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&paths) == IS_ARRAY) {
		zephir_is_iterable(&paths, 0, "nc/config/filesystemabstract.zep", 78);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&paths), _3$$3)
		{
			ZEPHIR_INIT_NVAR(&path);
			ZVAL_COPY(&path, _3$$3);
			ZVAL_LONG(&_4$$4, 8);
			ZEPHIR_CALL_FUNCTION(&_5$$4, "pathinfo", &_6, 12, &path, &_4$$4);
			zephir_check_call_status();
			zephir_get_strval(&_7$$4, &_5$$4);
			ZEPHIR_CPY_WRT(&name, &_7$$4);
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZEPHIR_INIT_NVAR(&_9$$4);
			ZEPHIR_INIT_NVAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "#^[\\w]+$#");
			zephir_preg_match(&_9$$4, &_10$$4, &name, &_8$$4, 0, 0 , 0  TSRMLS_CC);
			if (!(zephir_is_true(&_9$$4))) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&value);
			zephir_read_property(&_4$$4, this_ptr, SL("configs"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_fetch(&value, &_4$$4, &name, 0 TSRMLS_CC)) {
				zephir_array_update_zval(&configs, &name, &value, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_CALL_METHOD(&value, this_ptr, "readfrompath", &_11, 0, &path);
				zephir_check_call_status();
				zephir_array_update_zval(&configs, &name, &value, PH_COPY | PH_SEPARATE);
				zephir_update_property_array(this_ptr, SL("configs"), &name, &value TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&path);
	}
	RETURN_CCTOR(configs);

}

PHP_METHOD(Nc_Config_FileSystemAbstract, readFromPath) {

}

