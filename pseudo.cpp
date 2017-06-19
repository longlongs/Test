//the obstacles is 0 and the space is 1

//if the next is obstacles, turn down
//if the next is space ,traversal
int row=init_row,col=init_col;
if(1==area[row][col])
{
    col++;
}
if(col==width)
{
    col--;
    row++;
}
if(col==0)
{
    row++;
    col++;
}
if(0==area[row][col])
{
    row++;
}

