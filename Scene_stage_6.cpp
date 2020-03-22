#include "stdafx.h"
#include "Scene.h"
//Ʋ���׸�ã�� ��������6
bool isCorrect6[4] = { false, };
int hp6 = 3;
int timeLimit6 = 200;
bool ispaused6 = false;
bool hint6 = false;
bool hintmode6 = false;
int mouseX6;
int mouseY6;


void Stage_6::OnDestory() //�� �Ѿ�� �� ��ư�� ü�»��� �ʱ�ȭ
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
		ObjPool->stage_6.Draw(hMemDC);//�׽�Ʈ���� ����ٰ� �������� 6���� ����� �����ϸ� ��
		if (isCorrect6[0] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn21.pos.x + 17, ObjPool->asbtn21.pos.y - 3);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect6[1] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn22.pos.x + 10, ObjPool->asbtn22.pos.y - 5);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect6[2] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn23.pos.x, ObjPool->asbtn23.pos.y - 5);// ������ ���� �� �������� Oǥ��
		}
		if (isCorrect6[3] == true)
		{
			ObjPool->Obtn.Draw(hMemDC, ObjPool->asbtn24.pos.x + 20, ObjPool->asbtn24.pos.y + 15);// ������ ���� �� �������� Oǥ��
		}
		if (hint6 == true) // ��Ʈ �̹����� ���콺Ŀ�� ��ǥ��
		{
			ObjPool->hintcursor.Draw(hMemDC, mouseX6, mouseY6);
		}
		//��Ʈ�� ���

		ObjPool->heart1.Draw(hMemDC);//������������������������������������
		ObjPool->heart2.Draw(hMemDC);//                 ��Ʈ �̹���
		ObjPool->heart3.Draw(hMemDC);//������������������������������������
		ObjPool->light1.Draw(hMemDC);//������������������������������������
		ObjPool->light2.Draw(hMemDC);//                 ���� �̹���
		ObjPool->light3.Draw(hMemDC);//                 ��
		ObjPool->light4.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn21.Draw(hMemDC);//������������������������������������
		ObjPool->asbtn22.Draw(hMemDC);//                 ���� ��ư
		ObjPool->asbtn23.Draw(hMemDC);//                 ��
		ObjPool->asbtn24.Draw(hMemDC);//������������������������������������
		ObjPool->timer.Draw(hMemDC);// Ÿ�̸� �̹���
		ObjPool->stop.Draw(hMemDC);// �Ͻ����� �̹���
		ObjPool->hint.Draw(hMemDC);// ��Ʈ(������) �̹���

		//�ؽ�Ʈ(GDI) ���
		TCHAR str[20];
		wsprintf(str, L"%d", timeLimit6);
		ObjPool->Gdi.SetTextsColor(RGB(255, 0, 0)); //RGB�� ����
		ObjPool->Gdi.Text(hMemDC, 880, 570, str, 80); //�޸𸮵�, x, y, �۲� ũ��
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
		if (hp6 == 0 || timeLimit6 == 0) {//��Ʈ 3���� �� �������ų� �ð��� �� �Ǹ�
			Stage_6::OnDestory();
			ObjPool->System.SetScene(SCENE_GAMEOVER);//���ӿ��� ȭ������ �̵�
		}
		if (isCorrectCheck6())//�����ư 4���� �� ���߸�
		{
			Stage_6::OnDestory();
			ObjPool->System.SetScene(SCENE_CLEAR);	//�������� Ŭ���� ȭ������ �̵�
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
		
		if (ObjPool->stop.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			ispaused6 = true;
		}
		else if (ObjPool->asbtn21.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect6[0] = true;
			ObjPool->light1.bIsOn = true;
		}
		else if (ObjPool->asbtn22.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect6[1] = true;
			ObjPool->light2.bIsOn = true;
		}
		else if (ObjPool->asbtn23.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect6[2] = true;
			ObjPool->light3.bIsOn = true;
		}
		else if (ObjPool->asbtn24.isClick(x, y))	//��ư�� Ŭ������ ��
		{
			sndPlaySound(L"Sound\\chime1.wav", SND_ASYNC);
			isCorrect6[3] = true;
			ObjPool->light4.bIsOn = true;
		}

		else if (ObjPool->hint.isClick(x, y))
		{
			hintmode6 = true;
		}

		else if (ObjPool->stage_6.isClick(x, y)) {//Stage_4��� �޹���� Ŭ���ϸ�
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
		if (ObjPool->asbtn21.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect6[0] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint6 = false;
			}
			else	hint6 = true;
		}
		else if (ObjPool->asbtn22.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect6[1] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint6 = false;
			}
			else	hint6 = true;
		}
		else if (ObjPool->asbtn23.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect6[2] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
				hint6 = false;
			}
			else	hint6 = true;
		}
		else if (ObjPool->asbtn24.hint(x, y))// ���콺 �����Ͱ� ��ư ��ó������ �� ��Ʈǥ��
		{
			if (isCorrect6[3] == true) {//���࿡ ������ ���߸� ��Ʈ ��� �׸��ϰ� �ϱ�
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