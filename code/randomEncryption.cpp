#include<RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

#include <iostream>
#include <cstdlib>
#include <ctime>
#define random(x) rand()%(x)

using namespace std;

// [[Rcpp::export]]
Rcpp::List randomEncryption(arma::mat img)
{
  srand((int)time(0));
  int nrows = img.n_rows;
  int ncols = img.n_cols;
  int total=nrows*ncols;
  // arma::mat C(nrows, ncols,fill::zeros);
  arma::Mat<int> key(total,4,fill::zeros);
  arma::mat C(nrows,ncols,fill::zeros);
  for(int i=0;i<nrows;i++)
  {
    for(int j=0;j<ncols;j++)
    {
      C(i,j)=img(i,j);
    }
  }
  for(int i=0;i<total;i++)
  {
    int m1=random(nrows);
    int n1=random(ncols);
    int m2=random(nrows);
    int n2=random(ncols); 
    if(m1==m2&&n1==n2)
    {
      i--;
      continue;
    }
    key(i,0)=m1;
    key(i,1)=n1;
    key(i,2)=m2;
    key(i,3)=n2;
    double tmp=img(m1,n1);
    img(m1,n1)=img(m2,n2);
    img(m2,n2)=tmp;
    C(m1,n1)=img(m2,n2);
    C(m2,n2)=img(m1,n1);
  }
  return Rcpp::List::create(Rcpp::Named("img") = img,
                            Rcpp::Named("key") = key);
  
}
// [[Rcpp::export]]
arma::mat randomDecryption(arma::mat img,arma::Mat<int> key)
{
  int nrows = img.n_rows;
  int ncols = img.n_cols;
  int total=nrows*ncols;
  arma::mat C(nrows,ncols,fill::zeros);
  for(int i=0;i<nrows;i++)
  {
    for(int j=0;j<ncols;j++)
    {
      C(i,j)=img(i,j);
    }
  }
  for(int i=total-1;i>=0;i--)
  {
    int m1=key(i,0);
    int n1=key(i,1);
    int m2=key(i,2);
    int n2=key(i,3);
    if(m1==m2&&n1==n2)
    {
      i--;
      continue;
    }
    double tmp=img(m1,n1);
    img(m1,n1)=img(m2,n2);
    img(m2,n2)=tmp;
    C(m1,n1)=img(m2,n2);
    C(m2,n2)=img(m1,n1);
  }
  return img;
}