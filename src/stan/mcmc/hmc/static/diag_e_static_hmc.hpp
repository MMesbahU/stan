#ifndef STAN__MCMC__DIAG__E__STATIC__HMC__BETA
#define STAN__MCMC__DIAG__E__STATIC__HMC__BETA

#include <stan/mcmc/hmc/static/base_static_hmc.hpp>
#include <stan/mcmc/hmc/hamiltonians/diag_e_point.hpp>
#include <stan/mcmc/hmc/hamiltonians/diag_e_metric.hpp>
#include <stan/mcmc/hmc/integrators/expl_leapfrog.hpp>

namespace stan {

  namespace mcmc {

    // Hamiltonian Monte Carlo on a
    // Euclidean manifold with diagonal metric
    // and static integration time
    template <class M, class BaseRNG, class Writer>
    class diag_e_static_hmc
      : public base_static_hmc<M, diag_e_metric, expl_leapfrog, BaseRNG, Writer> {
    public:
      diag_e_static_hmc(M &m, BaseRNG& rng, Writer& writer)
        : base_static_hmc<M, diag_e_metric, expl_leapfrog,
                          BaseRNG, Writer>(m, rng, writer) {
        this->name_ = "Static HMC with a diagonal Euclidean metric";
      }
    };

  }  // mcmc

}  // stan

#endif
