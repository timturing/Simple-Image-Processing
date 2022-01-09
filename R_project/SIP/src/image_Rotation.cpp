#include <RcppArmadillo.h>
#include <cmath>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
arma::mat image_Rotation(arma::mat img,int angle){
  int row_size = img.n_rows;
  int col_size = img.n_cols;
  mat result = zeros<mat>(col_size,row_size);
  for(int i=0;i<row_size;i++){
    for(int j=0;j<col_size;j++){
      result(j,row_size-1-i) = img(i,j);
    }
  }
  if(angle==90) return result;
  if(angle==180) return image_Rotation(result,90);
  if(angle==270) return image_Rotation(image_Rotation(result,90),90);
  if(angle==360) return img;
}
