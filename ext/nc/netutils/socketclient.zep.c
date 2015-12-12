
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Nc_NetUtils_SocketClient) {

	ZEPHIR_REGISTER_CLASS(Nc\\NetUtils, SocketClient, nc, netutils_socketclient, nc_netutils_socketclient_method_entry, 0);

	zend_declare_property_null(nc_netutils_socketclient_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_NetUtils_SocketClient, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool persistent;
	long port, connectTimeout, flags = 0;
	zval *host_param = NULL, *port_param = NULL, *connectTimeout_param = NULL, *persistent_param = NULL, *handler = NULL, *errNo = NULL, *errStr = NULL, _0, _1, *_2 = NULL, *_4, *_5, *_6$$4, *_7$$4;
	zval *host = NULL, *address = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &host_param, &port_param, &connectTimeout_param, &persistent_param);

	zephir_get_strval(host, host_param);
	port = zephir_get_intval(port_param);
	if (!connectTimeout_param) {
		connectTimeout = 5;
	} else {
		connectTimeout = zephir_get_intval(connectTimeout_param);
	}
	if (!persistent_param) {
		persistent = 0;
	} else {
		persistent = zephir_get_boolval(persistent_param);
	}


	ZEPHIR_INIT_VAR(errNo);
	ZVAL_NULL(errNo);
	ZEPHIR_INIT_VAR(errStr);
	ZVAL_NULL(errStr);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "tcp://%s:%d", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, port);
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_0, host, &_1);
	zephir_check_call_status();
	zephir_get_strval(_3, _2);
	ZEPHIR_CPY_WRT(address, _3);
	flags = 4;
	if (persistent) {
		flags = (flags | 1);
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, connectTimeout);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, flags);
	ZEPHIR_MAKE_REF(errNo);
	ZEPHIR_CALL_FUNCTION(&handler, "stream_socket_client", NULL, 96, address, errNo, errStr, _4, _5);
	ZEPHIR_UNREF(errNo);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, nc_netutils_exception_ce);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_SVSVSV(_7$$4, "Cannot connect to ", address, " [", errNo, "]", errStr);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 2, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "nc/netutils/socketclient.zep", 21 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("handler"), handler TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SocketClient, __destruct) {

	zval *_0, *_1$$3;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		zephir_fclose(_1$$3 TSRMLS_CC);
	}

}

PHP_METHOD(Nc_NetUtils_SocketClient, getInternalHandler) {

	

	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Nc_NetUtils_SocketClient, setTcpNodelay) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *on_param = NULL, *socket = NULL, *_0, *_1 = NULL, _2, _3, *_4 = NULL;
	zend_bool on;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &on_param);

	on = zephir_get_boolval(on_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&socket, "socket_import_stream", NULL, 97, _0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(socket))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Failed: socket_import_stream", "nc/netutils/socketclient.zep", 45);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	if (on) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 1);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 6);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "socket_set_option", NULL, 98, socket, &_2, &_3, _1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Cannot set SOL_TCP TCP_NODELAY", "nc/netutils/socketclient.zep", 49);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SocketClient, setBlocking) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *on_param = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zend_bool on;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &on_param);

	on = zephir_get_boolval(on_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (on) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 1);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
	}
	ZEPHIR_CALL_FUNCTION(&_2, "stream_set_blocking", NULL, 99, _0, _1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Cannot set blocking", "nc/netutils/socketclient.zep", 56);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SocketClient, setTimeout) {

	long seconds = 0, microSeconds = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *timeout_param = NULL, *_0, _1, _2, *_3 = NULL;
	double timeout;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timeout_param);

	timeout = zephir_get_doubleval(timeout_param);


	if (unlikely(timeout < 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Cannot set timeout to negative value", "nc/netutils/socketclient.zep", 65);
		return;
	}
	seconds = (long) (timeout);
	microSeconds = (long) ((((timeout -  (double) seconds)) * 1000000.0));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, seconds);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, microSeconds);
	ZEPHIR_CALL_FUNCTION(&_3, "stream_set_timeout", NULL, 100, _0, &_1, &_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Failed: stream_set_timeout", "nc/netutils/socketclient.zep", 72);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SocketClient, enableCrypto) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cryptoType, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cryptoType);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "stream_socket_enable_crypto", NULL, 101, _0, ZEPHIR_GLOBAL(global_true), cryptoType);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Failed: stream_socket_enable_crypto", "nc/netutils/socketclient.zep", 79);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SocketClient, write) {

	zval *data_param = NULL, *_0, *_1;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	zephir_fwrite(_0, _1, data TSRMLS_CC);
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Cannot write", "nc/netutils/socketclient.zep", 86);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SocketClient, readLine) {

	zval *line = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&line, "fgets", NULL, 102, _0);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Cannot read line", "nc/netutils/socketclient.zep", 96);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Nc_NetUtils_SocketClient, readAll) {

	zval *line = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&line, "stream_get_contents", NULL, 103, _0);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Cannot read all", "nc/netutils/socketclient.zep", 108);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Nc_NetUtils_SocketClient, readLength) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, *line = NULL, *_4, _5, *_0$$3, _1$$3, *_2$$3 = NULL, *_3$$3;
	long len;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	if (unlikely(len < 1)) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, nc_netutils_exception_ce);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, len);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strval", NULL, 23, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid read length: ", _2$$3);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "nc/netutils/socketclient.zep", 119 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, len);
	ZEPHIR_CALL_FUNCTION(&line, "stream_get_contents", NULL, 103, _4, &_5);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Cannot read length", "nc/netutils/socketclient.zep", 124);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Nc_NetUtils_SocketClient, readMaxLength) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, *line = NULL, *_4, _5, *_0$$3, _1$$3, *_2$$3 = NULL, *_3$$3;
	long len;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	if (unlikely(len < 1)) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, nc_netutils_exception_ce);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, len);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strval", NULL, 23, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid read max length: ", _2$$3);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "nc/netutils/socketclient.zep", 135 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, len);
	ZEPHIR_CALL_FUNCTION(&line, "fread", NULL, 104, _4, &_5);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "Cannot read max length", "nc/netutils/socketclient.zep", 140);
		return;
	}
	RETURN_CCTOR(line);

}

