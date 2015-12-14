
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Db_DbInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Db, DbInterface, nc, db_dbinterface, nc_db_dbinterface_method_entry);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("ALL"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("ROW"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("CELL"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("COLUMNS"), 4 TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, getInternalHandler);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, getQueries);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, quote);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, query);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, inTransaction);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, begin);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, commit);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, rollback);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, savepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, releaseSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, releaseLastSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, rollbackToSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, rollbackToLastSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, insert);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, delete);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, update);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, upsert);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, select);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, countAndSelect);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, selectUnionAll);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, countAndSelectUnionAll);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, count);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, max);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, min);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, sum);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, avg);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, aggregation);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, aggregations);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, groupAggregations);

