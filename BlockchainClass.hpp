#include <iostream>
#include <string>
#include <vector>



class Blockchain {
private:
  /* data */
  void Genesis(); // genesis block (fisrt block on a blockchain)
  vector<Block> mainchain; // vector to hold chain, alternatively define double linked list with no insertions in the middle
                          // however I still find that vectors are better suited for the task unless specifi custom features are needed

  /*
  vector<Transaction> pendingTransactions;
  int miningReward = 100;
  */

  int difficulty;
public:
  Blockchain ();
/*
  void mineTransactions(string rewardAddress){
      Block block = Block(timestamp, pendingTransactions);
      block.mined(block.difficulty);
      cout << "Block mined" << '\n';
      mainchain.push_back(block);
      pendingTransactions.push_back(Transaction(NULL, rewardAddress, miningReward));
  }

  void newtransaction(Transaction transaction) {
    pendingTransactions.push_back(transaction);
  }

  int getBalance(string address){
   int balance = 0;
   for (int i = 0; i < mainchain.length(); i++) {
     for (int k = 0; k < mainchain[i].transactions; k++) {

       if (mainchain[i].transactions[k].senderKey == address) {
        balance = balance - mainchain[i].transactions[k].value;
       }
       if (mainchain[i].transactions[k].receiverKey == address) {
        balance = balance + mainchain[i].transactions[k].value;
       }
     }
   }
   return balance;
}

*/
  vector<Block> chain(); // returns the blockchain

  bool checkChain(); // checks if blockchain is valid

  void displayChain(); // displays the blockchain

  Block lastEntry(); // returns last block

  void newBlock(Block b); // adds a new block

  //virtual ~Blockchain ();
};
auto
