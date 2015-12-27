
extern zend_class_entry *nc_application_controllerabstracthttp_ce;

ZEPHIR_INIT_CLASS(Nc_Application_ControllerAbstractHttp);

PHP_METHOD(Nc_Application_ControllerAbstractHttp, getRequest);
PHP_METHOD(Nc_Application_ControllerAbstractHttp, getQuery);
PHP_METHOD(Nc_Application_ControllerAbstractHttp, getPost);
PHP_METHOD(Nc_Application_ControllerAbstractHttp, getCookie);
PHP_METHOD(Nc_Application_ControllerAbstractHttp, newUploadedFile);
PHP_METHOD(Nc_Application_ControllerAbstractHttp, hasUploadedFile);
PHP_METHOD(Nc_Application_ControllerAbstractHttp, getUploadedFile);
PHP_METHOD(Nc_Application_ControllerAbstractHttp, getUploadedFiles);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstracthttp_getrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstracthttp_getquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstracthttp_getpost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstracthttp_getcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstracthttp_newuploadedfile, 0, 0, 4)
	ZEND_ARG_INFO(0, error)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, tmpName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstracthttp_hasuploadedfile, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstracthttp_getuploadedfile, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstracthttp_getuploadedfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_application_controllerabstracthttp_method_entry) {
	PHP_ME(Nc_Application_ControllerAbstractHttp, getRequest, arginfo_nc_application_controllerabstracthttp_getrequest, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Application_ControllerAbstractHttp, getQuery, arginfo_nc_application_controllerabstracthttp_getquery, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Application_ControllerAbstractHttp, getPost, arginfo_nc_application_controllerabstracthttp_getpost, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Application_ControllerAbstractHttp, getCookie, arginfo_nc_application_controllerabstracthttp_getcookie, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Application_ControllerAbstractHttp, newUploadedFile, arginfo_nc_application_controllerabstracthttp_newuploadedfile, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Application_ControllerAbstractHttp, hasUploadedFile, arginfo_nc_application_controllerabstracthttp_hasuploadedfile, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Application_ControllerAbstractHttp, getUploadedFile, arginfo_nc_application_controllerabstracthttp_getuploadedfile, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Application_ControllerAbstractHttp, getUploadedFiles, arginfo_nc_application_controllerabstracthttp_getuploadedfiles, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
