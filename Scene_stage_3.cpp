#include "stdafx.h"
#include "Scene.h"
//틀린그림찾기 스테이지3
bool isCorrect3[4] = { false, };
int hp3 = 3;
int timeLimit3 = 200;
bool ispaused3 = false;
bool hint3 = false;
bool hintmode3 = false;
int mouseX3;
int mouseY3;

void Stage_3::OnDestory() //씬 넘어가기 전 버튼과 체력상태 초기화
{
	hintmode3 = false;
	hint3 = false;
	timeLimit3 = 200;
	hp3 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect3[0] = false;
	isCorrect3[1] = false;
	isCorrect3[2] = false;
	isCorrect3[3] = false;
}


void Stage_3::Draw(HDC hMemDC)
{
	ObjPool->stage_3.Draw(hMemDC);
	if (ispaused3 == false)
	{
		if (isCorrect3[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn9.pos.x + 7, ObjPool->asbtn9.pos.y + 17);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect3[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn10.pos.x, ObjPool->asbtn10.pos.y + 15);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect3[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn11.pos.x + 20, ObjPool->asbtn11.pos.y);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect3[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn12.pos.x, ObjPool->asbtn12.pos.y + 20);// 정답을 맞출 시 정답위에 O표시
		}
		if (hint3 == true) // 힌트 이미지가 마우스커서 좌표로
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX3, mouseY3);
		}
		//비트맵 출력

		ObjPool->heart1.Draw(hMemDC);//─────────────────┐
		ObjPool->heart2.Draw(hMemDC);//                 하트 이미지
		ObjPool->heart3.Draw(hMemDC);//─────────────────┘
		ObjPool->light1.Draw(hMemDC);//─────────────────┐
		ObjPool->light2.Draw(hMemDC);//                 전구 이미지
		ObjPool->light3.Draw(hMemDC);//                 │
		ObjPool->light4.Draw(hMemDC);//─────────────────┘
		ObjPool->asbtn9.Draw(hMemDC);//─────────────────┐
		ObjPool->asbtn10.Draw(hMemDC);//                 투명 버튼
		ObjPool->asbtn11.Draw(hMemDC);//                 │
		ObjPool->asbtn12.Draw(hMemDC);//─────────────────┘
		ObjPool->timer.Draw(hMemDC);// 타이머 이미지
		ObjPool->stop.Draw(hMemDC);// 일시정지 이미지
		ObjPool->hint.Draw(hMemDC);// 힌트(돋보기) 이미지
		//버튼 출력

		//텍스트(GDI) 출력
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit3);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB색 설정
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //메모리디씨, x, y, 글꼴 크기
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}

}

bool Stage_3::isCorrectCheck3()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect3[i] == false) return false;
	return true;
}


void Stage_3::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp3 == 0 || timeLimit3 == 0) {//하트 3개가 다 떨어지거나 시간이 다 되면
			Stage_3::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//게임오버 화면으로 이동
		}
		if (isCorrectCheck3())//투명버튼 4개를 다 맞추면
		{
			Stage_3::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//스테이지 클리어 화면으로 이동
			ObjPool->StageBtn_3.bIsOn = true;
			ObjPool->iscleared[2] = true;

		}
		break;
	case 1: //1초마다
		if (ispaused3 == false)
		{
			timeLimit3--;
		}
		break;
	}


}

void Stage_3::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused3 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//버튼을 클릭했을 때
		{
			ispaused3 = true;
		}
		else if (ObjPool->asbtn9.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect3[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn10.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect3[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn11.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect3[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn12.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect3[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y)) {
			hintmode3 = true;
		}

		else if (ObjPool->stage_3.isClick(x, y)) {//Stage_3라는 뒷배경을 클릭하면
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp3 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp3--;
			}
			else if (hp3 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp3--;
			}
			else if (hp3 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp3--;
			}
		}
	}
	else
	{
		ispaused3 = false;
	}
}


void Stage_3::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_3::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode3 == true)
	{
		mouseX3 = x;
		mouseY3 = y;
		if (ObjPool->asbtn9.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect3[0] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint3 = false;
			}
			else	hint3 = true;

		}
		else if (ObjPool->asbtn10.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect3[1] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint3 = false;
			}
			else	hint3 = true;
		}
		else if (ObjPool->asbtn11.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect3[2] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint3 = false;
			}
			else	hint3 = true;
		}
		else if (ObjPool->asbtn12.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect3[3] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint3 = false;
			}
			else	hint3 = true;
		}

		else
		{
			hint3 = false;
		}
	}
}

void Stage_3::OnKeyborad()
{

}