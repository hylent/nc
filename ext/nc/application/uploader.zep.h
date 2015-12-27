
extern zend_class_entry *nc_application_uploader_ce;

ZEPHIR_INIT_CLASS(Nc_Application_Uploader);

PHP_METHOD(Nc_Application_Uploader, __construct);
PHP_METHOD(Nc_Application_Uploader, setStorage);
PHP_METHOD(Nc_Application_Uploader, getStorage);
PHP_METHOD(Nc_Application_Uploader, saveUploadedFile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_uploader___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, validExtensions)
	ZEND_ARG_INFO(0, maxSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_uploader_setstorage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, Nc\\Storage\\StorageAbstract, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_uploader_saveuploadedfile, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, uploadedFile, Nc\\Application\\UploadedFile, 0)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, keep)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_application_uploader_method_entry) {
	PHP_ME(Nc_Application_Uploader, __construct, arginfo_nc_application_uploader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Application_Uploader, setStorage, arginfo_nc_application_uploader_setstorage, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application_Uploader, getStorage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application_Uploader, saveUploadedFile, arginfo_nc_application_uploader_saveuploadedfile, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
