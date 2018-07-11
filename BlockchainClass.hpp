#include <iostream>
#include <string>
#include <vector>



class Blockchain {
private:
  /* data */
  void Genesis(); // genesis block (fisrt block on a blockchain)
  vector<Block> mainchain; // vector to hold chain, alternatively define double linked list with no insertions in the middle
                          // however I still find that vectors are better suited for the task unless specifi custom features are needed
  int difficulty;
public:
  Blockchain ();

  vector<Block> chain(); // returns the blockchain

  bool checkChain(); // checks if blockchain is valid

  void displayChain(); // displays the blockchain

  Block lastEntry(); // returns last block

  void newBlock(Block b); // adds a new block

  //virtual ~Blockchain ();
};
