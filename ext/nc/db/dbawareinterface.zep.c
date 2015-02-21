
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Db_DbAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Db, DbAwareInterface, nc, db_dbawareinterface, nc_db_dbawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Db_DbAwareInterface, setDb);

ZEPHIR_DOC_METHOD(Nc_Db_DbAwareInterface, getDb);

