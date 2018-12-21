#include "stdafx.h"
#include "TCalcFuncSets.h"
#include <stdio.h>
#include "ADL.h"

//生成的dll及相关依赖dll请拷贝到通达信安装目录的T0002/dlls/下面,再在公式管理器进行绑定

void adl(int len,float* outs,float* codes,float* dates,float* pfINc)
{
	static ADL adl("E:\\quant\\data\\technical\\adl.csv");
	int code = codes[0];
	if (!adl.valid(code))
		return;
	for (int i = 0; i != len; ++i)
	{
		int date = dates[i];
		date += 19000000;
		outs[i] = adl.value(code, date);
	}
}

//加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&adl},
	{0,NULL},
};

//导出给TCalc的注册函数
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
	if(*pFun==NULL)
	{
		(*pFun)=g_CalcFuncSets;
		return TRUE;
	}
	return FALSE;
}
