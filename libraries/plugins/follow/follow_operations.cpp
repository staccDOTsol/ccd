#include <CreateCoin/plugins/follow/follow_operations.hpp>

#include <CreateCoin/protocol/operation_util_impl.hpp>

namespace CreateCoin { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //CreateCoin::plugins::follow

CreateCoin_DEFINE_OPERATION_TYPE( CreateCoin::plugins::follow::follow_plugin_operation )
