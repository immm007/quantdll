// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� QUANTDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// QUANTDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef QUANTDLL_EXPORTS
#define QUANTDLL_API __declspec(dllexport)
#else
#define QUANTDLL_API __declspec(dllimport)
#endif

// �����Ǵ� QuantDLL.dll ������
class QUANTDLL_API CQuantDLL {
public:
	CQuantDLL(void);
	// TODO:  �ڴ�������ķ�����
};

extern QUANTDLL_API int nQuantDLL;

QUANTDLL_API int fnQuantDLL(void);
