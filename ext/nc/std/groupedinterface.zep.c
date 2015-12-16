
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Std_GroupedInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Std, GroupedInterface, nc, std_groupedinterface, nc_std_groupedinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, setGrouped);

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, getGrouped);

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, deleteGrouped);

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, setManyGrouped);

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, getManyGrouped);

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, deleteManyGrouped);

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, setAllGrouped);

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, getAllGrouped);

ZEPHIR_DOC_METHOD(Nc_Std_GroupedInterface, deleteAllGrouped);

