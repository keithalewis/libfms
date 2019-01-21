// test_prob_normal.h - test the normal distribution
#include "ensure.h"
#include "prob_normal.h"

template<class X = double>
inline void test_prob_normal()
{
	ensure (prob::normal<X>::cdf(X(0)) == X(0.5));
}
