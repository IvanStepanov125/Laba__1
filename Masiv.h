#include <iostream>
#include <cstdint>
#include <cstring>


class ArrayHandler{
private:
    char* _array;
    long long int* _array_ind_mod;
    int _mod;
    char _max;
    char _min;
    long long int _size;
    long long int _size_bate;
public:
    ArrayHandler(char size){
        _array = new char[size];
        _size = size;
        _size_bate = size;
        _min = CHAR_MAX;
        _max = CHAR_MAX;
        _mod = 100;
        _array_ind_mod = new long long int[_mod];
        for (int j = 0; j < _mod; j++){
            _array_ind_mod[j] = -1;
        }
    }

    int GetMax(){
        return _max;
    }

    int GetMin(){
        return _min;
    }

    int GetIndexElem(int elem){
        return _array_ind_mod[elem];
    }

    void Append(int number){
        int cons = 4;
        if (_size == _size_bate){
            _size_bate = _size_bate * cons;
            char* array = new char[_size_bate];
            std::memcpy(array, _array, _size*sizeof(char));
            delete [] _array;
            _array = array;
        }
        _array[_size] = number;
        _size ++;
        

        if (number > _max)
            _max = number;
        else if (number < _min)
            _min = number;

        if (_array_ind_mod[number] == -1){
            _array_ind_mod[number] = _size;
        }
    }

    void Print(){
        for (long long int i = 0; i < _size; i++){
            std::cout << _array[i] << std::endl;
        }
    }
    ~ArrayHandler(){
        delete [] _array;
        delete [] _array_ind_mod;
    }
};