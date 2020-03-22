#include "stdafx.h"
#include "ButtonObj.h"

void Button::SetRect(RECT rt)
{
	rect.left = rt.left;
	rect.top = rt.top;
	rect.right = rt.right;
	rect.bottom = rt.bottom;
}

void Button::Init(HWND hWnd, LPCWSTR szUp, LPCWSTR szDown, int x, int y, int w, int h, COLORREF sprite)
{
	hdcImg = CreateCompatibleDC(GetDC(hWnd));	//그릴 DC를 생성

	SetRect({ x, y, x + w, y + h }); //LEFT와 RIGHT는 x값을 받고, TOP과 BOTTOM은 Y값을 받으므로.

	WCHAR str[128];
	wsprintf(str, szUp);
	ButtonUp = (HBITMAP)LoadImage(NULL, szUp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //이미지 경로로부터 이미지 받아오기

	wsprintf(str, szDown);
	ButtonDown = (HBITMAP)LoadImage(NULL, szDown, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	if (ButtonUp == NULL || ButtonDown == NULL) //이미지가 없으면
	{
		MessageBox(NULL, L"이미지가 없습니다.", L"에러!!!", MB_OK);	//이미지불러오기 실패
		exit(0);
	}

	pos.x = x; //그림을 띄울 좌표와
	pos.y = y;
	this->w = w; //그림의 너비, 높이를 지정
	this->h = h;

	SpriteColor = sprite; //마젠타 빼주기
}

void Button::Draw(HDC hMemDC)
{
	if (!bIsOn)	//온 여부에 따라서 어떤 브러쉬를 적용 할 것인지 체크
	{
		SelectObject(hdcImg, ButtonUp);	//미리 만들어둔 DC에 불러온 비트맵을 설정
		TransparentBlt(hMemDC, pos.x, pos.y, w, h, hdcImg, 0, 0, w, h, SpriteColor);	//받아온 후면DC에 비트맵을 불러온 DC를 복사
	}
	else
	{
		SelectObject(hdcImg, ButtonDown);	//미리 만들어둔 DC에 불러온 비트맵을 설정
		TransparentBlt(hMemDC, pos.x, pos.y, w, h, hdcImg, 0, 0, w, h, SpriteColor);	//받아온 후면DC에 비트맵을 불러온 DC를 복사
	}

	//받은 후면DC에 그린다
	//Rectangle(hMemDC, rect.left, rect.top, rect.right, rect.bottom);

	//잊지않게 지워주기
}

bool Button::isOver(int x, int y)	//마우스오버 체크
{
	if ((rect.left <= x) && (x <= rect.right) && (rect.top <= y) && (y <= rect.bottom))
	{
		bIsOn = true;
		return true;
	}
	bIsOn = false;
	return false;
}

bool Button::hint(int x, int y)	//마우스오버 체크
{
	if ((rect.left-25 <= x) && (x <= rect.right+25) && (rect.top-25 <= y) && (y <= rect.bottom+25))
	{
		return true;
	}
	return false;
}

bool Button::isClick(int x, int y)	//마우스오버와 같은 함수인데 또 만든이유는 함수의 이름을 다르게 하여 보기 편함을 위해
{									//아니면 마우스오버 색 외에 클릭 색도 추가하여 오버가 되었는지, 클릭이 되었는지 체크할 수 있음
	if ((rect.left <= x) && (x <= rect.right) && (rect.top <= y) && (y <= rect.bottom))
	{
		return true;
	}
	return false;
}