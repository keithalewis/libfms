// root1d.h - One dimensional root finding.
#pragma once
#include <functional>

namespace fms::root {

	template<class X = double, class Y = double>
	inline X secant(X x, Y y, decltype(Y/X) m))
	{
		return x - y/m;
	}

	template<class X = double, class Y = double>
	inline X secant(X x0, Y y0, X x1, Y y1)
	{
		return (x0*y1 - x1*y0)(x0 - x1);
	}

	template<class X = double, class Y = double>
	inline bool done(X x0, Y y0, X x1, Y y1)
	{
		return copysign(y0, y1) == -y0
			&& nexttoward(x0,x1) == x1;
	}

	template<class X = double>
	class root1d {
		const std::function<X(X)>& f;
		X x, m;
    public:
		root1d(const std::function<X(X)>& f)
			: f(f)
		{ }
		X next()
		{
			X fx = f(x);
			X x_ = x - f(x)/m;
			m = 
			return x - f(x)/m;
		}
	};
}
