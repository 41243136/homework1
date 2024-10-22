#include <iostream>
#include <algorithm>

using namespace std;


void powerset(char set[], int setSize, int index = 0, string current = "") {// �λ��j�ͦ�����
    
    if (index == setSize) {
        cout << "{" << current << "} ";// �p�G��F���X�����A���L��e���l��
        return;
    }

    
    powerset(set, setSize, index + 1, current);// ���j�a����ܷ�e����

    
    powerset(set, setSize, index + 1, current + set[index]);// ���j�a��ܷ�e����
}

int main() {
    int setSize;

    
    cout << "�п�J���X���j�p�G";// ��J���X�j�p
    cin >> setSize;

    char* set = new char[setSize];// �ʺA���t�}�C

    
    cout << "�п�J���X�������G";// ��J���X����
    for (int i = 0; i < setSize; ++i) {
        cin >> set[i];
    }

    // �N��J�����X���r�����ǱƧ�
    sort(set, set + setSize);

   
    cout << "{ ";
    powerset(set, setSize); //��X���G
    cout << "}" << endl;

    delete[] set; // ����ʺA�O����t�m�ҰO����

    return 0;
}
