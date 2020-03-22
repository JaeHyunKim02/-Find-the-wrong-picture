#include "stdafx.h"
#include "Scene.h"
//틀린그림찾기 스테이지5
bool isCorrect5[4] = { false, };
int hp5 = 3;
int timeLimit5 = 200;
bool ispaused5 = false;
bool hint5 = false;
bool hintmode5 = false;
int mouseX5;
int mouseY5;


void Stage_5::OnDestory() //씬 넘어가기 전 버튼과 체력상태 초기화
{
	hintmode5 = false;
	hint5 = false;
	timeLimit5 = 200;
	hp5 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect5[0] = false;
	isCorrect5[1] = false;
	isCorrect5[2] = false;
	isCorrect5[3] = false;
	
}
void Stage_5::Draw(HDC hMemDC)
{
	ObjPool->stage_5.Draw(hMemDC);//테스트용임 여기다가 스테이지 5부터 만들기 시작하면 됨
	if (ispaused5 == false)
	{
		if (isCorrect5[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn17.pos.x + 30, ObjPool->asbtn17.pos.y + 10);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect5[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn18.pos.x + 10, ObjPool->asbtn18.pos.y);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect5[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn19.pos.x + 15, ObjPool->asbtn19.pos.y + 20);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect5[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn20.pos.x + 10, ObjPool->asbtn20.pos.y); // 정답을 맞출 시 정답위에 O표시
		}
		if (hint5 == true) // 힌트 이미지가 마우스커서 좌표로
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX5, mouseY5);
		}
		//비트맵 출력

		ObjPool->heart1.Draw(hMemDC);//─────────────────┐
		ObjPool->heart2.Draw(hMemDC);//                 하트 이미지
		ObjPool->heart3.Draw(hMemDC);//─────────────────┘
		ObjPool->light1.Draw(hMemDC);//─────────────────┐
		ObjPool->light2.Draw(hMemDC);//                 전구 이미지
		ObjPool->light3.Draw(hMemDC);//                 │
		ObjPool->light4.Draw(hMemDC);//─────────────────┘
		ObjPool->asbtn17.Draw(hMemDC);//─────────────────┐
		ObjPool->asbtn18.Draw(hMemDC);//                 투명 버튼;
		ObjPool->asbtn19.Draw(hMemDC);//                 │
		ObjPool->asbtn20.Draw(hMemDC);//─────────────────┘
		ObjPool->timer.Draw(hMemDC);// 타이머 이미지
		ObjPool->stop.Draw(hMemDC);// 일시정지 이미지
		ObjPool->hint.Draw(hMemDC);// 힌트(돋보기) 이미지

		//텍스트(GDI) 출력
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit5);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB색 설정
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //메모리디씨, x, y, 글꼴 
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}
}

bool Stage_5::isCorrectCheck5()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect5[i] == false) return false;
	return true;
}


void Stage_5::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp5 == 0 || timeLimit5 == 0) {//하트 3개가 다 떨어지거나 시간이 다 되면
			Stage_5::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//게임오버 화면으로 이동
		}
		if (isCorrectCheck5())//투명버튼 4개를 다 맞추면
		{
			Stage_5::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//스테이지 클리어 화면으로 이동
			ObjPool->StageBtn_5.bIsOn = true;
			ObjPool->iscleared[4] = true;
		}
		break;
	case 1:
		if (ispaused5 == false)
		{
			timeLimit5--;
		}
		break;
	}
}

void Stage_5::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused5 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//버튼을 클릭했을 때
		{
			ispaused5 = true;
		}
		else if (ObjPool->asbtn17.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect5[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn18.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect5[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn19.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect5[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn20.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect5[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y))
		{
			hintmode5 = true;
		}

		else if (ObjPool->stage_5.isClick(x, y)) {//Stage_4라는 뒷배경을 클릭하면
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp5 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp5--;
			}
			else if (hp5 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp5--;
			}
			else if (hp5 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp5--;
			}
		}
	}
	else
	{
		ispaused5 = false;
	}
}

void Stage_5::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_5::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode5 == true)
	{
		mouseX5 = x;
		mouseY5 = y;
		if (ObjPool->asbtn17.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect5[0] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint5 = false;
			}
			else	hint5 = true;
		}
		else if (ObjPool->asbtn18.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect5[1] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint5 = false;
			}
			else	hint5 = true;
		}
		else if (ObjPool->asbtn19.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect5[2] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint5 = false;
			}
			else	hint5 = true;
		}
		else if (ObjPool->asbtn20.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect5[3] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint5 = false;
			}
			else	hint5 = true;
		}

		else
		{
			hint5 = false;
		}
	}
}

void Stage_5::OnKeyborad()
{

}