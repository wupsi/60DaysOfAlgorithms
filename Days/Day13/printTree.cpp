#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string do_padding (unsigned index, unsigned mlength){
  string padding;
  if (int((index-1)/2) != 0){
    return (int((index-1)/2) % 2 == 0) ?
    (do_padding(int((index-1)/2),mlength) + string(mlength+4,' ') + " ")  :
    (do_padding(int((index-1)/2),mlength) + string(mlength+3,' ') + " |") ;
  }
  return padding;
}

void printer (vector<int> const & tree, unsigned index, unsigned mlength){
  auto last = tree.size() - 1 ;
  auto  left = 2 * index + 1 ;
  auto  right = 2 * index + 2 ;
  cout << " " << tree[index] << " ";
  if (left <= last){
    auto llength = to_string(tree[left]).size();
    cout << "---" << string(mlength - llength,'-');
    printer(tree,left,mlength);
    if (right <= last) {
      auto rlength = to_string(tree[right]).size();
      cout << "\n" << do_padding(right,mlength) << string(mlength+ 3,' ') << " | ";
      cout << "\n" << do_padding(right,mlength) << string(mlength+ 3,' ') << " '-" <<
      string(mlength - rlength,'-');
      printer(tree,right,mlength);
    }
  }
}

void print_tree (vector<int> & tree){
  unsigned mlength = 0;
  for (int & element : tree){
    auto clength = to_string(element).size();
    if (clength > mlength) {
      mlength = to_string(element).size();
    }
  }
  cout <<  string(mlength- to_string(tree[0]).size(),' ');
  printer(tree,0,mlength);
}

int main() {
    vector<int> v;
    for(auto i = 0; i < 50; i++){
        v.push_back(rand() % 1000 + 1);
    }
    make_heap(v.begin(),v.end());
    print_tree(v);
}