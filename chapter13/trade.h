#include <memory>
#include <vector>

#include "asset.h" 

namespace stock_prices
{
    class Exchange
    {
        double initial_funds{100.0};
        double funds{ initial_funds };
        int number_of_assets{};
        std::unique_ptr<Asset> asset{}; 
        std::vector<double> prices{};

        public:
        Exchange(int number_of_assets, std::unique_ptr<Asset> asset) 
            : number_of_assets(number_of_assets), asset(std::move(asset))
        {
        }
        explicit Exchange(int number_of_assets)
            : Exchange(number_of_assets, nullptr)
        {
        }
        double next_price();
        std::vector<double> get_prices() const
        {
            return prices;
        }
    };

    double trading_game(Exchange & exchange);
}
