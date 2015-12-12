
extern zend_class_entry *nc_data_singlevaluebackendinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Data_SingleValueBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_singlevaluebackendinterface_setsinglevalue, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_singlevaluebackendinterface_getsinglevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_singlevaluebackendinterface_deletesinglevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_data_singlevaluebackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Data_SingleValueBackendInterface, setSingleValue, arginfo_nc_data_singlevaluebackendinterface_setsinglevalue)
	PHP_ABSTRACT_ME(Nc_Data_SingleValueBackendInterface, getSingleValue, arginfo_nc_data_singlevaluebackendinterface_getsinglevalue)
	PHP_ABSTRACT_ME(Nc_Data_SingleValueBackendInterface, deleteSingleValue, arginfo_nc_data_singlevaluebackendinterface_deletesinglevalue)
	PHP_FE_END
};
