#pragma once
//#include "Sprite.h"
#include "GdiObj.h"
#include "SystemObj.h"
#include "ButtonObj.h"
#include "BitmapObj.h"

class ObjectPool		//������Ʈ Ǯ (������������ ����)
{
private:
	ObjectPool(void) { }
	~ObjectPool(void) { }
	static ObjectPool *pool;

public:
	static ObjectPool *getInstance()	//�̱��� ����
	{
		if (!pool)
			pool = new ObjectPool;
		return pool;
	}

public:
	void CreateObject(HWND hWnd);		//�ʱ�ȭ (hWnd�� ��Ʈ�ʶ����� �޾���� �մϴ�)
	void DeleteObject();				//����

public:
	System System;	//�ý��� ������ �־�δ� �� 
	Gdi Gdi;		//�׸��� �Լ��� ����ϴ� ��

	// title scene
public:

	bool iscleared[6];

	Button startBtn;	//��ư (Rectangle�� �׸����� ��ġ�� ��ư ���¸� üũ�ؾ��ϹǷ� ��ü�� ����)
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
	Button heart1;//------��
	Button heart2;//       ����
	Button heart3;//------��
	Button light1;//-----------------------��
	Button light2;//        �� ���� Ȯ�� ����(����)
	Button light3;//                       ��
	Button light4;//-----------------------��
	Button asbtn1;//-----------------------��
	Button asbtn2;//                       ��
	Button asbtn3;//                       ��
	Button asbtn4;//                       ��
	Button asbtn5;//                       ��
	Button asbtn6;//                       ��
	Button asbtn7;//                       ��
	Button asbtn8;//                       ��
	Button asbtn9;//                       ��
	Button asbtn10;//                      ��
	Button asbtn11;//                      ��
	Button asbtn12;//                      ��
	Button asbtn13;//                      ��
	Button asbtn14;//               ������ġ Ȯ�� ����(���׶��)
	Button asbtn15;//                      ��
	Button asbtn16;//                      ��
	Button asbtn17;//                      ��
	Button asbtn18;//                      ��
	Button asbtn19;//                      ��
	Button asbtn20;//                      ��
	Button asbtn21;//                      ��
	Button asbtn22;//                      ��
	Button asbtn23;//                      ��
	Button asbtn24;//----------------------��
	Button stop;// �Ͻ� ����
	Button timer;//Ÿ�̸� �̹���
	Button hint;//��Ʈ �̹���
	Button ex;//���� ��ư ��ġ ������ ���� �̹���
	Button stage_1;//���
	Button stage_2;//������
	Button stage_3;//��
	Button stage_4;//�ܹ���
	Button stage_5;//��踻
	Button stage_6;//Ǯ����
	Button home;
	Button back;
	Button end;
	Button SoundBtn;

	Bitmap titleBg;		//��Ʈ��
	Bitmap creditBg;
	Bitmap ingameBg;
	Bitmap helpBg;
	Bitmap ClearBg;
	Bitmap FinalBg;
	Bitmap Game_OverBg;
	Bitmap stagechooseBg;
	Bitmap stopBg;
	Bitmap Obtn;//���׶��
	Bitmap Xbtn;//����
	Bitmap hintcursor;

};
