#pragma once

#include <CreateCoin/protocol/CreateCoin_optional_actions.hpp>

#include <CreateCoin/protocol/operation_util.hpp>

namespace CreateCoin { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
#ifdef IS_TEST_NET
            example_optional_action
#endif
         > optional_automated_action;

} } // CreateCoin::protocol

CreateCoin_DECLARE_OPERATION_TYPE( CreateCoin::protocol::optional_automated_action );

FC_TODO( "Remove ifdef when first optional automated action is added" )
#ifdef IS_TEST_NET
FC_REFLECT_TYPENAME( CreateCoin::protocol::optional_automated_action );
#endif