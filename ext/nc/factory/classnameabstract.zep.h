
extern zend_class_entry *nc_factory_classnameabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_ClassNameAbstract);

PHP_METHOD(Nc_Factory_ClassNameAbstract, __isset);
PHP_METHOD(Nc_Factory_ClassNameAbstract, newProduction);
PHP_METHOD(Nc_Factory_ClassNameAbstract, setArgs);
PHP_METHOD(Nc_Factory_ClassNameAbstract, setArgArray);
PHP_METHOD(Nc_Factory_ClassNameAbstract, getArgArray);
PHP_METHOD(Nc_Factory_ClassNameAbstract, getClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract_newproduction, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract_setargarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_classnameabstract_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_classnameabstract_method_entry) {
	PHP_ME(Nc_Factory_ClassNameAbstract, __isset, arginfo_nc_factory_classnameabstract___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, newProduction, arginfo_nc_factory_classnameabstract_newproduction, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, setArgs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, setArgArray, arginfo_nc_factory_classnameabstract_setargarray, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, getArgArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_ClassNameAbstract, getClassName, arginfo_nc_factory_classnameabstract_getclassname, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
