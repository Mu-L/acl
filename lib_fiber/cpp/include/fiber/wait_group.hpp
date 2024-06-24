#pragma once
#include "acl_cpp/stdlib/atomic.hpp"

namespace acl {

template<typename T> class fiber_tbox;

class wait_group {
public:
	wait_group(void);
	~wait_group(void);

	void add(int n);
	void done(void);
	void wait(void);

private:
	atomic_long state_;
	fiber_tbox<unsigned long>* box_;
};

} // namespace acl
