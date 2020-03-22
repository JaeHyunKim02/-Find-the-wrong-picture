#include "stdafx.h"
#include "Scene.h"
//크레딧
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
	if (ObjPool->mainBtn.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_TITLE);	//메인 화면으로
	}
}

void Credit::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Credit::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
}

void Credit::OnKeyborad()
{

}