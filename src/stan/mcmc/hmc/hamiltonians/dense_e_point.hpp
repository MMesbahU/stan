#ifndef STAN__MCMC__DENSE__E__POINT__BETA
#define STAN__MCMC__DENSE__E__POINT__BETA

#include <stan/mcmc/hmc/hamiltonians/ps_point.hpp>

namespace stan {

  namespace mcmc {

    // Point in a phase space with a base
    // Euclidean manifold with dense metric
    class dense_e_point: public ps_point {
    public:
      explicit dense_e_point(int n)
        : ps_point(n), mInv(n, n) {
        mInv.setIdentity();
      }

      Eigen::MatrixXd mInv;

      dense_e_point(const dense_e_point& z)
        : ps_point(z), mInv(z.mInv.rows(), z.mInv.cols()) {
        fast_matrix_copy_<double>(mInv, z.mInv);
      }

      template <class Writer>
      void write_metric(Writer& writer) {
        writer("# Elements of inverse mass matrix:");
        writer("M_inv", mInv.data(), mInv.rows(), mInv.cols());
      }
    };

  }  // mcmc

}  // stan

#endif
