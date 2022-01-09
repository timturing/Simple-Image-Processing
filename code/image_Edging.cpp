#include <RcppArmadillo.h>
#include <cmath>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

int mirrorIndex(int fetchI, int length){
  if(fetchI < 0)
    fetchI = -fetchI - 1;
  if(fetchI >= length){
    fetchI = length - (fetchI - length) - 1;
  }
  return fetchI;
}

//  [[Rcpp::export]]
arma::mat image_Edging(arma::mat img){
  arma::mat kernel(3,3);
  kernel = { {-1,-1,-1},{-1,8,-1},{-1,-1,-1} };
  int row_size = img.n_rows, col_size = img.n_cols;
  int i,j,p,q;
  arma::mat result ( row_size,col_size );
  double s;
  int fetchI_x,fetchI_y;
  for( i=1;i<row_size-1;i++ ){
    for( j=1;j<col_size-1;j++ ){
      s = 0;
      for( p=-1;p<=1;p++ ){
        for( q=-1;q<=1;q++ ){
          fetchI_x = i + p;
          fetchI_y = j + q;
          fetchI_x = mirrorIndex( fetchI_x,row_size );
          fetchI_y = mirrorIndex( fetchI_y,col_size );
          s += img( fetchI_x,fetchI_y ) * kernel( p+1,q+1 );
        }
      }
      if( s<0 ) s=0;
      if( s>1 ) s=1;
      result (i,j) = s;
    }
  }
  return result;
}