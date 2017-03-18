
extern zend_class_entry *nc_di_injector_ce;

ZEPHIR_INIT_CLASS(Nc_Di_Injector);

PHP_METHOD(Nc_Di_Injector, __isset);
PHP_METHOD(Nc_Di_Injector, __get);
PHP_METHOD(Nc_Di_Injector, __set);
PHP_METHOD(Nc_Di_Injector, __unset);
PHP_METHOD(Nc_Di_Injector, __invoke);
PHP_METHOD(Nc_Di_Injector, offsetSet);
PHP_METHOD(Nc_Di_Injector, offsetGet);
PHP_METHOD(Nc_Di_Injector, offsetExists);
PHP_METHOD(Nc_Di_Injector, offsetUnset);
PHP_METHOD(Nc_Di_Injector, setClassMapper);
PHP_METHOD(Nc_Di_Injector, setClassPrefix);
PHP_METHOD(Nc_Di_Injector, setClassNamespace);
PHP_METHOD(Nc_Di_Injector, resolveFirst);
PHP_METHOD(Nc_Di_Injector, resolveAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, delegate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_setclassmapper, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, classMapper, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_setclassprefix, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_setclassnamespace, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, ns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_resolvefirst, 0, 0, 1)
	ZEND_ARG_INFO(0, annotation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injector_resolveall, 0, 0, 1)
	ZEND_ARG_INFO(0, annotation)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_di_injector_method_entry) {
	PHP_ME(Nc_Di_Injector, __isset, arginfo_nc_di_injector___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, __get, arginfo_nc_di_injector___get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, __set, arginfo_nc_di_injector___set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, __unset, arginfo_nc_di_injector___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, __invoke, arginfo_nc_di_injector___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, offsetSet, arginfo_nc_di_injector_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, offsetGet, arginfo_nc_di_injector_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, offsetExists, arginfo_nc_di_injector_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, offsetUnset, arginfo_nc_di_injector_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, setClassMapper, arginfo_nc_di_injector_setclassmapper, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, setClassPrefix, arginfo_nc_di_injector_setclassprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, setClassNamespace, arginfo_nc_di_injector_setclassnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Di_Injector, resolveFirst, arginfo_nc_di_injector_resolvefirst, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Di_Injector, resolveAll, arginfo_nc_di_injector_resolveall, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
