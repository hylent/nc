
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Nc_RateLimiter_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\RateLimiter, Mysql, nc, ratelimiter_mysql, nc_ratelimiter_ratelimiterbackendabstract_ce, nc_ratelimiter_mysql_method_entry, 0);

	zend_declare_property_null(nc_ratelimiter_mysql_ce, SL("daoMysql"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_ratelimiter_mysql_ce, SL("numRetries"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_ratelimiter_mysql_ce, SL("DDL"), "CREATE TABLE %s (name VARCHAR(200) NOT NULL, rate VARCHAR(1000) NOT NULL, ts INT UNSIGNED NOT NULL DEFAULT 0, PRIMARY KEY (name)) ENGINE=InnoDB");

	return SUCCESS;

}

PHP_METHOD(Nc_RateLimiter_Mysql, __construct) {

	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	long numRetries;
	zval table;
	zval *db, db_sub, *table_param = NULL, *numRetries_param = NULL, _0, _2, _3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&db_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &db, &table_param, &numRetries_param);

	zephir_get_strval(&table, table_param);
	if (!numRetries_param) {
		numRetries = 2;
	} else {
		numRetries = zephir_get_intval(numRetries_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_db_daomysql_ce);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "name");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 100, db, &table, &_1, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("daoMysql"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(&_3, numRetries);
	zephir_update_property_zval(this_ptr, SL("numRetries"), &_3);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_RateLimiter_Mysql, getDaoMysql) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "daoMysql");

}

PHP_METHOD(Nc_RateLimiter_Mysql, initialize) {

	zval _0, _1, _2, _3, _4, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getdb", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "gettable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "CREATE TABLE %s (name VARCHAR(200) NOT NULL, rate VARCHAR(1000) NOT NULL, ts INT UNSIGNED NOT NULL DEFAULT 0, PRIMARY KEY (name)) ENGINE=InnoDB");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 6, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "execute", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_RateLimiter_Mysql, getNumRetries) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "numRetries");

}

PHP_METHOD(Nc_RateLimiter_Mysql, passRateLimits) {

	zend_bool _5$$4, _25$$10;
	zend_string *_2, *_24$$6;
	zend_ulong _1, _23$$6;
	long numRetries;
	int ZEPHIR_LAST_CALL_STATUS, _3$$4, _4$$4;
	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL;
	zval rateLimits, _15$$6, _19$$8, _31$$14, _33$$14;
	zval *name_param = NULL, *rateLimits_param = NULL, __$true, now, s, t, item, rate, row, rateOld, itemOld, *_0, _11$$4, _12$$4, _13$$4, _6$$5, _7$$5, _8$$5, _14$$6, _16$$6, _17$$6, _21$$6, *_22$$6, _18$$8, _20$$8, _26$$10, _27$$10, _28$$10, _29$$10, _30$$14, _32$$14;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&now);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&t);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&rate);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&rateOld);
	ZVAL_UNDEF(&itemOld);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&rateLimits);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_33$$14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &rateLimits_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&rateLimits, rateLimits_param);


	ZEPHIR_INIT_VAR(&rate);
	array_init(&rate);
	numRetries = 0;
	if (zephir_fast_count_int(&rateLimits TSRMLS_CC) < 1) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&now);
	zephir_time(&now);
	zephir_is_iterable(&rateLimits, 0, "nc/ratelimiter/mysql.zep", 64);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&rateLimits), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&s);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&s, _2);
		} else {
			ZVAL_LONG(&s, _1);
		}
		ZEPHIR_INIT_NVAR(&t);
		ZVAL_COPY(&t, _0);
		_3$$4 = zephir_get_intval(&s);
		ZEPHIR_INIT_NVAR(&s);
		ZVAL_LONG(&s, _3$$4);
		_4$$4 = zephir_get_intval(&t);
		ZEPHIR_INIT_NVAR(&t);
		ZVAL_LONG(&t, _4$$4);
		_5$$4 = ZEPHIR_LT_LONG(&s, 1);
		if (!(_5$$4)) {
			_5$$4 = ZEPHIR_LT_LONG(&t, 1);
		}
		if (unlikely(_5$$4)) {
			ZEPHIR_INIT_NVAR(&_6$$5);
			object_init_ex(&_6$$5, nc_ratelimiter_exception_ce);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "Invalid input s/t '%d/%d'");
			ZEPHIR_CALL_FUNCTION(&_8$$5, "sprintf", &_9, 6, &_7$$5, &s, &t);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_10, 7, &_8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$5, "nc/ratelimiter/mysql.zep", 53 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&item);
		array_init(&item);
		ZEPHIR_INIT_LNVAR(_11$$4);
		div_function(&_11$$4, &now, &s TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_12$$4);
		ZVAL_LONG(&_12$$4, zephir_get_intval(&_11$$4));
		zephir_array_update_long(&item, 0, &_12$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		zephir_array_update_long(&item, 1, &t, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_NVAR(&_13$$4);
		ZVAL_LONG(&_13$$4, 1);
		zephir_array_update_long(&item, 2, &_13$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		zephir_array_update_zval(&rate, &s, &item, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&t);
	ZEPHIR_INIT_NVAR(&s);
	while (1) {
		zephir_read_property(&_14$$6, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_15$$6);
		zephir_create_array(&_15$$6, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_15$$6, SL("name ="), &name, PH_COPY | PH_SEPARATE);
		ZVAL_NULL(&_16$$6);
		ZVAL_BOOL(&_17$$6, 1);
		ZEPHIR_CALL_METHOD(&row, &_14$$6, "findfirst", NULL, 0, &_15$$6, &_16$$6, &_17$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(&row))) {

			/* try_start_1: */

				zephir_read_property(&_18$$8, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_19$$8);
				zephir_create_array(&_19$$8, 3, 0 TSRMLS_CC);
				zephir_array_update_string(&_19$$8, SL("name"), &name, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_20$$8);
				zephir_json_encode(&_20$$8, &rate, 0 );
				zephir_array_update_string(&_19$$8, SL("rate"), &_20$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_19$$8, SL("ts"), &now, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_18$$8, "insert", NULL, 0, &_19$$8);
				zephir_check_call_status_or_jump(try_end_1);
				RETURN_MM_BOOL(1);

			try_end_1:

			zend_clear_exception(TSRMLS_C);
			continue;
		}
		zephir_array_fetch_string(&_21$$6, &row, SL("rate"), PH_NOISY | PH_READONLY, "nc/ratelimiter/mysql.zep", 83 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&rateOld);
		zephir_json_decode(&rateOld, &_21$$6, zephir_get_intval(&__$true) );
		if (Z_TYPE_P(&rateOld) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&rateOld);
			array_init(&rateOld);
		}
		zephir_is_iterable(&rate, 1, "nc/ratelimiter/mysql.zep", 102);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&rate), _23$$6, _24$$6, _22$$6)
		{
			ZEPHIR_INIT_NVAR(&s);
			if (_24$$6 != NULL) { 
				ZVAL_STR_COPY(&s, _24$$6);
			} else {
				ZVAL_LONG(&s, _23$$6);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _22$$6);
			ZEPHIR_OBS_NVAR(&itemOld);
			_25$$10 = !(zephir_array_isset_fetch(&itemOld, &rateOld, &s, 0 TSRMLS_CC));
			if (!(_25$$10)) {
				_25$$10 = !zephir_is_true(&itemOld);
			}
			if (_25$$10) {
				continue;
			}
			zephir_array_fetch_long(&_26$$10, &itemOld, 0, PH_NOISY | PH_READONLY, "nc/ratelimiter/mysql.zep", 92 TSRMLS_CC);
			zephir_array_fetch_long(&_27$$10, &item, 0, PH_NOISY | PH_READONLY, "nc/ratelimiter/mysql.zep", 92 TSRMLS_CC);
			if (ZEPHIR_LT(&_26$$10, &_27$$10)) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&_28$$10);
			zephir_array_fetch_long(&_28$$10, &itemOld, 2, PH_NOISY, "nc/ratelimiter/mysql.zep", 95 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&t);
			ZVAL_LONG(&t, (zephir_get_intval(&_28$$10) + 1));
			zephir_array_fetch_long(&_29$$10, &item, 1, PH_NOISY | PH_READONLY, "nc/ratelimiter/mysql.zep", 96 TSRMLS_CC);
			if (ZEPHIR_GT(&t, &_29$$10)) {
				RETURN_MM_BOOL(0);
			}
			zephir_array_update_multi(&rate, &t TSRMLS_CC, SL("zl"), 2, &s, 2);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
		ZEPHIR_INIT_NVAR(&s);

		/* try_start_2: */

			zephir_read_property(&_30$$14, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_31$$14);
			zephir_create_array(&_31$$14, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_32$$14);
			zephir_json_encode(&_32$$14, &rate, 0 );
			zephir_array_update_string(&_31$$14, SL("rate"), &_32$$14, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_31$$14, SL("ts"), &now, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_33$$14);
			zephir_create_array(&_33$$14, 1, 0 TSRMLS_CC);
			zephir_array_update_string(&_33$$14, SL("name ="), &name, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_30$$14, "update", NULL, 0, &_31$$14, &_33$$14);
			zephir_check_call_status_or_jump(try_end_2);
			RETURN_MM_BOOL(1);

		try_end_2:

		zend_clear_exception(TSRMLS_C);
		numRetries++;
		zephir_read_property(&_16$$6, this_ptr, SL("numRetries"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_LT_LONG(&_16$$6, numRetries)) {
			break;
		}
	}
	RETURN_MM_BOOL(0);

}

