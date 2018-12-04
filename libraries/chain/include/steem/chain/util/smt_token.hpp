#pragma once

#ifdef CreateCoin_ENABLE_SMT

#include <fc/optional.hpp>
#include <CreateCoin/chain/database.hpp>
#include <CreateCoin/chain/smt_objects/smt_token_object.hpp>
#include <CreateCoin/protocol/asset_symbol.hpp>

namespace CreateCoin { namespace chain { namespace util { namespace smt {

const smt_token_object* find_token( const database& db, uint32_t nai );
const smt_token_object* find_token( const database& db, asset_symbol_type symbol, bool precision_agnostic = false );
fc::optional< time_point_sec > last_emission_time( const database& db, const asset_symbol_type& symbol );

} } } } // CreateCoin::chain::util::smt

#endif
