#include <CreateCoin/protocol/validation.hpp>
#include <CreateCoin/protocol/CreateCoin_optional_actions.hpp>

namespace CreateCoin { namespace protocol {

#ifdef IS_TEST_NET
void example_optional_action::validate()const
{
   validate_account_name( account );
}
#endif

} } //CreateCoin::protocol
