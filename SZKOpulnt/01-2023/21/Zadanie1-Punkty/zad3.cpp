#include<fstream>
#include<iostream>

using std::cout;


struct point{
    int x;
    int y;
};


int dist(point p1, point p2){
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int dist_sqrd = dx*dx+dy*dy;
    int i = 2;
    while(i*i<dist_sqrd){
        i++;
    }
    return i;
}

int main(){

    std::ifstream file("punkty.txt");
    point * buffer = new point[1000];
    for(int i = 0; i<1000; i++){
        file >>buffer[i].x;
        file >>buffer[i].y;
    }
    file.close();

    point saved_start, saved_end;
    int saved_dist = 0;

    for(int i = 0; i<999; i++){
        for(int j = i+1; j<1000; j++){
            int new_dist = dist(buffer[i], buffer[j]);
            if(new_dist>saved_dist){
                saved_start = buffer[i];
                saved_end = buffer[j];
                saved_dist = new_dist;
            }
        }
    }

    cout << saved_start.x <<" " <<saved_start.y <<"\n";
    cout << saved_end.x <<" " <<saved_end.y <<"\n";
    cout <<saved_dist <<"\n";

    return 0;
}