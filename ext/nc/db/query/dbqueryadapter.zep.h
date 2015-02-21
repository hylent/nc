
extern zend_class_entry *nc_db_query_dbqueryadapter_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Query_DbQueryAdapter);

PHP_METHOD(Nc_Db_Query_DbQueryAdapter, __construct);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getDb);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getTable);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getTableAlias);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, duplicate);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clear);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, find);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, findMany);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, delete);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, insert);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, expression);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, increment);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, decrement);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, concat);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clearUpdates);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, update);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, replace);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, aggregate);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, count);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, sum);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, max);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, min);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, groupAggregate);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, groupCount);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, groupSum);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, groupMax);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, groupMin);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getSelectAsString);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, select);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, selectRow);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, selectOne);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, selectColumn);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, selectAndCount);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, join);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, innerJoin);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, leftJoin);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clearJoin);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, field);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clearField);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, where);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, raw);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, eq);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, neq);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, gt);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, gte);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, lt);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, lte);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, between);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, in);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, notIn);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, inSelect);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, notInSelect);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, like);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, notLike);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, isNull);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, isNotNull);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, setAnd);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, setOr);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clearWhere);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getWhere);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, groupBy);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clearGroupBy);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, having);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clearHaving);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, orderBy);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, orderByRand);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clearOrderBy);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, paginate);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, top);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, clearPagination);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, setNumRows);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getPage);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getPageSize);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getRowOffset);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getNumRows);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, getNumPages);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, parseTableAlias);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, buildField);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, buildTableAndJoin);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, buildWhere);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, buildGroupBy);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, buildHaving);
PHP_METHOD(Nc_Db_Query_DbQueryAdapter, buildOrderBy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, db, Nc\\Db\\DbInterface, 0)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, tableAlias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_find, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_findmany, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_expression, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, deta)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_decrement, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, deta)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_concat, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_update, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_aggregate, 0, 0, 2)
	ZEND_ARG_INFO(0, aggregateFunction)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_count, 0, 0, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_sum, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_max, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_min, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_groupaggregate, 0, 0, 3)
	ZEND_ARG_INFO(0, aggregateFunction)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_groupcount, 0, 0, 1)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_groupsum, 0, 0, 2)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_groupmax, 0, 0, 2)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_groupmin, 0, 0, 2)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_join, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, on)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_innerjoin, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_leftjoin, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_field, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, append)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_where, 0, 0, 1)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_raw, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_eq, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_neq, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_gt, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_gte, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_lt, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_lte, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_between, 0, 0, 3)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, v1)
	ZEND_ARG_INFO(0, v2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_in, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
	ZEND_ARG_INFO(0, notIn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_notin, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_inselect, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, select)
	ZEND_ARG_INFO(0, notInSelect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_notinselect, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, select)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_like, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, half)
	ZEND_ARG_INFO(0, notLike)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_notlike, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, half)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_isnull, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, isNotNull)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_isnotnull, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, append)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, asc)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_paginate, 0, 0, 0)
	ZEND_ARG_INFO(0, page)
	ZEND_ARG_INFO(0, pageSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_top, 0, 0, 0)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_setnumrows, 0, 0, 1)
	ZEND_ARG_INFO(0, numRows)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryadapter_parsetablealias, 0, 0, 1)
	ZEND_ARG_INFO(0, s)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_query_dbqueryadapter_method_entry) {
	PHP_ME(Nc_Db_Query_DbQueryAdapter, __construct, arginfo_nc_db_query_dbqueryadapter___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getTable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getTableAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, duplicate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, find, arginfo_nc_db_query_dbqueryadapter_find, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, findMany, arginfo_nc_db_query_dbqueryadapter_findmany, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, insert, arginfo_nc_db_query_dbqueryadapter_insert, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, expression, arginfo_nc_db_query_dbqueryadapter_expression, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, increment, arginfo_nc_db_query_dbqueryadapter_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, decrement, arginfo_nc_db_query_dbqueryadapter_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, concat, arginfo_nc_db_query_dbqueryadapter_concat, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clearUpdates, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, update, arginfo_nc_db_query_dbqueryadapter_update, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, replace, arginfo_nc_db_query_dbqueryadapter_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, aggregate, arginfo_nc_db_query_dbqueryadapter_aggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, count, arginfo_nc_db_query_dbqueryadapter_count, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, sum, arginfo_nc_db_query_dbqueryadapter_sum, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, max, arginfo_nc_db_query_dbqueryadapter_max, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, min, arginfo_nc_db_query_dbqueryadapter_min, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, groupAggregate, arginfo_nc_db_query_dbqueryadapter_groupaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, groupCount, arginfo_nc_db_query_dbqueryadapter_groupcount, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, groupSum, arginfo_nc_db_query_dbqueryadapter_groupsum, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, groupMax, arginfo_nc_db_query_dbqueryadapter_groupmax, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, groupMin, arginfo_nc_db_query_dbqueryadapter_groupmin, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getSelectAsString, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, select, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, selectRow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, selectOne, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, selectColumn, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, selectAndCount, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, join, arginfo_nc_db_query_dbqueryadapter_join, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, innerJoin, arginfo_nc_db_query_dbqueryadapter_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, leftJoin, arginfo_nc_db_query_dbqueryadapter_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clearJoin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, field, arginfo_nc_db_query_dbqueryadapter_field, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clearField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, where, arginfo_nc_db_query_dbqueryadapter_where, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, raw, arginfo_nc_db_query_dbqueryadapter_raw, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, eq, arginfo_nc_db_query_dbqueryadapter_eq, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, neq, arginfo_nc_db_query_dbqueryadapter_neq, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, gt, arginfo_nc_db_query_dbqueryadapter_gt, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, gte, arginfo_nc_db_query_dbqueryadapter_gte, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, lt, arginfo_nc_db_query_dbqueryadapter_lt, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, lte, arginfo_nc_db_query_dbqueryadapter_lte, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, between, arginfo_nc_db_query_dbqueryadapter_between, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, in, arginfo_nc_db_query_dbqueryadapter_in, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, notIn, arginfo_nc_db_query_dbqueryadapter_notin, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, inSelect, arginfo_nc_db_query_dbqueryadapter_inselect, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, notInSelect, arginfo_nc_db_query_dbqueryadapter_notinselect, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, like, arginfo_nc_db_query_dbqueryadapter_like, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, notLike, arginfo_nc_db_query_dbqueryadapter_notlike, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, isNull, arginfo_nc_db_query_dbqueryadapter_isnull, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, isNotNull, arginfo_nc_db_query_dbqueryadapter_isnotnull, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, setAnd, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, setOr, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clearWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, groupBy, arginfo_nc_db_query_dbqueryadapter_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clearGroupBy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, having, arginfo_nc_db_query_dbqueryadapter_having, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clearHaving, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, orderBy, arginfo_nc_db_query_dbqueryadapter_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, orderByRand, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clearOrderBy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, paginate, arginfo_nc_db_query_dbqueryadapter_paginate, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, top, arginfo_nc_db_query_dbqueryadapter_top, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, clearPagination, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, setNumRows, arginfo_nc_db_query_dbqueryadapter_setnumrows, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getPageSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getRowOffset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getNumRows, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, getNumPages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, parseTableAlias, arginfo_nc_db_query_dbqueryadapter_parsetablealias, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, buildField, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, buildTableAndJoin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, buildWhere, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, buildGroupBy, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, buildHaving, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAdapter, buildOrderBy, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
