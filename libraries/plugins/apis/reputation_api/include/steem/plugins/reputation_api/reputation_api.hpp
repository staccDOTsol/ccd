#pragma once
#include <CreateCoin/plugins/json_rpc/utility.hpp>
#include <CreateCoin/plugins/reputation/reputation_objects.hpp>
#include <CreateCoin/plugins/database_api/database_api_objects.hpp>

#include <CreateCoin/protocol/types.hpp>

#include <fc/optional.hpp>
#include <fc/variant.hpp>
#include <fc/vector.hpp>

namespace CreateCoin { namespace plugins { namespace reputation {

using CreateCoin::protocol::account_name_type;

namespace detail
{
   class reputation_api_impl;
}

struct account_reputation
{
   account_name_type             account;
   CreateCoin::protocol::share_type   reputation;
};

struct get_account_reputations_args
{
   account_name_type account_lower_bound;
   uint32_t          limit = 1000;
};

struct get_account_reputations_return
{
   vector< account_reputation > reputations;
};

class reputation_api
{
   public:
      reputation_api();
      ~reputation_api();

      DECLARE_API(
         (get_account_reputations)
      )

   private:
      std::unique_ptr< detail::reputation_api_impl > my;
};

} } } // CreateCoin::plugins::reputation

FC_REFLECT( CreateCoin::plugins::reputation::account_reputation,
            (account)(reputation) );

FC_REFLECT( CreateCoin::plugins::reputation::get_account_reputations_args,
            (account_lower_bound)(limit) );

FC_REFLECT( CreateCoin::plugins::reputation::get_account_reputations_return,
            (reputations) );
