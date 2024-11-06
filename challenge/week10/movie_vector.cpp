#include <vector>
#include <iostream>
using namespace std;

class Movie {
public:
    string name;
    double score;
    
    void Print() {
        cout << name <<": " << score << endl;

    }
};

int main() {

    Movie movie1;
    movie1.name = "titinic";
    movie1.score = 9.9;

    Movie movie2;
    movie2.name = "gone with the wind";
    movie2.score = 9.7;

    Movie movie3;
    movie3.name = "terminator";
    movie3.score = 9.7;
    
    vector<Movie> v ;

    v.push_back(movie1);
    v.push_back(movie2);
    v.push_back(movie3);

    for (Movie m : v)
        m.Print();


}