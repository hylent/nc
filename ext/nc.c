
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "nc.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *nc_di_containerinterface_ce;
zend_class_entry *nc_sequence_sequencebackendinterface_ce;
zend_class_entry *nc_di_injectedsetupmethodinterface_ce;
zend_class_entry *nc_log_writerinterface_ce;
zend_class_entry *nc_storage_storageinterface_ce;
zend_class_entry *nc_storage_urigeneratorinterface_ce;
zend_class_entry *nc_cache_cachebackendinterface_ce;
zend_class_entry *nc_config_configinterface_ce;
zend_class_entry *nc_db_dbinterface_ce;
zend_class_entry *nc_image_imageinterface_ce;
zend_class_entry *nc_ratelimiter_ratelimiterbackendinterface_ce;
zend_class_entry *nc_mvc_controllerinterface_ce;
zend_class_entry *nc_queue_queueinterface_ce;
zend_class_entry *nc_di_injectedctorparamsinterface_ce;
zend_class_entry *nc_di_injectedpropertyinterface_ce;
zend_class_entry *nc_mvc_sessionautogcstorageinterface_ce;
zend_class_entry *nc_exception_ce;
zend_class_entry *nc_sequence_sequencebackendabstract_ce;
zend_class_entry *nc_di_creatorabstract_ce;
zend_class_entry *nc_db_daoabstract_ce;
zend_class_entry *nc_mvc_contextabstract_ce;
zend_class_entry *nc_storage_storageabstract_ce;
zend_class_entry *nc_cache_cachebackendabstract_ce;
zend_class_entry *nc_config_filesystemabstract_ce;
zend_class_entry *nc_db_dbabstract_ce;
zend_class_entry *nc_image_imageabstract_ce;
zend_class_entry *nc_log_writerbufferedabstract_ce;
zend_class_entry *nc_netutils_exception_ce;
zend_class_entry *nc_ratelimiter_ratelimiterbackendabstract_ce;
zend_class_entry *nc_di_creatorclassprefix_ce;
zend_class_entry *nc_mvc_contexthttp_ce;
zend_class_entry *nc_cache_apcu_ce;
zend_class_entry *nc_cache_cachepool_ce;
zend_class_entry *nc_cache_exception_ce;
zend_class_entry *nc_cache_filesystem_ce;
zend_class_entry *nc_config_exception_ce;
zend_class_entry *nc_config_ini_ce;
zend_class_entry *nc_config_php_ce;
zend_class_entry *nc_db_daomysql_ce;
zend_class_entry *nc_db_daooracle_ce;
zend_class_entry *nc_db_daopgsql_ce;
zend_class_entry *nc_db_exception_ce;
zend_class_entry *nc_db_oci8_ce;
zend_class_entry *nc_db_pdo_ce;
zend_class_entry *nc_di_creatorclassmapper_ce;
zend_class_entry *nc_di_creatorclassnamespace_ce;
zend_class_entry *nc_di_creators_ce;
zend_class_entry *nc_di_exception_ce;
zend_class_entry *nc_di_injector_ce;
zend_class_entry *nc_image_area_ce;
zend_class_entry *nc_image_exception_ce;
zend_class_entry *nc_image_gd_ce;
zend_class_entry *nc_image_imagick_ce;
zend_class_entry *nc_log_exception_ce;
zend_class_entry *nc_log_file_ce;
zend_class_entry *nc_log_logger_ce;
zend_class_entry *nc_log_nil_ce;
zend_class_entry *nc_log_redislist_ce;
zend_class_entry *nc_log_stderr_ce;
zend_class_entry *nc_mvc_application_ce;
zend_class_entry *nc_mvc_contextcli_ce;
zend_class_entry *nc_mvc_contexthttpswoole_ce;
zend_class_entry *nc_mvc_controllercliswoole_ce;
zend_class_entry *nc_mvc_controllerdefault_ce;
zend_class_entry *nc_mvc_exception_ce;
zend_class_entry *nc_mvc_sessionautogcsavehandler_ce;
zend_class_entry *nc_mvc_uploadedfile_ce;
zend_class_entry *nc_netutils_smtp_ce;
zend_class_entry *nc_netutils_smtpexception_ce;
zend_class_entry *nc_netutils_tcpsocketclient_ce;
zend_class_entry *nc_netutils_tcpsocketclientexception_ce;
zend_class_entry *nc_queue_exception_ce;
zend_class_entry *nc_queue_mysql_ce;
zend_class_entry *nc_queue_redis_ce;
zend_class_entry *nc_ratelimiter_exception_ce;
zend_class_entry *nc_ratelimiter_mysql_ce;
zend_class_entry *nc_ratelimiter_ratelimiter_ce;
zend_class_entry *nc_ratelimiter_redis_ce;
zend_class_entry *nc_sequence_exception_ce;
zend_class_entry *nc_sequence_mongocollection_ce;
zend_class_entry *nc_sequence_mysql_ce;
zend_class_entry *nc_sequence_mysqlmyisam_ce;
zend_class_entry *nc_sequence_redis_ce;
zend_class_entry *nc_sequence_redishash_ce;
zend_class_entry *nc_sequence_sequence_ce;
zend_class_entry *nc_storage_exception_ce;
zend_class_entry *nc_storage_fastdfs_ce;
zend_class_entry *nc_storage_filesystem_ce;
zend_class_entry *nc_storage_ftp_ce;

ZEND_DECLARE_MODULE_GLOBALS(nc)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(nc)
{
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Nc_Di_ContainerInterface);
	ZEPHIR_INIT(Nc_Sequence_SequenceBackendInterface);
	ZEPHIR_INIT(Nc_Di_InjectedSetupMethodInterface);
	ZEPHIR_INIT(Nc_Log_WriterInterface);
	ZEPHIR_INIT(Nc_Storage_StorageInterface);
	ZEPHIR_INIT(Nc_Storage_UriGeneratorInterface);
	ZEPHIR_INIT(Nc_Cache_CacheBackendInterface);
	ZEPHIR_INIT(Nc_Config_ConfigInterface);
	ZEPHIR_INIT(Nc_Db_DbInterface);
	ZEPHIR_INIT(Nc_Image_ImageInterface);
	ZEPHIR_INIT(Nc_RateLimiter_RateLimiterBackendInterface);
	ZEPHIR_INIT(Nc_Mvc_ControllerInterface);
	ZEPHIR_INIT(Nc_Queue_QueueInterface);
	ZEPHIR_INIT(Nc_Di_InjectedCtorParamsInterface);
	ZEPHIR_INIT(Nc_Di_InjectedPropertyInterface);
	ZEPHIR_INIT(Nc_Mvc_SessionAutoGcStorageInterface);
	ZEPHIR_INIT(Nc_Exception);
	ZEPHIR_INIT(Nc_Sequence_SequenceBackendAbstract);
	ZEPHIR_INIT(Nc_Di_CreatorAbstract);
	ZEPHIR_INIT(Nc_Db_DaoAbstract);
	ZEPHIR_INIT(Nc_Mvc_ContextAbstract);
	ZEPHIR_INIT(Nc_Storage_StorageAbstract);
	ZEPHIR_INIT(Nc_Cache_CacheBackendAbstract);
	ZEPHIR_INIT(Nc_Config_FileSystemAbstract);
	ZEPHIR_INIT(Nc_Db_DbAbstract);
	ZEPHIR_INIT(Nc_Image_ImageAbstract);
	ZEPHIR_INIT(Nc_Log_WriterBufferedAbstract);
	ZEPHIR_INIT(Nc_NetUtils_Exception);
	ZEPHIR_INIT(Nc_RateLimiter_RateLimiterBackendAbstract);
	ZEPHIR_INIT(Nc_Di_CreatorClassPrefix);
	ZEPHIR_INIT(Nc_Mvc_ContextHttp);
	ZEPHIR_INIT(Nc_Cache_Apcu);
	ZEPHIR_INIT(Nc_Cache_CachePool);
	ZEPHIR_INIT(Nc_Cache_Exception);
	ZEPHIR_INIT(Nc_Cache_FileSystem);
	ZEPHIR_INIT(Nc_Config_Exception);
	ZEPHIR_INIT(Nc_Config_Ini);
	ZEPHIR_INIT(Nc_Config_Php);
	ZEPHIR_INIT(Nc_Db_DaoMysql);
	ZEPHIR_INIT(Nc_Db_DaoOracle);
	ZEPHIR_INIT(Nc_Db_DaoPgsql);
	ZEPHIR_INIT(Nc_Db_Exception);
	ZEPHIR_INIT(Nc_Db_Oci8);
	ZEPHIR_INIT(Nc_Db_Pdo);
	ZEPHIR_INIT(Nc_Di_CreatorClassMapper);
	ZEPHIR_INIT(Nc_Di_CreatorClassNamespace);
	ZEPHIR_INIT(Nc_Di_Creators);
	ZEPHIR_INIT(Nc_Di_Exception);
	ZEPHIR_INIT(Nc_Di_Injector);
	ZEPHIR_INIT(Nc_Image_Area);
	ZEPHIR_INIT(Nc_Image_Exception);
	ZEPHIR_INIT(Nc_Image_Gd);
	ZEPHIR_INIT(Nc_Image_Imagick);
	ZEPHIR_INIT(Nc_Log_Exception);
	ZEPHIR_INIT(Nc_Log_File);
	ZEPHIR_INIT(Nc_Log_Logger);
	ZEPHIR_INIT(Nc_Log_Nil);
	ZEPHIR_INIT(Nc_Log_RedisList);
	ZEPHIR_INIT(Nc_Log_StdErr);
	ZEPHIR_INIT(Nc_Mvc_Application);
	ZEPHIR_INIT(Nc_Mvc_ContextCli);
	ZEPHIR_INIT(Nc_Mvc_ContextHttpSwoole);
	ZEPHIR_INIT(Nc_Mvc_ControllerCliSwoole);
	ZEPHIR_INIT(Nc_Mvc_ControllerDefault);
	ZEPHIR_INIT(Nc_Mvc_Exception);
	ZEPHIR_INIT(Nc_Mvc_SessionAutoGcSaveHandler);
	ZEPHIR_INIT(Nc_Mvc_UploadedFile);
	ZEPHIR_INIT(Nc_NetUtils_Smtp);
	ZEPHIR_INIT(Nc_NetUtils_SmtpException);
	ZEPHIR_INIT(Nc_NetUtils_TcpSocketClient);
	ZEPHIR_INIT(Nc_NetUtils_TcpSocketClientException);
	ZEPHIR_INIT(Nc_Queue_Exception);
	ZEPHIR_INIT(Nc_Queue_Mysql);
	ZEPHIR_INIT(Nc_Queue_Redis);
	ZEPHIR_INIT(Nc_RateLimiter_Exception);
	ZEPHIR_INIT(Nc_RateLimiter_Mysql);
	ZEPHIR_INIT(Nc_RateLimiter_RateLimiter);
	ZEPHIR_INIT(Nc_RateLimiter_Redis);
	ZEPHIR_INIT(Nc_Sequence_Exception);
	ZEPHIR_INIT(Nc_Sequence_MongoCollection);
	ZEPHIR_INIT(Nc_Sequence_Mysql);
	ZEPHIR_INIT(Nc_Sequence_MysqlMyisam);
	ZEPHIR_INIT(Nc_Sequence_Redis);
	ZEPHIR_INIT(Nc_Sequence_RedisHash);
	ZEPHIR_INIT(Nc_Sequence_Sequence);
	ZEPHIR_INIT(Nc_Storage_Exception);
	ZEPHIR_INIT(Nc_Storage_Fastdfs);
	ZEPHIR_INIT(Nc_Storage_FileSystem);
	ZEPHIR_INIT(Nc_Storage_Ftp);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(nc)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_nc_globals *nc_globals TSRMLS_DC)
{
	nc_globals->initialized = 0;

	/* Memory options */
	nc_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	nc_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	nc_globals->cache_enabled = 1;

	/* Recursive Lock */
	nc_globals->recursive_lock = 0;

	/* Static cache */
	memset(nc_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_nc_globals *nc_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(nc)
{

	zend_nc_globals *nc_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	nc_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(nc_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(nc_globals_ptr TSRMLS_CC);


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
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_NC_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(nc)
{
	php_zephir_init_globals(nc_globals TSRMLS_CC);
	php_zephir_init_module_globals(nc_globals TSRMLS_CC);
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
