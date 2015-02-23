
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
zend_class_entry *nc_storage_naming_storagenamingawareinterface_ce;
zend_class_entry *nc_storage_storageinterface_ce;
zend_class_entry *nc_image_imageinterface_ce;
zend_class_entry *nc_loader_loaderinterface_ce;
zend_class_entry *nc_db_dbinterface_ce;
zend_class_entry *nc_serializer_serializerinterface_ce;
zend_class_entry *nc_log_backend_logbackendinterface_ce;
zend_class_entry *nc_router_routerinterface_ce;
zend_class_entry *nc_storage_naming_storagenaminginterface_ce;
zend_class_entry *nc_log_backend_logbackendawareinterface_ce;
zend_class_entry *nc_message_sender_messagesenderinterface_ce;
zend_class_entry *nc_cache_cacheawareinterface_ce;
zend_class_entry *nc_db_dbawareinterface_ce;
zend_class_entry *nc_message_sender_messagesenderawareinterface_ce;
zend_class_entry *nc_router_routerawareinterface_ce;
zend_class_entry *nc_storage_storageawareinterface_ce;
zend_class_entry *nc_exception_ce;
zend_class_entry *nc_cache_cacheabstract_ce;
zend_class_entry *nc_db_exception_ce;
zend_class_entry *nc_db_query_dbqueryabstract_ce;
zend_class_entry *nc_db_dbabstract_ce;
zend_class_entry *nc_image_imageabstract_ce;
zend_class_entry *nc_image_item_imageitemabstract_ce;
zend_class_entry *nc_loader_loaderabstract_ce;
zend_class_entry *nc_router_routerabstract_ce;
zend_class_entry *nc_storage_storageabstract_ce;
zend_class_entry *nc_image_exception_ce;
zend_class_entry *nc_log_exception_ce;
zend_class_entry *nc_message_exception_ce;
zend_class_entry *nc_router_uri_ce;
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
zend_class_entry *nc_db_savepointexception_ce;
zend_class_entry *nc_db_transactionexception_ce;
zend_class_entry *nc_image_gd_ce;
zend_class_entry *nc_image_imagick_ce;
zend_class_entry *nc_image_item_exception_ce;
zend_class_entry *nc_image_item_image_ce;
zend_class_entry *nc_image_item_text_ce;
zend_class_entry *nc_loader_classpath_ce;
zend_class_entry *nc_loader_exception_ce;
zend_class_entry *nc_loader_namespacedirectory_ce;
zend_class_entry *nc_log_backend_exception_ce;
zend_class_entry *nc_log_backend_file_ce;
zend_class_entry *nc_log_backend_nil_ce;
zend_class_entry *nc_log_logger_ce;
zend_class_entry *nc_message_sender_exception_ce;
zend_class_entry *nc_message_sender_smtp_ce;
zend_class_entry *nc_router_exception_ce;
zend_class_entry *nc_router_urienhanced_ce;
zend_class_entry *nc_serializer_exception_ce;
zend_class_entry *nc_serializer_igbinary_ce;
zend_class_entry *nc_serializer_json_ce;
zend_class_entry *nc_serializer_php_ce;
zend_class_entry *nc_std_ce;
zend_class_entry *nc_storage_exception_ce;
zend_class_entry *nc_storage_filesystem_ce;
zend_class_entry *nc_storage_ftp_ce;
zend_class_entry *nc_storage_naming_date_ce;
zend_class_entry *nc_storage_naming_uuid_ce;

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
	ZEPHIR_INIT(Nc_Storage_Naming_StorageNamingAwareInterface);
	ZEPHIR_INIT(Nc_Storage_StorageInterface);
	ZEPHIR_INIT(Nc_Image_ImageInterface);
	ZEPHIR_INIT(Nc_Loader_LoaderInterface);
	ZEPHIR_INIT(Nc_Db_DbInterface);
	ZEPHIR_INIT(Nc_Serializer_SerializerInterface);
	ZEPHIR_INIT(Nc_Log_Backend_LogBackendInterface);
	ZEPHIR_INIT(Nc_Router_RouterInterface);
	ZEPHIR_INIT(Nc_Storage_Naming_StorageNamingInterface);
	ZEPHIR_INIT(Nc_Log_Backend_LogBackendAwareInterface);
	ZEPHIR_INIT(Nc_Message_Sender_MessageSenderInterface);
	ZEPHIR_INIT(Nc_Cache_CacheAwareInterface);
	ZEPHIR_INIT(Nc_Db_DbAwareInterface);
	ZEPHIR_INIT(Nc_Message_Sender_MessageSenderAwareInterface);
	ZEPHIR_INIT(Nc_Router_RouterAwareInterface);
	ZEPHIR_INIT(Nc_Storage_StorageAwareInterface);
	ZEPHIR_INIT(Nc_Exception);
	ZEPHIR_INIT(Nc_Cache_CacheAbstract);
	ZEPHIR_INIT(Nc_Db_Exception);
	ZEPHIR_INIT(Nc_Db_Query_DbQueryAbstract);
	ZEPHIR_INIT(Nc_Db_DbAbstract);
	ZEPHIR_INIT(Nc_Image_ImageAbstract);
	ZEPHIR_INIT(Nc_Image_Item_ImageItemAbstract);
	ZEPHIR_INIT(Nc_Loader_LoaderAbstract);
	ZEPHIR_INIT(Nc_Router_RouterAbstract);
	ZEPHIR_INIT(Nc_Storage_StorageAbstract);
	ZEPHIR_INIT(Nc_Image_Exception);
	ZEPHIR_INIT(Nc_Log_Exception);
	ZEPHIR_INIT(Nc_Message_Exception);
	ZEPHIR_INIT(Nc_Router_Uri);
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
	ZEPHIR_INIT(Nc_Db_SavepointException);
	ZEPHIR_INIT(Nc_Db_TransactionException);
	ZEPHIR_INIT(Nc_Image_Gd);
	ZEPHIR_INIT(Nc_Image_Imagick);
	ZEPHIR_INIT(Nc_Image_Item_Exception);
	ZEPHIR_INIT(Nc_Image_Item_Image);
	ZEPHIR_INIT(Nc_Image_Item_Text);
	ZEPHIR_INIT(Nc_Loader_ClassPath);
	ZEPHIR_INIT(Nc_Loader_Exception);
	ZEPHIR_INIT(Nc_Loader_NamespaceDirectory);
	ZEPHIR_INIT(Nc_Log_Backend_Exception);
	ZEPHIR_INIT(Nc_Log_Backend_File);
	ZEPHIR_INIT(Nc_Log_Backend_Nil);
	ZEPHIR_INIT(Nc_Log_Logger);
	ZEPHIR_INIT(Nc_Message_Sender_Exception);
	ZEPHIR_INIT(Nc_Message_Sender_Smtp);
	ZEPHIR_INIT(Nc_Router_Exception);
	ZEPHIR_INIT(Nc_Router_UriEnhanced);
	ZEPHIR_INIT(Nc_Serializer_Exception);
	ZEPHIR_INIT(Nc_Serializer_Igbinary);
	ZEPHIR_INIT(Nc_Serializer_Json);
	ZEPHIR_INIT(Nc_Serializer_Php);
	ZEPHIR_INIT(Nc_Std);
	ZEPHIR_INIT(Nc_Storage_Exception);
	ZEPHIR_INIT(Nc_Storage_FileSystem);
	ZEPHIR_INIT(Nc_Storage_Ftp);
	ZEPHIR_INIT(Nc_Storage_Naming_Date);
	ZEPHIR_INIT(Nc_Storage_Naming_Uuid);

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


zend_function_entry php_nc_functions[] = {
ZEND_FE_END

};

zend_module_entry nc_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_NC_EXTNAME,
	php_nc_functions,
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
