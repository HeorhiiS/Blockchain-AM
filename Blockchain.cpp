#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "BlockchainClasses.hpp"
#include "BlockchainClass.hpp"


// function declarations go here

using namespace std;

void Block::printBlock(){
  cout <<creationtime<< '\n';
  cout <<previousHash<< '\n';
}

string Block::getPrevHash(){
  return previousHash;
}

string Block::getBlockHash(){
  return blockHash;
}

bool Block::hashCheck(){
  return (computeHash() == getBlockHash());
}

void Block::mine(int difficulty) {
  while (blockHash.substr(0,difficulty) != string x(difficulty,"0")) {
    nonce++;
    blockHash = computeHash();
  }
  cout << "Block mined: "<<blockHash<< '\n';
}

string Block::computeHash(){
string src_str = (data.compressOut()+creationtime+previousHash+to_string(nonce));
string hash_hex_str;
picosha2::hash256_hex_string(src_str, hash_hex_str);
return hash_hex_str;
}

void Blockchain::Genesis(){
  Block genesis = Block("0","7/11/2018","Genesis");
  mainchain.push_back(genesis);
}


Blockchain::Blockchain(){
  Genesis();
}

vector<Block> Blockchain::chain(){
  return mainchain;
}

Block Blockchain::lastEntry(){
  return mainchain.back();
}

void Blockchain::newBlock(Block b){
  b.previousHash = lastEntry().blockHash;
  b.mine(difficulty);
  mainchain.push_back(b);
}

bool Blockchain::checkChain(){

  for (int i = 1; i < mainchain.size(); i++) {
    Block current = mainchain[i];
    Block previous = mainchain[i-1];

    if (current.blockHash != current.computeHash()) {
      return false;
    }

    if (current.previousHash != previous.blockHash) {
      return false;
    }

  }
  return true;

}

void Blockchain::displayChain(){
  for (int i = 1; i < mainchain.size(); i++) {
    Block spotlight  = mainchain[i];
    std::cout <<"######################################" << '\n';
    std::cout <<"INDEX:"<<i<< '\n';
    std::cout <<"TIMESTAMP:"<<spotlight.creationtime<< '\n';
    std::cout <<"PREVIOUS HASH:"<<spotlight.previousHash<< '\n';
    std::cout <<"TRANSACTION:"<<spotlight.data.compressOut()<< '\n';
    std::cout <<"#######################################"<< '\n';
    std::cout << "  @@" << '\n';
    std::cout << "  @@" << '\n';
    std::cout << "  @@" << '\n';
    std::cout << " \\//" << '\n';
    std::cout << "  \/" << '\n';

  }

}

/*
ERASE newBlock()









*/
