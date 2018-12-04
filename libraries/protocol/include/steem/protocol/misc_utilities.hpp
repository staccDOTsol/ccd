#pragma once

namespace CreateCoin { namespace protocol {

enum curve_id
{
   quadratic,
   bounded_curation,
   linear,
   square_root
};

} } // CreateCoin::utilities


FC_REFLECT_ENUM(
   CreateCoin::protocol::curve_id,
   (quadratic)
   (bounded_curation)
   (linear)
   (square_root)
)
