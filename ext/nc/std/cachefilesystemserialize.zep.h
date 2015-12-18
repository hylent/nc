
extern zend_class_entry *nc_std_cachefilesystemserialize_ce;

ZEPHIR_INIT_CLASS(Nc_Std_CacheFileSystemSerialize);

PHP_METHOD(Nc_Std_CacheFileSystemSerialize, packData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystemserialize_packdata, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_cachefilesystemserialize_method_entry) {
	PHP_ME(Nc_Std_CacheFileSystemSerialize, packData, arginfo_nc_std_cachefilesystemserialize_packdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
