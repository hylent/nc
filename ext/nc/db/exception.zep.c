
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


ZEPHIR_INIT_CLASS(Nc_Db_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Db, Exception, nc, db_exception, nc_exception_ce, NULL, 0);

	zephir_declare_class_constant_long(nc_db_exception_ce, SL("CONNECTION_NOT_SUPPORTED"), 1);

	zephir_declare_class_constant_long(nc_db_exception_ce, SL("CONNECTION_FAILURE"), 2);

	zephir_declare_class_constant_long(nc_db_exception_ce, SL("EXECUTION_FAILURE"), 3);

	zephir_declare_class_constant_long(nc_db_exception_ce, SL("TRANSACTION_FAILURE"), 4);

	zephir_declare_class_constant_long(nc_db_exception_ce, SL("QUERY_NOT_IMPLEMENTED"), 5);

	zephir_declare_class_constant_long(nc_db_exception_ce, SL("QUERY_INVALID_WHERE"), 6);

	zephir_declare_class_constant_long(nc_db_exception_ce, SL("UPSERT_PK_EMPTY"), 7);

	zephir_declare_class_constant_long(nc_db_exception_ce, SL("UPSERT_PK_UNSATISFIED"), 8);

	return SUCCESS;

}

