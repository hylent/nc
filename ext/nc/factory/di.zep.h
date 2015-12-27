
extern zend_class_entry *nc_factory_di_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_Di);

PHP_METHOD(Nc_Factory_Di, __invoke);
PHP_METHOD(Nc_Factory_Di, __set);
PHP_METHOD(Nc_Factory_Di, __unset);
PHP_METHOD(Nc_Factory_Di, __isset);
PHP_METHOD(Nc_Factory_Di, newProduction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_di___invoke, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, initializer, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_di___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, production)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_di___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_di___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_di_newproduction, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_di_method_entry) {
	PHP_ME(Nc_Factory_Di, __invoke, arginfo_nc_factory_di___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Di, __set, arginfo_nc_factory_di___set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Di, __unset, arginfo_nc_factory_di___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Di, __isset, arginfo_nc_factory_di___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Di, newProduction, arginfo_nc_factory_di_newproduction, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
