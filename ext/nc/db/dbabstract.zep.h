
extern zend_class_entry *nc_db_dbabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Db_DbAbstract);

PHP_METHOD(Nc_Db_DbAbstract, profiledQuery);
PHP_METHOD(Nc_Db_DbAbstract, getQueries);
PHP_METHOD(Nc_Db_DbAbstract, query);
PHP_METHOD(Nc_Db_DbAbstract, queryAll);
PHP_METHOD(Nc_Db_DbAbstract, queryRow);
PHP_METHOD(Nc_Db_DbAbstract, queryCell);
PHP_METHOD(Nc_Db_DbAbstract, queryColumns);
PHP_METHOD(Nc_Db_DbAbstract, inTransaction);
PHP_METHOD(Nc_Db_DbAbstract, begin);
PHP_METHOD(Nc_Db_DbAbstract, commit);
PHP_METHOD(Nc_Db_DbAbstract, rollback);
PHP_METHOD(Nc_Db_DbAbstract, savepoint);
PHP_METHOD(Nc_Db_DbAbstract, releaseSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, releaseLastSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, rollbackToSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, rollbackToLastSavepoint);
PHP_METHOD(Nc_Db_DbAbstract, insert);
PHP_METHOD(Nc_Db_DbAbstract, delete);
PHP_METHOD(Nc_Db_DbAbstract, update);
PHP_METHOD(Nc_Db_DbAbstract, upsert);
PHP_METHOD(Nc_Db_DbAbstract, parseSelect);
PHP_METHOD(Nc_Db_DbAbstract, select);
PHP_METHOD(Nc_Db_DbAbstract, selectRow);
PHP_METHOD(Nc_Db_DbAbstract, selectCell);
PHP_METHOD(Nc_Db_DbAbstract, selectColumns);
PHP_METHOD(Nc_Db_DbAbstract, countAndSelect);
PHP_METHOD(Nc_Db_DbAbstract, selectUnionAll);
PHP_METHOD(Nc_Db_DbAbstract, countAndSelectUnionAll);
PHP_METHOD(Nc_Db_DbAbstract, count);
PHP_METHOD(Nc_Db_DbAbstract, max);
PHP_METHOD(Nc_Db_DbAbstract, min);
PHP_METHOD(Nc_Db_DbAbstract, sum);
PHP_METHOD(Nc_Db_DbAbstract, avg);
PHP_METHOD(Nc_Db_DbAbstract, aggregation);
PHP_METHOD(Nc_Db_DbAbstract, aggregations);
PHP_METHOD(Nc_Db_DbAbstract, groupAggregations);
PHP_METHOD(Nc_Db_DbAbstract, parseWhere);
PHP_METHOD(Nc_Db_DbAbstract, parseWhereMultipleIn);
PHP_METHOD(Nc_Db_DbAbstract, parsePagination);
PHP_METHOD(Nc_Db_DbAbstract, parseRandomOrder);
PHP_METHOD(Nc_Db_DbAbstract, tryToBegin);
PHP_METHOD(Nc_Db_DbAbstract, tryToCommit);
PHP_METHOD(Nc_Db_DbAbstract, tryToRollback);
PHP_METHOD(Nc_Db_DbAbstract, nextFlag);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_profiledquery, 0, 0, 3)
	ZEND_ARG_INFO(0, q)
	ZEND_ARG_ARRAY_INFO(0, p, 0)
	ZEND_ARG_INFO(0, t)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_queryall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_queryrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_querycell, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_querycolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_savepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_rollbacktosavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_update, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_upsert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_parseselect, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_select, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_INFO(0, fetch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_selectrow, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_selectcell, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_selectcolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_countandselect, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_INFO(0, fetch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_selectunionall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, selects, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_INFO(0, fetch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_countandselectunionall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, selects, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_INFO(0, fetch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_count, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_max, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_min, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_sum, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_avg, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_aggregation, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, aggregationFunction)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_aggregations, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, aggregations, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_groupaggregations, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, groupBy)
	ZEND_ARG_ARRAY_INFO(0, aggregations, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_parsewhere, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, where, 0)
	ZEND_ARG_INFO(0, sep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_parsewheremultiplein, 0, 0, 2)
	ZEND_ARG_INFO(0, columns)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, isNot)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_parsepagination, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_db_dbabstract_nextflag, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_db_dbabstract_method_entry) {
	PHP_ME(Nc_Db_DbAbstract, profiledQuery, arginfo_nc_db_dbabstract_profiledquery, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Db_DbAbstract, getQueries, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, query, arginfo_nc_db_dbabstract_query, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, queryAll, arginfo_nc_db_dbabstract_queryall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, queryRow, arginfo_nc_db_dbabstract_queryrow, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, queryCell, arginfo_nc_db_dbabstract_querycell, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, queryColumns, arginfo_nc_db_dbabstract_querycolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, savepoint, arginfo_nc_db_dbabstract_savepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, releaseSavepoint, arginfo_nc_db_dbabstract_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, releaseLastSavepoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, rollbackToSavepoint, arginfo_nc_db_dbabstract_rollbacktosavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, rollbackToLastSavepoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, insert, arginfo_nc_db_dbabstract_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, delete, arginfo_nc_db_dbabstract_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, update, arginfo_nc_db_dbabstract_update, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, upsert, arginfo_nc_db_dbabstract_upsert, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, parseSelect, arginfo_nc_db_dbabstract_parseselect, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, select, arginfo_nc_db_dbabstract_select, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, selectRow, arginfo_nc_db_dbabstract_selectrow, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, selectCell, arginfo_nc_db_dbabstract_selectcell, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, selectColumns, arginfo_nc_db_dbabstract_selectcolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, countAndSelect, arginfo_nc_db_dbabstract_countandselect, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, selectUnionAll, arginfo_nc_db_dbabstract_selectunionall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, countAndSelectUnionAll, arginfo_nc_db_dbabstract_countandselectunionall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, count, arginfo_nc_db_dbabstract_count, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, max, arginfo_nc_db_dbabstract_max, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, min, arginfo_nc_db_dbabstract_min, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, sum, arginfo_nc_db_dbabstract_sum, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, avg, arginfo_nc_db_dbabstract_avg, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, aggregation, arginfo_nc_db_dbabstract_aggregation, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, aggregations, arginfo_nc_db_dbabstract_aggregations, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, groupAggregations, arginfo_nc_db_dbabstract_groupaggregations, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, parseWhere, arginfo_nc_db_dbabstract_parsewhere, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, parseWhereMultipleIn, arginfo_nc_db_dbabstract_parsewheremultiplein, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, parsePagination, arginfo_nc_db_dbabstract_parsepagination, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, parseRandomOrder, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Db_DbAbstract, tryToBegin, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, tryToCommit, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, tryToRollback, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Db_DbAbstract, nextFlag, arginfo_nc_db_dbabstract_nextflag, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
