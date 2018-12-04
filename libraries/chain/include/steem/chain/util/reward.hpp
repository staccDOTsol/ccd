#pragma once

#include <CreateCoin/chain/util/asset.hpp>
#include <CreateCoin/chain/CreateCoin_objects.hpp>

#include <CreateCoin/protocol/asset.hpp>
#include <CreateCoin/protocol/config.hpp>
#include <CreateCoin/protocol/types.hpp>
#include <CreateCoin/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace CreateCoin { namespace chain { namespace util {

using CreateCoin::protocol::asset;
using CreateCoin::protocol::price;
using CreateCoin::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_sbd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_CreateCoin;
   price      current_CreateCoin_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = CreateCoin_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return CreateCoin_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = CreateCoin_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t CreateCoin_payout )
{
   return to_sbd( p, asset( CreateCoin_payout, CreateCoin_SYMBOL ) ) < CreateCoin_MIN_PAYOUT_SBD;
}

} } } // CreateCoin::chain::util

FC_REFLECT( CreateCoin::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_sbd)
   (total_reward_shares2)
   (total_reward_fund_CreateCoin)
   (current_CreateCoin_price)
   (reward_curve)
   (content_constant)
   )
