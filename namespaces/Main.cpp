// A namespace can span several files.
namespace abc {
	namespace def {
		void f() {}
		void g() {}
	}
}

namespace xyz {
	void f() {}
	void h() {}
}

void f() {
}

namespace n = abc::def;

using namespace abc::def;
using namespace xyz;
int main() {
	n::f();
	g();
	xyz::f();
	h();
	::f();
}