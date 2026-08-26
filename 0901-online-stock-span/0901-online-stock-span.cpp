class StockSpanner {
public:
    vector<int> arr;
    stack<int> s;

    StockSpanner() {}

    int next(int price) {
        int i = arr.size();
        arr.push_back(price);

        // Remove all previous prices <= current price
        while (!s.empty() && arr[s.top()] <= price) {
            s.pop();
        }

        // No previous greater element
        int span;
        if (s.empty()) {
            span = i + 1;
        }
        else {
            span = i - s.top();
        }

        // Store current index
        s.push(i);

        return span;
    }
};