#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int px, py, ax, ay, bx, by;
        cin >> px >> py >> ax >> ay >> bx >> by;
        long double dist_op = sqrt((px * px) + (py * py));
        long double dist_oa = sqrt((ax * ax) + (ay * ay));
        long double dist_ob = sqrt((bx * bx) + (by * by));
        long double dist_pa = sqrt(((px - ax) * (px - ax)) + ((py - ay) * (py - ay)));
        long double dist_pb = sqrt(((px - bx) * (px - bx)) + ((py - by) * (py - by)));
        long double dist_ab = sqrt(((ax - bx) * (ax - bx)) + ((ay - by) * (ay - by)));

        if(dist_pa > dist_pb){

        }else{

        }
        /*To find the minimum non-negative value w for the power of the lanterns such that there is a path from point O to point P which is completely illuminated, you can follow these steps:

        Calculate the distance from O to P: distance_OP = sqrt((Px - 0)^2 + (Py - 0)^2).

        Calculate the distance from A to P: distance_AP = sqrt((Px - Ax)^2 + (Py - Ay)^2).

        Calculate the distance from B to P: distance_BP = sqrt((Px - Bx)^2 + (Py - By)^2).

        The minimum value of w should be the maximum of the following three values:

        distance_OP: To ensure that the entire path from O to P is illuminated.
        distance_AP: To ensure that point P is illuminated by lantern A.
        distance_BP: To ensure that point P is illuminated by lantern B.
        So, the minimum w would be: w = max(distance_OP, distance_AP, distance_BP).

        This value of w will guarantee that there is a path from O to P that is completely illuminated by at least one of the lanterns.
        */
    }
}