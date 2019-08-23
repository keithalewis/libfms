// root1d.h - One dimensional root finding.
#pragma once
#include <functional>
#define ensure(x)

namespace fms::root {

	// Arguments have opposite sign.
	template<class X = double>
	inline bool opsign(X x0, X x1)
	{
		return copysign(x0, x1) == -x0;
	}

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
		return opsign(y0, y1) && nexttoward(x0,x1) == x1;
	}

	template<class X = double, class Y = double>
	class secant {
		X x0, x1;
		Y y0, y1;
		const std::function<Y(X)>& f;
	public:
		secant(X x0, X x1, const std::function<Y(X)>& f)
			: x0(x0), x1(x1), f(f), y0(f(x0)), y1(f(x1))
		{
			ensure (opsign(y0, y1));
		}
		// Return false when done
		bool next()
		{
			ensure (opsign(y0, y1));
			
			X x = secant(x0, y0, x1, y1);
			Y y = f(x);

			if (opsign(y0, y)) {
				x1 = x;
				y1 = y;
			}
			else {
				x0 = x;
				y0 = y;
			}

			ensure (opsign(y0, y1));

			return !done(x0, y0, x1, y1);
		}
	};

	template<class X = double, class Y = double>
	class newton {
		X x;
		Y y;
		const std::function<Y(X)>& f;
		const std::function<Y(X)>& df;
	public:
		using F = const std::function<Y(X)>&;
		newton(X x, F f, F df)
			: x(x), f(f), df(df), y(f(x))
		{
		}
		bool next()
		{
			X x_ = secant(x, y, df(x));
			Y y_ = f(x_);

			bool done_ = done(x, y, x_, y_);
			swap(x_, x);
			swap(y_, y);

			return done_;
		}
	};

	// solve => back(newton(...))
}
