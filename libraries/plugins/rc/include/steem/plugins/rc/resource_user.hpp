#pragma once

#include <CreateCoin/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace CreateCoin { namespace protocol {
struct signed_transaction;
} } // CreateCoin::protocol

namespace CreateCoin { namespace plugins { namespace rc {

using CreateCoin::protocol::account_name_type;
using CreateCoin::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // CreateCoin::plugins::rc
