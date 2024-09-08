#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t robot;
    robot.position.x = x;
    robot.position.y = y;
    robot.direction = direction;
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    for(int i = 0; commands[i] != '\0'; i++)
    {
        if(commands[i] == 'R')
        {
            robot->direction = (robot->direction+1 ) % 4;

        }
        if(commands[i] == 'L')
        {
            robot->direction = (robot->direction-1) % 4;
        }
        if(commands[i] == 'A')
        {
            switch (robot->direction)
            {
            case 0:
                robot->position.y++;
                break;
            case 1:
                robot->position.x++;
                break;
            case 2:
                robot->position.y--;
                break;
            case 3:
                robot->position.x--;
                break;
            
            default:
                break;
            }
        }
    }
}
