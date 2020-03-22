#include "stdafx.h"
#include "Scene.h"
//스테이지 선택화면으로 가는 버튼, 크레딧버튼, 게임을 나가는 버튼을 선택하는 곳
bool isSoundPlay = 0;

void Title::OnDestroy()
{

}

void Title::Draw(HDC hMemDC)
{

	ObjPool->titleBg.Draw(hMemDC, 0, 0);
	//비트맵 출력

	ObjPool->startBtn.Draw(hMemDC);
	//버튼 출력
	ObjPool->exitBtn.Draw(hMemDC);
	ObjPool->helpBtn.Draw(hMemDC);
	ObjPool->creditBtn.Draw(hMemDC);
	ObjPool->SoundBtn.Draw(hMemDC);
	
}

void Title::OnTimer(HWND hWnd, int timer)
{

}

void Title::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ObjPool->startBtn.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_INGAME);	//스테이지 선택 화면으로
	}
	if (ObjPool->creditBtn.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_CREDIT);	//크레딧으로
	}
	if (ObjPool->helpBtn.isClick(x, y))	//버튼을 클릭했을 때
	{
		ObjPool->System.SetScene(SCENE_HELP);	//도움창으로
	}
	if (ObjPool->exitBtn.isClick(x, y))	//버튼을 클릭했을 때
	{
		exit(0); //게임 종료
	}
	if (ObjPool->SoundBtn.isClick(x, y))	//버튼을 클릭했을 때
	{


		if (isSoundPlay == 0) {
			ObjPool->SoundBtn.bIsOn = true;
			//mciSendString(L"play Sound\\BGM.wav REPEAT", NULL, 0, 0);
			mciSendString(L"play Sound\\BGM.wav", NULL, 0, 0);
			//sndPlaySound(L"Sound\\BGM.wav", SND_NO); // 눌렀을 때 BGM나오게 해주는것
			isSoundPlay = 1;
			//mciSendString(L"play Sound\\BGM.wav", NULL, 0, NULL);
			
		}
		else if (isSoundPlay == 1) {
			ObjPool->SoundBtn.bIsOn = false;
			mciSendString(L"pause Sound\\BGM.wav", NULL, 0, 0);
			//sndPlaySound(NULL, SND_NOSTOP);
			isSoundPlay = 0;
		}
	}
}

void Title::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Title::OnMouseMove(HWND hWnd, int x, int y)
{
	ObjPool->startBtn.isOver(x, y);	//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
	ObjPool->exitBtn.isOver(x, y);	//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
	ObjPool->helpBtn.isOver(x, y);	//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
	ObjPool->creditBtn.isOver(x, y);//계속 마우스오버를 확인 (확인 되었을 때 객체 내부에서 On을 true로 바꿔줌)
}

void Title::OnKeyborad()
{

}