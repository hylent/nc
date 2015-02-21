
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Message_Sender_Smtp) {

	ZEPHIR_REGISTER_CLASS(Nc\\Message\\Sender, Smtp, nc, message_sender_smtp, nc_message_sender_smtp_method_entry, 0);

	zend_declare_property_null(nc_message_sender_smtp_ce, SL("socket"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_message_sender_smtp_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_message_sender_smtp_ce, SL("sender"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_message_sender_smtp_ce, SL("preSubject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_message_sender_smtp_ce, SL("EOL"), "\r\n" TSRMLS_CC);

	zend_class_implements(nc_message_sender_smtp_ce TSRMLS_CC, 1, nc_message_sender_messagesenderinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Message_Sender_Smtp, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_13 = NULL;
	zend_bool _1, _7;
	zval *host_param = NULL, *port_param = NULL, *user_param = NULL, *passwd_param = NULL, *from_param = NULL, *sender_param = NULL, *preSubject_param = NULL, *socket = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, _8, *_9 = NULL, *_12 = NULL, *_14 = NULL, *_15 = NULL, *_16, *_17;
	zval *host = NULL, *port = NULL, *user = NULL, *passwd = NULL, *from = NULL, *sender = NULL, *preSubject = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 2, &host_param, &port_param, &user_param, &passwd_param, &from_param, &sender_param, &preSubject_param);

	zephir_get_strval(host, host_param);
	zephir_get_strval(port, port_param);
	zephir_get_strval(user, user_param);
	zephir_get_strval(passwd, passwd_param);
	zephir_get_strval(from, from_param);
	if (!sender_param) {
		ZEPHIR_INIT_VAR(sender);
		ZVAL_STRING(sender, "", 1);
	} else {
		zephir_get_strval(sender, sender_param);
	}
	if (!preSubject_param) {
		ZEPHIR_INIT_VAR(preSubject);
		ZVAL_STRING(preSubject, "", 1);
	} else {
		zephir_get_strval(preSubject, preSubject_param);
	}


	_1 = zephir_fast_strlen_ev(user) < 1;
	if (!(_1)) {
		_1 = zephir_fast_strlen_ev(passwd) < 1;
	}
	if (unlikely(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_message_sender_exception_ce, "Empty user or passwd", "nc/message/sender/smtp.zep", 18);
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 30);
	Z_SET_ISREF_P(_3);
	ZEPHIR_CALL_FUNCTION(&socket, "fsockopen", &_6, host, port, _3, _4, _5);
	Z_UNSET_ISREF_P(_3);
	zephir_check_call_status();
	_7 = !zephir_is_true(socket);
	if (!(_7)) {
		ZEPHIR_SINIT_VAR(_8);
		ZVAL_LONG(&_8, 1);
		ZEPHIR_CALL_FUNCTION(&_9, "stream_set_blocking", &_10, socket, &_8);
		zephir_check_call_status();
		_7 = !zephir_is_true(_9);
	}
	if (unlikely(_7)) {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, nc_message_sender_exception_ce);
		ZEPHIR_INIT_VAR(_11);
		ZEPHIR_CONCAT_SVSV(_11, "Cannot connect or set blocking to ", host, ":", port);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "nc/message/sender/smtp.zep", 23 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("socket"), socket TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "CONNECT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 220);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_12, "base64_encode", &_13, user);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "AUTH USER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _3, _12, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_14, "base64_encode", &_13, passwd);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "AUTH PASSWD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 235);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _3, _14, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("from"), from TSRMLS_CC);
	if (sender && Z_STRLEN_P(sender)) {
		ZEPHIR_CALL_FUNCTION(&_15, "base64_encode", &_13, sender);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_16);
		ZEPHIR_CONCAT_SVSVS(_16, "=?UTF-8?B?", _15, "?= <", from, ">");
		zephir_update_property_this(this_ptr, SL("sender"), _16 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("sender"), from TSRMLS_CC);
	}
	if (preSubject && Z_STRLEN_P(preSubject)) {
		zephir_update_property_this(this_ptr, SL("preSubject"), preSubject TSRMLS_CC);
	} else {
		if (sender && Z_STRLEN_P(sender)) {
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SVS(_11, "[", sender, "]");
			zephir_update_property_this(this_ptr, SL("preSubject"), _11 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_17);
			ZVAL_STRING(_17, "", 1);
			zephir_update_property_this(this_ptr, SL("preSubject"), _17 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Message_Sender_Smtp, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "QUIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "QUIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 221);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _0, _1, _2);
		zephir_check_temp_parameter(_0);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	zephir_fclose(_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Message_Sender_Smtp, send) {

	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_14 = NULL, *_17 = NULL, *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *to_param = NULL, *subject_param = NULL, *message_param = NULL, *lines, *_0 = NULL, *_1, *_2, *_4, *_5, _6 = zval_used_for_init, *_7 = NULL, *_8, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_15, *_16 = NULL, *_18 = NULL, *_20, *_21, *_22, *_23 = NULL, *_25 = NULL;
	zval *to = NULL, *subject = NULL, *message = NULL, *_3, *_24, *_26 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &to_param, &subject_param, &message_param);

	zephir_get_strval(to, to_param);
	zephir_get_strval(subject, subject_param);
	zephir_get_strval(message, message_param);
	ZEPHIR_INIT_VAR(lines);
	array_init(lines);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Content-type: text/html; charset=UTF-8", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/message/sender/smtp.zep", 66);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Content-Transfer-Encoding: base64", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/message/sender/smtp.zep", 67);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("sender"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "From: ", _1);
	zephir_array_append(&lines, _2, PH_SEPARATE, "nc/message/sender/smtp.zep", 68);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "To: ", to);
	zephir_array_append(&lines, _3, PH_SEPARATE, "nc/message/sender/smtp.zep", 69);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("preSubject"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVV(_5, "Subject: ", _4, subject);
	zephir_array_append(&lines, _5, PH_SEPARATE, "nc/message/sender/smtp.zep", 70);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "r", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "gmdate", NULL, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SV(_8, "Date: ", _7);
	zephir_array_append(&lines, _8, PH_SEPARATE, "nc/message/sender/smtp.zep", 71);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "MIME-Version: 1.0", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/message/sender/smtp.zep", 72);
	ZEPHIR_CALL_FUNCTION(&_9, "mt_rand", &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_11, "uniqid", &_12, _9, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_13, "md5", &_14, _11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_CONCAT_SV(_15, "Message-ID: ", _13);
	zephir_array_append(&lines, _15, PH_SEPARATE, "nc/message/sender/smtp.zep", 73);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "X-Priority: 3", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/message/sender/smtp.zep", 74);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "X-Mailer: nc", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/message/sender/smtp.zep", 75);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/message/sender/smtp.zep", 76);
	ZEPHIR_CALL_FUNCTION(&_16, "base64_encode", &_17, message);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_18, "chunk_split", &_19, _16);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_20);
	ZEPHIR_CONCAT_VS(_20, _18, ".");
	zephir_array_append(&lines, _20, PH_SEPARATE, "nc/message/sender/smtp.zep", 77);
	_21 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_22);
	ZEPHIR_CONCAT_SVS(_22, "MAIL FROM: <", _21, ">");
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "MAIL FROM", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_23);
	ZVAL_LONG(_23, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _0, _22, _23);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_24);
	ZEPHIR_CONCAT_SVS(_24, "RCPT TO: <", to, ">");
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "RCPT TO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_23);
	ZVAL_LONG(_23, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _0, _24, _23);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_23);
	ZVAL_STRING(_23, "DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_25);
	ZVAL_LONG(_25, 354);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _0, _23, _25);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_23);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "\r\n", 0);
	zephir_fast_join(_0, &_6, lines TSRMLS_CC);
	zephir_get_strval(_26, _0);
	ZEPHIR_INIT_NVAR(_23);
	ZVAL_STRING(_23, "END DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_25);
	ZVAL_LONG(_25, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, _23, _26, _25);
	zephir_check_temp_parameter(_23);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Message_Sender_Smtp, doCommand) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL;
	zend_bool _0, _12;
	zval *step_param = NULL, *command_param = NULL, *validResult_param = NULL, *_1, *_3 = NULL, *_5 = NULL, *_7, _8, *_9 = NULL, *_13, *_14;
	zval *step = NULL, *command = NULL, *validResult = NULL, *output = NULL, *_2, *_6 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &step_param, &command_param, &validResult_param);

	zephir_get_strval(step, step_param);
	zephir_get_strval(command, command_param);
	zephir_get_strval(validResult, validResult_param);


	_0 = zephir_is_true(command);
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VS(_2, command, "\r\n");
		ZEPHIR_CALL_FUNCTION(&_3, "fputs", &_4, _1, _2);
		zephir_check_call_status();
		_0 = !zephir_is_true(_3);
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(_5);
		object_init_ex(_5, nc_message_sender_exception_ce);
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SV(_6, "Cannot do command: ", step);
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "nc/message/sender/smtp.zep", 90 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_5);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 1024);
	ZEPHIR_CALL_FUNCTION(&_9, "fread", &_10, _7, &_8);
	zephir_check_call_status();
	zephir_fast_trim(_5, _9, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(_11, _5);
	ZEPHIR_CPY_WRT(output, _11);
	_12 = zephir_is_true(validResult);
	if (_12) {
		ZEPHIR_INIT_VAR(_13);
		zephir_fast_strpos(_13, output, validResult, 0 );
		_12 = !ZEPHIR_IS_LONG_IDENTICAL(_13, 0);
	}
	if (unlikely(_12)) {
		ZEPHIR_INIT_VAR(_14);
		object_init_ex(_14, nc_message_sender_exception_ce);
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SVSV(_6, "Invalid command result: ", step, ", with output: ", output);
		ZEPHIR_CALL_METHOD(NULL, _14, "__construct", NULL, _6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_14, "nc/message/sender/smtp.zep", 96 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

