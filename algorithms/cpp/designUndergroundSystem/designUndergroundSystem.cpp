// Source: https://leetcode.com/problems/design-underground-system/
// Author: Miao Zhang
// Date:   2021-04-29

class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        id_[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        const auto& [s0, t0] = id_[id];
        string key = s0 + "_" + stationName;
        station_[key].first += (t - t0);
        station_[key].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        const auto& [sums, cnt] = station_[startStation + "_" + endStation];
        return static_cast<double>(sums) / cnt;
    }

private:
    unordered_map<int, pair<string, int>> id_; // id->{station, t}
    unordered_map<string, pair<int, int>> station_; // trip(from_to)-> {sum, cnt}
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
