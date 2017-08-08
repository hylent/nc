
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Image_Area) {

	ZEPHIR_REGISTER_CLASS(Nc\\Image, Area, nc, image_area, nc_image_area_method_entry, 0);

	zend_declare_property_null(nc_image_area_ce, SL("x"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(nc_image_area_ce, SL("y"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(nc_image_area_ce, SL("w"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(nc_image_area_ce, SL("h"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Area, __construct) {

	zval *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, _0;
	long x, y, w, h;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 4, 0, &x_param, &y_param, &w_param, &h_param);

	x = zephir_get_intval(x_param);
	y = zephir_get_intval(y_param);
	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, x);
	zephir_update_property_zval(this_ptr, SL("x"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, y);
	zephir_update_property_zval(this_ptr, SL("y"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, w);
	zephir_update_property_zval(this_ptr, SL("w"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, h);
	zephir_update_property_zval(this_ptr, SL("h"), &_0);

}

