namespace Nc\Data;

class Pivot extends DataAbstract
{
    public function add(string subj, string obj, long score) -> void
    {
        this->backend->addPivot(this->identifier, subj, obj, score);
    }

    public function remove(string subj, string obj) -> void
    {
        this->backend->removePivot(this->identifier, subj, obj);
    }

    public function has(string subj, string obj) -> bool
    {
        return this->backend->hasPivot(this->identifier, subj, obj);
    }

    public function addObjects(string subj, array objScores) -> void
    {
        this->backend->addObjectsPivot(this->identifier, subj, objScores);
    }

    public function removeObjects(string subj, array objs) -> void
    {
        this->backend->removeObjectsPivot(this->identifier, subj, objs);
    }

    public function hasObjects(string subj, array objs) -> array
    {
        return this->backend->hasObjectsPivot(this->identifier, subj, objs);
    }

    public function getObjects(string subj) -> array
    {
        return this->backend->getObjectsPivot(this->identifier, subj);
    }

    public function countObjects(string subj) -> long
    {
        return this->backend->countObjectsPivot(this->identifier, subj);
    }

    public function countAndGetObjects(string subj, bool asc = false, long limit = 50, long skip = 0) -> array
    {
        return this->backend->countAndGetObjectsPivot(this->identifier, subj, asc, limit, skip);
    }

    public function addSubjects(array subjScores, string obj) -> void
    {
        this->backend->addSubjectsPivot(this->identifier, subjScores, obj);
    }

    public function removeSubjects(array subjs, string obj) -> void
    {
        this->backend->removeSubjectsPivot(this->identifier, subjs, obj);
    }

    public function hasSubjects(array subjs, string obj) -> array
    {
        return this->backend->hasSubjectsPivot(this->identifier, subjs, obj);
    }

    public function getSubjects(string obj) -> array
    {
        return this->backend->getSubjectsPivot(this->identifier, obj);
    }

    public function countSubjects(string obj) -> long
    {
        return this->backend->countSubjectsPivot(this->identifier, obj);
    }

    public function countAndGetSubjects(string obj, bool asc = false, long limit = 50, long skip = 0) -> array
    {
        return this->backend->countAndGetSubjectsPivot(this->identifier, obj, asc, limit, skip);
    }

}
