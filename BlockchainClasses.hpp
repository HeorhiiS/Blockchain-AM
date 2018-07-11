// USE SHA256 when possible

#include <iostream>
#include <string>
#include <vector>
// class declarations go here

using namespace std;

class Blockchain;

class Block {
private:
  /* data */
  // no specific index needed as index of a block is its position in the chain
  string previousHash;
  string creationtime;
  string computeHash();
  Transaction data;
  string blockHash = computeHash();
  int nonce= 0;
  friend class Blockchain;

public:
  Block (string prevHash, string timestamp, Transaction inf){  // data in string represents single transaction packed into a single string
    previousHash = prevHash;
    data = inf;
    creationtime = timestamp;
  }

  // get previous string
  string getPrevHash();

  // get current string
  string getBlockHash();

  bool hashCheck(); // to prevent malicious use check if hashes are valid

  void mine(int difficulty);
};


class Transaction {
public:
  Transaction (int val, string s, string r);
  string senderKey = s;
  string receiverKey = r;
  int value = v;
  string compressOut(){
    return(senderKey+receiverKey+ to_string(value)); // outputs contents of a transaction in a single string
  }

  //virtual ~Transaction ();
};
