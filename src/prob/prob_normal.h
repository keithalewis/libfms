// prob.h - probability related functions
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace prob {

	template<class X = double>
	struct normal {
		static X pdf(const X& x)
		{
			static X sqrt2pi = ::sqrt(X(2*M_PI));

			return ::exp(-x*x/2)/sqrt2pi;
		}
		static X cdf(const X& x)
		{
			static X sqrt2 = ::sqrt(X(2));

		    return X(0.5) + ::erf(x/sqrt2)/2;
		}
		// static X inv(const X& x) ...
	};

} // namespace prob
