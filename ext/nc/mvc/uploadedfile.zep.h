
extern zend_class_entry *nc_mvc_uploadedfile_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_UploadedFile);

PHP_METHOD(Nc_Mvc_UploadedFile, __construct);
PHP_METHOD(Nc_Mvc_UploadedFile, getError);
PHP_METHOD(Nc_Mvc_UploadedFile, getSize);
PHP_METHOD(Nc_Mvc_UploadedFile, getName);
PHP_METHOD(Nc_Mvc_UploadedFile, getTmpName);
PHP_METHOD(Nc_Mvc_UploadedFile, getExtension);
PHP_METHOD(Nc_Mvc_UploadedFile, getImageType);
PHP_METHOD(Nc_Mvc_UploadedFile, isImage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_uploadedfile___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, error)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, tmpName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_uploadedfile_method_entry) {
	PHP_ME(Nc_Mvc_UploadedFile, __construct, arginfo_nc_mvc_uploadedfile___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Mvc_UploadedFile, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_UploadedFile, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_UploadedFile, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_UploadedFile, getTmpName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_UploadedFile, getExtension, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_UploadedFile, getImageType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_UploadedFile, isImage, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
