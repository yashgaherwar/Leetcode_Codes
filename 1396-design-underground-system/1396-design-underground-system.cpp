class UndergroundSystem {
public:
    map<int,pair<int,string>> ety;     //{id,{entry time,entry station}}
    
    map<pair<string,string>,int> sum; 
    
    map<pair<string,string>,int> count; 
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ety[id]={t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        double kk=(t-ety[id].first);
        
        sum[{ety[id].second,stationName}]+=kk;
        count[{ety[id].second,stationName}]++;
        ety.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return ((double)sum[{startStation,endStation}])/count[{startStation,endStation}];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */