/*	---------------------------------------------------------------
	 This header contains GTAIV/EFLC PC script common functions.

	 This file is a part of scocl project (C) Alexander Blade 2011
	---------------------------------------------------------------  */

#pragma once

#include "natives.h"
#include "consts.h"

void print(char* text){
	CLEAR_PRINTS();//Clears already printed text
	PRINT_STRING_WITH_LITERAL_STRING("string",text,3000,true);
	return;
}

void print_short(char* text){
	CLEAR_PRINTS();//Clears already printed text
	PRINT_STRING_WITH_LITERAL_STRING("string",text,1000,true);
	return;
}

void print_long(char* text){
	CLEAR_PRINTS();//Clears already printed text
	PRINT_STRING_WITH_LITERAL_STRING("string",text,6000,true);
	return;
}

void print_two(char* text, char* text2){
	CLEAR_PRINTS();//Clears already printed text
	PRINT_STRING_WITH_TWO_LITERAL_STRINGS("STRING",text,text2,3000,true);
	return;
}

void print_two_short(char* text, char* text2){
	CLEAR_PRINTS();//Clears already printed text
	PRINT_STRING_WITH_TWO_LITERAL_STRINGS("string",text,text2,1000,true);
	return;
}

void print_two_long(char* text, char* text2){
	CLEAR_PRINTS();//Clears already printed text
	PRINT_STRING_WITH_TWO_LITERAL_STRINGS("string",text,text2,5000,true);
	return;
}

void print_number(uint number){
	CLEAR_PRINTS();//Clears already printed text
	PRINT_WITH_NUMBER_NOW("string", number, 3000, true);
	return;
}

Player GetPlayerIndex(void)
{
	return GET_PLAYER_ID();
}

Ped GetPlayerPed(void)
{
	Ped playerped = INVALID_HANDLE;
	if ( PLAYER_HAS_CHAR(GetPlayerIndex()) )
		GET_PLAYER_CHAR(GetPlayerIndex(), &playerped);
	return playerped;
}

Player GetPlayerFromPed(Ped pPed){
	int i = 0;
	for(i;i<16;i++){
		if (i == GET_PLAYER_ID())continue;
		if (!IS_NETWORK_PLAYER_ACTIVE(i))continue;
		int tmp;
		GET_PLAYER_CHAR(i, &tmp);
		if (tmp == pPed) return i;
	}
	return -1; //Error code if ped isnt a player
}

void UpdateWeaponOfPed(Ped ped, Weapon weapon)
{
	if (HAS_CHAR_GOT_WEAPON(ped, weapon))
	{
		SET_CHAR_AMMO(ped, weapon, AMMO_MAX);    
	} 	else
	{
		GIVE_WEAPON_TO_CHAR(ped, weapon, AMMO_MAX, FALSE);	
		SET_CURRENT_CHAR_WEAPON(ped, weapon, true);
	}
}

void SetPedHater(Ped pPed){
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_PLAYER);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_COP);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_01);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_02);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_03);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_04);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_05);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_06);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_07);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_08);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_09);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_10);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_11);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_12);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_13);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_14);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_15);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_PLAYER_16);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_TEAM_1);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_TEAM_2);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_TEAM_3);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_TEAM_4);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_TEAM_5);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_TEAM_6);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_TEAM_7);
	SET_CHAR_RELATIONSHIP(pPed, RELATIONSHIP_HATE, RELATIONSHIP_GROUP_NETWORK_TEAM_8);
	return;
}

uint GetPlayerNetworkGroup(uint i){
	return i + 31;
}

uint GetRandomMeleeWeapon(){
	int i;
	GENERATE_RANDOM_INT_IN_RANGE(1,4,&i);
	if(i == 1) return WEAPON_UNARMED;
	else if(i == 2) return WEAPON_BASEBALLBAT;
	else if(i == 3) return WEAPON_POOLCUE;
	else if(i == 4) return WEAPON_KNIFE;
}