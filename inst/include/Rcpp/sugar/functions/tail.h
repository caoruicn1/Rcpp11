#ifndef Rcpp__sugar__tail_h
#define Rcpp__sugar__tail_h

namespace Rcpp{
namespace sugar{

template <int RTYPE, bool NA, typename T>
class Tail : 
    public SugarVectorExpression< RTYPE ,NA, Tail<RTYPE,NA,T> >, 
    public custom_sugar_vector_expression {
public:
    typedef typename Rcpp::SugarVectorExpression<RTYPE,NA,T> VEC_TYPE ;
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE ;

    Tail( const VEC_TYPE& object_, R_xlen_t n_ ) : object(object_), start(0), n(n_) {
        if( n > 0 ){
            start = object.size() - n ;
        } else {
            start = -n ;
            n = object.size() - start ;
        }
    }

    inline STORAGE operator[]( R_xlen_t i ) const {
        return object[ start + i ] ;
    }
    inline R_xlen_t size() const { return n; }

    template <typename Target>
    inline void apply( Target& target ) const {
        std::copy_n( sugar_begin(object) + start, n, target.begin() ) ; 
    }
    
private:
    const VEC_TYPE& object ;
    R_xlen_t start, n ;
} ;

} // sugar

template <int RTYPE,bool NA, typename T>
inline sugar::Tail<RTYPE,NA,T> tail( 
    const SugarVectorExpression<RTYPE,NA,T>& t, 
    int n 
    ){
    return sugar::Tail<RTYPE,NA,T>( t, n ) ;
}

} // Rcpp
#endif

