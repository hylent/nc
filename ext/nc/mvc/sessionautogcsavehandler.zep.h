
extern zend_class_entry *nc_mvc_sessionautogcsavehandler_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_SessionAutoGcSaveHandler);

PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, __construct);
PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, register);
PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, getStorage);
PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, open);
PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, read);
PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, write);
PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, destroy);
PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, close);
PHP_METHOD(Nc_Mvc_SessionAutoGcSaveHandler, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcsavehandler___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, Nc\\Mvc\\SessionAutoGcStorageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcsavehandler_open, 0, 0, 2)
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcsavehandler_read, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcsavehandler_write, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcsavehandler_destroy, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcsavehandler_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, maxLifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_sessionautogcsavehandler_method_entry) {
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, __construct, arginfo_nc_mvc_sessionautogcsavehandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, getStorage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, open, arginfo_nc_mvc_sessionautogcsavehandler_open, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, read, arginfo_nc_mvc_sessionautogcsavehandler_read, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, write, arginfo_nc_mvc_sessionautogcsavehandler_write, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, destroy, arginfo_nc_mvc_sessionautogcsavehandler_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_SessionAutoGcSaveHandler, gc, arginfo_nc_mvc_sessionautogcsavehandler_gc, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
