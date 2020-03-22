#include "stdafx.h"
#include "Scene.h"
//틀린그림찾기 스테이지4
bool isCorrect4[4] = { false, };
int hp4 = 3;
int timeLimit4 = 200;
bool ispaused4 = false;
bool hint4 = false;
bool hintmode4 = false;
int mouseX4;
int mouseY4;


void Stage_4::OnDestory() //씬 넘어가기 전 버튼과 체력상태 초기화
{
	hintmode4 = false;
	hint4 = false;
	timeLimit4 = 200;
	hp4 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect4[0] = false;
	isCorrect4[1] = false;
	isCorrect4[2] = false;
	isCorrect4[3] = false;
	
}

void Stage_4::Draw(HDC hMemDC)
{
	ObjPool->stage_4.Draw(hMemDC);
	if (ispaused4 == false)
	{
		if (isCorrect4[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn13.pos.x + 10, ObjPool->asbtn13.pos.y);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect4[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn14.pos.x + 20, ObjPool->asbtn14.pos.y);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect4[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn15.pos.x + 10, ObjPool->asbtn15.pos.y + 5);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect4[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn16.pos.x + 10, ObjPool->asbtn16.pos.y + 17); // 정답을 맞출 시 정답위에 O표시
		}
		//비트맵 출력

		ObjPool->heart1.Draw(hMemDC);//─────────────────┐
		ObjPool->heart2.Draw(hMemDC);//                 하트 이미지
		ObjPool->heart3.Draw(hMemDC);//─────────────────┘
		ObjPool->light1.Draw(hMemDC);//─────────────────┐
		ObjPool->light2.Draw(hMemDC);//                 전구 이미지
		ObjPool->light3.Draw(hMemDC);//                 │
		ObjPool->light4.Draw(hMemDC);//─────────────────┘
		ObjPool->asbtn13.Draw(hMemDC);//─────────────────┐
		ObjPool->asbtn14.Draw(hMemDC);//                 투명 버튼
		ObjPool->asbtn15.Draw(hMemDC);//                 │
		ObjPool->asbtn16.Draw(hMemDC);//─────────────────┘
		ObjPool->timer.Draw(hMemDC);// 타이머 이미지
		ObjPool->stop.Draw(hMemDC);// 일시정지 이미지
		ObjPool->hint.Draw(hMemDC);// 힌트(돋보기) 이미지

		if (hint4 == true) // 힌트 이미지가 마우스커서 좌표로
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX4, mouseY4);
		}
		//버튼 출력

		//텍스트(GDI) 출력
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit4);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB색 설정
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //메모리디씨, x, y, 글꼴 크기

	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);
	}

}

bool Stage_4::isCorrectCheck4()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect4[i] == false) return false;
	return true;
}


void Stage_4::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0:
		if (hp4 == 0 || timeLimit4 == 0) {//하트 3개가 다 떨어지거나 시간이 다 되면
			Stage_4::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//게임오버 화면으로 이동
		}
		if (isCorrectCheck4())//투명버튼 4개를 다 맞추면
		{
			Stage_4::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//스테이지 클리어 화면으로 이동
			ObjPool->StageBtn_4.bIsOn = true;
			ObjPool->iscleared[3] = true;
		}
		break;
	case 1: //1초마다
		if (ispaused4 == false)
		{
			timeLimit4--;
		}
		break;
	}


}

void Stage_4::OnMouseLButton(HWND hWnd, int x, int y)
{
	if (ispaused4 == false)
	{
		
		if (ObjPool->stop.isClick(x, y))	//버튼을 클릭했을 때
		{
			ispaused4 = true;
		}
		else if (ObjPool->asbtn13.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect4[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn14.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect4[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn15.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect4[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn16.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect4[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y))
		{
			hintmode4 = true;
		}

		else if (ObjPool->stage_4.isClick(x, y)) {//Stage_4라는 뒷배경을 클릭하면
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp4 == 3) {
				ObjPool->heart1.bIsOn = true;
				hp4--;
			}
			else if (hp4 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp4--;
			}
			else if (hp4 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp4--;
			}
		}
	}
	else
	{
		ispaused4 = false;
	}

}


void Stage_4::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_4::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode4 == true)
	mouseX4 = x;
	mouseY4 = y;
	if (ObjPool->asbtn13.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
	{
		if (isCorrect4[0] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
			hint4 = false;
		}
		else	hint4 = true;
	}
	else if (ObjPool->asbtn14.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
	{
		if (isCorrect4[1] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
			hint4 = false;
		}
		else	hint4 = true;
	}
	else if (ObjPool->asbtn15.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
	{
		if (isCorrect4[2] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
			hint4 = false;
		}
		else	hint4 = true;
	}
	else if (ObjPool->asbtn16.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
	{
		if (isCorrect4[3] == true) {//만약에 정답을 맞추면 힌트 출력 그만하게 하기
			hint4 = false;
		}
		else	hint4 = true;
	}

	else
	{
		hint4 = false;
	}
}

void Stage_4::OnKeyborad()
{

}