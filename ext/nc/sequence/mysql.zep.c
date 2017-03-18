
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


ZEPHIR_INIT_CLASS(Nc_Sequence_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Sequence, Mysql, nc, sequence_mysql, nc_sequence_sequencebackendabstract_ce, nc_sequence_mysql_method_entry, 0);

	zend_declare_property_null(nc_sequence_mysql_ce, SL("daoMysql"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_sequence_mysql_ce, SL("DDL"), "CREATE TABLE %s (name VARCHAR(100) NOT NULL, sequence BIGINT UNSIGNED NOT NULL, PRIMARY KEY (name)) ENGINE=InnoDB");

	return SUCCESS;

}

PHP_METHOD(Nc_Sequence_Mysql, __construct) {

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
	ZVAL_STRING(&_2, "name");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 127, db, &table, &_1, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("daoMysql"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_Mysql, getDaoMysql) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "daoMysql");

}

PHP_METHOD(Nc_Sequence_Mysql, initialize) {

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
	ZVAL_STRING(&_4, "CREATE TABLE %s (name VARCHAR(100) NOT NULL, sequence BIGINT UNSIGNED NOT NULL, PRIMARY KEY (name)) ENGINE=InnoDB");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 2, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "execute", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_Mysql, next) {

	zval _1, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _3, _4, _5;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "last_insert_id(1)");
	zephir_array_fast_append(&_2, &_3);
	zephir_array_update_string(&_1, SL("sequence"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "sequence = last_insert_id(sequence + 1)");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_METHOD(NULL, &_0, "upsert", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "querylastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_5));

}

PHP_METHOD(Nc_Sequence_Mysql, restore) {

	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	long sequence;
	zval *name_param = NULL, *sequence_param = NULL, _0, _2;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &sequence_param);

	zephir_get_strval(&name, name_param);
	sequence = zephir_get_intval(sequence_param);


	zephir_read_property(&_0, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, sequence);
	zephir_array_update_string(&_1, SL("sequence"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_Mysql, clear) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "delete", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

