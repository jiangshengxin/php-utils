
extern zend_class_entry *utils_convert_ce;

ZEPHIR_INIT_CLASS(Utils_Convert);

PHP_METHOD(Utils_Convert, IntToChr);

ZEND_BEGIN_ARG_INFO_EX(arginfo_utils_convert_inttochr, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, num, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(utils_convert_method_entry) {
	PHP_ME(Utils_Convert, IntToChr, arginfo_utils_convert_inttochr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
