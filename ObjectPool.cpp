#include "stdafx.h"
#include "ObjectPool.h"

ObjectPool* ObjectPool::pool = nullptr;

void ObjectPool::CreateObject(HWND hWnd)	//��ü�� �ʱ� ������ ���� ��
{
	startBtn.Init(hWnd, L"./Image/Start_ButtonDown.bmp", L"./Image/Start_ButtonUp.bmp", 50, 500, 350, 150, RGB(255, 0, 255));//���۹�ư
	creditBtn.Init(hWnd, L"./Image/Credit_ButtonDown.bmp", L"./Image/Credit_ButtonUp.bmp", 450, 500, 350, 150, RGB(255, 0, 255));//ũ���� ��ư
	exitBtn.Init(hWnd, L"./Image/Exit_ButtonDown.bmp", L"./Image/Exit_ButtonUp.bmp", 850, 500, 350, 150, RGB(255, 0, 255));//������ ��ư

	SoundBtn.Init(hWnd, L"./Image/SpeakerOff.bmp", L"./Image/SpeakerOn.bmp", 1130, 600, 154, 154, RGB(255, 0, 255));//������� �Ҹ� Ű�� ����
	end.Init(hWnd, L"./Image/endingdown.bmp", L"./Image/endingup.bmp", 450, 250, 353, 184, RGB(255, 0, 255));//������ư

	StageBtn_1.Init(hWnd, L"./Image/StageBtn_1.bmp", L"./Image/StageBtn_1-2.bmp", 200, 100, 125, 124, RGB(255, 0, 255));//�������� 1
	StageBtn_2.Init(hWnd, L"./Image/StageBtn_2.bmp", L"./Image/StageBtn_2-2.bmp", 200, 250, 125, 124, RGB(255, 0, 255));//�������� 2
	StageBtn_3.Init(hWnd, L"./Image/StageBtn_3.bmp", L"./Image/StageBtn_3-2.bmp", 200, 400, 125, 124, RGB(255, 0, 255));//�������� 3
	StageBtn_4.Init(hWnd, L"./Image/StageBtn_4.bmp", L"./Image/StageBtn_4-2.bmp", 900, 100, 125, 124, RGB(255, 0, 255));//�������� 4
	StageBtn_5.Init(hWnd, L"./Image/StageBtn_5.bmp", L"./Image/StageBtn_5-2.bmp", 900, 250, 125, 124, RGB(255, 0, 255));//�������� 5
	StageBtn_6.Init(hWnd, L"./Image/StageBtn_6.bmp", L"./Image/StageBtn_6-2.bmp", 900, 400, 125, 124, RGB(255, 0, 255));//�������� 6

	mainBtn.Init(hWnd, L"./Image/back.bmp", L"./Image/back.bmp", 1100, 550, 151, 157, RGB(255, 0, 255));//Ÿ ȭ�� -> ���� ȭ��
	home.Init(hWnd, L"./Image/home.bmp", L"./Image/home.bmp", 1000, 550, 151, 157, RGB(255, 0, 255));//Ÿȭ�� -> ������������ ȭ��
	back.Init(hWnd, L"./Image/back.bmp", L"./Image/back.bmp", 100, 550, 151, 157, RGB(255, 0, 255));

    stage_1.Init(hWnd, L"./Image/color.bmp", L"./Image/color.bmp", 0, 0, 1280, 720, RGB(255, 0, 255));//�������� ���
	stage_2.Init(hWnd, L"./Image/house.bmp", L"./Image/house.bmp", 0, 0, 1280, 720, RGB(255, 0, 255));//�������� ���
	stage_3.Init(hWnd, L"./Image/machine.bmp", L"./Image/machine.bmp", 0, 0, 1280, 720, RGB(255, 0, 255));//�������� ���
	stage_4.Init(hWnd, L"./Image/food.bmp", L"./Image/food.bmp", 0, 0, 1280, 720, RGB(255, 0, 255));//�������� ���
	stage_5.Init(hWnd, L"./Image/animal.bmp", L"./Image/animal.bmp", 0, 0, 1280, 720, RGB(255, 0, 255));//�������� ���
	stage_6.Init(hWnd, L"./Image/grass.bmp", L"./Image/grass.bmp", 0, 0, 1280, 720, RGB(255, 0, 255));//�������� ���


	heart1.Init(hWnd, L"./Image/heartON.bmp", L"./Image/heartOFF.bmp", 10, 450, 111, 171, RGB(255, 0, 255));//��������������������������������������
	heart2.Init(hWnd, L"./Image/heartON2.bmp", L"./Image/heartOFF2.bmp", 160, 450, 111, 171, RGB(255, 0, 255));//               ��Ʈ
	heart3.Init(hWnd, L"./Image/heartON3.bmp", L"./Image/heartOFF3.bmp", 85, 550, 111, 171, RGB(255, 0, 255));//����������������������������������

	light1.Init(hWnd, L"./Image/lightOFF.bmp", L"./Image/lightON.bmp", 310, 450, 111, 171, RGB(255, 0, 255));//��������������������������������������
	light2.Init(hWnd, L"./Image/lightOFF2.bmp", L"./Image/lightON2.bmp", 460, 450, 111, 171, RGB(255, 0, 255));//                ��
	light3.Init(hWnd, L"./Image/lightOFF3.bmp", L"./Image/lightON3.bmp", 310, 570, 111, 171, RGB(255, 0, 255));//               ����
	light4.Init(hWnd, L"./Image/lightOFF4.bmp", L"./Image/lightON4.bmp", 460, 570, 111, 171, RGB(255, 0, 255));//����������������������������������

	stop.Init(hWnd, L"./Image/stop.bmp", L"./Image/stop.bmp", 1100, 520, 154, 154, RGB(255, 0, 255));// �Ͻ����� ��ư

	hint.Init(hWnd, L"./Image/hint.bmp", L"./Image/hint.bmp", 630, 520, 111, 171, RGB(255, 0, 255));// ��Ʈ ��ư
	timer.Init(hWnd, L"./Image/timer.bmp", L"./Image/timer.bmp", 770, 520, 111, 171, RGB(255, 0, 255));// Ÿ�̸� ��ư

	asbtn1.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1175, 150, 75, 75, RGB(255, 0, 255));//��������������������������������������
	asbtn2.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 730, 200, 75, 75, RGB(255, 0, 255));//                   ��
	asbtn3.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1060, 420, 75, 75, RGB(255, 0, 255));//                  ��
	asbtn4.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1200, 400, 75, 75, RGB(255, 0, 255));//                  ��
																								 //                  ��
	asbtn5.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1175, 80, 75, 75, RGB(255, 0, 255));//                   ��
	asbtn6.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1000, 150, 75, 75, RGB(255, 0, 255));//                  ��
	asbtn7.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 750, 275, 75, 75, RGB(255, 0, 255));//                   ��
	asbtn8.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1100, 350, 75, 75, RGB(255, 0, 255));//                  ��
																								 //                  ��
	asbtn9.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 620, 20, 75, 75, RGB(255, 0, 255));//                    ��
	asbtn10.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 950, 20, 75, 75, RGB(255, 0, 255));//                   ��
	asbtn11.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1100, 175, 75, 75, RGB(255, 0, 255));//                 ��
	asbtn12.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1150, 350, 75, 75, RGB(255, 0, 255));//                ���� ��ư
						   					                                                      //                 ��
	asbtn13.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 875, 10, 75, 75, RGB(255, 0, 255));//                   ��
	asbtn14.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1150, 200, 75, 75, RGB(255, 0, 255));//                 ��
	asbtn15.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1200, 280, 75, 75, RGB(255, 0, 255));//                 ��
	asbtn16.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1050, 280, 75, 75, RGB(255, 0, 255));//                 ��
																								  //                 ��
	asbtn17.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1200, 40, 75, 75, RGB(255, 0, 255));//                  ��
	asbtn18.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1100, 100, 75, 75, RGB(255, 0, 255));//                 ��
	asbtn19.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 855, 120, 75, 75, RGB(255, 0, 255));//                  ��
	asbtn20.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 750, 250, 75, 75, RGB(255, 0, 255));//                  ��
																								 //                  ��
	asbtn21.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 800, 10, 75, 75, RGB(255, 0, 255));//                   ��
	asbtn22.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 630, 310, 75, 75, RGB(255, 0, 255));//                  ��
	asbtn23.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1230, 305, 75, 75, RGB(255, 0, 255));//                 ��
	asbtn24.Init(hWnd, L"./Image/as.bmp", L"./Image/as.bmp", 1100, 400, 75, 75, RGB(255, 0, 255));//������������������������������������

	titleBg.Init(hWnd, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, L"./Image/titleBg.bmp");//Ÿ��Ʋ ȭ��
	stagechooseBg.Init(hWnd, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, L"./Image/stagechooseBg.bmp");//�������� ���� ȭ��
	creditBg.Init(hWnd, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, L"./Image/creditBg.bmp");// ũ���� ���
	ClearBg.Init(hWnd, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, L"./Image/Clear.bmp");//�������� Ŭ���� ���
	FinalBg.Init(hWnd, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, L"./Image/Final.bmp");//���� ���
	Game_OverBg.Init(hWnd, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, L"./Image/Game_Over.bmp");//���ӿ��� ���
	stopBg.Init(hWnd, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, L"./Image/stopbg.bmp");//�Ͻ����� ���
	hintcursor.Init(hWnd, 0, 0, 100, 100, L"./Image/hintcursor.bmp");//��Ʈ��ư�� Ŭ���Ͽ����� �ٲ�¸��콺 Ŀ��

	Obtn.Init(hWnd, 0, 0, 50, 50, L"./Image/O.bmp");//���� ����� ��Ÿ����O��ư


}

void ObjectPool::DeleteObject()				//��Ʈ�ʰ�ü�� �ݵ�� �������ֱ�
{
	titleBg.Ternimate();
}
