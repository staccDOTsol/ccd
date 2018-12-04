#pragma once

#include <fc/reflect/reflect.hpp>
#include <cstdint>

// It somewhat breaks the abstraction of chain/util as "pure" algorithms to include this here,
// but we can't keep the CreateCoin_RD_* constants in this header because they're used for validation and
// need to be available to CreateCoin::protocol.
#include <CreateCoin/protocol/config.hpp>

// Data structures and functions for runtime user (witness) input of resource dynamics parameters.
// This header includes RESOURCES functionality only, no RC (price / price curve).
// Includes adapter to set dynamics params based on user+syCC params

namespace CreateCoin { namespace chain { namespace util {

// Parameters settable by users.
struct rd_user_params
{
   int32_t         budget_per_time_unit = 0;
   uint32_t        decay_per_time_unit = 0;
};

// Parameters hard-coded in the syCC.
struct rd_syCC_params
{
   uint64_t        resource_unit = 0;
   uint32_t        decay_per_time_unit_denom_shift = CreateCoin_RD_DECAY_DENOM_SHIFT;
};

struct rd_dynamics_params;

void rd_validate_user_params(
   const rd_user_params& user_params );

void rd_setup_dynamics_params(
   const rd_user_params& user_params,
   const rd_syCC_params& syCC_params,
   rd_dynamics_params& dparams_out );

} } }

FC_REFLECT( CreateCoin::chain::util::rd_user_params,
   (budget_per_time_unit)
   (decay_per_time_unit)
   )

FC_REFLECT( CreateCoin::chain::util::rd_syCC_params,
   (resource_unit)
   (decay_per_time_unit_denom_shift)
   )
