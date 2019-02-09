//
// Created by Olcay Taner Yıldız on 9.02.2019.
//
#include <cfloat>
#include "GaussianModel.h"
#include "../Instance/CompositeInstance.h"

/**
 * The predict method takes an Instance as an input. First it gets the size of prior distribution and loops this size times.
 * Then it gets the possible class labels and and calculates metric value. At the end, it returns the class which has the
 * maximum value of metric.
 *
 * @param instance {@link Instance} to predict.
 * @return The class which has the maximum value of metric.
 */
string GaussianModel::predict(Instance *instance) {
    string predictedClass;
    string Ci;
    vector<string> possibleLabels;
    double metric;
    double maxMetric = -DBL_MAX;
    int size;
    if (instance->isComposite()) {
        predictedClass = dynamic_cast<CompositeInstance*>(instance)->getPossibleClassLabels().at(0);
        size = dynamic_cast<CompositeInstance*>(instance)->getPossibleClassLabels().size();
    } else {
        predictedClass = priorDistribution.getMaxItem();
        size = priorDistribution.size();
        possibleLabels = priorDistribution.getItems();
    }
    for (int i = 0; i < size; i++) {
        if (instance->isComposite()) {
            Ci = dynamic_cast<CompositeInstance*>(instance)->getPossibleClassLabels().at(i);
        } else {
            Ci = possibleLabels.at(i);
        }
        if (priorDistribution.containsItem(Ci)) {
            metric = calculateMetric(instance, Ci);
            if (metric > maxMetric) {
                maxMetric = metric;
                predictedClass = Ci;
            }
        }
    }
    return predictedClass;
}
