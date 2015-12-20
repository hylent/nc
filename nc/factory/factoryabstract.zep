namespace Nc\Factory;

abstract class FactoryAbstract implements FactoryInterface
{
    protected productions;

    public function __get(string name)
    {
        var production;

        if fetch production, this->productions[name] {
            return production;
        }

        let production = this->newProduction(name);
        let this->productions[name] = production;

        return production;
    }

}
