PHP_ARG_ENABLE(nc, whether to enable nc, [ --enable-nc   Enable Nc])

if test "$PHP_NC" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, NC_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_NC, 1, [Whether you have Nc])
	nc_sources="nc.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c nc/exception.zep.c
	nc/router/sourceinterface.zep.c
	nc/view/viewinterface.zep.c
	nc/factory/factoryinterface.zep.c
	nc/data/dataabstract.zep.c
	nc/logger/loggerinterface.zep.c
	nc/db/dbabstract.zep.c
	nc/factory/factoryabstract.zep.c
	nc/logger/loggerabstract.zep.c
	nc/factory/classnameabstract.zep.c
	nc/image/imageabstract.zep.c
	nc/upload/storageabstract.zep.c
	nc/db/exception.zep.c
	nc/db/pdoabstract.zep.c
	nc/image/imagebackendabstract.zep.c
	nc/loader/loaderabstract.zep.c
	nc/router/routerabstract.zep.c
	nc/router/sourceuri.zep.c
	nc/task/taskmanagerabstract.zep.c
	nc/di.zep.c
	nc/factory/prefixed.zep.c
	nc/image/image.zep.c
	nc/router/exception.zep.c
	nc/application.zep.c
	nc/data/exception.zep.c
	nc/data/grouped.zep.c
	nc/data/groupedbackendinterface.zep.c
	nc/data/pivot.zep.c
	nc/data/pivotbackendinterface.zep.c
	nc/data/ratelimiter.zep.c
	nc/data/ratelimiterbackendinterface.zep.c
	nc/data/sequence.zep.c
	nc/data/sequencebackendinterface.zep.c
	nc/data/singlevalue.zep.c
	nc/data/singlevaluebackendinterface.zep.c
	nc/db/collection.zep.c
	nc/db/entity.zep.c
	nc/db/model.zep.c
	nc/db/oci8.zep.c
	nc/db/pdomysql.zep.c
	nc/db/pdopgsql.zep.c
	nc/db/queryexception.zep.c
	nc/db/transactionexception.zep.c
	nc/factory/exception.zep.c
	nc/factory/factories.zep.c
	nc/factory/generated.zep.c
	nc/factory/namespaced.zep.c
	nc/image/captcha.zep.c
	nc/image/exception.zep.c
	nc/image/gd.zep.c
	nc/image/imagick.zep.c
	nc/image/text.zep.c
	nc/loader/exception.zep.c
	nc/loader/namepath.zep.c
	nc/loader/namespacedirectory.zep.c
	nc/logger/exception.zep.c
	nc/logger/file.zep.c
	nc/logger/logclosure.zep.c
	nc/logger/loggers.zep.c
	nc/logger/nil.zep.c
	nc/netutils/exception.zep.c
	nc/netutils/smtpmailer.zep.c
	nc/netutils/socketclient.zep.c
	nc/router/action.zep.c
	nc/router/controlleraction.zep.c
	nc/router/notfoundexception.zep.c
	nc/router/sourceargv.zep.c
	nc/router/sourcerequesturi.zep.c
	nc/router/sourcesapistrategy.zep.c
	nc/router/sourceuripatterns.zep.c
	nc/std.zep.c
	nc/task/exception.zep.c
	nc/task/queueredis.zep.c
	nc/task/rundirectly.zep.c
	nc/task/taskexecutorinterface.zep.c
	nc/upload/exception.zep.c
	nc/upload/fastdfs.zep.c
	nc/upload/filesystem.zep.c
	nc/upload/ftp.zep.c
	nc/upload/uploadedfile.zep.c
	nc/upload/uploader.zep.c
	nc/view/content.zep.c
	nc/view/exception.zep.c
	nc/view/facade.zep.c
	nc/view/httpresponse.zep.c
	nc/view/json.zep.c
	nc/view/nil.zep.c
	nc/view/readfile.zep.c
	nc/view/redirect.zep.c
	nc/view/tpl.zep.c "
	PHP_NEW_EXTENSION(nc, $nc_sources, $ext_shared,, )
	PHP_SUBST(NC_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([nc], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([nc], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/nc], [php_NC.h])

fi
