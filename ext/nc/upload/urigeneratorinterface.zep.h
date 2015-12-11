
extern zend_class_entry *nc_upload_urigeneratorinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Upload_UriGeneratorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_urigeneratorinterface_generateuri, 0, 0, 3)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_upload_urigeneratorinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Upload_UriGeneratorInterface, generateUri, arginfo_nc_upload_urigeneratorinterface_generateuri)
	PHP_FE_END
};
