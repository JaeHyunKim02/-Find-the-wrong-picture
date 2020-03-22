#include "stdafx.h"
#include "Scene.h"
//틀린그림찾기 스테이지2
bool isCorrect2[4] = { false, };
int hp2 = 3;
int timeLimit2 = 200;
bool ispaused2 = false;
bool hint2 = false;
bool hintmode2 = false;
int mouseX2;
int mouseY2;


void Stage_2::OnDestory() //씬 넘어가기 전 버튼과 체력상태 초기화
{

	hintmode2 = false;
	hint2 = false;
	timeLimit2 = 200;
	hp2 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect2[0] = false;
	isCorrect2[1] = false;
	isCorrect2[2] = false;
	isCorrect2[3] = false;
	
}


void Stage_2::Draw(HDC hMemDC)
{
	if (ispaused2 == false)
	{
		ObjPool->stage_2.Draw(hMemDC);//테스트용임 여기다가 스테이지 2부터 만들기 시작하면 됨
		if (isCorrect2[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn5.pos.x + 25, ObjPool->asbtn5.pos.y + 10);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect2[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn6.pos.x + 5, ObjPool->asbtn6.pos.y + 25);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect2[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn7.pos.x + 25, ObjPool->asbtn7.pos.y + 20);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect2[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn8.pos.x + 20, ObjPool->asbtn8.pos.y + 27); // 정답을 맞출 시 정답위에 O표시
		}
		if (hint2 == true) // 힌트 이미지가 마우스커서 좌표로
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX2, mouseY2);
		}
		//비트맵 출력

		ObjPool->heart1.Draw(hMemDC);//─────────────────┐
		ObjPool->heart2.Draw(hMemDC);//                 하트 이미지
		ObjPool->heart3.Draw(hMemDC);//─────────────────┘
		ObjPool->light1.Draw(hMemDC);//─────────────────┐
		ObjPool->light2.Draw(hMemDC);//                 전구 이미지
		ObjPool->light3.Draw(hMemDC);//                 │
		ObjPool->light4.Draw(hMemDC);//─────────────────┘
		ObjPool->asbtn5.Draw(hMemDC);//─────────────────┐
		ObjPool->asbtn6.Draw(hMemDC);//                 투명 버튼
		ObjPool->asbtn7.Draw(hMemDC);//                 │
		ObjPool->asbtn8.Draw(hMemDC);//─────────────────┘
		ObjPool->timer.Draw(hMemDC);// 타이머 이미지
		ObjPool->stop.Draw(hMemDC);// 일시정지 이미지
		ObjPool->hint.Draw(hMemDC);// 힌트(돋보기) 이미지

		//텍스트(GDI) 출력
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit2);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB색 설정
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //메모리디씨, x, y, 글꼴 크기
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}
}

bool Stage_2::isCorrectCheck2()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect2[i] == false) return false;
	return true;
}


void Stage_2::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp2 == 0|| timeLimit2==0) {//하트 3개가 다 떨어지거나 시간이 다 되면
			Stage_2::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//게임오버 화면으로 이동
		}
		if (isCorrectCheck2())//투명버튼 4개를 다 맞추면
		{
			Stage_2::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//스테이지 클리어 화면으로 이동
			ObjPool->StageBtn_2.bIsOn = true;
			ObjPool->iscleared[1] = true;
		}
		break;
	case 1: //1초마다
		if (ispaused2 == false)
		{
			timeLimit2--;
		}
		break;
	}
}

void Stage_2::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused2 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//버튼을 클릭했을 때
		{
			ispaused2 = true;
		}
		else if (ObjPool->asbtn5.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect2[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn6.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect2[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn7.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect2[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn8.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect2[3] = true;
			ObjPool->light4.bIsOn = true;
		}
		else if (ObjPool->hint.isClick(x, y))
		{
			hintmode2 = true;
		}

		else if (ObjPool->stage_2.isClick(x, y)) {//Stage_4라는 뒷배경을 클릭하면
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp2 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp2--;
			}
			else if (hp2 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp2--;
			}
			else if (hp2 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp2--;
			}
		}
	}
	else
	{
		ispaused2 = false;
	}
}

void Stage_2::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_2::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode2 == true)
	{
		mouseX2 = x;
		mouseY2 = y;
		if (ObjPool->asbtn5.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect2[0] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint2 = false;
			}
			else	hint2 = true;
		}
		else if (ObjPool->asbtn6.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect2[1] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint2 = false;
			}
			else	hint2 = true;

		}
		else if (ObjPool->asbtn7.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect2[2] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint2 = false;
			}
			else	hint2 = true;

		}
		else if (ObjPool->asbtn8.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect2[3] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint2 = false;
			}
			else	hint2 = true;

		}

		else
		{
			hint2 = false;
		}
	}
}

void Stage_2::OnKeyborad()
{

}