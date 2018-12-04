#pragma once
#include <CreateCoin/protocol/block_header.hpp>
#include <CreateCoin/protocol/transaction.hpp>

namespace CreateCoin { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // CreateCoin::protocol

FC_REFLECT_DERIVED( CreateCoin::protocol::signed_block, (CreateCoin::protocol::signed_block_header), (transactions) )
