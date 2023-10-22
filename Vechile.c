#include <stdio.h>
#include <stdbool.h>

#include "Vechile_Func.h"

bool System_State = true, EngOFF = true;

int main(void)
{
    unsigned char SystemMode = 0;

    while( System_State )
    {
        printf("\nWelcome to NTI Vechile\n-----------------------------------\n");
        //Vechile_State();
        printf("\nWhat would you like to do?\n");
        printf("1- Turn ON Vechile Engine.\n");
        printf("2- Turn OFF Vechile Engine.\n");
        printf("3- Quit the system.\n\n-> ");

        fflush(stdin);
        scanf("%d", &SystemMode);

        switch (SystemMode)
        {
        case TURN_ON_VEC:
            Turn_On_System();
            break;
        case TURN_OFF_VEC:
            Turn_OFF_System();
            break;
        case EXIT:
            printf("Quitting System.....\n");
            printf("Bye..\n\n");
            System_State = false;
            break;
        default:
            printf("Invalid Input please choose one of the following.\n\n");
            break;
        }
    }

    return 0;
}

void Turn_On_System()
{
    EngOFF = false;
    char Sensor = 0;
    Engine_State = 1;
    printf("\nEngine is turned ON.\n\n");

    while (Engine_State)
    {
        printf("\na- Turn OFF Engine.\n");
        printf("b- Set Traffic light Color.\n");
        printf("c- Set room Temperature.\n");
        printf("d- Set Engine Temperature.\n\n-> ");

        fflush(stdin);
        scanf("%c",&Sensor);

        switch (Sensor)
        {
        case LIGHT_SENSOR:
            Light();
            break;
        case ROOM_TEMP:
            Room();
            break;
        case ENGINE_TEMP:
            Engine();
            break;
        case ENGINE_OFF:
            Turn_OFF_System();
            EngOFF = true;
            break;
        default:
            printf("Invalid Input please choose one of the following.\n\n");
            break;
        }
        Vechile_State();
    }
}
void Turn_OFF_System()
{
    Engine_State = 0;
    if (EngOFF)
    {
        printf("\nEngine is already turned OFF.\n\n");
    }
    else
    {
        printf("\nEngine is turned OFF.\n\n");
    }
}

void Vechile_State()
{
    printf("\nVehicle State:\n\n");
    printf("Engine is %s\n", Engine_State ? "ON" : "OFF");
    printf("Speed: %d km/hr\n", Speed);
    printf("Room Temperature: %d\n", Room_temp);
    printf("AC: %s\n", AC ? "ON" : "OFF");
    printf("Engine Temperature Sensor: %s\n", EngState ? "ON" : "OFF");
    printf("Engine Temperature: %d\n", Eng_temp);
}
void Light()
{
    printf("\nEnter Traffic Light Color (G / O / R) :\n-> ");
    char light = 0;
    
    fflush(stdin);
    scanf("%c",&light);

    if (light == 'G' || light == 'g')
    {
        Speed = 100;
    }
    else if (light == 'O' || light == 'o')
    {
        Speed = 30;
        EngState = true;
        AC = 1;
        Room_temp = Room_temp * (5/4) + 1;
        Eng_temp = Eng_temp * (5 / 4) + 1;
    }
    else if (light == 'R' || light == 'r')
    {
        Speed = 0;
    }
    else
    {
        printf("Invaled Input.\n");
    }
}

void Room()
{
    printf("\n the room temperature: ");
    
    fflush(stdin);
    scanf("%d", &Room_temp);

    if (Room_temp < 10)
    {
        AC = 1;
        Room_temp = 20;
    }
    else if (Room_temp > 30)
    {
        AC = 1;
        Room_temp = 20;
    }
    else
    {
        AC = 0;
    }
}


void Engine()
{
    printf("Enter the engine temperature: ");
    fflush(stdin);
    scanf("%d", &Eng_temp);

    if (Eng_temp < 100)
    {
        Eng_temp = 125;
        EngState = true;
    }
    else if (Eng_temp > 150)
    {
        Eng_temp = 125;
        EngState = true;
    }
    else
    {
        Eng_temp = 125;
    }
}