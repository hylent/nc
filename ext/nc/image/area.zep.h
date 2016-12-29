
extern zend_class_entry *nc_image_area_ce;

ZEPHIR_INIT_CLASS(Nc_Image_Area);

PHP_METHOD(Nc_Image_Area, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_area___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_area_method_entry) {
	PHP_ME(Nc_Image_Area, __construct, arginfo_nc_image_area___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
