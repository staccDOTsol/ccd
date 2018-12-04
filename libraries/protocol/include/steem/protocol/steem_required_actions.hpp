#pragma once
#include <CreateCoin/protocol/types.hpp>
#include <CreateCoin/protocol/base.hpp>

namespace CreateCoin { namespace protocol {

#ifdef IS_TEST_NET
   struct example_required_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }

      friend bool operator==( const example_required_action& lhs, const example_required_action& rhs );
   };
#endif

} } // CreateCoin::protocol

#ifdef IS_TEST_NET
FC_REFLECT( CreateCoin::protocol::example_required_action, (account) )
#endif
