
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

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("READ"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("WRITE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("FETCH_MASK"), 0xf0 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("ALL"), 0x10 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("ROW"), 0x20 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("ONE"), 0x30 TSRMLS_CC);

	zend_declare_class_constant_long(nc_db_dbinterface_ce, SL("COLUMN"), 0x40 TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, inTransaction);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, begin);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, commit);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, rollback);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, savepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, releaseSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, releaseLastSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, rollbackToSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, rollbackToLastSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, transactionAtomic);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, savepointAtomic);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, atomic);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, quote);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, query);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, setQueryClass);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, getQueryClass);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, __invoke);

