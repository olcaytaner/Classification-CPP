//
// Created by olcay on 6.02.2019.
//

#include "StratifiedKFoldCrossValidation.h"
#include "StratifiedKFoldRun.h"

/**
 * Constructor for KFoldRun class. Basically sets K parameter of the K-fold cross-validation.
 * @param K K of the K-fold cross-validation.
 */
StratifiedKFoldRun::StratifiedKFoldRun(int K) : KFoldRun(K) {
}

/**
 * Execute Stratified K-fold cross-validation with the given classifier on the given data set using the given parameters.
 *
 * @param experiment Experiment to be run.
 * @return An array of performances: result. result[i] is the performance of the classifier on the i'th fold.
 */
ExperimentPerformance *StratifiedKFoldRun::execute(Experiment experiment) {
    ExperimentPerformance* result = new ExperimentPerformance();
    StratifiedKFoldCrossValidation<Instance*>* crossValidation = new StratifiedKFoldCrossValidation<Instance*>(experiment.getDataSet().getClassInstances(), K, K, experiment.getParameter()->getSeed());
    runExperiment(experiment.getClassifier(), experiment.getParameter(), result, crossValidation);
    return result;
}
