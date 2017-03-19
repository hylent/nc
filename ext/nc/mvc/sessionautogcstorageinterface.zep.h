
extern zend_class_entry *nc_mvc_sessionautogcstorageinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_SessionAutoGcStorageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcstorageinterface_readsessiondata, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcstorageinterface_writesessiondata, 0, 0, 3)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_sessionautogcstorageinterface_destroysessiondata, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_sessionautogcstorageinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Mvc_SessionAutoGcStorageInterface, readSessionData, arginfo_nc_mvc_sessionautogcstorageinterface_readsessiondata)
	PHP_ABSTRACT_ME(Nc_Mvc_SessionAutoGcStorageInterface, writeSessionData, arginfo_nc_mvc_sessionautogcstorageinterface_writesessiondata)
	PHP_ABSTRACT_ME(Nc_Mvc_SessionAutoGcStorageInterface, destroySessionData, arginfo_nc_mvc_sessionautogcstorageinterface_destroysessiondata)
	PHP_FE_END
};
