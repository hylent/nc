
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Nc_NetUtils_TcpSocketClient) {

	ZEPHIR_REGISTER_CLASS(Nc\\NetUtils, TcpSocketClient, nc, netutils_tcpsocketclient, nc_netutils_tcpsocketclient_method_entry, 0);

	zend_declare_property_null(nc_netutils_tcpsocketclient_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, __construct) {

	zval _2;
	zend_bool persistent = 0;
	long port = 0, connectTimeout = 0;
	int ZEPHIR_LAST_CALL_STATUS, _9$$3;
	zephir_fcall_cache_entry *_8 = NULL;
	zval *options_param = NULL, __$false, mergedOptions, host, address, flags, handler, errNo, errStr, _1, _3, _4, _5, _6, _7, _10$$4, _11$$4, _12$$4;
	zval options, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&mergedOptions);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&address);
	ZVAL_UNDEF(&flags);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&errNo);
	ZVAL_UNDEF(&errStr);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&errNo);
	ZVAL_NULL(&errNo);
	ZEPHIR_INIT_VAR(&errStr);
	ZVAL_NULL(&errStr);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("host"), SL(""));
	add_assoc_long_ex(&_0, SL("port"), 0);
	add_assoc_long_ex(&_0, SL("connectTimeout"), 5);
	zephir_array_update_string(&_0, SL("persistent"), &__$false, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&mergedOptions);
	zephir_add_function(&mergedOptions, &options, &_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_string(&_1, &mergedOptions, SL("host"), PH_NOISY, "nc/netutils/tcpsocketclient.zep", 19 TSRMLS_CC);
	zephir_get_strval(&_2, &_1);
	ZEPHIR_CPY_WRT(&host, &_2);
	ZEPHIR_OBS_VAR(&_3);
	zephir_array_fetch_string(&_3, &mergedOptions, SL("port"), PH_NOISY, "nc/netutils/tcpsocketclient.zep", 20 TSRMLS_CC);
	port = zephir_get_intval(&_3);
	ZEPHIR_OBS_VAR(&_4);
	zephir_array_fetch_string(&_4, &mergedOptions, SL("connectTimeout"), PH_NOISY, "nc/netutils/tcpsocketclient.zep", 21 TSRMLS_CC);
	connectTimeout = zephir_get_intval(&_4);
	ZEPHIR_OBS_VAR(&_5);
	zephir_array_fetch_string(&_5, &mergedOptions, SL("persistent"), PH_NOISY, "nc/netutils/tcpsocketclient.zep", 22 TSRMLS_CC);
	persistent = zephir_get_boolval(&_5);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "tcp://%s:%d");
	ZVAL_LONG(&_7, port);
	ZEPHIR_CALL_FUNCTION(&address, "sprintf", &_8, 6, &_6, &host, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&flags);
	ZVAL_LONG(&flags, 4);
	if (persistent) {
		_9$$3 = ((int) (zephir_get_numberval(&flags)) | 1);
		ZEPHIR_INIT_NVAR(&flags);
		ZVAL_LONG(&flags, _9$$3);
	}
	ZVAL_LONG(&_7, connectTimeout);
	ZEPHIR_MAKE_REF(&errNo);
	ZEPHIR_MAKE_REF(&errStr);
	ZEPHIR_CALL_FUNCTION(&handler, "stream_socket_client", NULL, 91, &address, &errNo, &errStr, &_7, &flags);
	ZEPHIR_UNREF(&errNo);
	ZEPHIR_UNREF(&errStr);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&handler))) {
		ZEPHIR_INIT_VAR(&_10$$4);
		object_init_ex(&_10$$4, nc_netutils_tcpsocketclientexception_ce);
		ZEPHIR_INIT_VAR(&_11$$4);
		ZVAL_STRING(&_11$$4, "Cannot connect to '%s' [%s] %s");
		ZEPHIR_CALL_FUNCTION(&_12$$4, "sprintf", &_8, 6, &_11$$4, &address, &errNo, &errStr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_10$$4, "__construct", NULL, 7, &_12$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$4, "nc/netutils/tcpsocketclient.zep", 32 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("handler"), &handler);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, __destruct) {

	zval _0, _1$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
		zephir_fclose(&_1$$3 TSRMLS_CC);
	}

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, getInternalHandler) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, setTcpNodelay) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *on_param = NULL, socket, _0, _1, _2, _3, _4;
	zend_bool on;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&socket);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &on_param);

	on = zephir_get_boolval(on_param);


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&socket, "socket_import_stream", NULL, 92, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&socket))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Failed on 'socket_import_stream'", "nc/netutils/tcpsocketclient.zep", 56);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	if (on) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, 1);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, 0);
	}
	ZVAL_LONG(&_2, 6);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "socket_set_option", NULL, 93, &socket, &_2, &_3, &_1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_4))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Cannot set SOL_TCP TCP_NODELAY", "nc/netutils/tcpsocketclient.zep", 60);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, setBlocking) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *on_param = NULL, _0, _1, _2;
	zend_bool on;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &on_param);

	on = zephir_get_boolval(on_param);


	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (on) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, 1);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, 0);
	}
	ZEPHIR_CALL_FUNCTION(&_2, "stream_set_blocking", NULL, 94, &_0, &_1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Cannot set blocking", "nc/netutils/tcpsocketclient.zep", 67);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, setTimeout) {

	long seconds = 0, microSeconds = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *timeout_param = NULL, _0, _1, _2, _3;
	double timeout;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timeout_param);

	timeout = zephir_get_doubleval(timeout_param);


	if (unlikely(timeout < 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Cannot set timeout to negative value", "nc/netutils/tcpsocketclient.zep", 76);
		return;
	}
	seconds = (long) (timeout);
	microSeconds = (long) ((((timeout -  (double) seconds)) * 1000000.0));
	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, seconds);
	ZVAL_LONG(&_2, microSeconds);
	ZEPHIR_CALL_FUNCTION(&_3, "stream_set_timeout", NULL, 95, &_0, &_1, &_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Failed on 'stream_set_timeout'", "nc/netutils/tcpsocketclient.zep", 83);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, enableCrypto) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cryptoType, cryptoType_sub, __$true, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&cryptoType_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cryptoType);



	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "stream_socket_enable_crypto", NULL, 96, &_0, &__$true, cryptoType);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Failed on 'stream_socket_enable_crypto'", "nc/netutils/tcpsocketclient.zep", 90);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, write) {

	zval *data_param = NULL, _0, _1;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	zephir_fwrite(&_0, &_1, &data TSRMLS_CC);
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Cannot write", "nc/netutils/tcpsocketclient.zep", 97);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, readLine) {

	zval line, _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&line, "fgets", NULL, 97, &_0);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Cannot read line", "nc/netutils/tcpsocketclient.zep", 107);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, readAll) {

	zval line, _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&line, "stream_get_contents", NULL, 98, &_0);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Cannot read all", "nc/netutils/tcpsocketclient.zep", 119);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, readLength) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, line, _4, _5, _0$$3, _1$$3, _2$$3, _3$$3;
	long len;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	if (unlikely(len < 1)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, nc_netutils_tcpsocketclientexception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Invalid read length '%d'");
		ZVAL_LONG(&_2$$3, len);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 6, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 7, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "nc/netutils/tcpsocketclient.zep", 130 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, len);
	ZEPHIR_CALL_FUNCTION(&line, "stream_get_contents", NULL, 98, &_4, &_5);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Cannot read length", "nc/netutils/tcpsocketclient.zep", 135);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Nc_NetUtils_TcpSocketClient, readMaxLength) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, line, _4, _5, _0$$3, _1$$3, _2$$3, _3$$3;
	long len;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	if (unlikely(len < 1)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, nc_netutils_tcpsocketclientexception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Invalid read max length '%d'");
		ZVAL_LONG(&_2$$3, len);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 6, &_1$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 7, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "nc/netutils/tcpsocketclient.zep", 146 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, len);
	ZEPHIR_CALL_FUNCTION(&line, "fread", NULL, 99, &_4, &_5);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(&line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_tcpsocketclientexception_ce, "Cannot read max length", "nc/netutils/tcpsocketclient.zep", 151);
		return;
	}
	RETURN_CCTOR(line);

}

