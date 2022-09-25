class MyCircularQueue {
public:
    vector<int> vv;
    int de_point = 0;
    int en_point =0;
    int curr_size  =0;

    int max_size = 0;
    
    MyCircularQueue(int k) {
        vv.resize(k);
        max_size = vv.size();

        
        
    }
    
    bool enQueue(int value) {
        //cout<<"error val?? "<<value<<"\n";
        if (isFull()) return false;
        
        if (isEmpty()){en_point = 0; de_point=0;vv[en_point]=value; curr_size++; return true;}
        //cout<< "adding "<<value << endl;
        en_point = (en_point+1) % max_size;
        vv[en_point] = value;
        curr_size++;
        //en_point;
        //cout << isFull() << ' '<<isEmpty()<<endl;
       // for (auto kk:vv)
        //    cout <<kk<<" ";
        //cout<<endl;
        return true;
    }
    
    bool deQueue() {
        //cout<<"error deque?? \n";
        if (isEmpty()){en_point = 0; de_point=0; return false;}
        curr_size--;
        de_point++;
        de_point = de_point % max_size;
        
        //for (auto kk:vv)
        //    cout <<kk<<" ";
        //cout<<endl;
        return true;
        

    }
    
    int Front() {
        //cout<< "error front??"<<endl;
        if (isEmpty()) return -1;
        //cout <<de_point << " is de_point\n";

        return vv[de_point];
    }
    
    int Rear() { 
        //c/out<<" error rear?? "<<endl;
        if (isEmpty()) return -1;
        //cout <<en_point << " is en_point\n";
        return vv[en_point];
        
    }
    
    bool isEmpty() {
        if (curr_size == 0) return true;
        return false;
    }
    
    bool isFull() {
        if (curr_size == max_size) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */