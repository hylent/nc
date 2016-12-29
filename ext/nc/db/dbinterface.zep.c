
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

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, inTransaction);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, begin);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, commit);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, rollback);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, savepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, releaseSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, rollbackToSavepoint);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, quote);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, expression);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, execute);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, query);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, queryRow);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, queryCell);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, queryVector);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, queryMap);

ZEPHIR_DOC_METHOD(Nc_Db_DbInterface, getSqls);

