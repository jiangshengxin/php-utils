
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/math.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Utils_Convert)
{
	ZEPHIR_REGISTER_CLASS(Utils, Convert, utils, convert, utils_convert_method_entry, 0);

	return SUCCESS;
}

/**
 * 数字转字母
 *
 * @param int num
 * @param int start
 *
 * @return string
 */
PHP_METHOD(Utils_Convert, IntToChr)
{
	zval str;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *num_param = NULL, _0, _3, _4, _1$$3, _2$$3;
	zend_long num, ZEPHIR_LAST_CALL_STATUS, start, floor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&str);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(num)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &num_param);
	num = zephir_get_intval(num_param);


	start = 65;
	ZVAL_DOUBLE(&_0, zephir_safe_div_long_long(num, 26));
	floor = (long) (zephir_floor(&_0));
	if (floor > 0) {
		ZVAL_LONG(&_2$$3, (floor - 1));
		ZEPHIR_CALL_SELF(&_1$$3, "inttochr", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_concat_self(&str, &_1$$3);
	}
	ZVAL_DOUBLE(&_3, (zephir_safe_mod_long_long(num, 26) + start));
	ZEPHIR_CALL_FUNCTION(&_4, "chr", NULL, 1, &_3);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &str, &_4);
	RETURN_MM();
}

