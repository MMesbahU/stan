#ifndef STAN__MCMC__DENSE__E__STATIC__HMC__BETA
#define STAN__MCMC__DENSE__E__STATIC__HMC__BETA

#include <stan/mcmc/hmc/static/base_static_hmc.hpp>
#include <stan/mcmc/hmc/hamiltonians/dense_e_point.hpp>
#include <stan/mcmc/hmc/hamiltonians/dense_e_metric.hpp>
#include <stan/mcmc/hmc/integrators/expl_leapfrog.hpp>

namespace stan {

  namespace mcmc {

    // Hamiltonian Monte Carlo on a
    // Euclidean manifold with dense metric
    // and static integration time
    template <class M, class BaseRNG, class Writer>
    class dense_e_static_hmc
      : public base_static_hmc<M, dense_e_metric,
                               expl_leapfrog, BaseRNG, Writer> {
    public:
      dense_e_static_hmc(M &m, BaseRNG& rng, Writer& writer)
        : base_static_hmc<M, dense_e_metric,
                          expl_leapfrog, BaseRNG, Writer>(m, rng, writer) {
        this->name_ = "Static HMC with a dense Euclidean metric";
      }
    };

  }  // mcmc

}  // stan

#endif
