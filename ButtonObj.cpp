#include "stdafx.h"
#include "ButtonObj.h"

void Button::SetRect(RECT rt)
{
	rect.left = rt.left;
	rect.top = rt.top;
	rect.right = rt.right;
	rect.bottom = rt.bottom;
}

void Button::Init(HWND hWnd, LPCWSTR szUp, LPCWSTR szDown, int x, int y, int w, int h, COLORREF sprite)
{
	hdcImg = CreateCompatibleDC(GetDC(hWnd));	//�׸� DC�� ����

	SetRect({ x, y, x + w, y + h }); //LEFT�� RIGHT�� x���� �ް�, TOP�� BOTTOM�� Y���� �����Ƿ�.

	WCHAR str[128];
	wsprintf(str, szUp);
	ButtonUp = (HBITMAP)LoadImage(NULL, szUp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //�̹��� ��ηκ��� �̹��� �޾ƿ���

	wsprintf(str, szDown);
	ButtonDown = (HBITMAP)LoadImage(NULL, szDown, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	if (ButtonUp == NULL || ButtonDown == NULL) //�̹����� ������
	{
		MessageBox(NULL, L"�̹����� �����ϴ�.", L"����!!!", MB_OK);	//�̹����ҷ����� ����
		exit(0);
	}

	pos.x = x; //�׸��� ��� ��ǥ��
	pos.y = y;
	this->w = w; //�׸��� �ʺ�, ���̸� ����
	this->h = h;

	SpriteColor = sprite; //����Ÿ ���ֱ�
}

void Button::Draw(HDC hMemDC)
{
	if (!bIsOn)	//�� ���ο� ���� � �귯���� ���� �� ������ üũ
	{
		SelectObject(hdcImg, ButtonUp);	//�̸� ������ DC�� �ҷ��� ��Ʈ���� ����
		TransparentBlt(hMemDC, pos.x, pos.y, w, h, hdcImg, 0, 0, w, h, SpriteColor);	//�޾ƿ� �ĸ�DC�� ��Ʈ���� �ҷ��� DC�� ����
	}
	else
	{
		SelectObject(hdcImg, ButtonDown);	//�̸� ������ DC�� �ҷ��� ��Ʈ���� ����
		TransparentBlt(hMemDC, pos.x, pos.y, w, h, hdcImg, 0, 0, w, h, SpriteColor);	//�޾ƿ� �ĸ�DC�� ��Ʈ���� �ҷ��� DC�� ����
	}

	//���� �ĸ�DC�� �׸���
	//Rectangle(hMemDC, rect.left, rect.top, rect.right, rect.bottom);

	//�����ʰ� �����ֱ�
}

bool Button::isOver(int x, int y)	//���콺���� üũ
{
	if ((rect.left <= x) && (x <= rect.right) && (rect.top <= y) && (y <= rect.bottom))
	{
		bIsOn = true;
		return true;
	}
	bIsOn = false;
	return false;
}

bool Button::hint(int x, int y)	//���콺���� üũ
{
	if ((rect.left-25 <= x) && (x <= rect.right+25) && (rect.top-25 <= y) && (y <= rect.bottom+25))
	{
		return true;
	}
	return false;
}

bool Button::isClick(int x, int y)	//���콺������ ���� �Լ��ε� �� ���������� �Լ��� �̸��� �ٸ��� �Ͽ� ���� ������ ����
{									//�ƴϸ� ���콺���� �� �ܿ� Ŭ�� ���� �߰��Ͽ� ������ �Ǿ�����, Ŭ���� �Ǿ����� üũ�� �� ����
	if ((rect.left <= x) && (x <= rect.right) && (rect.top <= y) && (y <= rect.bottom))
	{
		return true;
	}
	return false;
}