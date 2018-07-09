// USE SHA256


#include <iostream>
#include <string>
#include <ctime>

// class declarations go here

class Block {
private:
  /* data */
  int index;
  // hash previousHash;
  // hash blockHash;
  // hash computeHash();

public:
  Block (\int i, TransactionINF inf, hash prevHash, time tstamp);

  TransactionINF info; // holds transation's info

  ///get previous hash
  hash getPrevHash();

  // get current hash
  hash getBlockHash();

  bool validHash(); // to prevent malicious use check if hashes are valid
};


class TransactionINF {

public:
  int transactionVal;
  string KeySender;
  string KeyReceiver;
  //time timestamp;
  TransactionINF ();
};
