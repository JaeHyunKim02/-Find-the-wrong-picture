#include "stdafx.h"
#include "Scene.h"
//������������ 4���� Ʋ�� �κ��� ã���� �� ������ �� 
void Clear::OnDestory()
{

}

void Clear::Draw(HDC hMemDC)
{
	ObjPool->ClearBg.Draw(hMemDC, 0, 0);
	ObjPool->home.Draw(hMemDC);
}

void Clear::OnTimer(HWND hWnd, int timer)
{

}

void Clear::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->home.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_INGAME);	// �������� ���� ȭ������
	}
}

void Clear::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Clear::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
}

void Clear::OnKeyborad()
{

}