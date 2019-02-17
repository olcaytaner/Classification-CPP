//
// Created by Olcay Taner Yıldız on 16.02.2019.
//

#ifndef CLASSIFICATION_DECISIONTREE_H
#define CLASSIFICATION_DECISIONTREE_H
#include "../ValidatedModel.h"
#include "DecisionNode.h"

class DecisionTree : public ValidatedModel{
private:
    DecisionNode root;
    void pruneNode(DecisionNode decisionNode, InstanceList pruneSet);
public:
    string predict(Instance* instance) override;
    explicit DecisionTree(DecisionNode root);
    void prune(InstanceList pruneSet);
};


#endif //CLASSIFICATION_DECISIONTREE_H