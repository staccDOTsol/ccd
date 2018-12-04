#pragma once

#include <CreateCoin/protocol/CreateCoin_operations.hpp>

#include <CreateCoin/chain/evaluator.hpp>

namespace CreateCoin { namespace chain {

using namespace CreateCoin::protocol;

CreateCoin_DEFINE_EVALUATOR( account_create )
CreateCoin_DEFINE_EVALUATOR( account_create_with_delegation )
CreateCoin_DEFINE_EVALUATOR( account_update )
CreateCoin_DEFINE_EVALUATOR( transfer )
CreateCoin_DEFINE_EVALUATOR( transfer_to_vesting )
CreateCoin_DEFINE_EVALUATOR( witness_update )
CreateCoin_DEFINE_EVALUATOR( account_witness_vote )
CreateCoin_DEFINE_EVALUATOR( account_witness_proxy )
CreateCoin_DEFINE_EVALUATOR( withdraw_vesting )
CreateCoin_DEFINE_EVALUATOR( set_withdraw_vesting_route )
CreateCoin_DEFINE_EVALUATOR( comment )
CreateCoin_DEFINE_EVALUATOR( comment_options )
CreateCoin_DEFINE_EVALUATOR( delete_comment )
CreateCoin_DEFINE_EVALUATOR( vote )
CreateCoin_DEFINE_EVALUATOR( custom )
CreateCoin_DEFINE_EVALUATOR( custom_json )
CreateCoin_DEFINE_EVALUATOR( custom_binary )
CreateCoin_DEFINE_EVALUATOR( pow )
CreateCoin_DEFINE_EVALUATOR( pow2 )
CreateCoin_DEFINE_EVALUATOR( feed_publish )
CreateCoin_DEFINE_EVALUATOR( convert )
CreateCoin_DEFINE_EVALUATOR( limit_order_create )
CreateCoin_DEFINE_EVALUATOR( limit_order_cancel )
CreateCoin_DEFINE_EVALUATOR( report_over_production )
CreateCoin_DEFINE_EVALUATOR( limit_order_create2 )
CreateCoin_DEFINE_EVALUATOR( escrow_transfer )
CreateCoin_DEFINE_EVALUATOR( escrow_approve )
CreateCoin_DEFINE_EVALUATOR( escrow_dispute )
CreateCoin_DEFINE_EVALUATOR( escrow_release )
CreateCoin_DEFINE_EVALUATOR( claim_account )
CreateCoin_DEFINE_EVALUATOR( create_claimed_account )
CreateCoin_DEFINE_EVALUATOR( request_account_recovery )
CreateCoin_DEFINE_EVALUATOR( recover_account )
CreateCoin_DEFINE_EVALUATOR( change_recovery_account )
CreateCoin_DEFINE_EVALUATOR( transfer_to_savings )
CreateCoin_DEFINE_EVALUATOR( transfer_from_savings )
CreateCoin_DEFINE_EVALUATOR( cancel_transfer_from_savings )
CreateCoin_DEFINE_EVALUATOR( decline_voting_rights )
CreateCoin_DEFINE_EVALUATOR( reset_account )
CreateCoin_DEFINE_EVALUATOR( set_reset_account )
CreateCoin_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef CreateCoin_ENABLE_SMT
CreateCoin_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
CreateCoin_DEFINE_EVALUATOR( delegate_vesting_shares )
CreateCoin_DEFINE_EVALUATOR( witness_set_properties )
#ifdef CreateCoin_ENABLE_SMT
CreateCoin_DEFINE_EVALUATOR( smt_setup )
CreateCoin_DEFINE_EVALUATOR( smt_cap_reveal )
CreateCoin_DEFINE_EVALUATOR( smt_refund )
CreateCoin_DEFINE_EVALUATOR( smt_setup_emissions )
CreateCoin_DEFINE_EVALUATOR( smt_set_setup_parameters )
CreateCoin_DEFINE_EVALUATOR( smt_set_runtime_parameters )
CreateCoin_DEFINE_EVALUATOR( smt_create )
#endif

} } // CreateCoin::chain
