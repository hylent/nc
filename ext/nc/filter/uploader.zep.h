
extern zend_class_entry *nc_filter_uploader_ce;

ZEPHIR_INIT_CLASS(Nc_Filter_Uploader);

PHP_METHOD(Nc_Filter_Uploader, __construct);
PHP_METHOD(Nc_Filter_Uploader, setStorage);
PHP_METHOD(Nc_Filter_Uploader, getStorage);
PHP_METHOD(Nc_Filter_Uploader, upload);
PHP_METHOD(Nc_Filter_Uploader, lastError);
PHP_METHOD(Nc_Filter_Uploader, fileArray);
PHP_METHOD(Nc_Filter_Uploader, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_filter_uploader___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, validExtensions)
	ZEND_ARG_INFO(0, maxSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_filter_uploader_setstorage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, Nc\\Storage\\StorageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_filter_uploader_upload, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, reserveTmp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_filter_uploader___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_filter_uploader_method_entry) {
	PHP_ME(Nc_Filter_Uploader, __construct, arginfo_nc_filter_uploader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Filter_Uploader, setStorage, arginfo_nc_filter_uploader_setstorage, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Filter_Uploader, getStorage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Filter_Uploader, upload, arginfo_nc_filter_uploader_upload, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Filter_Uploader, lastError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Filter_Uploader, fileArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Filter_Uploader, __get, arginfo_nc_filter_uploader___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
