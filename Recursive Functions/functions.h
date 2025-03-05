#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

class RecursiveAnalysis {
private:
    long long* data;
    int size;

public:
    RecursiveAnalysis(int n) {
        size = n;
        data = new long long[size];
        srand(time(0));

        for (int i = 0; i < size; i++) {
            data[i] = rand() % 20 + 1;  
        }
    }

    ~RecursiveAnalysis() {
        delete[] data;
    }

    
    void display(int i = 0) {
        if (i == size) {
            std::cout << std::endl;
            return;
        }
        std::cout << data[i] << " ";
        display(i + 1);
    }


    long long findsum(int i = 0) {
        if (i == size) return 0;
        return data[i] + findsum(i + 1);
    }

   
    float findmean() {
        return (size == 0) ? 0 : (findsum() / (float)size);
    }

    
    long long findprod(int i = 0) {
        if (i == size) return 1;
        return data[i] * findprod(i + 1);
    }

   
    long long findmax(int i = 0, long long maxVal = LLONG_MIN) {
        if (i == size) return maxVal;
        return findmax(i + 1, (maxVal > data[i]) ? maxVal : data[i]);
    }

    
    long long findmin(int i = 0, long long minVal = LLONG_MAX) {
        if (i == size) return minVal;
        return findmin(i + 1, (minVal < data[i]) ? minVal : data[i]);
    }

   
    long long findrange() {
        return findmax() - findmin();
    }

    
    void sortArray(int i = 0, int j = 0) {
        if (i == size - 1) return;
        if (j < size - i - 1) {
            if (data[j] > data[j + 1]) std::swap(data[j], data[j + 1]);
            sortArray(i, j + 1);
        }
        else {
            sortArray(i + 1, 0);
        }
    }

    
    float findmed() {
        sortArray();
        if (size % 2 != 0) return data[size / 2];
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }

   
    float sdev() {
        double mean_value = findmean();
        double sum_squared_diff = 0.0;
        for (int i = 0; i < size; i++) {
            sum_squared_diff += pow((data[i] - mean_value), 2);
        }
        return sqrt(sum_squared_diff / size);
    }

    
    int findmodeRecursive(int currentIndex, int& maxCount, int& modeVal, int i = 0, int count = 0) {
        if (i == size) {
            if (count > maxCount) {
                maxCount = count;
                modeVal = data[currentIndex];
            }
            if (currentIndex == size - 1) return modeVal;
            return findmodeRecursive(currentIndex + 1, maxCount, modeVal);
        }
        return findmodeRecursive(currentIndex, maxCount, modeVal, i + 1, count + (data[i] == data[currentIndex]));
    }

   
    int findmode() {
        int maxCount = 0, modeVal = data[0];
        return findmodeRecursive(0, maxCount, modeVal);
    }

   
    int search(long long num, int i = 0) {
        if (i == size) return -1;
        if (data[i] == num) return i;
        return search(num, i + 1);
    }
};

#endif 
