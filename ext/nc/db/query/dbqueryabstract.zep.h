
extern zend_class_entry *nc_db_query_dbqueryabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Db_Query_DbQueryAbstract);

PHP_METHOD(Nc_Db_Query_DbQueryAbstract, __construct);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getDb);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getTable);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getTableAlias);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, duplicate);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clear);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, find);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, findMany);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, delete);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, insert);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, expression);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, increment);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, decrement);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, concat);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearUpdates);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, update);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, replace);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, aggregate);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, count);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, sum);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, max);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, min);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupAggregate);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupCount);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupSum);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupMax);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupMin);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getSelectAsString);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, select);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, selectRow);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, selectOne);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, selectColumn);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, selectAndCount);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, join);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, innerJoin);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, leftJoin);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearJoin);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, field);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearField);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, where);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, raw);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, eq);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, neq);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, gt);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, gte);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, lt);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, lte);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, between);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, in);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, notIn);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, inSelect);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, notInSelect);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, like);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, notLike);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, isNull);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, isNotNull);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, setAnd);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, setOr);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearWhere);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getWhere);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, groupBy);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearGroupBy);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, having);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearHaving);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, orderBy);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, orderByRand);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearOrderBy);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, paginate);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, top);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, clearPagination);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, setNumRows);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getPage);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getPageSize);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getRowOffset);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getNumRows);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, getNumPages);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, parseTableAlias);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildField);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildTableAndJoin);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildWhere);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildGroupBy);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildHaving);
PHP_METHOD(Nc_Db_Query_DbQueryAbstract, buildOrderBy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, db, Nc\\Db\\DbInterface, 0)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, tableAlias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_find, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_findmany, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_expression, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, deta)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_decrement, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, deta)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_concat, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_update, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_aggregate, 0, 0, 2)
	ZEND_ARG_INFO(0, aggregateFunction)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_count, 0, 0, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_sum, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_max, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_min, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_groupaggregate, 0, 0, 3)
	ZEND_ARG_INFO(0, aggregateFunction)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_groupcount, 0, 0, 1)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_groupsum, 0, 0, 2)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_groupmax, 0, 0, 2)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_groupmin, 0, 0, 2)
	ZEND_ARG_INFO(0, groupField)
	ZEND_ARG_INFO(0, aggregateField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_join, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, on)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_innerjoin, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_leftjoin, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_field, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, overwrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_where, 0, 0, 1)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_raw, 0, 0, 1)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_eq, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_neq, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_gt, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_gte, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_lt, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_lte, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_between, 0, 0, 3)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, v1)
	ZEND_ARG_INFO(0, v2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_in, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
	ZEND_ARG_INFO(0, notIn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_notin, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_inselect, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, select)
	ZEND_ARG_INFO(0, notInSelect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_notinselect, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, select)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_like, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, notLike)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_notlike, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_isnull, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, isNotNull)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_isnotnull, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, overwrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, asc)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_paginate, 0, 0, 0)
	ZEND_ARG_INFO(0, page)
	ZEND_ARG_INFO(0, pageSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_top, 0, 0, 0)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_setnumrows, 0, 0, 1)
	ZEND_ARG_INFO(0, numRows)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_query_dbqueryabstract_parsetablealias, 0, 0, 1)
	ZEND_ARG_INFO(0, s)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_query_dbqueryabstract_method_entry) {
	PHP_ME(Nc_Db_Query_DbQueryAbstract, __construct, arginfo_nc_db_query_dbqueryabstract___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getTable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getTableAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, duplicate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, find, arginfo_nc_db_query_dbqueryabstract_find, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, findMany, arginfo_nc_db_query_dbqueryabstract_findmany, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, insert, arginfo_nc_db_query_dbqueryabstract_insert, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, expression, arginfo_nc_db_query_dbqueryabstract_expression, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, increment, arginfo_nc_db_query_dbqueryabstract_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, decrement, arginfo_nc_db_query_dbqueryabstract_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, concat, arginfo_nc_db_query_dbqueryabstract_concat, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clearUpdates, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, update, arginfo_nc_db_query_dbqueryabstract_update, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, replace, arginfo_nc_db_query_dbqueryabstract_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, aggregate, arginfo_nc_db_query_dbqueryabstract_aggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, count, arginfo_nc_db_query_dbqueryabstract_count, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, sum, arginfo_nc_db_query_dbqueryabstract_sum, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, max, arginfo_nc_db_query_dbqueryabstract_max, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, min, arginfo_nc_db_query_dbqueryabstract_min, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, groupAggregate, arginfo_nc_db_query_dbqueryabstract_groupaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, groupCount, arginfo_nc_db_query_dbqueryabstract_groupcount, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, groupSum, arginfo_nc_db_query_dbqueryabstract_groupsum, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, groupMax, arginfo_nc_db_query_dbqueryabstract_groupmax, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, groupMin, arginfo_nc_db_query_dbqueryabstract_groupmin, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getSelectAsString, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, select, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, selectRow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, selectOne, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, selectColumn, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, selectAndCount, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, join, arginfo_nc_db_query_dbqueryabstract_join, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, innerJoin, arginfo_nc_db_query_dbqueryabstract_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, leftJoin, arginfo_nc_db_query_dbqueryabstract_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clearJoin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, field, arginfo_nc_db_query_dbqueryabstract_field, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clearField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, where, arginfo_nc_db_query_dbqueryabstract_where, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, raw, arginfo_nc_db_query_dbqueryabstract_raw, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, eq, arginfo_nc_db_query_dbqueryabstract_eq, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, neq, arginfo_nc_db_query_dbqueryabstract_neq, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, gt, arginfo_nc_db_query_dbqueryabstract_gt, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, gte, arginfo_nc_db_query_dbqueryabstract_gte, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, lt, arginfo_nc_db_query_dbqueryabstract_lt, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, lte, arginfo_nc_db_query_dbqueryabstract_lte, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, between, arginfo_nc_db_query_dbqueryabstract_between, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, in, arginfo_nc_db_query_dbqueryabstract_in, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, notIn, arginfo_nc_db_query_dbqueryabstract_notin, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, inSelect, arginfo_nc_db_query_dbqueryabstract_inselect, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, notInSelect, arginfo_nc_db_query_dbqueryabstract_notinselect, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, like, arginfo_nc_db_query_dbqueryabstract_like, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, notLike, arginfo_nc_db_query_dbqueryabstract_notlike, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, isNull, arginfo_nc_db_query_dbqueryabstract_isnull, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, isNotNull, arginfo_nc_db_query_dbqueryabstract_isnotnull, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, setAnd, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, setOr, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clearWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, groupBy, arginfo_nc_db_query_dbqueryabstract_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clearGroupBy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, having, arginfo_nc_db_query_dbqueryabstract_having, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clearHaving, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, orderBy, arginfo_nc_db_query_dbqueryabstract_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, orderByRand, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clearOrderBy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, paginate, arginfo_nc_db_query_dbqueryabstract_paginate, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, top, arginfo_nc_db_query_dbqueryabstract_top, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, clearPagination, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, setNumRows, arginfo_nc_db_query_dbqueryabstract_setnumrows, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getPageSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getRowOffset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getNumRows, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, getNumPages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, parseTableAlias, arginfo_nc_db_query_dbqueryabstract_parsetablealias, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, buildField, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, buildTableAndJoin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, buildWhere, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, buildGroupBy, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, buildHaving, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_Query_DbQueryAbstract, buildOrderBy, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
