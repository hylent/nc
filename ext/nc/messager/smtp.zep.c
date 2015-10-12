
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Messager_Smtp) {

	ZEPHIR_REGISTER_CLASS(Nc\\Messager, Smtp, nc, messager_smtp, nc_messager_smtp_method_entry, 0);

	zend_declare_property_null(nc_messager_smtp_ce, SL("socket"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_messager_smtp_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_messager_smtp_ce, SL("sender"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_messager_smtp_ce, SL("preSubject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_messager_smtp_ce, SL("EOL"), "\r\n" TSRMLS_CC);

	zend_class_implements(nc_messager_smtp_ce TSRMLS_CC, 1, nc_messager_messagerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Messager_Smtp, __construct) {

	zend_bool _1, _6;
	zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *host_param = NULL, *port_param = NULL, *user_param = NULL, *passwd_param = NULL, *from_param = NULL, *sender_param = NULL, *preSubject_param = NULL, *socket = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, _7, *_8 = NULL, *_12 = NULL, *_14 = NULL, *_9$$4, *_15$$5 = NULL, *_16$$5, *_18$$10;
	zval *host = NULL, *port = NULL, *user = NULL, *passwd = NULL, *from = NULL, *sender = NULL, *preSubject = NULL, *_10$$4, *_17$$9;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_messager_exception_ce, "Empty user or passwd", "nc/messager/smtp.zep", 18);
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 30);
	ZEPHIR_MAKE_REF(_3);
	ZEPHIR_CALL_FUNCTION(&socket, "fsockopen", NULL, 84, host, port, _3, _4, _5);
	ZEPHIR_UNREF(_3);
	zephir_check_call_status();
	_6 = !zephir_is_true(socket);
	if (!(_6)) {
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, 1);
		ZEPHIR_CALL_FUNCTION(&_8, "stream_set_blocking", NULL, 85, socket, &_7);
		zephir_check_call_status();
		_6 = !zephir_is_true(_8);
	}
	if (unlikely(_6)) {
		ZEPHIR_INIT_VAR(_9$$4);
		object_init_ex(_9$$4, nc_messager_exception_ce);
		ZEPHIR_INIT_VAR(_10$$4);
		ZEPHIR_CONCAT_SVSV(_10$$4, "Cannot connect or set blocking to ", host, ":", port);
		ZEPHIR_CALL_METHOD(NULL, _9$$4, "__construct", NULL, 2, _10$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9$$4, "nc/messager/smtp.zep", 23 TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_11, 0, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_11, 0, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_11, 0, _3, _4, _5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_12, "base64_encode", &_13, 86, user);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "AUTH USER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_11, 0, _3, _12, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_14, "base64_encode", &_13, 86, passwd);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "AUTH PASSWD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 235);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_11, 0, _3, _14, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("from"), from TSRMLS_CC);
	if (!(!sender) && Z_STRLEN_P(sender)) {
		ZEPHIR_CALL_FUNCTION(&_15$$5, "base64_encode", &_13, 86, sender);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_16$$5);
		ZEPHIR_CONCAT_SVSVS(_16$$5, "=?UTF-8?B?", _15$$5, "?= <", from, ">");
		zephir_update_property_this(this_ptr, SL("sender"), _16$$5 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("sender"), from TSRMLS_CC);
	}
	if (!(!preSubject) && Z_STRLEN_P(preSubject)) {
		zephir_update_property_this(this_ptr, SL("preSubject"), preSubject TSRMLS_CC);
	} else {
		if (!(!sender) && Z_STRLEN_P(sender)) {
			ZEPHIR_INIT_VAR(_17$$9);
			ZEPHIR_CONCAT_SVS(_17$$9, "[", sender, "]");
			zephir_update_property_this(this_ptr, SL("preSubject"), _17$$9 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_18$$10);
			ZVAL_STRING(_18$$10, "", 1);
			zephir_update_property_this(this_ptr, SL("preSubject"), _18$$10 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Messager_Smtp, __destruct) {

	zval *_0$$3, *_1$$3, *_2$$3, *_3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "QUIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "QUIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 221);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", NULL, 0, _0$$3, _1$$3, _2$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	zephir_fclose(_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Messager_Smtp, send) {

	zephir_fcall_cache_entry *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *to_param = NULL, *subject_param = NULL, *message_param = NULL, *lines = NULL, *_0 = NULL, *_1, *_2, *_4, *_5, _6 = zval_used_for_init, *_7 = NULL, *_8, *_9 = NULL, *_10 = NULL, *_11, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15, *_16, *_17, *_18 = NULL, *_21 = NULL;
	zval *to = NULL, *subject = NULL, *message = NULL, *_3, *_20, *_22 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &to_param, &subject_param, &message_param);

	zephir_get_strval(to, to_param);
	zephir_get_strval(subject, subject_param);
	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(lines);
	array_init(lines);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Content-type: text/html; charset=UTF-8", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/messager/smtp.zep", 66);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Content-Transfer-Encoding: base64", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/messager/smtp.zep", 67);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("sender"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "From: ", _1);
	zephir_array_append(&lines, _2, PH_SEPARATE, "nc/messager/smtp.zep", 68);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "To: ", to);
	zephir_array_append(&lines, _3, PH_SEPARATE, "nc/messager/smtp.zep", 69);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("preSubject"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVV(_5, "Subject: ", _4, subject);
	zephir_array_append(&lines, _5, PH_SEPARATE, "nc/messager/smtp.zep", 70);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "r", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "gmdate", NULL, 87, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SV(_8, "Date: ", _7);
	zephir_array_append(&lines, _8, PH_SEPARATE, "nc/messager/smtp.zep", 71);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "MIME-Version: 1.0", 1);
	zephir_array_append(&lines, _0, PH_SEPARATE, "nc/messager/smtp.zep", 72);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_CALL_FUNCTION(&_9, "mt_rand", NULL, 88);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_10, "uniqid", NULL, 89, _9, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_md5(_0, _10);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_SV(_11, "Message-ID: ", _0);
	zephir_array_append(&lines, _11, PH_SEPARATE, "nc/messager/smtp.zep", 73);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_STRING(_12, "X-Priority: 3", 1);
	zephir_array_append(&lines, _12, PH_SEPARATE, "nc/messager/smtp.zep", 74);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "X-Mailer: nc", 1);
	zephir_array_append(&lines, _12, PH_SEPARATE, "nc/messager/smtp.zep", 75);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "", 1);
	zephir_array_append(&lines, _12, PH_SEPARATE, "nc/messager/smtp.zep", 76);
	ZEPHIR_CALL_FUNCTION(&_13, "base64_encode", NULL, 86, message);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_14, "chunk_split", NULL, 90, _13);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_CONCAT_VS(_15, _14, ".");
	zephir_array_append(&lines, _15, PH_SEPARATE, "nc/messager/smtp.zep", 77);
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_17);
	ZEPHIR_CONCAT_SVS(_17, "MAIL FROM: <", _16, ">");
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "MAIL FROM", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_18);
	ZVAL_LONG(_18, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_19, 0, _12, _17, _18);
	zephir_check_temp_parameter(_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_20);
	ZEPHIR_CONCAT_SVS(_20, "RCPT TO: <", to, ">");
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "RCPT TO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_18);
	ZVAL_LONG(_18, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_19, 0, _12, _20, _18);
	zephir_check_temp_parameter(_12);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_18);
	ZVAL_STRING(_18, "DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_21);
	ZVAL_LONG(_21, 354);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_19, 0, _12, _18, _21);
	zephir_check_temp_parameter(_12);
	zephir_check_temp_parameter(_18);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_12);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "\r\n", 0);
	zephir_fast_join(_12, &_6, lines TSRMLS_CC);
	zephir_get_strval(_22, _12);
	ZEPHIR_INIT_NVAR(_18);
	ZVAL_STRING(_18, "END DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_LONG(_21, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "docommand", &_19, 0, _18, _22, _21);
	zephir_check_temp_parameter(_18);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Messager_Smtp, doCommand) {

	zend_bool _0, _11;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *step_param = NULL, *command_param = NULL, *validResult_param = NULL, *_1, *_3 = NULL, *_6, *_7, _8, *_9 = NULL, *_12, *_4$$3, *_13$$4;
	zval *step = NULL, *command = NULL, *validResult = NULL, *output = NULL, *_2, *_10 = NULL, *_5$$3, *_14$$4;

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
		ZEPHIR_CALL_FUNCTION(&_3, "fputs", NULL, 91, _1, _2);
		zephir_check_call_status();
		_0 = !zephir_is_true(_3);
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, nc_messager_exception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, "Cannot do command: ", step);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 2, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "nc/messager/smtp.zep", 90 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_6);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 1024);
	ZEPHIR_CALL_FUNCTION(&_9, "fread", NULL, 47, _7, &_8);
	zephir_check_call_status();
	zephir_fast_trim(_6, _9, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(_10, _6);
	ZEPHIR_CPY_WRT(output, _10);
	_11 = zephir_is_true(validResult);
	if (_11) {
		ZEPHIR_INIT_VAR(_12);
		zephir_fast_strpos(_12, output, validResult, 0 );
		_11 = !ZEPHIR_IS_LONG_IDENTICAL(_12, 0);
	}
	if (unlikely(_11)) {
		ZEPHIR_INIT_VAR(_13$$4);
		object_init_ex(_13$$4, nc_messager_exception_ce);
		ZEPHIR_INIT_VAR(_14$$4);
		ZEPHIR_CONCAT_SVSV(_14$$4, "Invalid command result: ", step, ", with output: ", output);
		ZEPHIR_CALL_METHOD(NULL, _13$$4, "__construct", NULL, 2, _14$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13$$4, "nc/messager/smtp.zep", 96 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

