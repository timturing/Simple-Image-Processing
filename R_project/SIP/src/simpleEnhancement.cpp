#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

#include<iostream>
bool check(double k,double b)
{
  if(b<0||b>1)return false;
  if(k+b<0||k+b>1)return false;
  return true;
}

// [[Rcpp::export]]
arma::mat simpleEnhancement(arma::mat img,double k=0.5,double b=0.5)
{
  int nrows = img.n_rows;
  int ncols = img.n_cols;
  for(int i=0;i<nrows;i++)
  for(int j=0;j<ncols;j++)
  {
    img(i,j)=k*img(i,j)+b;
    if(img(i,j)>1)img(i,j)=1;
    if(img(i,j)<0)img(i,j)=0;
  }
  return img;
}