#pragma once

#include <CreateCoin/protocol/types.hpp>
#include <CreateCoin/protocol/transaction.hpp>
#include <CreateCoin/protocol/block_header.hpp>

#include <CreateCoin/plugins/json_rpc/utility.hpp>
#include <CreateCoin/plugins/transaction_status/transaction_status_objects.hpp>

namespace CreateCoin { namespace plugins { namespace transaction_status_api {

struct find_transaction_args
{
   chain::transaction_id_type transaction_id;
   fc::optional< fc::time_point_sec > expiration;
};

struct find_transaction_return
{
   transaction_status::transaction_status status;
   fc::optional< uint32_t > block_num;
};

} } } // CreateCoin::transaction_status_api

FC_REFLECT( CreateCoin::plugins::transaction_status_api::find_transaction_args, (transaction_id)(expiration) )
FC_REFLECT( CreateCoin::plugins::transaction_status_api::find_transaction_return, (status)(block_num) )
