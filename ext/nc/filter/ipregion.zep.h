
extern zend_class_entry *nc_filter_ipregion_ce;

ZEPHIR_INIT_CLASS(Nc_Filter_IpRegion);

PHP_METHOD(Nc_Filter_IpRegion, packItem);
PHP_METHOD(Nc_Filter_IpRegion, __construct);
PHP_METHOD(Nc_Filter_IpRegion, count);
PHP_METHOD(Nc_Filter_IpRegion, search);
PHP_METHOD(Nc_Filter_IpRegion, searchLong);
PHP_METHOD(Nc_Filter_IpRegion, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_filter_ipregion_packitem, 0, 0, 3)
	ZEND_ARG_INFO(0, ip1)
	ZEND_ARG_INFO(0, ip2)
	ZEND_ARG_INFO(0, region)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_filter_ipregion___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dataPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_filter_ipregion_search, 0, 0, 1)
	ZEND_ARG_INFO(0, ip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_filter_ipregion_searchlong, 0, 0, 1)
	ZEND_ARG_INFO(0, ipLong)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_filter_ipregion_method_entry) {
	PHP_ME(Nc_Filter_IpRegion, packItem, arginfo_nc_filter_ipregion_packitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Filter_IpRegion, __construct, arginfo_nc_filter_ipregion___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Filter_IpRegion, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Filter_IpRegion, search, arginfo_nc_filter_ipregion_search, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Filter_IpRegion, searchLong, arginfo_nc_filter_ipregion_searchlong, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Filter_IpRegion, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
