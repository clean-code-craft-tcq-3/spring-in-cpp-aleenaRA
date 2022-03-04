#include <vector>

class Stats
{
   public:
      float average, min , max;
       Stats()
       {
       }    
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& );
}


class IAlerter
{
public:
   virtual void sendAlert()
   {
   }
};


class EmailAlert : public IAlerter
{
   public:
      bool emailSent;
      EmailAlert()
      {
         emailSent = false;   
      } 
      void sendAlert()
      {
         emailSent = true; 
      }
};

class LEDAlert : public IAlerter
{
   public:
      bool ledGlows;
      LEDAlert()
      {
         ledGlows = false;   
      } 
     void sendAlert()
     {
         ledGlows = true; 
     }
};

class StatsAlerter
{
    float maxThreshold;
    std::vector<IAlerter*> alerters;
    public:
    StatsAlerter( float lmaxThresh, std::vector<IAlerter*> lalerts) :maxThreshold(lmaxThresh), alerters(lalerts)
    {
    }
    void checkAndAlert(const std::vector<float>& values);
};
