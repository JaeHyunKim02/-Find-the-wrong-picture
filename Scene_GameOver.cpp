#include "stdafx.h"
#include "Scene.h"
//한 스테이지에서 하트3개가 닳아 끝났을 때
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
	if (ObjPool->home.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_INGAME);	//스테이지 선택 화면으로
	}
}

void Game_Over::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Game_Over::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
}

void Game_Over::OnKeyborad()
{

}