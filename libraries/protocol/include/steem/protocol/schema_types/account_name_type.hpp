
#pragma once

#include <CreateCoin/schema/abstract_schema.hpp>
#include <CreateCoin/schema/schema_impl.hpp>

#include <CreateCoin/protocol/types.hpp>

namespace CreateCoin { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   CreateCoin_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< CreateCoin::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< CreateCoin::protocol::account_name_type >
{
   static const char* name()
   {
      return "CreateCoin::protocol::account_name_type";
   }
};

}
