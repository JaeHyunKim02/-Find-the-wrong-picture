#include "stdafx.h"
#include "Scene.h"
//스테이지를 선택하는 창
bool Ingame::endingCheck()
{
	for (int i = 0; i < 6; i++)
		if (ObjPool->iscleared[i] == false) return false;
	return true;
}



void Ingame::OnDestroy()
{

}

void Ingame::Draw(HDC hMemDC)
{
	ObjPool->stagechooseBg.Draw(hMemDC, 0, 0);
	ObjPool->StageBtn_1.Draw(hMemDC);//스테이 1~6 들어가는 버튼
	ObjPool->StageBtn_2.Draw(hMemDC);
	ObjPool->StageBtn_3.Draw(hMemDC);
	ObjPool->StageBtn_4.Draw(hMemDC);
	ObjPool->StageBtn_5.Draw(hMemDC);
	ObjPool->StageBtn_6.Draw(hMemDC);
	ObjPool->mainBtn.Draw(hMemDC);
	if (endingCheck())
	{
		ObjPool->end.Draw(hMemDC);
	}
}

void Ingame::OnTimer(HWND hWnd, int timer)
{
	//switch (timer)
	//{
	//case 0: //0.1초마다 호출되는 타이머
	//	
	//}
}

void Ingame::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->StageBtn_1.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_STAGE_1);	//첫번째 스테이지로
	}
	if (ObjPool->StageBtn_2.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_STAGE_2);	//두번째 스테이지로
	}
	if (ObjPool->StageBtn_3.isClick(x, y))	//버튼을 클 릭했을 때
	{
		ObjPool->System.SetScene(SCENE_STAGE_3);	//세번째 스테이지로
	}
	if (ObjPool->StageBtn_4.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_STAGE_4);	//네번째 스테이지로
	}
	if (ObjPool->StageBtn_5.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_STAGE_5);	//다섯번째 스테이지로
	}
	if (ObjPool->StageBtn_6.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_STAGE_6);	//여섯번째 스테이지로
	}
	if (ObjPool->mainBtn.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_TITLE);	//메인으로
	}
	if (ObjPool->end.isClick(x, y) && endingCheck())	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_FINAL);	//모든 스테이지를 끝냈을 때 가는 창으로
	}
}

void Ingame::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Ingame::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->mainBtn.isOver(x, y);//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
}

void Ingame::OnKeyborad()
{

}