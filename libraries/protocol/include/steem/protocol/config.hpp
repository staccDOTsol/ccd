/*
 * Copyright (c) 2016 CreateCoinit, Inc., and contributors.
 */
#pragma once
#include <CreateCoin/protocol/hardfork.hpp>

// WARNING!
// Every symbol defined here needs to be handled appropriately in get_config.cpp
// This is checked by get_config_check.sh called from Dockerfile

#ifdef IS_TEST_NET
#define CreateCoin_BLOCKCHAIN_VERSION              ( version(0, 21, 0) )

#define CreateCoin_INIT_PRIVATE_KEY                "5Jj8pyzebYBPe3rtD71f8fE44HLPgZ4oVNX8iwNKbGxSzwpdax6"
#define CreateCoin_INIT_PUBLIC_KEY_STR             (std::string( CreateCoin::protocol::public_key_type(CreateCoin_INIT_PRIVATE_KEY.get_public_key()) ))
#define CreateCoin_CHAIN_ID (fc::sha256::hash("createcoin"))
#define CreateCoin_ADDRESS_PREFIX                  "CC"

#define CreateCoin_GENESIS_TIME                    (fc::time_point_sec(1543884283))
#define CreateCoin_MINING_TIME                     (fc::time_point_sec(1543884283))
#define CreateCoin_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define CreateCoin_CASHOUT_WINDOW_SECONDS_PRE_HF12 (CreateCoin_CASHOUT_WINDOW_SECONDS)
#define CreateCoin_CASHOUT_WINDOW_SECONDS_PRE_HF17 (CreateCoin_CASHOUT_WINDOW_SECONDS)
#define CreateCoin_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define CreateCoin_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define CreateCoin_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define CreateCoin_UPVOTE_LOCKOUT_SECONDS          (60*5)    /// 5 minutes
#define CreateCoin_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define CreateCoin_MIN_ACCOUNT_CREATION_FEE          0
#define CreateCoin_MAX_ACCOUNT_CREATION_FEE          int64_t(1000000000)

#define CreateCoin_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define CreateCoin_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define CreateCoin_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define CreateCoin_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#define CreateCoin_INIT_SUPPLY                     (int64_t( 250 ) * int64_t( 1000000 ) * int64_t( 1000 ))

/// Allows to limit number of total produced blocks.
#define TESTNET_BLOCK_LIMIT                   (3000000)

#else // IS LIVE CreateCoin NETWORK

#define CreateCoin_BLOCKCHAIN_VERSION              ( version(0, 20, 6) )

#define CreateCoin_INIT_PUBLIC_KEY_STR             "CC8GC13uCZbP44HzMLV6zPZGwVQ8Nt4Kji8PapsPiNq1BK153XTX"
#define CreateCoin_CHAIN_ID fc::sha256()
#define CreateCoin_ADDRESS_PREFIX                  "CC"

#define CreateCoin_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define CreateCoin_MINING_TIME                     (fc::time_point_sec(1458838800))
#define CreateCoin_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24)    /// 1 day
#define CreateCoin_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*12)    /// 12 hours
#define CreateCoin_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define CreateCoin_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define CreateCoin_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define CreateCoin_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define CreateCoin_UPVOTE_LOCKOUT_SECONDS          (60*60*12)    /// 12 hours
#define CreateCoin_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define CreateCoin_MIN_ACCOUNT_CREATION_FEE           1
#define CreateCoin_MAX_ACCOUNT_CREATION_FEE           int64_t(1000000000)

#define CreateCoin_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define CreateCoin_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define CreateCoin_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define CreateCoin_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 3186477

#define CreateCoin_INIT_SUPPLY                     int64_t(0)

#endif

#define VESTS_SYMBOL  (CreateCoin::protocol::asset_symbol_type::from_asset_num( CreateCoin_ASSET_NUM_VESTS ) )
#define CreateCoin_SYMBOL  (CreateCoin::protocol::asset_symbol_type::from_asset_num( CreateCoin_ASSET_NUM_CreateCoin ) )
#define SBD_SYMBOL    (CreateCoin::protocol::asset_symbol_type::from_asset_num( CreateCoin_ASSET_NUM_SBD ) )

#define CreateCoin_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( CreateCoin_BLOCKCHAIN_VERSION ) )

#define CreateCoin_BLOCK_INTERVAL                  3
#define CreateCoin_BLOCKS_PER_YEAR                 (365*24*60*60/CreateCoin_BLOCK_INTERVAL)
#define CreateCoin_BLOCKS_PER_DAY                  (24*60*60/CreateCoin_BLOCK_INTERVAL)
#define CreateCoin_START_VESTING_BLOCK             (CreateCoin_BLOCKS_PER_DAY * 7)
#define CreateCoin_START_MINER_VOTING_BLOCK        (CreateCoin_BLOCKS_PER_DAY * 30)

#define CreateCoin_INIT_MINER_NAME                 "initminer"
#define CreateCoin_NUM_INIT_MINERS                 1
#define CreateCoin_INIT_TIME                       (fc::time_point_sec());

#define CreateCoin_MAX_WITNESSES                   21

#define CreateCoin_MAX_VOTED_WITNESSES_HF0         19
#define CreateCoin_MAX_MINER_WITNESSES_HF0         1
#define CreateCoin_MAX_RUNNER_WITNESSES_HF0        1

#define CreateCoin_MAX_VOTED_WITNESSES_HF17        20
#define CreateCoin_MAX_MINER_WITNESSES_HF17        0
#define CreateCoin_MAX_RUNNER_WITNESSES_HF17       1

#define CreateCoin_HARDFORK_REQUIRED_WITNESSES     1 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define CreateCoin_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define CreateCoin_MAX_MEMO_SIZE                   2048
#define CreateCoin_MAX_PROXY_RECURSION_DEPTH       4
#define CreateCoin_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define CreateCoin_VESTING_WITHDRAW_INTERVALS      13
#define CreateCoin_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define CreateCoin_MAX_WITHDRAW_ROUTES             10
#define CreateCoin_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define CreateCoin_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define CreateCoin_VOTING_MANA_REGENERATION_SECONDS (5*60*60*24) // 5 day
#define CreateCoin_MAX_VOTE_CHANGES                5
#define CreateCoin_REVERSE_AUCTION_WINDOW_SECONDS_HF6 (60*30) /// 30 minutes
#define CreateCoin_REVERSE_AUCTION_WINDOW_SECONDS_HF20 (60*15) /// 15 minutes
#define CreateCoin_MIN_VOTE_INTERVAL_SEC           3
#define CreateCoin_VOTE_DUST_THRESHOLD             (50000000)

#define CreateCoin_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define CreateCoin_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define CreateCoin_MIN_REPLY_INTERVAL_HF20         (fc::seconds(3)) // 3 seconds
#define CreateCoin_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define CreateCoin_POST_WEIGHT_CONSTANT            (uint64_t(4*CreateCoin_100_PERCENT) * (4*CreateCoin_100_PERCENT))// (4*CreateCoin_100_PERCENT) -> 2 posts per 1 days, average 1 every 12 hours

#define CreateCoin_MAX_ACCOUNT_WITNESS_VOTES       30

#define CreateCoin_100_PERCENT                     10000
#define CreateCoin_1_PERCENT                       (CreateCoin_100_PERCENT/100)
#define CreateCoin_DEFAULT_SBD_INTEREST_RATE       (10*CreateCoin_1_PERCENT) ///< 10% APR

#define CreateCoin_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define CreateCoin_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define CreateCoin_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define CreateCoin_CONTENT_REWARD_PERCENT          (75*CreateCoin_1_PERCENT) //75% of inflation, 7.125% inflation
#define CreateCoin_VESTING_FUND_PERCENT            (15*CreateCoin_1_PERCENT) //15% of inflation, 1.425% inflation

#define CreateCoin_MINER_PAY_PERCENT               (CreateCoin_1_PERCENT) // 1%
#define CreateCoin_MAX_RATION_DECAY_RATE           (1000000)

#define CreateCoin_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define CreateCoin_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define CreateCoin_MAX_COMMENT_DEPTH_PRE_HF17      6
#define CreateCoin_MAX_COMMENT_DEPTH               0xffff // 64k
#define CreateCoin_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define CreateCoin_MAX_RESERVE_RATIO               (20000)

#define CreateCoin_CREATE_ACCOUNT_WITH_CreateCoin_MODIFIER 30
#define CreateCoin_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define CreateCoin_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define CreateCoin_MINING_REWARD                   asset( 1000, CreateCoin_SYMBOL )
#define CreateCoin_EQUIHASH_N                      140
#define CreateCoin_EQUIHASH_K                      6

#define CreateCoin_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define CreateCoin_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define CreateCoin_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define CreateCoin_LIQUIDITY_REWARD_BLOCKS         (CreateCoin_LIQUIDITY_REWARD_PERIOD_SEC/CreateCoin_BLOCK_INTERVAL)
#define CreateCoin_MIN_LIQUIDITY_REWARD            (asset( 1000*CreateCoin_LIQUIDITY_REWARD_BLOCKS, CreateCoin_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define CreateCoin_MIN_CONTENT_REWARD              CreateCoin_MINING_REWARD
#define CreateCoin_MIN_CURATE_REWARD               CreateCoin_MINING_REWARD
#define CreateCoin_MIN_PRODUCER_REWARD             CreateCoin_MINING_REWARD
#define CreateCoin_MIN_POW_REWARD                  CreateCoin_MINING_REWARD

#define CreateCoin_ACTIVE_CHALLENGE_FEE            asset( 2000, CreateCoin_SYMBOL )
#define CreateCoin_OWNER_CHALLENGE_FEE             asset( 30000, CreateCoin_SYMBOL )
#define CreateCoin_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define CreateCoin_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define CreateCoin_POST_REWARD_FUND_NAME           ("post")
#define CreateCoin_COMMENT_REWARD_FUND_NAME        ("comment")
#define CreateCoin_RECENT_RSHARES_DECAY_TIME_HF17    (fc::days(30))
#define CreateCoin_RECENT_RSHARES_DECAY_TIME_HF19    (fc::days(15))
#define CreateCoin_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**CreateCoin_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define CreateCoin_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that CreateCoin_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define CreateCoin_APR_PERCENT_SHIFT_PER_BLOCK             87

#define CreateCoin_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define CreateCoin_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**CreateCoin_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define CreateCoin_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that CreateCoin_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define CreateCoin_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
#define CreateCoin_CURATE_APR_PERCENT              3875
#define CreateCoin_CONTENT_APR_PERCENT             3875
#define CreateCoin_LIQUIDITY_APR_PERCENT            750
#define CreateCoin_PRODUCER_APR_PERCENT             750
#define CreateCoin_POW_APR_PERCENT                  750

#define CreateCoin_MIN_PAYOUT_SBD                  (asset(20,SBD_SYMBOL))

#define CreateCoin_SBD_STOP_PERCENT_HF14           (5*CreateCoin_1_PERCENT ) // Stop printing SBD at 5% Market Cap
#define CreateCoin_SBD_STOP_PERCENT_HF20           (10*CreateCoin_1_PERCENT ) // Stop printing SBD at 10% Market Cap
#define CreateCoin_SBD_START_PERCENT_HF14          (2*CreateCoin_1_PERCENT) // Start reducing printing of SBD at 2% Market Cap
#define CreateCoin_SBD_START_PERCENT_HF20          (9*CreateCoin_1_PERCENT) // Start reducing printing of SBD at 9% Market Cap

#define CreateCoin_MIN_ACCOUNT_NAME_LENGTH          3
#define CreateCoin_MAX_ACCOUNT_NAME_LENGTH         16

#define CreateCoin_MIN_PERMLINK_LENGTH             0
#define CreateCoin_MAX_PERMLINK_LENGTH             256
#define CreateCoin_MAX_WITNESS_URL_LENGTH          2048

#define CreateCoin_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define CreateCoin_MAX_SATOSHIS                    int64_t(4611686018427387903ll)
#define CreateCoin_MAX_SIG_CHECK_DEPTH             2
#define CreateCoin_MAX_SIG_CHECK_ACCOUNTS          125

#define CreateCoin_MIN_TRANSACTION_SIZE_LIMIT      1024
#define CreateCoin_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define CreateCoin_SBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define CreateCoin_MAX_TRANSACTION_SIZE            (1024*64)
#define CreateCoin_MIN_BLOCK_SIZE_LIMIT            (CreateCoin_MAX_TRANSACTION_SIZE)
#define CreateCoin_MAX_BLOCK_SIZE                  (CreateCoin_MAX_TRANSACTION_SIZE*CreateCoin_BLOCK_INTERVAL*2000)
#define CreateCoin_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define CreateCoin_MIN_BLOCK_SIZE                  115
#define CreateCoin_BLOCKS_PER_HOUR                 (60*60/CreateCoin_BLOCK_INTERVAL)
#define CreateCoin_FEED_INTERVAL_BLOCKS            (CreateCoin_BLOCKS_PER_HOUR)
#define CreateCoin_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define CreateCoin_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define CreateCoin_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define CreateCoin_MIN_FEEDS                       (CreateCoin_MAX_WITNESSES/3) /// protects the network from conversions before price has been established
#define CreateCoin_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define CreateCoin_CONVERSION_DELAY                (fc::hours(CreateCoin_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define CreateCoin_MIN_UNDO_HISTORY                10
#define CreateCoin_MAX_UNDO_HISTORY                10000

#define CreateCoin_MIN_TRANSACTION_EXPIRATION_LIMIT (CreateCoin_BLOCK_INTERVAL * 5) // 5 transactions per block
#define CreateCoin_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define CreateCoin_BLOCKCHAIN_PRECISION_DIGITS     3
#define CreateCoin_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define CreateCoin_MAX_AUTHORITY_MEMBERSHIP        40
#define CreateCoin_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define CreateCoin_MAX_URL_LENGTH                  127

#define CreateCoin_IRREVERSIBLE_THRESHOLD          (75 * CreateCoin_1_PERCENT)

#define CreateCoin_VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define CreateCoin_VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

#define CreateCoin_INITIAL_VOTE_POWER_RATE (40)
#define CreateCoin_REDUCED_VOTE_POWER_RATE (10)

#define CreateCoin_MAX_LIMIT_ORDER_EXPIRATION     (60*60*24*28) // 28 days
#define CreateCoin_DELEGATION_RETURN_PERIOD_HF0   (CreateCoin_CASHOUT_WINDOW_SECONDS)
#define CreateCoin_DELEGATION_RETURN_PERIOD_HF20  (CreateCoin_VOTING_MANA_REGENERATION_SECONDS)

#define CreateCoin_RD_MIN_DECAY_BITS               6
#define CreateCoin_RD_MAX_DECAY_BITS              32
#define CreateCoin_RD_DECAY_DENOM_SHIFT           36
#define CreateCoin_RD_MAX_POOL_BITS               64
#define CreateCoin_RD_MAX_BUDGET_1                ((uint64_t(1) << (CreateCoin_RD_MAX_POOL_BITS + CreateCoin_RD_MIN_DECAY_BITS - CreateCoin_RD_DECAY_DENOM_SHIFT))-1)
#define CreateCoin_RD_MAX_BUDGET_2                ((uint64_t(1) << (64-CreateCoin_RD_DECAY_DENOM_SHIFT))-1)
#define CreateCoin_RD_MAX_BUDGET_3                (uint64_t( std::numeric_limits<int32_t>::max() ))
#define CreateCoin_RD_MAX_BUDGET                  (int32_t( std::min( { CreateCoin_RD_MAX_BUDGET_1, CreateCoin_RD_MAX_BUDGET_2, CreateCoin_RD_MAX_BUDGET_3 } )) )
#define CreateCoin_RD_MIN_DECAY                   (uint32_t(1) << CreateCoin_RD_MIN_DECAY_BITS)
#define CreateCoin_RD_MIN_BUDGET                  1
#define CreateCoin_RD_MAX_DECAY                   (uint32_t(0xFFFFFFFF))

#define CreateCoin_ACCOUNT_SUBSIDY_PRECISION      (CreateCoin_100_PERCENT)

// We want the global subsidy to run out first in normal (Poisson)
// conditions, so we boost the per-witness subsidy a little.
#define CreateCoin_WITNESS_SUBSIDY_BUDGET_PERCENT (125 * CreateCoin_1_PERCENT)

// Since witness decay only procs once per round, multiplying the decay
// constant by the number of witnesses means the per-witness pools have
// the same effective decay rate in real-time terms.
#define CreateCoin_WITNESS_SUBSIDY_DECAY_PERCENT  (CreateCoin_MAX_WITNESSES * CreateCoin_100_PERCENT)

// 347321 corresponds to a 5-day halflife
#define CreateCoin_DEFAULT_ACCOUNT_SUBSIDY_DECAY  (347321)
// Default rate is 0.5 accounts per block
#define CreateCoin_DEFAULT_ACCOUNT_SUBSIDY_BUDGET (797)
#define CreateCoin_DECAY_BACKSTOP_PERCENT         (90 * CreateCoin_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define CreateCoin_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define CreateCoin_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define CreateCoin_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define CreateCoin_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define CreateCoin_ROOT_POST_PARENT                (account_name_type())
///@}

#ifdef CreateCoin_ENABLE_SMT

#define SMT_MAX_VOTABLE_ASSETS 2
#define SMT_VESTING_WITHDRAW_INTERVAL_SECONDS   (60*60*24*7) /// 1 week per interval
#define SMT_UPVOTE_LOCKOUT                      (60*60*12)   /// 12 hours
#define SMT_EMISSION_MIN_INTERVAL_SECONDS       (60*60*6)    /// 6 hours
#define SMT_EMIT_INDEFINITELY                   (std::numeric_limits<uint32_t>::max())
#define SMT_MAX_NOMINAL_VOTES_PER_DAY           (1000)
#define SMT_MAX_VOTES_PER_REGENERATION          ((SMT_MAX_NOMINAL_VOTES_PER_DAY * SMT_VESTING_WITHDRAW_INTERVAL_SECONDS) / 86400)
#define SMT_DEFAULT_VOTES_PER_REGEN_PERIOD      (50)
#define SMT_DEFAULT_PERCENT_CURATION_REWARDS    (25 * CreateCoin_1_PERCENT)

#endif /// CreateCoin_ENABLE_SMT

