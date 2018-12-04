#pragma once
#include <CreateCoin/protocol/exceptions.hpp>
#include <CreateCoin/protocol/operations.hpp>

namespace CreateCoin { namespace chain {

class database;

template< typename OperationType=CreateCoin::protocol::operation >
class evaluator
{
   public:
      virtual ~evaluator() {}

      virtual void apply(const OperationType& op) = 0;
      virtual int get_type()const = 0;
      virtual std::string get_name( const OperationType& op ) = 0;
};

template< typename EvaluatorType, typename OperationType=CreateCoin::protocol::operation >
class evaluator_impl : public evaluator<OperationType>
{
   public:
      typedef OperationType operation_sv_type;
      // typedef typename EvaluatorType::operation_type op_type;

      evaluator_impl( database& d )
         : _db(d) {}

      virtual ~evaluator_impl() {}

      virtual void apply(const OperationType& o) final override
      {
         auto* eval = static_cast< EvaluatorType* >(this);
         const auto& op = o.template get< typename EvaluatorType::operation_type >();
         eval->do_apply(op);
      }

      virtual int get_type()const override { return OperationType::template tag< typename EvaluatorType::operation_type >::value; }

      virtual std::string get_name( const OperationType& o ) override
      {
         const auto& op = o.template get< typename EvaluatorType::operation_type >();

         return boost::core::demangle( typeid( op ).name() );
      }

      database& db() { return _db; }

   protected:
      database& _db;
};

} }

#define CreateCoin_DEFINE_EVALUATOR( X ) \
class X ## _evaluator : public CreateCoin::chain::evaluator_impl< X ## _evaluator > \
{                                                                           \
   public:                                                                  \
      typedef X ## _operation operation_type;                               \
                                                                            \
      X ## _evaluator( database& db )                                       \
         : CreateCoin::chain::evaluator_impl< X ## _evaluator >( db )          \
      {}                                                                    \
                                                                            \
      void do_apply( const X ## _operation& o );                            \
};

#define CreateCoin_DEFINE_ACTION_EVALUATOR( X, ACTION )                               \
class X ## _evaluator : public CreateCoin::chain::evaluator_impl< X ## _evaluator, ACTION > \
{                                                                                \
   public:                                                                       \
      typedef X ## _action operation_type;                                       \
                                                                                 \
      X ## _evaluator( database& db )                                            \
         : CreateCoin::chain::evaluator_impl< X ## _evaluator, ACTION >( db )        \
      {}                                                                         \
                                                                                 \
      void do_apply( const X ## _action& o );                                    \
};

#define CreateCoin_DEFINE_PLUGIN_EVALUATOR( PLUGIN, OPERATION, X )               \
class X ## _evaluator : public CreateCoin::chain::evaluator_impl< X ## _evaluator, OPERATION > \
{                                                                           \
   public:                                                                  \
      typedef X ## _operation operation_type;                               \
                                                                            \
      X ## _evaluator( CreateCoin::chain::database& db, PLUGIN* plugin )       \
         : CreateCoin::chain::evaluator_impl< X ## _evaluator, OPERATION >( db ), \
           _plugin( plugin )                                                \
      {}                                                                    \
                                                                            \
      void do_apply( const X ## _operation& o );                            \
                                                                            \
      PLUGIN* _plugin;                                                      \
};
