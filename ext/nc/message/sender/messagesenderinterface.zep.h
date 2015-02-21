
extern zend_class_entry *nc_message_sender_messagesenderinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Message_Sender_MessageSenderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_message_sender_messagesenderinterface_send, 0, 0, 3)
	ZEND_ARG_INFO(0, to)
	ZEND_ARG_INFO(0, subject)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_message_sender_messagesenderinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Message_Sender_MessageSenderInterface, send, arginfo_nc_message_sender_messagesenderinterface_send)
  PHP_FE_END
};
