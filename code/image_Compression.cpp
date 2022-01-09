#include <RcppArmadillo.h>
#include <cmath>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
arma::mat image_Compression(arma::mat img,int num){
  arma::mat result = zeros<arma::mat>(size(img));
  
  arma::mat U;
  arma::vec sigma;
  arma::mat V;
  svd_econ(U,sigma,V,img);
  
  for(int i=0;i<num;i++){
    result += U.col(i) * V.col(i).t() * sigma(i);
  }
  
  result( find(result<0) ).zeros();
  result( find(result>1) ).ones();
  
  return result;
}