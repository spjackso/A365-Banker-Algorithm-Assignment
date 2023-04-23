#include <iostream>
using namespace std;
 
int main()
{
    int t, r, i, j, k;
    t = 4;
    r = 3;
    string resourceNames[t]; 
    int maxResource[r];
    string threadsName[t];
    int resourcesRequested[t][r]; 
    int resourceAllocated[t][r]; 
    int neededResources[t][r]; 
    int currentAvailResources[r]; 
    ifstream fin;
    fin.open("data.txt");

    for (i = 1; i < r; r++) {
        fin >> resourceName[i] << resourceNumber[i];
    }

    for (i = 1; i < t; t++) {
        fin >> threadName[i];
    }

    for (j = 1; j < r; r++) {
        fin >> resourceMax[i][j];
    }

    for (i = 1; i < t; t++) {
      for (j = 1; j < r; r++)
            fin >> resourceAllocated[i][j];
    }

    for (i = i; i < t; t++) {
      for (j = 1; j < r; r++)
      neededResources[i][j] = maxResource[i][j] - resourceAllocated[i][j];
    }
    
    for (j = 1; j < r; r++) {
        currentAvailResources[j] += resourceAllocated[i][j];
    }
 
    return 0;

}