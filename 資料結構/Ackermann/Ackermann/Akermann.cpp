#include <iostream>
#include <stack>

using namespace std;

// 非遞迴實現 Ackermann 函數
int ackermann(int m, int n) {
    stack<pair<int, int>> s; //宣告一個堆疊  用堆疊來模擬遞迴
    s.push({ m, n }); //將 m 和 n 作為 一個pair推入堆疊中

    while (!s.empty()) {
        pair<int, int> top = s.top(); // 取出堆疊頂部的元素
        m = top.first; // 需計算的 m 和 n
        n = top.second;
        s.pop(); //將他們從堆疊中彈出

        if (m == 0) { //如果 m 等於0
            n += 1; // n + 1
            if (!s.empty()) {  //如果堆疊不是空的
                s.top().second = n; // 更新堆疊中的 n 值
            }
        }
        else if (m > 0 && n == 0) { //如果 m 大於0且 n == 0
            s.push({ m - 1, 1 }); //將(m-1, 1)推入堆疊
        }
        else if (m > 0 && n > 0) { //如果 m > 0 且 n > 0
            s.push({ m - 1, -1 }); // 暫時用 -1 來標記中間狀態
            s.push({ m, n - 1 });
        }
        else if (n == -1) { // 處理回溯時，n == -1 表示需要計算的中間結果
            int tmp = s.top().second; // 取出堆疊中的 n
            s.pop(); // 彈出剛剛放進去的 m-1, -1
            s.push({ m - 1, tmp }); // 將計算結果放回堆疊
        }
    }

    return n;
}

int main() {
    int m, n;
    cout << "請輸入 m 和 n 的值: "; //輸出 請輸入 m 和 n 的值
    cin >> m >> n; //輸入 m 和 n 
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl; //輸出結果
    return 0;
}
