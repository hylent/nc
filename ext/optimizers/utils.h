#ifndef _NC_OPTIMIZERS_UTILS_H
#define _NC_OPTIMIZERS_UTILS_H

#include <Zend/zend.h>

void nc_utils_crc16(zval *return_value, zval *str);
void nc_utils_serial(zval *return_value TSRMLS_DC);

#endif // _NC_OPTIMIZERS_UTILS_H
