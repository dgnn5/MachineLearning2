//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include "Header.h"
//#include "Cube.h"
#include "Brain.h"
//using namespace std;

//IN HEADER
/*
//const int TWOCUBE = 24;//   The number of squares on a 2x2x2 Rubik's cube
//const int THREECUBE = 54;// The number of squares on a 3x3x3 Rubik's cube
// These are the moveLists for the stickers for each possible move
const int U2[24] = {0,2,1,0,2,3,3,1,4,16,5,17,8,4,9,5,12,8,13,9,16,12,17,13};
const int U3[40] = {0,6,1,3,2,0,3,7,5,1,6,8,7,5,8,2,9,36,10,37,11,38,18,9,19,10,20,11,27,18,28,19,29,20,36,27,37,28,38,29};
//const int UP2[24] = {2,0,0,1,3,2,1,3,16,4,17,5,4,8,5,9,8,12,9,13,12,16,13,17};
const int F2[24] = {4,6,5,4,6,7,7,5,2,11,3,9,11,20,9,22,20,16,22,18,16,2,18,3};
const int F3[40] = {9,15,10,12,11,9,12,16,14,10,15,17,16,14,17,11,6,26,7,23,8,20,26,45,23,48,20,51,45,36,48,39,51,42,36,6,39,7,42,8};
const int L2[24] = {8,10,10,11,11,9,9,8,0,15,2,13,15,22,13,23,22,4,23,6,4,0,6,2};
const int L3[40] = {18,24,19,21,20,18,21,25,23,19,24,26,25,23,26,20,0,35,3,32,6,29,35,51,32,52,29,53,51,9,52,12,53,15,9,0,12,3,15,6};
const int B2[24] = {12,14,13,12,14,15,15,13,1,19,0,17,19,23,17,21,23,8,21,10,8,1,10,0};
const int B3[40] = {27,33,28,30,29,27,30,34,32,28,33,35,34,32,35,29,2,44,1,41,0,38,44,53,41,50,38,47,53,18,50,21,47,24,18,2,21,1,24,0};
const int R2[24] = {16,18,17,16,18,19,19,17,3,7,1,5,7,21,5,20,21,12,20,14,12,3,14,1};
const int R3[40] = {36,42,37,39,38,36,39,43,41,37,42,44,43,41,44,38,8,17,5,14,2,11,17,47,14,46,11,45,47,27,46,30,45,33,27,8,30,5,33,2};
const int D2[24] = {20,22,21,20,22,23,23,21,18,6,19,7,6,10,7,11,10,14,11,15,14,18,15,19};
const int D3[40] = {45,51,46,48,47,45,48,52,50,46,51,53,52,50,53,47,15,24,16,25,17,26,24,33,25,34,26,35,33,42,34,43,35,44,42,15,43,16,44,17};
*/
//IN CUBE_H
/*
const int NUMSIDES = 6;//      The number of sides on a Rubik's cube
const int DEFSIDELENGTH = 2;// The default side length for the Cube class
*/

const float brainList[49] = { 49, 3, 5, 1, 0, 0, 1, 0, 2, 0, 3, 0, 4, 4, -0.835322, 2, 0.452162, 3, 0.242866, 6, -0.314219, 7, 5, 0, 6, 2, 0.696371, 0, 0.832209, 1, 7, 2, 0.162694, 4, -0.305582, 5, 8, 1, -0.0315561, 7 };
int main()
{
  srand(time(NULL));
  const int inputvals[3] = {3, 6, 7};
  Package<int> pack(3, inputvals);

  Brain samantha(brainList);
  cout << samantha << endl << endl;

  /*
  Brain samantha(3, 5, 1);
  cout << samantha << endl << endl;
  */
  samantha.SetInput(pack);
  cout << samantha << endl << endl;
  samantha.Propogate();
  cout << samantha << endl << endl;
  cout << samantha.GetOutput() << endl << endl;
  samantha.Propogate();
  cout << samantha << endl << endl;
  cout << samantha.GetOutput() << endl << endl;

  float x = (1.0 / 6.0) + 0.75;
  cout << x;

  /*
  Cube test(3);
  cout << test << endl << endl;

  cout << test.getGrade() << endl << endl;

  Package<int> moveList(test.Scramble(3));
  cout << moveList << endl << endl;
  
  cout << test << endl << endl;

  cout << test.getGrade() << endl << endl;
  */
  return 0;
}