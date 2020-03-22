#include "stdafx.h"
#include "Scene.h"
//6개의 스테이지를 클리어하였을 때 엔딩보게 해주는 곳
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
	if (ObjPool->exitBtn.isClick(x, y))	//버튼을 클릭했을 때
	{
		exit(0);	//프로그램 종료
	}
}

void Final::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Final::OnMouseMove(HWND hWnd, int x, int y)
{

	//ObjPool->mainBtn.isOver(x, y);//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
}

void Final::OnKeyborad()
{

}