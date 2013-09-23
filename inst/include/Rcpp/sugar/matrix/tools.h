//
// matrix_functions.h: Rcpp R/C++ interface class library -- matrix sugar functions
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp11.
//
// Rcpp11 is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp11 is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp11.  If not, see <http://www.gnu.org/licenses/>.

#ifndef RCPP_SUGAR_MATRIX_TOOLS_H
#define RCPP_SUGAR_MATRIX_TOOLS_H

namespace Rcpp{
namespace internal{

	inline int get_line( int index, int nr ){
		return index % nr ;
	}

	inline int get_column( int index, int nr ){
		int i = get_line( index, nr ); 
		return (index-i) / nr ;
	}
	
	inline int get_column( int index, int nr, int i ){
		return (index-i) / nr ;
	}

}
}

#endif
