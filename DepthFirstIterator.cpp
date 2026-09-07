#include "DepthFirstIterator.h"

DepthFirstIterator::DepthFirstIterator(DeliveryComponent* root){
    this->root  = root;
}

DepthFirstIterator::~DepthFirstIterator(){

}

void DepthFirstIterator::first(){
    while(!nodes.empty()){
        nodes.pop();
    }
    if(root != nullptr){
        nodes.push(root);
    }else{
        return;
    }
}

void DepthFirstIterator::next(){
    if(nodes.empty()){
        return;
    }

    DeliveryComponent* cmp = nodes.top();
    nodes.pop();

    for(int i = cmp->childCount() - 1; i >= 0; i--){
        DeliveryComponent* child = cmp->getChild(i);
        if(child != nullptr){
            nodes.push(child);
        }
    }
}

bool DepthFirstIterator::isDone(){
    return nodes.empty();
}

DeliveryComponent* DepthFirstIterator::current(){
   return nodes.top();
}
