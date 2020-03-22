#include "stdafx.h"
#include "Scene.h"
//틀린그림찾기 스테이지6
bool isCorrect6[4] = { false, };
int hp6 = 3;
int timeLimit6 = 200;
bool ispaused6 = false;
bool hint6 = false;
bool hintmode6 = false;
int mouseX6;
int mouseY6;


void Stage_6::OnDestory() //씬 넘어가기 전 버튼과 체력상태 초기화
{
	hintmode6 = false;
	hint6 = false;
	timeLimit6 = 200;
	hp6 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect6[0] = false;
	isCorrect6[1] = false;
	isCorrect6[2] = false;
	isCorrect6[3] = false;
	
}
void Stage_6::Draw(HDC hMemDC)
{
	if (ispaused6 == false)
	{
		ObjPool->stage_6.Draw(hMemDC);//테스트용임 여기다가 스테이지 6부터 만들기 시작하면 됨
		if (isCorrect6[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn21.pos.x + 17, ObjPool->asbtn21.pos.y - 3);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect6[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn22.pos.x + 10, ObjPool->asbtn22.pos.y - 5);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect6[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn23.pos.x, ObjPool->asbtn23.pos.y - 5);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect6[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn24.pos.x + 20, ObjPool->asbtn24.pos.y + 15);// 정답을 맞출 시 정답위에 O표시
		}
		if (hint6 == true) // 힌트 이미지가 마우스커서 좌표로
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX6, mouseY6);
		}
		//비트맵 출력

		ObjPool->heart1.Draw(hMemDC);//─────────────────┐
		ObjPool->heart2.Draw(hMemDC);//                 하트 이미지
		ObjPool->heart3.Draw(hMemDC);//─────────────────┘
		ObjPool->light1.Draw(hMemDC);//─────────────────┐
		ObjPool->light2.Draw(hMemDC);//                 전구 이미지
		ObjPool->light3.Draw(hMemDC);//                 │
		ObjPool->light4.Draw(hMemDC);//─────────────────┘
		ObjPool->asbtn21.Draw(hMemDC);//─────────────────┐
		ObjPool->asbtn22.Draw(hMemDC);//                 투명 버튼
		ObjPool->asbtn23.Draw(hMemDC);//                 │
		ObjPool->asbtn24.Draw(hMemDC);//─────────────────┘
		ObjPool->timer.Draw(hMemDC);// 타이머 이미지
		ObjPool->stop.Draw(hMemDC);// 일시정지 이미지
		ObjPool->hint.Draw(hMemDC);// 힌트(돋보기) 이미지

		//텍스트(GDI) 출력
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit6);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB색 설정
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //메모리디씨, x, y, 글꼴 크기
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}
}

bool Stage_6::isCorrectCheck6()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect6[i] == false) return false;
	return true;
}

void Stage_6::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp6 == 0 || timeLimit6 == 0) {//하트 3개가 다 떨어지거나 시간이 다 되면
			Stage_6::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//게임오버 화면으로 이동
		}
		if (isCorrectCheck6())//투명버튼 4개를 다 맞추면
		{
			Stage_6::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//스테이지 클리어 화면으로 이동
			ObjPool->StageBtn_6.bIsOn = true;
			ObjPool->iscleared[5] = true;
		}
		break;
	case 1:
		if (ispaused6 == false)
		{
			timeLimit6--;
		}
		break;
	}
}

void Stage_6::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused6 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//버튼을 클릭했을 때
		{
			ispaused6 = true;
		}
		else if (ObjPool->asbtn21.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect6[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn22.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect6[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn23.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect6[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn24.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect6[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y))
		{
			hintmode6 = true;
		}

		else if (ObjPool->stage_6.isClick(x, y)) {//Stage_4라는 뒷배경을 클릭하면
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp6 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp6--;
			}
			else if (hp6 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp6--;
			}
			else if (hp6 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp6--;
			}
		}
	}
	else
	{
		ispaused6 = false;
	}
}

void Stage_6::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_6::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode6 == true)
	{
		mouseX6 = x;
		mouseY6 = y;
		if (ObjPool->asbtn21.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect6[0] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint6 = false;
			}
			else	hint6 = true;
		}
		else if (ObjPool->asbtn22.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect6[1] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint6 = false;
			}
			else	hint6 = true;
		}
		else if (ObjPool->asbtn23.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect6[2] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint6 = false;
			}
			else	hint6 = true;
		}
		else if (ObjPool->asbtn24.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect6[3] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint6 = false;
			}
			else	hint6 = true;
		}
		else
		{
			hint6 = false;
		}
	}
}

void Stage_6::OnKeyborad()
{

}