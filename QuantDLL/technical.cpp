#include "stdafx.h"
#include "TCalcFuncSets.h"
#include <stdio.h>
#include "ADL.h"

//���ɵ�dll���������dll�뿽����ͨ���Ű�װĿ¼��T0002/dlls/����,���ڹ�ʽ���������а�

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
