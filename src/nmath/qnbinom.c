/*
 *  Mathlib : A C Library of Special Functions
 *  Copyright (C) 1998 Ross Ihaka
 *  Copyright (C) 2000 The R Development Core Team
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA.
 *
 *  SYNOPSIS
 *
 *	#include "Mathlib.h"
 *	double qnbinom(double p, double n, double pr, int lower_tail, int log_p)
 *
 *  DESCRIPTION
 *
 *	The distribution function of the negative binomial distribution.
 *
 *  NOTES
 *
 *	x = the number of failures before the n-th success
 *
 *  METHOD
 *
 *	Uses the Cornish-Fisher Expansion to include a skewness
 *	correction to a normal approximation.  This gives an
 *	initial value which never seems to be off by more than
 *	1 or 2.	 A search is then conducted of values close to
 *	this initial start point.
 */

#include "Mathlib.h"

double qnbinom(double p, double n, double pr, int lower_tail, int log_p)
{
    double P, Q, mu, sigma, gamma, z, y;

#ifdef IEEE_754
    if (ISNAN(p) || ISNAN(n) || ISNAN(pr))
	return p + n + pr;
#endif
    R_Q_P01_check(p);
    if (pr <= 0 || pr >= 1 || n <= 0) ML_ERR_return_NAN;

    if (p == R_DT_0) return 0;
#ifdef IEEE_754
    if (p == R_DT_1) return ML_POSINF;
#endif
    Q = 1.0 / pr;
    P = (1.0 - pr) * Q;
    mu = n * P;
    sigma = sqrt(n * P * Q);
    gamma = (Q + P)/sigma;

    z = qnorm(p, 0., 1., lower_tail, log_p);
    y = floor(mu + sigma * (z + gamma * (z*z - 1.0) / 6.0) + 0.5);

    z = pnbinom(y, n, pr, lower_tail, log_p);

    if(z >= p) {	/* search to the left */

	for(;;) {
	    if((z = pnbinom(y - 1, n, pr, lower_tail, log_p)) < p)
		return y;
	    y = y - 1;
	}
    }
    else {		/* search to the right */

	for(;;) {
	    y = y + 1;
	    if((z = pnbinom(y, n, pr, lower_tail, log_p)) >= p)
		return y;
	}
    }
}
