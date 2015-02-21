
extern zend_class_entry *nc_serializer_serializerawareinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Serializer_SerializerAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_serializer_serializerawareinterface_setserializer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, serializer, Nc\\Serializer\\SerializerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_serializer_serializerawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Serializer_SerializerAwareInterface, setSerializer, arginfo_nc_serializer_serializerawareinterface_setserializer)
	PHP_ABSTRACT_ME(Nc_Serializer_SerializerAwareInterface, getSerializer, NULL)
  PHP_FE_END
};
