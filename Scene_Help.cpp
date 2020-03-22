#include "stdafx.h"
#include "Scene.h"

void Help::OnDestory()
{

}

void Help::Draw(HDC hMemDC)
{
	ObjPool->helpBg.Draw(hMemDC,0, 0);
	ObjPool->mainBtn.Draw(hMemDC);//메인 화면으로 가는 버튼
}

void Help::OnTimer(HWND hWnd, int timer)
{

}

void Help::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->mainBtn.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_TITLE);	//메인 화면으로
	}
}

void Help::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Help::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
}

void Help::OnKeyborad()
{

}