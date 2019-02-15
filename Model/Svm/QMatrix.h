//
// Created by Olcay Taner Yıldız on 15.02.2019.
//

#ifndef CLASSIFICATION_Q_H
#define CLASSIFICATION_Q_H

#include "Kernel.h"
#include "Problem.h"

class QMatrix {
private:
    Kernel kernel = Kernel();
    vector<double> y;
public:
    QMatrix(Problem problem, SvmParameter* parameter, vector<double> y);
    QMatrix();
    vector<double> getQ(int i, int length);
    void swapIndex(int i, int j);
};


#endif //CLASSIFICATION_Q_H
