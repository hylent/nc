
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Image_Item_Text) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Image\\Item, Text, nc, image_item_text, nc_image_item_imageitemabstract_ce, NULL, 0);

	return SUCCESS;

}

