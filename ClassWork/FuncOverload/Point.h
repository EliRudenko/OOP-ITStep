#pragma once


class Point
{
private:
    int x;
    int y;

public:
    Point();
    Point(int x1, int y1);
    void Init();
    void Init(int x1, int y1);
    void Output();

    Point operator+(int value);
    Point operator++();//Преф    
    Point operator++(int); //Пост  

};

