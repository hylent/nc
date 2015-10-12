
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Filter_IpRegion) {

	ZEPHIR_REGISTER_CLASS(Nc\\Filter, IpRegion, nc, filter_ipregion, nc_filter_ipregion_method_entry, 0);

	zend_declare_property_null(nc_filter_ipregion_ce, SL("dataPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_filter_ipregion_ce, SL("count"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_filter_ipregion_ce, SL("fileHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(nc_filter_ipregion_ce, SL("UNIT"), 12 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Filter_IpRegion, packItem) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	long region, vip1 = 0, vip2 = 0;
	zval *ip1, *ip2, *region_param = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, _6, _7, _8, _9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &ip1, &ip2, &region_param);

	region = zephir_get_intval(region_param);


	ZEPHIR_CALL_FUNCTION(&_0, "long2ip", &_1, 40, ip1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "ip2long", &_3, 41, _0);
	zephir_check_call_status();
	vip1 = zephir_get_intval(_2);
	ZEPHIR_CALL_FUNCTION(&_4, "long2ip", &_1, 40, ip2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "ip2long", &_3, 41, _4);
	zephir_check_call_status();
	vip2 = zephir_get_intval(_5);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "NNN", 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, vip1);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, vip2);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, region);
	ZEPHIR_RETURN_CALL_FUNCTION("pack", NULL, 42, &_6, &_7, &_8, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Filter_IpRegion, __construct) {

	long len = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dataPath_param = NULL, *_2 = NULL, *_5, *_0$$3, *_3$$4;
	zval *dataPath = NULL, *_1$$3, *_4$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dataPath_param);

	if (!dataPath_param) {
		ZEPHIR_INIT_VAR(dataPath);
		ZVAL_STRING(dataPath, "ipregion.dat", 1);
	} else {
		zephir_get_strval(dataPath, dataPath_param);
	}


	if (unlikely(!((zephir_file_exists(dataPath TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, nc_filter_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, "Invalid data path: ", dataPath);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "nc/filter/ipregion.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_2, "filesize", NULL, 43, dataPath);
	zephir_check_call_status();
	len = zephir_get_intval(_2);
	if (unlikely(len < 12)) {
		ZEPHIR_INIT_VAR(_3$$4);
		object_init_ex(_3$$4, nc_filter_exception_ce);
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_CONCAT_SV(_4$$4, "Invalid data file: ", dataPath);
		ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 2, _4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$4, "nc/filter/ipregion.zep", 33 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("dataPath"), dataPath TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, (long) (zephir_safe_div_long_long(len, 12 TSRMLS_CC)));
	zephir_update_property_this(this_ptr, SL("count"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Filter_IpRegion, count) {

	

	RETURN_MEMBER(this_ptr, "count");

}

PHP_METHOD(Nc_Filter_IpRegion, search) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *ip_param = NULL, *ipLong = NULL, *_0$$3;
	zval *ip = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ip_param);

	zephir_get_strval(ip, ip_param);


	ZEPHIR_CALL_FUNCTION(&ipLong, "ip2long", NULL, 41, ip);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(ipLong))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, nc_filter_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, "Invalid ip: ", ip);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "nc/filter/ipregion.zep", 51 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "searchlong", NULL, 0, ipLong);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Filter_IpRegion, searchLong) {

	zend_bool _12$$5, _13$$5;
	long high = 0, low = 0, pos = 0;
	double ipDouble = 0, i1 = 0, i2 = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL;
	zval *ipLong, *fp = NULL, *a = NULL, *_0 = NULL, *_2, *_3, *_4$$4, _5$$4, _6$$5 = zval_used_for_init, _7$$5 = zval_used_for_init, *_9$$5 = NULL, *_14$$5 = NULL, *_15$$5, *_16$$5 = NULL, *_17$$5, *_18$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ipLong);



	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "ulongtodouble", &_1, 44, ipLong);
	zephir_check_call_status();
	ipDouble = zephir_get_doubleval(_0);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("count"), PH_NOISY_CC);
	high = zephir_get_intval(_2);
	low = 0;
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("fileHandler"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		ZEPHIR_OBS_VAR(fp);
		zephir_read_property_this(&fp, this_ptr, SL("fileHandler"), PH_NOISY_CC);
	} else {
		_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("dataPath"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_STRING(&_5$$4, "r", 0);
		ZEPHIR_CALL_FUNCTION(&fp, "fopen", NULL, 45, _4$$4, &_5$$4);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("fileHandler"), fp TSRMLS_CC);
	}
	while (1) {
		pos = (long) (zephir_safe_div_long_long(((high + low)), 2 TSRMLS_CC));
		if ((pos - low) < 1) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_6$$5);
		ZVAL_LONG(&_6$$5, (12 * pos));
		ZEPHIR_SINIT_NVAR(_7$$5);
		ZVAL_LONG(&_7$$5, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "fseek", &_8, 46, fp, &_6$$5, &_7$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_6$$5);
		ZVAL_LONG(&_6$$5, 12);
		ZEPHIR_CALL_FUNCTION(&_9$$5, "fread", &_10, 47, fp, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_6$$5);
		ZVAL_STRING(&_6$$5, "Ni1/Ni2/Nr", 0);
		ZEPHIR_CALL_FUNCTION(&a, "unpack", &_11, 48, &_6$$5, _9$$5);
		zephir_check_call_status();
		_12$$5 = !(zephir_array_isset_string(a, SS("i1")));
		if (!(_12$$5)) {
			_12$$5 = !(zephir_array_isset_string(a, SS("i2")));
		}
		_13$$5 = _12$$5;
		if (!(_13$$5)) {
			_13$$5 = !(zephir_array_isset_string(a, SS("r")));
		}
		if (unlikely(_13$$5)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_filter_exception_ce, "Cannot read valid data", "nc/filter/ipregion.zep", 84);
			return;
		}
		zephir_array_fetch_string(&_15$$5, a, SL("i1"), PH_NOISY | PH_READONLY, "nc/filter/ipregion.zep", 87 TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_14$$5, nc_std_ce, "ulongtodouble", &_1, 44, _15$$5);
		zephir_check_call_status();
		i1 = zephir_get_doubleval(_14$$5);
		if (i1 > ipDouble) {
			high = pos;
			continue;
		}
		zephir_array_fetch_string(&_17$$5, a, SL("i2"), PH_NOISY | PH_READONLY, "nc/filter/ipregion.zep", 93 TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_16$$5, nc_std_ce, "ulongtodouble", &_1, 44, _17$$5);
		zephir_check_call_status();
		i2 = zephir_get_doubleval(_16$$5);
		if (i2 >= ipDouble) {
			ZEPHIR_OBS_NVAR(_18$$9);
			zephir_array_fetch_string(&_18$$9, a, SL("r"), PH_NOISY, "nc/filter/ipregion.zep", 95 TSRMLS_CC);
			RETURN_MM_LONG(zephir_get_intval(_18$$9));
		}
		low = pos;
	}
	RETURN_MM_LONG(0);

}

PHP_METHOD(Nc_Filter_IpRegion, __destruct) {

	zval *_0, *_1$$3;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fileHandler"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("fileHandler"), PH_NOISY_CC);
		zephir_fclose(_1$$3 TSRMLS_CC);
	}

}

