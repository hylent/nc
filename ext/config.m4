PHP_ARG_ENABLE(nc, whether to enable nc, [ --enable-nc   Enable Nc])

if test "$PHP_NC" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, NC_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_NC, 1, [Whether you have Nc])
	nc_sources="nc.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c nc/exception.zep.c
	nc/di/containerinterface.zep.c
	nc/sequence/sequencebackendinterface.zep.c
	nc/di/injectedsetupmethodinterface.zep.c
	nc/log/writerinterface.zep.c
	nc/sequence/sequencebackendabstract.zep.c
	nc/di/creatorabstract.zep.c
	nc/storage/storageinterface.zep.c
	nc/storage/urigeneratorinterface.zep.c
	nc/cache/cachebackendinterface.zep.c
	nc/config/configinterface.zep.c
	nc/db/daoabstract.zep.c
	nc/db/dbinterface.zep.c
	nc/image/imageinterface.zep.c
	nc/mvc/contextabstract.zep.c
	nc/ratelimiter/ratelimiterbackendinterface.zep.c
	nc/storage/storageabstract.zep.c
	nc/cache/cachebackendabstract.zep.c
	nc/config/filesystemabstract.zep.c
	nc/db/dbabstract.zep.c
	nc/image/imageabstract.zep.c
	nc/log/writerbufferedabstract.zep.c
	nc/mvc/controllerinterface.zep.c
	nc/netutils/exception.zep.c
	nc/queue/queueinterface.zep.c
	nc/ratelimiter/ratelimiterbackendabstract.zep.c
	nc/di/creatorclassprefix.zep.c
	nc/mvc/contexthttp.zep.c
	nc/cache/apcu.zep.c
	nc/cache/cachepool.zep.c
	nc/cache/exception.zep.c
	nc/cache/filesystem.zep.c
	nc/config/exception.zep.c
	nc/config/ini.zep.c
	nc/config/php.zep.c
	nc/db/daomysql.zep.c
	nc/db/daooracle.zep.c
	nc/db/daopgsql.zep.c
	nc/db/exception.zep.c
	nc/db/oci8.zep.c
	nc/db/pdo.zep.c
	nc/di/creatorclassmapper.zep.c
	nc/di/creatorclassnamespace.zep.c
	nc/di/creators.zep.c
	nc/di/exception.zep.c
	nc/di/injectedctorparamsinterface.zep.c
	nc/di/injectedpropertyinterface.zep.c
	nc/di/injector.zep.c
	nc/image/area.zep.c
	nc/image/exception.zep.c
	nc/image/gd.zep.c
	nc/image/imagick.zep.c
	nc/log/exception.zep.c
	nc/log/file.zep.c
	nc/log/logger.zep.c
	nc/log/nil.zep.c
	nc/log/redislist.zep.c
	nc/log/stderr.zep.c
	nc/mvc/application.zep.c
	nc/mvc/contextcli.zep.c
	nc/mvc/contexthttpswoole.zep.c
	nc/mvc/controllercliswoole.zep.c
	nc/mvc/controllerdefault.zep.c
	nc/mvc/exception.zep.c
	nc/mvc/sessionautogcsavehandler.zep.c
	nc/mvc/sessionautogcstorageinterface.zep.c
	nc/mvc/uploadedfile.zep.c
	nc/netutils/smtp.zep.c
	nc/netutils/smtpexception.zep.c
	nc/netutils/tcpsocketclient.zep.c
	nc/netutils/tcpsocketclientexception.zep.c
	nc/queue/exception.zep.c
	nc/queue/mysql.zep.c
	nc/queue/redis.zep.c
	nc/ratelimiter/exception.zep.c
	nc/ratelimiter/mysql.zep.c
	nc/ratelimiter/ratelimiter.zep.c
	nc/ratelimiter/redis.zep.c
	nc/sequence/exception.zep.c
	nc/sequence/mongocollection.zep.c
	nc/sequence/mysql.zep.c
	nc/sequence/mysqlmyisam.zep.c
	nc/sequence/redis.zep.c
	nc/sequence/redishash.zep.c
	nc/sequence/sequence.zep.c
	nc/storage/exception.zep.c
	nc/storage/fastdfs.zep.c
	nc/storage/filesystem.zep.c
	nc/storage/ftp.zep.c "
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
