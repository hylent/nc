<?php

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilationContext;
use Zephir\CompilerException;
use Zephir\CompiledExpression;
use Zephir\Optimizers\OptimizerAbstract;

class NcUtilsCrc16Optimizer extends OptimizerAbstract
{
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters'])) {
            return false;
        }

        if (count($expression['parameters']) != 1) {
            throw new CompilerException("nc_utils_crc16 only accepts one parameter", $expression);
        }

        $call->processExpectedReturn($context);

        $symbolVariable = $call->getSymbolVariable();
        if ($symbolVariable->getType() != 'variable') {
            throw new CompilerException("Returned values by functions can only be assigned to variant variables", $expression);
        }

        if ($call->mustInitSymbolVariable()) {
            $symbolVariable->initVariant($context);
        }

        $context->headersManager->add('optimizers/utils');
        $symbolVariable->setDynamicTypes('string');

        $resolvedParams = $call->getResolvedParams($expression['parameters'], $context, $expression);
        $context->codePrinter->output('nc_utils_crc16(' . $symbolVariable->getName() . ', ' . $resolvedParams[0] . ');');

        return new CompiledExpression('variable', $symbolVariable->getRealName(), $expression);
    }
}
