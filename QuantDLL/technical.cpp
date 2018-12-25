#include "stdafx.h"
#include "TCalcFuncSets.h"
#include <boost/python/numpy.hpp>

namespace p = boost::python;
namespace np = boost::python::numpy;
//���ɵ�dll���������dll�뿽����ͨ���Ű�װĿ¼��T0002/dlls/����,���ڹ�ʽ���������а�

void adl(int len,float* outs,float* codes,float* dates,float* pfINc)
{
	//MessageBoxA(nullptr, "1", "log", MB_OK);
	Py_SetPythonHome(L"E:\\anaconda3");
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		MessageBoxA(nullptr, "start python fail", "error", MB_OK);
	}
	//MessageBoxA(nullptr, "2", "log", MB_OK);
	np::initialize();
	//MessageBoxA(nullptr, "3", "log", MB_OK);
	np::ndarray py_array = np::from_data(outs, np::dtype::get_builtin<float>(),
		p::make_tuple(len),
		p::make_tuple(sizeof(float)),
		p::object());
	//MessageBoxA(nullptr, "4", "log", MB_OK);
	auto quant = p::import("quant");
	//MessageBoxA(nullptr, "5", "log", MB_OK);
	quant.attr("adl")(py_array);
	//MessageBoxA(nullptr, "6", "log", MB_OK);
}

//���صĺ���
PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&adl},
	{0,NULL},
};

//������TCalc��ע�ắ��
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
	if(*pFun==NULL)
	{
		(*pFun)=g_CalcFuncSets;
		return TRUE;
	}
	return FALSE;
}
