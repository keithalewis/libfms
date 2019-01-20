// template.h
#pragma once
#include <gsl_assert>

namespace fms {

static const char fms_template_doc[] = R"xyzzyx(
This is template documentation.
)xyzzyx"

	class template {
		int i;
		public:
		template(int i)
			: i(i)
		{ }
		int value() const
		{
			return i;
		}
	};

} // namespace fms
