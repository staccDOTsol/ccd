
#pragma once

#include <CreateCoin/protocol/base.hpp>
#include <CreateCoin/protocol/block_header.hpp>
#include <CreateCoin/protocol/asset.hpp>

#include <fc/utf8.hpp>

namespace CreateCoin { namespace protocol {

inline bool is_asset_type( asset asset, asset_symbol_type symbol )
{
   return asset.symbol == symbol;
}

inline void validate_account_name( const string& name )
{
   FC_ASSERT( is_valid_account_name( name ), "Account name ${n} is invalid", ("n", name) );
}

inline void validate_permlink( const string& permlink )
{
   FC_ASSERT( permlink.size() < CreateCoin_MAX_PERMLINK_LENGTH, "permlink is too long" );
   FC_ASSERT( fc::is_utf8( permlink ), "permlink not formatted in UTF8" );
}

} }
