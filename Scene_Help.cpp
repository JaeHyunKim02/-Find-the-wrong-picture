#include "stdafx.h"
#include "Scene.h"

void Help::OnDestory()
{

}

void Help::Draw(HDC hMemDC)
{
	ObjPool->helpBg.Draw(hMemDC,0, 0);
	ObjPool->mainBtn.Draw(hMemDC);//���� ȭ������ ���� ��ư
}

void Help::OnTimer(HWND hWnd, int timer)
{

}

void Help::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->mainBtn.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_TITLE);	//���� ȭ������
	}
}

void Help::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Help::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
}

void Help::OnKeyborad()
{

}