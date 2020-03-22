#pragma once

class Button	//��ư!
{
public:
	Button() { }
	~Button() { }

public:
	bool bIsOn = false;	//���� �Ǿ��°�?
	RECT rect;

	HDC hdcImg;				//�̸� �׷��� ��Ʈ���� DC
	HBITMAP ButtonUp;		//��Ʈ��
	HBITMAP ButtonDown;		//��Ʈ��
	COLORREF SpriteColor;	//����ȭ �÷� (����Ÿ�� �⺻)
	POINT pos;				//��ǥ
	int w;					//�ʺ�
	int h;					//����

	std::function<void()> m_Func;

public:
	void Init(HWND hWnd, LPCWSTR szUp, LPCWSTR szDown, int x, int y, int w, int h, COLORREF sprite); //�ʱ�ȭ
	void Draw(HDC hMemDC);	//�׸���

	void SetRect(RECT rt);	//��ġ ����

	bool isOver(int x, int y);	//���콺�� �ö�Դ���
	bool hint(int x, int y);
	bool isClick(int x, int y);	//Ŭ���� �Ǿ�����
};
