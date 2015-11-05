/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
 *                            K.U. Leuven. All rights reserved.
 *    Copyright (C) 2011-2014 Greg Horn
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef CASADI_OLD_COLLOCATION_IVPSOL_HPP
#define CASADI_OLD_COLLOCATION_IVPSOL_HPP

#include "casadi/core/function/ivpsol.hpp"
#include "casadi/core/misc/integration_tools.hpp"
#include <casadi/solvers/casadi_ivpsol_oldcollocation_export.h>

/** \defgroup plugin_Ivpsol_oldcollocation

     Collocation integrator
     ODE/DAE integrator based on collocation

     The method is still under development

*/
/** \pluginsection{Ivpsol,oldcollocation} */

/// \cond INTERNAL
namespace casadi {

  /**
     \brief \pluginbrief{Ivpsol,oldcollocation}

     @copydoc DAE_doc
     @copydoc plugin_Ivpsol_oldcollocation

     \author Joel Andersson
     \date 2011
  */
  class CASADI_IVPSOL_OLDCOLLOCATION_EXPORT
  OldCollocationIvpsol : public Ivpsol {

  public:

    /// Constructor
    explicit OldCollocationIvpsol(const std::string& name, const XProblem& dae);

    /** \brief  Create a new integrator */
    static Ivpsol* creator(const std::string& name, const XProblem& dae) {
      return new OldCollocationIvpsol(name, dae);
    }

    /// Destructor
    virtual ~OldCollocationIvpsol();

    // Get name of the plugin
    virtual const char* plugin_name() const { return "oldcollocation";}

    /// Initialize stage
    virtual void init();

    /// Reset the forward problem and bring the time back to t0
    virtual void reset(const double** arg, double** res, int* iw, double* w);

    /// Reset the backward problem and take time to tf
    virtual void resetB() {}

    /** \brief  Advance solution in time */
    virtual void advance(int k);

    /** \brief  Retreat solution in time */
    virtual void retreat(int k);

    // Startup integrator (generates an initial trajectory guess)
    Function startup_integrator_;

    // Implicit function solver
    Function implicit_solver_;

    // With hotstart
    bool hotstart_;

    // Has the system been integrated once
    bool integrated_once_;

    // Collocated times
    std::vector<std::vector<double> > coll_time_;

    /// A documentation string
    static const std::string meta_doc;

  };

} // namespace casadi
/// \endcond
#endif // CASADI_OLD_COLLOCATION_IVPSOL_HPP
