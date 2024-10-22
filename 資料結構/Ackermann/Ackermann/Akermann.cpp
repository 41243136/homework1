#include <iostream>
#include <stack>

using namespace std;

// �D���j��{ Ackermann ���
int ackermann(int m, int n) {
    stack<pair<int, int>> s; //�ŧi�@�Ӱ��|  �ΰ��|�Ӽ������j
    s.push({ m, n }); //�N m �M n �@�� �@��pair���J���|��

    while (!s.empty()) {
        pair<int, int> top = s.top(); // ���X���|����������
        m = top.first; // �ݭp�⪺ m �M n
        n = top.second;
        s.pop(); //�N�L�̱q���|���u�X

        if (m == 0) { //�p�G m ����0
            n += 1; // n + 1
            if (!s.empty()) {  //�p�G���|���O�Ū�
                s.top().second = n; // ��s���|���� n ��
            }
        }
        else if (m > 0 && n == 0) { //�p�G m �j��0�B n == 0
            s.push({ m - 1, 1 }); //�N(m-1, 1)���J���|
        }
        else if (m > 0 && n > 0) { //�p�G m > 0 �B n > 0
            s.push({ m - 1, -1 }); // �Ȯɥ� -1 �ӼаO�������A
            s.push({ m, n - 1 });
        }
        else if (n == -1) { // �B�z�^���ɡAn == -1 ��ܻݭn�p�⪺�������G
            int tmp = s.top().second; // ���X���|���� n
            s.pop(); // �u�X����i�h�� m-1, -1
            s.push({ m - 1, tmp }); // �N�p�⵲�G��^���|
        }
    }

    return n;
}

int main() {
    int m, n;
    cout << "�п�J m �M n ����: "; //��X �п�J m �M n ����
    cin >> m >> n; //��J m �M n 
    cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl; //��X���G
    return 0;
}
