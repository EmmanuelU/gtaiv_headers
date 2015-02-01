/*

Default config
	ENGLISH
	by: Emmanuel Utomi

*/
//Xbox 360 buttons
#define BUTTON_SELECT 0xD
#define BUTTON_START 0xC
#define BUTTON_X 0xE
#define BUTTON_Y 0xF
#define BUTTON_A 0x10
#define BUTTON_B 0x11
#define DPAD_UP 0x8
#define DPAD_DOWN 0x9
#define DPAD_LEFT 0xA
#define DPAD_RIGHT 0xB
#define BUTTON_L 0x5
#define BUTTON_R 0x7
#define BUTTON_LB 0x4
#define BUTTON_RB 0x6
#define STICK_LEFT 0x12
#define STICK_RIGHT 0x13

//PS3 Buttons
#define L3  0x12
#define L2  0x5
#define R2  0x7
#define L1  0x4
#define R1  0x6
#define START      0xC
#define SELECT     0xD
#define SQUARE     0xE
#define TRIANGLE   0xF
#define X          0x10
#define CIRCLE     0x11
#define STICK_L    0x12  //L3
#define STICK_R    0x13  //R3

#define do_toggle(x) \
	if(x) x=false;\
	else x=true;
	
Ped pPlayer;
uint i, model,tick;
int pId;
int weapon;
Vehicle pVeh;
Group pGroup;
float x,y,z,heading;

#ifdef ONLINE
	Ped online_char;
	
	typedef struct Multiplayer{
		char* name;
		Ped ped;
		int id;
		float x,y,z;
		int weapon;
		Vehicle vehicle;
		uint model;
	} Multiplayer;

	Multiplayer player[16];
	
	void SetMutliplayer(void){
		for(i = 0;i <= 15;i++){
			if(!IS_NETWORK_PLAYER_ACTIVE(i)) continue;
			if(GET_PLAYER_ID() == i) continue;
			GET_PLAYER_CHAR(i,&online_char);
			player[i].ped = online_char;
			player[i].name = GET_PLAYER_NAME(i);
			player[i].id = i;
			if(DOES_CHAR_EXIST(online_char)){
				GET_CURRENT_CHAR_WEAPON(online_char,&player[i].weapon);
				GET_CAR_CHAR_IS_USING(online_char, &player[i].vehicle);
				GET_CHAR_COORDINATES(online_char, &player[i].x,&player[i].y,&player[i].z);
				GET_CHAR_MODEL(online_char,&player[i].model);
			}
		}
		return;
	}
	
#endif