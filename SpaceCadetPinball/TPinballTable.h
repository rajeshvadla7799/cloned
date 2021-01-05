#pragma once

#include "TPinballComponent.h"

struct scoreStruct;
class TFlipper;
class TPlunger;
class TDrain;
class TDemo;
class objlist_class;
class TLightGroup;

struct score_struct_super
{
	scoreStruct* ScoreStruct;
	int Score;
	int ScoreE9Part;
	int Unknown2;
	int BallCount;
	int ExtraBalls;
	int BallLockedCounter;
};


class TPinballTable : public TPinballComponent
{
public:
	TPinballTable();
	~TPinballTable();
	TPinballComponent* find_component(LPCSTR componentName);
	TPinballComponent* find_component(int groupIndex);
	int AddScore(int score);
	void ChangeBallCount(int count);
	void tilt(float time);
	void port_draw() override;
	int Message(int code, float value) override;

	static void EndGame_timeout(int timerId, void* caller);
	static void LightShow_timeout(int timerId, void* caller);
	static void replay_timer_callback(int timerId, void* caller);
	static void tilt_timeout(int timerId, void* caller);

	TFlipper* FlipperL;
	TFlipper* FlipperR;
	scoreStruct* CurScoreStruct;
	scoreStruct* ScoreBallcount;
	scoreStruct* ScorePlayerNumber1;
	int UnknownP6;
	int SoundIndex1;
	int SoundIndex2;
	int SoundIndex3;
	int UnknownP10;
	int CurScore;
	int CurScoreE9;
	int LightShowTimer;
	int EndGameTimeoutTimer;
	int TiltTimeoutTimer;
	score_struct_super PlayerScores[4];
	int PlayerCount;
	int CurrentPlayer;
	TPlunger* Plunger;
	TDrain* Drain;
	TDemo* Demo;
	int XOffset;
	int YOffset;
	int Width;
	int Height;
	objlist_class* ComponentList;
	objlist_class* BallList;
	TLightGroup* LightGroup;
	float TableAngleMult;
	float TableAngle1;
	float TableAngle2;
	float CollisionCompOffset;
	int UnknownP62;
	int UnknownP63;
	int ScoreMultiplier;
	int ScoreAdded;
	int ScoreSpecial1;
	int ScoreSpecial2;
	int ScoreSpecial2Flag;
	int ScoreSpecial3;
	int ScoreSpecial3Flag;
	int UnknownP71;
	int BallCount;
	int MaxBallCount;
	int ExtraBalls;
	int UnknownP75;
	int BallLockedCounter;
	int MultiballFlag;
	int UnknownP78;
	int ReplayActiveFlag;
	int ReplayTimer;
	int UnknownP81;
	int UnknownP82;
	int TiltLockFlag;

private:
	static int score_multipliers[5];
};