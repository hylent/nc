PHP_ARG_ENABLE(nc, whether to enable nc, [ --enable-nc   Enable Nc])

if test "$PHP_NC" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, NC_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_NC, 1, [Whether you have Nc])
	nc_sources="nc.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c nc/cache/apc.zep.c
	nc/cache/cacheadapter.zep.c
	nc/cache/cacheawareinterface.zep.c
	nc/cache/cacheinterface.zep.c
	nc/cache/exception.zep.c
	nc/cache/file.zep.c
	nc/cache/memcache.zep.c
	nc/cache/redis.zep.c
	nc/db/dbadapter.zep.c
	nc/db/dbawareinterface.zep.c
	nc/db/dbinterface.zep.c
	nc/db/exception.zep.c
	nc/db/oci.zep.c
	nc/db/pdo.zep.c
	nc/db/query/dbqueryadapter.zep.c
	nc/db/query/exception.zep.c
	nc/db/query/mysql.zep.c
	nc/db/query/oracle.zep.c
	nc/db/query/pgsql.zep.c
	nc/db/queryexception.zep.c
	nc/exception.zep.c
	nc/image/backend/exception.zep.c
	nc/image/backend/gd.zep.c
	nc/image/backend/imagebackendadapter.zep.c
	nc/image/backend/imagebackendinterface.zep.c
	nc/image/backend/imagick.zep.c
	nc/image/exception.zep.c
	nc/image/image.zep.c
	nc/image/item.zep.c
	nc/image/text.zep.c
	nc/loader/classpath.zep.c
	nc/loader/exception.zep.c
	nc/loader/loaderadapter.zep.c
	nc/loader/loaderinterface.zep.c
	nc/loader/namespacedirectory.zep.c
	nc/log/backend/exception.zep.c
	nc/log/backend/file.zep.c
	nc/log/backend/logbackendawareinterface.zep.c
	nc/log/backend/logbackendinterface.zep.c
	nc/log/backend/nil.zep.c
	nc/log/exception.zep.c
	nc/log/logger.zep.c
	nc/message/exception.zep.c
	nc/message/sender/exception.zep.c
	nc/message/sender/messagesenderawareinterface.zep.c
	nc/message/sender/messagesenderinterface.zep.c
	nc/message/sender/smtp.zep.c
	nc/serializer/exception.zep.c
	nc/serializer/igbinary.zep.c
	nc/serializer/json.zep.c
	nc/serializer/php.zep.c
	nc/serializer/serializerawareinterface.zep.c
	nc/serializer/serializerinterface.zep.c
	nc/std.zep.c
	nc/storage/backend/exception.zep.c
	nc/storage/backend/filesystem.zep.c
	nc/storage/backend/ftp.zep.c
	nc/storage/backend/storagebackendadapter.zep.c
	nc/storage/backend/storagebackendawareinterface.zep.c
	nc/storage/backend/storagebackendinterface.zep.c
	nc/storage/exception.zep.c
	nc/storage/namepolicy/storagenamepolicyawareinterface.zep.c
	nc/storage/namepolicy/storagenamepolicyinterface.zep.c
	nc/storage/namepolicy/uuid.zep.c
	nc/storage/uploader.zep.c "
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
