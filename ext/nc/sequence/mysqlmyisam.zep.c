
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


ZEPHIR_INIT_CLASS(Nc_Sequence_MysqlMyisam) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Sequence, MysqlMyisam, nc, sequence_mysqlmyisam, nc_sequence_sequencebackendabstract_ce, nc_sequence_mysqlmyisam_method_entry, 0);

	zend_declare_property_null(nc_sequence_mysqlmyisam_ce, SL("daoMysql"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_sequence_mysqlmyisam_ce, SL("DDL"), "CREATE TABLE %s (name VARCHAR(100) NOT NULL, sequence BIGINT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY (name, sequence), UNIQUE KEY(name)) ENGINE=MyISAM");

	return SUCCESS;

}

PHP_METHOD(Nc_Sequence_MysqlMyisam, __construct) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table;
	zval *db, db_sub, *table_param = NULL, _0, _2;
	zval *this_ptr = getThis();

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
	ZVAL_STRING(&_2, "sequence");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 135, db, &table, &_1, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("daoMysql"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_MysqlMyisam, getDaoMysql) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "daoMysql");

}

PHP_METHOD(Nc_Sequence_MysqlMyisam, initialize) {

	zval _0, _1, _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

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
	ZVAL_STRING(&_4, "CREATE TABLE %s (name VARCHAR(100) NOT NULL, sequence BIGINT UNSIGNED NOT NULL AUTO_INCREMENT, PRIMARY KEY (name, sequence), UNIQUE KEY(name)) ENGINE=MyISAM");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 2, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "execute", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Sequence_MysqlMyisam, next) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _2, _3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "querylastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_3));

}

PHP_METHOD(Nc_Sequence_MysqlMyisam, restore) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	long sequence;
	zval *name_param = NULL, *sequence_param = NULL, _0, _2;
	zval name;
	zval *this_ptr = getThis();

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

PHP_METHOD(Nc_Sequence_MysqlMyisam, clear) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("daoMysql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "delete", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

