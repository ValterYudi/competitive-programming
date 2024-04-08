#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

struct Gadget{
    int type, cost, index;
};

bool compareByCost(const Gadget& a, const Gadget& b){
    return a.cost < b.cost;
}

int main(){
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    
    vector<int> dollarRates(n);
    vector<int> poundRates(n);
    
    for(int i = 0; i < n; ++i){
        cin >> dollarRates[i];
    }
    
    for(int i = 0; i < n; ++i){
        cin >> poundRates[i];
    }
    
    vector<Gadget> gadgets(m);
    
    for(int i = 0; i < m; ++i){
        cin >> gadgets[i].type >> gadgets[i].cost;
        gadgets[i].index = i + 1;
    }
    
    vector<Gadget> dollarGadgets, poundGadgets;
    
    for(int i = 0; i < m; ++i){
        if (gadgets[i].type == 1){
            dollarGadgets.push_back(gadgets[i]);
        }else{
            poundGadgets.push_back(gadgets[i]);
        }
    }
    
    sort(dollarGadgets.begin(), dollarGadgets.end(), compareByCost);
    sort(poundGadgets.begin(), poundGadgets.end(), compareByCost);
    
    int minDayIndex = n + 1;
    vector<pair<int, int>> purchases;
    
    for(int i = 0, j = 0, totalCost = 0, gadgetsBought = 0; i < dollarGadgets.size() || j < poundGadgets.size(); ) {
        if(gadgetsBought >= k){
            break;
        }
        
        if(i < dollarGadgets.size() && dollarGadgets[i].cost <= s){
            totalCost += dollarGadgets[i].cost;
            purchases.push_back({dollarGadgets[i].index, i + 1});
            ++i;
        }else if(j < poundGadgets.size() && poundGadgets[j].cost <= s){
            totalCost += poundGadgets[j].cost;
            purchases.push_back({poundGadgets[j].index, j + 1});
            ++j;
        }else{
            break;
        }
        
        ++gadgetsBought;
        
        while(i < dollarGadgets.size() && dollarGadgets[i].cost > s){
            ++i;
        }
        
        while(j < poundGadgets.size() && poundGadgets[j].cost > s){
            ++j;
        }
        
        if(gadgetsBought == k && totalCost <= s){
            minDayIndex = min(minDayIndex, max(i, j) + 1);
        }
    }
    
    if(minDayIndex == n + 1 || purchases.size() < k){
        cout << -1 << endl;
    }else{
        cout << minDayIndex << endl;
        for(int i = 0; i < k; ++i){
            cout << purchases[i].first << " " << purchases[i].second << endl;
        }
    }
    
    return 0;
}