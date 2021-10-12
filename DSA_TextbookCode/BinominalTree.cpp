#include <iostream>
#include <string>
using namespace std;
template <class T>
class BinaryTree{
private:
    BinaryTreeNode<T>* root;
public:
    BinaryTree(){
        root = NULL; 
    };
    ~BinaryTree() { 
        DeleteBinaryTree(root); 
    };
    bool isEmpty() 
        const;
    BinaryTreeNode<T>* Root() {
        return root;
    };


    T1 key;  //�ؼ���
    T2 value;  //ֵ
    Pair(T1 k, T2 v) :key(k), value(v) { };
    bool operator < (const Pair<T1, T2>& p) const;
};
template<class T1, class T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2>& p) const
    //Pair�ĳ�Ա���� operator <
{ //"С"����˼���ǹؼ���С
    return key < p.key;
}
int main()
{
    Pair<string, int> student("Tom", 19); //ʵ������һ���� Pair<string,int>
    cout << student.key << " " << student.value;
    return 0;
}

