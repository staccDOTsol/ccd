#pragma once

#include <fc/time.hpp>

#include <CreateCoin/chain/database.hpp>

namespace CreateCoin { namespace plugins { namespace chain {
   
class abstract_block_producer {
public:
   virtual ~abstract_block_producer() = default;

   virtual CreateCoin::chain::signed_block generate_block(
      fc::time_point_sec when,
      const CreateCoin::chain::account_name_type& witness_owner,
      const fc::ecc::private_key& block_signing_private_key,
      uint32_t skip = CreateCoin::chain::database::skip_nothing) = 0;
};

} } } // CreateCoin::plugins::chain
