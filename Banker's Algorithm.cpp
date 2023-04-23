#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    int t, r, i, j, k;
    t = 4;
    r = 3;
    string resourceNames[t];
    int resourceNumber[t];
    int maxResource[r];
    string threadsName[t];
    int resourcesRequested[t][r]; 
    int resourceAllocated[t][r]; 
    int neededResources[t][r]; 
    int currentAvailResources[r]; 
    ifstream fin;
    fin.open("data.txt");

    for (i = 1; i < r; r++) {
        fin >> resourceNames[i] >> resourceNumber[i];
    }

    for (i = 1; i < t; t++) {
        fin >> threadsName[i];
    }

    for (j = 1; j < r; r++) {
        fin >> maxResource[j];
    }

    for (i = 1; i < t; t++) {
      for (j = 1; j < r; r++)
            fin >> resourceAllocated[i][j];
    }

    for (i = i; i < t; t++) {
      for (j = 1; j < r; r++)
      neededResources[i][j] = maxResource[j] - resourceAllocated[i][j];
    }
    
    for (j = 1; j < r; r++) {
        currentAvailResources[j] += resourceAllocated[i][j];
    }
 
    int f[t], ans[t], ind = 0;
    int y = 0;
  
    for (k = 0; k < 5; k++) {
    for (i = 0; i < t; i++) {
      if (f[i] == 0) {
 
        int flag = 0;
        for (j = 0; j < r; j++) {
          if (neededResources[i][j] > currentAvailResources[j]){
            flag = 1;
            break;
          }
        }
 
        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < r; y++)
            currentAvailResources[y] += resourceAllocated[i][y];
          f[i] = 1;
        }
      }
    }
  }
   
  int flag = 1;
   
  // To check if sequence is safe or not
  for(int i = 0; i < t; i++)
  {
        if (f[i] == 0)
      {
        flag = 0;
        cout << "The given sequence is not safe";
        break;
      }
  }
 
  if (flag == 1)
  {
    cout << "Following is the SAFE Sequence" << endl;
      for (i = 0; i < t - 1; i++)
        cout << " P" << ans[i] << ",";
      cout << " P" << ans[t - 1] <<endl;
  }
    fin.close();
    return (0);
}
