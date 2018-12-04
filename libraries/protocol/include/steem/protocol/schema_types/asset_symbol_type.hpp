
#pragma once

#include <CreateCoin/schema/abstract_schema.hpp>
#include <CreateCoin/schema/schema_impl.hpp>

#include <CreateCoin/protocol/asset_symbol.hpp>

namespace CreateCoin { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   CreateCoin_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< CreateCoin::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
