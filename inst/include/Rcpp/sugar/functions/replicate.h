#ifndef Rcpp__sugar__replicate_h
#define Rcpp__sugar__replicate_h

namespace Rcpp{
    namespace sugar{
    
        template <typename OUT, typename CallType >
        class Replicate : 
            public SugarVectorExpression< Rcpp::traits::r_sexptype_traits<OUT>::rtype , true, Replicate<OUT,CallType> >, 
            public custom_sugar_vector_expression {
        public:
            Replicate( R_xlen_t n_, CallType call_ ): n(n_), call(call_) {}
            
            inline OUT operator[]( R_xlen_t i ) const {
                return call() ;
            }
            inline R_xlen_t size() const { return n ; }
            
            template <typename Target>
            inline void apply( Target& target ) const {
                std::generate_n( target.begin(), n, call ) ;  
            }
            
        private:
            size_t n ;
            CallType call ; 
        } ;
    
    
    } // sugar
    
    template <typename CallType>
    inline sugar::Replicate<typename std::result_of<CallType()>::type, CallType> 
    replicate( R_xlen_t n, CallType call){
        return sugar::Replicate<typename std::result_of<CallType()>::type, CallType>( n, call ) ;    
    }



} // Rcpp
#endif

