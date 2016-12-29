
extern zend_class_entry *nc_factory_classnameabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_ClassNameAbstract);

PHP_METHOD(Nc_Factory_ClassNameAbstract, newInstanceOf);
PHP_METHOD(Nc_Factory_ClassNameAbstract, getClassName);
PHP_METHOD(Nc_Factory_ClassNameAbstract, __isset);
PHP_METHOD(Nc_Factory_ClassNameAbstract, setArgs);
PHP_METHOD(Nc_Factory_ClassNameAbstract, setArgsByArray);
PHP_METHOD(Nc_Factory_ClassNameAbstract, getArgs);
PHP_METHOD(Nc_Factory_ClassNameAbstract, setLazyArg);
PHP_METHOD(Nc_Factory_ClassNameAbstract, getLazyArgs);
PHP_METHOD(Nc_Factory_ClassNameAbstract, createInternally);
PHP_METHOD(Nc_Factory_ClassNameAbstract, processLazyArgs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract_newinstanceof, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract_setargsbyarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract_setlazyarg, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, lazyArg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract_createinternally, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_classnameabstract_method_entry) {
	PHP_ME(Nc_Factory_ClassNameAbstract, newInstanceOf, arginfo_nc_factory_classnameabstract_newinstanceof, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, getClassName, arginfo_nc_factory_classnameabstract_getclassname, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, __isset, arginfo_nc_factory_classnameabstract___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, setArgs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, setArgsByArray, arginfo_nc_factory_classnameabstract_setargsbyarray, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, getArgs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, setLazyArg, arginfo_nc_factory_classnameabstract_setlazyarg, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, getLazyArgs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, createInternally, arginfo_nc_factory_classnameabstract_createinternally, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Factory_ClassNameAbstract, processLazyArgs, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
