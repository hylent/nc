
extern zend_class_entry *nc_storage_uploader_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_Uploader);

PHP_METHOD(Nc_Storage_Uploader, __construct);
PHP_METHOD(Nc_Storage_Uploader, setStorageBackend);
PHP_METHOD(Nc_Storage_Uploader, getStorageBackend);
PHP_METHOD(Nc_Storage_Uploader, upload);
PHP_METHOD(Nc_Storage_Uploader, lastError);
PHP_METHOD(Nc_Storage_Uploader, fileArray);
PHP_METHOD(Nc_Storage_Uploader, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_uploader___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, validExtensions)
	ZEND_ARG_INFO(0, maxSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_uploader_setstoragebackend, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storageBackend, Nc\\Storage\\Backend\\StorageBackendInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_uploader_upload, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, reserveTmp)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_uploader___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_uploader_method_entry) {
	PHP_ME(Nc_Storage_Uploader, __construct, arginfo_nc_storage_uploader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Storage_Uploader, setStorageBackend, arginfo_nc_storage_uploader_setstoragebackend, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Uploader, getStorageBackend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Uploader, upload, arginfo_nc_storage_uploader_upload, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Uploader, lastError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Uploader, fileArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Uploader, __get, arginfo_nc_storage_uploader___get, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
