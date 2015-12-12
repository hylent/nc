
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Data_Pivot) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Data, Pivot, nc, data_pivot, nc_data_dataabstract_ce, nc_data_pivot_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Data_Pivot, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	long score;
	zval *subj_param = NULL, *obj_param = NULL, *score_param = NULL, *_0, *_1, *_2;
	zval *subj = NULL, *obj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &subj_param, &obj_param, &score_param);

	zephir_get_strval(subj, subj_param);
	zephir_get_strval(obj, obj_param);
	score = zephir_get_intval(score_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, score);
	ZEPHIR_CALL_METHOD(NULL, _0, "addpivot", NULL, 0, _1, subj, obj, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Pivot, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *subj_param = NULL, *obj_param = NULL, *_0, *_1;
	zval *subj = NULL, *obj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subj_param, &obj_param);

	zephir_get_strval(subj, subj_param);
	zephir_get_strval(obj, obj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "removepivot", NULL, 0, _1, subj, obj);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Pivot, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *subj_param = NULL, *obj_param = NULL, *_0, *_1;
	zval *subj = NULL, *obj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subj_param, &obj_param);

	zephir_get_strval(subj, subj_param);
	zephir_get_strval(obj, obj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "haspivot", NULL, 0, _1, subj, obj);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Pivot, addObjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *objScores = NULL;
	zval *subj_param = NULL, *objScores_param = NULL, *_0, *_1;
	zval *subj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subj_param, &objScores_param);

	zephir_get_strval(subj, subj_param);
	zephir_get_arrval(objScores, objScores_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "addobjectspivot", NULL, 0, _1, subj, objScores);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Pivot, removeObjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *objs = NULL;
	zval *subj_param = NULL, *objs_param = NULL, *_0, *_1;
	zval *subj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subj_param, &objs_param);

	zephir_get_strval(subj, subj_param);
	zephir_get_arrval(objs, objs_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "removeobjectspivot", NULL, 0, _1, subj, objs);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Pivot, hasObjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *objs = NULL;
	zval *subj_param = NULL, *objs_param = NULL, *_0, *_1;
	zval *subj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subj_param, &objs_param);

	zephir_get_strval(subj, subj_param);
	zephir_get_arrval(objs, objs_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "hasobjectspivot", NULL, 0, _1, subj, objs);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Pivot, getObjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *subj_param = NULL, *_0, *_1;
	zval *subj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &subj_param);

	zephir_get_strval(subj, subj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getobjectspivot", NULL, 0, _1, subj);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Pivot, countObjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *subj_param = NULL, *_0, *_1;
	zval *subj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &subj_param);

	zephir_get_strval(subj, subj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "countobjectspivot", NULL, 0, _1, subj);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Pivot, countAndGetObjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	long limit, skip;
	zend_bool asc;
	zval *subj_param = NULL, *asc_param = NULL, *limit_param = NULL, *skip_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *subj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &subj_param, &asc_param, &limit_param, &skip_param);

	zephir_get_strval(subj, subj_param);
	if (!asc_param) {
		asc = 0;
	} else {
		asc = zephir_get_boolval(asc_param);
	}
	if (!limit_param) {
		limit = 50;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!skip_param) {
		skip = 0;
	} else {
		skip = zephir_get_intval(skip_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	if (asc) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, limit);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, skip);
	ZEPHIR_RETURN_CALL_METHOD(_0, "countandgetobjectspivot", NULL, 0, _1, subj, _2, _3, _4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Pivot, addSubjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *obj = NULL;
	zval *subjScores_param = NULL, *obj_param = NULL, *_0, *_1;
	zval *subjScores = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subjScores_param, &obj_param);

	zephir_get_arrval(subjScores, subjScores_param);
	zephir_get_strval(obj, obj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "addsubjectspivot", NULL, 0, _1, subjScores, obj);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Pivot, removeSubjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *obj = NULL;
	zval *subjs_param = NULL, *obj_param = NULL, *_0, *_1;
	zval *subjs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subjs_param, &obj_param);

	zephir_get_arrval(subjs, subjs_param);
	zephir_get_strval(obj, obj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "removesubjectspivot", NULL, 0, _1, subjs, obj);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Data_Pivot, hasSubjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *obj = NULL;
	zval *subjs_param = NULL, *obj_param = NULL, *_0, *_1;
	zval *subjs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subjs_param, &obj_param);

	zephir_get_arrval(subjs, subjs_param);
	zephir_get_strval(obj, obj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "hassubjectspivot", NULL, 0, _1, subjs, obj);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Pivot, getSubjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *obj_param = NULL, *_0, *_1;
	zval *obj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj_param);

	zephir_get_strval(obj, obj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getsubjectspivot", NULL, 0, _1, obj);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Pivot, countSubjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *obj_param = NULL, *_0, *_1;
	zval *obj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj_param);

	zephir_get_strval(obj, obj_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "countsubjectspivot", NULL, 0, _1, obj);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Data_Pivot, countAndGetSubjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	long limit, skip;
	zend_bool asc;
	zval *obj_param = NULL, *asc_param = NULL, *limit_param = NULL, *skip_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *obj = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &obj_param, &asc_param, &limit_param, &skip_param);

	zephir_get_strval(obj, obj_param);
	if (!asc_param) {
		asc = 0;
	} else {
		asc = zephir_get_boolval(asc_param);
	}
	if (!limit_param) {
		limit = 50;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!skip_param) {
		skip = 0;
	} else {
		skip = zephir_get_intval(skip_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	if (asc) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, limit);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, skip);
	ZEPHIR_RETURN_CALL_METHOD(_0, "countandgetsubjectspivot", NULL, 0, _1, obj, _2, _3, _4);
	zephir_check_call_status();
	RETURN_MM();

}

