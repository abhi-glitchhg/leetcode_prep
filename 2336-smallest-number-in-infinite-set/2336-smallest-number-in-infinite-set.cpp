class SmallestInfiniteSet {
set<int> val;
int untouched = 1;
    public:
    SmallestInfiniteSet() {

    
    }
    
    int popSmallest() {
        if (*val.begin()== 0){
            untouched++;
            return untouched-1;
        }
        int to_be_returned = min(*val.begin(), untouched);
        cout << *val.begin()<< untouched << endl;
        //cout<< *val.begin() << *val.end()<< endl;
        if ( to_be_returned == untouched) untouched++;
        else 
          val.erase(to_be_returned);
        return to_be_returned;
    }
    
    void addBack(int num) {
        
        if (val.find(num) == val.end() && num< untouched ) val.insert(num);
        for (int x:val)
            cout << x<< " ";
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */