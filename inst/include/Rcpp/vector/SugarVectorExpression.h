#ifndef Rcpp__vector__SugarVectorExpression_h
#define Rcpp__vector__SugarVectorExpression_h

namespace Rcpp{
         
    template <int RTYPE, bool NA, typename VECTOR>
    struct SugarVectorExpression : 
        public VectorBase<RTYPE, NA, VECTOR>, 
        public SugarVectorExpressionBase
    {
        using VectorBase<RTYPE, NA, VECTOR>::get_ref ;
        
        template <typename Target>
        void apply( Target& target ) const {
            // get_ref().apply(target) ;
            
            // TODO: need better than this
            int n = get_ref().size() ;
            for(int i=0; i<n; i++){
                target[i] = get_ref()[i] ;    
            }
        }
    
    } ;
    
}

#endif