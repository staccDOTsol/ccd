#pragma once
#include <CreateCoin/chain/database.hpp>
#include <CreateCoin/protocol/asset_symbol.hpp>

#ifdef CreateCoin_ENABLE_SMT

namespace CreateCoin { namespace chain {

   void replenish_nai_pool( database& db );
   void remove_from_nai_pool( database &db, const asset_symbol_type& a );

} } // CreateCoin::chain

#endif
