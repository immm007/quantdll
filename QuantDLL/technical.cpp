#include "stdafx.h"
#include "TCalcFuncSets.h"
#include <stdio.h>

//���ɵ�dll���������dll�뿽����ͨ���Ű�װĿ¼��T0002/dlls/����,���ڹ�ʽ���������а�

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

//���صĺ���
PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&relative_strength},
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
