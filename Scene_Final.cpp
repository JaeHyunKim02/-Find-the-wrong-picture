#include "stdafx.h"
#include "Scene.h"
//6���� ���������� Ŭ�����Ͽ��� �� �������� ���ִ� ��
void Final::OnDestory()
{

}

void Final::Draw(HDC hMemDC)
{
	ObjPool->FinalBg.Draw(hMemDC, 0, 0);
	ObjPool->exitBtn.Draw(hMemDC);
}

void Final::OnTimer(HWND hWnd, int timer)
{

}

void Final::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->exitBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		exit(0);	//���α׷� ����
	}
}

void Final::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Final::OnMouseMove(HWND hWnd, int x, int y)
{

	//ObjPool->mainBtn.isOver(x, y);//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
}

void Final::OnKeyborad()
{

}