
extern zend_class_entry *nc_std_cachefilesystemvarexport_ce;

ZEPHIR_INIT_CLASS(Nc_Std_CacheFileSystemVarExport);

PHP_METHOD(Nc_Std_CacheFileSystemVarExport, packData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystemvarexport_packdata, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_cachefilesystemvarexport_method_entry) {
	PHP_ME(Nc_Std_CacheFileSystemVarExport, packData, arginfo_nc_std_cachefilesystemvarexport_packdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
