#include "stdafx.h"
#include "Scene.h"
//ũ����
void Credit::OnDestory()
{

}

void Credit::Draw(HDC hMemDC)
{
	ObjPool->creditBg.Draw(hMemDC, 0, 0);
	ObjPool->mainBtn.Draw(hMemDC);
}

void Credit::OnTimer(HWND hWnd, int timer)
{

}

void Credit::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->mainBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_TITLE);	//���� ȭ������
	}
}

void Credit::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Credit::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
}

void Credit::OnKeyborad()
{

}