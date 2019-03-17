// enumerator.t.cpp - test enum
/*
:!CXXFLAGS='-g -Wall' make %:r; ./%:r
*/
#include <cassert>
#include "enumerator.h"

using namespace fms;
using namespace enumerator;

template<class T>
void test_fms_enumerator_counted()
{
	{
		T t[] = {1,2,3};
		auto e = counted<T*>(t);
		assert (e);
		assert (e.size() == -1ul);
		auto e2{e};
		assert (e2);
		assert (e2.size() == -1ul);
		assert (e2 == e);
		assert (!(e2 != e));
		e = e2;
		assert (e);
		assert (e2);
		assert (e.size() == -1ul);
		assert (e2.size() == -1ul);
		assert (*e == t[0]);
		*e = 4;
		assert (*e == 4);
		++e;
		assert (e.size() == -2ul);
		assert (e);
		assert (*e == t[1]);
		++e;
		assert (e.size() == -3ul);
		assert (e);
		assert (*e == t[2]);
		++e;
		assert (e.size() == -4ul);
		assert (e); // but don't deref
		++e;
		assert (e.size() == -5ul);
		assert (e); // but don't deref
	}
}

int main()
{
	test_fms_enumerator_counted<double>();

	return 0;
}
