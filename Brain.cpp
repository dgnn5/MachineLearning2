// Implementation file for the Brain class
#include "Brain.h"

void Brain::SetInput(const Package<int> input)
{
  if (input.m_size == m_numIn)// Checking the input is valid size
  {
    // Updating the values of every input node
    for (int i = 0; i < m_numIn; i++)
      m_nodes.m_values[i].m_value = input.m_values[i];
  }
  else// Invalid input size
  {
    // Outputting an error message
    cout << "!!!!!!! INVALID SETINPUT SIZE !!!!!!!!" << endl
      << "m_nodes = " << m_nodes << endl << endl
      << "input = " << input << endl
      << "input.m_size = " << input.m_size << endl
      << "m_numIn = " << m_numIn << endl;
  }
  return;
}

void Brain::Propogate(const int numTimes)
{
  float temp;// Used to store what will become the value of each node

  // Propogating numTimes times
  for (int w = 0; w < numTimes; w++)
  {
    // Looping through every hidden node and the output node IMPROVEEEEEEEEEE SPEED ("+1" -> "<=")(maybe elsewhere aswell)
    for (int i = m_numIn; i < (m_numIn + m_numHid + 1); i++)
    {
      temp = 0.0;// Initializing temp to 0.0 (Also serves as a reset on the next loop through)
      // Looping through every inward connection on node i
      for (int x = 0; x < m_nodes.m_values[i].m_in.m_size; x++)
      {
        // Incrementing temp by ((the weight of the connection) * (the value of the node it's coming from))
        temp += ((m_nodes.m_values[i].m_in.m_values[x].m_weight)
          * (m_nodes.m_values[m_nodes.m_values[i].m_in.m_values[x].m_pointing].m_value));
      }
      // Setting the value of node i to the Sigmoid of temp
      m_nodes.m_values[i].m_value = Sigmoid(temp);
    }
  }
  return;
}


/*
Output format: A one dimensional array...
Key: () = loop, [] = output of each iteration of the loop
  {
    count, m_numIn, m_numHid, m_numCon,
    (for each node in m_nodes):
    [
      node.m_index, ///node.m_value///, node.m_in.m_size,
      (for each connection in node.m_in):
      [
        node.connection.m_weight, node.connection.m_pointing,
      ]
    ]
  }
*/
ostream& operator<<(ostream& out, const Brain& brain)
{
  Package<float> pack;// This will store all of the appropriate values

  // Append the first few values to the pack (casting them to float for consistency)
  pack.append(static_cast<float>(brain.m_numIn));
  pack.append(static_cast<float>(brain.m_numHid));
  pack.append(static_cast<float>(brain.m_numCon));

  // Looping through every node
  for (int i = 0; i < (brain.m_numIn + brain.m_numHid + 1); i++)
  {
    pack.append(static_cast<float>(brain.m_nodes.m_values[i].m_index));// Append the index of node i
    //EEEE REMOVE EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    pack.append(brain.m_nodes.m_values[i].m_value);// Append the value of node i
    //EEEEE REMOVE EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    pack.append(static_cast<float>(brain.m_nodes.m_values[i].m_in.m_size));// Append the number of connections of node i
    // Looping through every connection of node i
    for (int x = 0; x < (brain.m_nodes.m_values[i].m_in.m_size); x++)
    {
      pack.append(brain.m_nodes.m_values[i].m_in.m_values[x].m_weight);// Append the weight of connection x of node i
      pack.append(static_cast<float>(
        brain.m_nodes.m_values[i].m_in.m_values[x].m_pointing));// Append the 'target' of connection x of node i
    }
  }

  // Outputting the length of the brain list
  out << "{" << (pack.m_size + 1);
  // Outputting the rest of the brain list
  for (int i = 0; i < pack.m_size; i++)
    out << ", " << pack.m_values[i];
  // Outputting the closing brace
  out << "}";

  // Returning the output
  return out;
}

Brain& Brain::operator=(const Brain& source)
{
  // Setting LHS = RHS
  m_numIn = source.m_numIn;
  m_numHid = source.m_numHid;
  m_numCon = source.m_numCon;
  m_nodes = source.m_nodes;
  // Return the LHS
  return (*this);
}