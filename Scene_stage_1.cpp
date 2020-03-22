#include "stdafx.h"
#include "Scene.h"
//Ʋ���׸�ã�� ��������1
bool isCorrect1[4] = { false, };
int hp1 = 3;
int timeLimit1 = 200;
bool ispaused1 = false;
bool hint = false;
bool hintmode = false;//��Ʈ�� �������� ���������� Ȯ��
int mouseX;
int mouseY;

void Stage_1::OnDestory() //�� �Ѿ�� �� ��ư�� ü�»��� �ʱ�ȭ
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
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn1.pos.x, ObjPool->asbtn1.pos.y + 20);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect1[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn2.pos.x + 25, ObjPool->asbtn2.pos.y + 10);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect1[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn3.pos.x + 20, ObjPool->asbtn3.pos.y + 10);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect1[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn4.pos.x + 15, ObjPool->asbtn4.pos.y + 20); // ������ ���� �� �������� Oǥ��
		}
		if (hint == true) // ��Ʈ �̹����� ���콺Ŀ�� ��ǥ��
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX, mouseY);
		}
		//��Ʈ�� ���

		ObjPool->heart1.Draw(hMemDC);//������������������������������������
		ObjPool->heart2.Draw(hMemDC);//                 ��Ʈ �̹���
		ObjPool->heart3.Draw(hMemDC);//������������������������������������
		ObjPool->light1.Draw(hMemDC);//������������������������������������
		ObjPool->light2.Draw(hMemDC);//                 ���� �̹���
		ObjPool->light3.Draw(hMemDC);//                 ��
		ObjPool->light4.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn1.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn2.Draw(hMemDC);//                 ���� ��ư
		ObjPool->asbtn3.Draw(hMemDC);//                 ��
		ObjPool->asbtn4.Draw(hMemDC);//������������������������������������
		ObjPool->timer.Draw(hMemDC);// Ÿ�̸� �̹���
		ObjPool->stop.Draw(hMemDC);// �Ͻ����� �̹���
		ObjPool->hint.Draw(hMemDC);// ��Ʈ(������) �̹���
		

		//�ؽ�Ʈ(GDI) ���
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit1);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB�� ����
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //�޸𸮵�, x, y, �۲� ũ��
	}
	else
	{
		ObjPool->stopBg.Draw(hMemDC, 0, 0);//�Ͻ����� ȭ��
	}
}

//������ üũ�ϴ� �Լ�
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
	case 0: //0.1�ʸ��� ȣ��Ǵ� Ÿ�̸�
		if (hp1 == 0 || timeLimit1 == 0) //��Ʈ 3���� �� �������ų� �ð��� �� �Ǹ�
		{
			Stage_1::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//���ӿ��� ȭ������ �̵�
		}
		if (isCorrectCheck1())//�����ư 4���� �� ���߸�
		{
			Stage_1::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);//�������� Ŭ���� ȭ������ �̵�
			ObjPool->StageBtn_1.bIsOn = true;
			ObjPool->iscleared[0] = true;
		}
		break;
	case 1: //1�ʸ��� ���ڰ� �پ���
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
		if (ObjPool->stop.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			ispaused1 = true;
			
		}
		else if (ObjPool->asbtn1.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);// ���� ��ư Ŭ���ÿ��� �򵿼Ҹ�����
			isCorrect1[0] = true;
			ObjPool->light1.bIsOn = true;// ���� ��ư Ŭ���ÿ� ������ ������
		}
		else if (ObjPool->asbtn2.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect1[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn3.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect1[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn4.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect1[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			hintmode = true;

		}

		else if (ObjPool->stage_1.isClick(x, y)) {//Stage_4��� �޹���� Ŭ���ϸ�
			sndPlaySound(L"Sound\\miss.wav", SND_ASYNC);
			if (hp1 == 3) {// ��Ʈ�� ������ ü�� ����
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
	if (hintmode == true)//��Ʈ��尡 �������� ��
	{
		mouseX = x;
		mouseY = y;
		if (ObjPool->asbtn1.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if(isCorrect1[0] ==true ){//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint = false;
			}
			else	hint = true;
		}
		else if (ObjPool->asbtn2.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect1[1] == true) {
				hint = false;
			}
			else hint = true;
		}
		else if (ObjPool->asbtn3.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{

			if (isCorrect1[2] == true) {
			hint = false;
			}
			else hint = true;
		}
		else if (ObjPool->asbtn4.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
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