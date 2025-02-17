﻿#pragma once

#define CASTLE_HEIGHT_MAX 30
#define CASTLE_WIDTH_MAX 30
#define BATTLE_HEGIHT_MAX 30
#define BATTLE_WIDTH_MAX 30

// 병사
typedef struct _tagSoldier
{
	POINT	m_tPos;

	int m_nMoveRange; // 움직임 가능

	int m_nAttackMin;	// 공격력 최소
	int m_nAttackMax;	// 공격력 최대
	int m_nAttackRange; // 공격 범위

	int m_nArmorMin; // 방어력 최소
	int m_nArmorMax; // 방어력 최대

	int m_nCurHp;	// 현재 체력
	int m_nHp;		// 최대 체력

	int m_nCurUpgrade;	// 현재 업그레이드 수준
	int m_nUpgradeMax;	// 업그레이드 최대 횟수

	int m_nDie;	// 죽었는 지 여부

	char	m_strName[24];		// 이름
	char	m_strClass[24];		// 직업
	char	m_cShape[5];		// 모양

	int		m_nType;			// 타입 ( 기병, 보병, 궁병 )
	int		m_nColor;			// 색
	int		m_nTeam;			// 플레이어 / 적군 / 동맹 판별

	int		m_bMoveFlag;		// 움직였는 지 여부
	int		m_bAttackFlag;		// 공격했는 지 여부
	int		m_bTurn;			// 턴이 존재하는 지 여부

}SOLDIER, *PSOLDIER;

typedef struct _tagMouse
{
	int x, y; // 좌표
}MOUSE, *PMOUSE;

typedef struct _tagItem
{
	int m_eItemType;	// 아이템 타입

	int m_nHpHeal;	// 체력 회복 정도
	int m_nSoldierType;	// 대상
	int m_nScopeRange;

	int m_nCount; // 아이템 개수

	struct _tagItem* m_pPrev;
	struct _tagItem* m_pNext;

}ITEM, *PITEM;

typedef struct _tagInventory
{
	PITEM	m_pBegin;
	PITEM	m_pEnd;
	int		m_nSize;

}INVENTORY, *PINVENTORY;

// 플레이어
typedef struct _tagPlayer
{
	POINT	m_tPos; // 플레이어 위치
	POINT	m_tWorldPos; // 월드 상 위치

	int		m_nMoney; // 소지 금액
	int		m_nColor; // 색상
	int		m_nHaveShip; // 물을 통과할 수 있는 지 여부
	int		m_nSelectSoldier; // 선택된 병사
	int		m_nBattleMapMode;
	int		m_nAreaCount; // 영역
	int		m_nScope;	// 볼 수 있는 거리
	int		m_nOccupiedCastle;
	int		m_nClearGame;

	MOUSE	m_tMouse;
	int		m_nMouseOn;

	char	m_cShape[3];
	SOLDIER m_tSoldiers[3]; // 병사들

	INVENTORY m_tInventory;

}PLAYER, *PPLAYER;


// 배틀 맵
typedef struct _tagBattleMap
{
	// 적군 시작 주소
	POINT m_tEnemyStartPos[3];
	// 아군 시작 주소
	POINT m_tPlayerStartPos[3];
	// 적군
	SOLDIER	m_tEnemy[3];

	int		m_nCurTurn;
	int		m_nEnemyCount;
	int		m_nRewardMin;
	int		m_nRewardMax;

	// 맵
	char m_aBattleMap[BATTLE_HEGIHT_MAX][BATTLE_WIDTH_MAX];

}BATTLEMAP, *PBATTLEMAP;


/* 적 성 */
// 문
typedef struct _tagDoor
{
	POINT m_tPos;
	int m_nClosed;

	struct _tagDoor* m_pPrev;
	struct _tagDoor* m_pNext;

}DOOR, *PDOOR;

// 지역
typedef struct _tagArea
{
	POINT m_tPos;
	int m_beOccupied;

	struct _tagArea* m_pPrev;
	struct _tagArea* m_pNext;

}AREA, *PAREA;

// 적 성문 리스트
typedef struct _tagDoorList
{
	PDOOR m_pBegin;
	PDOOR m_pEnd;

	int m_nSize;

}DLIST, *PDLIST;

// 적 성 지역 리스트
typedef struct _tagAreaList
{
	PAREA	m_pBegin;
	PAREA	m_pEnd;

	int		m_nSize;

}ALIST, *PALIST;

// 적 성
typedef struct _tagECastle
{
	POINT	m_tWorldPos;

	PDLIST	m_tDoorPosList;
	PALIST	m_tAreaPosList;

	POINT	m_tStartPos;
	POINT	m_tDestPos;
	POINT	m_tKeyPos;

	char m_aECastleMap[CASTLE_HEIGHT_MAX][CASTLE_WIDTH_MAX]; // 맵
	int m_nReward; // 보상

}ECASTLE, *PECASTLE;