/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 2004-5   The R Development Core Team.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#include <Rinternals.h>
#include <R_ext/Boolean.h>

#ifdef ENABLE_NLS
#include <libintl.h>
#undef _
#define _(String) dgettext ("grDevices", String)
#else
#define _(String) (String)
#endif

void R_chull(int *n, double *x, int *m, int *in,
	   int *ia, int *ib,
	   int *ih, int *nh, int *il);

SEXP PicTeX(SEXP);

SEXP PostScript(SEXP);
SEXP XFig(SEXP);
SEXP PDF(SEXP);
SEXP Type1FontInUse(SEXP, SEXP);
SEXP CIDFontInUse(SEXP, SEXP);

SEXP Quartz(SEXP);

SEXP R_GD_nullDevice();

Rboolean
PSDeviceDriver(NewDevDesc*, const char*, const char*, const char*, char**,
	       const char*, const char*, const char*, double, double,
	       Rboolean, double, Rboolean, Rboolean, Rboolean,
	       const char*, const char*, SEXP, const char*);

Rboolean
PDFDeviceDriver(NewDevDesc*, const char *, const char *, const char *,
		char**, const char *, const char *, const char *,
		double, double, double, int, int, const char*, SEXP, int, int);

#ifdef WIN32
SEXP devga(SEXP);
SEXP savePlot(SEXP);
#endif

