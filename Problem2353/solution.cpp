/* 
Time Complexity: O(n log n) and O(log n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:

    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };

    unordered_map<string, pair<string,int>> foodmap;
    unordered_map<string, priority_queue<pair<int, string>,vector<pair<int,string>>,Compare>> cuisinemap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            foodmap[foods[i]] = { cuisines[i],ratings[i] };
            cuisinemap[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodmap[food].second = newRating;
        cuisinemap[foodmap[food].first].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        if (cuisinemap[cuisine].empty()) return "";

        pair<int, string> current = cuisinemap[cuisine].top();
        while (current.first != foodmap[current.second].second) {
            cuisinemap[cuisine].pop();
            current = cuisinemap[cuisine].top();
        }

        return current.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */