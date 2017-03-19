
extern zend_class_entry *nc_mvc_contexthttp_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_ContextHttp);

PHP_METHOD(Nc_Mvc_ContextHttp, generateSessionId);
PHP_METHOD(Nc_Mvc_ContextHttp, __construct);
PHP_METHOD(Nc_Mvc_ContextHttp, getRoutingNames);
PHP_METHOD(Nc_Mvc_ContextHttp, getRawInput);
PHP_METHOD(Nc_Mvc_ContextHttp, getParamMap);
PHP_METHOD(Nc_Mvc_ContextHttp, getParam);
PHP_METHOD(Nc_Mvc_ContextHttp, getQuery);
PHP_METHOD(Nc_Mvc_ContextHttp, getPost);
PHP_METHOD(Nc_Mvc_ContextHttp, getCookie);
PHP_METHOD(Nc_Mvc_ContextHttp, newUploadedFile);
PHP_METHOD(Nc_Mvc_ContextHttp, hasUploadedFile);
PHP_METHOD(Nc_Mvc_ContextHttp, getUploadedFile);
PHP_METHOD(Nc_Mvc_ContextHttp, getUploadedFiles);
PHP_METHOD(Nc_Mvc_ContextHttp, getRequestMethod);
PHP_METHOD(Nc_Mvc_ContextHttp, getRemoteAddr);
PHP_METHOD(Nc_Mvc_ContextHttp, isXhr);
PHP_METHOD(Nc_Mvc_ContextHttp, getHttpHost);
PHP_METHOD(Nc_Mvc_ContextHttp, getHttpUserAgent);
PHP_METHOD(Nc_Mvc_ContextHttp, getHttpReferer);
PHP_METHOD(Nc_Mvc_ContextHttp, setDefaultCookieOptions);
PHP_METHOD(Nc_Mvc_ContextHttp, getDefaultCookieOptions);
PHP_METHOD(Nc_Mvc_ContextHttp, startSession);
PHP_METHOD(Nc_Mvc_ContextHttp, status);
PHP_METHOD(Nc_Mvc_ContextHttp, cookie);
PHP_METHOD(Nc_Mvc_ContextHttp, header);
PHP_METHOD(Nc_Mvc_ContextHttp, redirect);
PHP_METHOD(Nc_Mvc_ContextHttp, sendFile);
PHP_METHOD(Nc_Mvc_ContextHttp, initArgVectorFromRequestUri);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_getquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_getpost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_getcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_newuploadedfile, 0, 0, 4)
	ZEND_ARG_INFO(0, error)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, tmpName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_hasuploadedfile, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_getuploadedfile, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_getuploadedfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_setdefaultcookieoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_startsession, 0, 0, 0)
	ZEND_ARG_INFO(0, sessionIdGenerator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_status, 0, 0, 1)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_cookie, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_header, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttp_sendfile, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_contexthttp_method_entry) {
	PHP_ME(Nc_Mvc_ContextHttp, generateSessionId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Mvc_ContextHttp, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Mvc_ContextHttp, getRoutingNames, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getRawInput, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getParamMap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getParam, arginfo_nc_mvc_contexthttp_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getQuery, arginfo_nc_mvc_contexthttp_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getPost, arginfo_nc_mvc_contexthttp_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getCookie, arginfo_nc_mvc_contexthttp_getcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, newUploadedFile, arginfo_nc_mvc_contexthttp_newuploadedfile, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, hasUploadedFile, arginfo_nc_mvc_contexthttp_hasuploadedfile, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getUploadedFile, arginfo_nc_mvc_contexthttp_getuploadedfile, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getUploadedFiles, arginfo_nc_mvc_contexthttp_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getRequestMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getRemoteAddr, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, isXhr, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getHttpHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getHttpUserAgent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getHttpReferer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, setDefaultCookieOptions, arginfo_nc_mvc_contexthttp_setdefaultcookieoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, getDefaultCookieOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, startSession, arginfo_nc_mvc_contexthttp_startsession, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, status, arginfo_nc_mvc_contexthttp_status, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, cookie, arginfo_nc_mvc_contexthttp_cookie, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, header, arginfo_nc_mvc_contexthttp_header, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, redirect, arginfo_nc_mvc_contexthttp_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, sendFile, arginfo_nc_mvc_contexthttp_sendfile, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttp, initArgVectorFromRequestUri, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
