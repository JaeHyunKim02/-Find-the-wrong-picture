#include "stdafx.h"
#include "Scene.h"
//틀린그림찾기 스테이지1
bool isCorrect1[4] = { false, };
int hp1 = 3;
int timeLimit1 = 200;
bool ispaused1 = false;
bool hint = false;
bool hintmode = false;//힌트가 켜지는지 안켜지는지 확인
int mouseX;
int mouseY;

void Stage_1::OnDestory() //씬 넘어가기 전 버튼과 체력상태 초기화
{

	hintmode = false;
	hint = false;
	timeLimit1 = 200;
	hp1 = 3;
	ObjPool->light1.bIsOn = false;
	ObjPool->light2.bIsOn = false;
	ObjPool->light3.bIsOn = false;
	ObjPool->light4.bIsOn = false;
	ObjPool->heart1.bIsOn = false;
	ObjPool->heart2.bIsOn = false;
	ObjPool->heart3.bIsOn = false;
	isCorrect1[0] = false;
	isCorrect1[1] = false;
	isCorrect1[2] = false;
	isCorrect1[3] = false;
}

void Stage_1::Draw(HDC hMemDC)
{
	if (ispaused1 == false) {
		ObjPool->stage_1.Draw(hMemDC);
		if (isCorrect1[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn1.pos.x, ObjPool->asbtn1.pos.y + 20);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect1[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn2.pos.x + 25, ObjPool->asbtn2.pos.y + 10);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect1[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn3.pos.x + 20, ObjPool->asbtn3.pos.y + 10);// 정답을 맞출 시 정답위에 O표시
		}
		if (isCorrect1[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn4.pos.x + 15, ObjPool->asbtn4.pos.y + 20); // 정답을 맞출 시 정답위에 O표시
		}
		if (hint == true) // 힌트 이미지가 마우스커서 좌표로
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX, mouseY);
		}
		//비트맵 출력

		ObjPool->heart1.Draw(hMemDC);//─────────────────┐
		ObjPool->heart2.Draw(hMemDC);//                 하트 이미지
		ObjPool->heart3.Draw(hMemDC);//─────────────────┘
		ObjPool->light1.Draw(hMemDC);//─────────────────┐
		ObjPool->light2.Draw(hMemDC);//                 전구 이미지
		ObjPool->light3.Draw(hMemDC);//                 │
		ObjPool->light4.Draw(hMemDC);//─────────────────┘
		ObjPool->asbtn1.Draw(hMemDC);//─────────────────┐
		ObjPool->asbtn2.Draw(hMemDC);//                 투명 버튼
		ObjPool->asbtn3.Draw(hMemDC);//                 │
		ObjPool->asbtn4.Draw(hMemDC);//─────────────────┘
		ObjPool->timer.Draw(hMemDC);// 타이머 이미지
		ObjPool->stop.Draw(hMemDC);// 일시정지 이미지
		ObjPool->hint.Draw(hMemDC);// 힌트(돋보기) 이미지
		

		//텍스트(GDI) 출력
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit1);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB색 설정
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //메모리디씨, x, y, 글꼴 크기
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);//일시정지 화면
	}
}

//정답을 체크하는 함수
bool Stage_1::isCorrectCheck1()
{
	for (int i = 0; i < 4; i++)
		if (isCorrect1[i] == false) return false;
	return true;
}

void Stage_1::OnTimer(HWND hWnd, int timer)
{
	switch (timer)
	{
	case 0: //0.1초마다 호출되는 타이머
		if (hp1 == 0 || timeLimit1 == 0) //하트 3개가 다 떨어지거나 시간이 다 되면
		{
			Stage_1::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//게임오버 화면으로 이동
		}
		if (isCorrectCheck1())//투명버튼 4개를 다 맞추면
		{
			Stage_1::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);//스테이지 클리어 화면으로 이동
			ObjPool->StageBtn_1.bIsOn = true;
			ObjPool->iscleared[0] = true;
		}
		break;
	case 1: //1초마다 숫자가 줄어든다
		if (ispaused1 == false)
		{
			timeLimit1--;
		}
		break;
	}
}

void Stage_1::OnMouseLButton(HWND hWnd, int x, int y)
{
	
	
	if (ispaused1 == false) {
		if (ObjPool->stop.isClick(x, y))	//버튼을 클릭했을 때
		{
			ispaused1 = true;
			
		}
		else if (ObjPool->asbtn1.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);// 투명 버튼 클릭시에만 띵동소리가남
			isCorrect1[0] = true;
			ObjPool->light1.bIsOn = true;// 투명 버튼 클릭시에 전구가 켜진다
		}
		else if (ObjPool->asbtn2.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect1[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn3.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect1[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn4.isClick(x, y))	//버튼을 클릭했을 때
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect1[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y))	//버튼을 클릭했을 때
		{
			hintmode = true;

		}

		else if (ObjPool->stage_1.isClick(x, y)) {//Stage_4라는 뒷배경을 클릭하면
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp1 == 3) {// 하트가 꺼지며 체력 감소
				ObjPool->heart1.bIsOn = true;
				hp1--;
			}
			else if (hp1 == 2) {
				ObjPool->heart2.bIsOn = true;
				hp1--;
			}
			else if (hp1 == 1) {
				ObjPool->heart3.bIsOn = true;
				hp1--;
			}
		}
	}
	else
	{
		ispaused1 = false;
	}
}

void Stage_1::OnMouseRButton(HWND hWnd, int x, int y)
{

}

void Stage_1::OnMouseMove(HWND hWnd, int x, int y)
{
	if (hintmode == true)//힌트모드가 켜져있을 때
	{
		mouseX = x;
		mouseY = y;
		if (ObjPool->asbtn1.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if(isCorrect1[0] ==true ){//만약에 정답을 맞추면 힌트 출력 그만하게 하기
				hint = false;
			}
			else	hint = true;
		}
		else if (ObjPool->asbtn2.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect1[1] == true) {
				hint = false;
			}
			else hint = true;
		}
		else if (ObjPool->asbtn3.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{

			if (isCorrect1[2] == true) {
			hint = false;
			}
			else hint = true;
		}
		else if (ObjPool->asbtn4.hint(x, y))// 마우스 포인터가 버튼 근처에있을 때 힌트표시
		{
			if (isCorrect1[3] == true) {
				hint = false;
			}
			else hint = true;
		}
		else
		{
			hint = false;
		}
	}
}

void Stage_1::OnKeyborad()
{

}