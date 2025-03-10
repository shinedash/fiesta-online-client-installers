//***********************************************************************************
//
//	File		:	NtlBattle.h
//
//	Begin		:	2006-04-24
//
//	Copyright	:	ⓒ NTL-Inc Co., Ltd
//
//	Author		:	Hyun Woo, Koo   ( zeroera@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once

#include "NtlBitFlag.h"
#include "NtlObject.h"

// Damage Type
enum eDBO_DAMAGE_TYPE
{
	DBO_DAMAGE_TYPE_PHYSICAL, //physical damage
	DBO_DAMAGE_TYPE_ENERGY, //energy damage

	DBO_DAMAGE_TYPE_COUNT,

	DBO_DAMAGE_TYPE_INVALID = 0xFF,

	DBO_DAMAGE_TYPE_FIRST = DBO_DAMAGE_TYPE_PHYSICAL,
	DBO_DAMAGE_TYPE_LAST = DBO_DAMAGE_TYPE_ENERGY
};

// Attack Type
enum eBATTLE_ATTACK_TYPE
{
	BATTLE_ATTACK_TYPE_PHYSICAL, //melee
	BATTLE_ATTACK_TYPE_ENERGY, //range

	BATTLE_ATTACK_TYPE_COUNT,

	BATTLE_ATTACK_TYPE_INVALID = 0xFF
};


// Attack Results
enum eBATTLE_ATTACK_RESULT
{
	BATTLE_ATTACK_RESULT_HIT, // General Attack
	BATTLE_ATTACK_RESULT_CRITICAL_HIT, // Critical Attack
	BATTLE_ATTACK_RESULT_DODGE, // Dodge attack
	BATTLE_ATTACK_RESULT_RESISTED, // resist attack
	BATTLE_ATTACK_RESULT_BLOCK, // block attack
	BATTLE_ATTACK_RESULT_REFLECTED_DAMAGE, // Reflected damage from the target
	BATTLE_ATTACK_RESULT_KNOCKDOWN, // Knockdown
	BATTLE_ATTACK_RESULT_SLIDING, // Sliding
	BATTLE_ATTACK_RESULT_IMMUNE, //immune

	BATTLE_ATTACK_RESULT_COUNT,

	BATTLE_ATTACK_RESULT_FIRST = BATTLE_ATTACK_RESULT_HIT,
	BATTLE_ATTACK_RESULT_LAST = BATTLE_ATTACK_RESULT_IMMUNE
};

enum eNPC_NEST_TYPE
{
	NPC_NEST_TYPE_DEFAULT,
	NPC_NEST_TYPE_FIX,
	NPC_NEST_TYPE_COUNT,
	INVALID_NPC_NEST_TYPE = 0xFF,
};

// Combat property
enum eBATTLE_ATTRIBUTE
{
	BATTLE_ATTRIBUTE_NONE, 
	BATTLE_ATTRIBUTE_HONEST, 
	BATTLE_ATTRIBUTE_STRANGE,
	BATTLE_ATTRIBUTE_WILD, 
	BATTLE_ATTRIBUTE_ELEGANCE, 
	BATTLE_ATTRIBUTE_FUNNY,

	BATTLE_ATTRIBUTE_COUNT,
	BATTLE_ATTRIBUTE_UNKNOWN	= 0xFF,

	BATTLE_ATTRIBUTE_FIRST = BATTLE_ATTRIBUTE_NONE,
	BATTLE_ATTRIBUTE_LAST = BATTLE_ATTRIBUTE_FUNNY
};


// when char die reason
enum eFAINT_REASON
{
	FAINT_REASON_HIT, // by hit 
	FAINT_REASON_SKILL, // by skill
	FAINT_REASON_BUFF, // by buff
	FAINT_REASON_KNOCKDOWN, // by knockdown
	FAINT_REASON_SLIDING, // by knockdown
	FAINT_REASON_COMMAND, // by command
	FAINT_REASON_HTB, // by htb
	FAINT_REASON_REMOVE, // Due to the elimination of death (used in TMQ)
	FAINT_REASON_SELF_FAINTING, // Fainting due to self-destruct skill

	FAINT_REASON_COUNT,

	FAINT_REASON_UNKNOWN = 0xFF
};


enum eMOB_FAINT_BUFF_TYPE
{
	eMOB_FAINT_BUFF_SLAYER,
	eMOB_FAINT_BUFF_PARTY
};


//-----------------------------------------------------------------------------------
// NEW NEW NEW 4.12.2014
//-----------------------------------------------------------------------------------
#pragma pack(push, 1)
struct sDBO_BATTLE_STATISTICS
{
	int	aBattleStatisticsLp[9];
};
#pragma pack(pop)

// HTB 관련 정의
enum eHTB_SKILL_TYPE
{
	HTB_SKILL_NONE,
	HTB_SKILL_DASH,			// htb를 처음 시작할 때 client가 target에 dash 이동으로 가까이 접근한다.(자연스러운 연출을 위하여)
	HTB_SKILL_HOMING_UP,	// attacker가 target을 따라서 올라간다.
	HTB_SKILL_HOMING_DOWN,	// attacket가 지면으로 다시 내려온다.
	HTB_SKILL_JUMPING_UP,	// 공중 12m 높이로 무조건 올라간다
	HTB_SKILL_JUMPING_DOWN,	// 공중 12m 높이에서 무조건 내려온다

	HTB_SKILL_TYPE_UNKNOWN	= 0xFF,

	HTB_SKILL_TYPE_FIRST = HTB_SKILL_NONE,
	HTB_SKILL_TYPE_TYPE_LAST  = HTB_SKILL_JUMPING_DOWN
};


// 프리배틀 결과
enum eFREEBATTLE_RESULT
{
	FREEBATTLE_RESULT_WIN, // 대전중에 한명이 HP가 0이 되어 승리함
	FREEBATTLE_RESULT_LOSE, // 대전중에 한명이 대전범위를 벗어나 승리함
	FREEBATTLE_RESULT_DRAW, // 시간이 경과되어 무승부가 ?

	FREEBATTLE_RESULT_COUNT
};


// 공격 액션 정의
enum eATTACK_ACTION
{
	ATTACK_ACTION_HTB,
	ATTACK_ACTION_PUSH,
	ATTACK_ACTION_KNOCKDOWN,
	ATTACK_ACTION_ACTIVE_PULL,

	MAX_ATTACK_ACTION,
	INVALID_ATTACK_ACTION,
};

// 공격 액션 플래그
enum eATTACK_ACTION_FLAG
{
	ATTACK_ACTION_FLAG_HTB			= MAKE_BIT_FLAG( ATTACK_ACTION_HTB ),
	ATTACK_ACTION_FLAG_PUSH			= MAKE_BIT_FLAG( ATTACK_ACTION_PUSH ),
	ATTACK_ACTION_FLAG_KNOCKDOWN	= MAKE_BIT_FLAG( ATTACK_ACTION_KNOCKDOWN ),
	ATTACK_ACTION_FLAG_ACTIVE_PULL	= MAKE_BIT_FLAG( ATTACK_ACTION_ACTIVE_PULL ),
};

enum eDBO_AGGRO_CHANGE_TYPE
{
	DBO_AGGRO_CHANGE_TYPE_INCREASE,
	DBO_AGGRO_CHANGE_TYPE_DECREASE,
	DBO_AGGRO_CHANGE_TYPE_HIGHEST,
	DBO_AGGRO_CHANGE_TYPE_LOWEST,

	DBO_AGGRO_CHANGE_TYPE_PERCENT,
	DBO_AGGRO_CHANGE_TYPE_HIGHEST_PERCENT,
	DBO_AGGRO_CHANGE_TYPE_LOWEST_PERCENT,

	DBO_AGGRO_CHANGE_TYPE_COUNT,

	DBO_AGGRO_CHANGE_TYPE_FIRST = DBO_AGGRO_CHANGE_TYPE_INCREASE,
	DBO_AGGRO_CHANGE_TYPE_LAST = DBO_AGGRO_CHANGE_TYPE_COUNT - 1,
};

enum eDBO_BATTLE_STATISTICS_LP_TYPE
{
	DBO_BATTLE_STATISTICS_LP_TYPE_DAMAGE_DONE,
	DBO_BATTLE_STATISTICS_LP_TYPE_DAMAGE_GET,
	DBO_BATTLE_STATISTICS_LP_TYPE_HEAL_DONE,
	DBO_BATTLE_STATISTICS_LP_TYPE_HEAL_GET,
	DBO_BATTLE_STATISTICS_LP_TYPE_STOLEN_LP,
	DBO_BATTLE_STATISTICS_LP_TYPE_REGEN,
	DBO_BATTLE_STATISTICS_LP_TYPE_AUTO_HEAL,
	DBO_BATTLE_STATISTICS_LP_TYPE_ETC_PLUS,
	DBO_BATTLE_STATISTICS_LP_TYPE_ETC_MINUS,

	DBO_BATTLE_STATISTICS_LP_TYPE_COUNT,
	DBO_BATTLE_STATISTICS_LP_TYPE_INVALID = 0xFF,
	DBO_BATTLE_STATISTICS_LP_TYPE_FIRST = DBO_BATTLE_STATISTICS_LP_TYPE_DAMAGE_DONE,
	DBO_BATTLE_STATISTICS_LP_TYPE_LAST = DBO_BATTLE_STATISTICS_LP_TYPE_ETC_MINUS,
};

enum eDBO_SPECIAL_ATTACK_TYPE
{
	DBO_SPECIAL_ATTACK_TYPE_SPINNING_ATTACK,
	DBO_SPECIAL_ATTACK_TYPE_ROLLING_ATTACK ,
	DBO_SPECIAL_ATTACK_TYPE_CURSE_REFLECT,

	DBO_SPECIAL_ATTACK_TYPE_COUNT,
	DBO_SPECIAL_ATTACK_TYPE_INVALID = 0xFF,
	DBO_SPECIAL_ATTACK_TYPE_FIRST = DBO_SPECIAL_ATTACK_TYPE_SPINNING_ATTACK,
	DBO_SPECIAL_ATTACK_TYPE_LAST = DBO_SPECIAL_ATTACK_TYPE_CURSE_REFLECT,
};

enum eDBO_BATTLE_LP_CHANGE_TYPE
{
	DBO_BATTLE_LP_CHANGE_TYPE_DAMAGE,
	DBO_BATTLE_LP_CHANGE_TYPE_HEAL,
	DBO_BATTLE_LP_CHANGE_TYPE_STOLEN_LP,
	DBO_BATTLE_LP_CHANGE_TYPE_REGEN,
	DBO_BATTLE_LP_CHANGE_TYPE_AUTO_HEAL,
	DBO_BATTLE_LP_CHANGE_TYPE_ETC,

	DBO_BATTLE_LP_CHANGE_TYPE_COUNT,
	DBO_BATTLE_LP_CHANGE_TYPE_INVALID = 0xFF,
	DBO_BATTLE_LP_CHANGE_TYPE_FIRST = DBO_BATTLE_LP_CHANGE_TYPE_DAMAGE,
	DBO_BATTLE_LP_CHANGE_TYPE_LAST = DBO_BATTLE_LP_CHANGE_TYPE_ETC,
};

//TODO !
enum eIMMUNITY_FLAG
{
	/*-THESE EXIST
		IMMUNITY_FLAG_MIND
		IMMUNITY_FLAG_BODY
	*/

	IMMUNITY_FLAG_CHARGE_BLOCK, //maybe
	IMMUNITY_FLAG_TAUNT, // maybe
	IMMUNITY_FLAG_PARALYZE,
	IMMUNITY_FLAG_CONFUSION,
	IMMUNITY_FLAG_FEAR, 
	IMMUNITY_FLAG_STUN,	//stuns like quick attack or kidney shot 
	IMMUNITY_FLAG_CHANGE, // MAYBE
	IMMUNITY_FLAG_PETRIFICATION,// maybe
	IMMUNITY_FLAG_CANDY,// maybe
	IMMUNITY_FLAG_10,
	IMMUNITY_FLAG_FREEZE,
	IMMUNITY_FLAG_FIGHT_INABILITY, // maybe
	IMMUNITY_FLAG_SKILL_LOCK, // maybe
	IMMUNITY_FLAG_SLEEP,
	IMMUNITY_FLAG_BLEED,
	IMMUNITY_FLAG_ABDOMINAL,
	IMMUNITY_FLAG_POISON,
	IMMUNITY_FLAG_BURN,
	IMMUNITY_FLAG_19,
	IMMUNITY_FLAG_CHEWING_GUM, // only event boss "Nana" has it. So it makes sense.

	IMMUNITY_FLAG_COUNT,
};

enum eSYSTEM_EFFECT_APPLY_TYPE
{
	SYSTEM_EFFECT_APPLY_TYPE_VALUE = 0,
	SYSTEM_EFFECT_APPLY_TYPE_PERCENT,
	SYSTEM_EFFECT_APPLY_TYPE_MAX_LP,
	SYSTEM_EFFECT_APPLY_TYPE_MAX_EP,
	SYSTEM_EFFECT_APPLY_TYPE_MAX_RP,
	SYSTEM_EFFECT_APPLY_TYPE_CURRENT_LP,
	SYSTEM_EFFECT_APPLY_TYPE_CURRENT_EP,
	SYSTEM_EFFECT_APPLY_TYPE_CURRENT_RP,
	SYSTEM_EFFECT_APPLY_TYPE_CURRENT_PHYSICAL_OFFENCE,
	SYSTEM_EFFECT_APPLY_TYPE_CURRENT_ENERGY_OFFENCE,
	SYSTEM_EFFECT_APPLY_TYPE_CURRENT_PHYSICAL_DEFENCE,
	SYSTEM_EFFECT_APPLY_TYPE_CURRENT_ENERGY_DEFENCE,
	SYSTEM_EFFECT_APPLY_TYPE_MAX_MASCOT_SP, //new

	SYSTEM_EFFECT_APPLY_TYPE_COUNT,

	SYSTEM_EFFECT_APPLY_TYPE_UNKNOWN = 0xFF,

	SYSTEM_EFFECT_APPLY_TYPE_FIRST = SYSTEM_EFFECT_APPLY_TYPE_VALUE,
	SYSTEM_EFFECT_APPLY_TYPE_LAST = SYSTEM_EFFECT_APPLY_TYPE_CURRENT_ENERGY_DEFENCE
};

//-----------------------------------------------------------------------------------
// 전투 관련 상수 정의 : [4/25/2006 zeroera] : 수정필요 : lua로 옮길 것
//-----------------------------------------------------------------------------------
const float			NTL_BATTLE_PUSH_DISTANCE					= 1.0f; // PUSH 거리
const float			NTL_BATTLE_KNOCKDOWN_DISTANCE				= 5.6f;	// KNOCKDOWN 거리.
const float			NTL_BATTLE_SLIDING_DISTANCE					= 4.0f; // SLIDING 거리

const int			NTL_BATTLE_CHAIN_ATTACK_START				= 1; // chain attack start id 

const int			NTL_BATTLE_MAX_CHAIN_ATTACK_COUNT			= 6; // The maximum value chain attack

const float			NTL_BATTLE_BLOCK_DAMAGE_REDUCE_RATE			= 0.3f;
const float			DBO_BATTLE_OFFENCE_CHANGE_RATE_BY_BLOCK			= 0.3f;
const float			NTL_BATTLE_CRITICAL_DAMAGE_INCREASE_RATE	= 1.5f;	//1.5
const float			DBO_BATTLE_OFFENCE_BONUS_RATE_BY_CRITICAL	= 75.0f;		// in percent. Default 100

const float			NTL_BATTLE_HIT_FRONT_SIDE_BONUS_RATE		= 1.0f;
const float			NTL_BATTLE_HIT_BACK_SIDE_BONUS_RATE			= 1.5f;

const DWORD			NTL_BATTLE_ATTACK_DELAY_TIME				= 1000;

const DWORD			NTL_BATTLE_COMBAT_DISABLE					= 6000;

const DWORD			NTL_BATTLE_KNOCKDOWN_WAKEUP_TIME			= 4000; // KNOCKDOWN TIME FOR NPC/MOB
const DWORD			NTL_BATTLE_KNOCKDOWN_MIN_WAKEUP_TIME		= 1000; // MIN KNOCKDOWN TIME FOR PC
const DWORD			NTL_BATTLE_KNOCKDOWN_MAX_WAKEUP_TIME		= 6000; // MAX KNOCKDOWN TIME FOR PC
const DWORD			NTL_BATTLE_KNOCKDOWN_WAKEUP_TIME_DIFF		= NTL_BATTLE_KNOCKDOWN_MAX_WAKEUP_TIME - NTL_BATTLE_KNOCKDOWN_MIN_WAKEUP_TIME;
const DWORD			NTL_BATTLE_SLIDING_END_TIME					= 1200; // 슬라이딩 끝나는 타임
const DWORD			NTL_BATTLE_HTB_SANDBAG_END_TIME				= 10000; // HTB시 SANDBAG 끝나는 타임

const int			NTL_BATTLE_MAX_NPC_ATTACK_TYPE				= 2; // NPC attacks (currently 2 types)

const int			DBO_BATTLE_ANGLE_IN_DEGREE_PC = 120;

// Free Battle
const float			DBO_FREEBATTLE_CHALLENGE_RANGE				= 10.0f; // Free battle city streets can be a challenge
const float			DBO_FREEBATTLE_MATCH_INSIDE_RADIUS			= 45.0f; // Inside the pre-war range from battle when the reference point (radius)
const float			DBO_FREEBATTLE_MATCH_OUTSIDE_RADIUS			= 50.0f; // From the pre-war outside of the scope of the battle when the reference point (radius)
const DWORD			DBO_FREEBATTLE_CHALLENGE_RETRY_TIME			= 10; // Free battle city jaedojeon (s)
const DWORD			DBO_FREEBATTLE_CHALLENGE_RETRY_MILLITIME	= DBO_FREEBATTLE_CHALLENGE_RETRY_TIME * 1000; // 프리배틀시 재도전(밀리세컨드)
const DWORD			DBO_FREEBATTLE_CHALLENGE_WAIT_TIME			= 60; // 프리배틀시 재도전(초)
const DWORD			DBO_FREEBATTLE_CHALLENGE_WAIT_MILLITIME		= DBO_FREEBATTLE_CHALLENGE_WAIT_TIME * 1000; // 프리배틀시 재도전(밀리세컨드)
const DWORD			DBO_FREEBATTLE_OUTSIDE_ALLOW_TIME			= 10; // 프리배틀시 장외허용 시간(초)
const DWORD			DBO_FREEBATTLE_OUTSIDE_ALLOW_MILLITIME		= DBO_FREEBATTLE_OUTSIDE_ALLOW_TIME * 1000; // 프리배틀시 장외허용 시간(밀리세컨드)
const DWORD			DBO_FREEBATTLE_MATCH_TIME					= 3600; // 프리배틀 경기 시간(초)
const DWORD			DBO_FREEBATTLE_MATCH_MILLITIME				= DBO_FREEBATTLE_MATCH_TIME * 1000; // 프리배틀 경기시간(밀리세컨드단위)

// ARENA
const float			DBO_ARENA_BASE_LOC_X						= 5770.0f;
const float			DBO_ARENA_BASE_LOC_Y						= -97.0f;
const float			DBO_ARENA_BASE_LOC_Z						= 766.0f;
const float			DBO_ARENA_FREEBATTLELOC_RANGE				= 100.0f;


//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
const char * NtlGetBattleAttackTypeString(BYTE byAttackType);

const char * NtlGetBattleAttackResultString(BYTE byAttackResult);

const char * DboGetFreeBattleResultString(BYTE byBattleResult);


//-----------------------------------------------------------------------------------
// 전투 관련 함수 정의 : [4/25/2006 zeroera] : 수정필요 : lua로 옮길 것
//-----------------------------------------------------------------------------------
BYTE				NtlGetBattleChainAttackSequence(BYTE byCharLevel); // 레벨당 최대 CHAIN ATTACK 수 

//float				NtlGetBattleAttributeBonusRate(BYTE bySubjectAtt, BYTE byTargetAtt); // get battle attribute bonus // old

eSYSTEM_EFFECT_CODE	GetBattleAttributeEffectCode(BYTE byAtt);
BYTE				GetBattleAttributeEffectApplyType(BYTE byAtt);
float				GetBattleAttributeEffectApplyValue(BYTE byAtt);

float				NtlGetBattleChainAttackBounsRate(BYTE byAttackSequence); // 체인 어택에 따른 보너스 공격률

bool				IsInBattleArena(TBLIDX worldTblidx, CNtlVector& vCurLoc);


struct sBOT_AGGROPOINT
{
	HOBJECT		hObject;
	DWORD		dwTotalDamage;
	DWORD		dwAggroPoint;

	sBOT_AGGROPOINT(HOBJECT hObj, DWORD dwTot, DWORD dwAggr)
		: hObject(hObj), dwTotalDamage(dwTot), dwAggroPoint(dwAggr)
	{}

};
