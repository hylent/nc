
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Message_Sender_MessageSenderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Message\\Sender, MessageSenderInterface, nc, message_sender_messagesenderinterface, nc_message_sender_messagesenderinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Message_Sender_MessageSenderInterface, send);

