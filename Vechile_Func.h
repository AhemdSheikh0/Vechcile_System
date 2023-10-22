#ifndef VECHILE_FUNC_H
#define VECHILE_FUNC_H

#define TURN_ON_VEC     1
#define TURN_OFF_VEC    2
#define EXIT            3

#define ENGINE_OFF      'a'
#define LIGHT_SENSOR    'b'
#define ROOM_TEMP       'c'
#define ENGINE_TEMP     'd'

unsigned char Engine_State = 0; 
unsigned char AC = 0;           
unsigned char Speed = 0;
unsigned char Room_temp = 0;
unsigned char Eng_temp = 0;
bool EngState = false;

// System Functions
void Turn_On_System();
void Turn_OFF_System();
void Vechile_State();
void Light();
void Room();
void Engine();
#endif