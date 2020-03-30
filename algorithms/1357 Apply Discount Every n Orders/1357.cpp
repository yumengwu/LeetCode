#include "../header.h"

static auto magic = []() {ios_base::sync_with_stdio(false); cin.tie(nullptr); return false; }();
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        en = n;
        cnt = 0;
        dis = discount;
        for (int i = 0; i < products.size(); ++i) {
            m[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double res = 0;
        for (int i = 0; i < product.size(); ++i) {
            res += m[product[i]] * amount[i];
        }
        if (++cnt == en) {
            res -= (dis * res + 0.0) / 100;
            cnt = 0;
        }
        return res;
    }
    
private:
    int en;
    int cnt;
    int dis;
    unordered_map<int, int> m;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */