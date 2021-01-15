// Global Header file
// Contains: Sigmoid function, Package struct, Connection struct, Node struct
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TWOCUBE = 24;//   The number of squares on a 2x2x2 Rubik's cube
const int THREECUBE = 54;// The number of squares on a 3x3x3 Rubik's cube

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


// The sigmoid function, used for calculations
inline
float Sigmoid(const float num)
{
  return (1.0 / (1.0 + exp(-1.0 * num)));
}


// Package is used to store arrays of T in a very convinient way
template <typename T>
struct Package
{
  int m_size;//  The size of the array
  T* m_values;// The array

  // Constructors
  Package() : m_size(0), m_values(new T[m_size]) {}
  Package(const int size) : m_size(size), m_values(new T[m_size]) {}
  Package(const int size, const T values[]) : m_size(size), m_values(new T[m_size])
  {
    for (int i = 0; i < m_size; i++)
      m_values[i] = values[i];
  }

  // Copy Constructor
  Package(const Package<T>& source) : m_size(source.m_size), m_values(new T[m_size])
  {
    for (int i = 0; i < m_size; i++)
      m_values[i] = source.m_values[i];
  }

  // Destructor
  ~Package() { delete[] m_values; }

  // Setter for m_values
  // NEEEEEEEEEEEEEED TO UPDATE SIZE
  void setValues(const T values[])
  {
    for (int i = 0; i < m_size; i++)
      m_values[i] = values[i];
  }

  // Append function, which appends value to the end of m_values
  void append(const T value)
  {
    T* temp = new T[m_size];// This will store m_values

    // Setting temp = m_values
    for (int i = 0; i < m_size; i++)
      temp[i] = m_values[i];

    // Increasing the size of m_values by 1
    delete[] m_values;
    m_size++;
    m_values = new T[m_size];

    // Setting m_values equal to temp and appending value to the end of m_values
    for (int i = 0; i < m_size - 1; i++)
      m_values[i] = temp[i];
    m_values[m_size - 1] = value;

    // Deleting temp and ending the function
    delete[] temp;
    return;
  }

  // Clears the list and sets m_size to 0
  void Clear()
  {
    delete[] m_values;
    m_size = 0;
    m_values = new T[m_size];
    return;
  }

  // Bracket operator overload
  T operator[](const int index)const { return m_values[index]; }

  // Copy Assignment operator overload
  Package<T>& operator=(const Package<T>& source)
  {
    // If LHS != RHS
    if (m_values != source.m_values)
    {
      m_size = source.m_size;// Set the size of LHS
      delete[] m_values;// Clear the LHS values
      m_values = new T[m_size];// Instantiate the LHS values
      // Set the LHS values
      for (int i = 0; i < m_size; i++)
        m_values[i] = source.m_values[i];
    }
    // Return the LHS
    return (*this);
  }

  // Equivalence operator overload EEEEEEEEEEE MAYBE CUT EEEEEEEEEEEEEEEE (NOTE: DOESN'T WORK WITH CONNECTION OR NODE)
  bool operator==(const Package<T>& p2)
  {
    if (m_size == p2.m_size)
    {
      for (int i = 0; i < m_size; i++)
      {
        if (m_values[i] != p2.m_values[i])
          return false;
      }
      return true;
    }
    return false;
  }
};
// Insertion operator overload
template <typename T>
inline
ostream& operator<<(ostream& out, const Package<T>& pack)
{
  for (int i = 0; i < pack.m_size; i++)
  {
    out << ((i == 0) ? ("[") : (", ")) << pack.m_values[i] << (i == (pack.m_size - 1) ? ("]") : (""));
  }
  return out;
}





// Connection is used to store data on the connections between nodes
struct Connection
{
  float m_weight;// The weight of the connection
  int m_pointing;// Stores the index the connection is pointing from

  // Constructors
  Connection() : m_weight(0.0), m_pointing(0) {}
  Connection(const float weight, const int pointing) : m_weight(weight), m_pointing(pointing) {}

  // Copy Assignment operator overload
  Connection& operator=(const Connection& source)
  {
    // Set LHS = RHS
    m_weight = source.m_weight;
    m_pointing = source.m_pointing;
    // Return the LHS
    return (*this);
  }
};
//Insertion operator overload
inline
ostream& operator<<(ostream& out, const Connection& connect)
{
  out << "(" << connect.m_weight << ", " << connect.m_pointing << ")";
  return out;
}





// Node is used to represent nodes within the Brain
struct Node
{
  int m_index;//              The index of the node
  float m_value;//            The value of the node
  Package<Connection> m_in;// The connections pointing into the node
  //Package<Connection> m_out;// The connections pointing out of the node

  // Constructors
  Node() : m_index(0), m_value(0.0) {}
  Node(const int index) : m_index(index), m_value(0.0) {}
  Node(const int index, const float value) : m_index(index), m_value(value) {}

  // Copy constructor EEEEEEEEEEEE ADD LATER EEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
  //Node(const Node& source)

  // Copy Assignment operator overload
  Node& operator=(const Node& source)
  {
    // Set LHS = RHS
    m_index = source.m_index;
    m_value = source.m_value;
    m_in = source.m_in;
    // Return the LHS
    return (*this);
  }
};
//Insertion operator overload
inline
ostream& operator<<(ostream& out, const Node& node)
{
  out << "{" << node.m_index << ", " << node.m_value << ", " << node.m_in << "}";
  return out;
}

#endif