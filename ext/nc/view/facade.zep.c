
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
#include "Zend/zend_closures.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_View_Facade) {

	ZEPHIR_REGISTER_CLASS(Nc\\View, Facade, nc, view_facade, nc_view_facade_method_entry, 0);

	zend_declare_property_null(nc_view_facade_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_view_facade_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_view_facade_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_view_facade_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Nc_View_Facade, __construct) {

	zval *options_param = NULL, *data_param = NULL, *view = NULL;
	zval *options = NULL, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &options_param, &data_param, &view);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}
	if (!view) {
		view = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("view"), view TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, content) {

	zval *content = NULL, *contentType = NULL, *_0, *_1$$3, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &content, &contentType);

	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!contentType) {
		contentType = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "content", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	if (Z_TYPE_P(content) != IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "content", 1);
		zephir_update_property_array(this_ptr, SL("options"), _1$$3, content TSRMLS_CC);
	}
	if (Z_TYPE_P(contentType) != IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "contentType", 1);
		zephir_update_property_array(this_ptr, SL("options"), _2$$4, contentType TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, httpResponse) {

	zval *httpResponseCode = NULL, *httpResponseContent = NULL, *_0, *_1$$3, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &httpResponseCode, &httpResponseContent);

	if (!httpResponseCode) {
		httpResponseCode = ZEPHIR_GLOBAL(global_null);
	}
	if (!httpResponseContent) {
		httpResponseContent = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "httpResponse", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	if (Z_TYPE_P(httpResponseCode) != IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "httpResponseCode", 1);
		zephir_update_property_array(this_ptr, SL("options"), _1$$3, httpResponseCode TSRMLS_CC);
	}
	if (Z_TYPE_P(httpResponseContent) != IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "httpResponseContent", 1);
		zephir_update_property_array(this_ptr, SL("options"), _2$$4, httpResponseContent TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, json) {

	zval *jsonCallback = NULL, *jsonCors = NULL, *_0, *_1$$3, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &jsonCallback, &jsonCors);

	if (!jsonCallback) {
		jsonCallback = ZEPHIR_GLOBAL(global_null);
	}
	if (!jsonCors) {
		jsonCors = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "json", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	if (Z_TYPE_P(jsonCallback) != IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "jsonCallback", 1);
		zephir_update_property_array(this_ptr, SL("options"), _1$$3, jsonCallback TSRMLS_CC);
	}
	if (Z_TYPE_P(jsonCors) != IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "jsonCors", 1);
		zephir_update_property_array(this_ptr, SL("options"), _2$$4, jsonCors TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, nil) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "nil", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);

}

PHP_METHOD(Nc_View_Facade, readFile) {

	zval *readFile = NULL, *readFileContentType = NULL, *_0, *_1$$3, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &readFile, &readFileContentType);

	if (!readFile) {
		readFile = ZEPHIR_GLOBAL(global_null);
	}
	if (!readFileContentType) {
		readFileContentType = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "readFile", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	if (Z_TYPE_P(readFile) != IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "readFile", 1);
		zephir_update_property_array(this_ptr, SL("options"), _1$$3, readFile TSRMLS_CC);
	}
	if (Z_TYPE_P(readFileContentType) != IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "readFileContentType", 1);
		zephir_update_property_array(this_ptr, SL("options"), _2$$4, readFileContentType TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, redirect) {

	zval *redirectUrl = NULL, *redirectDataAsQueries = NULL, *_0, *_1$$3, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &redirectUrl, &redirectDataAsQueries);

	if (!redirectUrl) {
		redirectUrl = ZEPHIR_GLOBAL(global_null);
	}
	if (!redirectDataAsQueries) {
		redirectDataAsQueries = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "redirect", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	if (Z_TYPE_P(redirectUrl) != IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "redirectUrl", 1);
		zephir_update_property_array(this_ptr, SL("options"), _1$$3, redirectUrl TSRMLS_CC);
	}
	if (Z_TYPE_P(redirectDataAsQueries) != IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "redirectDataAsQueries", 1);
		zephir_update_property_array(this_ptr, SL("options"), _2$$4, redirectDataAsQueries TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, tpl) {

	zval *tplId = NULL, *layoutId = NULL, *_0, *_1$$3, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &tplId, &layoutId);

	if (!tplId) {
		tplId = ZEPHIR_GLOBAL(global_null);
	}
	if (!layoutId) {
		layoutId = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "tpl", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	if (Z_TYPE_P(tplId) != IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "tplId", 1);
		zephir_update_property_array(this_ptr, SL("options"), _1$$3, tplId TSRMLS_CC);
	}
	if (Z_TYPE_P(layoutId) != IS_NULL) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "layoutId", 1);
		zephir_update_property_array(this_ptr, SL("options"), _2$$4, layoutId TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, setView) {

	zval *view;

	zephir_fetch_params(0, 1, 0, &view);



	zephir_update_property_this(this_ptr, SL("view"), view TSRMLS_CC);

}

PHP_METHOD(Nc_View_Facade, getView) {

	

	RETURN_MEMBER(this_ptr, "view");

}

PHP_METHOD(Nc_View_Facade, __invoke) {

	zval *_1$$3 = NULL;
	zend_bool _12;
	zval *view = NULL, *_13, *_14, *_0$$3, _2$$3 = zval_used_for_init, *_3$$3 = NULL, *_9$$3 = NULL, *_10$$3 = NULL, *_11$$3 = NULL, *_4$$6 = NULL, *_5$$6 = NULL, *_7$$6 = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	while (1) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("view"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(view, _0$$3);
		if (Z_TYPE_P(view) == IS_OBJECT) {
			if (zephir_instance_of_ev(view, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&view, view, NULL, 0);
				zephir_check_call_status();
			}
			break;
		}
		zephir_get_strval(_1$$3, view);
		ZEPHIR_CPY_WRT(view, _1$$3);
		ZEPHIR_SINIT_NVAR(_2$$3);
		ZVAL_STRING(&_2$$3, "\\", 0);
		ZEPHIR_INIT_NVAR(_3$$3);
		zephir_fast_strpos(_3$$3, view, &_2$$3, 0 );
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3$$3)) {
			ZEPHIR_INIT_NVAR(_4$$6);
			object_init_ex(_4$$6, nc_factory_namespaced_ce);
			ZEPHIR_INIT_NVAR(_5$$6);
			ZVAL_STRING(_5$$6, "Nc\\View", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _4$$6, "__construct", &_6, 144, _5$$6);
			zephir_check_temp_parameter(_5$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$6, _4$$6, "__get", &_8, 145, view);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(view, _7$$6);
			break;
		}
		ZEPHIR_INIT_NVAR(_9$$3);
		object_init_ex(_9$$3, nc_factory_namespaced_ce);
		ZEPHIR_INIT_NVAR(_10$$3);
		ZVAL_STRING(_10$$3, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _9$$3, "__construct", &_6, 144, _10$$3);
		zephir_check_temp_parameter(_10$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11$$3, _9$$3, "__get", &_8, 145, view);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(view, _11$$3);
		break;
	}
	_12 = Z_TYPE_P(view) != IS_OBJECT;
	if (!(_12)) {
		_12 = !((zephir_instance_of_ev(view, nc_view_viewinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_12)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_view_exception_ce, "Invalid view", "nc/view/facade.zep", 131);
		return;
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, view, "run", NULL, 0, _13, _14);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, setOptions) {

	HashTable *_1;
	HashPosition _0;
	zval *options_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	zephir_is_iterable(options, &_1, &_0, 0, 0, "nc/view/facade.zep", 144);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_update_property_array(this_ptr, SL("options"), k, v TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, getOptions) {

	

	RETURN_MEMBER(this_ptr, "options");

}

PHP_METHOD(Nc_View_Facade, __set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("options"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, __get) {

	zval *key_param = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, __isset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Nc_View_Facade, __unset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, setData) {

	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "nc/view/facade.zep", 182);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_update_property_array(this_ptr, SL("data"), k, v TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, getData) {

	

	RETURN_MEMBER(this_ptr, "data");

}

PHP_METHOD(Nc_View_Facade, offsetSet) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, offsetGet) {

	zval *key_param = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_View_Facade, offsetExists) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Nc_View_Facade, offsetUnset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

