#pragma once

#define MAX_SCENENUM	16

enum eSCENE	//�� �̳�
{
	SCENE_TITLE,
	SCENE_INGAME,
	SCENE_CREDIT,
	SCENE_HELP,
	SCENE_STAGE_1,
	SCENE_STAGE_2,
	SCENE_STAGE_3,
	SCENE_STAGE_4,
	SCENE_STAGE_5,
	SCENE_STAGE_6,

	SCENE_CLEAR,
	SCENE_FINAL,
	SCENE_GAMEOVER,

	SCENE_NULL = MAX_SCENENUM
};

class Scene
{
public:
	Scene() { }
	~Scene() { }

private:
	eSCENE scene;	//�� �ѹ�
	int evnt;		//�̺�Ʈ �ѹ�

public:
	virtual void SetScene(eSCENE num) {
		scene = num;
	}

	virtual eSCENE GetScene() {
		return scene;
	}

	virtual void SetEvent(int num) {
		evnt = num;
	}

	virtual int GetEvent() {
		return evnt;
	}
};