// The header file for the Brain class ("Recurrent Neural Network" (kind of))
#ifndef BRAIN_H
#define BRAIN_H

#include "Cube.h"

const int DEFHID = 100;// The default number of hidden nodes
const int DEFCON = 3;//   The default number of outward connections per node
const float UCAP = 0.0833333;// The max threshold for a move to be interpreted as U
const float UPCAP = 0.166667;// The max threshold for a move to be interpreted as U'
const float FCAP = 0.25;//      The max threshold for a move to be interpreted as F
const float FPCAP = 0.333333;// The max threshold for a move to be interpreted as F'
const float LCAP = 0.416667;//  The max threshold for a move to be interpreted as L
const float LPCAP = 0.5;//      The max threshold for a move to be interpreted as L'
const float BCAP = 0.583333;//  The max threshold for a move to be interpreted as B
const float BPCAP = 0.666667;// The max threshold for a move to be interpreted as B'
const float RCAP = 0.75;//      The max threshold for a move to be interpreted as R
const float RPCAP = 0.833333;// The max threshold for a move to be interpreted as R'
const float DCAP = 0.916667;//  The max threshold for a move to be interpreted as D
const float DPCAP = 1.0;//      The max threshold for a move to be interpreted as D'


// The brain of the AI (NOTE: ASSUMES ONLY ONE OUTPUT NODE)
class Brain
{
private:
  int m_numIn;//  The number of input nodes
  int m_numHid;// The number of hidden-layer nodes
  int m_numCon;// The number of outward connections each node has
  Package<Node> m_nodes;// The array of nodes

public:
  // Constructors
  Brain() : m_numIn(TWOCUBE), m_numHid(DEFHID), m_numCon(DEFCON)
  {
    int randindex;//      Used for storing the index of a randomly generated connection
    Connection randcon;// Used for storing the data of a randomly generated connection
    // Instantiating all of the nodes (input, hidden, and output)
    for (int i = 0; i < (m_numIn + m_numHid + 1); i++)
      m_nodes.append(Node(i));

    // Creating the connections from the input nodes and hidden nodes to other hidden nodes or the output node
    for (int i = 0; i < (m_numIn + m_numHid); i++)
    {
      for (int x = 0; x < m_numCon; x++)
      {
        randindex = ((rand() % (m_numHid + 1)) + m_numIn);// Picking a random node to point to
        randcon.m_weight = ((rand() / static_cast<float>(RAND_MAX)) + (-1.0 * (rand() % 2)));// Randomizing the weight
        randcon.m_pointing = i;// Setting the index the connection is pointing from
        m_nodes.m_values[randindex].m_in.append(randcon);// Appending the connection to the target node
      }
    }
    // If the output node has no connections, generate one for it to have
    if (m_nodes.m_values[m_numIn + m_numHid].m_in.m_size == 0)
    {
      randindex = ((rand() % m_numHid) + m_numIn);// Picking a random hidden node to point to
      randcon.m_weight = ((rand() / static_cast<float>(RAND_MAX)) + (-1.0 * (rand() % 2)));// Randomizing the weight
      randcon.m_pointing = randindex;// Setting the index the connection is pointing from
      m_nodes.m_values[m_numIn + m_numHid].m_in.append(randcon);// Appending the connection to the output node
    }
  }
  Brain(const int numIn, const int numHid) : m_numIn(numIn), m_numHid(numHid), m_numCon(DEFCON)
  {
    int randindex;//      Used for storing the index of a randomly generated connection
    Connection randcon;// Used for storing the data of a randomly generated connection
    // Instantiating all of the nodes (input, hidden, and output)
    for (int i = 0; i < (m_numIn + m_numHid + 1); i++)
      m_nodes.append(Node(i));

    // Creating the connections from the input nodes and hidden nodes to other hidden nodes or the output node
    for (int i = 0; i < (m_numIn + m_numHid); i++)
    {
      for (int x = 0; x < m_numCon; x++)
      {
        randindex = ((rand() % (m_numHid + 1)) + m_numIn);// Picking a random node to point to
        randcon.m_weight = ((rand() / static_cast<float>(RAND_MAX)) + (-1.0 * (rand() % 2)));// Randomizing the weight
        randcon.m_pointing = i;// Setting the index the connection is pointing from
        m_nodes.m_values[randindex].m_in.append(randcon);// Appending the connection to the target node
      }
    }
    // If the output node has no connections, generate one for it to have
    if (m_nodes.m_values[m_numIn + m_numHid].m_in.m_size == 0)
    {
      randindex = ((rand() % m_numHid) + m_numIn);// Picking a random hidden node to point to
      randcon.m_weight = ((rand() / static_cast<float>(RAND_MAX)) + (-1.0 * (rand() % 2)));// Randomizing the weight
      randcon.m_pointing = randindex;// Setting the index the connection is pointing from
      m_nodes.m_values[m_numIn + m_numHid].m_in.append(randcon);// Appending the connection to the output node
    }
  }
  Brain(const int numIn, const int numHid, const int numCon) : m_numIn(numIn), m_numHid(numHid), m_numCon(numCon)
  {
    int randindex;//      Used for storing the index of a randomly generated connection
    Connection randcon;// Used for storing the data of a randomly generated connection
    // Instantiating all of the nodes (input, hidden, and output)
    for (int i = 0; i < (m_numIn + m_numHid + 1); i++)
      m_nodes.append(Node(i));

    // Creating the connections from the input nodes and hidden nodes to other hidden nodes or the output node
    for (int i = 0; i < (m_numIn + m_numHid); i++)
    {
      for (int x = 0; x < m_numCon; x++)
      {
        randindex = ((rand() % (m_numHid + 1)) + m_numIn);// Picking a random node to point to
        randcon.m_weight = ((rand() / static_cast<float>(RAND_MAX)) + (-1.0 * (rand() % 2)));// Randomizing the weight
        randcon.m_pointing = i;// Setting the index the connection is pointing from
        m_nodes.m_values[randindex].m_in.append(randcon);// Appending the connection to the target node
      }
    }
    // If the output node has no connections, generate one for it to have
    if (m_nodes.m_values[m_numIn + m_numHid].m_in.m_size == 0)
    {
      randindex = ((rand() % m_numHid) + m_numIn);// Picking a random hidden node to point to
      randcon.m_weight = ((rand() / static_cast<float>(RAND_MAX)) + (-1.0 * (rand() % 2)));// Randomizing the weight
      randcon.m_pointing = randindex;// Setting the index the connection is pointing from
      m_nodes.m_values[m_numIn + m_numHid].m_in.append(randcon);// Appending the connection to the output node
    }
  }
  
  // Copy-ish constructor (format of list[] is the same format as the insertion operator's output)
  Brain(const float list[]) :
    m_numIn(static_cast<int>(list[1])), m_numHid(static_cast<int>(list[2])),m_numCon(static_cast<int>(list[3]))
  {
    int ind = 4;//  This is used to track the current index in the list
    int temp = 0;// This is used to track how far the index will move
    // Instantiate all of the nodes
    for (int i = 0; i < (m_numIn + m_numHid + 1); i++)
    {
      m_nodes.append(Node(i));
    }
    // Loop through the whole list
    while (ind < list[0])
    {
      // Set the number of connections for node ind
      // !!!!!DONT DO BECAUSE YOU CANT JUST UPDATE THE SIZE OF AN ARRAY EEEEEEEEEEEEEEEEE!!!!!!!
      //m_nodes.m_values[static_cast<int>(list[ind])].m_in.m_size = static_cast<int>(list[ind + 1]);
      temp++;// Increment temp
      // Loop through each connection of node ind
      for (int x = 0; x < static_cast<int>(list[ind + 1]); x++)
      {
        // Append connection x to node ind
        m_nodes.m_values[static_cast<int>(list[ind])].m_in.append(
          Connection(list[ind + 2 + 2*x], static_cast<int>(list[ind + 3 + 2*x])));
        temp += 2;// Increment temp
      }
      temp++;// Increment temp so that it is lying on top of the index next node
      ind += temp;// Increase ind by temp
      temp = 0;// Resetting temp
    }
  }

  // Copy Constructor
  // EEEEEEEEEE ADD LATER EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

  // Sets the values of the input nodes
  void SetInput(const Package<int> input);

  // Propogates the nodes numTimes times (or one time if unspecified)
  void Propogate(const int numTimes = 1);

  // Getter for the output node's value
  float GetOutput() { return m_nodes[m_numIn + m_numHid].m_value; }

  // Insertion operator overload
  friend ostream& operator<<(ostream& out, const Brain& brain);

  // Assignment operator overload
  Brain& operator=(const Brain& source);
};

#endif