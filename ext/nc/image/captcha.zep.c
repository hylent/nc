
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Image_Captcha) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Captcha, nc, image_captcha, nc_image_image_ce, nc_image_captcha_method_entry, 0);

	zend_declare_property_string(nc_image_captcha_ce, SL("text"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(nc_image_captcha_ce, SL("font"), "simhei.ttf", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_double(nc_image_captcha_ce, SL("rPadding"), 0.2, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_double(nc_image_captcha_ce, SL("rOverlap"), 0.2, ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Captcha, setOptions) {

	zend_bool _3$$5, _5$$7;
	double d = 0;
	zval *s = NULL, *_2$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *mergedOptions = NULL, *opt = NULL, *_0, *_1 = NULL, *_4$$6, *_6$$8;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getdefaultoptions", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(mergedOptions);
	zephir_fast_array_merge(mergedOptions, &(_1), &(options) TSRMLS_CC);
	ZEPHIR_OBS_VAR(opt);
	if (zephir_array_isset_string_fetch(&opt, mergedOptions, SS("font"), 0 TSRMLS_CC)) {
		zephir_get_strval(_2$$3, opt);
		ZEPHIR_CPY_WRT(s, _2$$3);
		if (!(!s) && Z_STRLEN_P(s)) {
			zephir_update_property_this(this_ptr, SL("font"), s TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, mergedOptions, SS("rPadding"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(opt);
		_3$$5 = d > 0;
		if (_3$$5) {
			_3$$5 = d < 1;
		}
		if (_3$$5) {
			ZEPHIR_INIT_ZVAL_NREF(_4$$6);
			ZVAL_DOUBLE(_4$$6, d);
			zephir_update_property_this(this_ptr, SL("rPadding"), _4$$6 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, mergedOptions, SS("rOverlap"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(opt);
		_5$$7 = d > 0;
		if (_5$$7) {
			_5$$7 = d < 1;
		}
		if (_5$$7) {
			ZEPHIR_INIT_ZVAL_NREF(_6$$8);
			ZVAL_DOUBLE(_6$$8, d);
			zephir_update_property_this(this_ptr, SL("rOverlap"), _6$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

