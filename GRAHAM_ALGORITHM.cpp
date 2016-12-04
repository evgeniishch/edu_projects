//
//  main.cpp
//  Построение выпуклой оболочки методом Грэхама
//
//  Created by user on 04.12.16.
//  Copyright © 2016 EulerLabs. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <list>
#include <vector>

using namespace std;

struct Point {
    double  x,y,cos,distToStart;
    
    Point(){};
    Point(double x1,double y1){
        x = x1;
        y = y1;
        cos = 0;
        distToStart = 0;
    }
    
    double distanceToPoint(Point p){
        double distX = x - p.x;
        double distY = y - p.y;
        return sqrt(pow(distX, 2) + pow(distY, 2));
    }
    
    void setCosine(double cosValue){
        cos = cosValue;
    }
    
    void setDistToStart(double value){
        distToStart = value;
    }
    
    bool equals (Point p){
        return x == p.x && y == p.y;
    }
};

struct coordinateComparator {
    inline bool operator() (const Point& left, const Point& right) {
        if (left.y == right.y) {
            return left.x <= right.x;
        }
        return left.y < right.y;
    }
};

struct cosineValueComparator {
    inline bool operator() (const Point& left, const Point& right) {
        if (left.cos == right.cos) {
            return left.distToStart < right.distToStart;
        }
        return left.cos > right.cos;
    }
};

void calculateCosine(Point& startingPoint, Point& point) {
    double hypotenuse = startingPoint.distanceToPoint(point);
    point.distToStart = hypotenuse;
    
    if (hypotenuse == 0) {
        point.cos = 1;
        return;
    }
    
    double cathetus = fabs(point.x - startingPoint.x);
    double cosine = cathetus / hypotenuse;
    point.cos = cosine;
    
    //тупой угол
    if (point.x < startingPoint.x) {
        double sine = fabs(point.x - startingPoint.x) / hypotenuse;
        point.cos = -sine;
    }
}

double determinantForPoints(Point &firstPoint, Point &secondPoint, Point &thirdPoint) {
    double a = firstPoint.x * secondPoint.y + firstPoint.y * thirdPoint.x + secondPoint.x * thirdPoint.y;
    double b = thirdPoint.x * secondPoint.y + firstPoint.x * thirdPoint.y + secondPoint.x * firstPoint.y;
    return a - b;
}

bool shouldDeleteFromStack(stack<Point> &stack, Point point) {
    Point topPoint = stack.top();
    stack.pop();
    Point nextToTop = stack.top();
    stack.push(topPoint);
    double det = determinantForPoints(nextToTop, topPoint, point);
    return det <= 0;
}

int main(int argc, const char * argv[]) {
    vector<Point> points = vector<Point>();
    
    int n;
    double insertX, insertY;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>> insertX >> insertY;
        points.push_back(*new Point(insertX,insertY));
    }
    
    
    sort(points.begin(), points.end(), coordinateComparator());
    Point startingPoint = points.front();
    
    for(vector<Point>::iterator i = points.begin(); i != points.end(); i++) {
        calculateCosine(startingPoint, *i);
    }
    sort(points.begin(), points.end(), cosineValueComparator());
    
    stack<Point> pointStack;
    pointStack.push(points.at(0));
    pointStack.push(points.at(1));
    pointStack.push(points.at(2));
    
    for(int i = 3; i < points.size(); i++) {
        while (shouldDeleteFromStack(pointStack, points.at(i))) {
            pointStack.pop();
            if (pointStack.top().equals(startingPoint)) {
                break;
            }
        }
        pointStack.push(points[i]);
    }
    
    cout << "Выпуклая оболочка: " << endl;
    while (!pointStack.empty()) {
        cout << pointStack.top().x << "  "<< pointStack.top().y<< endl;
        pointStack.pop();
    }
    
    return 0; 
}
