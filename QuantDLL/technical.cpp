#include "stdafx.h"
#include "TCalcFuncSets.h"
#include <stdio.h>

//生成的dll及相关依赖dll请拷贝到通达信安装目录的T0002/dlls/下面,再在公式管理器进行绑定

void relative_strength(int len,float* outs,float* codes,float* dates,float* pfINc)
{
	char s[8];
	int code = codes[0];
	sprintf(s, "%06d", code);
	MessageBoxA(NULL, s, "1", MB_OK);
	for (int i = 0; i != len; ++i)
	{
		int date = dates[i];
		date += 19000000;
		char s2[16];
		sprintf(s2, "%08d", date);
		MessageBoxA(NULL, s2, "2", MB_OK);
	}
}

//加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&relative_strength},
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
