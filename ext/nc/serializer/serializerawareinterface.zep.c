
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Serializer_SerializerAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Serializer, SerializerAwareInterface, nc, serializer_serializerawareinterface, nc_serializer_serializerawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Serializer_SerializerAwareInterface, setSerializer);

ZEPHIR_DOC_METHOD(Nc_Serializer_SerializerAwareInterface, getSerializer);

