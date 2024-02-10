                                                 # Assignment 1
## Name : Malla Sailesh</br>
## Roll Number : 2021101106</br>

# <h1><b> very important : q1.out q2.out q3.out keep them in 2021101106 folder only not in sub folders for makefile 

# <b> Q1

   1)node.h</br>
   2)main.c</br>
   3)my_dll.c</br>
   4)my_dll.h</br>

   Input :             Output : 
   insert 1</br>
   insert 2 </br>
   insert 3</br>
   insert 4</br>
   print</br>          1 2 3 4</br>
   prune </br> 
   print</br>          1 3</br>
   insert_at 2 2</br>  
   print </br>         1 3 2</br>
   delete 0</br>       
   print</br>          3 2</nr>
   ### Assumptions 
   insert -> (enter a integer value i.e the data) used to inert node at end</br>
   insert_at -> (enter two inetegers one - data and one index) used to insert node at any index</br>
   delete -> (enter a integer for index) - deletes the node at end</br>
   find -> (enter a int to find that data exists in the list)</br>
   prune -> deletes the node at odd indexes</br>
   print -> print all the elements</br>
   print_reverse -> print all the elements in reverse order</br>
   get_size -> give the size of the list</br>

   ### how to compile was mentioned in makefile </br>

# <b> Q2
  
   1)complex.c</br>
   2)complex.h</br>
   3)main.c</br>

   Input:         Output:
   MOD 3</br>
   1 2 3</br>     3.74</br>
   ADD 3</br>
   1 2 3</br>
   2 3 4</br>     3 5 7</br>
   
   MOD 3 -> (enter the value of array of elements of size n=3) - give the mod of complex number 
   SUM 3 -> (enter the value of 2 arrays of elements of size n=3) - give the sum of complex numbers
   SUB 3 -> (enter the value of 2 arrays of elements of size n=3) - give the subtraction of complex numbers
   DOT 3 -> (enter the value of 2 arrays of elements of size n=3) - give the value of dot prduct(upto 2 decimals)
   COS 3 -> (enter the value of 2 arrays of elements of size n=3) - give the value of mod of  cross product(upto 2 decimals)
   ### how to compile was mentioned in makefile </br>
# <b> Q3

   1)musicplayer.c</br>
   2)musicplayer.h</br>
   3)song.c</br>
   4)song.h</br>
   5)main.c</br>
   

   Input:             Output:
   ADD a b 3</br>     Song a with artist b and duration 3.000000 created</br>
   ADD c d 3</br>     Song c with artist d and duration 3.000000 created</br>
   ADD s r 4</br>     Song s with artist r and duration 4.000000 created</br>
   INSERT a</br>      Song a added succesfully</br>
   INSERT b</br>      Song b couldn't be added to the music player</br>
   INSERT c</br>      Song c added succesfully</br>
   INSERT s</br>      Song s added succesfully</br>
   REMOVE 2</br>      Song at index 2 removed successfully</br>
   GET</br>           No song playing</br>
   PLAY</br>          Playing song</br>
   GET</br>           Song A is playing right now</br>
   EXIT</br>
   
 ### how to compile was mentioned in makefile </br>
