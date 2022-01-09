#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
arma::mat simpleEncryption(arma::mat source,arma::mat mask,double percent=0.5)
{
  mask.resize(size(source));
  return percent*mask+(1-percent)*source;
}

// [[Rcpp::export]]
arma::mat simpleDecryption(arma::mat img,arma::mat mask,double percent)
{
  mask.resize(size(img));
  arma::mat or_img=(img-percent*mask)/(1-percent);
  int ro=img.n_rows,co=img.n_cols;
  for(int i=0;i<ro;i++)
  {
    for(int j=0;j<co;j++)
    {
      if(or_img(i,j)>1)
      {
        or_img(i,j)=1;
      }
      if(or_img(i,j)<0)
      {
        or_img(i,j)=0;
      }
    }
  }
  return or_img;
}