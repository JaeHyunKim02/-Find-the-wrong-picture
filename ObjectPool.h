#pragma once
//#include "Sprite.h"
#include "GdiObj.h"
#include "SystemObj.h"
#include "ButtonObj.h"
#include "BitmapObj.h"

class ObjectPool		//오브젝트 풀 (전역변수같이 사용됨)
{
private:
	ObjectPool(void) { }
	~ObjectPool(void) { }
	static ObjectPool *pool;

public:
	static ObjectPool *getInstance()	//싱글톤 적용
	{
		if (!pool)
			pool = new ObjectPool;
		return pool;
	}

public:
	void CreateObject(HWND hWnd);		//초기화 (hWnd는 비트맵때문에 받아줘야 합니다)
	void DeleteObject();				//종료

public:
	System System;	//시스템 변수를 넣어두는 곳 
	Gdi Gdi;		//그리기 함수를 사용하는 곳

	// title scene
public:

	bool iscleared[6];

	Button startBtn;	//버튼 (Rectangle로 그리지만 위치나 버튼 상태를 체크해야하므로 객체로 만듬)
	Button helpBtn;
	Button creditBtn;
	Button exitBtn;
	Button StageBtn_1;
	Button StageBtn_2;
	Button StageBtn_3;
	Button StageBtn_4;
	Button StageBtn_5;
	Button StageBtn_6;
	Button mainBtn;
	Button heart1;//------┐
	Button heart2;//       생명
	Button heart3;//------┘
	Button light1;//-----------------------┐
	Button light2;//        총 정답 확인 여부(전구)
	Button light3;//                       │
	Button light4;//-----------------------┘
	Button asbtn1;//-----------------------┐
	Button asbtn2;//                       │
	Button asbtn3;//                       │
	Button asbtn4;//                       │
	Button asbtn5;//                       │
	Button asbtn6;//                       │
	Button asbtn7;//                       │
	Button asbtn8;//                       │
	Button asbtn9;//                       │
	Button asbtn10;//                      │
	Button asbtn11;//                      │
	Button asbtn12;//                      │
	Button asbtn13;//                      │
	Button asbtn14;//               정답위치 확인 여부(동그라미)
	Button asbtn15;//                      │
	Button asbtn16;//                      │
	Button asbtn17;//                      │
	Button asbtn18;//                      │
	Button asbtn19;//                      │
	Button asbtn20;//                      │
	Button asbtn21;//                      │
	Button asbtn22;//                      │
	Button asbtn23;//                      │
	Button asbtn24;//----------------------┘
	Button stop;// 일시 정지
	Button timer;//타이머 이미지
	Button hint;//힌트 이미지
	Button ex;//투명 버튼 위치 지정을 위한 이미지
	Button stage_1;//기계
	Button stage_2;//색연필
	Button stage_3;//집
	Button stage_4;//햄버거
	Button stage_5;//얼룩말
	Button stage_6;//풀때기
	Button home;
	Button back;
	Button end;
	Button SoundBtn;

	Bitmap titleBg;		//비트맵
	Bitmap creditBg;
	Bitmap ingameBg;
	Bitmap helpBg;
	Bitmap ClearBg;
	Bitmap FinalBg;
	Bitmap Game_OverBg;
	Bitmap stagechooseBg;
	Bitmap stopBg;
	Bitmap Obtn;//동그라미
	Bitmap Xbtn;//엑스
	Bitmap hintcursor;

};
