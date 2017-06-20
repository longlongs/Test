This is the solution for the Dorabot Programming Task.
pseudo.cpp solve the Navigation test.I use the pseudo code and comments to express this algorithm.
In order to solve the problem of pathfinding,I used the depth first search algorithm.According to the direction of the sequence traversal each node, until you find the finish.
If the robot hit a wall, change direction, if the current node all direction to find out ,then to back up one step.

The task2.cpp in src solve the two parts of the task2. They should be executable using basic c++ on linux.
This file is composed of two functions,Generator and Processor.

In Generator,you should input min length and max length,the program will create a sequence of strings,which output in "../file/output.txt".
Strings size must at least twice the amount of system RAM,and every string length must > min length and < max length.
If you input min length>max length, the program will warning error and exit.
The program will output a summary file which include spend time,in "../file/Generator_summary.txt"
I have used openmp to open multiple threads.

In Processor,you should input input file name, and the program will read the file ,sort by character,then output in "../file/output.txt",
and output the summary file which include spend time,in "../file/Processor_summary.txt".
The program will sort input strings by A-Z a-z.
In order to prevent the hard disk ,I add a expensiveFunc() to delay 10ms.