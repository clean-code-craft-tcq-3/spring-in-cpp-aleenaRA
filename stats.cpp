#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& values) {
    //Implement statistics here
    Stats obj;
    for(int index = 0, float sum=0.0 ; index < values.size() ; index++)
        sum += values[index];
    obj.average = sum / values.size();
    
    return obj;
        
}
