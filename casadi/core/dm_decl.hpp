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

#ifndef CASADI_DM_DECL_HPP
#define CASADI_DM_DECL_HPP

#include "im_fwd.hpp"
#include "dm_fwd.hpp"
#include "matrix_decl.hpp"

using namespace std;

namespace casadi {
 
  /**
  // Template specializations
  template<>
  CASADI_EXPORT Matrix<double> Matrix<double>::
  solve(const Matrix<double>& a, const Matrix<double>& b,
        const std::string& lsolver, const Dict& dict);

  template<>
  CASADI_EXPORT Matrix<double> Matrix<double>::
  pinv(const Matrix<double>& A, const std::string& lsolver, const Dict& dict);

  template<>
  CASADI_EXPORT Matrix<double> Matrix<double>::
  rand(const Sparsity& sp); // NOLINT(runtime/threadsafe_fn)

  template<>
  CASADI_EXPORT Matrix<double> Matrix<double>::
  expm_const(const Matrix<double>& A, const Matrix<double>& t);

  template<>
  CASADI_EXPORT Matrix<double> Matrix<double>::
  expm(const Matrix<double>& A);

  template<>
  Matrix<double> Matrix<double>::
  solve(const Matrix<double>& A, const Matrix<double>& b,
        const string& lsolver, const Dict& dict);

  template<>
  Matrix<double> Matrix<double>::
  inv(const Matrix<double>& A,
        const string& lsolver, const Dict& dict);
  template<>
  Matrix<double> Matrix<double>::
  pinv(const Matrix<double>& A, const string& lsolver,
       const Dict& dict);

  template<>
  CASADI_EXPORT Matrix<double> Matrix<double>::
  rand(const Sparsity& sp); // NOLINT(runtime/threadsafe_fn)

  template<>
  Matrix<double> Matrix<double>::
  expm_const(const Matrix<double>& A, const Matrix<double>& t);

  template<>
  Matrix<double> Matrix<double>::
  expm(const Matrix<double>& A);

  template<> void DM::export_code(const std::string& lang,
       std::ostream &stream, const Dict& options) const;

  template<>
  Dict DM::info() const;

  template<>
  void DM::to_file(const std::string& filename, const std::string& format_hint) const;
*/

#ifndef CASADI_DM_INSTANTIATOR_CPP 
  extern template class Matrix<double>;
#endif // CASADI_DM_INSTANTIATOR_CPP

} // namespace casadi

#endif // CASADI_DM_DECL_HPP