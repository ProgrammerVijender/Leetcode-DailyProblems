class ProductOfNumbers {
public:
    // int index = -1;
        vector <int> v;
    ProductOfNumbers() {
        v.push_back(-1);
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int siz = v.size();
        int val = 1;
        int t = siz - k;
        
        while(t != siz)
        {
            val *= v[t];
            t++;
        }


        return val;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */