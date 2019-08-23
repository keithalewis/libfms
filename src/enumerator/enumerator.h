// enum.h - Enumerators: iterators with operator bool() const..
#pragma once
#include <cstddef>

namespace fms {
namespace enumerator {

	template<class E>
	class counted {
		E e;
		std::size_t n;
	public:
		counted(E e, std::size_t n = -1)
			: e(e), n(n)
		{ }
		std::size_t size() const
		{ 
			return n;
		}
		bool operator==(const counted& a) const
		{
			return e == a.e && n == a.n;
		}
		bool operator!=(const counted& a) const
		{
			return !operator==(a);
		}
		operator bool() const
		{
			return n != 0;
		}
		auto& operator*()
		{
			return *e;
		}
		const auto& operator*() const
		{
			return *e;
		}
		counted& operator++()
		{
			++e;
			--n;

			return *this;
		}
	};

#if 0
	template<class E>
	inline E&& end(E&& e)
	{
		while (e) {
			++e;
		}

		return e;
	}

	template<class E>
	inline E&& back(E&& e)
	{
		auto b = e;

		if (e) {
			while (++e) {
				++b;
			}
		}

		return b;
	}
	
	template<class E>
	class reverse {
		E&& b;
		E&& e;
		bool done;
	public:
		reverse(E&& e)
			: b(e), e(end(e)), done(--e)
		{ }
		operator bool() const
		{ 
			return !done;			
		}
		auto operator*()
		{
			return *e;
		}
		reverse& operator++()
		{
			if (b == e)
				done = true;
			--e;

			return *this;
		}
	};

	template<class E>
	inline auto drop(int n, E&& e)
	{
		if (n > 0) {
			while (n-- && e) {
				++e;
			}
		}
		else if (n < 0) {
			e = reverse(drop(-n, reverse(e)));
		}

		return e;
	}

	template<class E>
	class take {
		int n;
		E&& e;
		public:
		take(int n, E&& e)
			: n(n), e(n < 0 ? reverse(take(-n,reverse(e))) : e)
		{ }
		operator bool() const
		{
			return n != 0;
		}
		auto operator*()
		{
			return *e;
		}
		take& operator++()
		{
			--n;
			++e;

			return *this;
		}
	};
#endif // 0

}} // fms::enum
