
extern zend_class_entry *nc_data_pivot_ce;

ZEPHIR_INIT_CLASS(Nc_Data_Pivot);

PHP_METHOD(Nc_Data_Pivot, add);
PHP_METHOD(Nc_Data_Pivot, remove);
PHP_METHOD(Nc_Data_Pivot, has);
PHP_METHOD(Nc_Data_Pivot, addObjects);
PHP_METHOD(Nc_Data_Pivot, removeObjects);
PHP_METHOD(Nc_Data_Pivot, hasObjects);
PHP_METHOD(Nc_Data_Pivot, getObjects);
PHP_METHOD(Nc_Data_Pivot, countObjects);
PHP_METHOD(Nc_Data_Pivot, countAndGetObjects);
PHP_METHOD(Nc_Data_Pivot, addSubjects);
PHP_METHOD(Nc_Data_Pivot, removeSubjects);
PHP_METHOD(Nc_Data_Pivot, hasSubjects);
PHP_METHOD(Nc_Data_Pivot, getSubjects);
PHP_METHOD(Nc_Data_Pivot, countSubjects);
PHP_METHOD(Nc_Data_Pivot, countAndGetSubjects);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_add, 0, 0, 3)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_INFO(0, score)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_remove, 0, 0, 2)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_has, 0, 0, 2)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_addobjects, 0, 0, 2)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_ARRAY_INFO(0, objScores, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_removeobjects, 0, 0, 2)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_ARRAY_INFO(0, objs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_hasobjects, 0, 0, 2)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_ARRAY_INFO(0, objs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_getobjects, 0, 0, 1)
	ZEND_ARG_INFO(0, subj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_countobjects, 0, 0, 1)
	ZEND_ARG_INFO(0, subj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_countandgetobjects, 0, 0, 1)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_INFO(0, asc)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_addsubjects, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, subjScores, 0)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_removesubjects, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, subjs, 0)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_hassubjects, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, subjs, 0)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_getsubjects, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_countsubjects, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_data_pivot_countandgetsubjects, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_INFO(0, asc)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_data_pivot_method_entry) {
	PHP_ME(Nc_Data_Pivot, add, arginfo_nc_data_pivot_add, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, remove, arginfo_nc_data_pivot_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, has, arginfo_nc_data_pivot_has, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, addObjects, arginfo_nc_data_pivot_addobjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, removeObjects, arginfo_nc_data_pivot_removeobjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, hasObjects, arginfo_nc_data_pivot_hasobjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, getObjects, arginfo_nc_data_pivot_getobjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, countObjects, arginfo_nc_data_pivot_countobjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, countAndGetObjects, arginfo_nc_data_pivot_countandgetobjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, addSubjects, arginfo_nc_data_pivot_addsubjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, removeSubjects, arginfo_nc_data_pivot_removesubjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, hasSubjects, arginfo_nc_data_pivot_hassubjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, getSubjects, arginfo_nc_data_pivot_getsubjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, countSubjects, arginfo_nc_data_pivot_countsubjects, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Data_Pivot, countAndGetSubjects, arginfo_nc_data_pivot_countandgetsubjects, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
