#pragma once

class Button	//버튼!
{
public:
	Button() { }
	~Button() { }

public:
	bool bIsOn = false;	//온이 되었는가?
	RECT rect;

	HDC hdcImg;				//미리 그려둘 비트맵의 DC
	HBITMAP ButtonUp;		//비트맵
	HBITMAP ButtonDown;		//비트맵
	COLORREF SpriteColor;	//투명화 컬러 (마젠타가 기본)
	POINT pos;				//좌표
	int w;					//너비
	int h;					//높이

	std::function<void()> m_Func;

public:
	void Init(HWND hWnd, LPCWSTR szUp, LPCWSTR szDown, int x, int y, int w, int h, COLORREF sprite); //초기화
	void Draw(HDC hMemDC);	//그리기

	void SetRect(RECT rt);	//위치 변경

	bool isOver(int x, int y);	//마우스가 올라왔는지
	bool hint(int x, int y);
	bool isClick(int x, int y);	//클릭이 되었는지
};
