#include "stdafx.h"
#include "Scene.h"
//�� ������������ ��Ʈ3���� ��� ������ ��
void Game_Over::OnDestory()
{

}

void Game_Over::Draw(HDC hMemDC)
{
	ObjPool->Game_OverBg.Draw(hMemDC, 0, 0);
	ObjPool->home.Draw(hMemDC);
}

void Game_Over::OnTimer(HWND hWnd, int timer)
{

}

void Game_Over::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->home.isClick(x, y))	//��ư�� Ŭ������ ��
	{
		ObjPool->System.SetScene(SCENE_INGAME);	//�������� ���� ȭ������
	}
}

void Game_Over::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Game_Over::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//��� ���콺������ Ȯ�� (Ȯ�� �Ǿ��� �� ��ü ���ο��� On�� true�� �ٲ���)
}

void Game_Over::OnKeyborad()
{

}