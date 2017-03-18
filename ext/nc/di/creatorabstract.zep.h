
extern zend_class_entry *nc_di_creatorabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Di_CreatorAbstract);

PHP_METHOD(Nc_Di_CreatorAbstract, setupByInjector);
PHP_METHOD(Nc_Di_CreatorAbstract, __isset);
PHP_METHOD(Nc_Di_CreatorAbstract, __get);
PHP_METHOD(Nc_Di_CreatorAbstract, getValidClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorabstract_setupbyinjector, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, injector, Nc\\Di\\Injector, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorabstract___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorabstract___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorabstract_getvalidclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_di_creatorabstract_method_entry) {
	PHP_ME(Nc_Di_CreatorAbstract, setupByInjector, arginfo_nc_di_creatorabstract_setupbyinjector, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_CreatorAbstract, __isset, arginfo_nc_di_creatorabstract___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_CreatorAbstract, __get, arginfo_nc_di_creatorabstract___get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_CreatorAbstract, getValidClassName, arginfo_nc_di_creatorabstract_getvalidclassname, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
