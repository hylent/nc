
extern zend_class_entry *nc_image_text_ce;

ZEPHIR_INIT_CLASS(Nc_Image_Text);

PHP_METHOD(Nc_Image_Text, setOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_image_text_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_image_text_method_entry) {
	PHP_ME(Nc_Image_Text, setOptions, arginfo_nc_image_text_setoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
