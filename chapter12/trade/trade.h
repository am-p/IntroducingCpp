#include <memory>
#include <vector>

#include "stock.h"

namespace stock_prices
{
    class Exchange 
    {
        double initial_funds{}; 
        double funds{ initial_funds }; 
        int number_of_assets{}; 
        std::unique_ptr<Stock> asset{}; 
        std::vector<double> prices{}; 

        public:
        explicit Exchange(int number_of_assets)
            : number_of_assets(number_of_assets) 
        {
        }
        double next_price(); 
        std::vector<double> get_prices() const 
        {
            return prices;
        }
    };
}
