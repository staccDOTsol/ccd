#pragma once

#include <CreateCoin/protocol/CreateCoin_optional_actions.hpp>

#include <CreateCoin/chain/evaluator.hpp>

namespace CreateCoin { namespace chain {

using namespace CreateCoin::protocol;

#ifdef IS_TEST_NET
CreateCoin_DEFINE_ACTION_EVALUATOR( example_optional, optional_automated_action )
#endif

} } //CreateCoin::chain
