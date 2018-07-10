// USE SHA256 when possible

#include <iostream>
#include <string>
#include <vector>
// class declarations go here

using namespace std;

// class Blockchain;

class Block {
private:
  /* data */
  int index;
  string previousHash;
  string creationtime;
  string computeHash();
  string data;
  string blockHash = computeHash();
  friend class Blockchain;

public:
  Block (int i, string prevHash, string timestamp, sting inf){  // data in string represents single transaction packed into a single string
    index = i;
    previousHash = prevHash;
    data = inf;
    creationtime = timestamp;
  }

  // get previous string
  string getPrevHash();

  // get current string
  string getBlockHash();

  // returns the index of a block
  int index();

  bool hashCheck(); // to prevent malicious use check if hashes are valid
};

class Blockchain {
private:
  /* data */
  void Genesis(); // genesis block (fisrt block on a blockchain)
  vector<Block> mainchain; // vector to hold chain, alternatively define double linked list with no insertion in the middle
                          // however I still find vectors are better suited for the task unless specifi custom features are needed
public:
  Blockchain ();

  vector<Block> chain(); // returns the blockchain

  bool checkChain(); // checks if blockchain is valid

  void displayChain(); // displays the blockchain

  Block lastEntry(); // returns last block

  void newBlock(Block b); // adds a new block

  //virtual ~Blockchain ();
};
