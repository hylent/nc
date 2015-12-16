<?php

namespace NcApp\Action;

use NcApp\ActionBase;

class Db extends ActionBase
{
    public function __invoke()
    {
        $m = new \Nc\Db\Model($this->app->db, 'file', 'uri', '');

        print_R($m->getDb()->queryColumns('show tables'));

        if (0) {
            $c = $m->paged([], 'created_ts desc', 10, 1);
            print_R($c);
        }

    }

}
