//use matrix area means the map
//the obstacles is 0 and the space is 1

//use the struct Position as the representative location
typedef struct
{
    int row;            //row of the position
    int col;            //col of the position
    int direction;      //direction of next step
} Position;
/*direction
    1 2 3
    4 0 5
    6 7 8
***********/

//init the position
Position position[width*height];
int step=0;
position[step].row=init_row,position[step].col=init_col,position[step].direction=1;
while(not stop)
{
    if(position[step].row==goal_row&&position[step].col==goal_col)
    {
        stop=true;
    }
    //if all the direction have been passed
    else if(8<position[step].direction)
    {
        step--;//return to the last step
        position[step].direction++;//choose the next direction
    }
    //if there is no direction to traverse, go in this direction
    else
    {
        //Method isSpace can determine whether it is an obstacle or an edge,and update the row and col
        if(isSpace(position[step].direction,row,col))//if next step is space,update the row and col by direction
        {
            position[step].row=row,position[step].col=col,position[step].direction=1;
            step++;//next step
        }
        position[step].direction++;
    }
}

/********************************************************
The algorithm uses depth first method to find the target.
Traverse every direction, go ahead in turn,if it meets obstacles,change direction. 
If you traverse all directions, move back to the next step.
*********************************************************/

