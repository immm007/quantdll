#include <iostream>
#include <boost/python/numpy.hpp>

using namespace std;

namespace p = boost::python;
namespace np = boost::python::numpy;

int main()
{
	Py_SetPythonHome(L"E:\\anaconda3");
	Py_Initialize();
	np::initialize();
	float* outs = new float[5];
	np::ndarray py_array = np::from_data(outs, np::dtype::get_builtin<float>(),
		p::make_tuple(5),
		p::make_tuple(sizeof(float)),
		p::object());
	auto quant = p::import("quant");
	quant.attr("adl")(py_array);
	for (int i = 0; i != 5; ++i)
	{
		cout << outs[i];
	}
	cin.get();
}