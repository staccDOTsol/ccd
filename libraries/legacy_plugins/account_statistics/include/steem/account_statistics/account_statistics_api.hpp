#pragma once

#include <CreateCoin/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace CreateCoin { namespace app {
   struct api_context;
} }

namespace CreateCoin { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const CreateCoin::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // CreateCoin::account_statistics

FC_API( CreateCoin::account_statistics::account_statistics_api, )