#include <iostream>
#include <algorithm>

using namespace std;


void powerset(char set[], int setSize, int index = 0, string current = "") {// 用遞迴生成冪集
    
    if (index == setSize) {
        cout << "{" << current << "} ";// 如果到達集合末尾，打印當前的子集
        return;
    }

    
    powerset(set, setSize, index + 1, current);// 遞迴地不選擇當前元素

    
    powerset(set, setSize, index + 1, current + set[index]);// 遞迴地選擇當前元素
}

int main() {
    int setSize;

    
    cout << "請輸入集合的大小：";// 輸入集合大小
    cin >> setSize;

    char* set = new char[setSize];// 動態分配陣列

    
    cout << "請輸入集合的元素：";// 輸入集合元素
    for (int i = 0; i < setSize; ++i) {
        cin >> set[i];
    }

    // 將輸入的集合按字母順序排序
    sort(set, set + setSize);

   
    cout << "{ ";
    powerset(set, setSize); //輸出結果
    cout << "}" << endl;

    delete[] set; // 釋放動態記憶體配置所記憶體

    return 0;
}
