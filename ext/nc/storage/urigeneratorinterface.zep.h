
extern zend_class_entry *nc_storage_urigeneratorinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_UriGeneratorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_urigeneratorinterface_generateuri, 0, 0, 3)
	ZEND_ARG_INFO(0, src)
	ZEND_ARG_INFO(0, pre)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_urigeneratorinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Storage_UriGeneratorInterface, generateUri, arginfo_nc_storage_urigeneratorinterface_generateuri)
	PHP_FE_END
};
