
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "utils.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *utils_convert_ce;

ZEND_DECLARE_MODULE_GLOBALS(utils)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(utils)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Utils_Convert);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(utils)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_utils_globals *utils_globals)
{
	utils_globals->initialized = 0;

	/* Cache Enabled */
	utils_globals->cache_enabled = 1;

	/* Recursive Lock */
	utils_globals->recursive_lock = 0;

	/* Static cache */
	memset(utils_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_utils_globals *utils_globals)
{
	
}

static PHP_RINIT_FUNCTION(utils)
{
	zend_utils_globals *utils_globals_ptr;
	utils_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(utils_globals_ptr);
	zephir_initialize_memory(utils_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(utils)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(utils)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_UTILS_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_UTILS_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_UTILS_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_UTILS_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_UTILS_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(utils)
{
#if defined(COMPILE_DL_UTILS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(utils_globals);
	php_zephir_init_module_globals(utils_globals);
}

static PHP_GSHUTDOWN_FUNCTION(utils)
{
	
}


zend_function_entry php_utils_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_utils_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry utils_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_utils_deps,
	PHP_UTILS_EXTNAME,
	php_utils_functions,
	PHP_MINIT(utils),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(utils),
#else
	NULL,
#endif
	PHP_RINIT(utils),
	PHP_RSHUTDOWN(utils),
	PHP_MINFO(utils),
	PHP_UTILS_VERSION,
	ZEND_MODULE_GLOBALS(utils),
	PHP_GINIT(utils),
	PHP_GSHUTDOWN(utils),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(utils),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_UTILS
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(utils)
#endif
