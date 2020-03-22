#include "stdafx.h"
#include "Scene.h"
//스테이지에서 4개의 틀린 부분을 찾았을 때 나오는 씬 
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
	if (ObjPool->home.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_INGAME);	// 스테이지 선택 화면으로
	}
}

void Clear::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Clear::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
}

void Clear::OnKeyborad()
{

}