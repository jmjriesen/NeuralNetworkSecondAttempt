#ifndef HEBB_h
#define HEBB_h
#include <vector>
#include <armadillo>

class Hebb{
public:
  Hebb(std::vector<std::pair<arma::vec,arma::vec>>);
  arma::Col<double> run(arma::Col<double> const&);
  void train();
  std::vector< std::pair <arma::vec,arma::vec> > inputs;

  arma::mat waits;
  arma::Col<double> bies;
};
#endif
