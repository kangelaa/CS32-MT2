//
//  main.cpp
//  Midterm 2
//
//  Created by Angela Kan on 2/23/21.
//
//
//#include <vector>
//#include <list>
//#include <string>
//#include <algorithm>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
//// COMMENT AFTER THE END OF THE removeEverySecond IMPLEMENTATION
//
//template<typename Cont, typename Iter>
//void removeEverySecond(Cont& container, Iter iterator){
//    while (iterator != container.end()){
//        iterator = container.erase(iterator);
//        if (iterator == container.end()){
//            return;
//        }
//        iterator++;
//    }
//}
//
//// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
//// COMMENT BEFORE THE START OF THE removeEverySecond IMPLEMENTATION
//
//int main()
//{
//    string a1[9] = { "30", "80", "70", "20", "60", "10", "90", "40", "50" };
//    string expected1[6] = { "30", "80", "70", "60", "90", "50" };
//    int a2[9] = { 30, 80, 70, 20, 60, 10, 90, 40, 50 };
//    int expected2[5] = { 30, 80, 20, 10, 40 };
//
//    vector<string> v1(a1, a1+9);  // construct v1 from the array
//    removeEverySecond(v1, v1.begin()+3);  // starting at position 3, the "20"
//    assert(v1.size() == 6);
//      // std::equal returns true if the values at corresponding positions
//      // in the two ranges are equal
//    assert(std::equal(v1.begin(), v1.end(), expected1, expected1+6));
//    cout << "Passed test 1" << endl;
//
//    vector<int> v2(a2, a2+9);
//    removeEverySecond(v2, v2.begin()+2);  // starting at position 2, the 70
//    assert(v2.size() == 5);
//    assert(std::equal(v2.begin(), v2.end(), expected2, expected2+5));
//    cout << "Passed test 2" << endl;
//
//    list<string> l1(a1, a1+9);
//    list<string>::iterator p1 = l1.begin();
//    for (int k = 0; k < 3; k++)
//        p1++;
//    removeEverySecond(l1, p1);  // starting at position 3, the "20"
//    assert(l1.size() == 6);
//    assert(std::equal(l1.begin(), l1.end(), expected1, expected1+6));
//    cout << "Passed test 3" << endl;
//
//    list<int> l2(a2, a2+9);
//    list<int>::iterator p2 = l2.begin();
//    for (int k = 0; k < 2; k++)
//        p2++;
//    removeEverySecond(l2, p2);  // starting at position 2, the 70
//    assert(l2.size() == 5);
//    assert(std::equal(l2.begin(), l2.end(), expected2, expected2+5));
//    cout << "Passed test 4" << endl;
//}

#include <iostream>
#include <cassert>
using namespace std;

struct Node
{
    int   data;
    Node* child[3];
};

// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE END OF THE countLessers FUNCTION

int countLessers(const Node* p)
{
    if (p == nullptr){
        return 0;
    }
    int count = 0;
    int compareData = p->data;
    bool foundLesser = false;
    for (int i=0; i<3; i++){
        if (p->child[i] != nullptr){
            if (compareData < p->child[i]->data){
                foundLesser = true;
            }
            count += countLessers(p->child[i]);
        }
    }
    if (foundLesser){
        count++;
    }
    return count;
}

//TODO: THIS IS THE ONE U SUBMITTED!!!!
//int countLessers(const Node* p)
//{
//    if (p == nullptr)
//        return 0;
//    int sum = 0;
//    bool foundLesser = false;
//    for (int i=0; i<3; i++){
//        if (p->child[i] != nullptr){
//            foundLesser = foundLesser || p->data < p->child[i]->data;
//            sum += countLessers(p->child[i]);
//        }
//    }
//    sum = foundLesser ? sum + 1 : sum;
//    return sum;
//}
// SUBMIT AS YOUR ANSWER ONLY THE CODE BETWEEN THIS COMMENT AND THE
// COMMENT AT THE START OF THE countLessers FUNCTION

Node* makeNode(int d)
{
     Node* p = new Node;
     p->data = d;
     for (int k = 0; k < 3; k++)
         p->child[k] = nullptr;
     return p;
}

int main()
{
      // Build the 3-tree pictured in the problem as an example

    Node* n8 = makeNode(8);
    n8->child[2] = makeNode(3);
 
    Node* n2 = makeNode(2);
    n2->child[1] = n8;
     
    Node* n5 = makeNode(5);
    n5->child[0] = makeNode(8);
    n5->child[2] = makeNode(9);
     
    Node* n7 = makeNode(7);
    n7->child[1] = n5;
 
    Node* root = makeNode(4);
    root->child[0] = n2;
    root->child[1] = makeNode(1);
    root->child[2] = n7;
    
      // Test countLessers with that tree
 
    assert(countLessers(root) == 3);
    assert(countLessers(root->child[2]) == 1);
    assert(countLessers(nullptr) == 0);
    cout << "All tests succeeded" << endl;

      // Clean up the tree

    delete n8->child[2];
    delete n8;
    delete n2;
    delete root->child[1];
    delete n5->child[0];
    delete n5->child[2];
    delete n5;
    delete n7;
    delete root;
}
