#pragma once

#include <fc/container/flat.hpp>
#include <CreateCoin/protocol/operations.hpp>
#include <CreateCoin/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace CreateCoin { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const CreateCoin::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const CreateCoin::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // CreateCoin::app
