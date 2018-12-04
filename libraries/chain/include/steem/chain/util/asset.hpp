#pragma once

#include <CreateCoin/protocol/asset.hpp>

namespace CreateCoin { namespace chain { namespace util {

using CreateCoin::protocol::asset;
using CreateCoin::protocol::price;

inline asset to_sbd( const price& p, const asset& CreateCoin )
{
   FC_ASSERT( CreateCoin.symbol == CreateCoin_SYMBOL );
   if( p.is_null() )
      return asset( 0, SBD_SYMBOL );
   return CreateCoin * p;
}

inline asset to_CreateCoin( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == SBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, CreateCoin_SYMBOL );
   return sbd * p;
}

} } }
