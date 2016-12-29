
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Nc_NetUtils_Smtp) {

	ZEPHIR_REGISTER_CLASS(Nc\\NetUtils, Smtp, nc, netutils_smtp, nc_netutils_smtp_method_entry, 0);

	zend_declare_property_null(nc_netutils_smtp_ce, SL("tcpSocketClient"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_netutils_smtp_ce, SL("sender"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_netutils_smtp_ce, SL("namedSender"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_netutils_smtp_ce, SL("CRLF"), "\r\n");

	return SUCCESS;

}

PHP_METHOD(Nc_NetUtils_Smtp, pack) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *addr_param = NULL, _0, _3, _1$$3, _2$$3;
	zval name, addr, s, _4$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&addr);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &addr_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!addr_param) {
		ZEPHIR_INIT_VAR(&addr);
		ZVAL_STRING(&addr, "");
	} else {
		zephir_get_strval(&addr, addr_param);
	}


	ZEPHIR_INIT_VAR(&s);
	ZVAL_STRING(&s, "");
	if (zephir_fast_strlen_ev(&name) > 0) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "base64_encode", NULL, 81, &name);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "=?UTF-8?B?", &_1$$3, "?=");
		zephir_concat_self(&s, &_2$$3 TSRMLS_CC);
	}
	if (zephir_fast_strlen_ev(&addr) > 0) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "<", &addr, ">");
		zephir_concat_self(&s, &_4$$4 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Nc_NetUtils_Smtp, __construct) {

	zval _3, _5, _7, _9;
	double timeout = 0;
	zephir_fcall_cache_entry *_20 = NULL, *_25 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, secure;
	zval *options_param = NULL, __$false, mergedOptions, user, passwd, from, name, tcpSocketClient, _1, _2, _4, _6, _8, _10, _11, _12, _13, _14, _15, _19, _24, _26, _16$$6, _17$$7, _18$$7, _21$$8, _22$$8, _23$$8;
	zval options, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&mergedOptions);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&passwd);
	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tcpSocketClient);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	secure = 0;
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 11, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("host"), SL(""));
	add_assoc_long_ex(&_0, SL("port"), 25);
	add_assoc_long_ex(&_0, SL("connectTimeout"), 10);
	zephir_array_update_string(&_0, SL("persistent"), &__$false, PH_COPY | PH_SEPARATE);
	add_assoc_double_ex(&_0, SL("timeout"), 5.0);
	add_assoc_stringl_ex(&_0, SL("user"), SL(""));
	add_assoc_stringl_ex(&_0, SL("passwd"), SL(""));
	add_assoc_stringl_ex(&_0, SL("from"), SL(""));
	add_assoc_stringl_ex(&_0, SL("name"), SL(""));
	zephir_array_update_string(&_0, SL("ssl"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("tls"), &__$false, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&mergedOptions);
	zephir_add_function(&mergedOptions, &options, &_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_string(&_1, &mergedOptions, SL("timeout"), PH_NOISY, "nc/netutils/smtp.zep", 45 TSRMLS_CC);
	timeout = zephir_get_doubleval(&_1);
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch_string(&_2, &mergedOptions, SL("user"), PH_NOISY, "nc/netutils/smtp.zep", 46 TSRMLS_CC);
	zephir_get_strval(&_3, &_2);
	ZEPHIR_CPY_WRT(&user, &_3);
	ZEPHIR_OBS_VAR(&_4);
	zephir_array_fetch_string(&_4, &mergedOptions, SL("passwd"), PH_NOISY, "nc/netutils/smtp.zep", 47 TSRMLS_CC);
	zephir_get_strval(&_5, &_4);
	ZEPHIR_CPY_WRT(&passwd, &_5);
	ZEPHIR_OBS_VAR(&_6);
	zephir_array_fetch_string(&_6, &mergedOptions, SL("from"), PH_NOISY, "nc/netutils/smtp.zep", 48 TSRMLS_CC);
	zephir_get_strval(&_7, &_6);
	ZEPHIR_CPY_WRT(&from, &_7);
	ZEPHIR_OBS_VAR(&_8);
	zephir_array_fetch_string(&_8, &mergedOptions, SL("name"), PH_NOISY, "nc/netutils/smtp.zep", 49 TSRMLS_CC);
	zephir_get_strval(&_9, &_8);
	ZEPHIR_CPY_WRT(&name, &_9);
	zephir_array_fetch_string(&_10, &mergedOptions, SL("ssl"), PH_NOISY | PH_READONLY, "nc/netutils/smtp.zep", 51 TSRMLS_CC);
	if (zephir_is_true(&_10)) {
		secure = 1;
	}
	zephir_array_fetch_string(&_11, &mergedOptions, SL("tls"), PH_NOISY | PH_READONLY, "nc/netutils/smtp.zep", 54 TSRMLS_CC);
	if (zephir_is_true(&_11)) {
		secure = 2;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&from, "")) {
		ZEPHIR_CPY_WRT(&from, &user);
	}
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "");
	ZEPHIR_CALL_SELF(&_12, "pack", NULL, 0, &_13, &from);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("sender"), &_12);
	ZEPHIR_CALL_SELF(&_14, "pack", NULL, 0, &name, &from);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("namedSender"), &_14);
	ZEPHIR_INIT_VAR(&tcpSocketClient);
	object_init_ex(&tcpSocketClient, nc_netutils_tcpsocketclient_ce);
	ZEPHIR_CALL_METHOD(NULL, &tcpSocketClient, "__construct", NULL, 82, &mergedOptions);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("tcpSocketClient"), &tcpSocketClient);
	ZVAL_BOOL(&_15, 1);
	ZEPHIR_CALL_METHOD(NULL, &tcpSocketClient, "settcpnodelay", NULL, 83, &_15);
	zephir_check_call_status();
	ZVAL_BOOL(&_15, 1);
	ZEPHIR_CALL_METHOD(NULL, &tcpSocketClient, "setblocking", NULL, 84, &_15);
	zephir_check_call_status();
	if (timeout > 0) {
		ZVAL_DOUBLE(&_16$$6, timeout);
		ZEPHIR_CALL_METHOD(NULL, &tcpSocketClient, "settimeout", NULL, 85, &_16$$6);
		zephir_check_call_status();
	}
	if (secure == 1) {
		ZEPHIR_INIT_VAR(&_17$$7);
		ZVAL_STRING(&_17$$7, "STREAM_CRYPTO_METHOD_SSLv23_CLIENT");
		ZEPHIR_CALL_FUNCTION(&_18$$7, "constant", NULL, 86, &_17$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &tcpSocketClient, "enablecrypto", NULL, 87, &_18$$7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "CONNECT");
	ZEPHIR_INIT_VAR(&_19);
	ZVAL_STRING(&_19, "");
	ZVAL_LONG(&_15, 220);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_20, 0, &_13, &_19, &_15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "EHLO HELO");
	ZEPHIR_INIT_NVAR(&_19);
	ZVAL_STRING(&_19, "EHLO HELO");
	ZVAL_LONG(&_15, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_20, 0, &_13, &_19, &_15);
	zephir_check_call_status();
	if (secure == 2) {
		ZEPHIR_INIT_VAR(&_21$$8);
		ZVAL_STRING(&_21$$8, "STARTTLS");
		ZEPHIR_INIT_VAR(&_22$$8);
		ZVAL_STRING(&_22$$8, "STARTTLS");
		ZVAL_LONG(&_23$$8, 220);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_20, 0, &_21$$8, &_22$$8, &_23$$8);
		zephir_check_call_status();
		ZVAL_LONG(&_23$$8, 9);
		ZEPHIR_CALL_METHOD(NULL, &tcpSocketClient, "enablecrypto", NULL, 87, &_23$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_21$$8);
		ZVAL_STRING(&_21$$8, "EHLO HELO");
		ZEPHIR_INIT_NVAR(&_22$$8);
		ZVAL_STRING(&_22$$8, "EHLO HELO");
		ZVAL_LONG(&_23$$8, 250);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_20, 0, &_21$$8, &_22$$8, &_23$$8);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "AUTH LOGIN");
	ZEPHIR_INIT_NVAR(&_19);
	ZVAL_STRING(&_19, "AUTH LOGIN");
	ZVAL_LONG(&_15, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_20, 0, &_13, &_19, &_15);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_24, "base64_encode", &_25, 81, &user);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "AUTH USER");
	ZVAL_LONG(&_15, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_20, 0, &_13, &_24, &_15);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_26, "base64_encode", &_25, 81, &passwd);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "AUTH PASSWD");
	ZVAL_LONG(&_15, 235);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_20, 0, &_13, &_26, &_15);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_Smtp, getTcpSocketClient) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "tcpSocketClient");

}

PHP_METHOD(Nc_NetUtils_Smtp, sendMessageTo) {

	zend_bool _47, _55, _56;
	zend_string *_8, *_18$$5, *_28$$7;
	zend_ulong _7, _17$$5, _27$$7;
	zval boundary, _43, _46, _50$$12;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL, *_52 = NULL, *_54 = NULL, *_61 = NULL, *_62 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *to_param = NULL, *cc_param = NULL, *bcc_param = NULL, __$true, data, recievers, addr, name, subject, plain, body, attachments, path, _0, _1, _2, _3, _5, *_6, _15, _36, _37, _38, _39, _42, _44, _45, _51, _53, _70, _71, _72, _9$$4, _11$$4, _12$$4, _13$$4, _14$$4, *_16$$5, _24$$5, _25$$5, _19$$6, _20$$6, _21$$6, _22$$6, _23$$6, *_26$$7, _34$$7, _35$$7, _29$$8, _30$$8, _31$$8, _32$$8, _33$$8, _40$$9, _41$$9, _48$$10, _49$$11, *_57$$14, _58$$16, _59$$16, _60$$16, _63$$15, _64$$15, _65$$15, _66$$15, _67$$15, _68$$15, _69$$15;
	zval message, to, cc, bcc;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&to);
	ZVAL_UNDEF(&cc);
	ZVAL_UNDEF(&bcc);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&recievers);
	ZVAL_UNDEF(&addr);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&subject);
	ZVAL_UNDEF(&plain);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&attachments);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_70);
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_48$$10);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_58$$16);
	ZVAL_UNDEF(&_59$$16);
	ZVAL_UNDEF(&_60$$16);
	ZVAL_UNDEF(&_63$$15);
	ZVAL_UNDEF(&_64$$15);
	ZVAL_UNDEF(&_65$$15);
	ZVAL_UNDEF(&_66$$15);
	ZVAL_UNDEF(&_67$$15);
	ZVAL_UNDEF(&_68$$15);
	ZVAL_UNDEF(&_69$$15);
	ZVAL_UNDEF(&boundary);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_50$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &message_param, &to_param, &cc_param, &bcc_param);

	zephir_get_arrval(&message, message_param);
	zephir_get_arrval(&to, to_param);
	if (!cc_param) {
		ZEPHIR_INIT_VAR(&cc);
		array_init(&cc);
	} else {
		zephir_get_arrval(&cc, cc_param);
	}
	if (!bcc_param) {
		ZEPHIR_INIT_VAR(&bcc);
		array_init(&bcc);
	} else {
		zephir_get_arrval(&bcc, bcc_param);
	}


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_read_property(&_0, this_ptr, SL("sender"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "MAIL FROM: ", &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "MAIL FROM");
	ZVAL_LONG(&_3, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, &_2, &_1, &_3);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("namedSender"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SV(&_5, "FROM: ", &_3);
	zephir_array_append(&data, &_5, PH_SEPARATE, "nc/netutils/smtp.zep", 104);
	if (unlikely(zephir_fast_count_int(&to TSRMLS_CC) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_smtpexception_ce, "No recievers to send to", "nc/netutils/smtp.zep", 107);
		return;
	}
	ZEPHIR_INIT_VAR(&recievers);
	array_init(&recievers);
	zephir_is_iterable(&to, 0, "nc/netutils/smtp.zep", 115);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&to), _7, _8, _6)
	{
		ZEPHIR_INIT_NVAR(&addr);
		if (_8 != NULL) { 
			ZVAL_STR_COPY(&addr, _8);
		} else {
			ZVAL_LONG(&addr, _7);
		}
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _6);
		ZEPHIR_INIT_NVAR(&_11$$4);
		ZVAL_STRING(&_11$$4, "");
		ZEPHIR_CALL_SELF(&_9$$4, "pack", &_10, 0, &_11$$4, &addr);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_12$$4);
		ZEPHIR_CONCAT_SV(&_12$$4, "RCPT TO: ", &_9$$4);
		ZEPHIR_INIT_NVAR(&_11$$4);
		ZVAL_STRING(&_11$$4, "RCPT TO");
		ZVAL_LONG(&_13$$4, 250);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, &_11$$4, &_12$$4, &_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&_14$$4, "pack", &_10, 0, &name, &addr);
		zephir_check_call_status();
		zephir_array_append(&recievers, &_14$$4, PH_SEPARATE, "nc/netutils/smtp.zep", 113);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&addr);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_fast_join_str(&_2, SL(","), &recievers TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_SV(&_15, "TO: ", &_2);
	zephir_array_append(&data, &_15, PH_SEPARATE, "nc/netutils/smtp.zep", 115);
	if (zephir_fast_count_int(&cc TSRMLS_CC) > 0) {
		ZEPHIR_INIT_NVAR(&recievers);
		array_init(&recievers);
		zephir_is_iterable(&cc, 0, "nc/netutils/smtp.zep", 123);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&cc), _17$$5, _18$$5, _16$$5)
		{
			ZEPHIR_INIT_NVAR(&addr);
			if (_18$$5 != NULL) { 
				ZVAL_STR_COPY(&addr, _18$$5);
			} else {
				ZVAL_LONG(&addr, _17$$5);
			}
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _16$$5);
			ZEPHIR_INIT_NVAR(&_20$$6);
			ZVAL_STRING(&_20$$6, "");
			ZEPHIR_CALL_SELF(&_19$$6, "pack", &_10, 0, &_20$$6, &addr);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_21$$6);
			ZEPHIR_CONCAT_SV(&_21$$6, "RCPT TO: ", &_19$$6);
			ZEPHIR_INIT_NVAR(&_20$$6);
			ZVAL_STRING(&_20$$6, "RCPT TO");
			ZVAL_LONG(&_22$$6, 250);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, &_20$$6, &_21$$6, &_22$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_SELF(&_23$$6, "pack", &_10, 0, &name, &addr);
			zephir_check_call_status();
			zephir_array_append(&recievers, &_23$$6, PH_SEPARATE, "nc/netutils/smtp.zep", 121);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&name);
		ZEPHIR_INIT_NVAR(&addr);
		ZEPHIR_INIT_VAR(&_24$$5);
		zephir_fast_join_str(&_24$$5, SL(","), &recievers TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_25$$5);
		ZEPHIR_CONCAT_SV(&_25$$5, "CC: ", &_24$$5);
		zephir_array_append(&data, &_25$$5, PH_SEPARATE, "nc/netutils/smtp.zep", 123);
	}
	if (zephir_fast_count_int(&bcc TSRMLS_CC) > 0) {
		ZEPHIR_INIT_NVAR(&recievers);
		array_init(&recievers);
		zephir_is_iterable(&bcc, 0, "nc/netutils/smtp.zep", 131);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bcc), _27$$7, _28$$7, _26$$7)
		{
			ZEPHIR_INIT_NVAR(&addr);
			if (_28$$7 != NULL) { 
				ZVAL_STR_COPY(&addr, _28$$7);
			} else {
				ZVAL_LONG(&addr, _27$$7);
			}
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _26$$7);
			ZEPHIR_INIT_NVAR(&_30$$8);
			ZVAL_STRING(&_30$$8, "");
			ZEPHIR_CALL_SELF(&_29$$8, "pack", &_10, 0, &_30$$8, &addr);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_31$$8);
			ZEPHIR_CONCAT_SV(&_31$$8, "RCPT TO: ", &_29$$8);
			ZEPHIR_INIT_NVAR(&_30$$8);
			ZVAL_STRING(&_30$$8, "RCPT TO");
			ZVAL_LONG(&_32$$8, 250);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, &_30$$8, &_31$$8, &_32$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_SELF(&_33$$8, "pack", &_10, 0, &name, &addr);
			zephir_check_call_status();
			zephir_array_append(&recievers, &_33$$8, PH_SEPARATE, "nc/netutils/smtp.zep", 129);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&name);
		ZEPHIR_INIT_NVAR(&addr);
		ZEPHIR_INIT_VAR(&_34$$7);
		zephir_fast_join_str(&_34$$7, SL(","), &recievers TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_35$$7);
		ZEPHIR_CONCAT_SV(&_35$$7, "BCC: ", &_34$$7);
		zephir_array_append(&data, &_35$$7, PH_SEPARATE, "nc/netutils/smtp.zep", 131);
	}
	ZEPHIR_INIT_VAR(&_36);
	ZEPHIR_CALL_FUNCTION(&_37, "mt_rand", NULL, 11);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_38, "uniqid", NULL, 12, &_37, &__$true);
	zephir_check_call_status();
	zephir_md5(&_36, &_38);
	ZEPHIR_INIT_VAR(&_39);
	ZEPHIR_CONCAT_SV(&_39, "----Boundary-", &_36);
	zephir_get_strval(&boundary, &_39);
	ZEPHIR_OBS_VAR(&subject);
	if (zephir_array_isset_string_fetch(&subject, &message, SL("subject"), 0)) {
		ZEPHIR_CALL_SELF(&_40$$9, "pack", &_10, 0, &subject);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_41$$9);
		ZEPHIR_CONCAT_SV(&_41$$9, "Subject: ", &_40$$9);
		zephir_array_append(&data, &_41$$9, PH_SEPARATE, "nc/netutils/smtp.zep", 137);
	}
	ZEPHIR_INIT_VAR(&_42);
	ZVAL_STRING(&_42, "Mime-Version: 1.0");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 139);
	ZEPHIR_INIT_VAR(&_43);
	ZEPHIR_CONCAT_SVS(&_43, "Content-Type: multipart/mixed; boundary=\"", &boundary, "\"");
	zephir_array_append(&data, &_43, PH_SEPARATE, "nc/netutils/smtp.zep", 140);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "Content-Transfer-Encoding: 8Bit");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 141);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "r");
	ZEPHIR_CALL_FUNCTION(&_44, "gmdate", NULL, 88, &_42);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_45);
	ZEPHIR_CONCAT_SV(&_45, "Date: ", &_44);
	zephir_array_append(&data, &_45, PH_SEPARATE, "nc/netutils/smtp.zep", 142);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 143);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "This is a multi-part message in MIME format!");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 144);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 145);
	ZEPHIR_INIT_VAR(&_46);
	ZEPHIR_CONCAT_SV(&_46, "--", &boundary);
	ZEPHIR_CPY_WRT(&boundary, &_46);
	zephir_array_append(&data, &boundary, PH_SEPARATE, "nc/netutils/smtp.zep", 149);
	ZEPHIR_OBS_VAR(&plain);
	_47 = zephir_array_isset_string_fetch(&plain, &message, SL("plain"), 0);
	if (_47) {
		_47 = zephir_is_true(&plain);
	}
	if (_47) {
		ZEPHIR_INIT_VAR(&_48$$10);
		ZVAL_STRING(&_48$$10, "Content-Type: text/plain; charset=UTF-8");
		zephir_array_append(&data, &_48$$10, PH_SEPARATE, "nc/netutils/smtp.zep", 151);
	} else {
		ZEPHIR_INIT_VAR(&_49$$11);
		ZVAL_STRING(&_49$$11, "Content-Type: text/html; charset=UTF-8");
		zephir_array_append(&data, &_49$$11, PH_SEPARATE, "nc/netutils/smtp.zep", 153);
	}
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "Content-Transfer-Encoding: base64");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 155);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 156);
	ZEPHIR_OBS_VAR(&body);
	if (zephir_array_isset_string_fetch(&body, &message, SL("body"), 0)) {
		zephir_get_strval(&_50$$12, &body);
		ZEPHIR_CPY_WRT(&body, &_50$$12);
	} else {
		ZEPHIR_INIT_NVAR(&body);
		ZVAL_STRING(&body, " ");
	}
	ZEPHIR_CALL_FUNCTION(&_51, "base64_encode", &_52, 81, &body);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_53, "chunk_split", &_54, 89, &_51);
	zephir_check_call_status();
	zephir_array_append(&data, &_53, PH_SEPARATE, "nc/netutils/smtp.zep", 162);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 163);
	ZEPHIR_OBS_VAR(&attachments);
	_55 = zephir_array_isset_string_fetch(&attachments, &message, SL("attachments"), 0);
	if (_55) {
		_55 = Z_TYPE_P(&attachments) == IS_ARRAY;
	}
	_56 = _55;
	if (_56) {
		_56 = zephir_fast_count_int(&attachments TSRMLS_CC) > 0;
	}
	if (_56) {
		zephir_is_iterable(&attachments, 0, "nc/netutils/smtp.zep", 178);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attachments), _57$$14)
		{
			ZEPHIR_INIT_NVAR(&path);
			ZVAL_COPY(&path, _57$$14);
			if (unlikely(!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)))) {
				ZEPHIR_INIT_NVAR(&_58$$16);
				object_init_ex(&_58$$16, nc_netutils_smtpexception_ce);
				ZEPHIR_INIT_NVAR(&_59$$16);
				ZVAL_STRING(&_59$$16, "Cannot find attachment '%s'");
				ZEPHIR_CALL_FUNCTION(&_60$$16, "sprintf", &_61, 6, &_59$$16, &path);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_58$$16, "__construct", &_62, 7, &_60$$16);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_58$$16, "nc/netutils/smtp.zep", 168 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&data, &boundary, PH_SEPARATE, "nc/netutils/smtp.zep", 170);
			ZEPHIR_INIT_NVAR(&_63$$15);
			ZVAL_STRING(&_63$$15, "Content-Type: application/octet-stream");
			zephir_array_append(&data, &_63$$15, PH_SEPARATE, "nc/netutils/smtp.zep", 171);
			ZEPHIR_INIT_NVAR(&_63$$15);
			zephir_basename(&_63$$15, &path TSRMLS_CC);
			ZEPHIR_CALL_SELF(&_64$$15, "pack", &_10, 0, &_63$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_65$$15);
			ZEPHIR_CONCAT_SVS(&_65$$15, "Content-Disposition: attachment; filename=\"", &_64$$15, "\"");
			zephir_array_append(&data, &_65$$15, PH_SEPARATE, "nc/netutils/smtp.zep", 172);
			ZEPHIR_INIT_NVAR(&_66$$15);
			ZVAL_STRING(&_66$$15, "Content-Transfer-Encoding: base64");
			zephir_array_append(&data, &_66$$15, PH_SEPARATE, "nc/netutils/smtp.zep", 173);
			ZEPHIR_INIT_NVAR(&_66$$15);
			ZVAL_STRING(&_66$$15, "");
			zephir_array_append(&data, &_66$$15, PH_SEPARATE, "nc/netutils/smtp.zep", 174);
			ZEPHIR_INIT_NVAR(&_66$$15);
			zephir_file_get_contents(&_66$$15, &path TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_67$$15, "base64_encode", &_52, 81, &_66$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_68$$15, "chunk_split", &_54, 89, &_67$$15);
			zephir_check_call_status();
			zephir_array_append(&data, &_68$$15, PH_SEPARATE, "nc/netutils/smtp.zep", 175);
			ZEPHIR_INIT_NVAR(&_69$$15);
			ZVAL_STRING(&_69$$15, "");
			zephir_array_append(&data, &_69$$15, PH_SEPARATE, "nc/netutils/smtp.zep", 176);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&path);
	}
	zephir_concat_self_str(&boundary, "--", sizeof("--")-1 TSRMLS_CC);
	zephir_array_append(&data, &boundary, PH_SEPARATE, "nc/netutils/smtp.zep", 182);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, ".");
	zephir_array_append(&data, &_42, PH_SEPARATE, "nc/netutils/smtp.zep", 183);
	ZEPHIR_INIT_NVAR(&_42);
	ZVAL_STRING(&_42, "DATA");
	ZEPHIR_INIT_VAR(&_70);
	ZVAL_STRING(&_70, "DATA");
	ZVAL_LONG(&_71, 354);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, &_42, &_70, &_71);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_42);
	ZEPHIR_INIT_NVAR(&_70);
	ZVAL_STRING(&_70, "\r\n");
	zephir_fast_join(&_42, &_70, &data TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_72);
	ZVAL_STRING(&_72, "END DATA");
	ZVAL_LONG(&_71, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, &_72, &_42, &_71);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_Smtp, __destruct) {

	zval _0$$3, _1$$3, _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "QUIT");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "QUIT");
		ZVAL_LONG(&_2$$3, 221);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", NULL, 0, &_0$$3, &_1$$3, &_2$$3);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_Smtp, cmd) {

	zend_bool _9;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *step_param = NULL, *cmd_param = NULL, *expected_param = NULL, _0, _3, _4, _5, _6, _8, _10, _1$$3, _11$$4, _12$$4, _13$$4;
	zval step, cmd, expected, output, _7, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&step);
	ZVAL_UNDEF(&cmd);
	ZVAL_UNDEF(&expected);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &step_param, &cmd_param, &expected_param);

	zephir_get_strval(&step, step_param);
	zephir_get_strval(&cmd, cmd_param);
	zephir_get_strval(&expected, expected_param);


	if (zephir_fast_strlen_ev(&cmd) > 0) {
		zephir_read_property(&_1$$3, this_ptr, SL("tcpSocketClient"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VS(&_2$$3, &cmd, "\r\n");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "write", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_read_property(&_4, this_ptr, SL("tcpSocketClient"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_6, 1024);
	ZEPHIR_CALL_METHOD(&_5, &_4, "readmaxlength", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_fast_trim(&_3, &_5, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(&_7, &_3);
	ZEPHIR_CPY_WRT(&output, &_7);
	_9 = zephir_fast_strlen_ev(&expected) > 0;
	if (_9) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_fast_strpos(&_10, &output, &expected, 0 );
		_9 = !ZEPHIR_IS_LONG_IDENTICAL(&_10, 0);
	}
	if (unlikely(_9)) {
		ZEPHIR_INIT_VAR(&_11$$4);
		object_init_ex(&_11$$4, nc_netutils_smtpexception_ce);
		ZEPHIR_INIT_VAR(&_12$$4);
		ZVAL_STRING(&_12$$4, "Unexpected response '%s' on step '%s'");
		ZEPHIR_CALL_FUNCTION(&_13$$4, "sprintf", NULL, 6, &_12$$4, &output, &step);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_11$$4, "__construct", NULL, 7, &_13$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$4, "nc/netutils/smtp.zep", 207 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

