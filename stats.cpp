#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& values) {
    //Implement statistics here
    Stats obj;
    float obj.max = values.front();
    float obj.min = values.front();
    for(int index = 0, float sum=0.0 ; index < values.size() ; index++)
    {    
        sum += values[index];
        if(obj.max < values[index])
            obj.max = values[index];
        if(obj.min > values[index])
            obj.min = values[index];
    }   
    obj.average = sum / values.size();
    
    return obj;       
}
