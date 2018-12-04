#include <CreateCoin/protocol/get_config.hpp>
#include <CreateCoin/protocol/config.hpp>
#include <CreateCoin/protocol/asset.hpp>
#include <CreateCoin/protocol/types.hpp>
#include <CreateCoin/protocol/version.hpp>

namespace CreateCoin { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result[ "IS_TEST_NET" ] = true;
   result["TESTNET_BLOCK_LIMIT"] = TESTNET_BLOCK_LIMIT;
#else
   result[ "IS_TEST_NET" ] = false;
#endif
#ifdef CreateCoin_ENABLE_SMT
   result[ "CreateCoin_ENABLE_SMT" ] = true;
   result["SMT_MAX_VOTABLE_ASSETS"] = SMT_MAX_VOTABLE_ASSETS;
   result["SMT_VESTING_WITHDRAW_INTERVAL_SECONDS"] = SMT_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["SMT_UPVOTE_LOCKOUT"] = SMT_UPVOTE_LOCKOUT;
   result["SMT_EMISSION_MIN_INTERVAL_SECONDS"] = SMT_EMISSION_MIN_INTERVAL_SECONDS;
   result["SMT_EMIT_INDEFINITELY"] = SMT_EMIT_INDEFINITELY;
   result["SMT_MAX_NOMINAL_VOTES_PER_DAY"] = SMT_MAX_NOMINAL_VOTES_PER_DAY;
   result["SMT_MAX_VOTES_PER_REGENERATION"] = SMT_MAX_VOTES_PER_REGENERATION;
   result["SMT_DEFAULT_VOTES_PER_REGEN_PERIOD"] = SMT_DEFAULT_VOTES_PER_REGEN_PERIOD;
   result["SMT_DEFAULT_PERCENT_CURATION_REWARDS"] = SMT_DEFAULT_PERCENT_CURATION_REWARDS;
#else
   result[ "CreateCoin_ENABLE_SMT" ] = false;
#endif

   result["SBD_SYMBOL"] = SBD_SYMBOL;
   result["CreateCoin_INITIAL_VOTE_POWER_RATE"] = CreateCoin_INITIAL_VOTE_POWER_RATE;
   result["CreateCoin_REDUCED_VOTE_POWER_RATE"] = CreateCoin_REDUCED_VOTE_POWER_RATE;
   result["CreateCoin_100_PERCENT"] = CreateCoin_100_PERCENT;
   result["CreateCoin_1_PERCENT"] = CreateCoin_1_PERCENT;
   result["CreateCoin_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = CreateCoin_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
   result["CreateCoin_ACTIVE_CHALLENGE_COOLDOWN"] = CreateCoin_ACTIVE_CHALLENGE_COOLDOWN;
   result["CreateCoin_ACTIVE_CHALLENGE_FEE"] = CreateCoin_ACTIVE_CHALLENGE_FEE;
   result["CreateCoin_ADDRESS_PREFIX"] = CreateCoin_ADDRESS_PREFIX;
   result["CreateCoin_APR_PERCENT_MULTIPLY_PER_BLOCK"] = CreateCoin_APR_PERCENT_MULTIPLY_PER_BLOCK;
   result["CreateCoin_APR_PERCENT_MULTIPLY_PER_HOUR"] = CreateCoin_APR_PERCENT_MULTIPLY_PER_HOUR;
   result["CreateCoin_APR_PERCENT_MULTIPLY_PER_ROUND"] = CreateCoin_APR_PERCENT_MULTIPLY_PER_ROUND;
   result["CreateCoin_APR_PERCENT_SHIFT_PER_BLOCK"] = CreateCoin_APR_PERCENT_SHIFT_PER_BLOCK;
   result["CreateCoin_APR_PERCENT_SHIFT_PER_HOUR"] = CreateCoin_APR_PERCENT_SHIFT_PER_HOUR;
   result["CreateCoin_APR_PERCENT_SHIFT_PER_ROUND"] = CreateCoin_APR_PERCENT_SHIFT_PER_ROUND;
   result["CreateCoin_BANDWIDTH_AVERAGE_WINDOW_SECONDS"] = CreateCoin_BANDWIDTH_AVERAGE_WINDOW_SECONDS;
   result["CreateCoin_BANDWIDTH_PRECISION"] = CreateCoin_BANDWIDTH_PRECISION;
   result["CreateCoin_BLOCKCHAIN_PRECISION"] = CreateCoin_BLOCKCHAIN_PRECISION;
   result["CreateCoin_BLOCKCHAIN_PRECISION_DIGITS"] = CreateCoin_BLOCKCHAIN_PRECISION_DIGITS;
   result["CreateCoin_BLOCKCHAIN_HARDFORK_VERSION"] = CreateCoin_BLOCKCHAIN_HARDFORK_VERSION;
   result["CreateCoin_BLOCKCHAIN_VERSION"] = CreateCoin_BLOCKCHAIN_VERSION;
   result["CreateCoin_BLOCK_INTERVAL"] = CreateCoin_BLOCK_INTERVAL;
   result["CreateCoin_BLOCKS_PER_DAY"] = CreateCoin_BLOCKS_PER_DAY;
   result["CreateCoin_BLOCKS_PER_HOUR"] = CreateCoin_BLOCKS_PER_HOUR;
   result["CreateCoin_BLOCKS_PER_YEAR"] = CreateCoin_BLOCKS_PER_YEAR;
   result["CreateCoin_CASHOUT_WINDOW_SECONDS"] = CreateCoin_CASHOUT_WINDOW_SECONDS;
   result["CreateCoin_CASHOUT_WINDOW_SECONDS_PRE_HF12"] = CreateCoin_CASHOUT_WINDOW_SECONDS_PRE_HF12;
   result["CreateCoin_CASHOUT_WINDOW_SECONDS_PRE_HF17"] = CreateCoin_CASHOUT_WINDOW_SECONDS_PRE_HF17;
   result["CreateCoin_CHAIN_ID"] = CreateCoin_CHAIN_ID;
   result["CreateCoin_COMMENT_REWARD_FUND_NAME"] = CreateCoin_COMMENT_REWARD_FUND_NAME;
   result["CreateCoin_CONTENT_APR_PERCENT"] = CreateCoin_CONTENT_APR_PERCENT;
   result["CreateCoin_CONTENT_CONSTANT_HF0"] = CreateCoin_CONTENT_CONSTANT_HF0;
   result["CreateCoin_CONTENT_REWARD_PERCENT"] = CreateCoin_CONTENT_REWARD_PERCENT;
   result["CreateCoin_CONVERSION_DELAY"] = CreateCoin_CONVERSION_DELAY;
   result["CreateCoin_CONVERSION_DELAY_PRE_HF_16"] = CreateCoin_CONVERSION_DELAY_PRE_HF_16;
   result["CreateCoin_CREATE_ACCOUNT_DELEGATION_RATIO"] = CreateCoin_CREATE_ACCOUNT_DELEGATION_RATIO;
   result["CreateCoin_CREATE_ACCOUNT_DELEGATION_TIME"] = CreateCoin_CREATE_ACCOUNT_DELEGATION_TIME;
   result["CreateCoin_CREATE_ACCOUNT_WITH_CreateCoin_MODIFIER"] = CreateCoin_CREATE_ACCOUNT_WITH_CreateCoin_MODIFIER;
   result["CreateCoin_CURATE_APR_PERCENT"] = CreateCoin_CURATE_APR_PERCENT;
   result["CreateCoin_DEFAULT_SBD_INTEREST_RATE"] = CreateCoin_DEFAULT_SBD_INTEREST_RATE;
   result["CreateCoin_EQUIHASH_K"] = CreateCoin_EQUIHASH_K;
   result["CreateCoin_EQUIHASH_N"] = CreateCoin_EQUIHASH_N;
   result["CreateCoin_FEED_HISTORY_WINDOW"] = CreateCoin_FEED_HISTORY_WINDOW;
   result["CreateCoin_FEED_HISTORY_WINDOW_PRE_HF_16"] = CreateCoin_FEED_HISTORY_WINDOW_PRE_HF_16;
   result["CreateCoin_FEED_INTERVAL_BLOCKS"] = CreateCoin_FEED_INTERVAL_BLOCKS;
   result["CreateCoin_GENESIS_TIME"] = CreateCoin_GENESIS_TIME;
   result["CreateCoin_HARDFORK_REQUIRED_WITNESSES"] = CreateCoin_HARDFORK_REQUIRED_WITNESSES;
   result["CreateCoin_INFLATION_NARROWING_PERIOD"] = CreateCoin_INFLATION_NARROWING_PERIOD;
   result["CreateCoin_INFLATION_RATE_START_PERCENT"] = CreateCoin_INFLATION_RATE_START_PERCENT;
   result["CreateCoin_INFLATION_RATE_STOP_PERCENT"] = CreateCoin_INFLATION_RATE_STOP_PERCENT;
   result["CreateCoin_INIT_MINER_NAME"] = CreateCoin_INIT_MINER_NAME;
   result["CreateCoin_INIT_PUBLIC_KEY_STR"] = CreateCoin_INIT_PUBLIC_KEY_STR;
#if 0
   // do not expose private key, period.
   // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
   result["CreateCoin_INIT_PRIVATE_KEY"] = CreateCoin_INIT_PRIVATE_KEY;
#endif
   result["CreateCoin_INIT_SUPPLY"] = CreateCoin_INIT_SUPPLY;
   result["CreateCoin_INIT_TIME"] = CreateCoin_INIT_TIME;
   result["CreateCoin_IRREVERSIBLE_THRESHOLD"] = CreateCoin_IRREVERSIBLE_THRESHOLD;
   result["CreateCoin_LIQUIDITY_APR_PERCENT"] = CreateCoin_LIQUIDITY_APR_PERCENT;
   result["CreateCoin_LIQUIDITY_REWARD_BLOCKS"] = CreateCoin_LIQUIDITY_REWARD_BLOCKS;
   result["CreateCoin_LIQUIDITY_REWARD_PERIOD_SEC"] = CreateCoin_LIQUIDITY_REWARD_PERIOD_SEC;
   result["CreateCoin_LIQUIDITY_TIMEOUT_SEC"] = CreateCoin_LIQUIDITY_TIMEOUT_SEC;
   result["CreateCoin_MAX_ACCOUNT_CREATION_FEE"] = CreateCoin_MAX_ACCOUNT_CREATION_FEE;
   result["CreateCoin_MAX_ACCOUNT_NAME_LENGTH"] = CreateCoin_MAX_ACCOUNT_NAME_LENGTH;
   result["CreateCoin_MAX_ACCOUNT_WITNESS_VOTES"] = CreateCoin_MAX_ACCOUNT_WITNESS_VOTES;
   result["CreateCoin_MAX_ASSET_WHITELIST_AUTHORITIES"] = CreateCoin_MAX_ASSET_WHITELIST_AUTHORITIES;
   result["CreateCoin_MAX_AUTHORITY_MEMBERSHIP"] = CreateCoin_MAX_AUTHORITY_MEMBERSHIP;
   result["CreateCoin_MAX_BLOCK_SIZE"] = CreateCoin_MAX_BLOCK_SIZE;
   result["CreateCoin_SOFT_MAX_BLOCK_SIZE"] = CreateCoin_SOFT_MAX_BLOCK_SIZE;
   result["CreateCoin_MAX_CASHOUT_WINDOW_SECONDS"] = CreateCoin_MAX_CASHOUT_WINDOW_SECONDS;
   result["CreateCoin_MAX_COMMENT_DEPTH"] = CreateCoin_MAX_COMMENT_DEPTH;
   result["CreateCoin_MAX_COMMENT_DEPTH_PRE_HF17"] = CreateCoin_MAX_COMMENT_DEPTH_PRE_HF17;
   result["CreateCoin_MAX_FEED_AGE_SECONDS"] = CreateCoin_MAX_FEED_AGE_SECONDS;
   result["CreateCoin_MAX_INSTANCE_ID"] = CreateCoin_MAX_INSTANCE_ID;
   result["CreateCoin_MAX_MEMO_SIZE"] = CreateCoin_MAX_MEMO_SIZE;
   result["CreateCoin_MAX_WITNESSES"] = CreateCoin_MAX_WITNESSES;
   result["CreateCoin_MAX_MINER_WITNESSES_HF0"] = CreateCoin_MAX_MINER_WITNESSES_HF0;
   result["CreateCoin_MAX_MINER_WITNESSES_HF17"] = CreateCoin_MAX_MINER_WITNESSES_HF17;
   result["CreateCoin_MAX_PERMLINK_LENGTH"] = CreateCoin_MAX_PERMLINK_LENGTH;
   result["CreateCoin_MAX_PROXY_RECURSION_DEPTH"] = CreateCoin_MAX_PROXY_RECURSION_DEPTH;
   result["CreateCoin_MAX_RATION_DECAY_RATE"] = CreateCoin_MAX_RATION_DECAY_RATE;
   result["CreateCoin_MAX_RESERVE_RATIO"] = CreateCoin_MAX_RESERVE_RATIO;
   result["CreateCoin_MAX_RUNNER_WITNESSES_HF0"] = CreateCoin_MAX_RUNNER_WITNESSES_HF0;
   result["CreateCoin_MAX_RUNNER_WITNESSES_HF17"] = CreateCoin_MAX_RUNNER_WITNESSES_HF17;
   result["CreateCoin_MAX_SATOSHIS"] = CreateCoin_MAX_SATOSHIS;
   result["CreateCoin_MAX_SHARE_SUPPLY"] = CreateCoin_MAX_SHARE_SUPPLY;
   result["CreateCoin_MAX_SIG_CHECK_DEPTH"] = CreateCoin_MAX_SIG_CHECK_DEPTH;
   result["CreateCoin_MAX_SIG_CHECK_ACCOUNTS"] = CreateCoin_MAX_SIG_CHECK_ACCOUNTS;
   result["CreateCoin_MAX_TIME_UNTIL_EXPIRATION"] = CreateCoin_MAX_TIME_UNTIL_EXPIRATION;
   result["CreateCoin_MAX_TRANSACTION_SIZE"] = CreateCoin_MAX_TRANSACTION_SIZE;
   result["CreateCoin_MAX_UNDO_HISTORY"] = CreateCoin_MAX_UNDO_HISTORY;
   result["CreateCoin_MAX_URL_LENGTH"] = CreateCoin_MAX_URL_LENGTH;
   result["CreateCoin_MAX_VOTE_CHANGES"] = CreateCoin_MAX_VOTE_CHANGES;
   result["CreateCoin_MAX_VOTED_WITNESSES_HF0"] = CreateCoin_MAX_VOTED_WITNESSES_HF0;
   result["CreateCoin_MAX_VOTED_WITNESSES_HF17"] = CreateCoin_MAX_VOTED_WITNESSES_HF17;
   result["CreateCoin_MAX_WITHDRAW_ROUTES"] = CreateCoin_MAX_WITHDRAW_ROUTES;
   result["CreateCoin_MAX_WITNESS_URL_LENGTH"] = CreateCoin_MAX_WITNESS_URL_LENGTH;
   result["CreateCoin_MIN_ACCOUNT_CREATION_FEE"] = CreateCoin_MIN_ACCOUNT_CREATION_FEE;
   result["CreateCoin_MIN_ACCOUNT_NAME_LENGTH"] = CreateCoin_MIN_ACCOUNT_NAME_LENGTH;
   result["CreateCoin_MIN_BLOCK_SIZE_LIMIT"] = CreateCoin_MIN_BLOCK_SIZE_LIMIT;
   result["CreateCoin_MIN_BLOCK_SIZE"] = CreateCoin_MIN_BLOCK_SIZE;
   result["CreateCoin_MIN_CONTENT_REWARD"] = CreateCoin_MIN_CONTENT_REWARD;
   result["CreateCoin_MIN_CURATE_REWARD"] = CreateCoin_MIN_CURATE_REWARD;
   result["CreateCoin_MIN_PERMLINK_LENGTH"] = CreateCoin_MIN_PERMLINK_LENGTH;
   result["CreateCoin_MIN_REPLY_INTERVAL"] = CreateCoin_MIN_REPLY_INTERVAL;
   result["CreateCoin_MIN_REPLY_INTERVAL_HF20"] = CreateCoin_MIN_REPLY_INTERVAL_HF20;
   result["CreateCoin_MIN_ROOT_COMMENT_INTERVAL"] = CreateCoin_MIN_ROOT_COMMENT_INTERVAL;
   result["CreateCoin_MIN_VOTE_INTERVAL_SEC"] = CreateCoin_MIN_VOTE_INTERVAL_SEC;
   result["CreateCoin_MINER_ACCOUNT"] = CreateCoin_MINER_ACCOUNT;
   result["CreateCoin_MINER_PAY_PERCENT"] = CreateCoin_MINER_PAY_PERCENT;
   result["CreateCoin_MIN_FEEDS"] = CreateCoin_MIN_FEEDS;
   result["CreateCoin_MINING_REWARD"] = CreateCoin_MINING_REWARD;
   result["CreateCoin_MINING_TIME"] = CreateCoin_MINING_TIME;
   result["CreateCoin_MIN_LIQUIDITY_REWARD"] = CreateCoin_MIN_LIQUIDITY_REWARD;
   result["CreateCoin_MIN_LIQUIDITY_REWARD_PERIOD_SEC"] = CreateCoin_MIN_LIQUIDITY_REWARD_PERIOD_SEC;
   result["CreateCoin_MIN_PAYOUT_SBD"] = CreateCoin_MIN_PAYOUT_SBD;
   result["CreateCoin_MIN_POW_REWARD"] = CreateCoin_MIN_POW_REWARD;
   result["CreateCoin_MIN_PRODUCER_REWARD"] = CreateCoin_MIN_PRODUCER_REWARD;
   result["CreateCoin_MIN_TRANSACTION_EXPIRATION_LIMIT"] = CreateCoin_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result["CreateCoin_MIN_TRANSACTION_SIZE_LIMIT"] = CreateCoin_MIN_TRANSACTION_SIZE_LIMIT;
   result["CreateCoin_MIN_UNDO_HISTORY"] = CreateCoin_MIN_UNDO_HISTORY;
   result["CreateCoin_NULL_ACCOUNT"] = CreateCoin_NULL_ACCOUNT;
   result["CreateCoin_NUM_INIT_MINERS"] = CreateCoin_NUM_INIT_MINERS;
   result["CreateCoin_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM"] = CreateCoin_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM;
   result["CreateCoin_OWNER_AUTH_RECOVERY_PERIOD"] = CreateCoin_OWNER_AUTH_RECOVERY_PERIOD;
   result["CreateCoin_OWNER_CHALLENGE_COOLDOWN"] = CreateCoin_OWNER_CHALLENGE_COOLDOWN;
   result["CreateCoin_OWNER_CHALLENGE_FEE"] = CreateCoin_OWNER_CHALLENGE_FEE;
   result["CreateCoin_OWNER_UPDATE_LIMIT"] = CreateCoin_OWNER_UPDATE_LIMIT;
   result["CreateCoin_POST_AVERAGE_WINDOW"] = CreateCoin_POST_AVERAGE_WINDOW;
   result["CreateCoin_POST_REWARD_FUND_NAME"] = CreateCoin_POST_REWARD_FUND_NAME;
   result["CreateCoin_POST_WEIGHT_CONSTANT"] = CreateCoin_POST_WEIGHT_CONSTANT;
   result["CreateCoin_POW_APR_PERCENT"] = CreateCoin_POW_APR_PERCENT;
   result["CreateCoin_PRODUCER_APR_PERCENT"] = CreateCoin_PRODUCER_APR_PERCENT;
   result["CreateCoin_PROXY_TO_SELF_ACCOUNT"] = CreateCoin_PROXY_TO_SELF_ACCOUNT;
   result["CreateCoin_SBD_INTEREST_COMPOUND_INTERVAL_SEC"] = CreateCoin_SBD_INTEREST_COMPOUND_INTERVAL_SEC;
   result["CreateCoin_SECONDS_PER_YEAR"] = CreateCoin_SECONDS_PER_YEAR;
   result["CreateCoin_RECENT_RSHARES_DECAY_TIME_HF19"] = CreateCoin_RECENT_RSHARES_DECAY_TIME_HF19;
   result["CreateCoin_RECENT_RSHARES_DECAY_TIME_HF17"] = CreateCoin_RECENT_RSHARES_DECAY_TIME_HF17;
   result["CreateCoin_REVERSE_AUCTION_WINDOW_SECONDS_HF6"] = CreateCoin_REVERSE_AUCTION_WINDOW_SECONDS_HF6;
   result["CreateCoin_REVERSE_AUCTION_WINDOW_SECONDS_HF20"] = CreateCoin_REVERSE_AUCTION_WINDOW_SECONDS_HF20;
   result["CreateCoin_ROOT_POST_PARENT"] = CreateCoin_ROOT_POST_PARENT;
   result["CreateCoin_SAVINGS_WITHDRAW_REQUEST_LIMIT"] = CreateCoin_SAVINGS_WITHDRAW_REQUEST_LIMIT;
   result["CreateCoin_SAVINGS_WITHDRAW_TIME"] = CreateCoin_SAVINGS_WITHDRAW_TIME;
   result["CreateCoin_SBD_START_PERCENT_HF14"] = CreateCoin_SBD_START_PERCENT_HF14;
   result["CreateCoin_SBD_START_PERCENT_HF20"] = CreateCoin_SBD_START_PERCENT_HF20;
   result["CreateCoin_SBD_STOP_PERCENT_HF14"] = CreateCoin_SBD_STOP_PERCENT_HF14;
   result["CreateCoin_SBD_STOP_PERCENT_HF20"] = CreateCoin_SBD_STOP_PERCENT_HF20;
   result["CreateCoin_SECOND_CASHOUT_WINDOW"] = CreateCoin_SECOND_CASHOUT_WINDOW;
   result["CreateCoin_SOFT_MAX_COMMENT_DEPTH"] = CreateCoin_SOFT_MAX_COMMENT_DEPTH;
   result["CreateCoin_START_MINER_VOTING_BLOCK"] = CreateCoin_START_MINER_VOTING_BLOCK;
   result["CreateCoin_START_VESTING_BLOCK"] = CreateCoin_START_VESTING_BLOCK;
   result["CreateCoin_TEMP_ACCOUNT"] = CreateCoin_TEMP_ACCOUNT;
   result["CreateCoin_UPVOTE_LOCKOUT_HF7"] = CreateCoin_UPVOTE_LOCKOUT_HF7;
   result["CreateCoin_UPVOTE_LOCKOUT_HF17"] = CreateCoin_UPVOTE_LOCKOUT_HF17;
   result["CreateCoin_UPVOTE_LOCKOUT_SECONDS"] = CreateCoin_UPVOTE_LOCKOUT_SECONDS;
   result["CreateCoin_VESTING_FUND_PERCENT"] = CreateCoin_VESTING_FUND_PERCENT;
   result["CreateCoin_VESTING_WITHDRAW_INTERVALS"] = CreateCoin_VESTING_WITHDRAW_INTERVALS;
   result["CreateCoin_VESTING_WITHDRAW_INTERVALS_PRE_HF_16"] = CreateCoin_VESTING_WITHDRAW_INTERVALS_PRE_HF_16;
   result["CreateCoin_VESTING_WITHDRAW_INTERVAL_SECONDS"] = CreateCoin_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["CreateCoin_VOTE_DUST_THRESHOLD"] = CreateCoin_VOTE_DUST_THRESHOLD;
   result["CreateCoin_VOTING_MANA_REGENERATION_SECONDS"] = CreateCoin_VOTING_MANA_REGENERATION_SECONDS;
   result["CreateCoin_SYMBOL"] = CreateCoin_SYMBOL;
   result["VESTS_SYMBOL"] = VESTS_SYMBOL;
   result["CreateCoin_VIRTUAL_SCHEDULE_LAP_LENGTH"] = CreateCoin_VIRTUAL_SCHEDULE_LAP_LENGTH;
   result["CreateCoin_VIRTUAL_SCHEDULE_LAP_LENGTH2"] = CreateCoin_VIRTUAL_SCHEDULE_LAP_LENGTH2;
   result["CreateCoin_MAX_LIMIT_ORDER_EXPIRATION"] = CreateCoin_MAX_LIMIT_ORDER_EXPIRATION;
   result["CreateCoin_DELEGATION_RETURN_PERIOD_HF0"] = CreateCoin_DELEGATION_RETURN_PERIOD_HF0;
   result["CreateCoin_DELEGATION_RETURN_PERIOD_HF20"] = CreateCoin_DELEGATION_RETURN_PERIOD_HF20;
   result["CreateCoin_RD_MIN_DECAY_BITS"] = CreateCoin_RD_MIN_DECAY_BITS;
   result["CreateCoin_RD_MAX_DECAY_BITS"] = CreateCoin_RD_MAX_DECAY_BITS;
   result["CreateCoin_RD_DECAY_DENOM_SHIFT"] = CreateCoin_RD_DECAY_DENOM_SHIFT;
   result["CreateCoin_RD_MAX_POOL_BITS"] = CreateCoin_RD_MAX_POOL_BITS;
   result["CreateCoin_RD_MAX_BUDGET_1"] = CreateCoin_RD_MAX_BUDGET_1;
   result["CreateCoin_RD_MAX_BUDGET_2"] = CreateCoin_RD_MAX_BUDGET_2;
   result["CreateCoin_RD_MAX_BUDGET_3"] = CreateCoin_RD_MAX_BUDGET_3;
   result["CreateCoin_RD_MAX_BUDGET"] = CreateCoin_RD_MAX_BUDGET;
   result["CreateCoin_RD_MIN_DECAY"] = CreateCoin_RD_MIN_DECAY;
   result["CreateCoin_RD_MIN_BUDGET"] = CreateCoin_RD_MIN_BUDGET;
   result["CreateCoin_RD_MAX_DECAY"] = CreateCoin_RD_MAX_DECAY;
   result["CreateCoin_ACCOUNT_SUBSIDY_PRECISION"] = CreateCoin_ACCOUNT_SUBSIDY_PRECISION;
   result["CreateCoin_WITNESS_SUBSIDY_BUDGET_PERCENT"] = CreateCoin_WITNESS_SUBSIDY_BUDGET_PERCENT;
   result["CreateCoin_WITNESS_SUBSIDY_DECAY_PERCENT"] = CreateCoin_WITNESS_SUBSIDY_DECAY_PERCENT;
   result["CreateCoin_DEFAULT_ACCOUNT_SUBSIDY_DECAY"] = CreateCoin_DEFAULT_ACCOUNT_SUBSIDY_DECAY;
   result["CreateCoin_DEFAULT_ACCOUNT_SUBSIDY_BUDGET"] = CreateCoin_DEFAULT_ACCOUNT_SUBSIDY_BUDGET;
   result["CreateCoin_DECAY_BACKSTOP_PERCENT"] = CreateCoin_DECAY_BACKSTOP_PERCENT;

   return result;
}

} } // CreateCoin::protocol
