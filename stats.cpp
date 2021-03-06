#include "stats.h"
#include <math.h>

Stats Statistics::ComputeStatistics(const std::vector<float>& values) {
    //Implement statistics here
    Stats obj;
    if(values.size() == 0)
    {
       obj.max = NAN;
       obj.min = NAN;
       obj.average = NAN; 
    }
    else
    {    
       obj.max = values.front();
       obj.min = values.front();
       float sum=0.0;
       for(size_t index = 0; index < values.size() ; index++)
       {    
          sum += values[index];
          if(obj.max < values[index])
             obj.max = values[index];
          if(obj.min > values[index])
            obj.min = values[index];
       }   
       obj.average = sum / values.size();
    }
    
    return obj;       
}

EmailAlert::EmailAlert()
{
   emailSent = false;   
} 
void EmailAlert::sendAlert()
{
   emailSent = true; 
}

LEDAlert::LEDAlert()
{
   ledGlows = false;   
} 
void LEDAlert::sendAlert()
{
   ledGlows = true; 
}

void StatsAlerter :: checkAndAlert( const std::vector<float>& values)
{
   Stats obj = Statistics::ComputeStatistics(values);
   if (obj.max > maxThreshold)
   {
      for( size_t i = 0; i<alerters.size(); i++)
      {
         alerters[i]->sendAlert();
      }     
   }
}
