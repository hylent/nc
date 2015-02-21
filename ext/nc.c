
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "nc.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *nc_cache_cacheinterface_ce;
zend_class_entry *nc_serializer_serializerawareinterface_ce;
zend_class_entry *nc_storage_backend_storagebackendinterface_ce;
zend_class_entry *nc_storage_namepolicy_storagenamepolicyawareinterface_ce;
zend_class_entry *nc_image_backend_imagebackendinterface_ce;
zend_class_entry *nc_loader_loaderinterface_ce;
zend_class_entry *nc_db_dbinterface_ce;
zend_class_entry *nc_serializer_serializerinterface_ce;
zend_class_entry *nc_log_backend_logbackendinterface_ce;
zend_class_entry *nc_log_backend_logbackendawareinterface_ce;
zend_class_entry *nc_message_sender_messagesenderinterface_ce;
zend_class_entry *nc_storage_backend_storagebackendawareinterface_ce;
zend_class_entry *nc_storage_namepolicy_storagenamepolicyinterface_ce;
zend_class_entry *nc_cache_cacheawareinterface_ce;
zend_class_entry *nc_db_dbawareinterface_ce;
zend_class_entry *nc_message_sender_messagesenderawareinterface_ce;
zend_class_entry *nc_exception_ce;
zend_class_entry *nc_cache_cacheadapter_ce;
zend_class_entry *nc_db_query_dbqueryadapter_ce;
zend_class_entry *nc_db_dbadapter_ce;
zend_class_entry *nc_db_exception_ce;
zend_class_entry *nc_image_backend_imagebackendadapter_ce;
zend_class_entry *nc_image_item_ce;
zend_class_entry *nc_loader_loaderadapter_ce;
zend_class_entry *nc_storage_backend_storagebackendadapter_ce;
zend_class_entry *nc_image_exception_ce;
zend_class_entry *nc_log_exception_ce;
zend_class_entry *nc_message_exception_ce;
zend_class_entry *nc_storage_exception_ce;
zend_class_entry *nc_cache_apc_ce;
zend_class_entry *nc_cache_exception_ce;
zend_class_entry *nc_cache_file_ce;
zend_class_entry *nc_cache_memcache_ce;
zend_class_entry *nc_cache_redis_ce;
zend_class_entry *nc_db_oci_ce;
zend_class_entry *nc_db_pdo_ce;
zend_class_entry *nc_db_query_exception_ce;
zend_class_entry *nc_db_query_mysql_ce;
zend_class_entry *nc_db_query_oracle_ce;
zend_class_entry *nc_db_query_pgsql_ce;
zend_class_entry *nc_db_queryexception_ce;
zend_class_entry *nc_image_backend_exception_ce;
zend_class_entry *nc_image_backend_gd_ce;
zend_class_entry *nc_image_backend_imagick_ce;
zend_class_entry *nc_image_image_ce;
zend_class_entry *nc_image_text_ce;
zend_class_entry *nc_loader_classpath_ce;
zend_class_entry *nc_loader_exception_ce;
zend_class_entry *nc_loader_namespacedirectory_ce;
zend_class_entry *nc_log_backend_exception_ce;
zend_class_entry *nc_log_backend_file_ce;
zend_class_entry *nc_log_backend_nil_ce;
zend_class_entry *nc_log_logger_ce;
zend_class_entry *nc_message_sender_exception_ce;
zend_class_entry *nc_message_sender_smtp_ce;
zend_class_entry *nc_serializer_exception_ce;
zend_class_entry *nc_serializer_igbinary_ce;
zend_class_entry *nc_serializer_json_ce;
zend_class_entry *nc_serializer_php_ce;
zend_class_entry *nc_std_ce;
zend_class_entry *nc_storage_backend_exception_ce;
zend_class_entry *nc_storage_backend_filesystem_ce;
zend_class_entry *nc_storage_backend_ftp_ce;
zend_class_entry *nc_storage_namepolicy_uuid_ce;
zend_class_entry *nc_storage_uploader_ce;

ZEND_DECLARE_MODULE_GLOBALS(nc)

static PHP_MINIT_FUNCTION(nc)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Nc_Cache_CacheInterface);
	ZEPHIR_INIT(Nc_Serializer_SerializerAwareInterface);
	ZEPHIR_INIT(Nc_Storage_Backend_StorageBackendInterface);
	ZEPHIR_INIT(Nc_Storage_NamePolicy_StorageNamePolicyAwareInterface);
	ZEPHIR_INIT(Nc_Image_Backend_ImageBackendInterface);
	ZEPHIR_INIT(Nc_Loader_LoaderInterface);
	ZEPHIR_INIT(Nc_Db_DbInterface);
	ZEPHIR_INIT(Nc_Serializer_SerializerInterface);
	ZEPHIR_INIT(Nc_Log_Backend_LogBackendInterface);
	ZEPHIR_INIT(Nc_Log_Backend_LogBackendAwareInterface);
	ZEPHIR_INIT(Nc_Message_Sender_MessageSenderInterface);
	ZEPHIR_INIT(Nc_Storage_Backend_StorageBackendAwareInterface);
	ZEPHIR_INIT(Nc_Storage_NamePolicy_StorageNamePolicyInterface);
	ZEPHIR_INIT(Nc_Cache_CacheAwareInterface);
	ZEPHIR_INIT(Nc_Db_DbAwareInterface);
	ZEPHIR_INIT(Nc_Message_Sender_MessageSenderAwareInterface);
	ZEPHIR_INIT(Nc_Exception);
	ZEPHIR_INIT(Nc_Cache_CacheAdapter);
	ZEPHIR_INIT(Nc_Db_Query_DbQueryAdapter);
	ZEPHIR_INIT(Nc_Db_DbAdapter);
	ZEPHIR_INIT(Nc_Db_Exception);
	ZEPHIR_INIT(Nc_Image_Backend_ImageBackendAdapter);
	ZEPHIR_INIT(Nc_Image_Item);
	ZEPHIR_INIT(Nc_Loader_LoaderAdapter);
	ZEPHIR_INIT(Nc_Storage_Backend_StorageBackendAdapter);
	ZEPHIR_INIT(Nc_Image_Exception);
	ZEPHIR_INIT(Nc_Log_Exception);
	ZEPHIR_INIT(Nc_Message_Exception);
	ZEPHIR_INIT(Nc_Storage_Exception);
	ZEPHIR_INIT(Nc_Cache_Apc);
	ZEPHIR_INIT(Nc_Cache_Exception);
	ZEPHIR_INIT(Nc_Cache_File);
	ZEPHIR_INIT(Nc_Cache_Memcache);
	ZEPHIR_INIT(Nc_Cache_Redis);
	ZEPHIR_INIT(Nc_Db_Oci);
	ZEPHIR_INIT(Nc_Db_Pdo);
	ZEPHIR_INIT(Nc_Db_QueryException);
	ZEPHIR_INIT(Nc_Db_Query_Exception);
	ZEPHIR_INIT(Nc_Db_Query_Mysql);
	ZEPHIR_INIT(Nc_Db_Query_Oracle);
	ZEPHIR_INIT(Nc_Db_Query_Pgsql);
	ZEPHIR_INIT(Nc_Image_Backend_Exception);
	ZEPHIR_INIT(Nc_Image_Backend_Gd);
	ZEPHIR_INIT(Nc_Image_Backend_Imagick);
	ZEPHIR_INIT(Nc_Image_Image);
	ZEPHIR_INIT(Nc_Image_Text);
	ZEPHIR_INIT(Nc_Loader_ClassPath);
	ZEPHIR_INIT(Nc_Loader_Exception);
	ZEPHIR_INIT(Nc_Loader_NamespaceDirectory);
	ZEPHIR_INIT(Nc_Log_Backend_Exception);
	ZEPHIR_INIT(Nc_Log_Backend_File);
	ZEPHIR_INIT(Nc_Log_Backend_Nil);
	ZEPHIR_INIT(Nc_Log_Logger);
	ZEPHIR_INIT(Nc_Message_Sender_Exception);
	ZEPHIR_INIT(Nc_Message_Sender_Smtp);
	ZEPHIR_INIT(Nc_Serializer_Exception);
	ZEPHIR_INIT(Nc_Serializer_Igbinary);
	ZEPHIR_INIT(Nc_Serializer_Json);
	ZEPHIR_INIT(Nc_Serializer_Php);
	ZEPHIR_INIT(Nc_Std);
	ZEPHIR_INIT(Nc_Storage_Backend_Exception);
	ZEPHIR_INIT(Nc_Storage_Backend_FileSystem);
	ZEPHIR_INIT(Nc_Storage_Backend_Ftp);
	ZEPHIR_INIT(Nc_Storage_NamePolicy_Uuid);
	ZEPHIR_INIT(Nc_Storage_Uploader);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(nc)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_nc_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(nc)
{

	zend_nc_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(nc)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(nc)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_NC_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_NC_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_NC_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_NC_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_NC_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(nc)
{
	php_zephir_init_globals(nc_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(nc)
{

}

zend_module_entry nc_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_NC_EXTNAME,
	NULL,
	PHP_MINIT(nc),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(nc),
#else
	NULL,
#endif
	PHP_RINIT(nc),
	PHP_RSHUTDOWN(nc),
	PHP_MINFO(nc),
	PHP_NC_VERSION,
	ZEND_MODULE_GLOBALS(nc),
	PHP_GINIT(nc),
	PHP_GSHUTDOWN(nc),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_NC
ZEND_GET_MODULE(nc)
#endif
