#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int,
  null_type,//opcional
  greater<int>,//a ordem que você quer para a sua árvore
  rb_tree_tag,
  tree_order_statistics_node_update>
StatisticsTree;

int main()
{
    StatisticsTree s;
    s.insert(12);
    s.insert(505);
    s.insert(30);
    cout << s.order_of_key(11) << '\n';
    cout << s.order_of_key(13) << '\n';
    cout << s.order_of_key(50) << '\n';
    cout << s.order_of_key(506) << '\n';
    return 0;
}

typedef
tree<
  int,
  int,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
map_t;

int main()
{
  map_t s;
  s.insert(make_pair(12, 1012));
  s.insert(make_pair(505, 1505));
  s.insert(make_pair(30, 1030));
  cout << s.find_by_order(1)->second << '\n'; // find_by_order funciona para árvore com pair
  return 0;
}