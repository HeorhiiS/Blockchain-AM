// USE SHA256 when possible, use time_t for timestamp and size_t for size_t

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
// class declarations go here

using namespace std;

class Block {
private:
  /* data */
  int index;
  size_t previousHash;
  size_t blockHash;
  size_t computeHash();

public:
  Block (int i, TransactionINF inf, size_t prevHash, time_t tstamp);

  TransactionINF info; // holds transation's info

  ///get previous size_t
  size_t getPrevHash();

  // get current size_t
  size_t getBlockHash();

  bool hashCheck(); // to prevent malicious use check if hashes are valid
};


class TransactionINF {

public:
  int transactionVal;
  string KeySender;
  string KeyReceiver;
  time_t timestamp;
  TransactionINF (){
    cout << "NO DATA FOR TRANSACTION" << '\n';
  };
  TransactionINF(int x, string keyS, string keyR, time_t timeS ){
    transactionVal = x;
    KeySender = keyS;
    KeyReceiver = keyR;
    timestamp = timeS;
  }
};

class Blockchain {
private:
  /* data */
  Block Genesis(); // genesis block (fisrt block on a blockchain)
  vector<Block> mainchain; // vector to hold chain, alternatively define double linked list with no insertion in the middle
                          // however I still find vectors are better suited for the task unless specifi custom features are needed
public:
  Blockchain ();

  vector<Block> chain(); // returns the blockchain 

  bool checkChain(); // checks if blockchain is valid

  void displayChain(); // displays the blockchain

  Block lastEntry(); // returns last block

  void newBlock(); // adds a new block

  void printLastBlock(); // prints public contents of the last block

  //virtual ~Blockchain ();
};
