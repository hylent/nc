
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_Image_Text) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image, Text, nc, image_text, nc_image_imageabstract_ce, nc_image_text_method_entry, 0);

	zend_declare_property_string(nc_image_text_ce, SL("text"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(nc_image_text_ce, SL("font"), "simhei.ttf", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(nc_image_text_ce, SL("fontSize"), 24, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(nc_image_text_ce, SL("color"), "#000000", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_double(nc_image_text_ce, SL("opacity"), 0.5, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(nc_image_text_ce, SL("padding"), 5, ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Image_Text, setOptions) {

	zend_bool _5$$7, _10$$9;
	double d = 0;
	long l = 0;
	zval *s = NULL, *_2$$3 = NULL, *_4$$7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *mergedOptions = NULL, *opt = NULL, *m = NULL, *_0, *_1 = NULL, *_3$$6, *_6$$7, _7$$7, *_8$$8 = NULL, *_9$$8, *_11$$10, *_12$$12;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
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
	if (zephir_array_isset_string_fetch(&opt, mergedOptions, SS("fontSize"), 0 TSRMLS_CC)) {
		l = zephir_get_intval(opt);
		if (l > 7) {
			ZEPHIR_INIT_ZVAL_NREF(_3$$6);
			ZVAL_LONG(_3$$6, l);
			zephir_update_property_this(this_ptr, SL("fontSize"), _3$$6 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, mergedOptions, SS("color"), 0 TSRMLS_CC)) {
		zephir_get_strval(_4$$7, opt);
		ZEPHIR_CPY_WRT(s, _4$$7);
		_5$$7 = zephir_is_true(s);
		if (_5$$7) {
			ZEPHIR_INIT_VAR(_6$$7);
			ZEPHIR_SINIT_VAR(_7$$7);
			ZVAL_STRING(&_7$$7, "/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", 0);
			zephir_preg_match(_6$$7, &_7$$7, s, m, 0, 0 , 0  TSRMLS_CC);
			_5$$7 = zephir_is_true(_6$$7);
		}
		if (_5$$7) {
			ZEPHIR_INIT_VAR(_9$$8);
			zephir_fast_strtoupper(_9$$8, s);
			zephir_update_property_this(this_ptr, SL("color"), _9$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, mergedOptions, SS("opacity"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(opt);
		_10$$9 = d >= 0;
		if (_10$$9) {
			_10$$9 = d <= 1;
		}
		if (_10$$9) {
			ZEPHIR_INIT_ZVAL_NREF(_11$$10);
			ZVAL_DOUBLE(_11$$10, d);
			zephir_update_property_this(this_ptr, SL("opacity"), _11$$10 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, mergedOptions, SS("padding"), 0 TSRMLS_CC)) {
		l = zephir_get_intval(opt);
		if (l >= 0) {
			ZEPHIR_INIT_ZVAL_NREF(_12$$12);
			ZVAL_LONG(_12$$12, l);
			zephir_update_property_this(this_ptr, SL("padding"), _12$$12 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

