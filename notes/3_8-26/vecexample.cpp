#include <iostream>
#include <vector>

using namespace std;

int main () {

  vector<int> intVec;

  // display initial size and capacity of vector (both = 0)
  cout << "Initial size of vector: " << intVec.size() << endl;
  cout << "Initial capacity of vector: " << intVec.capacity() << endl;

  // add three values to the end of the vector
  intVec.push_back(5);
  intVec.push_back(4);
  intVec.push_back(3);

  // display current size and capacity of vector
  cout << "Current size of vector: " << intVec.size() << endl;
  cout << "Current capacity of vector: " << intVec.capacity() << endl;

  // display vector contents using a forward iterator, ++i is used to avoid a temporary variable
  vector<int>::const_iterator i;
  for (i = intVec.begin(); i != intVec.end(); ++i) 
    cout << *i << "  ";

  cout << endl;

  // display vector contents using a reverse iterator, ++i is used to avoid a temporary variable
  vector<int>::const_reverse_iterator r;
  vector<int>::const_reverse_iterator end = intVec.rend();
  for (r = intVec.rbegin(); r != end; ++r) 
    cout << *r << "  ";

  cout << endl;

}
