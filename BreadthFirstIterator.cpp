#include "BreadthFirstIterator.h"

BreadthFirstIterator::BreadthFirstIterator(DeliveryComponent* root){
    this->root = root;
    first();
}

BreadthFirstIterator::~BreadthFirstIterator(){

}

void BreadthFirstIterator::first(){
    while(!nodes.empty()){
        nodes.pop();
    }
    if(root != nullptr){
        nodes.push(root);
    }
}

void BreadthFirstIterator::next(){
    if(nodes.empty()){
        return;
    }

    DeliveryComponent* cmp = nodes.front();
    nodes.pop();

    for(int i = 0; i < cmp->childCount(); i++){
        DeliveryComponent* child = cmp->getChild(i);
        if(child != nullptr){
            nodes.push(child);
        }
    }
}

bool BreadthFirstIterator::isDone(){
    return nodes.empty();
}

DeliveryComponent* BreadthFirstIterator::current(){
    return nodes.front();
}
