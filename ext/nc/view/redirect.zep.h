
extern zend_class_entry *nc_view_redirect_ce;

ZEPHIR_INIT_CLASS(Nc_View_Redirect);

PHP_METHOD(Nc_View_Redirect, run);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_view_redirect_run, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_view_redirect_method_entry) {
	PHP_ME(Nc_View_Redirect, run, arginfo_nc_view_redirect_run, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
