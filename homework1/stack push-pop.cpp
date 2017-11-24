#include <iostream>
#include <string>

using namespace std;

template <class T>
struct node {
    T data;
    node* next = NULL;
    node* prevMax = NULL;
};

template <class T>
class LStack {

    private:
    node<T>* topNode;
    node<T>* maxVal;
    void copy(node<T>* toCopy);
    void eraseStack();
    void copyStack(LStack const&);

    public:
    LStack();
    LStack(LStack const&);
    LStack& operator=(LStack const&);
    ~LStack();
    bool empty() const;
    void push(T const& x);
    T pop();
    T top() const;
    T maxEl() const;
};

int main()
{
    /*unsigned short type; // Problem 1
    unsigned int N, x;
    LStack <unsigned int> krek;
    cin >> N;
    while(N--)
    {
        cin >> type;
        switch (type)
        {
            case 1:{cin >> x; krek.push(x); break;}
            case 2:{krek.pop();break;}
            case 3: cout << "Max:" << krek.maxEl() << '\n';
        }
    }*/

    unsigned short n_games;
    cin >> n_games;
    while(n_games--)
    {
    unsigned int a_size, b_size, limit, x, sum;
    cin >> a_size >> b_size >> limit;
    string currentBest, current;
    unsigned short index = 1;
    LStack <unsigned int> reversed_stack; //Za6to vyrhyt na steka trqbva da e pryv?
    LStack <unsigned int> copyA;
    LStack <unsigned int> copyB;
    while(a_size--){
        cin >> x;
        reversed_stack.push(x);
    }
    while(!reversed_stack.empty())
        copyA.push(reversed_stack.pop());
    const LStack <unsigned int> A = copyA;
    while(b_size--){
        cin >> x;
        reversed_stack.push(x);
    }
    while(!reversed_stack.empty())
        copyB.push(reversed_stack.pop());
    const LStack <unsigned int> B = copyB;
    do
    {
    --index;
    current="";
    sum = 0;
    copyA = A;
    copyB = B;
    for(int i = 0; i < index; ++i)
    {
        if (currentBest[ i ] == 'A') {sum += copyA.pop() ; current += 'A';}
        else {sum += copyB.pop(); current += 'B';}
    }
    if(currentBest.length() > 0)
        if ((currentBest[ index ] == 'A') && (!copyB.empty())) {sum += copyB.pop() ; current += 'B';}
        else if ((currentBest[ index ] == 'A') && (copyB.empty())) continue;
        else if ((currentBest[ index ] == 'B') && (!copyA.empty())) {sum += copyA.pop(); current += 'A';}
        else continue;
    while(sum <= limit)
    {
        if((!copyA.empty()) && (!copyB.empty()))
            if(copyA.top() < copyB.top()) {sum += copyA.pop() ; current += 'A';}
            else {sum += copyB.pop(); current += 'B';}
        else if((!copyA.empty()) || (!copyB.empty()))
            if(copyA.empty()) {sum += copyB.pop(); current += 'B';}
            else {sum += copyA.pop(); current += 'A';}
        else {current += 'C'; break;}
    }
    if (current.length() > 0)  current.resize (current.length() - 1);
    if (current.length() > currentBest.length())
    {
        currentBest = current;
        index = currentBest.length();
        cout << currentBest << '\t' << currentBest.length() << '\n';
    }
    }while(index > 0);
    //cout << currentBest.length() << '\n';
    }
    return 0;
}

template <class T>
LStack<T>::LStack() : topNode(NULL), maxVal(NULL) {}

template <class T>
bool LStack<T>::empty() const {
    return topNode == NULL;
}

template <class T>
void LStack<T>::push(T const& x) {
    node<T>* p = new node<T>;
    p->data = x;
    p->next = topNode;
    if(empty())
        maxVal = p;
    topNode = p;
    if(x >= maxVal->data && p!= maxVal)
    {
        p->prevMax = maxVal;
        maxVal = p;
    }
}

template <class T>
T LStack<T>::pop() {
    if (empty())
    {
        cout << "Empty stack!(cannot pop)\n";
        return 0;
    }
    if (topNode->data == maxVal->data)
        maxVal = topNode->prevMax;
    node<T>* p = topNode;
    topNode = topNode->next;
    T x = p->data;
    delete p;
    return x;
}

template <typename T>
T LStack<T>::top() const {
    if (empty())
    {
        cout << "Empty stack!\n";
        return 0;
    }
    return topNode->data;
}

template <typename T>
void LStack<T>::eraseStack() {
    while (!empty())
        pop();
}

template <typename T>
LStack<T>::~LStack() {
    eraseStack();
}

template <typename T>
void LStack<T>::copy(node<T>* toCopy) {
    if (toCopy == NULL)
        return;
    copy(toCopy->next);
    push(toCopy->data);
}

template <typename T>
void LStack<T>::copyStack(LStack const& ls) {
    topNode = NULL;
    copy(ls.topNode);
}

template <typename T>
LStack<T>::LStack(LStack const& ls) {
    copyStack(ls);
}

template <typename T>
LStack<T>& LStack<T>::operator=(LStack const& ls) {
    if (this != &ls)
    {
        eraseStack();
        copyStack(ls);
    }
    return *this;
}

template <typename T>
T LStack<T>::maxEl() const {
    if (empty())
    {
        cout << "Empty stack! ";
        return 0;
    }
    return maxVal->data;
}
