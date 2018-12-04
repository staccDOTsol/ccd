#pragma once

#include <CreateCoin/chain/evaluator.hpp>

#include <CreateCoin/private_message/private_message_operations.hpp>
#include <CreateCoin/private_message/private_message_plugin.hpp>

namespace CreateCoin { namespace private_message {

CreateCoin_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, CreateCoin::private_message::private_message_plugin_operation, private_message )

} }
