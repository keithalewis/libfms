# libfms

## Modules

### Probability

Define pdf, cdf, and inv for each distribution.

Define instruments using coroutines.
Each call returns (t,a,i,c) time, amount, instrument, counterparty

struct ForwardRateAgreement {
	Time effective, termination;
	Amount coupon;

	Tenor settlement; // e.g, T+1
	Tenor period; // e.g., 3 months
	DayCountBasis dcb; // e.g., actual/360
	RollConvention roll; // e.g., following
	Calendar calendar; // e.g., New York business

	fix(valuation, coupon)
	{
		effective = (valuation + settlment).adjust(roll, calendar);
		termination = (effective + period).adjust(roll, calendar);
		coupon = coupon;
	}
};

struct ForwardRate {
	Tenor tenor;
	DayCountBasis dcb;
	RollConvention roll; // e.g., following
	Calendar calendar; // e.g., New York business
};

Rate forward(ForwardRate f, Discount D)
{
	return [](auto t, e) {
		e.adjust(f.roll, f.calendar);
		e = (e + f.tenor).adjust(f.roll, f.calendar);
		return (D(t, b)/D(t,e) - 1)/dcf(b,e);
	};
}
