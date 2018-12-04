#pragma once

#include <CreateCoin/protocol/block.hpp>

namespace CreateCoin { namespace chain {

struct transaction_notification
{
   transaction_notification( const CreateCoin::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   CreateCoin::protocol::transaction_id_type          transaction_id;
   const CreateCoin::protocol::signed_transaction&    transaction;
};

} }
