
extern zend_class_entry *nc_di_creators_ce;

ZEPHIR_INIT_CLASS(Nc_Di_Creators);

PHP_METHOD(Nc_Di_Creators, __construct);
PHP_METHOD(Nc_Di_Creators, offsetSet);
PHP_METHOD(Nc_Di_Creators, offsetGet);
PHP_METHOD(Nc_Di_Creators, offsetExists);
PHP_METHOD(Nc_Di_Creators, offsetUnset);
PHP_METHOD(Nc_Di_Creators, getValidClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creators___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, creators, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creators_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, creator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creators_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creators_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creators_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creators_getvalidclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_di_creators_method_entry) {
	PHP_ME(Nc_Di_Creators, __construct, arginfo_nc_di_creators___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Di_Creators, offsetSet, arginfo_nc_di_creators_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Creators, offsetGet, arginfo_nc_di_creators_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Creators, offsetExists, arginfo_nc_di_creators_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Creators, offsetUnset, arginfo_nc_di_creators_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Creators, getValidClassName, arginfo_nc_di_creators_getvalidclassname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
