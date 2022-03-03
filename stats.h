#include <vector>

namespace Statistics {
    
    class Stats{
        public:
        float average, min , max;
    };
    Stats ComputeStatistics(const std::vector<float>& );
}
