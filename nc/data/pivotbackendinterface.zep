namespace Nc\Data;

interface PivotBackendInterface
{
    public function addPivot(string identifier, string subj, string obj, long score) -> void;
    public function removePivot(string identifier, string subj, string obj) -> void;
    public function hasPivot(string identifier, string subj, string obj) -> bool;
    public function addObjectsPivot(string identifier, string subj, array objScores) -> void;
    public function removeObjectsPivot(string identifier, string subj, array objs) -> void;
    public function hasObjectsPivot(string identifier, string subj, array objs) -> array;
    public function getObjectsPivot(string identifier, string subj) -> array;
    public function countObjectsPivot(string identifier, string subj) -> long;
    public function countAndGetObjectsPivot(string identifier, string subj, bool asc, long limit, long skip) -> array;
    public function addSubjectsPivot(string identifier, array subjScores, string obj) -> void;
    public function removeSubjectsPivot(string identifier, array subjs, string obj) -> void;
    public function hasSubjectsPivot(string identifier, array subjs, string obj) -> array;
    public function getSubjectsPivot(string identifier, string obj) -> array;
    public function countSubjectsPivot(string identifier, string obj) -> long;
    public function countAndGetSubjectsPivot(string identifier, string obj, bool asc, long limit, long skip) -> array;

}
