
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_NC_H
#define PHP_NC_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_NC_NAME        "Nc Framework"
#define PHP_NC_VERSION     "0.9.1701"
#define PHP_NC_EXTNAME     "nc"
#define PHP_NC_AUTHOR      "Hylent"
#define PHP_NC_ZEPVERSION  "0.9.6a-dev-72dbb2063e"
#define PHP_NC_DESCRIPTION "A PHP framework for web development."



ZEND_BEGIN_MODULE_GLOBALS(nc)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(nc)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(nc)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(nc, v)
#else
	#define ZEPHIR_GLOBAL(v) (nc_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_nc_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(nc_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(nc_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def nc_globals
#define zend_zephir_globals_def zend_nc_globals

extern zend_module_entry nc_module_entry;
#define phpext_nc_ptr &nc_module_entry

#endif
