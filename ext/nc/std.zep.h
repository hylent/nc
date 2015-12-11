
extern zend_class_entry *nc_std_ce;

ZEPHIR_INIT_CLASS(Nc_Std);

PHP_METHOD(Nc_Std, sizeToBytes);
PHP_METHOD(Nc_Std, bytesToSize);
PHP_METHOD(Nc_Std, pascalCase);
PHP_METHOD(Nc_Std, camelCase);
PHP_METHOD(Nc_Std, normalCase);
PHP_METHOD(Nc_Std, uuid);
PHP_METHOD(Nc_Std, randString);
PHP_METHOD(Nc_Std, tr);
PHP_METHOD(Nc_Std, valueAt);
PHP_METHOD(Nc_Std, valueOf);
PHP_METHOD(Nc_Std, indexedData);
PHP_METHOD(Nc_Std, indexedValues);
PHP_METHOD(Nc_Std, groupedData);
PHP_METHOD(Nc_Std, groupedValues);
PHP_METHOD(Nc_Std, groupIndexedData);
PHP_METHOD(Nc_Std, groupIndexedValues);
PHP_METHOD(Nc_Std, uniqueValues);
PHP_METHOD(Nc_Std, newInstanceOf);
PHP_METHOD(Nc_Std, ignoreError);
PHP_METHOD(Nc_Std, throwError);
PHP_METHOD(Nc_Std, outputScript);
PHP_METHOD(Nc_Std, renderScript);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_sizetobytes, 0, 0, 1)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_bytestosize, 0, 0, 1)
	ZEND_ARG_INFO(0, bytes)
	ZEND_ARG_INFO(0, decimal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_pascalcase, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_camelcase, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_normalcase, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, sep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_uuid, 0, 0, 0)
	ZEND_ARG_INFO(0, salt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_randstring, 0, 0, 1)
	ZEND_ARG_INFO(0, len)
	ZEND_ARG_INFO(0, charList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_tr, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_valueat, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, noException)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_valueof, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_indexeddata, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, indexKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_indexedvalues, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, indexKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupeddata, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, groupKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupedvalues, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupindexeddata, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, indexKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_groupindexedvalues, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, indexKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_uniquevalues, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, uniqueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_newinstanceof, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_ignoreerror, 0, 0, 4)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_INFO(0, s)
	ZEND_ARG_INFO(0, f)
	ZEND_ARG_INFO(0, l)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_throwerror, 0, 0, 4)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_INFO(0, s)
	ZEND_ARG_INFO(0, f)
	ZEND_ARG_INFO(0, l)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_outputscript, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_renderscript, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_method_entry) {
	PHP_ME(Nc_Std, sizeToBytes, arginfo_nc_std_sizetobytes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, bytesToSize, arginfo_nc_std_bytestosize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, pascalCase, arginfo_nc_std_pascalcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, camelCase, arginfo_nc_std_camelcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, normalCase, arginfo_nc_std_normalcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, uuid, arginfo_nc_std_uuid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, randString, arginfo_nc_std_randstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, tr, arginfo_nc_std_tr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, valueAt, arginfo_nc_std_valueat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, valueOf, arginfo_nc_std_valueof, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, indexedData, arginfo_nc_std_indexeddata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, indexedValues, arginfo_nc_std_indexedvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, groupedData, arginfo_nc_std_groupeddata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, groupedValues, arginfo_nc_std_groupedvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, groupIndexedData, arginfo_nc_std_groupindexeddata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, groupIndexedValues, arginfo_nc_std_groupindexedvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, uniqueValues, arginfo_nc_std_uniquevalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, newInstanceOf, arginfo_nc_std_newinstanceof, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, ignoreError, arginfo_nc_std_ignoreerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, throwError, arginfo_nc_std_throwerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, outputScript, arginfo_nc_std_outputscript, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Std, renderScript, arginfo_nc_std_renderscript, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
