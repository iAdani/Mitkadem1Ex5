// Author: Guy Adani 208642884

#include "HybridAnomalyDetector.h"

HybridAnomalyDetector::HybridAnomalyDetector() {
}

HybridAnomalyDetector::~HybridAnomalyDetector() {
}

// decides which funcion calculates the threshold depending on correlation
float HybridAnomalyDetector::calcThres(vector<Point*> points, Line reg, Circle minCir, float cor) {
    if (cor > 0.9) {
	    return maxDev(points, reg);
    }

    // else the correlation is between 0.5-0.9
    return minCir.radius;
}

bool HybridAnomalyDetector::detected(Point p, correlatedFeatures corFeat) {
    if (corFeat.corrlation > 0.9) {
        return SimpleAnomalyDetector::detected(p, corFeat);
    }

    // else the correlation is between 0.5-0.9
    float distance = dist(corFeat.min_cir.center, p);
    return distance > corFeat.threshold;
}
