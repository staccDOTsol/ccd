#pragma once
#include <CreateCoin/plugins/block_api/block_api_objects.hpp>

#include <CreateCoin/protocol/types.hpp>
#include <CreateCoin/protocol/transaction.hpp>
#include <CreateCoin/protocol/block_header.hpp>

#include <CreateCoin/plugins/json_rpc/utility.hpp>

namespace CreateCoin { namespace plugins { namespace block_api {

/* get_block_header */

struct get_block_header_args
{
   uint32_t block_num;
};

struct get_block_header_return
{
   optional< block_header > header;
};

/* get_block */
struct get_block_args
{
   uint32_t block_num;
};

struct get_block_return
{
   optional< api_signed_block_object > block;
};

} } } // CreateCoin::block_api

FC_REFLECT( CreateCoin::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( CreateCoin::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( CreateCoin::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( CreateCoin::plugins::block_api::get_block_return,
   (block) )

