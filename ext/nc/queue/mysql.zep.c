
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
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Queue_Mysql) {

	ZEPHIR_REGISTER_CLASS(Nc\\Queue, Mysql, nc, queue_mysql, nc_queue_mysql_method_entry, 0);

	zend_declare_property_null(nc_queue_mysql_ce, SL("daoMysql"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_queue_mysql_ce, SL("DDL"), "CREATE TABLE %s (id BIGINT UNSIGNED NOT NULL, ts INT UNSIGNED NOT NULL, PRIMARY KEY (id), KEY (ts)) ENGINE=InnoDB");

	zend_class_implements(nc_queue_mysql_ce TSRMLS_CC, 1, nc_queue_queueinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Queue_Mysql, __construct) {

	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval table;
	zval *db, db_sub, *table_param = NULL, _0, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&db_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &db, &table_param);

	zephir_get_strval(&table, table_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, nc_db_daomysql_ce);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "id");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 136, db, &table, &_1, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("daoMysql"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Queue_Mysql, getDaoMysql) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "daoMysql");

}

PHP_METHOD(Nc_Queue_Mysql, initialize) {

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
	ZVAL_STRING(&_4, "CREATE TABLE %s (id BIGINT UNSIGNED NOT NULL, ts INT UNSIGNED NOT NULL, PRIMARY KEY (id), KEY (ts)) ENGINE=InnoDB");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 2, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "execute", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Queue_Mysql, put) {

	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	long delay;
	zval *id_param = NULL, *delay_param = NULL, _0, _2;
	zval id;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &id_param, &delay_param);

	zephir_get_strval(&id, id_param);
	if (!delay_param) {
		delay = 0;
	} else {
		delay = zephir_get_intval(delay_param);
	}


	zephir_read_property(&_0, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("id"), &id, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	add_assoc_long_ex(&_1, SL("ts"), (zephir_get_numberval(&_2) + delay));
	ZEPHIR_CALL_METHOD(NULL, &_0, "repalce", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Queue_Mysql, reserve) {

	zval _4, _6, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ttr_param = NULL, now, rc, _3, _5, _8, _0$$3, _1$$3, _2$$3, _9$$4;
	long ttr;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&now);
	ZVAL_UNDEF(&rc);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ttr_param);

	ttr = zephir_get_intval(ttr_param);


	if (unlikely(ttr < 1)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, nc_queue_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "reserve");
		ZVAL_LONG(&_2$$3, 3);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "nc/queue/mysql.zep", 43 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&now);
	zephir_time(&now);
	zephir_read_property(&_3, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(&_4, SL("ts"), (zephir_get_numberval(&now) + ttr));
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "id = last_insert_id(id)");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(&_6, SL("ts >="), 1);
	zephir_array_update_string(&_6, SL("ts <="), &now, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(&_7, SL("ts"), 1);
	add_assoc_long_ex(&_7, SL("id"), 1);
	ZVAL_LONG(&_8, 1);
	ZEPHIR_CALL_METHOD(&rc, &_3, "updatetop", NULL, 0, &_4, &_6, &_7, &_8);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&rc, 0)) {
		zephir_read_property(&_9$$4, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_9$$4, "querylastinsertid", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STRING("");

}

PHP_METHOD(Nc_Queue_Mysql, delete) {

	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0;
	zval id;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("id ="), &id, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_0, "delete", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

