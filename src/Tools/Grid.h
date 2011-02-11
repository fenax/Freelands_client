/* 
 * File:   Grid.h
 * Author: fenax
 *
 * Created on 9 décembre 2010, 19:11
 */

#ifndef GRID_H
#define	GRID_H

template <typename T>
class Grid {
private:
    size_t row_length_;
    size_t height_;
    T* array_;


public:
    Grid(){
        array_ = 0;
    }
    Grid(size_t width, size_t height){
        row_length_ = width;
        height_ = height;
        array_ = new  T[width*height];
    }
    virtual ~Grid(){
        if (array_){
            delete[] array_;
        }
    }

    T* operator[](int index){
    	assert(index<height_ && index >= 0);
        return &array_[index*row_length_];
    }

};

#endif	/* GRID_H */

