// QuantDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "QuantDLL.h"


// ���ǵ���������һ��ʾ��
QUANTDLL_API int nQuantDLL=0;

// ���ǵ���������һ��ʾ����
QUANTDLL_API int fnQuantDLL(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� QuantDLL.h
CQuantDLL::CQuantDLL()
{
    return;
}
