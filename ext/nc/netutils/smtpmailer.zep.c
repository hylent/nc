
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
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Nc_NetUtils_SmtpMailer) {

	ZEPHIR_REGISTER_CLASS(Nc\\NetUtils, SmtpMailer, nc, netutils_smtpmailer, nc_netutils_smtpmailer_method_entry, 0);

	zend_declare_property_null(nc_netutils_smtpmailer_ce, SL("socket"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_netutils_smtpmailer_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_netutils_smtpmailer_ce, SL("CRLF"), "\r\n" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_NetUtils_SmtpMailer, __construct) {

	zend_bool secure = 0;
	double timeout = 0;
	long port = 0, connectTimeout = 0;
	zval *host = NULL, *user = NULL, *passwd = NULL, *from = NULL, *name = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_26 = NULL, *_28 = NULL;
	zval *options_param = NULL, *socket = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_22 = NULL, *_27 = NULL, *_29 = NULL, *_16$$3 = NULL, *_17$$3, *_18$$3, *_19$$4 = NULL, *_20$$4, *_21$$4, *_23$$5, _24$$6, *_25$$6 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "host", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, nc_std_ce, "valueat", &_1, 5, options, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_3, _0);
	ZEPHIR_CPY_WRT(host, _3);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_4, nc_std_ce, "valueat", &_1, 5, options, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_5, _4);
	ZEPHIR_CPY_WRT(user, _5);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "passwd", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_6, nc_std_ce, "valueat", &_1, 5, options, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_7, _6);
	ZEPHIR_CPY_WRT(passwd, _7);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "from", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_8, nc_std_ce, "valueat", &_1, 5, options, _2, user);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_9, _8);
	ZEPHIR_CPY_WRT(from, _9);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "name", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_10, nc_std_ce, "valueat", &_1, 5, options, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	zephir_get_strval(_12, _10);
	ZEPHIR_CPY_WRT(name, _12);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "connectTimeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, 10);
	ZEPHIR_CALL_CE_STATIC(&_13, nc_std_ce, "valueat", &_1, 5, options, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	connectTimeout = zephir_get_intval(_13);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "timeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, 5);
	ZEPHIR_CALL_CE_STATIC(&_14, nc_std_ce, "valueat", &_1, 5, options, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	timeout = zephir_get_doubleval(_14);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "secure", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_BOOL(_11, 0);
	ZEPHIR_CALL_CE_STATIC(&_15, nc_std_ce, "valueat", &_1, 5, options, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	secure = zephir_get_boolval(_15);
	if (secure) {
		ZEPHIR_INIT_VAR(_17$$3);
		ZVAL_STRING(_17$$3, "port", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_18$$3);
		ZVAL_LONG(_18$$3, 465);
		ZEPHIR_CALL_CE_STATIC(&_16$$3, nc_std_ce, "valueat", &_1, 5, options, _17$$3, _18$$3);
		zephir_check_temp_parameter(_17$$3);
		zephir_check_call_status();
		port = zephir_get_intval(_16$$3);
	} else {
		ZEPHIR_INIT_VAR(_20$$4);
		ZVAL_STRING(_20$$4, "port", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_21$$4);
		ZVAL_LONG(_21$$4, 25);
		ZEPHIR_CALL_CE_STATIC(&_19$$4, nc_std_ce, "valueat", &_1, 5, options, _20$$4, _21$$4);
		zephir_check_temp_parameter(_20$$4);
		zephir_check_call_status();
		port = zephir_get_intval(_19$$4);
	}
	ZEPHIR_INIT_VAR(socket);
	object_init_ex(socket, nc_netutils_socketclient_ce);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, port);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, connectTimeout);
	ZEPHIR_INIT_VAR(_22);
	ZVAL_BOOL(_22, 0);
	ZEPHIR_CALL_METHOD(NULL, socket, "__construct", NULL, 87, host, _2, _11, _22);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, socket, "settcpnodelay", NULL, 88, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, socket, "setblocking", NULL, 89, _2);
	zephir_check_call_status();
	if (timeout > 0) {
		ZEPHIR_INIT_VAR(_23$$5);
		ZVAL_DOUBLE(_23$$5, timeout);
		ZEPHIR_CALL_METHOD(NULL, socket, "settimeout", NULL, 90, _23$$5);
		zephir_check_call_status();
	}
	if (secure) {
		ZEPHIR_SINIT_VAR(_24$$6);
		ZVAL_STRING(&_24$$6, "STREAM_CRYPTO_METHOD_SSLv23_CLIENT", 0);
		ZEPHIR_CALL_FUNCTION(&_25$$6, "constant", NULL, 91, &_24$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, socket, "enablecrypto", NULL, 92, _25$$6);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("socket"), socket TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "pack", NULL, 0, name, from);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("from"), _15 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "CONNECT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_22);
	ZVAL_LONG(_22, 220);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_26, 0, _2, _11, _22);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_22);
	ZVAL_LONG(_22, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_26, 0, _2, _11, _22);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_22);
	ZVAL_LONG(_22, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_26, 0, _2, _11, _22);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_27, "base64_encode", &_28, 93, user);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "AUTH USER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_26, 0, _2, _27, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_29, "base64_encode", &_28, 93, passwd);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "AUTH PASSWD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, 235);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_26, 0, _2, _29, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SmtpMailer, getSocket) {

	

	RETURN_MEMBER(this_ptr, "socket");

}

PHP_METHOD(Nc_NetUtils_SmtpMailer, sendMessageTo) {

	zend_bool _44, _52, _53;
	HashTable *_8, *_17$$5, *_26$$7, *_55$$14;
	HashPosition _7, _16$$5, _25$$7, _54$$14;
	zval *boundary = NULL, *_39, *_43, *_47$$12 = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_11 = NULL, *_35 = NULL, *_49 = NULL, *_51 = NULL, *_59 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *to_param = NULL, *cc_param = NULL, *bcc_param = NULL, *data = NULL, *recievers = NULL, *addr = NULL, *name = NULL, *subject = NULL, *plain = NULL, *body = NULL, *attachments = NULL, *path = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_5, *_6, **_9, *_15, *_34 = NULL, *_36, _40 = zval_used_for_init, *_41 = NULL, *_42, *_48 = NULL, *_50 = NULL, *_67 = NULL, *_68 = NULL, *_10$$4 = NULL, *_12$$4 = NULL, *_13$$4 = NULL, *_14$$4 = NULL, **_18$$5, *_23$$5, *_24$$5, *_19$$6 = NULL, *_20$$6 = NULL, *_21$$6 = NULL, *_22$$6 = NULL, **_27$$7, *_32$$7, *_33$$7, *_28$$8 = NULL, *_29$$8 = NULL, *_30$$8 = NULL, *_31$$8 = NULL, *_37$$9 = NULL, *_38$$9, *_45$$10, *_46$$11, **_56$$14, *_57$$16 = NULL, *_58$$16 = NULL, *_60$$15 = NULL, *_61$$15 = NULL, *_62$$15 = NULL, *_63$$15 = NULL, *_64$$15 = NULL, *_65$$15 = NULL, *_66$$15 = NULL;
	zval *message = NULL, *to = NULL, *cc = NULL, *bcc = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &message_param, &to_param, &cc_param, &bcc_param);

	zephir_get_arrval(message, message_param);
	zephir_get_arrval(to, to_param);
	if (!cc_param) {
		ZEPHIR_INIT_VAR(cc);
		array_init(cc);
	} else {
		zephir_get_arrval(cc, cc_param);
	}
	if (!bcc_param) {
		ZEPHIR_INIT_VAR(bcc);
		array_init(bcc);
	} else {
		zephir_get_arrval(bcc, bcc_param);
	}


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "MAIL FROM: ", _0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "MAIL FROM", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _2, _1, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "FROM: ", _5);
	zephir_array_append(&data, _6, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 69);
	if (zephir_fast_count_int(to TSRMLS_CC) < 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_netutils_exception_ce, "No recievers to send to", "nc/netutils/smtpmailer.zep", 72);
		return;
	}
	ZEPHIR_INIT_VAR(recievers);
	array_init(recievers);
	zephir_is_iterable(to, &_8, &_7, 0, 0, "nc/netutils/smtpmailer.zep", 81);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(addr, _8, _7);
		ZEPHIR_GET_HVALUE(name, _9);
		ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "pack", &_11, 0, name, addr);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(name, _10$$4);
		ZEPHIR_INIT_LNVAR(_12$$4);
		ZEPHIR_CONCAT_SV(_12$$4, "RCPT TO: ", name);
		ZEPHIR_INIT_NVAR(_13$$4);
		ZVAL_STRING(_13$$4, "RCPT TO", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_14$$4);
		ZVAL_LONG(_14$$4, 250);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _13$$4, _12$$4, _14$$4);
		zephir_check_temp_parameter(_13$$4);
		zephir_check_call_status();
		zephir_array_append(&recievers, name, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 79);
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_fast_join_str(_2, SL(","), recievers TSRMLS_CC);
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_CONCAT_SV(_15, "TO: ", _2);
	zephir_array_append(&data, _15, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 81);
	if (zephir_fast_count_int(cc TSRMLS_CC) > 0) {
		ZEPHIR_INIT_NVAR(recievers);
		array_init(recievers);
		zephir_is_iterable(cc, &_17$$5, &_16$$5, 0, 0, "nc/netutils/smtpmailer.zep", 90);
		for (
		  ; zephir_hash_get_current_data_ex(_17$$5, (void**) &_18$$5, &_16$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_17$$5, &_16$$5)
		) {
			ZEPHIR_GET_HMKEY(addr, _17$$5, _16$$5);
			ZEPHIR_GET_HVALUE(name, _18$$5);
			ZEPHIR_CALL_METHOD(&_19$$6, this_ptr, "pack", &_11, 0, name, addr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(name, _19$$6);
			ZEPHIR_INIT_LNVAR(_20$$6);
			ZEPHIR_CONCAT_SV(_20$$6, "RCPT TO: ", name);
			ZEPHIR_INIT_NVAR(_21$$6);
			ZVAL_STRING(_21$$6, "RCPT TO", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_22$$6);
			ZVAL_LONG(_22$$6, 250);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _21$$6, _20$$6, _22$$6);
			zephir_check_temp_parameter(_21$$6);
			zephir_check_call_status();
			zephir_array_append(&recievers, name, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 88);
		}
		ZEPHIR_INIT_VAR(_23$$5);
		zephir_fast_join_str(_23$$5, SL(","), recievers TSRMLS_CC);
		ZEPHIR_INIT_VAR(_24$$5);
		ZEPHIR_CONCAT_SV(_24$$5, "CC: ", _23$$5);
		zephir_array_append(&data, _24$$5, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 90);
	}
	if (zephir_fast_count_int(bcc TSRMLS_CC) > 0) {
		ZEPHIR_INIT_NVAR(recievers);
		array_init(recievers);
		zephir_is_iterable(bcc, &_26$$7, &_25$$7, 0, 0, "nc/netutils/smtpmailer.zep", 99);
		for (
		  ; zephir_hash_get_current_data_ex(_26$$7, (void**) &_27$$7, &_25$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_26$$7, &_25$$7)
		) {
			ZEPHIR_GET_HMKEY(addr, _26$$7, _25$$7);
			ZEPHIR_GET_HVALUE(name, _27$$7);
			ZEPHIR_CALL_METHOD(&_28$$8, this_ptr, "pack", &_11, 0, name, addr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(name, _28$$8);
			ZEPHIR_INIT_LNVAR(_29$$8);
			ZEPHIR_CONCAT_SV(_29$$8, "RCPT TO: ", name);
			ZEPHIR_INIT_NVAR(_30$$8);
			ZVAL_STRING(_30$$8, "RCPT TO", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_31$$8);
			ZVAL_LONG(_31$$8, 250);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _30$$8, _29$$8, _31$$8);
			zephir_check_temp_parameter(_30$$8);
			zephir_check_call_status();
			zephir_array_append(&recievers, name, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 97);
		}
		ZEPHIR_INIT_VAR(_32$$7);
		zephir_fast_join_str(_32$$7, SL(","), recievers TSRMLS_CC);
		ZEPHIR_INIT_VAR(_33$$7);
		ZEPHIR_CONCAT_SV(_33$$7, "BCC: ", _32$$7);
		zephir_array_append(&data, _33$$7, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 99);
	}
	ZEPHIR_CALL_CE_STATIC(&_34, nc_std_ce, "uuid", &_35, 18);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_36);
	ZEPHIR_CONCAT_SV(_36, "----Boundary-", _34);
	zephir_get_strval(boundary, _36);
	ZEPHIR_OBS_VAR(subject);
	if (zephir_array_isset_string_fetch(&subject, message, SS("subject"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_37$$9, this_ptr, "pack", &_11, 0, subject);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_38$$9);
		ZEPHIR_CONCAT_SV(_38$$9, "Subject: ", _37$$9);
		zephir_array_append(&data, _38$$9, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 105);
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "Mime-Version: 1.0", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 107);
	ZEPHIR_INIT_VAR(_39);
	ZEPHIR_CONCAT_SVS(_39, "Content-Type: multipart/mixed; boundary=\"", boundary, "\"");
	zephir_array_append(&data, _39, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 108);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "Content-Transfer-Encoding: 8Bit", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 109);
	ZEPHIR_SINIT_VAR(_40);
	ZVAL_STRING(&_40, "r", 0);
	ZEPHIR_CALL_FUNCTION(&_41, "gmdate", NULL, 94, &_40);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_42);
	ZEPHIR_CONCAT_SV(_42, "Date: ", _41);
	zephir_array_append(&data, _42, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 110);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 111);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "This is a multi-part message in MIME format!", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 112);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 113);
	ZEPHIR_INIT_VAR(_43);
	ZEPHIR_CONCAT_SV(_43, "--", boundary);
	ZEPHIR_CPY_WRT(boundary, _43);
	zephir_array_append(&data, boundary, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 117);
	ZEPHIR_OBS_VAR(plain);
	_44 = zephir_array_isset_string_fetch(&plain, message, SS("plain"), 0 TSRMLS_CC);
	if (_44) {
		_44 = zephir_is_true(plain);
	}
	if (_44) {
		ZEPHIR_INIT_VAR(_45$$10);
		ZVAL_STRING(_45$$10, "Content-Type: text/plain; charset=UTF-8", 1);
		zephir_array_append(&data, _45$$10, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 119);
	} else {
		ZEPHIR_INIT_VAR(_46$$11);
		ZVAL_STRING(_46$$11, "Content-Type: text/html; charset=UTF-8", 1);
		zephir_array_append(&data, _46$$11, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 121);
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "Content-Transfer-Encoding: base64", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 123);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 124);
	ZEPHIR_OBS_VAR(body);
	if (zephir_array_isset_string_fetch(&body, message, SS("body"), 0 TSRMLS_CC)) {
		zephir_get_strval(_47$$12, body);
		ZEPHIR_CPY_WRT(body, _47$$12);
	} else {
		ZEPHIR_INIT_NVAR(body);
		ZVAL_STRING(body, " ", 1);
	}
	ZEPHIR_CALL_FUNCTION(&_48, "base64_encode", &_49, 93, body);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_50, "chunk_split", &_51, 95, _48);
	zephir_check_call_status();
	zephir_array_append(&data, _50, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 130);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 131);
	ZEPHIR_OBS_VAR(attachments);
	_52 = zephir_array_isset_string_fetch(&attachments, message, SS("attachments"), 0 TSRMLS_CC);
	if (_52) {
		_52 = Z_TYPE_P(attachments) == IS_ARRAY;
	}
	_53 = _52;
	if (_53) {
		_53 = zephir_fast_count_int(attachments TSRMLS_CC) > 0;
	}
	if (_53) {
		zephir_is_iterable(attachments, &_55$$14, &_54$$14, 0, 0, "nc/netutils/smtpmailer.zep", 146);
		for (
		  ; zephir_hash_get_current_data_ex(_55$$14, (void**) &_56$$14, &_54$$14) == SUCCESS
		  ; zephir_hash_move_forward_ex(_55$$14, &_54$$14)
		) {
			ZEPHIR_GET_HVALUE(path, _56$$14);
			if (unlikely(!((zephir_file_exists(path TSRMLS_CC) == SUCCESS)))) {
				ZEPHIR_INIT_NVAR(_57$$16);
				object_init_ex(_57$$16, nc_netutils_exception_ce);
				ZEPHIR_INIT_LNVAR(_58$$16);
				ZEPHIR_CONCAT_SV(_58$$16, "Cannot find attachment: ", path);
				ZEPHIR_CALL_METHOD(NULL, _57$$16, "__construct", &_59, 2, _58$$16);
				zephir_check_call_status();
				zephir_throw_exception_debug(_57$$16, "nc/netutils/smtpmailer.zep", 136 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&data, boundary, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 138);
			ZEPHIR_INIT_NVAR(_60$$15);
			ZVAL_STRING(_60$$15, "Content-Type: application/octet-stream", 1);
			zephir_array_append(&data, _60$$15, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 139);
			ZEPHIR_INIT_NVAR(_60$$15);
			zephir_basename(_60$$15, path TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_61$$15, this_ptr, "pack", &_11, 0, _60$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_62$$15);
			ZEPHIR_CONCAT_SVS(_62$$15, "Content-Disposition: attachment; filename=\"", _61$$15, "\"");
			zephir_array_append(&data, _62$$15, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 140);
			ZEPHIR_INIT_NVAR(_63$$15);
			ZVAL_STRING(_63$$15, "Content-Transfer-Encoding: base64", 1);
			zephir_array_append(&data, _63$$15, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 141);
			ZEPHIR_INIT_NVAR(_63$$15);
			ZVAL_STRING(_63$$15, "", 1);
			zephir_array_append(&data, _63$$15, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 142);
			ZEPHIR_INIT_NVAR(_63$$15);
			zephir_file_get_contents(_63$$15, path TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_64$$15, "base64_encode", &_49, 93, _63$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_65$$15, "chunk_split", &_51, 95, _64$$15);
			zephir_check_call_status();
			zephir_array_append(&data, _65$$15, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 143);
			ZEPHIR_INIT_NVAR(_66$$15);
			ZVAL_STRING(_66$$15, "", 1);
			zephir_array_append(&data, _66$$15, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 144);
		}
	}
	zephir_concat_self_str(&boundary, "--", sizeof("--")-1 TSRMLS_CC);
	zephir_array_append(&data, boundary, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 150);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, ".", 1);
	zephir_array_append(&data, _3, PH_SEPARATE, "nc/netutils/smtpmailer.zep", 151);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_67);
	ZVAL_STRING(_67, "DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_68);
	ZVAL_LONG(_68, 354);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _3, _67, _68);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_67);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_SINIT_NVAR(_40);
	ZVAL_STRING(&_40, "\r\n", 0);
	zephir_fast_join(_3, &_40, data TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_67);
	ZVAL_STRING(_67, "END DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_68);
	ZVAL_LONG(_68, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _67, _3, _68);
	zephir_check_temp_parameter(_67);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SmtpMailer, __destruct) {

	zval *_0$$3, *_1$$3, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "QUIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "QUIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 221);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", NULL, 0, _0$$3, _1$$3, _2$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SmtpMailer, cmd) {

	zend_bool _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *step_param = NULL, *cmd_param = NULL, *expected_param = NULL, *_2, *_3, *_4 = NULL, *_5 = NULL, *_0$$3, *_8$$4;
	zval *step = NULL, *cmd = NULL, *expected = NULL, *output = NULL, *_6 = NULL, *_1$$3, *_9$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &step_param, &cmd_param, &expected_param);

	zephir_get_strval(step, step_param);
	zephir_get_strval(cmd, cmd_param);
	zephir_get_strval(expected, expected_param);


	if (!(!cmd) && Z_STRLEN_P(cmd)) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_VS(_1$$3, cmd, "\r\n");
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "write", NULL, 0, _1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 1024);
	ZEPHIR_CALL_METHOD(&_4, _3, "readmaxlength", NULL, 0, _5);
	zephir_check_call_status();
	zephir_fast_trim(_2, _4, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(_6, _2);
	ZEPHIR_CPY_WRT(output, _6);
	_7 = zephir_is_true(expected);
	if (_7) {
		ZEPHIR_INIT_NVAR(_5);
		zephir_fast_strpos(_5, output, expected, 0 );
		_7 = !ZEPHIR_IS_LONG_IDENTICAL(_5, 0);
	}
	if (_7) {
		ZEPHIR_INIT_VAR(_8$$4);
		object_init_ex(_8$$4, nc_netutils_exception_ce);
		ZEPHIR_INIT_VAR(_9$$4);
		ZEPHIR_CONCAT_SVSV(_9$$4, "Unexpected response on step: ", step, ", with output: ", output);
		ZEPHIR_CALL_METHOD(NULL, _8$$4, "__construct", NULL, 2, _9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$4, "nc/netutils/smtpmailer.zep", 175 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_NetUtils_SmtpMailer, pack) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *addr_param = NULL, *_0$$3 = NULL, *_1$$3;
	zval *name = NULL, *addr = NULL, *s, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &addr_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "", 1);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!addr_param) {
		ZEPHIR_INIT_VAR(addr);
		ZVAL_STRING(addr, "", 1);
	} else {
		zephir_get_strval(addr, addr_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZVAL_EMPTY_STRING(s);
	if (!(!name) && Z_STRLEN_P(name)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "base64_encode", NULL, 93, name);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVS(_1$$3, "=?UTF-8?B?", _0$$3, "?=");
		zephir_concat_self(&s, _1$$3 TSRMLS_CC);
	}
	if (!(!addr) && Z_STRLEN_P(addr)) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SVS(_2$$4, "<", addr, ">");
		zephir_concat_self(&s, _2$$4 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

