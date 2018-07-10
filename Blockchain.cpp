#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "BlockchainClasses.hpp"
#include "sha256"

// function declarations go here

using namespace std;

void Block::printBlock(){
  cout <<index<< '\n';
  cout <<creationtime<< '\n';
  cout <<previousHash<< '\n';
}

int Block::index(){
  return index;
}

size_t Block::getPrevHash(){
  return previousHash;
}

size_t Block::getBlockHash(){
  return blockHash;
}

bool Block::hashCheck(){
  return (computeHash()== getBlockHash());
}

size_t Block::computeHash(){

}

void Blockchain::Genesis(){
  Block genesis = Block(0,NULL,NULL);
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
  mainchain.push_back(b);
}

bool Blockchain::checkChain(){

}

void Blockchain::displayChain(){

}
